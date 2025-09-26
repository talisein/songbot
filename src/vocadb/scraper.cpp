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

#include "scraper.hpp"
#include "../errors.hpp"
#include "vocadb-api.hpp"

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

#include "vocadb-api.hpp"

export module vocadb.events;

import std;

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
            std::chrono::year_month_day date;
            ss >> std::chrono::parse("%Y-%m-%dT%H:%M:%SZ", date);

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
            } else {
                return std::format("{}", v);
            }
        } else {
            return "std::nullopt";
        }
    }

    [[nodiscard]]
    cpr::Url
    sanitize_url(std::string_view sv) noexcept
    {
        return cpr::Url{sv.substr(0, sv.find_last_of('?'))};
    }

    struct {
        std::string_view key;
        std::format_string<std::uint64_t, const std::string_view&> filename_format;
        std::format_string<const std::uint64_t&> variable_format;
    } constexpr pic_key_filename_map[] = {
        { "urlOriginal",   "event_pic_orig_{}.{}", "event_pic_orig_{}" },
        { "urlSmallThumb", "event_pic_small_thumb_{}.{}", "event_pic_small_thumb_{}" },
        { "urlThumb",      "event_pic_thumb_{}.{}", "event_pic_thumb_{}" },
        { "urlTinyThumb",  "event_pic_tiny_thumb_{}.{}", "event_pic_tiny_thumb_{}" },
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
    std::println(full_file, "{}", preamble);

    // Write out un-exported stuff
    for (const auto& e : vec) {
        write_event_anonymous(e, full_file);
    }

    // now write the final array
    std::println(full_file, "export constexpr std::array<release_event, {}> events {{{{", vec.size());
    for (const auto& e : vec) {
        std::optional<json> song_list;
        if (e.contains("songList")) {
            song_list = e["songList"];
        }
        std::println(full_file, R"###(  {{{0}, "{1}"sv, {2}, {3}, {4}, {5}, {6}, {7}, {8}, {9}, {10}, {11}, {12}, {13}, "{14}"sv, {15}, {16}, {17} }},)###",
                     /*0*/as_raw(e["additionalNames"].get<std::string_view>()),
                     /*1*/e["category"].get<std::string_view>(),
                     /*2*/as_ymd(e, "date"),
                     /*3*/as_opt(e, "description"),
                     /*4*/as_ymd(e, "endDate"),
                     /*5*/e["id"].get<std::uint64_t>(),
                     /*6*/std::format("event_picture_{}", e["id"].get<std::uint64_t>()),
                     /*7*/as_raw(e["name"].get<std::string>()),
                     /*8*/std::format("names_{}", e["id"].get<std::uint64_t>()),
                     /*9*/as_opt<std::uint64_t>(e, "seriesId"),
                     /*10*/as_opt<std::uint64_t>(e, "seriesNumber"),
                     /*11*/as_opt(e, "seriesSuffix"),
                     /*12*/song_list.transform([](const auto &j) { return std::to_string(j["id"].template get<std::uint64_t>()); }).value_or("std::nullopt"),
                     /*13*/song_list.transform([](const auto &j) { return std::format("R\"({})\"", j["name"].template get<std::string_view>()); }).value_or("std::nullopt"),
                     /*14*/e["status"].get<std::string_view>(),
                     /*15*/as_raw(e["urlSlug"].get<std::string_view>()),
                     /*16*/as_opt(e, "venueName"),
                     /*17*/std::format("web_links_{}", e["id"].get<std::uint64_t>())
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
scraper::write_event_anonymous(const json& event,  std::ostream& full_file)
{
    const auto this_id = event["id"].get<std::uint64_t>();
    if (event.contains("names")) {
        std::println(full_file, "/* {} */\nconstexpr std::array<additional_name, {}> names_{} {{{{",
                     event["name"].get<std::string>(),
                     event["names"].size(),
                     this_id);
        for (const auto& name : event["names"]) {
            std::println(full_file, R"XXX(  {{"{}"sv, R"XYX({})XYX"sv}},)XXX",
                         name["language"].get<std::string>(),
                         name["value"].get<std::string>());
        }
        std::println(full_file, "}}}};\n");
    }

    if (event.contains("webLinks")) {
        std::println(full_file, "/* {} */\nconstexpr std::array<web_link, {}> web_links_{} {{{{",
                     event["name"].get<std::string>(),
                     event["webLinks"].size(),
                     this_id);
        for (const auto& name : event["webLinks"]) {
            std::println(full_file, R"(  {{"{}"sv, "{}"sv, "{}"sv, {} }},)",
                         name["category"].get<std::string>(),
                         name["description"].get<std::string>(),
                         name["url"].get<std::string>(),
                         name["id"].get<std::uint64_t>());
        }
        std::println(full_file, "}}}};\n");
    }

    if (event.contains("mainPicture")) {
        std::println(full_file, "/* {} */", event["name"].get<std::string>());

        auto picture_embeds = fetch_event_embeds(event);
        if (!picture_embeds) return std::unexpected(picture_embeds.error());
        for (const auto& [opt_filename, map] : std::views::zip(std::views::all(picture_embeds.value()),
                                                               std::views::all(pic_key_filename_map)))
        {
            std::string variable_name = std::format(map.variable_format, this_id);
            if (opt_filename) {
                std::println(full_file, R"(
#if __has_embed("{}") == __STDC_EMBED_FOUND__
constexpr std::array {} = std::to_array<std::uint8_t>({{
    #embed "{}"
}});
#else
constexpr std::array<std::uint8_t, 0> {};
#endif
)",
                             *opt_filename, variable_name, *opt_filename, variable_name);
            } else {
                std::println(full_file, "constexpr std::array<std::uint8_t, 0> {};\n", variable_name);
            }
        }

        const json pic = event["mainPicture"];
        std::println(full_file, R"(constexpr release_event_picture event_picture_{0} = {{ "{1}", {2}, {3}, {4}, {5}, {6}, {7}, {8}, {9}, {10}  }};
)",
                     /*0*/this_id,
                     /*1*/pic["mime"].get<std::string_view>(),
                     /*2*/as_opt(pic, "name"),
                     /*3*/as_opt(pic, pic_key_filename_map[0].key),
                     /*4*/std::format(pic_key_filename_map[0].variable_format, this_id),
                     /*5*/as_opt(pic, pic_key_filename_map[1].key),
                     /*6*/std::format(pic_key_filename_map[1].variable_format, this_id),
                     /*7*/as_opt(pic, pic_key_filename_map[2].key),
                     /*8*/std::format(pic_key_filename_map[2].variable_format, this_id),
                     /*9*/as_opt(pic, pic_key_filename_map[3].key),
                     /*10*/std::format(pic_key_filename_map[3].variable_format, this_id));
    }
    return {};
}


std::expected<std::vector<std::optional<std::string>>, std::error_code>
scraper::fetch_event_embeds(const json& event)
{
    if (!event.contains("mainPicture")) return {};
    const auto pics = event["mainPicture"];
    if (!pics.contains("mime")) return {};
    const auto mime = pics["mime"].get<std::string_view>();
    const auto suffix = mime.substr(mime.find('/') + 1);
    std::vector<std::optional<std::string>> downloaded_filenames;

    for (const auto& pic : pic_key_filename_map) {
        if (pics.contains(pic.key)) {
            cpr::Url url { sanitize_url(pics[pic.key].template get<std::string>()) };
            const auto filename = std::format(pic.filename_format, event["id"].get<std::uint64_t>(), suffix);
            const auto path = res_dir / filename;
            const auto tmppath = std::filesystem::path{path}.replace_extension(std::format("{}.tmp", path.extension().string()));
            const auto last_modified = std::chrono::clock_cast<std::chrono::system_clock>(std::filesystem::exists(path) ? std::filesystem::last_write_time(path) : std::filesystem::file_time_type::min());
            if ((std::chrono::system_clock::now() - last_modified) < std::chrono::days{30}) {
                downloaded_filenames.push_back(filename);
                continue;
            }
            const auto zt = std::chrono::zoned_time{"UTC", last_modified};
            cpr::Header hdrs {{ "If-Modified-Since", std::format("{:%a, %d %b %Y %H:%M:%S} GMT", zt) }};
            session.SetHeader(hdrs);
            std::ofstream ofs {tmppath, std::ios::binary | std::ios::out };
            auto res = download(url, ofs);
            if (!res) {
                if (res.error() == songbot_error::http_error_404) {
                    downloaded_filenames.push_back(std::nullopt);
                    ofs.close();
                    std::filesystem::remove(tmppath);
                    if (std::filesystem::exists(path)) {
                        if (0uz == std::filesystem::file_size(path)) {
                            std::filesystem::last_write_time(path, std::chrono::clock_cast<std::chrono::file_clock>(std::chrono::system_clock::now()));
                        } else {
                            std::println("Info: {} was fetched before but returned 404 today", filename);
                        }
                    } else {
                        std::ofstream emptyfile {path};
                    }
                    continue;
                } else {
                    return std::unexpected(res.error());
                }
            }
            if (res->status_code == 304) {
                std::println("Info: {} has no change", filename);
                ofs.close();
                std::filesystem::remove(tmppath);
                std::filesystem::last_write_time(path, std::chrono::clock_cast<std::chrono::file_clock>(std::chrono::system_clock::now()));

            } else {
                ofs.flush();
                ftruncate(ofs.rdbuf()->native_handle(), ofs.tellp());
                std::println("Info: {} written (tmp), size {}", filename, static_cast<std::streamoff>(ofs.tellp()));
                ofs.close();
                std::filesystem::rename(tmppath, path);
            }
            downloaded_filenames.push_back(filename);
        } else {
            downloaded_filenames.push_back(std::nullopt);
        }
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
            return std::unexpected(songbot_error::http_error_404);
        }
        if (res.status_code >= 400) {
            std::println(std::cerr, "Error: {}", res.status_code);
            std::println(std::cerr, "Body: {}", res.text);
            return std::unexpected(songbot_error::http_error_400);
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
            return std::unexpected(songbot_error::http_error_404);
        }
        if (res.status_code >= 400) {
            std::println(std::cerr, "Error: {}", res.status_code);
            std::println(std::cerr, "Body: {}", res.text);
            return std::unexpected(songbot_error::http_error_400);
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
