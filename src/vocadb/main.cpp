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

#include "scraper.hpp"
#include "config.h"

int main(int argc, char *argv[])
{
    scraper scraper { RES_DIR } ;
    const std::filesystem::path gen_dir { GEN_DIR };
    if (auto scrape_result = scraper.scrape_events(gen_dir / "release_events.cppm"); !scrape_result) return 1;
    if (auto scrape_result = scraper.scrape_songs(gen_dir / "vocadb_songs.cppm"); !scrape_result) return 1;
    if (auto scrape_result = scraper.scrape_localvoid(gen_dir / "localvoid_charts.cppm"); !scrape_result) return 1;
    return 0;
}
