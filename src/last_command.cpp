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
import songs;
import songbot.errors;

#include "last_command.hpp"
#include "last_shared.hpp"
#include "context.hpp"
#include "formatters.hpp"

namespace
{
  using namespace std::literals;
  constexpr std::string_view INDEX_PREFIX {"idx:"sv};
}

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

    prometheus::Histogram::BucketBoundaries buckets {0.0001, 0.00025, 0.0005, 0.001, 0.0025, 0.005, 0.01, 0.025, 0.05, 0.1, 0.25, 0.5, 1.0};
    prometheus::Labels labels {{"command", "last"}};
    autocomplete_latency = &ctx.autocomplete_latency->Add(labels, buckets);
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

dpp::task<std::expected<void, std::error_code>>
last_command::on_slashcommand(const dpp::slashcommand_t event)
{
    auto param = std::get<std::string>(event.get_parameter("song"));

    auto song_result = resolve_song_from_param(param, ctx,
        [](std::string_view p) -> std::expected<Song, std::string> {
            if (auto s = lookup_song(p)) return *s;
            auto matches = match_songs(p);
            if (matches.size() == 1) return matches.front();
            if (matches.empty()) return std::unexpected("I'm sorry, I don't know a song by that name"s);
            std::ostringstream ss;
            std::print(ss, "{} songs match '{}', including {}", matches.size(), p, matches.front().name);
            for (const auto& s : matches | std::views::drop(1) | std::views::take(5))
                std::print(ss, ", {}", s.name);
            ss << "...";
            return std::unexpected(ss.str());
        });

    if (!song_result) {
        auto msg = dpp::message(song_result.error()).set_flags(dpp::message_flags::m_ephemeral);
        auto e = co_await util::reply_handler_new(event.co_reply(msg), ctx, last_success_counter, last_failure_counter);
        co_return std::unexpected(e.error_or(songbot_error::no_match));
    }

    const Song& song = *song_result;
    auto history  = build_concert_history(song);
    auto enriched = enrich_from_vocadb(song, ctx);

    auto msg = dpp::message().set_flags(dpp::message_flags::m_using_components_v2).suppress_embeds(true);

    song_card_component card;
    card.set_title(history.main_text);
    if (!enriched.subtext.empty())
        card.set_left(std::format("-# {}", enriched.subtext));
    if (enriched.pic) {
        auto filename = std::format("{}.{}", *song.vocadb_id, enriched.pic->ext);
        std::string_view data{reinterpret_cast<const char*>(enriched.pic->pic.data()), enriched.pic->pic.size_bytes()};
        card.set_image(filename, enriched.pic->mime_type, data);
    }
    if (!history.priors_text.empty())
        card.set_bottom(std::format("-# {}", history.priors_text));
    card.apply_to(msg);

    co_return co_await util::reply_handler_new(event.co_reply(msg), ctx, last_success_counter, last_failure_counter);
}

std::expected<dpp::interaction_response, std::error_code>
last_command::on_autocomplete_impl(const dpp::autocomplete_t& event)
{
    for (auto & opt : event.options | std::views::filter(&dpp::command_option::focused)) {
        try {
            std::string uservalue = std::get<std::string>(opt.value);

            auto matches = match_songs_indexed(uservalue);
            if (matches.empty()) {
                return std::unexpected(songbot_error::autocomplete_no_match);
            }

            auto resp = dpp::interaction_response(dpp::ir_autocomplete_reply);
            for (const auto& song : matches | std::views::take(AUTOCOMPLETE_MAX_CHOICES) ) {
              auto n = get_autocomplete_text_for_song(std::get<1>(song));
              auto c = std::format("{}{}", INDEX_PREFIX, std::get<0>(song));
              resp.add_autocomplete_choice(dpp::command_option_choice(n, c));
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
    const auto start = std::chrono::high_resolution_clock::now();
    auto res = on_autocomplete_impl(event);
    const auto end = std::chrono::high_resolution_clock::now();
    autocomplete_latency->Observe(std::chrono::duration_cast<std::chrono::duration<double>>(end - start).count());
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
