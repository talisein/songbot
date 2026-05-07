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

import util;
import concerts;
import songs;
import songbot.errors;
import vocadb.api;
import vocadb.songs;

#include "freq_command.hpp"
#include "context.hpp"
#include "formatters.hpp"
#include "paged_widget.hpp"

freq_command::freq_command(context &ctx) noexcept :
    iface_command(ctx, "freq", "List the most frequent live songs")
{
    /* Metric: freq command */
    freq_success_counter = &ctx.slashcommand_counter->Add({{"command", "freq"}, {"result", "success"}});
    freq_failure_counter = &ctx.slashcommand_counter->Add({{"command", "freq"}, {"result", "failure"}});
}

dpp::slashcommand
freq_command::get_command()
{
    auto freq_cmd = iface_command::get_command();

    return freq_cmd;
}


dpp::task<std::expected<void, std::error_code>>
freq_command::on_slashcommand(const dpp::slashcommand_t event)
{
    constexpr size_t step = 25;
    auto make_page = [&](size_t start_idx) -> std::string {
        std::ostringstream ss;
        for (auto const [idx, song_freq] : std::views::enumerate(song_frequencies)
                                         | std::views::drop(start_idx)
                                         | std::views::take(step)) {
            auto song = lookup_song(song_freq.song_name, song_freq.producer);
            if (song) std::println(ss, "{}. `{:2d}x` {}", idx + 1, song_freq.count, *song);
            else       std::println(ss, "{}. `{:2d}x` {}", idx + 1, song_freq.count, song_freq.song_name);
        }
        return ss.str();
    };
    co_return co_await run_paged_widget(event, ctx, song_frequencies.size(), step, make_page,
                                        freq_success_counter, freq_failure_counter);
}

std::expected<dpp::interaction_response, std::error_code>
freq_command::on_autocomplete(const dpp::autocomplete_t& event)
{
  return std::unexpected(std::make_error_code(std::errc::invalid_argument));
}
