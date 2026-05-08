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

#include "setlist_command.hpp"
#include "setlist_message.hpp"
#include "context.hpp"
#include "formatters.hpp"

namespace {
    static std::vector<std::string>
    get_setlist_lines(const Concert& concert)
    {
        std::vector<std::string> lines;
        if (concert.date > util::get_build_date()) {
            lines.push_back(std::format("{} will first play on {}. I won't know the setlist until after that.",
                                           concert.name, concert.date));
            return lines;
        }

        auto setlist = get_setlist(concert.short_name);
        for (auto &track : setlist) {
            auto song = lookup_song(track.song, track.producer);
            if (!song) {
                lines.push_back(std::format("{}. 🫠 '{}' I guess? This is a bug...\n", track.pos, track.song));
                continue;
            }

            std::ostringstream ss;

            using namespace std::literals;
            ss << std::format("- {}. {}",
                              track.pos,
                              track.variant.transform([](const auto& v) { return std::format("`{}` ", v); }).value_or(""s));
            if (song->vocadb_id || track.remix_id) {
              auto id = track.remix_id.or_else([&] { return song->vocadb_id; });
              ss << '[' << song->name;
              if (track.remix) {
                ss << ' ' << *track.remix;
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
            ss << "\n";
            lines.push_back(ss.str());
        }

        return lines;
    }
}

setlist_command::setlist_command(context &ctx) noexcept :
    iface_command(ctx, "setlist", "Full Concert Setlist")
{
    /* Metric: setlist */
    setlist_success_counter = &ctx.slashcommand_counter->Add({{"command", "setlist"}, {"result", "success"}, {"visibility", "ephemeral"}});
    setlist_failure_counter = &ctx.slashcommand_counter->Add({{"command", "setlist"}, {"result", "failure"}, {"visibility", "ephemeral"}});
    setlist_reveal_success_counter = &ctx.slashcommand_counter->Add({{"command", "setlist"}, {"result", "success"}, {"visibility", "public"}});
    setlist_reveal_failure_counter = &ctx.slashcommand_counter->Add({{"command", "setlist"}, {"result", "failure"}, {"visibility", "public"}});

    /* Metric: Autocompletions */
    ac_setlist_success_counter = &ctx.autocompletion_counter->Add({{"event", "setlist"}, {"result", "success"}});
    ac_setlist_no_match_counter = &ctx.autocompletion_counter->Add({{"event", "setlist"}, {"result", "no-match"}});
    ac_setlist_failure_counter = &ctx.autocompletion_counter->Add({{"event", "setlist"}, {"result", "failure"}});
}

dpp::slashcommand
setlist_command::get_command()
{
    auto setlist_cmd = iface_command::get_command();
    auto event_opt = dpp::command_option(dpp::command_option_type::co_string, "event", "Name of event, e.g. ME2014LANY", true);
    event_opt.set_auto_complete(true);

    setlist_cmd.add_option(std::move(event_opt));

    return setlist_cmd;
}

dpp::task<std::expected<void, std::error_code>>
setlist_command::reply_multimessage(const dpp::slashcommand_t& event,
                                        const Concert& concert)
{
    const bool can_post = can_post_setlist_publicly(event, *ctx);
    const auto reveal_click_key = can_post
        ? std::make_optional<std::string>(ctx->keygen())
        : std::nullopt;
    const auto no_spoiler_click_key = can_post
        ? std::make_optional<std::string>(ctx->keygen())
        : std::nullopt;
    auto headers = get_header_lines(concert);
    auto body_lines = get_setlist_lines(concert);

    auto first_msgs = setlist_message::build_messages(concert, headers, body_lines, true, reveal_click_key, no_spoiler_click_key);
    if (auto res = co_await reply_and_followup(event, first_msgs, ctx); !res) {
        co_return res;
    }

    if (!reveal_click_key) {
        co_return {};
    }

    /* Wait for button click or expiration */
    if (auto when_any_result = co_await dpp::when_any{
            event.owner->on_button_click.when([key = *reveal_click_key](const auto& click) {
                return click.custom_id == key;
            }),
            event.owner->on_button_click.when([key = *no_spoiler_click_key](const auto& click) {
                return click.custom_id == key;
            }),
            event.owner->co_sleep(5 * 60)
        };
        when_any_result.index() == 0 || when_any_result.index() == 1)
    { // Button clicked
        const bool suppress_spoiler = when_any_result.index() == 1;
        const dpp::button_click_t click_event = suppress_spoiler
            ? when_any_result.get<1>()
            : when_any_result.get<0>();
        auto reveal_msgs = setlist_message::build_messages(concert, headers, body_lines, false, std::nullopt, std::nullopt, suppress_spoiler);
        if (auto res = co_await reply_and_followup(click_event, reveal_msgs, ctx); !res) {
            setlist_reveal_failure_counter->Increment();
            co_return res;
        }

        auto success_msg = dpp::message().set_flags(dpp::message_flags::m_using_components_v2 | dpp::message_flags::m_ephemeral);
        success_msg.add_component_v2(dpp::component().set_type(dpp::cot_text_display).set_content("Setlist posted to channel!"));
        co_return co_await util::reply_handler_new(event.co_edit_original_response(success_msg), ctx, setlist_reveal_success_counter, setlist_reveal_failure_counter);
    } else { // Buttons expiring. Replace the first message without buttons.
        auto expired_msgs = setlist_message::build_messages(concert, headers, body_lines, true, std::nullopt);
        co_return co_await util::reply_handler_new(event.co_edit_original_response(*std::ranges::begin(expired_msgs)), ctx, setlist_reveal_success_counter, setlist_reveal_failure_counter);
    }

    co_return {};
}

dpp::task<std::expected<void, std::error_code>>
setlist_command::on_slashcommand(const dpp::slashcommand_t event)
{
    try {
        const auto concert_str = std::get<std::string>(event.get_parameter("event"));
        const auto concert = lookup_concert(concert_str);
        if (!concert) {
            dpp::message m{std::format("I'm sorry, I don't know about a concert named '{}'", concert_str)};
            m.set_flags(dpp::message_flags::m_ephemeral);

            auto res = co_await util::reply_handler_new(event.co_reply(m), ctx, setlist_success_counter, setlist_failure_counter);
            co_return std::unexpected(res.error_or(songbot_error::no_match));
        }

        auto res = co_await reply_multimessage(event, *concert);
        if (res) {
            setlist_success_counter->Increment();
        } else {
            setlist_failure_counter->Increment();
        }
        co_return res;
    } catch(std::system_error &e) {
        dpp::message m("I have a bug in my programming, so I can't give you that setlist. I'm sorry!");
        m.set_flags(dpp::message_flags::m_ephemeral);
        event.reply(m);
        ctx->log_error("/setlist: System Error {}", e.what());
        setlist_failure_counter->Increment();
        co_return std::unexpected(e.code());
    } catch (std::bad_variant_access &e) {
        dpp::message m("I have a bug in my programming, so I can't give you that setlist. I'm sorry!");
        m.set_flags(dpp::message_flags::m_ephemeral);
        event.reply(m);
        ctx->log_error("/setlist: std::get() {}", e.what());
        setlist_failure_counter->Increment();
        co_return std::unexpected(songbot_error::explosion);
    }

    co_return {};
}

std::expected<dpp::interaction_response, std::error_code>
setlist_command::on_autocomplete_impl(const dpp::autocomplete_t& event)
{
    for (const auto& opt : std::views::all(event.options) | std::views::filter(&dpp::command_option::focused)) {
        try {
            std::string uservalue = std::get<std::string>(opt.value);

            auto matches = match_concerts(uservalue);
            if (matches.empty()) {
                return std::unexpected(songbot_error::autocomplete_no_match);
            }

            auto resp = dpp::interaction_response(dpp::ir_autocomplete_reply);
            for (const auto& concert : matches | std::views::take(AUTOCOMPLETE_MAX_CHOICES) ) {
                resp.add_autocomplete_choice(dpp::command_option_choice(std::string(tour_to_string(concert.short_name)), std::string(tour_to_string(concert.short_name))));
            }

            return resp;
        } catch (std::bad_variant_access &e) {
            ctx->log_error("/setlist: autocomplete error: {}", e.what());
            return std::unexpected(std::make_error_code(std::errc::invalid_argument));
        }
    }

    return std::unexpected(songbot_error::autocomplete_no_focused_option);
}

std::expected<dpp::interaction_response, std::error_code>
setlist_command::on_autocomplete(const dpp::autocomplete_t& event)
{
    auto res = on_autocomplete_impl(event);
    if (res) {
        ac_setlist_success_counter->Increment();
    } else {
        bool is_no_match = res.error().category() == get_songbot_error_category() &&
            res.error().value() == std::to_underlying(songbot_error::autocomplete_no_match);
        if (is_no_match) {
            ac_setlist_no_match_counter->Increment();
        } else {
            ac_setlist_failure_counter->Increment();
        }
    }

    return res;
}
