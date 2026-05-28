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

#pragma once

import std;
import dpp;
import songs;

class context;

struct pic_details
{
    std::span<const std::uint8_t> pic;
    std::string_view mime_type;
    std::string_view ext;
};

struct concert_history
{
    std::string main_text;
    std::string priors_text;
};

struct vocadb_enrichment
{
    std::string subtext;
    std::optional<pic_details> pic;
};

std::expected<Song, std::string>
resolve_song_from_param(std::string_view param, context* ctx,
                        std::function<std::expected<Song, std::string>(std::string_view)> name_fallback);

concert_history build_concert_history(const Song& song);

vocadb_enrichment enrich_from_vocadb(const Song& song, context* ctx);

class song_card_component : public dpp::component
{
public:
    /* Constructs as a cot_section */
    song_card_component();

    song_card_component& set_title(std::string content);
    /* filename is copied; mime_type and data are non-owning views into static constexpr storage */
    song_card_component& set_image(std::string fname, std::string_view mtype, std::string_view data);
    /* second cot_text_display in the section */
    song_card_component& set_left(std::string content);
    /* cot_text_display after the section; folded into left if short */
    song_card_component& set_bottom(std::string content);

    /* Finalises the section structure and appends it (and optionally a bottom text) to msg.
       Must only be called once. */
    void apply_to(dpp::message& msg);

private:
    std::string title;
    std::string left;
    std::string bottom;
    std::string filename;
    std::string_view mime_type;
    std::string_view image_data;
};
