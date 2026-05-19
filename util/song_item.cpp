#include "song_item.hpp"
#include <peel/Soup/Message.h>
#include <peel/Soup/Status.h>
#include <peel/Gio/AsyncResult.h>
#include <peel/GLib/GLib.h>
#include <peel/Gdk/Texture.h>
#include <peel/Gly/Gly.h>
#include <peel/GlyGtk4/GlyGtk4.h>
#include <nlohmann/json.hpp>
#include <format>
#include <print>
#include <set>
#include <vector>

using namespace peel;

struct SongData {
    nlohmann::json         json        = nlohmann::json::object();
    RefPtr<Gdk::Paintable> paintable;
    Soup::Session         *session     = nullptr;
    Gio::Cancellable      *cancellable = nullptr;
};

void SongItem::init(Class *) { data = new SongData; }
SongItem::~SongItem() { delete data; }

bool
SongItem::has_cjk(const std::string &s)
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

std::string
SongItem::producer_str(const nlohmann::json &song)
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

std::string
SongItem::vocalist_str(const nlohmann::json &song)
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

RefPtr<SongItem>
SongItem::create(const nlohmann::json &song)
{
    auto item = Object::create<SongItem>();
    item->data->json = song;
    return item;
}

RefPtr<SongItem>
SongItem::create_placeholder(Soup::Session *session, Gio::Cancellable *cancellable)
{
    auto item = Object::create<SongItem>();
    item->data->session     = session;
    item->data->cancellable = cancellable;
    return item;
}

void
SongItem::populate(const nlohmann::json &song)
{
    data->json = song;
    freeze_notify();
    notify(prop_name());
    notify(prop_artist());
    notify(prop_vocalists());
    notify(prop_song_type());
    notify(prop_publish_date());
    notify(prop_duration());
    notify(prop_id());
    notify(prop_japanese_name());
    notify(prop_romaji_name());
    notify(prop_english_name());
    notify(prop_thumb_url());
    thaw_notify();
    fetch_thumb();
}

void
SongItem::fetch_thumb()
{
    if (data->paintable || !data->session) return;
    auto url = std::string(get_thumb_url());
    if (url.empty()) return;

    auto msg = Soup::Message::create(SOUP_METHOD_GET, url.c_str());
    RefPtr<SongItem> ref(this);
    data->session->send_and_read_async(msg, G_PRIORITY_LOW, data->cancellable,
        [ref, msg](GObject::Object *src, Gio::AsyncResult *res) {
            UniquePtr<GLib::Error> error;
            auto bytes = static_cast<Soup::Session *>(src)->send_and_read_finish(res, &error);
            if (error) { std::println("thumb error: {}", error->message); return; }
            if (msg->get_status() != Soup::Status::OK) return;

            auto loader = Gly::Loader::create_for_bytes(bytes);
            loader->load_async(ref->data->cancellable,
                [ref, loader](GObject::Object *src, Gio::AsyncResult *res) {
                    UniquePtr<GLib::Error> error;
                    auto image = static_cast<Gly::Loader *>(src)->load_finish(res, &error);
                    if (error) { std::println("thumb load error: {}", error->message); return; }
                    if (!image) return;

                    image->next_frame_async(ref->data->cancellable,
                        [ref, image](GObject::Object *src, Gio::AsyncResult *res) {
                            UniquePtr<GLib::Error> error;
                            auto frame = static_cast<Gly::Image *>(src)->next_frame_finish(res, &error);
                            if (error) { std::println("thumb frame error: {}", error->message); return; }
                            if (!frame) return;

                            auto texture = GlyGtk4::frame_get_texture(frame);
                            ref->set_paintable(texture->cast<Gdk::Paintable>());
                        });
                });
        });
}

peel::String
SongItem::get_name() const
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

peel::String SongItem::get_artist()    const { return peel::String(producer_str(data->json).c_str()); }
peel::String SongItem::get_vocalists() const { return peel::String(vocalist_str(data->json).c_str()); }
peel::String SongItem::get_song_type() const { return peel::String(data->json.value("songType", "").c_str()); }

peel::String
SongItem::get_publish_date() const
{
    if (data->json.contains("publishDate") && !data->json["publishDate"].is_null()) {
        auto raw = data->json["publishDate"].get<std::string>();
        if (raw.size() >= 10) return peel::String(raw.c_str(), 10);
    }
    return peel::String("");
}

peel::String
SongItem::get_duration() const
{
    if (int secs = data->json.value("lengthSeconds", 0); secs > 0) {
        auto s = std::format("{}:{:02}", secs / 60, secs % 60);
        return peel::String(s.c_str());
    }
    return peel::String("");
}

int SongItem::get_id() const { return data->json.value("id", 0); }

peel::String
SongItem::get_japanese_name() const
{
    if (auto it = data->json.find("names"); it != data->json.end())
        for (const auto &n : *it)
            if (n.value("language", "") == "Japanese")
                return peel::String(n.value("value", "").c_str());
    return peel::String("");
}

peel::String
SongItem::get_romaji_name() const
{
    if (auto it = data->json.find("names"); it != data->json.end())
        for (const auto &n : *it)
            if (n.value("language", "") == "Romaji")
                return peel::String(n.value("value", "").c_str());
    return peel::String("");
}

peel::String
SongItem::get_english_name() const
{
    if (auto it = data->json.find("names"); it != data->json.end())
        for (const auto &n : *it)
            if (n.value("language", "") == "English")
                return peel::String(n.value("value", "").c_str());
    return peel::String("");
}

peel::String
SongItem::get_thumb_url() const
{
    if (data->json.contains("mainPicture") && !data->json["mainPicture"].is_null())
        return peel::String(data->json["mainPicture"].value("urlThumb", "").c_str());
    return peel::String("");
}

static Gdk::Paintable *
placeholder_paintable()
{
    static auto tex = Gdk::Texture::create_from_resource("/bot/hatsune/SongSearcher/leek-placeholder.svg");
    return tex->cast<Gdk::Paintable>();
}

Gdk::Paintable *SongItem::get_paintable() const
{
    if (data->paintable) return data->paintable;
    return placeholder_paintable();
}

void
SongItem::set_paintable(Gdk::Paintable *p)
{
    if (p) data->paintable = RefPtr<Gdk::Paintable>(p);
    else   data->paintable = {};
    notify(prop_paintable());
}

std::string
SongItem::copy_names_text() const
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

void SongItem::Class::init() {}
PEEL_CLASS_IMPL(SongItem, "SongSearcherItem", GObject::Object)
