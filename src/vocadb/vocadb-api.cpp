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

import nlohmann.json;
using json = nlohmann::json;

#include "vocadb-api.hpp"

namespace vocadb
{

scraper::scraper(std::filesystem::path res_dir) noexcept :
    res_dir(std::move(res_dir))
{
    session.SetHeader(cpr::Header{{"User-Agent", "github/talisein/songbot"},
                                  {"accept", "application/json"}});
}

std::expected<void, std::error_code>
scraper::scrape_events(const std::filesystem::path& generated_src)
{
//    cpr::Response r = cpr::Get(cpr::Url{"https://api.github.com/repos/whoshuu/cpr/contributors"},
//                      cpr::Authentication{"user", "pass", cpr::AuthMode::BASIC},
//                      cpr::Parameters{{"anon", "true"}, {"key", "value"}});
//    r.status_code;                  // 200
//    r.header["content-type"];       // application/json; charset=utf-8
//    r.text;                         // JSON text string

    for (auto concert : std::views::all(concerts)
             | std::views::filter([](const auto& c) { return c.vocadb_event_id.has_value(); })
             | std::views::take(1))
    {
        cpr::Url url{std::format(release_events_url, concert.vocadb_event_id.value())};
        cpr::Parameters params{{"fields", "AdditionalNames,Description,MainPicture,Names,Series,SongList,Venue,WebLinks"},
                               {"lang", "English"}};

        auto res = get(url, params);
        if (res && res->status_code == 200) {
            auto e = json::parse(res->text);
            std::println("{}", e.dump(2));

        }
    }
    return {};
}

std::expected<cpr::Response, std::error_code>
scraper::get(const cpr::Url& url, const cpr::Parameters& params)
{
    try {
        session.SetUrl(url);
        session.SetParameters(params);
        auto res = session.Get();
//        std::this_thread::sleep_for(2000ms);
        return res;
    } catch (std::system_error& e) {
        return std::unexpected(e.code());
    }
}


}
