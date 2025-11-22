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
module;

export module vocadb.api;

import std;

export namespace vocadb
{
    using namespace std::literals;
    constexpr std::string_view base_url { "https://vocadb.net"sv };
    constexpr std::string_view release_events_url { "https://vocadb.net/api/releaseEvents/{}"sv };
    constexpr std::string_view songs_url { "https://vocadb.net/api/songs/{}"sv };

    struct release_event_picture
    {
        std::string_view mime;
        std::optional<std::string_view> name;
        std::string_view url_original;
        std::span<const std::uint8_t> original;
        std::string_view url_small_thumb;
        std::span<const std::uint8_t> small_thumb;
        std::string_view url_thumb;
        std::span<const std::uint8_t> thumb;
        std::string_view url_tiny_thumb;
        std::span<const std::uint8_t> tiny_thumb;
    };

    struct additional_name
    {
        std::string_view language;
        std::string_view name;
    };

    struct web_link
    {
        std::string_view category;
        std::string_view description;
        std::string_view url;
        std::uint64_t id;
    };

    struct release_event
    {
        // AdditionalNames
        std::string_view additional_names;
        std::string_view category;
        std::chrono::year_month_day date;
        // Description
        std::optional<std::string_view> description;
        std::optional<std::chrono::year_month_day> end_date;
        std::uint64_t id;
        // Main Picture
        release_event_picture picture;
        std::string_view name;
        // Names
        std::span<const additional_name> names;
        // Series
        std::optional<std::uint64_t> series_id;
        std::optional<std::uint64_t> series_number; // e.g. 2018 for snow miku 2018
        std::optional<std::string_view> series_suffix;
        // SongList
        std::optional<std::uint64_t> song_list_id;
        std::optional<std::string_view> song_list_name;

        std::string_view status;
        std::string_view url_slug;

        // Tags (skip)

        // Venue
        std::optional<std::string_view> venue_name;

        // WebLinks
        std::span<const web_link> web_links;
    };

} // namespace vocadb
