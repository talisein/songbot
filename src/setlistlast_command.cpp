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


#include "setlistlast_command.hpp"
#include "context.hpp"

namespace {
    static
    std::generator<std::string> get_setlistlast_lines(std::string_view concert_name)
    {
        const auto concert = lookup_concert(concert_name);
        if (!concert) {
            co_yield std::format("I don't know about '{}'", concert_name);
            co_return;
        }

        auto setlistlast = get_setlist(concert->short_name);
        co_yield std::format("## Setlist for {}:\n", concert->name);
        for (auto &track : setlistlast) {
            auto song = lookup_song(track.song, track.producer);
            if (!song) {
                co_yield std::format("`{:2}` 🫠 '{}' I guess? This is a bug...\n", track.pos, track.song);
                continue;
            }
            /* Drop the concerts that occurred after the requested concert... */
            auto rng = std::views::drop_while(std::views::reverse(setlists), [&](const auto &track)
            {
                return track.concert != concert->short_name;
            /* Drop the tracks for the requested concert... */
            }) | std::views::drop_while([&](const auto &track)
            {
                return track.concert == concert->short_name;
            /* Match the remaining cases where the song name matches */
            }) | std::views::filter([&](const auto &track)
            {
                return track.song == song->name;
            });

            std::ostringstream ss;
            ss << std::format("`{:2}` {}", track.pos, util::escape_markdown(song->name));
            if (song->singer != NO_VIRTUAL_SINGER) {
                ss << " feat. " << magic_enum::enum_flags_name(song->singer);
            }
            ss << " by " << util::escape_markdown(song->producer);

            if (std::ranges::empty(rng)) {
                ss << " **LIVE DEBUT**";
//                co_yield std::format("`{:2}` {} feat. {} by {} **LIVE DEBUT**\n", track.pos, util::escape_markdown(song->name), magic_enum::enum_flags_name(song->singer), util::escape_markdown(song->producer));
            } else {
                auto count = std::ranges::distance(rng);
                ss << " *Previously@" << std::ranges::begin(rng)->concert;
                if (count > 1) {
                    ss << ", " << count - 1 << " more before*";
//                    co_yield std::format("`{:2}` {} feat. {} by {} *Previously@{}, {} more*\n", track.pos, util::escape_markdown(song->name), magic_enum::enum_flags_name(song->singer), util::escape_markdown(song->producer), std::ranges::begin(rng)->concert, count - 1);
                } else {
                    ss << "*";
                        //co_yield std::format("`{:2}` {} feat. {} by {} *Previously@{}*\n", track.pos, util::escape_markdown(song->name), magic_enum::enum_flags_name(song->singer), util::escape_markdown(song->producer), std::ranges::begin(rng)->concert);
                }
            }
            auto after_rng = std::views::take_while(std::views::reverse(setlists), [&](const auto &track)
            {
                return track.concert != concert->short_name;
            }) | std::views::filter([&](const auto &track)
            {
                return track.song == song->name;
            });
            const auto after_count = std::ranges::distance(after_rng);
            if (after_count > 0) {
                ss << " *and " << after_count << " after*";
            }
            ss << "\n";
            co_yield ss.str();
        }
    }

}

setlistlast_command::setlistlast_command(context &ctx) noexcept :
    iface_command(ctx, "setlistlast", "Full Concert Setlist with each song's previous appearance")
{
    /* Metric: setlistlast */
    setlistlast_success_counter = &ctx.slashcommand_counter->Add({{"command", "setlistlast"}, {"result", "success"}});
    setlistlast_failure_counter = &ctx.slashcommand_counter->Add({{"command", "setlistlast"}, {"result", "failure"}});

    /* Metric: Autocompletions */
    ac_setlistlast_success_counter = &ctx.autocompletion_counter->Add({{"event", "setlistlast"}, {"result", "success"}});
    ac_setlistlast_no_match_counter = &ctx.autocompletion_counter->Add({{"event", "setlistlast"}, {"result", "no-match"}});
    ac_setlistlast_failure_counter = &ctx.autocompletion_counter->Add({{"event", "setlistlast"}, {"result", "failure"}});
}

dpp::slashcommand
setlistlast_command::get_command()
{
    auto setlistlast_cmd = iface_command::get_command();
    auto event_opt = dpp::command_option(dpp::command_option_type::co_string, "event", "Name of event, e.g. ME2014LANY", true);
    event_opt.set_auto_complete(true);

    setlistlast_cmd.add_option(std::move(event_opt));

    ctx->bot->on_button_click([this](const dpp::button_click_t& event) { return on_button_click(event); });

    return setlistlast_cmd;
}

namespace {
    constexpr size_t DISCORD_REPLY_LIMIT = 2000UZ;
    constexpr std::string_view SETLISTLAST_BUTTON_ID_PREFIX { "setlistlast:" };
    template <typename EventType>
    void my_follow_up(const EventType& event,
                      const dpp::message& msg,
                      dpp::command_completion_event_t cb = dpp::utility::log_error())
    {
        event.owner->interaction_followup_create(event.command.token, msg, std::move(cb));
    }

    /* DPP makes confirmation_callback_t const, so we need to create a new closure for each successive followup. */
    template <typename T>
    struct recursive_follow_upper
    {
        T event;
        context * const ctx;
        std::vector<dpp::message> msgs;
        int sequence;

        recursive_follow_upper(const T& event, context * const ctx, auto &&rng, int sequence = 2) noexcept :
            event(event),
            ctx(ctx),
            msgs(std::views::drop(rng, 1) | std::ranges::to<std::vector>()),
            sequence(sequence)
        { }


        void operator()(const dpp::confirmation_callback_t& confirmation) const
        {
            if (confirmation.is_error()) {
                dpp::utility::log_error()(confirmation);
            }

            if (msgs.size() == 1) {
                my_follow_up(event, msgs.front());
            } else {
                my_follow_up(event, msgs.front(), recursive_follow_upper(event, ctx, msgs, sequence + 1));
            }
        }

    };


    /* Takes a generator that produces multiple lines. It constructs a sequence
     * dpp::messages, each less than the reply limit and sends it off. */
    template <typename EventType, typename GeneratorCallable, typename GeneratorInput, typename Context>
    void reply_multimessage(const EventType& event, GeneratorCallable &&line_generator, GeneratorInput&& generator_input, bool use_ephemeral, std::string_view button_id_prefix, Context&& ctx)
    {
        std::ostringstream reply;
        std::vector<dpp::message> messages;
        for (const auto& line : line_generator(std::forward<GeneratorInput>(generator_input))) {
            if ((reply.view().size() + line.size()) >= DISCORD_REPLY_LIMIT) {
                messages.emplace_back(reply.view());
                if (use_ephemeral) {
                    messages.back().set_flags(dpp::message_flags::m_ephemeral);
                }
                reply.str(std::string());
                reply << line;
            } else {
                reply << line;
            }
        }

        if (reply.view().size() > 0) {
            messages.emplace_back(reply.view());
            if (use_ephemeral) {
                messages.back().set_flags(dpp::message_flags::m_ephemeral);
            }
        }

        /* Ok, we have a list of messages to send. */
        if (use_ephemeral) {
            messages.front().set_flags(dpp::m_using_components_v2).add_component_v2(
                dpp::component().set_type(dpp::cot_container).add_component(
                    dpp::component().set_type(dpp::cot_button)
                    .set_style(dpp::cos_primary)
                    .set_label("Post Publicly")
                    .set_id(std::format("{}{}", button_id_prefix, generator_input))
                    )
                );
        }
        if (messages.size() < 3) {
            event.reply(messages.front());
        } else {
            event.reply(messages.front(), recursive_follow_upper(event, std::forward<Context>(ctx), std::views::drop(messages, 1)));
        }

    }
}

void
setlistlast_command::on_button_click(const dpp::button_click_t& event)
{
    if (!event.custom_id.starts_with(SETLISTLAST_BUTTON_ID_PREFIX))
        return;
    std::string concert = event.custom_id.substr(SETLISTLAST_BUTTON_ID_PREFIX.size());

    std::ostringstream reply;
    std::vector<dpp::message> messages;
    for (const auto& line : get_setlistlast_lines(concert)) {
        if ((reply.view().size() + line.size()) >= DISCORD_REPLY_LIMIT) {
            messages.emplace_back(reply.view());
            reply.str(std::string());
            reply << line;
        } else {
            reply << line;
        }
    }

    if (reply.view().size() > 0) {
        messages.emplace_back(reply.view());
    }

    /* Ok, we have a list of messages to send. */
    if (messages.size() == 1) {
        event.reply(messages.front());
    } else {
        event.reply(messages.front(), recursive_follow_upper(event, ctx, messages));
    }

}

std::expected<void, std::error_code>
setlistlast_command::on_slashcommand(const dpp::slashcommand_t& event)
{
    try {
        const auto concert = std::get<std::string>(event.get_parameter("event"));
        /* Some setlists are more than 2000 characters. So we need to split up
         * our reply into a reply and some number of follow ups. */
        std::ostringstream reply;
        std::vector<dpp::message> messages;
        for (const auto& line : get_setlistlast_lines(concert)) {
            if ((reply.view().size() + line.size()) >= DISCORD_REPLY_LIMIT) {
                messages.emplace_back(reply.view()).set_flags(dpp::message_flags::m_ephemeral);
                reply.str(std::string());
                reply << line;
            } else {
                reply << line;
            }
        }

        if (reply.view().size() > 0) {
            messages.emplace_back(reply.view()).set_flags(dpp::message_flags::m_ephemeral);
        }

        /* Ok, we have a list of messages to send. */
        auto real_msg       = dpp::message().set_flags(dpp::message_flags::m_using_components_v2 | dpp::message_flags::m_ephemeral);
        auto container      = dpp::component().set_type(dpp::cot_container);
        auto action_row     = dpp::component().set_type(dpp::cot_action_row);
        auto button         = dpp::component().set_type(dpp::cot_button)
                                              .set_style(dpp::cos_primary)
                                              .set_label("Post Publicly")
                                              .set_id(std::format("{}{}", SETLISTLAST_BUTTON_ID_PREFIX, concert));
        auto text_display_1 = dpp::component().set_type(dpp::cot_text_display)
                                              .set_content(messages[0].content);
        action_row.add_component_v2(button);
        container.add_component_v2(action_row);
        container.add_component_v2(text_display_1);
        if (messages.size() > 1) {
            auto text_display_2 = dpp::component().set_type(dpp::cot_text_display).set_content(messages[1].content);
            container.add_component_v2(text_display_2);
        }
        real_msg.add_component_v2(container);
        event.reply(real_msg);

        if (messages.size() < 3) {
            event.reply(real_msg);
        } else {
            event.reply(messages.front(), recursive_follow_upper(event, ctx, messages));
        }

    } catch(std::system_error &e) {
        event.reply("I have a bug in my programming, so I can't give you that setlist. I'm sorry!");
        ctx->bot->log(dpp::ll_error, std::format("/setlistlast: System Error {}", e.what()));
        setlistlast_failure_counter->Increment();
        return std::unexpected(e.code());
    } catch (...) {
        event.reply("I have a bug in my programming, so I can't give you that setlist. I'm sorry!");
        ctx->bot->log(dpp::ll_error, "/setlistlast: Unhandled exception");
        setlistlast_failure_counter->Increment();
        return std::unexpected(songbot_error::explosion);
    }

    setlistlast_success_counter->Increment();
    return {};
}

std::expected<dpp::interaction_response, std::error_code>
setlistlast_command::on_autocomplete_impl(const dpp::autocomplete_t& event)
{
    for (auto & opt : event.options | std::views::filter(&dpp::command_option::focused)) {
        try {
            std::string uservalue = std::get<std::string>(opt.value);

            auto matches = match_concerts(uservalue);
            if (matches.empty()) {
                return std::unexpected(songbot_error::autocomplete_no_match);
            }

            auto resp = dpp::interaction_response(dpp::ir_autocomplete_reply);
            for (const auto& concert : matches | std::views::take(AUTOCOMPLETE_MAX_CHOICES) ) {
                resp.add_autocomplete_choice(dpp::command_option_choice(std::string(concert.short_name), std::string(concert.short_name)));
            }

            return resp;
        } catch (std::bad_variant_access &e) {
            ctx->bot->log(dpp::ll_error, std::format("/setlistlast: autocomplete error: {}", e.what()));
            return std::unexpected(std::make_error_code(std::errc::invalid_argument));
        }
    }

    return std::unexpected(songbot_error::autocomplete_no_focused_option);
}

std::expected<dpp::interaction_response, std::error_code>
setlistlast_command::on_autocomplete(const dpp::autocomplete_t& event)
{
    auto res = on_autocomplete_impl(event);
    if (res) {
        ac_setlistlast_success_counter->Increment();
    } else {
        bool is_no_match = res.error().category() == get_songbot_error_category() &&
            res.error().value() == std::to_underlying(songbot_error::autocomplete_no_match);
        if (is_no_match) {
            ac_setlistlast_no_match_counter->Increment();
        } else {
            ac_setlistlast_failure_counter->Increment();
        }
    }

    return res;
}
