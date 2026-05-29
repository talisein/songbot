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

static bool icontains(std::string_view haystack, std::string_view needle)
{
    return std::search(
        haystack.begin(), haystack.end(),
        needle.begin(), needle.end(),
        [](unsigned char a, unsigned char b) { return std::tolower(a) == std::tolower(b); }
    ) != haystack.end();
}

static std::vector<Song> search_songs(std::string_view term)
{
    std::vector<Song> results;
    for (const auto& s : songs) {
        if (icontains(s.name, term) ||
            (s.romanji_name && icontains(*s.romanji_name, term)) ||
            (s.jp_name && icontains(*s.jp_name, term)))
            results.push_back(s);
    }
    return results;
}

int main(int argc, char* argv[])
{
    const std::string filepath = argc > 1 ? argv[1] : "../src/project_sekai_tracks.cppm";

    std::vector<std::pair<std::string, std::string>> replacements;
    std::set<std::string> seen_wikis;
    bool quit = false;

    for (const auto& track : sekai_tracks) {
        if (quit) break;
        std::string wiki{track.song};

        if (!seen_wikis.insert(wiki).second) continue;
        if (std::ranges::any_of(songs, [&](const Song& s) { return s.name == track.song; })) continue;

        std::print(std::cerr, "Sekai: \"{}\"\n", wiki);

        while (true) {
            std::print(std::cerr, "Search (- to skip): ");
            std::string term;
            if (!std::getline(std::cin, term)) { quit = true; break; }
            if (term == "-") break;
            if (term == "q") { quit = true; break; }

            std::optional<Song> unique = lookup_song(term);
            if (!unique) {
                auto hits = search_songs(term);
                if (hits.empty()) {
                    std::print(std::cerr, "No matches.\n");
                    continue;
                }
                if (hits.size() > 1) {
                    for (const auto& s : hits)
                        std::print(std::cerr, "  {}\n", s);
                    continue;
                }
                unique = hits[0];
            }

            std::print(std::cerr, "{}\n", *unique);
            std::print(std::cerr, "Accept? [y/n]: ");
            std::string ans;
            if (!std::getline(std::cin, ans)) { quit = true; break; }
            char ac = ans.empty() ? '\0' : std::tolower((unsigned char)ans[0]);
            if (ac == 'q') { quit = true; break; }
            if (ac == '-') break;
            if (ac == 'y') {
                replacements.emplace_back(wiki, std::string(unique->name));
                break;
            }
        }
        std::print(std::cerr, "\n");
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

    auto patched = orig;

    /* Apply name replacements for accepted matches, stripping any existing // miss */
    for (const auto& [old_name, new_name] : replacements) {
        std::string pat = std::format("\"{}\"", old_name);
        std::string rep = std::format("\"{}\"", new_name);
        for (auto& line : patched) {
            if (auto pos = line.find(pat); pos != std::string::npos) {
                line.replace(pos, pat.size(), rep);
                if (auto miss_pos = line.find(" // miss"); miss_pos != std::string::npos)
                    line.erase(miss_pos);
            }
        }
    }

    /* Unified diff */
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
