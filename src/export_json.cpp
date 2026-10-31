/*
    Songbot: Hatsune Miku Concert Database for Discord
    Copyright (C) 2026  Andrew Potter

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

import std;
import nlohmann.json;
import magic_enum;
import songs;
import concerts;
import project_diva;
import project_sekai;

#include "export_json.hpp"

namespace {

using json = nlohmann::json;

/* Optionals are omitted rather than written as null */
template <typename T>
void set_opt(json& j, const char* key, const std::optional<T>& v)
{
    if (v)
        j[key] = *v;
}

json singers_array(Singer s)
{
    auto arr = json::array();
    for (auto flag : magic_enum::enum_values<Singer>()) {
        if (flag != NO_VIRTUAL_SINGER && (s & flag) == flag)
            arr.push_back(magic_enum::enum_name(flag));
    }
    return arr;
}

std::string iso_date(const std::chrono::year_month_day& ymd)
{
    return std::format("{:%F}", ymd);
}

json wrap(json data)
{
    return json{{"schema_version", export_json::schema_version}, {"data", std::move(data)}};
}

json export_songs()
{
    auto arr = json::array();
    for (const auto& s : songs) {
        json j;
        j["name"] = s.name;
        set_opt(j, "jp_name", s.jp_name);
        set_opt(j, "romaji_name", s.romanji_name);
        j["producer"] = s.producer;
        j["singers"] = singers_array(s.singer);
        if (s.minor_roles)
            j["minor_roles"] = singers_array(*s.minor_roles);
        set_opt(j, "vocadb_id", s.vocadb_id);
        set_opt(j, "disambiguation", s.disambiguation);
        arr.push_back(std::move(j));
    }
    return wrap(std::move(arr));
}

json export_concerts()
{
    auto arr = json::array();
    for (const auto& c : concerts) {
        json j;
        j["tour"] = magic_enum::enum_name(c.short_name);
        j["tour_display"] = tour_to_string(c.short_name);
        j["series"] = magic_enum::enum_name(c.series);
        j["name"] = c.name;
        j["date"] = iso_date(c.date);
        if (c.last_date)
            j["last_date"] = iso_date(*c.last_date);
        set_opt(j, "vocadb_event_id", c.vocadb_event_id);

        auto setlist = json::array();
        for (const auto& t : setlists) {
            if (t.concert_short_name != c.short_name)
                continue;
            json track;
            track["pos"] = t.pos;
            track["song"] = t.song;
            set_opt(track, "producer", t.producer);
            set_opt(track, "variant", t.variant);
            set_opt(track, "remix", t.remix);
            set_opt(track, "remix_id", t.remix_id);
            auto song = std::ranges::find_if(songs, [&t](const Song& s) { return exact_song_track_match(s, t); });
            if (song != std::ranges::end(songs))
                set_opt(track, "song_vocadb_id", song->vocadb_id);
            setlist.push_back(std::move(track));
        }
        j["setlist"] = std::move(setlist);
        arr.push_back(std::move(j));
    }
    return wrap(std::move(arr));
}

json export_events()
{
    using namespace std::chrono;
    auto arr = json::array();
    for (const auto& e : get_live_events()) {
        const auto local = e.start_time.get_local_time();
        const auto sys = e.start_time.get_sys_time();
        json j;
        j["tour"] = magic_enum::enum_name(e.tour);
        j["vocadb_event_id"] = e.vocadb_id;
        j["start_local"] = std::format("{:%FT%T}", local);
        j["start_utc"] = std::format("{:%FT%TZ}", sys);
        j["start_unix"] = sys.time_since_epoch().count();
        j["tz"] = e.start_time.get_time_zone().name;
        j["duration_minutes"] = e.duration.value_or(default_show_duration).count();
        j["location_name"] = e.location_name;
        j["city"] = e.city;
        j["location_link"] = e.location_link;
        arr.push_back(std::move(j));
    }
    return wrap(std::move(arr));
}

json export_diva()
{
    auto arr = json::array();
    for (const auto& t : diva_tracks) {
        json j;
        j["game"] = magic_enum::enum_name(t.game);
        j["song"] = t.song;
        set_opt(j, "producer", t.producer);
        set_opt(j, "variant", t.variant);
        set_opt(j, "remix", t.remix);
        set_opt(j, "remix_id", t.remix_id);
        arr.push_back(std::move(j));
    }
    return wrap(std::move(arr));
}

json export_sekai()
{
    auto arr = json::array();
    for (const auto& t : sekai_tracks) {
        json j;
        set_opt(j, "id", t.id);
        j["unit"] = magic_enum::enum_name(t.unit);
        j["song"] = t.song;
        set_opt(j, "producer", t.producer);
        set_opt(j, "remix", t.remix);
        set_opt(j, "remix_id", t.remix_id);
        arr.push_back(std::move(j));
    }
    return wrap(std::move(arr));
}

std::string dump(const json& j)
{
    return j.dump(1, '\t') + '\n';
}

} // namespace

namespace export_json {

std::vector<file> export_all()
{
    return {
        {"songs.json",    dump(export_songs())},
        {"concerts.json", dump(export_concerts())},
        {"events.json",   dump(export_events())},
        {"diva.json",     dump(export_diva())},
        {"sekai.json",    dump(export_sekai())},
    };
}

}
