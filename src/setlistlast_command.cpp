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
    constexpr size_t DISCORD_REPLY_LIMIT = 4000UZ;

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
            lines.push_back(ss.str());
        }

        return lines;
    }

    /* Takes lines and concats them in a a big string less than DISCORD_REPLY_LIMIT */
    static std::vector<std::string>
    get_setlist_chunks(const Concert &concert, size_t header_size)
    {
        std::vector<std::string> messages;
        std::ostringstream reply;
        for (const auto& line : get_setlistlast_lines(concert))
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

        return messages;
    }

    static std::vector<std::string>
    get_header_lines(const Concert& concert)
    {
        std::vector<std::string> headers;
        headers.push_back(std::format("## {}", concert.name));
        if (concert.last_date) {
            if (concert.date.year() != concert.last_date->year()) {
                headers.push_back(std::format("{:%A, %e %B %Y} – {:%A, %e %B %Y}", concert.date, *concert.last_date));
            } else if (concert.date.month() != concert.last_date->month()) {
                headers.push_back(std::format("{:%A, %b %e} – {:%A, %b %e %Y}", concert.date, *concert.last_date));
            } else {
                headers.push_back(std::format("{:%B %e (%a)}–{:%e (%a) %Y}", concert.date, *concert.last_date));
            }
        } else {
            headers.push_back(std::format("{:%A, %e %B %Y}", concert.date));
        }
        if (auto it = std::ranges::find(vocadb::events, concert.vocadb_event_id, &decltype(vocadb::events)::value_type::id);
            it != std::ranges::end(vocadb::events))
        {
            using namespace std::literals;
            std::vector<std::string> links;
            const auto is_official_weblink = [](const auto &link) static -> bool {
	      return link.description.has_value() && link.url.has_value() && (
		    0 == una::caseless::compare_utf8("Website (EN)"sv, *link.description) ||
                    0 == una::caseless::compare_utf8("Website"sv, *link.description) ||
                    0 == una::caseless::compare_utf8("Official website"sv, *link.description) ||
                    0 == una::caseless::compare_utf8("mikuexpo.com"sv, *link.description) ||
                    0 == una::caseless::compare_utf8("Official Page"sv, *link.description) ||
                    0 == una::caseless::compare_utf8("Official Webpage"sv, *link.description));
            };
            for (const auto &link : std::views::filter(it->web_links, is_official_weblink) | std::views::take(1))
            {
                links.push_back(std::format("[Offical Website]({})", *link.url));
            }
            links.push_back(std::format("[VocaDB](https://vocadb.net/E/{}/{})", it->id, it->url_slug));
            const auto is_vocawiki_weblink = [](const auto &link) static -> bool {
	      return link.url.has_value() && (
		    una::caseless::find_utf8(*link.url, "vocaloid.wikia.com"sv) ||
                    una::caseless::find_utf8(*link.url, "vocaloid.fandom.com"sv));
            };
            for (const auto &link : std::views::filter(it->web_links, is_vocawiki_weblink) | std::views::take(1))
            {
                links.push_back(std::format("[VocaWiki]({})", *link.url));
            }
            headers.push_back(std::format("-# {}", std::views::join_with(links, " — "sv) | std::ranges::to<std::string>()));
        }

        return headers;
    }

}

setlistlast_command::setlistlast_command(context &ctx) noexcept :
    iface_command(ctx, "setlistlast", "Full Concert Setlist with each song's previous appearance")
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

    return setlistlast_cmd;
}

namespace {
    [[nodiscard]] dpp::component
    make_gui_header(const Concert& concert,
                    std::ranges::range auto&& header_content,
                    dpp::message& message)
    {
        auto section = dpp::component().set_type(dpp::cot_section);
        for (const auto& header : header_content) {
            auto widget = dpp::component().set_type(dpp::cot_text_display)
                .set_content(header);
            section.add_component_v2(widget);
        }

        if (concert.vocadb_event_id) {
            auto it = std::ranges::find_if(vocadb::events, [id = concert.vocadb_event_id](const auto &event) {
                return event.id == id;
            });
            if (it != std::ranges::end(vocadb::events) &&
                it->main_picture.original &&
                it->main_picture.original->size() > 0)
            {
                using namespace std::literals;
                std::string_view data{reinterpret_cast<const char *>(it->main_picture.original->data()), it->main_picture.original->size_bytes()};
                std::string filename = std::format("{}.{}", it->id, it->main_picture.original_file_ext.size() > 0 ? it->main_picture.original_file_ext : "jpg"sv);
                auto mime = it->main_picture.original_mime_type;
                if (mime.size() == 0 && it->main_picture.mime) {
                    mime = it->main_picture.mime.value();
                }
                message.add_file(filename, data, mime);
                section.set_accessory(dpp::component().set_type(dpp::cot_thumbnail).set_thumbnail(std::format("attachment://{}", filename)));
            }
        }

        return section;
    }


    [[nodiscard]] dpp::message
    make_reveal_gui(const std::string& message,
                    std::ranges::range auto&& header_content,
                    const Concert& concert,
                    bool use_ephemeral,
                    std::optional<std::string> reveal_button_id)
    {
        const auto flags      = dpp::message_flags::m_using_components_v2 | (use_ephemeral ? dpp::message_flags::m_ephemeral : 0);
        auto real_msg         = dpp::message().set_flags(flags);
        auto bottom_container = dpp::component().set_type(dpp::cot_container);
        bottom_container.set_accent(dpp::utility::rgb(134,206,203));

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
            auto section = make_gui_header(concert, header_content, real_msg);
            real_msg.add_component_v2(section);
        }

        /* Actual setlist content */
        using namespace std::literals;
        bool is_spoiler = (std::chrono::system_clock::now() - static_cast<std::chrono::sys_days>(concert.last_date.value_or(concert.date))) < (36h);
        if (is_spoiler) {
            bottom_container.set_spoiler(true);
            real_msg.add_component_v2(dpp::component().set_type(dpp::cot_text_display).set_content("Setlist Spoilers Below:"));
        }
        auto text_display_1 = dpp::component().set_type(dpp::cot_text_display)
                                              .set_content(message);
        bottom_container.add_component_v2(text_display_1);
        real_msg.add_component_v2(bottom_container);
        return real_msg;
    }

    template<typename Event>
    dpp::task<std::expected<void, std::error_code>>
    reply_and_followup(const Event& event, std::ranges::forward_range auto&& rng, context *ctx)
        requires std::same_as<std::ranges::range_value_t<decltype(rng)>, dpp::message>
    {
        if (auto conf = co_await event.co_reply(*std::ranges::begin(rng));
            conf.is_error())
        {
            co_return util::reply_handler(conf, ctx);
        }

        for (const auto& msg : rng | std::views::drop(1))
        {
            auto conf = co_await event.co_follow_up(msg);
            if (conf.is_error()) {
                co_return util::reply_handler(conf, ctx);
            }
        }

        co_return {};
    }

    auto
    make_gui_messages(const Concert& concert, std::ranges::forward_range auto& headers, std::ranges::forward_range auto& setlist_chunks, bool use_emphemeral, const std::optional<std::string>& reveal_button_key)
    {
        return std::views::concat(setlist_chunks | std::views::take(1) |
                                  std::views::transform([=, &headers](const auto &msg) {
                                      return make_reveal_gui(msg, headers,
                                                             concert, use_emphemeral, reveal_button_key); }),
                                  setlist_chunks | std::views::drop(1) |
                                  std::views::transform([=](const auto &msg) {
                                      return make_reveal_gui(msg, std::views::empty<std::string>,
                                                             concert, use_emphemeral, std::nullopt); }));
    }
}


/* Takes a generator that produces multiple lines. It constructs a sequence
 * dpp::messages, each less than the reply limit and sends it off using the make_reveal_gui() */

dpp::task<std::expected<void, std::error_code>>
setlistlast_command::reply_multimessage(const dpp::slashcommand_t& event,
                                        const Concert& concert)
{
    const auto reveal_click_key = std::make_optional<std::string>(ctx->keygen());
    auto headers = get_header_lines(concert);
    const auto header_size = std::ranges::fold_left(std::views::transform(headers, &std::string::size), 0UZ, std::plus<size_t>());
    auto setlist_chunks = get_setlist_chunks(concert, header_size);

    auto first_gui_msgs = make_gui_messages(concert, headers, setlist_chunks, true, reveal_click_key);
    if (auto res = co_await reply_and_followup(event, std::move(first_gui_msgs), ctx); !res) {
        co_return res;
    }

    /* Wait for button click or expiration */
    if (auto when_any_result = co_await dpp::when_any{
            event.owner->on_button_click.when([key = reveal_click_key](const auto& click) {
                return click.custom_id == key;
            }),
                event.owner->co_sleep(5 * 60) // 5 minutes
                };
        when_any_result.index() == 0)
    { // Button clicked
        const dpp::button_click_t click_event = when_any_result.get<0>();
        auto reveal_gui_msgs = make_gui_messages(concert, headers, setlist_chunks, false, std::nullopt);
        if (auto res = co_await reply_and_followup(click_event, reveal_gui_msgs, ctx); !res) {
            setlistlast_reveal_failure_counter->Increment();
            co_return res;
        }
        setlistlast_reveal_success_counter->Increment();
        auto success_msg = dpp::message().set_flags(dpp::message_flags::m_using_components_v2 | dpp::message_flags::m_ephemeral);
        success_msg.add_component_v2(dpp::component().set_type(dpp::cot_text_display).set_content("Setlist posted to channel!"));
        auto conf = co_await event.co_edit_original_response(success_msg);
        co_return util::reply_handler(conf, ctx);
    } else { // Button expiring. Just replace the first message.
        auto expired_gui_msgs = make_gui_messages(concert, headers, setlist_chunks, true, std::nullopt);
        auto res = co_await event.co_edit_original_response(*std::ranges::begin(expired_gui_msgs));
        co_return util::reply_handler(res, ctx);
    }

    co_return {};
}

dpp::task<std::expected<void, std::error_code>>
setlistlast_command::on_slashcommand(const dpp::slashcommand_t event)
{
    try {
        const auto concert_str = std::get<std::string>(event.get_parameter("event"));
        const auto concert = lookup_concert(concert_str);
        if (!concert) {
            dpp::message m{std::format("I'm sorry, I don't know about a concert named '{}'", concert_str)};
            m.set_flags(dpp::message_flags::m_ephemeral);
            auto res = co_await event.co_reply(m);
            setlistlast_failure_counter->Increment();
            co_return std::unexpected(util::reply_handler(res, ctx).error_or(songbot_error::no_match));
        }

        auto res = co_await reply_multimessage(event, *concert);
        if (res) {
            setlistlast_success_counter->Increment();
        } else {
            setlistlast_failure_counter->Increment();
        }
        co_return res;
    } catch(std::system_error &e) {
        dpp::message m("I have a bug in my programming, so I can't give you that setlist. I'm sorry!");
        m.set_flags(dpp::message_flags::m_ephemeral);
        event.reply(m);
        ctx->log_error("/setlistlast: System Error {}", e.what());
        setlistlast_failure_counter->Increment();
        co_return std::unexpected(e.code());
    } catch (std::bad_variant_access &e) {
        dpp::message m("I have a bug in my programming, so I can't give you that setlist. I'm sorry!");
        m.set_flags(dpp::message_flags::m_ephemeral);
        event.reply(m);
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
