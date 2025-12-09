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
        co_return {};
    }


    auto prev_concerts_rng = std::views::filter(std::views::reverse(setlists), [&name = song->name](const auto& track) { return name == track.song;}) |
        std::views::filter([](const auto& track) {
            auto concert = lookup_concert(track.concert_short_name);
            using namespace std::literals;
            return (std::chrono::system_clock::now() - static_cast<std::chrono::sys_days>(concert->last_date.value_or(concert->date))) > (36h);
        });
    if (std::ranges::empty(prev_concerts_rng)) {
        auto msg = dpp::message(std::format("I'm sorry, '{}' isn't in a concert I know about yet.", param)).set_flags(dpp::message_flags::m_ephemeral);
        event.reply(msg);
        last_failure_counter->Increment();
        co_return {};
    }

    auto count = std::ranges::distance(prev_concerts_rng);

    std::ostringstream ss;
    using namespace std::literals;
    ss << std::format("{} last played at {}", *song, lookup_concert(std::ranges::begin(prev_concerts_rng)->concert_short_name)->name);
    ss << std::ranges::begin(prev_concerts_rng)->variant.transform([](const auto &v) { return std::format(" `{}`. ", v); }).value_or(". ");

    auto remaining_concerts_rng = std::views::drop(prev_concerts_rng, 1);
    if (std::ranges::empty(remaining_concerts_rng)) {
        ss << "That's the only time its played!";
    } else {
        ss << "Prior to that: ";
        ss << tour_to_string(std::ranges::begin(remaining_concerts_rng)->concert_short_name);
        if (auto it = std::ranges::begin(remaining_concerts_rng); it->variant.has_value()) {
            ss << " `" << it->variant.value() << "`";
        }

        for (auto track : std::views::drop(remaining_concerts_rng, 1)) {
            ss << ", " << tour_to_string(track.concert_short_name);
            if (track.variant.has_value()) {
                ss << " `" << track.variant.value() << "`";
            }
        }
        ss << ". " << count << " times total.";
        ss << " Frequency Rank " << get_song_frequency_rank(song->name);
    }

    struct pic_details
    {
        std::span<const std::uint8_t> pic;
        std::string_view mime_type;
        std::string_view ext;
    };
    std::optional<pic_details> pic;
    std::string subtext;
    if (song->vocadb_id.has_value()) {
        auto it = std::ranges::find(vocadb::songs, *song->vocadb_id, &vocadb::song::id);
        if (it != std::ranges::end(vocadb::songs)) {
            try {
                std::ostringstream ss;
                std::print(ss, "-# ");
                if (it->publish_date) std::print(ss, "Published {} ", *it->publish_date);
                if (it->pvs) {
                    auto originals = std::views::filter(*it->pvs, [](const auto &pv) { return pv.pv_type == "Original"sv && pv.url.has_value(); });
                    auto yt = std::ranges::find(originals, "Youtube"sv, &vocadb::song_pv::service);
                    auto yt_end = std::ranges::end(originals);
                    auto yt2 = std::ranges::find(*it->pvs, "Youtube"sv, &vocadb::song_pv::service);
                    auto yt2_end = std::ranges::end(*it->pvs);
                    auto nnd = std::ranges::find(originals, "NicoNicoDouga"sv, &vocadb::song_pv::service);
                    auto nnd_end = std::ranges::end(originals);
                    auto nnd2 = std::ranges::find(*it->pvs, "NicoNicoDouga"sv, &vocadb::song_pv::service);
                    auto nnd2_end = std::ranges::end(*it->pvs);
                    if (yt != yt_end || nnd != nnd_end || yt2 != yt2_end || nnd2 != nnd2_end) {
                        std::print(ss, "PVs: ");
                    }
                    if (yt != yt_end) {
                        std::print(ss, "[{}]({}) ", yt->service, *yt->url);
                    } else if (yt2 != yt2_end) {
                        std::print(ss, "[{}]({}) ", yt2->service, *yt2->url);
                    }
                    if (nnd != nnd_end) {
                        std::print(ss, "[{}]({}) ", nnd->service, *nnd->url);
                    } else if (nnd2 != nnd2_end) {
                        std::print(ss, "[{}]({}) ", nnd2->service, *nnd2->url);
                    }
                }
                if (!it->web_links.empty()) {
                    auto rng = std::views::filter(it->web_links, [](const auto& link) { return link.description.has_value() && link.url.has_value(); });
                    auto end = std::ranges::end(rng);
                    auto lyrics = std::ranges::find_if(rng, [](const auto& link) { return *link.description == "Vocaloid Lyrics Wiki"sv; });
                    auto wiki = std::ranges::find_if(rng, [](const auto& link) { return *link.description == "Vocaloid Wiki"sv; });
                    if (lyrics != end || wiki != end) {
                        std::print(ss, "Info: ");
                    }
                    if (lyrics != end && wiki != end) {
                        std::print(ss, "[Lyrics]({}), ", *lyrics->url);
                    } else if (lyrics != end) {
                        std::print(ss, "[Lyrics]({})", *lyrics->url);
                    }
                    if (wiki != end) {
                        std::print(ss, "[VocaWiki]({})", *wiki->url);
                    }
                }
                subtext = ss.str();
                pic = it->main_picture.transform([](const auto& pic) -> pic_details {
                    if (pic.original && pic.thumb) {
                        if (pic.original->size() > pic.thumb->size()) {
                            return {*pic.original, pic.original_mime_type, pic.original_file_ext};
                        } else {
                            return {*pic.thumb, pic.thumb_mime_type, pic.thumb_file_ext};
                        }
                    }
                    if (pic.original && pic.original->size() > 0) {
                        return {*pic.original, pic.original_mime_type, pic.original_file_ext};
                    }
                    if (pic.thumb && pic.thumb->size() > 0) {
                        return {*pic.thumb, pic.thumb_mime_type, pic.thumb_file_ext};
                    }
                    if (pic.small_thumb && pic.small_thumb->size() > 0) {
                        return {*pic.small_thumb, pic.small_thumb_mime_type, pic.small_thumb_file_ext};
                    }
                    if (pic.tiny_thumb && pic.tiny_thumb->size() > 0) {
                        return {*pic.tiny_thumb, pic.tiny_thumb_mime_type, pic.tiny_thumb_file_ext};
                    }
                    throw "oops";
                });
            } catch (...) {
            }
        }
    }

    if (!pic) {
        dpp::message msg{ss.view()};
        msg.suppress_embeds(true);
        event.reply(msg);
    } else {
        auto msg = dpp::message().set_flags(dpp::message_flags::m_using_components_v2).suppress_embeds(true);
        auto section = dpp::component().set_type(dpp::cot_section);
        auto text = dpp::component().set_type(dpp::cot_text_display).set_content(ss.str());
        section.add_component_v2(text);
        section.add_component_v2(dpp::component().set_type(dpp::cot_text_display).set_content(subtext));
        auto filename = std::format("{}.{}", *song->vocadb_id, pic->ext);
        std::string_view data{reinterpret_cast<const char *>(pic->pic.data()), pic->pic.size_bytes()};
        msg.add_file(filename, data, pic->mime_type);
        section.set_accessory(dpp::component().set_type(dpp::cot_thumbnail).set_thumbnail(std::format("attachment://{}", filename)));
        msg.add_component_v2(section);
        event.reply(msg);
    }
    last_success_counter->Increment();
    co_return {};
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
