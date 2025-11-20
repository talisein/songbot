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
import uni_algo;

#include "setlistlast_command.hpp"
#include "context.hpp"
#include "formatters.hpp"

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

            using namespace std::literals;
            ss << std::format("- {}. {}",
                              track.pos,
                              track.variant.transform([](const auto& v) { return std::format("`{}` ", v); }).value_or(""s));
            if (song->vocadb_id) {
                ss << '[' << song->name << "](https://vocadb.net/S/" << *song->vocadb_id << ')';
            } else {
                ss << util::escape_markdown(song->name);
            }

            if (song->singer != NO_VIRTUAL_SINGER) {
                ss << " feat. ";
                song_singer_emoji(ss, *song);
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
            co_yield ss.str();
        }
    }

}

setlistlast_command::setlistlast_command(context &ctx) noexcept :
    iface_command(ctx, "setlistlast", "Full Concert Setlist with each song's previous appearance"),
    cmd_state_store(ctx),
    btn_reveal_state_store(ctx),
    btn_lang_state_store(ctx)
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

    ctx->bot->on_button_click(util::bind_front<&setlistlast_command::on_button_click>(this));

    return setlistlast_cmd;
}

namespace {
    constexpr size_t DISCORD_REPLY_LIMIT = 4000UZ;

    [[nodiscard]] dpp::message
    make_reveal_gui(const auto& message,
                    std::ranges::range auto&& header_content,
                    const setlistlast_command::event_state& state,
                    bool use_ephemeral,
                    std::optional<std::string> reveal_button_id)
    {
        const auto flags    = dpp::message_flags::m_using_components_v2 | (use_ephemeral ? dpp::message_flags::m_ephemeral : 0);
        auto real_msg       = dpp::message().set_flags(flags);
        auto container      = dpp::component().set_type(dpp::cot_container);
        container.set_accent(dpp::utility::rgb(134,206,203));

        /* Button row */
        if (reveal_button_id.has_value()) {
            auto action_row = dpp::component().set_type(dpp::cot_action_row);
            auto button     = dpp::component().set_type(dpp::cot_button)
                              .set_style(dpp::cos_primary)
                              .set_label("Post Publicly")
                              .set_id(reveal_button_id.value());
            action_row.add_component_v2(button);
            real_msg.add_component_v2(action_row);
        }

        /* header / thumbnail */
        if (!std::ranges::empty(header_content)) {
            auto c = lookup_concert(state.concert);
            auto section = dpp::component().set_type(dpp::cot_section);
            for (const auto& header : header_content) {
                auto widget = dpp::component().set_type(dpp::cot_text_display)
                              .set_content(header);
                section.add_component_v2(widget);
            }

            if (c && c->vocadb_event_id) {
                auto it = std::ranges::find_if(vocadb::events, [id = *c->vocadb_event_id](const auto &event) {
                    return event.id == id;
                });
                if (it != std::ranges::end(vocadb::events) &&
                    it->picture.original.size() > 0)
                {
                    std::string_view data{reinterpret_cast<const char *>(it->picture.original.data()), it->picture.original.size_bytes()};
                    real_msg.add_file("thumb.jpg", data, it->picture.mime);
                    section.set_accessory(dpp::component().set_type(dpp::cot_thumbnail).set_thumbnail("attachment://thumb.jpg"));
                }
            }
            container.add_component_v2(section);
        }

        auto text_display_1 = dpp::component().set_type(dpp::cot_text_display)
                                              .set_content(message);
        container.add_component_v2(text_display_1);

        real_msg.add_component_v2(container);
        return real_msg;
    }

    /* Takes a generator that produces multiple lines. It constructs a sequence
     * dpp::messages, each less than the reply limit and sends it off using the make_reveal_gui() */
    template <typename EventType, typename GeneratorCallable, typename GeneratorInput>
    dpp::task<std::expected<void, std::error_code>>
    reply_multimessage(const EventType& event,
                       context * const ctx,
                       GeneratorCallable&& line_generator,
                       GeneratorInput&& generator_input,
                       const setlistlast_command::event_state& state,
                       bool use_ephemeral,
                       std::optional<std::string> reveal_button_callback_key,
                       dpp::command_completion_event_t final_callback = dpp::utility::log_error())
    {
        std::ostringstream reply;
        std::vector<std::string> messages;

        const auto c = lookup_concert(state.concert);
        std::vector<std::string> headers;
        headers.emplace_back(std::format("## {}", c->name));
        if (c->last_date) {
            if (c->date.year() != c->last_date->year()) {
                headers.emplace_back(std::format("{:%A, %e %B %Y} – {:%A, %e %B %Y}", c->date, *c->last_date));
            } else if (c->date.month() != c->last_date->month()) {
                headers.emplace_back(std::format("{:%A, %b %e} – {:%A, %b %e %Y}", c->date, *c->last_date));
            } else {
                headers.emplace_back(std::format("{:%B %e (%a)}–{:%e (%a) %Y}", c->date, *c->last_date));
            }
        } else {
            headers.emplace_back(std::format("{:%A, %e %B %Y}", c->date));
        }
        if (auto it = std::ranges::find(vocadb::events, c->vocadb_event_id, &decltype(vocadb::events)::value_type::id);
            it != std::ranges::end(vocadb::events))
        {
            using namespace std::literals;
            std::vector<std::string> links;
            const auto is_official_weblink = [](const auto &link) static -> bool {
                return 0 == una::caseless::compare_utf8("Website (EN)"sv, link.description) ||
                    0 == una::caseless::compare_utf8("Website"sv, link.description) ||
                    0 == una::caseless::compare_utf8("Official website"sv, link.description) ||
                    0 == una::caseless::compare_utf8("mikuexpo.com"sv, link.description) ||
                    0 == una::caseless::compare_utf8("Official Page"sv, link.description) ||
                    0 == una::caseless::compare_utf8("Official Webpage"sv, link.description);
            };
            for (const auto &link : std::views::filter(it->web_links, is_official_weblink) | std::views::take(1))
            {
                links.emplace_back(std::format("[Offical Website]({})", link.url));
            }
            links.emplace_back(std::format("[VocaDB](https://vocadb.net/Es/{}/{})", it->id, it->url_slug));
            const auto is_vocawiki_weblink = [](const auto &link) static -> bool {
                return una::caseless::find_utf8(link.url, "vocaloid.wikia.com"sv) ||
                    una::caseless::find_utf8(link.url, "vocaloid.fandom.com"sv);
            };
            for (const auto &link : std::views::filter(it->web_links, is_vocawiki_weblink) | std::views::take(1))
            {
                links.emplace_back(std::format("[VocaWiki]({})", link.url));
            }
            headers.emplace_back(std::format("-# {}", std::views::join_with(links, " — "sv) | std::ranges::to<std::string>()));
        }
        auto header_size = std::ranges::fold_left(std::views::transform(headers, &std::string::size), 0UZ, std::plus<size_t>());
        for (const auto& line : std::invoke(std::forward<GeneratorCallable>(line_generator),
                                             std::forward<GeneratorInput>(generator_input)))
        {
            if ((reply.view().size() + line.size() + header_size) >= DISCORD_REPLY_LIMIT) {
                messages.emplace_back(reply.view());
                reply.str(std::string());
                reply << line;
                header_size = 0;
            } else {
                reply << line;
            }
        }

        if (reply.view().size() > 0) {
            messages.emplace_back(reply.view());
        }

        /* Ok, we have a list of messages to send. Reply, then follow up if necessary. */
        auto first_gui = make_reveal_gui(messages.front(), headers,
                                         state, use_ephemeral, reveal_button_callback_key);
        if (auto res = co_await event.co_reply(first_gui); res.is_error()) {
            ctx->log_error("reply_multimessage: {:d}", res.get_error());
            co_return std::unexpected(songbot_error::reply_failure);
        }

        for (const auto& msg : messages | std::views::drop(1)) {
            auto gui = make_reveal_gui(msg, std::views::empty<std::string>, state, use_ephemeral, std::nullopt);
            auto res = co_await event.co_follow_up(gui);
            if (res.is_error()) {
                ctx->log_error("reply_multimessage: {:d}", res.get_error());
                co_return std::unexpected(songbot_error::reply_failure);
            }
        }

        co_return {};
    }
}

dpp::task<void>
setlistlast_command::on_reveal_button_click(const dpp::button_click_t& event, const event_state& state)
{
    const auto concert = state.concert;
    auto on_completion = [event = state.event](const dpp::confirmation_callback_t &c) {
        auto msg = dpp::message().set_flags(dpp::message_flags::m_using_components_v2 | dpp::message_flags::m_ephemeral);
        if (c.is_error()) {
            dpp::utility::log_error()(c);
            msg.add_component_v2(dpp::component().set_type(dpp::cot_text_display).set_content("Sorry, I made a mistake and can't this setlist publically."));
        } else {
            msg.add_component_v2(dpp::component().set_type(dpp::cot_text_display).set_content("Setlist posted to channel!"));
        }
        event.edit_original_response(msg);
    };

    auto res = co_await reply_multimessage(event, ctx, &get_setlistlast_lines, concert, state, false, std::nullopt, on_completion);
    if (res) {
        setlistlast_reveal_success_counter->Increment();
    } else {
        setlistlast_reveal_failure_counter->Increment();
    }

    co_return;
}

dpp::task<void>
setlistlast_command::on_button_click(const dpp::button_click_t& event)
{
    auto cmd_key = btn_reveal_state_store.get(event.custom_id);
    if (!cmd_key) co_return;
    auto args = cmd_state_store.get(*cmd_key);
    if (!args) co_return;
    co_await on_reveal_button_click(event, *args);
    co_return;
}

dpp::task<std::expected<void, std::error_code>>
setlistlast_command::on_slashcommand(const dpp::slashcommand_t event)
{
    try {
        const auto concert = std::get<std::string>(event.get_parameter("event"));
        auto cmd_pair = cmd_state_store.insert(concert, event);
        auto reveal_btn_pair = btn_reveal_state_store.insert(cmd_pair.first);
        auto lang_btn_pair = btn_lang_state_store.insert(cmd_pair.first);
        cmd_pair.second.reveal_key = reveal_btn_pair.first;
        cmd_pair.second.lang_key = lang_btn_pair.first;

        auto res = co_await reply_multimessage(event, ctx, &get_setlistlast_lines, concert, cmd_pair.second, true, reveal_btn_pair.first);
        if (res) {
            setlistlast_success_counter->Increment();
            co_return res;
        } else {
            setlistlast_failure_counter->Increment();
            co_return res;
        }
    } catch(std::system_error &e) {
        event.reply("I have a bug in my programming, so I can't give you that setlist. I'm sorry!");
        ctx->log_error("/setlistlast: System Error {}", e.what());
        setlistlast_failure_counter->Increment();
        co_return std::unexpected(e.code());
    } catch (std::bad_variant_access &e) {
        event.reply("I have a bug in my programming, so I can't give you that setlist. I'm sorry!");
        ctx->log_error("/setlistlast: std::get() {}", e.what());
        setlistlast_failure_counter->Increment();
        co_return std::unexpected(songbot_error::explosion);
    }

    co_return {};
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
            ctx->log_error("/setlistlast: autocomplete error: {}", e.what());
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
