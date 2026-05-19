#pragma once
#include <peel/GObject/Object.h>
#include <peel/class.h>
#include <peel/String.h>
#include <peel/RefPtr.h>
#include <peel/Gdk/Paintable.h>
#include <peel/Soup/Session.h>
#include <peel/Gio/Cancellable.h>
#include <peel/coro/SimpleTask.h>
#include <nlohmann/json.hpp>
#include <string>

struct SongData;

class SongItem final : public peel::GObject::Object
{
    PEEL_SIMPLE_CLASS(SongItem, peel::GObject::Object);

    SongData *data = nullptr;

    void init(Class *);
    ~SongItem();
    peel::coro::SimpleTask fetch_thumb();

    static bool has_cjk(const std::string &s);
    static std::string producer_str(const nlohmann::json &song);
    static std::string vocalist_str(const nlohmann::json &song);

public:
    static peel::RefPtr<SongItem> create(const nlohmann::json &song);
    static peel::RefPtr<SongItem> create_placeholder(peel::Soup::Session *session, peel::Gio::Cancellable *cancellable);
    void populate(const nlohmann::json &song);

    peel::String get_name() const;
    peel::String get_artist() const;
    peel::String get_vocalists() const;
    peel::String get_song_type() const;
    peel::String get_publish_date() const;
    peel::String get_duration() const;
    int get_id() const;
    peel::String get_japanese_name() const;
    peel::String get_romaji_name() const;
    peel::String get_english_name() const;
    peel::String get_thumb_url() const;
    peel::Gdk::Paintable *get_paintable() const;
    void set_paintable(peel::Gdk::Paintable *p);

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
    PEEL_PROPERTY(peel::Gdk::Paintable, paintable, "paintable")

    std::string copy_names_text() const;

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
