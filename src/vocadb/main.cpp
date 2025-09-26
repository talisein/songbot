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

import std;
import cpr;

#include "vocadb-api.hpp"

int main(int argc, char *argv[])
{
    cpr::Session session;
    session.SetHeader(cpr::Header{{"User-Agent", "github/talisein/songbot"}});
    vocadb::scraper scraper { "../../../res/" } ;

    auto res = scraper.scrape_events("gen/release_events.cppm");

    return 0;
}
