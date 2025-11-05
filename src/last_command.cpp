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

#include "last_command.hpp"
#include "context.hpp"

last_command::last_command(context &ctx) noexcept :
    iface_command(ctx, "last", "Song details")
{
    /* Metric: last command */
    last_success_counter = &ctx.slashcommand_counter->Add({{"command", "last"}, {"result", "success"}});
    last_failure_counter = &ctx.slashcommand_counter->Add({{"command", "last"}, {"result", "failure"}});

    /* Metric: Autocompletions */
    ac_last_success_counter = &ctx.autocompletion_counter->Add({{"event", "last"}, {"result", "success"}});
    ac_last_no_match_counter = &ctx.autocompletion_counter->Add({{"event", "last"}, {"result", "no-match"}});
    ac_last_failure_counter = &ctx.autocompletion_counter->Add({{"event", "last"}, {"result", "failure"}});
}

dpp::slashcommand
last_command::get_command()
{
    auto last_cmd = iface_command::get_command();
    auto event_opt = dpp::command_option(dpp::command_option_type::co_string, "song", "Name of song, e.g. Melt", true);
    event_opt.set_auto_complete(true);

    last_cmd.add_option(std::move(event_opt));
    return last_cmd;
}

std::expected<void, std::error_code>
last_command::on_slashcommand(const dpp::slashcommand_t& event)
{
    auto param = std::get<std::string>(event.get_parameter("song"));
    auto song = lookup_song(param);
    if (!song) {
        auto songs = match_songs(param);
        if (songs.size() == 1) {
            song = songs.front();
        }
    }
    if (!song) {
        auto msg = dpp::message(std::format("I'm sorry, I don't know about the song '{}'", param)).set_flags(dpp::message_flags::m_ephemeral);
        event.reply(msg);
        last_failure_counter->Increment();
        return {};
    }


    auto rng = std::views::filter(std::views::reverse(setlists), [&name = song->name](const auto& track) { return name == track.song;}) |
        std::views::filter([](const auto& track) {
            auto concert = lookup_concert(track.concert_short_name);
            using namespace std::literals;
            return (std::chrono::system_clock::now() - static_cast<std::chrono::sys_days>(concert->date)) > (24h * 30);
        });
    if (std::ranges::empty(rng)) {
        auto msg = dpp::message(std::format("I'm sorry, '{}' isn't in a concert I know about yet.", param)).set_flags(dpp::message_flags::m_ephemeral);
        event.reply(msg);
        last_failure_counter->Increment();
        return {};
    }

    auto count = std::ranges::distance(rng);

    std::ostringstream ss;
    using namespace std::literals;
    ss << std::format("{} last played at {}. ", *song, lookup_concert(std::ranges::begin(rng)->concert_short_name)->name);
    if (song->published != 0y/0/0) {
        ss << std::format("It was published {}. ", song->published);
    }

    auto remaining = std::views::drop(rng, 1);
    if (std::ranges::empty(remaining)) {
        ss << "That's the only time its played!";
    } else {
        ss << "Prior to that: ";
        ss << tour_to_string(std::ranges::begin(remaining)->concert_short_name);
        for (auto track : std::views::drop(remaining, 1)) {
            ss << ", " << tour_to_string(track.concert_short_name);
        }
        ss << ". " << count << " times total.";
        ss << " Frequency Rank " << get_song_frequency_rank(song->name);
    }

    event.reply(ss.view());
    last_success_counter->Increment();
    return {};
}

std::expected<dpp::interaction_response, std::error_code>
last_command::on_autocomplete_impl(const dpp::autocomplete_t& event)
{
    for (auto & opt : event.options | std::views::filter(&dpp::command_option::focused)) {
        try {
            std::string uservalue = std::get<std::string>(opt.value);

            auto matches = match_songs(uservalue);
            if (matches.empty()) {
                return std::unexpected(songbot_error::autocomplete_no_match);
            }

            auto resp = dpp::interaction_response(dpp::ir_autocomplete_reply);
            for (const auto& song : matches | std::views::take(AUTOCOMPLETE_MAX_CHOICES) ) {
                resp.add_autocomplete_choice(dpp::command_option_choice(std::string(song.name), std::string(song.name)));
            }

            return resp;
        } catch (std::bad_variant_access &e) {
            ctx->bot->log(dpp::ll_error, std::format("/last: autocomplete error: {}", e.what()));
            return std::unexpected(std::make_error_code(std::errc::invalid_argument));
        }
    }

    return std::unexpected(songbot_error::autocomplete_no_focused_option);
}

std::expected<dpp::interaction_response, std::error_code>
last_command::on_autocomplete(const dpp::autocomplete_t& event)
{
    auto res = on_autocomplete_impl(event);
    if (res) {
        ac_last_success_counter->Increment();
    } else {
        bool is_no_match = res.error().category() == get_songbot_error_category() &&
            res.error().value() == std::to_underlying(songbot_error::autocomplete_no_match);
        if (is_no_match) {
            ac_last_no_match_counter->Increment();
        } else {
            ac_last_failure_counter->Increment();
        }
    }

    return res;
}
