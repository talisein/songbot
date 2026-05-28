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
import project_diva;
import vocadb.api;
import vocadb.songs;
import localvoid;

#include "last_shared.hpp"
#include "context.hpp"

namespace
{
    using namespace std::literals;
    constexpr std::string_view INDEX_PREFIX {"idx:"sv};
}

std::expected<Song, std::string>
resolve_song_from_param(std::string_view param, context* ctx,
                        std::function<std::expected<Song, std::string>(std::string_view)> name_fallback)
{
    if (!param.starts_with(INDEX_PREFIX))
        return name_fallback(param);

    std::string_view sv = param;
    sv.remove_prefix(INDEX_PREFIX.size());
    const auto sv_end = sv.data() + sv.size();

    std::ranges::range_difference_t<decltype(songs)> idx;

    auto [ptr, ec] = std::from_chars(sv.data(), sv_end, idx);
    if (ec != std::errc{}) {
        if (ec == std::errc::invalid_argument)
            return std::unexpected("I'm sorry, what are you even asking me?"s);
        if (ec == std::errc::result_out_of_range)
            return std::unexpected("I'm sorry, but that's asking for a bit much..."s);
        ctx->log_error("While parsing {}: {}", param, std::make_error_code(ec).message());
        return std::unexpected("I'm sorry, I'm just not prepared to answer that."s);
    }
    if (ptr != sv_end)
        return std::unexpected("I'm sorry, I didn't quite catch all of that..."s);
    if (auto remaining = std::views::drop(songs, idx); std::ranges::empty(remaining))
        return std::unexpected("I know about ODDS&ENDS, but not overflows off ends. Hahaha..."s);
    else
        return *std::ranges::begin(remaining);
}

concert_history build_concert_history(const Song& song)
{
    using namespace std::literals;
    concert_history result;

    auto prev_concerts_rng = std::views::filter(std::views::reverse(setlists), util::bind_front<exact_song_track_match>(song)) |
        std::views::filter(is_past_spoiler_window);
    std::ostringstream ss;
    std::ostringstream priors;

    if (std::ranges::empty(prev_concerts_rng)) {
        if (song_is_game_track(song)) {
            ss << std::format("{} hasn't been performed at a concert yet, but it is in the Project DIVA games.", song);
        } else {
            ss << std::format("{} isn't in a concert or game I know about yet — I just think it's neat!", song);
        }
    } else {
        auto count = std::ranges::distance(prev_concerts_rng);
        ss << std::format("{} last played at {}", song, lookup_concert(std::ranges::begin(prev_concerts_rng)->concert_short_name)->name);
        ss << std::ranges::begin(prev_concerts_rng)->variant.transform([](const auto &v) { return std::format(" `{}`. ", v); }).value_or(".");

        auto remaining_concerts_rng = std::views::drop(prev_concerts_rng, 1);
        if (std::ranges::empty(remaining_concerts_rng)) {
            ss << " That's the only time its played!";
        } else {
            priors << "Prior lives: ";
            priors << tour_to_string(std::ranges::begin(remaining_concerts_rng)->concert_short_name);
            if (auto it = std::ranges::begin(remaining_concerts_rng); it->variant.has_value()) {
                priors << " `" << it->variant.value() << "`";
            }

            for (auto track : std::views::drop(remaining_concerts_rng, 1)) {
                priors << ", " << tour_to_string(track.concert_short_name);
                if (track.variant.has_value()) {
                    priors << " `" << track.variant.value() << "`";
                }
            }
            priors << ". " << count << " times total.";
            priors << " Frequency Rank " << get_song_frequency_rank(song.name);
        }
    }

    result.main_text = ss.str();
    result.priors_text = priors.str();
    return result;
}

vocadb_enrichment enrich_from_vocadb(const Song& song, context* ctx)
{
    using namespace std::literals;
    vocadb_enrichment result;

    if (!song.vocadb_id.has_value())
        return result;

    auto it = std::ranges::find(vocadb::songs, *song.vocadb_id, &vocadb::song::id);
    if (it == std::ranges::end(vocadb::songs))
        return result;

    try {
        std::ostringstream ss;
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
                std::print(ss, "[Nico]({}) ", *nnd->url);
            } else if (nnd2 != nnd2_end) {
                std::print(ss, "[Nico]({}) ", *nnd2->url);
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
        {
            auto games = get_song_games(song);
            if (!games.empty()) {
                std::print(ss, " Games: {}", diva_game_short_name(games.front()));
                for (const auto& g : games | std::views::drop(1)) {
                    std::print(ss, ", {}", diva_game_short_name(g));
                }
            }
        }
        if (auto lv_it = std::ranges::find(localvoid::localvoid_ranks, *song.vocadb_id, &localvoid::localvoid_data::vocadb_id);
            lv_it != std::ranges::end(localvoid::localvoid_ranks))
        {
            std::print(ss, "\n-# [Peak Chart Rank](https://lvchart.com/?year={}&month={}&week={}): {}", lv_it->ymw.y, lv_it->ymw.m, lv_it->ymw.w, lv_it->peak_rank);
            if (lv_it->weeks > 1) {
                std::print(ss, " ({} weeks)", lv_it->weeks);
            }
        }

        result.subtext = ss.str();
        result.pic = it->main_picture.and_then([](const auto& mp) -> std::optional<pic_details> {
            if (mp.original && mp.thumb) {
                if (mp.original->size() > mp.thumb->size()) {
                    return pic_details{*mp.original, mp.original_mime_type, mp.original_file_ext};
                } else {
                    return pic_details{*mp.thumb, mp.thumb_mime_type, mp.thumb_file_ext};
                }
            }
            if (mp.original && mp.original->size() > 0)
                return pic_details{*mp.original, mp.original_mime_type, mp.original_file_ext};
            if (mp.thumb && mp.thumb->size() > 0)
                return pic_details{*mp.thumb, mp.thumb_mime_type, mp.thumb_file_ext};
            if (mp.small_thumb && mp.small_thumb->size() > 0)
                return pic_details{*mp.small_thumb, mp.small_thumb_mime_type, mp.small_thumb_file_ext};
            if (mp.tiny_thumb && mp.tiny_thumb->size() > 0)
                return pic_details{*mp.tiny_thumb, mp.tiny_thumb_mime_type, mp.tiny_thumb_file_ext};
            return std::nullopt;
        });
    } catch (const std::exception& e) {
        ctx->log_error("vocadb enrichment failed for id {}: {}", *song.vocadb_id, e.what());
    }

    return result;
}

song_card_component::song_card_component()
{
    set_type(dpp::cot_section);
}

song_card_component& song_card_component::set_title(std::string content)
{
    title = std::move(content);
    return *this;
}

song_card_component& song_card_component::set_image(std::string fname, std::string_view mtype, std::string_view data)
{
    filename = std::move(fname);
    mime_type = mtype;
    image_data = data;
    return *this;
}

song_card_component& song_card_component::set_left(std::string content)
{
    left = std::move(content);
    return *this;
}

song_card_component& song_card_component::set_bottom(std::string content)
{
    bottom = std::move(content);
    return *this;
}

void song_card_component::apply_to(dpp::message& msg)
{
    constexpr auto PRIORS_THRESHOLD = 65UZ;
    bool bottom_inline = !bottom.empty() && bottom.size() <= PRIORS_THRESHOLD;

    std::string left_content = left;
    if (bottom_inline) {
        if (!left_content.empty())
            left_content += '\n';
        left_content += bottom;
    }

    if (!filename.empty()) {
        /* Section requires an accessory — only use it when we have an image */
        if (!title.empty())
            add_component_v2(dpp::component().set_type(dpp::cot_text_display).set_content(title));
        if (!left_content.empty())
            add_component_v2(dpp::component().set_type(dpp::cot_text_display).set_content(left_content));
        msg.add_file(filename, image_data, mime_type);
        set_accessory(dpp::component().set_type(dpp::cot_thumbnail).set_thumbnail(std::format("attachment://{}", filename)));
        msg.add_component_v2(*this);
    } else {
        if (!title.empty())
            msg.add_component_v2(dpp::component().set_type(dpp::cot_text_display).set_content(title));
        if (!left_content.empty())
            msg.add_component_v2(dpp::component().set_type(dpp::cot_text_display).set_content(left_content));
    }

    if (!bottom.empty() && !bottom_inline) {
        msg.add_component_v2(dpp::component().set_type(dpp::cot_text_display).set_content(bottom));
    }
}
