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

    struct picture
    {
      std::optional<std::string_view> mime;
      std::optional<std::string_view> name;
      std::optional<std::string_view> url_original;
      std::optional<std::span<const std::uint8_t>> original;
      std::string_view original_mime_type;
      std::string_view original_file_ext;
      std::optional<std::string_view> url_small_thumb;
      std::optional<std::span<const std::uint8_t>> small_thumb;
      std::string_view small_thumb_mime_type;
      std::string_view small_thumb_file_ext;
      std::optional<std::string_view> url_thumb;
      std::optional<std::span<const std::uint8_t>> thumb;
      std::string_view thumb_mime_type;
      std::string_view thumb_file_ext;
      std::optional<std::string_view> url_tiny_thumb;
      std::optional<std::span<const std::uint8_t>> tiny_thumb;
      std::string_view tiny_thumb_mime_type;
      std::string_view tiny_thumb_file_ext;
    };

    struct additional_name
    {
        std::string_view language;
        std::string_view name;
    };

    struct web_link
    {
        std::string_view category;
        std::optional<std::string_view> description;
        std::optional<std::string_view> url;
        std::uint64_t id;
    };

  struct artist_t
  {
    std::optional<std::string_view> additional_names;
    std::string_view artist_type;
    std::optional<bool> deleted;
    std::uint64_t id;
    std::optional<std::string_view> name;
    std::optional<std::string_view> picture_mime;
    std::optional<std::chrono::year_month_day> release_date;
    std::string_view status;
    std::uint64_t version;
  };

  struct song_artists
  {
    std::optional<artist_t> artist;
    std::string_view categories;
    std::string_view effective_roles;
    std::uint64_t id;
    bool is_custom_name;
    bool is_support;
    std::optional<std::string_view> name;
    std::string_view roles;
  };

  struct song_pv
  {
    std::optional<std::string_view> author;
    std::optional<std::uint64_t> created_by;
    bool disabled;
    std::optional<std::string_view> extended_metadata_json;
    std::uint64_t id;
    std::uint64_t length;
    std::optional<std::string_view> name;
    std::optional<std::chrono::year_month_day> publish_date;
    std::optional<std::string_view> pv_id;
    std::string_view service;
    std::string_view pv_type;
    std::optional<std::string_view> thumb_url;
    std::optional<std::string_view> url;
  };


    struct release_event
    {
        // AdditionalNames
        std::optional<std::string_view> additional_names;
        std::string_view category;
        std::chrono::year_month_day date;
        // Description
        std::optional<std::string_view> description;
        std::optional<std::chrono::year_month_day> end_date;
        std::uint64_t id;
        // Main Picture
        picture main_picture;
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

  struct song
  {
    std::optional<std::string_view> additional_names;
    // albums (skip)
    std::span<const song_artists> artists;
    std::string_view artist_string;
    std::optional<std::chrono::year_month_day> create_date;
    std::string_view default_name;
    std::string_view default_name_language;
    std::optional<bool> deleted;
    std::uint64_t favorited_times;
    std::uint64_t id;
    std::chrono::seconds length;
    // lyrics (skip)
    std::optional<picture> main_picture;
    std::optional<std::uint64_t> max_milli_bpm;
    std::optional<std::uint64_t> merged_to;
    std::optional<std::uint64_t> min_milli_bpm;
    std::string_view name;
    std::span<const additional_name> names;
    std::optional<std::uint64_t> original_version_id;
    std::optional<std::chrono::year_month_day> publish_date;
    std::optional<std::span<const song_pv>> pvs;
    std::string_view pv_services;
    std::uint64_t rating_score;
    // release_event (skip)
    // release_events (skip)
    std::string_view song_type;
    std::string_view status;
    // tags (skip)
    std::string_view thumb_url;
    std::uint64_t version;
    std::span<const web_link> web_links;
    std::span<const std::string_view> culture_codes;
  };

} // namespace vocadb
