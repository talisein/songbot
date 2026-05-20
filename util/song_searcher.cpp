#include "song_item.hpp"
#include "primary_song_data_cell.hpp"
#include "secondary_song_data_cell.hpp"
#include "vocadb_song_model.hpp"
#include <peel/Adw/Adw.h>
#include <peel/Gtk/Gtk.h>
#include <peel/Gio/Gio.h>
#include <peel/GLib/GLib.h>
#include <peel/Gdk/Paintable.h>
#include <peel/Gdk/Clipboard.h>
#include <peel/GObject/Binding.h>
#include <peel/Soup/Session.h>
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

    VocadbSongModel       *model = nullptr;
    RefPtr<Soup::Session>  soup_session;

    void init(Class *);
    void vfunc_dispose();

    void on_search_changed();

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

    auto mdl = VocadbSongModel::create(soup_session);
    model = mdl;
    mdl->connect_items_changed([this](Gio::ListModel *, unsigned pos, unsigned removed, unsigned) {
        if (pos == 0 && removed == 0) {
            unsigned n = model->get_n_items();
            auto msg = n > 0 ? std::format("Found {} results", n) : std::string("No results");
            m.status_label->set_label(msg.c_str());
        }
    });
    mdl->connect_error([this](VocadbSongModel *, const GLib::Error *err) {
        auto msg = std::format("Error: {}", err->message);
        m.status_label->set_label(msg.c_str());
    });
    auto selection = Gtk::SingleSelection::create(std::move(mdl).cast<Gio::ListModel>());

    struct ThumbBindings {
        RefPtr<GObject::Binding> paint_bind;
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
        auto *binds = new ActionBindings{};
        RefPtr<SongItem> ref(song);
        binds->id_conn = id_btn->connect_clicked([ref](Gtk::Button *) {
            auto text = std::to_string(ref->get_id());
            Gdk::Display::get_default()->get_clipboard()->set_text(text.c_str());
        });
        binds->names_conn = names_btn->connect_clicked([ref](Gtk::Button *) {
            auto text = ref->copy_names_text();
            Gdk::Display::get_default()->get_clipboard()->set_text(text.c_str());
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
    m.status_label->set_label("Searching\xe2\x80\xa6");
    model->search(text);
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
        Gtk::IconTheme::get_for_display(Gdk::Display::get_default())
            ->add_resource_path("/bot/hatsune/SongSearcher/icons");
        auto *window = ApplicationWindow::create(cast<Adw::Application>());
        window->set_icon_name("bot.hatsune.SongSearcher");
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
