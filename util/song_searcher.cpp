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
#include <string>
#include <format>
#include <print>
#include <set>
#include <vector>

using namespace peel;

struct SongData {
    nlohmann::json json;
    RefPtr<Gdk::Paintable> paintable;
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
        auto item = Object::create<SongItem>();
        item->data->json = song;
        return item;
    }

    peel::String get_name() const
    {
        std::string english_name, romaji_name;
        if (auto it = data->json.find("names"); it != data->json.end()) {
            for (const auto &n : *it) {
                auto lang = n.value("language", "");
                if (lang == "English" && english_name.empty()) english_name = n.value("value", "");
                else if (lang == "Romaji" && romaji_name.empty()) romaji_name = n.value("value", "");
            }
        }
        if (!english_name.empty()) return peel::String(english_name.c_str());
        if (!romaji_name.empty())  return peel::String(romaji_name.c_str());
        return peel::String(data->json.value("name", "").c_str());
    }

    peel::String get_artist()    const { return peel::String(producer_str(data->json).c_str()); }
    peel::String get_vocalists() const { return peel::String(vocalist_str(data->json).c_str()); }
    peel::String get_song_type() const { return peel::String(data->json.value("songType", "").c_str()); }

    peel::String get_publish_date() const
    {
        if (data->json.contains("publishDate") && !data->json["publishDate"].is_null()) {
            auto raw = data->json["publishDate"].get<std::string>();
            if (raw.size() >= 10) return peel::String(raw.c_str(), 10);
        }
        return peel::String("");
    }

    peel::String get_duration() const
    {
        if (int secs = data->json.value("lengthSeconds", 0); secs > 0) {
            auto s = std::format("{}:{:02}", secs / 60, secs % 60);
            return peel::String(s.c_str());
        }
        return peel::String("");
    }

    int get_id() const { return data->json.value("id", 0); }

    peel::String get_japanese_name() const
    {
        if (auto it = data->json.find("names"); it != data->json.end())
            for (const auto &n : *it)
                if (n.value("language", "") == "Japanese")
                    return peel::String(n.value("value", "").c_str());
        return peel::String("");
    }

    peel::String get_romaji_name() const
    {
        if (auto it = data->json.find("names"); it != data->json.end())
            for (const auto &n : *it)
                if (n.value("language", "") == "Romaji")
                    return peel::String(n.value("value", "").c_str());
        return peel::String("");
    }

    peel::String get_english_name() const
    {
        if (auto it = data->json.find("names"); it != data->json.end())
            for (const auto &n : *it)
                if (n.value("language", "") == "English")
                    return peel::String(n.value("value", "").c_str());
        return peel::String("");
    }

    peel::String get_thumb_url() const
    {
        if (data->json.contains("mainPicture") && !data->json["mainPicture"].is_null())
            return peel::String(data->json["mainPicture"].value("urlThumb", "").c_str());
        return peel::String("");
    }

    Gdk::Paintable *get_paintable() const { return data->paintable; }

    void set_paintable(Gdk::Paintable *p)
    {
        if (p) data->paintable = RefPtr<Gdk::Paintable>(p);
        else   data->paintable = {};
        notify(prop_paintable());
    }

    PEEL_PROPERTY(const char *, name,          "name")
    PEEL_PROPERTY(const char *, artist,        "artist")
    PEEL_PROPERTY(const char *, vocalists,     "vocalists")
    PEEL_PROPERTY(const char *, song_type,     "song-type")
    PEEL_PROPERTY(const char *, publish_date,  "publish-date")
    PEEL_PROPERTY(const char *, duration,      "duration")
    PEEL_PROPERTY(int,          id,            "id")
    PEEL_PROPERTY(const char *, japanese_name, "japanese-name")
    PEEL_PROPERTY(const char *, romaji_name,   "romaji-name")
    PEEL_PROPERTY(const char *, english_name,  "english-name")
    PEEL_PROPERTY(const char *, thumb_url,     "thumb-url")
    PEEL_PROPERTY(Gdk::Paintable, paintable,   "paintable")

    std::string copy_names_text() const
    {
        const auto &j = data->json;
        std::string japanese_name, romaji_name, english_name;
        if (auto it = j.find("names"); it != j.end()) {
            for (const auto &n : *it) {
                auto lang = n.value("language", "");
                if (lang == "Japanese")     japanese_name = n.value("value", "");
                else if (lang == "Romaji")  romaji_name   = n.value("value", "");
                else if (lang == "English") english_name  = n.value("value", "");
            }
        }
        auto qfmt = [](const std::string &s) -> std::string {
            if (s.empty()) return "nullopt";
            return std::format("\"{}\"", s);
        };
        auto vocal = vocalist_str(j);
        return std::format("{{{}, {}, {}, {}, {}, {} }},",
            qfmt(japanese_name), qfmt(romaji_name), qfmt(english_name),
            vocal.empty() ? "nullopt" : vocal, qfmt(producer_str(j)), j.value("id", 0));
    }

private:
    template<typename F>
    static void define_properties(F &f)
    {
        f.prop(prop_name(),          nullptr).get(&SongItem::get_name);
        f.prop(prop_artist(),        nullptr).get(&SongItem::get_artist);
        f.prop(prop_vocalists(),     nullptr).get(&SongItem::get_vocalists);
        f.prop(prop_song_type(),     nullptr).get(&SongItem::get_song_type);
        f.prop(prop_publish_date(),  nullptr).get(&SongItem::get_publish_date);
        f.prop(prop_duration(),      nullptr).get(&SongItem::get_duration);
        f.prop(prop_id(),            0, G_MAXINT, 0).get(&SongItem::get_id);
        f.prop(prop_japanese_name(), nullptr).get(&SongItem::get_japanese_name);
        f.prop(prop_romaji_name(),   nullptr).get(&SongItem::get_romaji_name);
        f.prop(prop_english_name(),  nullptr).get(&SongItem::get_english_name);
        f.prop(prop_thumb_url(),     nullptr).get(&SongItem::get_thumb_url);
        f.prop(prop_paintable())
         .get(&SongItem::get_paintable)
         .set(&SongItem::set_paintable);
    }
};

void SongItem::Class::init() {}
PEEL_CLASS_IMPL(SongItem, "SongSearcherItem", GObject::Object)


class PrimarySongDataCell final : public Gtk::Box
{
    PEEL_SIMPLE_CLASS(PrimarySongDataCell, Gtk::Box);

    struct Members {
        Gtk::Label *name_label;
        Gtk::Label *artist_label;
        Gtk::Label *vocalist_label;
    } m;

    RefPtr<GObject::Binding> name_bind;
    RefPtr<GObject::Binding> artist_bind;
    RefPtr<GObject::Binding> vocalist_bind;

    void init(Class *);
    void vfunc_dispose();

public:
    static FloatPtr<PrimarySongDataCell> create();
    void bind(SongItem *song);
    void unbind();
};

void
PrimarySongDataCell::Class::init()
{
    override_vfunc_dispose<PrimarySongDataCell>();
    set_template_from_resource("/bot/hatsune/SongSearcher/primary_song_data_cell.ui");
    PEEL_WIDGET_TEMPLATE_BIND_CHILD(PrimarySongDataCell, m.name_label,     "name-label");
    PEEL_WIDGET_TEMPLATE_BIND_CHILD(PrimarySongDataCell, m.artist_label,   "artist-label");
    PEEL_WIDGET_TEMPLATE_BIND_CHILD(PrimarySongDataCell, m.vocalist_label, "vocalist-label");
}

void
PrimarySongDataCell::init(Class *)
{
    new (&m) Members;
    init_template();
}

void
PrimarySongDataCell::vfunc_dispose()
{
    dispose_template(Type::of<PrimarySongDataCell>());
    parent_vfunc_dispose<PrimarySongDataCell>();
}

FloatPtr<PrimarySongDataCell>
PrimarySongDataCell::create()
{
    return Object::create<PrimarySongDataCell>();
}

void
PrimarySongDataCell::bind(SongItem *song)
{
    int sid = song->get_id();
    name_bind = Object::bind_property(
        song, SongItem::prop_name(),
        m.name_label, Gtk::Label::prop_label(),
        GObject::BindingFlags::SYNC_CREATE,
        [sid](const char *name) -> peel::String {
            auto escaped = GLib::markup_escape_text(name, -1);
            auto link = std::format("<a href=\"https://vocadb.net/S/{}\">{}</a>", sid, escaped.c_str());
            return peel::String(link.c_str());
        });
    artist_bind = Object::bind_property(
        song, SongItem::prop_artist(),
        m.artist_label, Gtk::Label::prop_label(),
        GObject::BindingFlags::SYNC_CREATE);
    vocalist_bind = Object::bind_property(
        song, SongItem::prop_vocalists(),
        m.vocalist_label, Gtk::Label::prop_label(),
        GObject::BindingFlags::SYNC_CREATE);
}

void
PrimarySongDataCell::unbind()
{
    if (name_bind)     { name_bind->unbind();     name_bind = {}; }
    if (artist_bind)   { artist_bind->unbind();   artist_bind = {}; }
    if (vocalist_bind) { vocalist_bind->unbind(); vocalist_bind = {}; }
}

PEEL_CLASS_IMPL(PrimarySongDataCell, "SongSearcherPrimarySongDataCell", Gtk::Box)


class SecondarySongDataCell final : public Gtk::Box
{
    PEEL_SIMPLE_CLASS(SecondarySongDataCell, Gtk::Box);

    struct Members {
        Gtk::Label *type_label;
        Gtk::Label *date_label;
        Gtk::Label *duration_label;
    } m;

    RefPtr<GObject::Binding> type_bind;
    RefPtr<GObject::Binding> date_bind;
    RefPtr<GObject::Binding> dur_bind;

    void init(Class *);
    void vfunc_dispose();

public:
    static FloatPtr<SecondarySongDataCell> create();
    void bind(SongItem *song);
    void unbind();
};

void
SecondarySongDataCell::Class::init()
{
    override_vfunc_dispose<SecondarySongDataCell>();
    set_template_from_resource("/bot/hatsune/SongSearcher/secondary_song_data_cell.ui");
    PEEL_WIDGET_TEMPLATE_BIND_CHILD(SecondarySongDataCell, m.type_label,     "type-label");
    PEEL_WIDGET_TEMPLATE_BIND_CHILD(SecondarySongDataCell, m.date_label,     "date-label");
    PEEL_WIDGET_TEMPLATE_BIND_CHILD(SecondarySongDataCell, m.duration_label, "duration-label");
}

void
SecondarySongDataCell::init(Class *)
{
    new (&m) Members;
    init_template();
}

void
SecondarySongDataCell::vfunc_dispose()
{
    dispose_template(Type::of<SecondarySongDataCell>());
    parent_vfunc_dispose<SecondarySongDataCell>();
}

FloatPtr<SecondarySongDataCell>
SecondarySongDataCell::create()
{
    return Object::create<SecondarySongDataCell>();
}

void
SecondarySongDataCell::bind(SongItem *song)
{
    type_bind = Object::bind_property(
        song, SongItem::prop_song_type(),
        m.type_label, Gtk::Label::prop_label(),
        GObject::BindingFlags::SYNC_CREATE);
    date_bind = Object::bind_property(
        song, SongItem::prop_publish_date(),
        m.date_label, Gtk::Label::prop_label(),
        GObject::BindingFlags::SYNC_CREATE);
    dur_bind = Object::bind_property(
        song, SongItem::prop_duration(),
        m.duration_label, Gtk::Label::prop_label(),
        GObject::BindingFlags::SYNC_CREATE);
}

void
SecondarySongDataCell::unbind()
{
    if (type_bind) { type_bind->unbind(); type_bind = {}; }
    if (date_bind) { date_bind->unbind(); date_bind = {}; }
    if (dur_bind)  { dur_bind->unbind();  dur_bind = {}; }
}

PEEL_CLASS_IMPL(SecondarySongDataCell, "SongSearcherSecondarySongDataCell", Gtk::Box)


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
