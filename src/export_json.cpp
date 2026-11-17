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
import vocadb.api;
import vocadb.songs;

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
        if (s.vocadb_id) {
            auto v = std::ranges::find(vocadb::songs, *s.vocadb_id, &vocadb::song::id);
            if (v != std::ranges::end(vocadb::songs) && v->publish_date)
                j["publish_date"] = iso_date(*v->publish_date);
        }
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

/* A C++ string literal holding s. Non-ASCII bytes become octal escapes
 * (at most three digits, so a following digit cannot be swallowed), keeping
 * the file ASCII: MSVC reads unmarked source in the local code page. */
std::string cpp_literal(std::string_view s)
{
    std::string out{'"'};
    for (unsigned char c : s) {
        if (c == '"' || c == '\\')
            out += std::format("\\{:c}", c);
        else if (c < 0x20 || c >= 0x7f)
            out += std::format("\\{:03o}", c);
        else
            out += static_cast<char>(c);
    }
    out += '"';
    return out;
}

/* shows.inc: the live events as C++ designated initializers, for consumers
 * that compile the schedule in (mikuexpocountdown). Each line initializes a
 * struct the consumer defines with exactly these members, declared in this
 * order (designated initializers must follow declaration order):
 *     std::string_view tour;
 *     std::uint64_t vocadb_id;
 *     std::string_view city, venue, tz;
 *     std::chrono::local_seconds start;
 *     std::chrono::minutes duration;
 * and the consumer includes it inside a braced array initializer with
 * std::chrono and std::chrono_literals in scope. Adding, renaming or
 * reordering a member here breaks the consumer's build on purpose: bump
 * export_json::schema_version when doing so. */
std::string export_shows_inc()
{
    using namespace std::chrono;
    std::string out = std::format(
        "// Generated by songbot-export-json. DO NOT EDIT.\n"
        "// https://concert-data.39music.dance/shows.inc, schema {}\n",
        export_json::schema_version);
    for (const auto& e : get_live_events()) {
        const auto local = e.start_time.get_local_time();
        const auto day = floor<days>(local);
        const year_month_day ymd{day};
        const hh_mm_ss tod{local - day};
        std::string start = std::format("local_days{{{}y/{}/{}}} + {}h",
                                        static_cast<int>(ymd.year()),
                                        static_cast<unsigned>(ymd.month()),
                                        static_cast<unsigned>(ymd.day()),
                                        tod.hours().count());
        if (tod.minutes().count())
            start += std::format(" + {}min", tod.minutes().count());
        if (tod.seconds().count())
            start += std::format(" + {}s", tod.seconds().count());
        out += std::format("{{.tour = {}, .vocadb_id = {}, .city = {}, .venue = {}, .tz = {},\n"
                           " .start = {}, .duration = {}min}},\n",
                           cpp_literal(magic_enum::enum_name(e.tour)), e.vocadb_id,
                           cpp_literal(e.city), cpp_literal(e.location_name),
                           cpp_literal(e.start_time.get_time_zone().name), start,
                           e.duration.value_or(default_show_duration).count());
    }
    return out;
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
        {"shows.inc",     export_shows_inc()},
    };
}

}
