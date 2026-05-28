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
import songs;
import project_sekai;

int main(int argc, char* argv[])
{
    const std::string filepath = argc > 1 ? argv[1] : "../src/project_sekai_tracks.cppm";

    /* Build set of song names with no exact English match in the songs DB */
    std::set<std::string> misses;
    for (const auto& track : sekai_tracks) {
        std::string_view wiki = track.song;
        if (!std::ranges::any_of(songs, [wiki](const Song& s) { return s.name == wiki; }))
            misses.insert(std::string(wiki));
    }

    /* Read source file */
    std::ifstream f(filepath);
    if (!f) {
        std::print(std::cerr, "Cannot open {}\n", filepath);
        return 1;
    }
    std::vector<std::string> orig;
    for (std::string line; std::getline(f, line); )
        orig.push_back(std::move(line));

    /* Annotate each miss line */
    auto patched = orig;
    for (const auto& miss : misses) {
        std::string pat = std::format("\"{}\"", miss);
        for (auto& line : patched)
            if (line.find(pat) != std::string::npos)
                line += " // miss";
    }

    /* Emit unified diff to stdout */
    constexpr int CTX = 3;

    std::vector<int> changed;
    for (int i = 0; i < (int)orig.size(); ++i)
        if (orig[i] != patched[i]) changed.push_back(i);

    struct Hunk { int lo, hi; };
    std::vector<Hunk> hunks;
    for (int idx : changed) {
        int lo = std::max(0, idx - CTX);
        int hi = std::min((int)orig.size(), idx + CTX + 1);
        if (!hunks.empty() && lo <= hunks.back().hi)
            hunks.back().hi = hi;
        else
            hunks.push_back({lo, hi});
    }

    std::print("--- a/src/project_sekai_tracks.cppm\n+++ b/src/project_sekai_tracks.cppm\n");
    for (const auto& [lo, hi] : hunks) {
        std::print("@@ -{},{} +{},{} @@\n", lo + 1, hi - lo, lo + 1, hi - lo);
        for (int i = lo; i < hi; ++i) {
            if (orig[i] != patched[i]) {
                std::print("-{}\n", orig[i]);
                std::print("+{}\n", patched[i]);
            } else {
                std::print(" {}\n", orig[i]);
            }
        }
    }

    return 0;
}
