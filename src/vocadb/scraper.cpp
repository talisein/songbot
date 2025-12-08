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

import concerts;
import songs;
import songbot.errors;
import vocadb.api;
import magic;

#include "scraper.hpp"

using json = nlohmann::json;

namespace
{
    constexpr std::string_view preamble { R"###(/*
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

/* THIS IS A GENERATED FILE, DO NOT EDIT DIRECTLY */

module;
)###"};

  constexpr std::string_view preamble_events { R"###(
export module vocadb.events;

import std;
import vocadb.api;

namespace vocadb {

using namespace std::literals;

)###"};

  constexpr std::string_view preamble_songs { R"###(
export module vocadb.songs;

import std;
import vocadb.api;

namespace vocadb {

using namespace std::literals;

)###"};


    const json test_event_one = json::parse(R"###({
  "additionalNames": "ミクFES'09（夏）, Miku FES'09 (Natsu)",
  "category": "Concert",
  "date": "2009-08-31T00:00:00Z",
  "description": "Hatsune Miku's 2nd anniversary fesitval.\n\n**Concert Schedule**:\n\n* **August 31st, 2009 (Mon.)**\nOPEN 18:00 / START19:00 (JST)",
  "id": 2522,
  "mainPicture": {
    "mime": "image/jpeg",
    "urlOriginal": "https://static.vocadb.net/img/releaseevent/mainOrig/2522.jpg?v=7",
    "urlSmallThumb": "https://static.vocadb.net/img/releaseevent/mainSmall/2522.jpg?v=7",
    "urlThumb": "https://static.vocadb.net/img/releaseevent/mainThumb/2522.jpg?v=7",
    "urlTinyThumb": "https://static.vocadb.net/img/releaseevent/mainTiny/2522.jpg?v=7"
  },
  "name": "Miku FES'09 (Summer)",
  "names": [
    {
      "language": "Romaji",
      "value": "Miku FES'09 (Natsu)"
    },
    {
      "language": "English",
      "value": "Miku FES'09 (Summer)"
    },
    {
      "language": "Japanese",
      "value": "ミクFES'09（夏）"
    }
  ],
  "seriesNumber": 0,
  "seriesSuffix": "",
  "songList": {
    "featuredCategory": "Concerts",
    "id": 219,
    "name": "ミクFES'09（夏）"
  },
  "status": "Approved",
  "urlSlug": "miku-fes09-natsu",
  "venue": {
    "address": "〒136-0082 東京都江東区新木場２丁目２−10",
    "addressCountryCode": "JP",
    "coordinates": {
      "formatted": "35.6423312, 139.8248855",
      "hasValue": true,
      "latitude": 35.6423312,
      "longitude": 139.8248855
    },
    "deleted": false,
    "id": 101,
    "name": "Studio Coast",
    "status": "Finished",
    "version": 1
  },
  "venueName": "新木場 StudioCoast",
  "version": 7,
  "webLinks": [
    {
      "category": "Reference",
      "description": "NicoNicoPedia",
      "disabled": false,
      "id": 949,
      "url": "https://dic.nicovideo.jp/a/%E3%83%9F%E3%82%AFfes%2709%28%E5%A4%8F%29"
    },
    {
      "category": "Other",
      "description": "HATSUNE MIKU OFFICIAL BLOG",
      "disabled": false,
      "id": 950,
      "url": "https://blog.piapro.net/2009/09/fes09.html"
    },
    {
      "category": "Other",
      "description": "Hatsune Miku LIVE Wiki",
      "disabled": false,
      "id": 951,
      "url": "https://www46.atwiki.jp/mikulive/pages/24.html"
    },
    {
      "category": "Reference",
      "description": "Vocaloid Wiki",
      "disabled": false,
      "id": 952,
      "url": "https://vocaloid.fandom.com/wiki/Miku_FES%2709_(Natsu)"
    },
    {
      "category": "Other",
      "description": "ASCII.jp",
      "disabled": false,
      "id": 6547,
      "url": "https://ascii.jp/elem/000/000/456/456009/"
    },
    {
      "category": "Other",
      "description": "Website",
      "disabled": true,
      "id": 6548,
      "url": "http://mikufes.jp/"
    },
    {
      "category": "Other",
      "description": "NicoNicoLive",
      "disabled": true,
      "id": 6549,
      "url": "http://www.nicovideo.jp/static/weblive/mikufes09/"
    },
    {
      "category": "Other",
      "description": "Streaming+",
      "disabled": true,
      "id": 6550,
      "url": "http://eplus.jp/miku-web"
    },
    {
      "category": "Other",
      "description": "BARKS",
      "disabled": false,
      "id": 6551,
      "url": "https://www.barks.jp/news/?id=1000051890"
    }
  ]
})###");

    const json test_event_two = json::parse(R"###({
  "additionalNames": "ミクの日感謝祭39's Giving Day",
  "category": "Concert",
  "date": "2010-03-09T00:00:00Z",
  "description": "",
  "id": 2520,
  "mainPicture": {
    "mime": "image/gif",
    "urlOriginal": "https://static.vocadb.net/img/releaseevent/mainOrig/2520.gif?v=8",
    "urlSmallThumb": "https://static.vocadb.net/img/releaseevent/mainSmall/2520.gif?v=8",
    "urlThumb": "https://static.vocadb.net/img/releaseevent/mainThumb/2520.gif?v=8",
    "urlTinyThumb": "https://static.vocadb.net/img/releaseevent/mainTiny/2520.gif?v=8"
  },
  "name": "Miku no Hi Kanshasai 39's Giving Day",
  "names": [
    {
      "language": "Romaji",
      "value": "Miku no Hi Kanshasai 39's Giving Day"
    },
    {
      "language": "Japanese",
      "value": "ミクの日感謝祭39's Giving Day"
    }
  ],
  "seriesNumber": 0,
  "seriesSuffix": "",
  "songList": {
    "featuredCategory": "Concerts",
    "id": 3952,
    "name": "ミクの日感謝祭 39's Giving Day Project DIVA presents 初音ミク・ソロコンサート～こんばんは、初音ミクです。〜"
  },
  "status": "Finished",
  "urlSlug": "miku-no-hi-kanshasai-39s-givin",
  "venue": {
    "address": "〒135-0064 東京都江東区青海１丁目３−11",
    "addressCountryCode": "JP",
    "coordinates": {
      "formatted": "35.6256638, 139.7823996",
      "hasValue": true,
      "latitude": 35.6256638,
      "longitude": 139.7823996
    },
    "deleted": false,
    "id": 162,
    "name": "Zepp Haneda",
    "status": "Finished",
    "version": 4
  },
  "venueName": "Zepp Tokyo in Odaiba",
  "version": 8,
  "webLinks": [
    {
      "category": "Other",
      "description": "Official website",
      "disabled": false,
      "id": 948,
      "url": "http://miku.sega.jp/39/mikufes.html"
    },
    {
      "category": "Reference",
      "description": "NicoNicoPedia",
      "disabled": false,
      "id": 1292,
      "url": "https://dic.nicovideo.jp/a/%E3%83%9F%E3%82%AF%E3%81%AE%E6%97%A5%E6%84%9F%E8%AC%9D%E7%A5%AD"
    },
    {
      "category": "Reference",
      "description": "Vocaloid Wiki",
      "disabled": false,
      "id": 1293,
      "url": "https://vocaloid.fandom.com/wiki/Miku_no_Hi_Kanshasai_39%27s_Giving_Day"
    }
  ]
})###");

    [[nodiscard]]
    std::string
    as_ymd(const json& j, std::string_view key) noexcept
    {
        if (j.contains(key)) {
            auto s = j[key].get<std::string>();
            std::istringstream ss(s);
            using namespace std::literals;
            std::chrono::year_month_day date{};
            ss >> std::chrono::parse("%Y-%m-%dT%H:%M:%S", date);
            if (ss.fail()) {
                std::println(std::cerr, "Failed to parse date {}", s);
		return "std::nullopt";
            }
            return std::format("{:d}y/{:d}/{:d}",
                               static_cast<int>(date.year()),
                               static_cast<unsigned int>(date.month()),
                               static_cast<unsigned int>(date.day()));
        } else {
            return "std::nullopt";
        }
    }

    using namespace std::literals;
    template<typename StringType>
    std::string as_raw(StringType&& s, std::string_view suffix = "XYX"sv)
    {
        return std::format(R"###(R"{}({}){}"sv)###", suffix, std::forward<StringType>(s), suffix);
    }

    template <typename T = std::string_view>
    [[nodiscard]]
    std::string
    as_opt(const json& j, std::string_view key) noexcept
    {
        if (j.contains(key)) {
            auto v = j[key].template get<T>();
            if constexpr (std::is_same_v<T, std::string> || std::is_same_v<T, std::string_view>) {
                if (v.empty()) return "std::nullopt";
                return as_raw(v);
	    } else if constexpr (std::is_same_v<T, bool>) {
	      if (v) {
		return "true";
	      } else {
		return "false";
	      }
            } else {
                return std::format("{}", v);
            }
        } else {
            return "std::nullopt";
        }
    }

    [[nodiscard]]
    std::expected<cpr::Url, std::error_code>
    sanitize_url(std::string url) noexcept
    {
        std::unique_ptr<CURLU, decltype([](CURLU *h) static { if (h) curl_url_cleanup(h); })> curlu_p { curl_url() };
        auto rc = curl_url_set(curlu_p.get(), CURLUPART_URL, url.c_str(), 0);
        if (CURLUE_OK != rc) return std::unexpected(std::make_error_code(rc));
        std::unique_ptr<char, decltype([](char *s) static { if (s) curl_free(s); })> scheme;
        std::unique_ptr<char, decltype([](char *s) static { if (s) curl_free(s); })> host;
        std::unique_ptr<char, decltype([](char *s) static { if (s) curl_free(s); })> path;
        rc = curl_url_get(curlu_p.get(), CURLUPART_SCHEME, std::out_ptr(scheme), cpr::FLAG_DEFAULT_SCHEME);
        if (CURLUE_OK != rc) return std::unexpected(std::make_error_code(rc));
        rc = curl_url_get(curlu_p.get(), CURLUPART_HOST, std::out_ptr(host), cpr::FLAG_PUNYCODE);
        if (CURLUE_OK != rc) return std::unexpected(std::make_error_code(rc));
        rc = curl_url_get(curlu_p.get(), CURLUPART_PATH, std::out_ptr(path), 0);
        if (CURLUE_OK != rc) return std::unexpected(std::make_error_code(rc));

        return cpr::Url{std::format("{}://{}{}", scheme.get(), host.get(), path.get())};
    }

    struct {
        std::string_view key;
        std::format_string<const std::string_view&, const std::uint64_t&> filename_format; // no extension
        std::format_string<const std::string_view&, const std::uint64_t&> filename_variable_format;
        std::format_string<const std::string_view&, const std::uint64_t&> mime_variable_format;
        std::format_string<const std::string_view&, const std::uint64_t&> file_ext_variable_format;
    } constexpr pic_key_filename_map[] = {
      { "urlOriginal",   "{}_pic_orig_{}", "{}_pic_orig_{}", "{}_mime_type_orig_{}", "{}_file_ext_orig_{}" },
        { "urlSmallThumb", "{}_pic_small_thumb_{}", "{}_pic_small_thumb_{}", "{}_mime_type_small_thumb_{}", "{}_file_ext_small_thumb_{}" },
        { "urlThumb",      "{}_pic_thumb_{}", "{}_pic_thumb_{}", "{}_mime_type_thumb_{}", "{}_file_ext_thumb_{}" },
        { "urlTinyThumb",  "{}_pic_tiny_thumb_{}", "{}_pic_tiny_thumb_{}", "{}_mime_type_tiny_thumb_{}", "{}_file_ext_tiny_thumb_{}" },
    };

    constexpr double target_mean_delay_sec = 5.0;
    constexpr double shape_k = 5.0;
    constexpr double scale_beta = target_mean_delay_sec / shape_k;

} // anonymous namespace

scraper::scraper(std::filesystem::path res_dir) noexcept :
    res_dir(std::move(res_dir)),
    rng_eng([]{ std::random_device rd; std::seed_seq seq {rd(), rd(), rd(), rd()}; return std::default_random_engine{seq};  }()),
    dist(shape_k, scale_beta)
{
    session.SetOption(cpr::UserAgent("github/talisein/songbot (dev)"));
    session.SetHeader(cpr::Header{{"User-Agent", "github/talisein/songbot"},
                                  {"Accept", "application/json"}});
}

std::expected<void, std::error_code>
scraper::scrape_songs(const std::filesystem::path& generated_src)
{
    std::vector<json> vec;
    vec.reserve(concerts.size());

    // sample for testing
        auto gen = std::mt19937{std::random_device{}()};
        std::vector<Song> sampled_songs;
        std::ranges::sample(songs, std::back_inserter(sampled_songs), 5, gen);

    for (auto song : std::views::all(sampled_songs)
             | std::views::filter([](const auto& s) { return s.vocadb_id.has_value(); })
        )
    {
        cpr::Url url{std::format(vocadb::songs_url, song.vocadb_id.value())};
        cpr::Parameters params{{"fields", "AdditionalNames,Artists,MainPicture,Names,PVs,ThumbUrl,WebLinks,Bpm,CultureCodes"},
                               {"lang", "English"}};
        std::println("Fetching root json for {}", song.name);
        auto res = get(url, params);
        if (res && res->status_code == 200) {
            vec.push_back(json::parse(res->text));
        }
    }

    std::ostringstream full_file;
    std::println(full_file, "{}{}", preamble, preamble_songs);

    // Write out un-exported stuff
    for (const auto& s : vec) {
        write_song_anonymous(s, full_file);
    }

    // now write the final array
    std::println(full_file, "export constexpr std::array<song, {}> songs {{{{", vec.size());
    for (const auto& s : vec) {
      const auto id = s["id"].get<std::uint64_t>();
      const std::string_view id_namespace = "song";
      using sv = std::string_view;
      std::println(full_file, R"###(  {{{0}, {1}, {2}, {3}, {4}, "{5}"sv, {6}, {7}, {8}, {9}, {10}, {11}, {12}, {13}, {14}, {15}, {16}, {17}, {18}, "{19}"sv, {20}, "{21}"sv, "{22}"sv, {23}, {24}, {25}, {26}}},)###",
		   /*0*/as_opt(s, "additionalNames"),
		   /*1*/std::format("song_artists_{}_{}", id_namespace, id),
		   /*2*/as_raw(s["artistString"].get<sv>()),
		   /*3*/as_ymd(s, "createDate"),
		   /*4*/as_raw(s["defaultName"].get<sv>()),
		   /*5*/s["defaultNameLanguage"].get<sv>(),
		   /*6*/as_opt<bool>(s, "deleted"),
		   /*7*/s["favoritedTimes"].get<std::uint64_t>(),
		   /*8*/s["id"].get<std::uint64_t>(),
		   /*9*/std::format("std::chrono::seconds({})", s["lengthSeconds"].get<std::uint64_t>()),
		   /*10*/s.contains("mainPicture") ? std::format("picture_{}_{}", id_namespace, id) : std::string{"std::nullopt"},
		   /*11*/as_opt<std::uint64_t>(s, "maxMilliBpm"),
		   /*12*/as_opt<std::uint64_t>(s, "mergedTo"),
		   /*13*/as_opt<std::uint64_t>(s, "minMilliBpm"),
		   /*14*/as_raw(s["name"].get<sv>()),
		   /*15*/std::format("names_{}_{}", id_namespace, id),
		   /*16*/as_opt<std::uint64_t>(s, "originalVersionId"),
		   /*17*/as_ymd(s, "publishDate"),
		   /*18*/s.contains("pvs") ? std::format("pvs_{}_{}", id_namespace, id) : std::string{"std::nullopt"},
		   /*19*/s["pvServices"].get<sv>(),
		   /*20*/s["ratingScore"].get<std::uint64_t>(),
		   /*21*/s["songType"].get<sv>(),
		   /*22*/s["status"].get<sv>(),
		   /*23*/as_raw(s["thumbUrl"].get<sv>()),
		   /*24*/s["version"].get<std::uint64_t>(),
		   /*25*/std::format("web_links_{}_{}", id_namespace, id),
		   /*26*/std::format("culture_codes_{}_{}", id_namespace, id)
		   );
    }

    std::println(full_file, "}}}};\n");
    std::println(full_file, "\n}} // namespace vocadb");
    std::println("Writing to {}", generated_src.string());
    std::fstream file { generated_src, std::ios_base::out | std::ios_base::trunc };
    if (!file.is_open()) {
        std::println("Not open!?");
    }
    file << full_file.view();
    file.flush();
    file.close();

    return {};
}

std::expected<void, std::error_code>
scraper::scrape_events(const std::filesystem::path& generated_src)
{
    std::vector<json> vec;
    vec.reserve(concerts.size());
    for (auto concert : std::views::all(concerts)
             | std::views::filter([](const auto& c) { return c.vocadb_event_id.has_value(); })
//             | std::views::take(2)
        )
    {
        cpr::Url url{std::format(vocadb::release_events_url, concert.vocadb_event_id.value())};
        cpr::Parameters params{{"fields", "AdditionalNames,Description,MainPicture,Names,Series,SongList,Venue,WebLinks"},
                               {"lang", "English"}};
        std::println("Fetching root json for {}", concert.name);
        auto res = get(url, params);
        if (res && res->status_code == 200) {
            vec.push_back(json::parse(res->text));
        }
    }

    std::ostringstream full_file;
    std::println(full_file, "{}{}", preamble, preamble_events);

    // Write out un-exported stuff
    for (const auto& e : vec) {
        write_event_anonymous(e, full_file);
    }

    // now write the final array
    std::println(full_file, "export constexpr std::array<release_event, {}> events {{{{", vec.size());
    for (const auto& e : vec) {
      const auto id = e["id"].get<std::uint64_t>();
        std::optional<json> song_list;
        if (e.contains("songList")) {
            song_list = e["songList"];
        }
        std::println(full_file, R"###(  {{{0}, "{1}"sv, {2}, {3}, {4}, {5}, {6}, {7}, {8}, {9}, {10}, {11}, {12}, {13}, "{14}"sv, {15}, {16}, {17} }},)###",
                     /*0*/as_opt(e, "additionalNames"),
                     /*1*/e["category"].get<std::string_view>(),
                     /*2*/as_ymd(e, "date"),
                     /*3*/as_opt(e, "description"),
                     /*4*/as_ymd(e, "endDate"),
                     /*5*/id,
                     /*6*/std::format("picture_release_event_{}", id),
                     /*7*/as_raw(e["name"].get<std::string>()),
		     /*8*/std::format("names_release_event_{}", id),
                     /*9*/as_opt<std::uint64_t>(e, "seriesId"),
                     /*10*/as_opt<std::uint64_t>(e, "seriesNumber"),
                     /*11*/as_opt(e, "seriesSuffix"),
                     /*12*/song_list.transform([](const auto &j) { return std::to_string(j["id"].template get<std::uint64_t>()); }).value_or("std::nullopt"),
                     /*13*/song_list.transform([](const auto &j) { return std::format("R\"({})\"", j["name"].template get<std::string_view>()); }).value_or("std::nullopt"),
                     /*14*/e["status"].get<std::string_view>(),
                     /*15*/as_raw(e["urlSlug"].get<std::string_view>()),
                     /*16*/as_opt(e, "venueName"),
		     /*17*/std::format("web_links_{}_{}", "release_event", id)
            );
    }
    std::println(full_file, "}}}};\n");

    std::println(full_file, "\n}} // namespace vocadb");

    std::println("Writing to {}", generated_src.string());
    std::fstream file { generated_src, std::ios_base::out | std::ios_base::trunc };
    if (!file.is_open()) {
        std::println("Not open!?");
    }
    file << full_file.view();
    file.flush();
    file.close();
    return {};
}

void
write_additional_names(std::ostream& os,
		       const json& names,
		       std::string_view id_namespace,
		       std::uint64_t id)
{
  std::println(os, "constexpr std::array<additional_name, {}> names_{}_{} {{{{",
	       names.size(),
	       id_namespace,
	       id);
  for (const auto& name : names) {
    std::println(os, R"XXX(  {{"{}"sv, R"XYX({})XYX"sv}},)XXX",
		 name["language"].get<std::string>(),
		 name["value"].get<std::string>());
  }
  std::println(os, "}}}};\n");
}

void
write_web_links(std::ostream& os,
		const json& weblinks,
		std::string_view id_namespace,
		std::uint64_t id)
{
  std::println(os, "constexpr std::array<web_link, {}> web_links_{}_{} {{{{",
	       weblinks.size(),
	       id_namespace,
	       id);
  for (const auto& weblink : weblinks) {
    std::println(os, R"(  {{"{}"sv, {}, {}, {} }},)",
		 weblink["category"].get<std::string>(),
		 as_opt(weblink, "description"),
		 as_opt(weblink, "url"),
		 weblink["id"].get<std::uint64_t>());
  }
  std::println(os, "}}}};\n");

}

std::expected<void, std::error_code>
scraper::write_pictures(std::ostream& os,
			const json& pic,
			const std::string_view id_namespace,
			const std::uint64_t id)
{
  auto picture_embeds = fetch_picture_embeds(pic, id_namespace, id);
  if (!picture_embeds) return std::unexpected(picture_embeds.error());
  for (const auto& [embed_fileinfo, map] : std::views::zip(std::views::all(picture_embeds.value()),
							 std::views::all(pic_key_filename_map)))
    {
      const auto filename_variable_name = std::format(map.filename_variable_format, id_namespace, id);
      const auto mime_variable_name     = std::format(map.mime_variable_format,     id_namespace, id);
      const auto ext_variable_name      = std::format(map.file_ext_variable_format, id_namespace, id);
      if (embed_fileinfo) {
	std::println(os, R"(
#if __has_embed("{}") == __STDC_EMBED_FOUND__
constexpr std::array {} = std::to_array<std::uint8_t>({{
    #embed "{}"
}});
constexpr std::string_view {} = "{}";
constexpr std::string_view {} = "{}";
#else
constexpr std::array<std::uint8_t, 0> {};
constexpr std::string_view {} = "inode/x-empty";
constexpr std::string_view {};
#endif
)",
                 embed_fileinfo->embed_filename, filename_variable_name, embed_fileinfo->embed_filename,
                 mime_variable_name, embed_fileinfo->mime_type,
                 ext_variable_name, embed_fileinfo->file_ext,
                 filename_variable_name, mime_variable_name, ext_variable_name);
      } else {
	std::println(os, R"(constexpr std::array<std::uint8_t, 0> {};
constexpr std::string_view {} = "inode/x-empty";
constexpr std::string_view {};
)", filename_variable_name, mime_variable_name, ext_variable_name);
      }
    }

  std::println(os, R"(constexpr picture picture_{0}_{1} = {{ {2}, {3}, {4}, {5}, {12}, {13}, {6}, {7}, {14}, {15}, {8}, {9}, {16}, {17}, {10}, {11}, {18}, {19}  }};
)",
               /*0*/id_namespace,
               /*1*/id,
               /*2 mime*/as_opt(pic, "mime"),
               /*3 name*/as_opt(pic, "name"),
               /*4 url_orig*/as_opt(pic, pic_key_filename_map[0].key),
               /*5 orig */std::format(pic_key_filename_map[0].filename_variable_format, id_namespace, id),
               /*6 url_small*/as_opt(pic, pic_key_filename_map[1].key),
               /*7 small*/std::format(pic_key_filename_map[1].filename_variable_format, id_namespace, id),
               /*8 url_thumb */as_opt(pic, pic_key_filename_map[2].key),
               /*9 thumb*/std::format(pic_key_filename_map[2].filename_variable_format, id_namespace, id),
               /*10 url tiny_thumb */as_opt(pic, pic_key_filename_map[3].key),
               /*11 tiny_thumb*/std::format(pic_key_filename_map[3].filename_variable_format, id_namespace, id),
               /*12*/std::format(pic_key_filename_map[0].mime_variable_format, id_namespace, id),
               /*13*/std::format(pic_key_filename_map[0].file_ext_variable_format, id_namespace, id),
               /*14*/std::format(pic_key_filename_map[1].mime_variable_format, id_namespace, id),
               /*15*/std::format(pic_key_filename_map[1].file_ext_variable_format, id_namespace, id),
               /*16*/std::format(pic_key_filename_map[2].mime_variable_format, id_namespace, id),
               /*17*/std::format(pic_key_filename_map[2].file_ext_variable_format, id_namespace, id),
               /*18*/std::format(pic_key_filename_map[3].mime_variable_format, id_namespace, id),
               /*19*/std::format(pic_key_filename_map[3].file_ext_variable_format, id_namespace, id)
    );

  return {};
}

void
write_song_artists(std::ostream& os,
		   const json& song_artists,
		   std::string_view id_namespace,
		   std::uint64_t id)
{
  std::println(os, "constexpr std::array<song_artists, {}> song_artists_{}_{} {{{{",
	       song_artists.size(),
	       id_namespace,
	       id);

  for (const auto& song_artist : song_artists) {
    using sv = std::string_view;
    if (song_artist.contains("artist")) {
      const auto artist = song_artist["artist"];
      std::println(os, R"(  {{ artist_t{{ {0}, "{1}"sv, {2}, {3}, {4}, {5}, {6}, "{7}"sv, {8} }}, "{9}"sv, "{10}"sv, {11}, {12}, {13}, {14}, "{15}"sv }},)",
		   /* 0 */ as_opt(artist, "additionalNames"),
		   /* 1 */ artist["artistType"].get<sv>(),
		   /* 2 */ as_opt<bool>(artist, "deleted"),
		   /* 3 */ artist["id"].get<std::uint64_t>(),
		   /* 4 */ as_opt(artist, "name"),
		   /* 5 */ as_opt(artist, "pictureMime"),
		   /* 6 */ as_ymd(artist, "releaseDate"),
		   /* 7 */ artist["status"].get<sv>(),
		   /* 8 */ artist["version"].get<std::uint64_t>(),
		   /* 9 */  song_artist["categories"].get<sv>(),
		   /* 10 */ song_artist["effectiveRoles"].get<sv>(),
		   /* 11 */ song_artist["id"].get<std::uint64_t>(),
		   /* 12 */ song_artist["isCustomName"].get<bool>() ? "true" : "false",
		   /* 13 */ song_artist["isSupport"].get<bool>() ? "true" : "false",
		   /* 14 */ as_opt(song_artist, "name"),
		   /* 15 */ song_artist["roles"].get<sv>()
		   );
    } else {
      std::println(os, R"(  {{ std::nullopt, "{0}"sv, "{1}"sv, {2}, {3}, {4}, {5}, "{6}"sv }},)",
		   /* 0 */ song_artist["categories"].get<sv>(),
		   /* 1 */ song_artist["effectiveRoles"].get<sv>(),
		   /* 2 */ song_artist["id"].get<std::uint64_t>(),
		   /* 3 */ song_artist["isCustomName"].get<bool>() ? "true" : "false",
		   /* 4 */ song_artist["isSupport"].get<bool>() ? "true" : "false",
		   /* 5 */ as_opt(song_artist, "name"),
		   /* 6 */ song_artist["roles"].get<sv>()
		   );

    }
  }
  std::println(os, "}}}};\n");

}

void
write_pvs(std::ostream& os,
	  const json& pvs,
	  std::string_view id_namespace,
	  std::uint64_t id)
{
  std::println(os, "constexpr std::array<song_pv, {}> pvs_{}_{} {{{{",
	       pvs.size(),
	       id_namespace,
	       id);

  for (const auto& pv : pvs) {
    using sv = std::string_view;
    std::string_view extended = "std::nullopt";
    if (pv.contains("extendedMetadata") && pv["extendedMetadata"].contains("json")) {
      extended = pv["extendedMetadata"]["json"].get<sv>();
    }
    std::println(os, R"(  {{ {0}, {1}, {2}, {3}, {4}, {5}, {6}, {7}, {8}, "{9}"sv, "{10}"sv, {11}, {12} }},)",
		 /*0*/as_opt(pv, "author"),
		 /*1*/as_opt<std::uint64_t>(pv, "createdBy"),
		 /*2*/pv["disabled"].get<bool>() ? "true" : "false",
		 /*3*/as_raw(extended),
		 /*4*/pv["id"].get<std::uint64_t>(),
		 /*5*/pv["length"].get<std::uint64_t>(),
		 /*6*/as_opt(pv, "name"),
		 /*7*/as_ymd(pv, "publishDate"),
		 /*8*/as_opt(pv, "pvId"),
		 /*9*/pv["service"].get<sv>(),
		 /*10*/pv["pvType"].get<sv>(),
		 /*11*/as_opt(pv, "thumbUrl"),
		 /*12*/as_opt(pv, "url")
		 );
  };
  std::println(os, "}}}};\n");
}

void
write_culture_codes(std::ostream& os,
		    const json& culture_codes,
		    std::string_view id_namespace,
		    std::uint64_t id)
{
  std::println(os, "constexpr std::array<std::string_view, {}> culture_codes_{}_{} {{{{",
	       culture_codes.size(),
	       id_namespace,
	       id);

  for (const auto& culture_code : culture_codes) {
    std::print(os, R"("{}"sv, )", culture_code.get<std::string_view>());
  }
  std::println(os, "}}}};\n");
}

std::expected<void, std::error_code>
scraper::write_song_anonymous(const json& song,  std::ostream& full_file)
{
    const auto this_id = song["id"].get<std::uint64_t>();
    const std::string_view this_id_namespace {"song"};

    std::println(full_file, R"(/* Start Song {}: {} */
)", this_id, song["name"].get<std::string_view>());
    if (song.contains("names")) {
      write_additional_names(full_file,
			     song["names"],
			     this_id_namespace,
			     this_id);
    }

    if (song.contains("webLinks")) {
      write_web_links(full_file,
		      song["webLinks"],
		      this_id_namespace,
		      this_id);
    }

    if (song.contains("mainPicture")) {
      auto res = write_pictures(full_file,
				song["mainPicture"],
				this_id_namespace,
				this_id);
      if (!res) return res;
    }

    if (song.contains("artists")) {
      write_song_artists(full_file,
			 song["artists"],
			 this_id_namespace,
			 this_id);
    }

    if (song.contains("cultureCodes")) {
      write_culture_codes(full_file,
			  song["cultureCodes"],
			  this_id_namespace,
			  this_id);
    }

    if (song.contains("pvs")) {
      write_pvs(full_file,
		song["pvs"],
		this_id_namespace,
		this_id);
    }

    std::println(full_file, R"(/* End Song {}: {} */
)", this_id, song["name"].get<std::string_view>());
    return {};
}


std::expected<void, std::error_code>
scraper::write_event_anonymous(const json& event,  std::ostream& full_file)
{
    const auto this_id = event["id"].get<std::uint64_t>();
    const std::string_view this_id_namespace {"release_event"};

    if (event.contains("names")) {
      write_additional_names(full_file,
			     event["names"],
			     this_id_namespace,
			     this_id);
    }

    if (event.contains("webLinks")) {
      write_web_links(full_file,
		      event["webLinks"],
		      this_id_namespace,
		      this_id);
    }

    if (event.contains("mainPicture")) {
      auto res = write_pictures(full_file,
				event["mainPicture"],
				this_id_namespace,
				this_id);
      if (!res) return res;
    }
    return {};
}

scraper::fetched_pic::fetched_pic(const std::filesystem::path& res_dir, std::string_view filename) :
  embed_filename(filename)
{
  const auto path = res_dir / embed_filename;

  if (auto mime = magic::get_mime(path); mime) {
    mime_type = mime.value();
  } else {
    try {
      std::rethrow_exception(mime.error());
    } catch (const std::exception& e) {
      std::println(std::cerr, "Error: Unable to determine mime type for {}: {}", path.native(), e.what());
    }
    mime_type = "image/jpeg";
  }

  if (auto ext = magic::get_ext(path); ext) {
    file_ext = ext.value();
  } else {
    try {
      std::rethrow_exception(ext.error());
    } catch (const std::exception& e) {
      std::println(std::cerr, "Error: Unable to determine extension for {}: {}", path.native(), e.what());
    }
    file_ext = "jpg";
  }
}

std::expected<std::vector<std::optional<scraper::fetched_pic>>, std::error_code>
scraper::fetch_picture_embeds(const json& pictures,
                              const std::string_view id_namespace,
                              const std::uint64_t id)
{
    std::vector<std::optional<scraper::fetched_pic>> downloaded_filenames;
    for (const auto& pic : pic_key_filename_map) {
        if (!pictures.contains(pic.key)) {
            downloaded_filenames.push_back(std::nullopt);
            continue;
        }
        const auto picture_url = pictures[pic.key].template get<std::string>();
        auto e_url = sanitize_url(picture_url);
        if (!e_url) {
          std::println(std::cerr, "Error: Failed to sanitize url {}: {}", picture_url, e_url.error().message());
          downloaded_filenames.push_back(std::nullopt);
          continue;
        }
        const auto filename_noext = std::format(pic.filename_format, id_namespace, id);
        const auto path = res_dir / filename_noext;
        const auto tmppath = std::filesystem::path{path}.replace_extension(".tmp");
        const auto now = std::chrono::system_clock::now();
        const auto last_modified = std::chrono::clock_cast<std::chrono::system_clock>(std::filesystem::exists(path) ? std::filesystem::last_write_time(path) : std::filesystem::file_time_type::min());
        if ((now - last_modified) < std::chrono::days{30}) {
          downloaded_filenames.emplace_back(std::in_place, res_dir, filename_noext);
          continue;
        }
        cpr::set_ifmodsince(session, last_modified);
        std::ofstream ofs {tmppath, std::ios::binary | std::ios::out | std::ios::trunc };
        if (!ofs) {
          std::println(std::cerr, "Error: Failed to open {}", tmppath.native());
          downloaded_filenames.push_back(std::nullopt);
          continue;
        }
        auto res = download(e_url.value(), ofs);
        if (!res) {
          if (res.error() == std::make_error_code(std::errc::no_such_file_or_directory)) {
            downloaded_filenames.push_back(std::nullopt);
            ofs.close();
            std::filesystem::remove(tmppath);
            if (std::filesystem::exists(path)) {
              if (0uz == std::filesystem::file_size(path)) {
                std::filesystem::last_write_time(path, std::chrono::clock_cast<std::chrono::file_clock>(now));
              } else {
                std::println("Info: {} was fetched before but returned 404 today", filename_noext);
              }
            } else {
              std::ofstream emptyfile {path};
            }
            continue;
          } else {
            std::println(std::cerr, "Error: Failed to download {}: {}", picture_url, res.error().message());
            downloaded_filenames.push_back(std::nullopt);
            continue;
          }
        }

        if (res->status_code == 304) {
          std::println("Info: {} has no change", filename_noext);
          ofs.close();
          std::filesystem::remove(tmppath);
          std::filesystem::last_write_time(path, std::chrono::clock_cast<std::chrono::file_clock>(now));
        } else {
          ofs.flush();
          std::println("Info: {} written (tmp), size {}", filename_noext, static_cast<std::streamoff>(ofs.tellp()));
          ofs.close();
          std::filesystem::rename(tmppath, path);
        }
        downloaded_filenames.emplace_back(std::in_place, res_dir, filename_noext);
    }

    return downloaded_filenames;
}

std::expected<cpr::Response, std::error_code>
scraper::get(const cpr::Url& url, const cpr::Parameters& params)
{
    try {
        using namespace std::literals;
        session.SetUrl(url);
        session.SetParameters(params);
        auto res = session.Get();
        std::this_thread::sleep_for(get_request_delay());
        if (res.error.code != cpr::ErrorCode::OK) {
            std::println(std::cerr, "Error: {}", res.error.message);
            return std::unexpected(cpr::make_error_code(res.error.code));
        }
        if (res.status_code == 404) {
            return std::unexpected(std::make_error_code(std::errc::no_such_file_or_directory));
        }
        if (res.status_code >= 400) {
            std::println(std::cerr, "Error: {}", res.status_code);
            std::println(std::cerr, "Body: {}", res.text);
            return std::unexpected(std::make_error_code(std::errc::invalid_argument));
        }
        return res;
    } catch (std::system_error& e) {
        return std::unexpected(e.code());
    }
}

std::expected<cpr::Response, std::error_code>
scraper::download(const cpr::Url& url, std::ofstream &os, const cpr::Parameters& params)
{
    try {
        using namespace std::literals;
        session.SetUrl(url);
        session.SetParameters(params);
        std::println("Fetching url {}", session.GetFullRequestUrl());
        auto res = session.Download(os);
        std::this_thread::sleep_for(get_request_delay());
        if (res.error.code != cpr::ErrorCode::OK) {
            std::println(std::cerr, "Error: {}", res.error.message);
            return std::unexpected(cpr::make_error_code(res.error.code));
        }
        if (res.status_code == 404) {
            return std::unexpected(std::make_error_code(std::errc::no_such_file_or_directory));
        }
        if (res.status_code >= 400) {
            std::println(std::cerr, "Error: {}", res.status_code);
            std::println(std::cerr, "Body: {}", res.text);
            return std::unexpected(std::make_error_code(std::errc::invalid_argument));
        }
        return res;
    } catch (std::system_error& e) {
        return std::unexpected(e.code());
    }
}


const std::error_category&
cpr::cpr_error_category() noexcept
{
    static CprErrorCategory instance;
    return instance;
}

std::error_code
cpr::make_error_code(ErrorCode e) noexcept
{
    return {static_cast<int>(e), cpr_error_category()};
}

std::chrono::milliseconds
scraper::get_request_delay()
{
    double time_in_seconds = dist(rng_eng);

    // 2. Construct a duration representing seconds with a double representation,
    //    then use duration_cast to convert it cleanly to the target unit (milliseconds).
    return std::chrono::duration_cast<std::chrono::milliseconds>(
        std::chrono::duration<double>(time_in_seconds)
    );
}
