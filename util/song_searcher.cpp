#include "song_item.hpp"
#include "primary_song_data_cell.hpp"
#include "secondary_song_data_cell.hpp"
#include <peel/Adw/Adw.h>
#include <peel/Gtk/Gtk.h>
#include <peel/Gio/Gio.h>
#include <peel/GLib/GLib.h>
#include <peel/Gdk/Paintable.h>
#include <peel/Gdk/Clipboard.h>
#include <peel/Gly/Gly.h>
#include <peel/GlyGtk4/GlyGtk4.h>
#include <peel/GObject/Binding.h>
#include <peel/Soup/Session.h>
#include <peel/Soup/Message.h>
#include <peel/Soup/Status.h>
#include <peel/Gio/Cancellable.h>
#include <peel/Gio/AsyncResult.h>
#include <peel/Gtk/ShortcutController.h>
#include <peel/Gtk/Shortcut.h>
#include <peel/Gtk/ShortcutTrigger.h>
#include <peel/Gtk/CallbackAction.h>
#include <peel/class.h>
#include <peel/widget-template.h>
#include <nlohmann/json.hpp>
#include <format>
#include <print>

using namespace peel;

class ApplicationWindow final : public Adw::ApplicationWindow
{
    PEEL_SIMPLE_CLASS(ApplicationWindow, Adw::ApplicationWindow);

    struct Members {
        Gtk::Entry          *search_entry;
        Gtk::Label          *status_label;
        Gtk::ScrolledWindow *scrolled;
    } m;

    Gio::ListStore           *results = nullptr;
    RefPtr<Soup::Session>     soup_session;
    RefPtr<Gio::Cancellable>  cancellable;

    void init(Class *);
    void vfunc_dispose();

    void on_search_changed();
    void on_api_response(GObject::Object *, Gio::AsyncResult *);
    void fetch_thumb(RefPtr<SongItem> item, std::string url);
    void on_thumb_response(RefPtr<SongItem> item, RefPtr<Soup::Message> msg, GObject::Object *, Gio::AsyncResult *);
    void on_gly_load(RefPtr<SongItem> item, GObject::Object *, Gio::AsyncResult *);
    void on_gly_frame(RefPtr<SongItem> item, GObject::Object *, Gio::AsyncResult *);

public:
    static ApplicationWindow* create(Adw::Application *app)
    {
        return Object::create<ApplicationWindow>(prop_application(), app);
    }
};

void
ApplicationWindow::vfunc_dispose()
{
    dispose_template(Type::of<ApplicationWindow>());
    parent_vfunc_dispose<ApplicationWindow>();
}

void
ApplicationWindow::Class::init()
{
    override_vfunc_dispose<ApplicationWindow>();
    set_template_from_resource("/bot/hatsune/SongSearcher/song_searcher.ui");
    PEEL_WIDGET_TEMPLATE_BIND_CHILD(ApplicationWindow, m.search_entry, "search-entry");
    PEEL_WIDGET_TEMPLATE_BIND_CHILD(ApplicationWindow, m.status_label, "status-label");
    PEEL_WIDGET_TEMPLATE_BIND_CHILD(ApplicationWindow, m.scrolled,     "scrolled");
}

void
ApplicationWindow::init(Class *)
{
    new (&m) Members;
    init_template();

    soup_session = Soup::Session::create();
    soup_session->set_user_agent("github/talisein/songbot/song_searcher");
    soup_session->set_timeout(30);

    m.search_entry->connect_activate([this](Gtk::Entry *) { on_search_changed(); });
    m.search_entry->connect_icon_press([this](Gtk::Entry *, Gtk::Entry::IconPosition pos) {
        if (pos == Gtk::Entry::IconPosition::SECONDARY)
            m.search_entry->set_text("");
    });

    auto model = Gio::ListStore::create(GObject::Type::of<SongItem>());
    results = model;
    auto selection = Gtk::SingleSelection::create(std::move(model).cast<Gio::ListModel>());

    struct ThumbBindings {
        RefPtr<GObject::Binding> paint_bind;
        ~ThumbBindings() { if (paint_bind) paint_bind->unbind(); }
    };
    struct ActionBindings {
        SignalConnection id_conn;
        SignalConnection names_conn;
    };

    /* Column 1: thumbnail */
    auto thumb_factory = Gtk::SignalListItemFactory::create();
    thumb_factory->connect_setup([](Gtk::SignalListItemFactory *, GObject::Object *obj) {
        auto *cell = obj->cast<Gtk::ColumnView::Cell>();
        auto image = Gtk::Image::create();
        image->set_pixel_size(64);
        cell->set_child(std::move(image));
    });
    thumb_factory->connect_bind([](Gtk::SignalListItemFactory *, GObject::Object *obj) {
        auto *cell  = obj->cast<Gtk::ColumnView::Cell>();
        auto *song  = cell->get_item()->cast<SongItem>();
        auto *image = cell->get_child()->cast<Gtk::Image>();
        auto *binds = new ThumbBindings{};
        binds->paint_bind = Object::bind_property(
            song, SongItem::prop_paintable(),
            image, Gtk::Image::prop_paintable(),
            GObject::BindingFlags::SYNC_CREATE);
        cell->set_data("binds", binds, [](gpointer b) { delete static_cast<ThumbBindings*>(b); });
    });
    thumb_factory->connect_unbind([](Gtk::SignalListItemFactory *, GObject::Object *obj) {
        auto *cell = obj->cast<Gtk::ColumnView::Cell>();
        delete static_cast<ThumbBindings*>(cell->steal_data("binds"));
    });
    auto thumb_col = Gtk::ColumnView::Column::create(nullptr,
        std::move(thumb_factory).cast<Gtk::ListItemFactory>());
    thumb_col->set_fixed_width(72);

    /* Column 2: title / artist / vocalists */
    auto song_factory = Gtk::SignalListItemFactory::create();
    song_factory->connect_setup([](Gtk::SignalListItemFactory *, GObject::Object *obj) {
        auto *cell = obj->cast<Gtk::ColumnView::Cell>();
        cell->set_child(PrimarySongDataCell::create());
    });
    song_factory->connect_bind([](Gtk::SignalListItemFactory *, GObject::Object *obj) {
        auto *cell = obj->cast<Gtk::ColumnView::Cell>();
        cell->get_child()->cast<PrimarySongDataCell>()->bind(
            cell->get_item()->cast<SongItem>());
    });
    song_factory->connect_unbind([](Gtk::SignalListItemFactory *, GObject::Object *obj) {
        auto *cell = obj->cast<Gtk::ColumnView::Cell>();
        cell->get_child()->cast<PrimarySongDataCell>()->unbind();
    });
    auto song_col = Gtk::ColumnView::Column::create("Song",
        std::move(song_factory).cast<Gtk::ListItemFactory>());
    song_col->set_expand(true);
    song_col->set_resizable(true);

    /* Column 3: type / date / duration */
    auto info_factory = Gtk::SignalListItemFactory::create();
    info_factory->connect_setup([](Gtk::SignalListItemFactory *, GObject::Object *obj) {
        auto *cell = obj->cast<Gtk::ColumnView::Cell>();
        cell->set_child(SecondarySongDataCell::create());
    });
    info_factory->connect_bind([](Gtk::SignalListItemFactory *, GObject::Object *obj) {
        auto *cell = obj->cast<Gtk::ColumnView::Cell>();
        cell->get_child()->cast<SecondarySongDataCell>()->bind(
            cell->get_item()->cast<SongItem>());
    });
    info_factory->connect_unbind([](Gtk::SignalListItemFactory *, GObject::Object *obj) {
        auto *cell = obj->cast<Gtk::ColumnView::Cell>();
        cell->get_child()->cast<SecondarySongDataCell>()->unbind();
    });
    auto info_col = Gtk::ColumnView::Column::create("Info",
        std::move(info_factory).cast<Gtk::ListItemFactory>());
    info_col->set_resizable(true);

    /* Column 4: copy buttons */
    auto actions_factory = Gtk::SignalListItemFactory::create();
    actions_factory->connect_setup([](Gtk::SignalListItemFactory *, GObject::Object *obj) {
        auto *cell = obj->cast<Gtk::ColumnView::Cell>();
        auto id_btn    = Gtk::Button::create_with_label("Copy ID");
        auto names_btn = Gtk::Button::create_with_label("Copy Names");
        auto btn_box   = Gtk::Box::create(Gtk::Orientation::VERTICAL, 4);
        btn_box->set_valign(Gtk::Align::CENTER);
        btn_box->append(std::move(id_btn));
        btn_box->append(std::move(names_btn));
        cell->set_child(std::move(btn_box));
    });
    actions_factory->connect_bind([](Gtk::SignalListItemFactory *, GObject::Object *obj) {
        auto *cell      = obj->cast<Gtk::ColumnView::Cell>();
        auto *song      = cell->get_item()->cast<SongItem>();
        auto *btn_box   = cell->get_child()->cast<Gtk::Box>();
        auto *id_btn    = btn_box->get_first_child()->cast<Gtk::Button>();
        auto *names_btn = id_btn->get_next_sibling()->cast<Gtk::Button>();
        int sid = song->get_id();
        std::string nt = song->copy_names_text();
        auto *binds = new ActionBindings{};
        binds->id_conn = id_btn->connect_clicked([sid](Gtk::Button *) {
            auto text = std::to_string(sid);
            Gdk::Display::get_default()->get_clipboard()->set_text(text.c_str());
        });
        binds->names_conn = names_btn->connect_clicked([nt = std::move(nt)](Gtk::Button *) {
            Gdk::Display::get_default()->get_clipboard()->set_text(nt.c_str());
        });
        cell->set_data("binds", binds, [](gpointer b) { delete static_cast<ActionBindings*>(b); });
    });
    actions_factory->connect_unbind([](Gtk::SignalListItemFactory *, GObject::Object *obj) {
        auto *cell = obj->cast<Gtk::ColumnView::Cell>();
        delete static_cast<ActionBindings*>(cell->steal_data("binds"));
    });
    auto actions_col = Gtk::ColumnView::Column::create(nullptr,
        std::move(actions_factory).cast<Gtk::ListItemFactory>());

    auto col_view = Gtk::ColumnView::create(std::move(selection).cast<Gtk::SelectionModel>());
    col_view->append_column(thumb_col);
    col_view->append_column(song_col);
    col_view->append_column(info_col);
    col_view->append_column(actions_col);
    col_view->set_show_row_separators(true);
    m.scrolled->set_child(std::move(col_view));

    auto sc = Gtk::ShortcutController::create();
    sc->set_scope(Gtk::Shortcut::Scope::GLOBAL);
    sc->add_shortcut(Gtk::Shortcut::create(
        Gtk::ShortcutTrigger::parse_string("<Control>k"),
        Gtk::CallbackAction::create([this](Gtk::Widget *, GLib::Variant *) -> bool {
            m.search_entry->set_text("");
            m.search_entry->grab_focus();
            return true;
        })));
    add_controller(std::move(sc).cast<Gtk::EventController>());
}

void
ApplicationWindow::on_search_changed()
{
    const char *text = m.search_entry->get_text();
    if (!text || !*text) return;

    if (cancellable) cancellable->cancel();
    cancellable = Gio::Cancellable::create();

    results->remove_all();
    m.status_label->set_label("Searching\xe2\x80\xa6");

    auto escaped = GLib::Uri::escape_string(text, nullptr, true);
    auto url = std::format(
        "https://vocadb.net/api/songs?query={}&maxResults=20"
        "&fields=Artists,Names,MainPicture&nameMatchMode=Partial&sort=RatingScore&lang=English",
        escaped.c_str());

    auto msg = Soup::Message::create(SOUP_METHOD_GET, url.c_str());
    soup_session->send_and_read_async(
        msg, G_PRIORITY_DEFAULT, cancellable,
        [this](GObject::Object *src, Gio::AsyncResult *res) {
            on_api_response(src, res);
        });
}

void
ApplicationWindow::on_api_response(GObject::Object *src, Gio::AsyncResult *res)
{
    UniquePtr<GLib::Error> error;
    auto bytes = static_cast<Soup::Session*>(src)->send_and_read_finish(res, &error);
    if (error) {
        if (error->matches(G_IO_ERROR, G_IO_ERROR_CANCELLED)) return;
        std::println("api error: {}", error->message);
        auto msg = std::format("Error: {}", error->message);
        m.status_label->set_label(msg.c_str());
        return;
    }

    auto data = bytes->get_data();
    std::string_view response{reinterpret_cast<const char*>(data.data()), data.size()};

    try {
        auto json = nlohmann::json::parse(response);

        unsigned count = 0;
        for (const auto &song : json["items"]) {
            auto item = SongItem::create(song);
            results->append(item);
            if (song.contains("mainPicture") && !song["mainPicture"].is_null()) {
                auto url = song["mainPicture"].value("urlThumb", "");
                if (!url.empty()) fetch_thumb(item, std::move(url));
            }
            ++count;
        }
        auto found_msg = std::format("Found {} results", count);
        m.status_label->set_label(found_msg.c_str());
    } catch (const std::exception &e) {
        auto err_msg = std::format("Parse error: {}", e.what());
        m.status_label->set_label(err_msg.c_str());
    }
}

void
ApplicationWindow::fetch_thumb(RefPtr<SongItem> item, std::string url)
{
    auto msg = Soup::Message::create(SOUP_METHOD_GET, url.c_str());
    soup_session->send_and_read_async(
        msg, G_PRIORITY_LOW, cancellable,
        [this, item = std::move(item), msg](GObject::Object *src, Gio::AsyncResult *res) mutable {
            on_thumb_response(std::move(item), msg, src, res);
        });
}

void
ApplicationWindow::on_thumb_response(RefPtr<SongItem> item, RefPtr<Soup::Message> msg, GObject::Object *src, Gio::AsyncResult *res)
{
    UniquePtr<GLib::Error> error;
    auto bytes = static_cast<Soup::Session*>(src)->send_and_read_finish(res, &error);
    if (error) {
        std::println("thumb error: {}", error->message);
        return;
    }
    if (msg->get_status() != Soup::Status::OK)
        return;

    auto loader = Gly::Loader::create_for_bytes(bytes);
    loader->load_async(cancellable,
        [this, item = std::move(item), loader](GObject::Object *src, Gio::AsyncResult *res) mutable {
            on_gly_load(std::move(item), src, res);
        });
}

void
ApplicationWindow::on_gly_load(RefPtr<SongItem> item, GObject::Object *src, Gio::AsyncResult *res)
{
    UniquePtr<GLib::Error> error;
    auto image = static_cast<Gly::Loader*>(src)->load_finish(res, &error);
    if (error) {
        std::println("thumb gly load error: {}", error->message);
        return;
    }
    if (!image) return;

    image->next_frame_async(cancellable,
        [this, item = std::move(item), image](GObject::Object *src, Gio::AsyncResult *res) mutable {
            on_gly_frame(std::move(item), src, res);
        });
}

void
ApplicationWindow::on_gly_frame(RefPtr<SongItem> item, GObject::Object *src, Gio::AsyncResult *res)
{
    UniquePtr<GLib::Error> error;
    auto frame = static_cast<Gly::Image*>(src)->next_frame_finish(res, &error);
    if (error) {
        std::println("thumb gly frame error: {}", error->message);
        return;
    }
    if (!frame) return;

    auto texture = GlyGtk4::frame_get_texture(frame);
    item->set_paintable(texture->cast<Gdk::Paintable>());
}

PEEL_CLASS_IMPL(ApplicationWindow, "SongSearcherApplicationWindow", Adw::ApplicationWindow)


class Application final : public Adw::Application
{
    PEEL_SIMPLE_CLASS(Application, Adw::Application);
    friend class Gio::Application;

    void init(Class *) {}

    void vfunc_activate()
    {
        parent_vfunc_activate<Application>();
        auto *window = ApplicationWindow::create(cast<Adw::Application>());
        window->present();
    }

public:
    static RefPtr<Application> create()
    {
        return Object::create<Application>(
            prop_application_id(), "bot.hatsune.SongSearcher",
            prop_flags(), Gio::Application::Flags::DEFAULT_FLAGS);
    }
};

void
Application::Class::init()
{
    override_vfunc_activate<Application>();
}

PEEL_CLASS_IMPL(Application, "SongSearcherApplication", Adw::Application)

int main(int argc, char *argv[])
{
    GLib::setenv("RUST_LOG", "warn", false);
    RefPtr<Application> app = Application::create();
    return app->run(argc, argv);
}
