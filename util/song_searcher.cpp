#include <peel/Adw/Adw.h>
#include <peel/Gtk/Gtk.h>
#include <peel/Gio/Gio.h>
#include <peel/GLib/GLib.h>
#include <peel/Gdk/Paintable.h>
#include <peel/Gdk/Clipboard.h>
#include <peel/Pango/EllipsizeMode.h>
#include <peel/GObject/Binding.h>
#include <peel/Soup/Session.h>
#include <peel/Soup/Message.h>
#include <peel/Gio/Cancellable.h>
#include <peel/Gio/AsyncResult.h>
#include <peel/Gtk/ShortcutController.h>
#include <peel/Gtk/Shortcut.h>
#include <peel/Gtk/ShortcutTrigger.h>
#include <peel/Gtk/CallbackAction.h>
#include <peel/class.h>
#include <nlohmann/json.hpp>
#include <string>
#include <format>
#include <print>
#include <set>
#include <vector>

using namespace peel;

struct SongData {
    std::string name;
    std::string artist;
    std::string vocalists;
    std::string song_type;
    std::string publish_date;
    std::string duration;
    RefPtr<Gdk::Paintable> paintable;
    int id = 0;
    std::string japanese_name;
    std::string romaji_name;
    std::string english_name;
    std::string thumb_url;
};

class SongItem final : public GObject::Object
{
    PEEL_SIMPLE_CLASS(SongItem, GObject::Object);

    SongData *data = nullptr;

    void init(Class *) { data = new SongData; }
    ~SongItem() { delete data; }

    static bool has_cjk(const std::string &s)
    {
        for (size_t i = 0; i < s.size(); ) {
            auto c = static_cast<unsigned char>(s[i]);
            if (c < 0x80) { ++i; continue; }
            if (c < 0xE0) { i += 2; continue; }
            if (c < 0xF0) {
                unsigned char b = i + 1 < s.size() ? static_cast<unsigned char>(s[i+1]) : 0;
                /* U+3000–U+9FFF (Kana, CJK ideographs) or U+FF00–U+FFEF (fullwidth) */
                if ((c >= 0xE3 && c <= 0xE9) || (c == 0xEF && b >= 0xBC)) return true;
                i += 3;
            } else { i += 4; }
        }
        return false;
    }

    static std::string producer_str(const nlohmann::json &song)
    {
        std::string result;
        for (const auto &a : song.value("artists", nlohmann::json::array())) {
            if (a.value("categories", "").find("Producer") == std::string::npos) continue;
            std::string name = a.value("name", "");
            /* If the returned name is still CJK, scan additionalNames for a Latin alternative. */
            if (has_cjk(name) && a.contains("artist") && !a["artist"].is_null()) {
                const auto &extra = a["artist"].value("additionalNames", "");
                size_t pos = 0;
                while (pos < extra.size()) {
                    auto comma = extra.find(',', pos);
                    auto end   = comma == std::string::npos ? extra.size() : comma;
                    auto cand  = extra.substr(pos, end - pos);
                    while (!cand.empty() && cand.front() == ' ') cand.erase(0, 1);
                    while (!cand.empty() && cand.back()  == ' ') cand.pop_back();
                    if (!cand.empty() && !has_cjk(cand)) { name = cand; break; }
                    pos = comma == std::string::npos ? extra.size() : comma + 1;
                }
            }
            if (!result.empty()) result += ", ";
            result += name;
        }
        return result;
    }

    static std::string vocalist_str(const nlohmann::json &song)
    {
        static const std::pair<std::string_view, std::string_view> kMap[] = {
            {"Hatsune Miku",  "Miku"},
            {"Kagamine Rin",  "Rin"},
            {"Kagamine Len",  "Len"},
            {"Megurine Luka", "Luka"},
            {"KAITO",         "KAITO"},
            {"MEIKO",         "MEIKO"},
            {"GUMI",          "GUMI"},
            {"IA",            "IA"},
            {"Kasane Teto",   "Teto"},
            {"Yuzuki Yukari", "Yukari"},
            {"v flower",      "flower"},
        };
        auto canonical = [](const std::string &n) -> std::string {
            std::string_view sv{n};
            for (auto &[prefix, canon] : kMap) {
                if (sv.starts_with(prefix) &&
                    (sv.size() == prefix.size() || sv[prefix.size()] == ' '))
                    return std::string(canon);
            }
            return n;
        };

        std::set<std::string> seen;
        std::vector<std::string> order;
        for (const auto &a : song.value("artists", nlohmann::json::array())) {
            if (a.value("categories", "").find("Vocalist") == std::string::npos) continue;
            auto c = canonical(a.value("name", ""));
            if (seen.insert(c).second) order.push_back(c);
        }

        if (order.empty()) return "";
        if (order.size() == 1) return order[0];
        std::string result = "duet(";
        for (size_t i = 0; i < order.size(); ++i) {
            if (i > 0) result += ',';
            result += order[i];
        }
        result += ')';
        return result;
    }

public:
    static RefPtr<SongItem> create(const nlohmann::json &song)
    {
        int id = song.value("id", 0);

        std::string japanese_name, romaji_name, english_name;
        if (auto it = song.find("names"); it != song.end()) {
            for (const auto &n : *it) {
                auto lang = n.value("language", "");
                if (lang == "Japanese")     japanese_name = n.value("value", "");
                else if (lang == "Romaji")  romaji_name   = n.value("value", "");
                else if (lang == "English") english_name  = n.value("value", "");
            }
        }
        std::string display_name = english_name.empty()
            ? song.value("name", "") : english_name;

        std::string publish_date;
        if (song.contains("publishDate") && !song["publishDate"].is_null()) {
            auto raw = song["publishDate"].get<std::string>();
            if (raw.size() >= 10) publish_date = raw.substr(0, 10);
        }

        std::string duration;
        if (int secs = song.value("lengthSeconds", 0); secs > 0)
            duration = std::format("{}:{:02}", secs / 60, secs % 60);

        auto item = Object::create<SongItem>();
        item->data->name          = std::move(display_name);
        item->data->artist        = producer_str(song);
        item->data->vocalists     = vocalist_str(song);
        item->data->song_type     = song.value("songType", "");
        item->data->publish_date  = std::move(publish_date);
        item->data->duration      = std::move(duration);
        item->data->id            = id;
        item->data->japanese_name = std::move(japanese_name);
        item->data->romaji_name   = std::move(romaji_name);
        item->data->english_name  = std::move(english_name);
        if (song.contains("mainPicture") && !song["mainPicture"].is_null())
            item->data->thumb_url = song["mainPicture"].value("urlThumb", "");
        return item;
    }

    const std::string &get_name()         const { return data->name; }
    const std::string &get_artist()       const { return data->artist; }
    const std::string &get_vocalists()    const { return data->vocalists; }
    const std::string &get_song_type()    const { return data->song_type; }
    const std::string &get_publish_date() const { return data->publish_date; }
    const std::string &get_duration()     const { return data->duration; }
    const std::string &get_thumb_url()    const { return data->thumb_url; }
    int get_id() const { return data->id; }

    Gdk::Paintable *get_paintable() const { return data->paintable; }

    void set_paintable(Gdk::Paintable *p)
    {
        if (p) {
            data->paintable = RefPtr<Gdk::Paintable>(p);
        } else {
            data->paintable = {};
        }
        notify(prop_paintable());
    }

    PEEL_PROPERTY(Gdk::Paintable, paintable, "paintable")

    std::string copy_names_text() const
    {
        auto qfmt = [](const std::string &s) -> std::string {
            if (s.empty()) return "nullopt";
            return std::format("\"{}\"", s);
        };
        const auto &vocal = data->vocalists.empty() ? "nullopt" : data->vocalists;
        return std::format("{{{}, {}, {}, {}, {}, {} }},",
            qfmt(data->japanese_name), qfmt(data->romaji_name), qfmt(data->english_name),
            vocal, qfmt(data->artist), data->id);
    }

private:
    template<typename F>
    static void define_properties(F &f)
    {
        f.prop(prop_paintable())
         .get(&SongItem::get_paintable)
         .set(&SongItem::set_paintable);
    }
};

void SongItem::Class::init() {}
PEEL_CLASS_IMPL(SongItem, "SongSearcherItem", GObject::Object)


class Application final : public Adw::Application
{
    PEEL_SIMPLE_CLASS(Application, Adw::Application);
    friend class Gio::Application;

    Gtk::Entry          *search_entry = nullptr;
    Gio::ListStore      *results      = nullptr;
    Gtk::Label          *status_label = nullptr;
    RefPtr<Soup::Session>      soup_session;
    RefPtr<Gio::Cancellable>   cancellable;

    void init(Class *) {}

    void vfunc_activate()
    {
        parent_vfunc_activate<Application>();

        soup_session = Soup::Session::create();
        soup_session->set_user_agent("github/talisein/songbot/song_searcher");
        soup_session->set_timeout(30);

        auto *window = Adw::ApplicationWindow::create(cast<Gtk::Application>());
        window->set_title("Song Searcher");
        window->set_default_size(800, 600);

        auto entry_float = Gtk::Entry::create();
        search_entry = entry_float;
        search_entry->set_placeholder_text("Search songs\xe2\x80\xa6");
        search_entry->set_icon_from_icon_name(Gtk::Entry::IconPosition::SECONDARY, "edit-clear-symbolic");
        search_entry->connect_activate([this](Gtk::Entry *) { on_search_changed(); });
        search_entry->connect_icon_press([this](Gtk::Entry *, Gtk::Entry::IconPosition pos) {
            if (pos == Gtk::Entry::IconPosition::SECONDARY)
                search_entry->set_text("");
        });

        auto model = Gio::ListStore::create(GObject::Type::of<SongItem>());
        results = model;
        auto selection = Gtk::SingleSelection::create(std::move(model).cast<Gio::ListModel>());

        auto factory = Gtk::SignalListItemFactory::create();
        factory->connect_setup([](Gtk::SignalListItemFactory *, GObject::Object *obj) {
            auto *item = obj->cast<Gtk::ListItem>();

            auto image_float = Gtk::Image::create();
            image_float->set_pixel_size(64);

            auto name_label_float = Gtk::Label::create("");
            name_label_float->set_halign(Gtk::Align::START);
            name_label_float->set_hexpand(true);
            name_label_float->set_ellipsize(Pango::EllipsizeMode::END);

            auto artist_label_float = Gtk::Label::create("");
            artist_label_float->set_halign(Gtk::Align::START);

            auto vocalist_label_float = Gtk::Label::create("");
            vocalist_label_float->set_halign(Gtk::Align::START);

            auto vbox = Gtk::Box::create(Gtk::Orientation::VERTICAL, 2);
            vbox->append(std::move(name_label_float));
            vbox->append(std::move(artist_label_float));
            vbox->append(std::move(vocalist_label_float));
            vbox->set_valign(Gtk::Align::CENTER);

            auto type_label_float = Gtk::Label::create("");
            type_label_float->set_halign(Gtk::Align::START);

            auto date_label_float = Gtk::Label::create("");
            date_label_float->set_halign(Gtk::Align::START);

            auto duration_label_float = Gtk::Label::create("");
            duration_label_float->set_halign(Gtk::Align::START);

            auto info_box = Gtk::Box::create(Gtk::Orientation::VERTICAL, 2);
            info_box->set_valign(Gtk::Align::CENTER);
            info_box->append(std::move(type_label_float));
            info_box->append(std::move(date_label_float));
            info_box->append(std::move(duration_label_float));

            auto id_btn_float = Gtk::Button::create_with_label("Copy ID");
            auto names_btn_float = Gtk::Button::create_with_label("Copy Names");

            auto btn_box = Gtk::Box::create(Gtk::Orientation::VERTICAL, 4);
            btn_box->set_valign(Gtk::Align::CENTER);
            btn_box->append(std::move(id_btn_float));
            btn_box->append(std::move(names_btn_float));

            auto hbox = Gtk::Box::create(Gtk::Orientation::HORIZONTAL, 8);
            hbox->append(std::move(image_float));
            hbox->append(std::move(vbox));
            hbox->append(std::move(info_box));
            hbox->append(std::move(btn_box));

            item->set_child(std::move(hbox));
        });

        struct Bindings {
            RefPtr<GObject::Binding> paint_bind;
            SignalConnection id_conn;
            SignalConnection names_conn;
            ~Bindings() { if (paint_bind) paint_bind->unbind(); }
        };

        factory->connect_bind([](Gtk::SignalListItemFactory *, GObject::Object *obj) {
            auto *item         = obj->cast<Gtk::ListItem>();
            auto *song         = item->get_item()->cast<SongItem>();
            auto *hbox         = item->get_child()->cast<Gtk::Box>();
            auto *image           = hbox->get_first_child()->cast<Gtk::Image>();
            auto *vbox            = image->get_next_sibling()->cast<Gtk::Box>();
            auto *name_label      = vbox->get_first_child()->cast<Gtk::Label>();
            auto *artist_label    = name_label->get_next_sibling()->cast<Gtk::Label>();
            auto *vocalist_label  = artist_label->get_next_sibling()->cast<Gtk::Label>();
            auto *info_box        = vbox->get_next_sibling()->cast<Gtk::Box>();
            auto *type_label      = info_box->get_first_child()->cast<Gtk::Label>();
            auto *date_label      = type_label->get_next_sibling()->cast<Gtk::Label>();
            auto *duration_label  = date_label->get_next_sibling()->cast<Gtk::Label>();
            auto *btn_box         = info_box->get_next_sibling()->cast<Gtk::Box>();
            auto *id_btn          = btn_box->get_first_child()->cast<Gtk::Button>();
            auto *names_btn       = id_btn->get_next_sibling()->cast<Gtk::Button>();

            int sid = song->get_id();

            {
                auto escaped = GLib::markup_escape_text(song->get_name().c_str(), -1);
                auto markup = std::format("<a href=\"https://vocadb.net/S/{}\">{}</a>", sid, escaped.c_str());
                name_label->set_markup(markup.c_str());
            }
            artist_label->set_label(song->get_artist().c_str());
            vocalist_label->set_label(song->get_vocalists().c_str());
            type_label->set_label(song->get_song_type().c_str());
            date_label->set_label(song->get_publish_date().c_str());
            duration_label->set_label(song->get_duration().c_str());

            auto *binds = new Bindings{};
            binds->paint_bind = Object::bind_property(
                song, SongItem::prop_paintable(),
                image, Gtk::Image::prop_paintable(),
                GObject::BindingFlags::SYNC_CREATE);
            binds->id_conn = id_btn->connect_clicked([sid](Gtk::Button *) {
                auto text = std::to_string(sid);
                Gdk::Display::get_default()->get_clipboard()->set_text(text.c_str());
            });
            std::string nt = song->copy_names_text();
            binds->names_conn = names_btn->connect_clicked([nt = std::move(nt)](Gtk::Button *) {
                Gdk::Display::get_default()->get_clipboard()->set_text(nt.c_str());
            });
            item->set_data("binds", binds, [](gpointer b) { delete static_cast<Bindings*>(b); });
        });
        factory->connect_unbind([](Gtk::SignalListItemFactory *, GObject::Object *obj) {
            auto *item = obj->cast<Gtk::ListItem>();
            delete static_cast<Bindings*>(item->steal_data("binds"));
        });

        auto list_view = Gtk::ListView::create(std::move(selection), std::move(factory));

        auto scrolled = Gtk::ScrolledWindow::create();
        scrolled->set_vexpand(true);
        scrolled->set_policy(Gtk::PolicyType::NEVER, Gtk::PolicyType::AUTOMATIC);
        scrolled->set_child(std::move(list_view));

        auto label_float = Gtk::Label::create("");
        status_label = label_float;
        status_label->set_halign(Gtk::Align::START);

        auto box = Gtk::Box::create(Gtk::Orientation::VERTICAL, 8);
        box->append(std::move(entry_float));
        box->append(std::move(label_float));
        box->append(std::move(scrolled));

        auto toolbar_view = Adw::ToolbarView::create();
        toolbar_view->add_top_bar(Adw::HeaderBar::create());
        toolbar_view->set_content(std::move(box));

        window->set_content(std::move(toolbar_view));

        auto sc = Gtk::ShortcutController::create();
        sc->set_scope(Gtk::Shortcut::Scope::GLOBAL);
        sc->add_shortcut(Gtk::Shortcut::create(
            Gtk::ShortcutTrigger::parse_string("<Control>k"),
            Gtk::CallbackAction::create([this](Gtk::Widget *, GLib::Variant *) -> bool {
                search_entry->set_text("");
                search_entry->grab_focus();
                return true;
            })));
        window->add_controller(std::move(sc).cast<Gtk::EventController>());

        window->present();
    }

    void on_search_changed()
    {
        const char *text = search_entry->get_text();
        if (!text || !*text) return;

        if (cancellable) cancellable->cancel();
        cancellable = Gio::Cancellable::create();

        results->remove_all();
        status_label->set_label("Searching\xe2\x80\xa6");

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

    void on_api_response(GObject::Object *src, Gio::AsyncResult *res)
    {
        UniquePtr<GLib::Error> error;
        auto bytes = static_cast<Soup::Session*>(src)->send_and_read_finish(res, &error);
        if (error) {
            if (error->matches(G_IO_ERROR, G_IO_ERROR_CANCELLED)) return;
            std::println("api error: {}", error->message);
            auto msg = std::format("Error: {}", error->message);
            status_label->set_label(msg.c_str());
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
                if (const auto &url = item->get_thumb_url(); !url.empty())
                    fetch_thumb(item, url);
                ++count;
            }
            auto found_msg = std::format("Found {} results", count);
            status_label->set_label(found_msg.c_str());
        } catch (const std::exception &e) {
            auto err_msg = std::format("Parse error: {}", e.what());
            status_label->set_label(err_msg.c_str());
        }
    }

    void fetch_thumb(RefPtr<SongItem> item, std::string url)
    {
        auto msg = Soup::Message::create(SOUP_METHOD_GET, url.c_str());
        soup_session->send_and_read_async(
            msg, G_PRIORITY_LOW, cancellable,
            [this, item = std::move(item)](GObject::Object *src, Gio::AsyncResult *res) mutable {
                on_thumb_response(std::move(item), src, res);
            });
    }

    void on_thumb_response(RefPtr<SongItem> item, GObject::Object *src, Gio::AsyncResult *res)
    {
        UniquePtr<GLib::Error> error;
        auto bytes = static_cast<Soup::Session*>(src)->send_and_read_finish(res, &error);
        if (error) {
            std::println("thumb error: {}", error->message);
            return;
        }

        UniquePtr<GLib::Error> err;
        auto texture = Gdk::Texture::create_from_bytes(bytes, &err);
        if (err) {
            std::println("thumb texture error: {}", err->message);
            return;
        }
        if (!texture) return;

        item->set_paintable(texture->cast<Gdk::Paintable>());
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
    RefPtr<Application> app = Application::create();
    return app->run(argc, argv);
}
