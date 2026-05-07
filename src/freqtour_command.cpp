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
import magic_enum;

#include "freqtour_command.hpp"
#include "context.hpp"
#include "formatters.hpp"
#include "paged_widget.hpp"

freqtour_command::freqtour_command(context &ctx) noexcept :
    iface_command(ctx, "freqtour", "List the most frequent live songs for a concert series")
{
    /* Metric: freq command */
    freqtour_success_counter = &ctx.slashcommand_counter->Add({{"command", "freqtour"}, {"result", "success"}});
    freqtour_failure_counter = &ctx.slashcommand_counter->Add({{"command", "freqtour"}, {"result", "failure"}});
}

dpp::slashcommand
freqtour_command::get_command()
{
    auto freqtour_cmd = iface_command::get_command();

    auto series_opt = dpp::command_option(dpp::command_option_type::co_string, "series", "Name of tour series, e.g. MIKU_EXPO", true);
    constexpr std::array supported { MIKU_EXPO, MAGICAL_MIRAI, MIKUPA, MIKU_WITH_YOU, SNOW_MIKU };
    for (const auto& s : supported) {
      series_opt.add_choice(dpp::command_option_choice(std::string(magic_enum::enum_name(s)), std::string(magic_enum::enum_name(s))));
    }

    freqtour_cmd.add_option(std::move(series_opt));

    return freqtour_cmd;
}


dpp::task<std::expected<void, std::error_code>>
freqtour_command::on_slashcommand(const dpp::slashcommand_t event)
{
    using namespace std::literals;
    constexpr auto freqs_for_series = [](ConcertSeries series) constexpr -> std::span<const song_frequency, std::dynamic_extent> {
      switch (series) {
        case MIKU_EXPO: return song_frequencies_expo;
        case MAGICAL_MIRAI: return song_frequencies_mirai;
        case MIKU_WITH_YOU: return song_frequencies_mwy;
        case MIKUPA: return song_frequencies_mikupa;
        case SNOW_MIKU: return song_frequencies_snowmiku;
        default:
        throw songbot_error::no_match;
      }
    };


    ConcertSeries series;
    std::span<const song_frequency, std::dynamic_extent> queried_frequencies;
    try {
      const auto series_str = std::get<std::string>(event.get_parameter("series"));
      auto series_opt = magic_enum::enum_cast<ConcertSeries>(series_str, magic_enum::case_insensitive);

      if (!series_opt.has_value()) {
        dpp::message m{std::format("I'm sorry, I don't know about a concert series named '{}'", series_str)};
        m.set_flags(dpp::message_flags::m_ephemeral);
        auto e = co_await util::reply_handler_new(event.co_reply(m), ctx, freqtour_success_counter, freqtour_failure_counter);
        co_return std::unexpected(e.error_or(songbot_error::no_match));
      } else {
        queried_frequencies = freqs_for_series(*series_opt);
        series = *series_opt;
      }
    } catch(std::exception &e) {
      dpp::message m{std::format("I'm sorry, I couldn't understand what concert series you asked about.")};
      m.set_flags(dpp::message_flags::m_ephemeral);
      event.reply(m);
      freqtour_failure_counter->Increment();
      co_return std::unexpected(songbot_error::no_match);
    } catch(songbot_error &e) {
      dpp::message m{std::format("I'm sorry, I don't have frequency data for that series.")};
      m.set_flags(dpp::message_flags::m_ephemeral);
      event.reply(m);
      freqtour_failure_counter->Increment();
      co_return std::unexpected(songbot_error::no_match);
    }

    constexpr size_t step = 25;
    auto make_page = [&](size_t start_idx) -> std::string {
        std::ostringstream ss;
        std::println(ss, "# Song Frequency for Tour Series {}", magic_enum::enum_name(series));
        for (auto const [idx, song_freq] : std::views::enumerate(queried_frequencies)
                                         | std::views::drop(start_idx)
                                         | std::views::take(step)) {
            auto song = lookup_song(song_freq.song_name, song_freq.producer);
            if (song) std::println(ss, "{}. `{:2d}x` {}", idx + 1, song_freq.count, *song);
            else       std::println(ss, "{}. `{:2d}x` {}", idx + 1, song_freq.count, song_freq.song_name); // FIXME: METEOR & Meteor
        }
        return ss.str();
    };
    co_return co_await run_paged_widget(event, ctx, queried_frequencies.size(), step, make_page,
                                        freqtour_success_counter, freqtour_failure_counter);
}

std::expected<dpp::interaction_response, std::error_code>
freqtour_command::on_autocomplete(const dpp::autocomplete_t& event)
{
  return std::unexpected(std::make_error_code(std::errc::invalid_argument));
}
