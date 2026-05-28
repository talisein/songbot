/*
    Songbot: Hatsune Miku Concert Database for Discord
    Copyright (C) 2025  Andrew Potter

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

import songs;
import util;
import concerts;
import vocadb.events;
import songbot.errors;
import uni_algo;

#include "setlistlast_command.hpp"
#include "context.hpp"
#include "formatters.hpp"

namespace {
    static std::vector<std::string>
    get_setlistlast_lines(const Concert& concert)
    {
        std::vector<std::string> lines;
        if (concert.date > util::get_build_date()) {
            lines.push_back(std::format("{} will first play on {}. I won't know the setlist until after that.",
                                           concert.name, concert.date));
            return lines;
        }

        auto setlistlast = get_setlist(concert.short_name);
        for (auto &track : setlistlast) {
            auto song = lookup_song(track.song, track.producer);
            if (!song) {
                lines.push_back(std::format("{}. 🫠 '{}' I guess? This is a bug...\n", track.pos, track.song));
                continue;
            }
            /* Drop the concerts that occurred after the requested concert... */
            auto rng = std::views::drop_while(std::views::reverse(setlists), [&](const auto &track)
            {
                return track.concert_short_name != concert.short_name;
            /* Drop the tracks for the requested concert... */
            }) | std::views::drop_while([&](const auto &track)
            {
                return track.concert_short_name == concert.short_name;
            /* Match the remaining cases where the song name matches */
            }) | std::views::filter([&](const auto &track)
            {
                return track.song == song->name;
            });

            std::ostringstream ss;

            using namespace std::literals;
            ss << std::format("- {}. {}",
                              track.pos,
                              track.variant.transform([](const auto& v) { return std::format("`{}` ", v); }).value_or(""s));
            if (song->vocadb_id || track.remix_id) {
              auto id = track.remix_id.or_else([&] { return song->vocadb_id; });
              ss << '[' << util::escape_markdown(song->name, true);
              if (track.remix) {
                ss << ' ' << util::escape_markdown(*track.remix, true);
              }
              ss << "](https://vocadb.net/S/" << *id << ')';
            } else {
                ss << util::escape_markdown(song->name);
                if (track.remix) {
                  ss << ' ' << util::escape_markdown(*track.remix);
                }
            }

            if (song->singer != NO_VIRTUAL_SINGER) {
                ss << " feat. ";
                track_singer_emoji(ss, track, *song);
            }
            ss << " by " << util::escape_markdown(song->producer);

            if (std::ranges::empty(rng)) {
                ss << " **LIVE DEBUT**";
            } else {
                ss << " *Previous: "
                   << tour_to_string(std::ranges::begin(rng)->concert_short_name)
                   << "*";
            }
            ss << "\n";
            lines.push_back(ss.str());
        }

        return lines;
    }
}

setlistlast_command::setlistlast_command(context& ctx) noexcept :
    setlist_base_command(ctx, "setlistlast", "Full Concert Setlist with each song's previous appearance")
{
}

std::vector<std::string>
setlistlast_command::get_body_lines(const Concert& concert)
{
    return get_setlistlast_lines(concert);
}
