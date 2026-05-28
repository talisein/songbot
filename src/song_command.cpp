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
import uni_algo;
import vocadb.api;
import vocadb.songs;

#include "song_command.hpp"
#include "last_shared.hpp"
#include "context.hpp"
#include "formatters.hpp"

namespace
{
    using namespace std::literals;
    constexpr std::string_view INDEX_PREFIX {"idx:"sv};
}

song_command::song_command(context &ctx) noexcept :
    iface_command(ctx, "song", "Song details")
{
    song_success_counter = &ctx.slashcommand_counter->Add({{"command", "song"}, {"result", "success"}});
    song_failure_counter = &ctx.slashcommand_counter->Add({{"command", "song"}, {"result", "failure"}});

    ac_song_success_counter = &ctx.autocompletion_counter->Add({{"event", "song"}, {"result", "success"}});
    ac_song_no_match_counter = &ctx.autocompletion_counter->Add({{"event", "song"}, {"result", "no-match"}});
    ac_song_failure_counter = &ctx.autocompletion_counter->Add({{"event", "song"}, {"result", "failure"}});

    prometheus::Histogram::BucketBoundaries buckets {0.0001, 0.00025, 0.0005, 0.001, 0.0025, 0.005, 0.01, 0.025, 0.05, 0.1, 0.25, 0.5, 1.0};
    prometheus::Labels labels {{"command", "song"}};
    autocomplete_latency = &ctx.autocomplete_latency->Add(labels, buckets);
}

dpp::slashcommand
song_command::get_command()
{
    auto song_cmd = iface_command::get_command();
    auto event_opt = dpp::command_option(dpp::command_option_type::co_string, "song", "Name of song, e.g. Melt", true);
    event_opt.set_auto_complete(true);

    song_cmd.add_option(std::move(event_opt));
    return song_cmd;
}

dpp::task<std::expected<void, std::error_code>>
song_command::on_slashcommand(const dpp::slashcommand_t event)
{
    using namespace std::literals;

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
        auto e = co_await util::reply_handler_new(event.co_reply(msg), ctx, song_success_counter, song_failure_counter);
        co_return std::unexpected(e.error_or(songbot_error::no_match));
    }

    const Song& song = *song_result;
    auto enriched = enrich_from_vocadb(song, ctx);

    std::string alt_names;
    std::string artists_str;

    if (song.vocadb_id) {
        if (auto it = std::ranges::find(vocadb::songs, *song.vocadb_id, &vocadb::song::id);
            it != std::ranges::end(vocadb::songs))
        {
            alt_names = it->names
                | std::views::transform(&vocadb::additional_name::name)
                | std::views::filter([&song](std::string_view n) { return una::caseless::compare_utf8(n, song.name) != 0; })
                | std::views::join_with(", "sv)
                | std::ranges::to<std::string>();

            /* Materialise optional<string> first so the string_view in the final transform is stable */
            artists_str = it->artists
                | std::views::filter([](const auto& a) {
                  return !a.is_support
                    && (a.categories.contains("Producer"sv)
                        || a.categories.contains("Circle"sv))
                    && !a.roles.contains("Publisher"); })
                | std::views::transform([](const auto& sa) -> std::optional<std::string> {
                    return sa.artist
                        .and_then([](const auto& a) -> std::optional<std::string_view> { return a.name; })
                        .or_else([&sa]() -> std::optional<std::string_view> { return sa.name; })
                        .transform([&sa](const auto& n) -> std::string {
                            if (sa.effective_roles != "Default"sv) {
                                return std::format("{} ({})", n, sa.effective_roles);
                            } else if (sa.artist && sa.artist->artist_type != "OtherGroup"sv) {
                                return std::format("{} ({})", n, sa.artist->artist_type);
                            }
                            return std::string(n);
                        });
                  })
                | std::ranges::to<std::vector<std::optional<std::string>>>()
                | std::views::filter([](const auto& opt) { return opt.has_value(); })
                | std::views::transform([](const auto& opt) { return *opt; })
                | std::views::join_with(", "sv)
                | std::ranges::to<std::string>();
        }
    }

    std::string left_str;
    if (!artists_str.empty() && !enriched.subtext.empty()) {
      left_str = std::format("{}\n{}", artists_str, enriched.subtext);
    } else if (!artists_str.empty()) {
      left_str = artists_str;
    } else {
      left_str = enriched.subtext;
    }

    auto msg = dpp::message().set_flags(dpp::message_flags::m_using_components_v2).suppress_embeds(true);

    song_card_component card;

    std::string title;
    if (song.vocadb_id)
        title = std::format("**[{}](https://vocadb.net/S/{})** by {}", song.name, *song.vocadb_id, song.producer);
    else
        title = std::format("**{}** by {}", song.name, song.producer);
    if (!alt_names.empty())
        title += std::format("\n-# {}", alt_names);
    card.set_title(title);

    card.set_left(left_str);
    if (enriched.pic) {
        auto filename = std::format("{}.{}", *song.vocadb_id, enriched.pic->ext);
        std::string_view data{reinterpret_cast<const char*>(enriched.pic->pic.data()), enriched.pic->pic.size_bytes()};
        card.set_image(filename, enriched.pic->mime_type, data);
    }

    card.apply_to(msg);

    co_return co_await util::reply_handler_new(event.co_reply(msg), ctx, song_success_counter, song_failure_counter);
}

std::expected<dpp::interaction_response, std::error_code>
song_command::on_autocomplete_impl(const dpp::autocomplete_t& event)
{
    for (auto & opt : event.options | std::views::filter(&dpp::command_option::focused)) {
        try {
            std::string uservalue = std::get<std::string>(opt.value);

            auto matches = match_songs_indexed(uservalue);
            if (matches.empty()) {
                return std::unexpected(songbot_error::autocomplete_no_match);
            }

            auto resp = dpp::interaction_response(dpp::ir_autocomplete_reply);
            for (const auto& song : matches | std::views::take(AUTOCOMPLETE_MAX_CHOICES)) {
                auto n = get_autocomplete_text_for_song(std::get<1>(song));
                auto c = std::format("{}{}", INDEX_PREFIX, std::get<0>(song));
                resp.add_autocomplete_choice(dpp::command_option_choice(n, c));
            }

            return resp;
        } catch (std::bad_variant_access &e) {
            ctx->bot->log(dpp::ll_error, std::format("/song: autocomplete error: {}", e.what()));
            return std::unexpected(std::make_error_code(std::errc::invalid_argument));
        }
    }

    return std::unexpected(songbot_error::autocomplete_no_focused_option);
}

std::expected<dpp::interaction_response, std::error_code>
song_command::on_autocomplete(const dpp::autocomplete_t& event)
{
    const auto start = std::chrono::high_resolution_clock::now();
    auto res = on_autocomplete_impl(event);
    const auto end = std::chrono::high_resolution_clock::now();
    autocomplete_latency->Observe(std::chrono::duration_cast<std::chrono::duration<double>>(end - start).count());
    if (res) {
        ac_song_success_counter->Increment();
    } else {
        bool is_no_match = res.error().category() == get_songbot_error_category() &&
            res.error().value() == std::to_underlying(songbot_error::autocomplete_no_match);
        if (is_no_match) {
            ac_song_no_match_counter->Increment();
        } else {
            ac_song_failure_counter->Increment();
        }
    }

    return res;
}
