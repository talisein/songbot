/*
    Songbot: Hatsune Miku Concert Database for Discord
    Copyright (C) 2026  Andrew Potter

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

#include "export_json.hpp"

/* Writes the published JSON datasets (see site/static/index.html) into the
 * given directory, creating it if needed. */
int main(int argc, char** argv)
{
    if (argc != 2) {
        std::println(std::cerr, "usage: {} <outdir>", argv[0]);
        return 2;
    }
    const std::filesystem::path outdir{argv[1]};
    std::filesystem::create_directories(outdir);

    for (const auto& f : export_json::export_all()) {
        const auto path = outdir / f.name;
        std::ofstream out{path, std::ios::binary};
        out << f.contents;
        if (!out.flush()) {
            std::println(std::cerr, "failed to write {}", path.string());
            return 1;
        }
        std::println("wrote {} ({} bytes)", path.string(), f.contents.size());
    }
    return 0;
}
