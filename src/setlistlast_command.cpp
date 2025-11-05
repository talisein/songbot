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
        if (concert->date > util::get_build_date()) {
            co_yield std::format("{} will first play on {}. I won't know the setlist until after that.",
                                 concert->name, concert->date);
            co_return;
        }

        auto setlistlast = get_setlist(concert->short_name);
        co_yield std::format("## Setlist for {}:\n", concert->name);
        for (auto &track : setlistlast) {
            auto song = lookup_song(track.song, track.producer);
            if (!song) {
                co_yield std::format("{}. 🫠 '{}' I guess? This is a bug...\n", track.pos, track.song);
                continue;
            }
            /* Drop the concerts that occurred after the requested concert... */
            auto rng = std::views::drop_while(std::views::reverse(setlists), [&](const auto &track)
            {
                return track.concert_short_name != concert->short_name;
            /* Drop the tracks for the requested concert... */
            }) | std::views::drop_while([&](const auto &track)
            {
                return track.concert_short_name == concert->short_name;
            /* Match the remaining cases where the song name matches */
            }) | std::views::filter([&](const auto &track)
            {
                return track.song == song->name;
            });

            std::ostringstream ss;
            ss << std::format("{}. {}", track.pos, util::escape_markdown(song->name));
            if (song->singer != NO_VIRTUAL_SINGER) {
                ss << " feat. " << magic_enum::enum_flags_name(song->singer);
            }
            ss << " by " << util::escape_markdown(song->producer);

            if (std::ranges::empty(rng)) {
                ss << " **LIVE DEBUT**";
            } else {
                auto count = std::ranges::distance(rng);
                ss << " *Previous: " << tour_to_string(std::ranges::begin(rng)->concert_short_name);
                ss << "*";
                /*
                if (count > 1) {
                    ss << ", " << count - 1 << " more before*";
                } else {
                    ss << "*";
                }
                */
            }
            auto after_rng = std::views::take_while(std::views::reverse(setlists), [&](const auto &track)
            {
                return track.concert_short_name != concert->short_name;
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
    iface_command(ctx, "setlistlast", "Full Concert Setlist with each song's previous appearance"),
    storage(ctx)
{
    /* Metric: setlistlast */
    setlistlast_success_counter = &ctx.slashcommand_counter->Add({{"command", "setlistlast"}, {"result", "success"}, {"visibility", "ephemeral"}});
    setlistlast_failure_counter = &ctx.slashcommand_counter->Add({{"command", "setlistlast"}, {"result", "failure"}, {"visibility", "ephemeral"}});
    setlistlast_reveal_success_counter = &ctx.slashcommand_counter->Add({{"command", "setlistlast"}, {"result", "success"}, {"visibility", "public"}});
    setlistlast_reveal_failure_counter = &ctx.slashcommand_counter->Add({{"command", "setlistlast"}, {"result", "failure"}, {"visibility", "public"}});

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

    [[nodiscard]] dpp::message
    make_reveal_gui(const auto &messages, bool use_ephemeral, std::optional<std::string> button_id)
    {
        const auto flags    = dpp::message_flags::m_using_components_v2 | (use_ephemeral ? dpp::message_flags::m_ephemeral : 0);
        auto real_msg       = dpp::message().set_flags(flags);
        if (button_id.has_value()) {
            auto action_row = dpp::component().set_type(dpp::cot_action_row);
            auto button     = dpp::component().set_type(dpp::cot_button)
                              .set_style(dpp::cos_primary)
                              .set_label("Post Publicly")
                              .set_id(button_id.value());
            action_row.add_component_v2(button);
            real_msg.add_component_v2(action_row);
        }
        auto text_display_1 = dpp::component().set_type(dpp::cot_text_display)
                                              .set_content(messages[0]);
        real_msg.add_component_v2(text_display_1);
        if (messages.size() > 1) {
            auto text_display_2 = dpp::component().set_type(dpp::cot_text_display).set_content(messages[1]);
            real_msg.add_component_v2(text_display_2);
        }
        return real_msg;
    }

    /* DPP makes confirmation_callback_t const, so we need to create a new closure for each successive followup. */
    template <typename T>
    struct recursive_follow_upper
    {
        T event;
        context * const ctx;
        bool use_ephemeral;
        std::vector<std::string> messages;
        dpp::command_completion_event_t final_callback;
        int sequence;

        recursive_follow_upper(const T& event,
                               context * const ctx,
                               bool use_ephemeral,
                               std::ranges::input_range auto&& rng,
                               dpp::command_completion_event_t final_callback = dpp::utility::log_error(),
                               int sequence = 2) noexcept :
            event(event),
            ctx(ctx),
            use_ephemeral(use_ephemeral),
            messages(std::ranges::to<std::vector>(rng)),
            final_callback(final_callback),
            sequence(sequence)
        { }


        void operator()(const dpp::confirmation_callback_t& confirmation) const
        {
            if (confirmation.is_error()) {
                final_callback(confirmation);
                return;
            }

            auto real_msg = make_reveal_gui(messages, use_ephemeral, std::nullopt);
            if (messages.size() < 3) {
                my_follow_up(event, real_msg, final_callback);
            } else {
                my_follow_up(event, real_msg,
                             recursive_follow_upper(event, ctx, use_ephemeral, std::views::drop(messages, 2), final_callback));
            }
        }

    };

    /* Takes a generator that produces multiple lines. It constructs a sequence
     * dpp::messages, each less than the reply limit and sends it off using the make_reveal_gui() */
    template <typename EventType, typename GeneratorCallable, typename GeneratorInput>
    void reply_multimessage(const EventType& event,
                            context * const ctx,
                            GeneratorCallable&& line_generator,
                            GeneratorInput&& generator_input,
                            bool use_ephemeral,
                            std::optional<std::string> button_callback_key,
                            dpp::command_completion_event_t final_callback = dpp::utility::log_error())
    {
        std::ostringstream reply;
        std::vector<std::string> messages;
        for (const auto& line : std::invoke(std::forward<GeneratorCallable>(line_generator),
                                            std::forward<GeneratorInput>(generator_input)))
        {
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
        dpp::message msg;
        if (button_callback_key) {
            msg = make_reveal_gui(messages, use_ephemeral, button_callback_key);
        } else {
            msg = make_reveal_gui(messages, use_ephemeral, std::nullopt);
        }

        if (messages.size() < 3) {
            event.reply(msg, final_callback);
        } else {
            event.reply(msg, recursive_follow_upper(event, ctx, use_ephemeral, std::views::drop(messages, 2)));
        }
    }
}

void
setlistlast_command::on_button_click(const dpp::button_click_t& event)
{
    auto args = storage.get(event.custom_id);
    if (!args) {
        // Could be a button click for another handler? So just ignore.
        return;
    }

    const auto concert = args.value().concert;
    auto on_completion = [event = args.value().event](const dpp::confirmation_callback_t &c) {
        auto msg = dpp::message().set_flags(dpp::message_flags::m_using_components_v2 | dpp::message_flags::m_ephemeral);
        if (c.is_error()) {
            dpp::utility::log_error()(c);
            msg.add_component_v2(dpp::component().set_type(dpp::cot_text_display).set_content("Sorry, I made a mistake and can't this setlist publically."));
        } else {
            msg.add_component_v2(dpp::component().set_type(dpp::cot_text_display).set_content("Setlist posted to channel!"));
        }
        event.edit_original_response(msg);
    };

    reply_multimessage(event, ctx, &get_setlistlast_lines, concert, false, std::nullopt, on_completion);
    setlistlast_reveal_success_counter->Increment();
}

std::expected<void, std::error_code>
setlistlast_command::on_slashcommand(const dpp::slashcommand_t& event)
{
    try {
        const auto concert = std::get<std::string>(event.get_parameter("event"));
        auto key = storage.insert({concert, event});
        reply_multimessage(event, ctx, &get_setlistlast_lines, concert, true, key);
    } catch(std::system_error &e) {
        event.reply("I have a bug in my programming, so I can't give you that setlist. I'm sorry!");
        ctx->log(dpp::ll_error, "/setlistlast: System Error {}", e.what());
        setlistlast_failure_counter->Increment();
        return std::unexpected(e.code());
    } catch (std::bad_variant_access &e) {
        event.reply("I have a bug in my programming, so I can't give you that setlist. I'm sorry!");
        ctx->log(dpp::ll_error, "/setlistlast: std::get() {}", e.what());
        setlistlast_failure_counter->Increment();
        return std::unexpected(songbot_error::explosion);
    }

    setlistlast_success_counter->Increment();
    return {};
}

std::expected<dpp::interaction_response, std::error_code>
setlistlast_command::on_autocomplete_impl(const dpp::autocomplete_t& event)
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
