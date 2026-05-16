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

export module project_diva:tracks;

import :types;
import std;
import songs;
import songbot.errors;

using std::nullopt;
export constexpr std::array diva_tracks = std::to_array<GameTrack>({
    /* Base game */
    { DIVA, "World is Mine" },
    { DIVA, "Jaded" },
    { DIVA, "Love is War" },
    { DIVA, "That One Second in Slow Motion" },
    { DIVA, "Melt" },
    { DIVA, "Far Away" },
    { DIVA, "Strobe Nights" },
    { DIVA, "Star Story", nullopt, nullopt, "Star Story (GAME edit)", 2951 },
    { DIVA, "Last Night, Good Night" },
    { DIVA, "Packaged" },
    { DIVA, "Sweet*Drops After the Rain" },
    { DIVA, "Miracle Paint" },
    { DIVA, "Bad Mood Waltz" },
    { DIVA, "Marginal" },
    { DIVA, "Dreaming Leaf -Dreaming Words-" },
    { DIVA, "Song of Wastelands, Forests, and Magic" },
//    { DIVA, "Song of Wastelands, Forests, and Magic (Len ver.)" },
//    { DIVA, "Song of Wastelands, Forests, and Magic (Rin ver.)" },
    { DIVA, "White Dove" },
    { DIVA, "moon" },
    { DIVA, "Beware of the Miku Miku Germs♪" },
    { DIVA, "Song of Life" },
//    { DIVA, "Song of Life (Len ver.)" },
//    { DIVA, "Song of Life (Rin ver.)" },
    { DIVA, "The secret garden" },
    { DIVA, "Dear cocoa girls" },
    { DIVA, "Velvet Arabesque" },
    { DIVA, "Updating My Love List?" },
    { DIVA, "Sakura Rain", nullopt, nullopt, "Rain of Cherry Blossoms -standard edit-", 26817 },
    { DIVA, "VOC@LOID in Love" },
    { DIVA, "Ievan Polkka" },
    { DIVA, "Your Diva" },
    { DIVA, "Electric Angel" },
    { DIVA, "The Disappearance of Hatsune Miku -DEAD END-" },
    { DIVA, "Golden Holy Night Rotting into the Frost and Snow", nullopt, nullopt, "Requiem for the Phantasma [25,Dec]", 2923 },
    { DIVA, "I'll Miku-Miku You♪ (For Reals)" },
    /* DLC 1: Miku Uta, Okawari */
    { DIVA, "Though My Song Has No Shape" },
    { DIVA, "celluloid" },
    { DIVA, "1/6 -out of the gravity-" },
    { DIVA, "Two-Sided Lovers" },
    { DIVA, "Two Breaths Walking" },
    { DIVA, "Puzzle" },
    { DIVA, "SPiCa" },
    { DIVA, "Alice", nullopt, nullopt, "Alice -DIVA mix", 620276 },
    { DIVA, "*Hello, Planet.", nullopt, nullopt, "*Hello, Planet. (I.M.PLSE-EDIT)", 260433 },
    /* DLC 2: Motto Okawari, Rin, Len, Luka */
    { DIVA, "RING×RING×RING" },
    { DIVA, "I Like You, I Love You" },
    { DIVA, "MobiRe SenS@tion", nullopt, nullopt, "MobiRe SenS@tion (C.A.LLME-EDIT)", 597987 },
    { DIVA, "Self-Hatred" },
    { DIVA, "Transmit" },
    { DIVA, "Why Don't You Call Me Yet?" },
    { DIVA, "To Beyond a Duodecillion", nullopt, nullopt, "To Beyond A Duodecillion (PD Ver)", 13237 },
    { DIVA, "I'll Outrun You For Good♪" },
    { DIVA, "Sandscraper -Desert Express Line-" },
    { DIVA, "RIP=RELEASE" },
    { DIVA, "Palette" },
    { DIVA, "Wanderlast", nullopt, nullopt, "Wanderlast (A.R.MAGE-EDIT)", 597983 },
    { DIVA, "A Single Red Leaf" },
    { DIVA, "Itinerating Diva's Dance Music" },
    { DIVA, "philosophy -Another-" },
    { DIVA, "Luka Luka★Night Fever" },
    { DIVA, "No Logic" },
    { DIVA, "Toeto" },
    /* Background songs */
//    { DIVA, "Miku Room" },
    { DIVA, "I'm Going to Do the Rin Rin Rin" },
    { DIVA, "Cool Love Song" },
    { DIVA, "Double Lariat" },
    { DIVA, "Thousand Year Solo" },
    { DIVA, "Lover's Suicide Oblivion" },
    { DIVA, "Soar" },
    { DIVA, "The Farthest Ends" },
    { DIVA, "ＳＥＴＳＵＮＡ" },
    { DIVA, "Sunset Nostalgic -remix-" },
    { DIVA, "Love it!", nullopt, nullopt, "Love it! -Radio Edit-", 75300  },
    { DIVA, "Can You Hear Me?" },
    { DIVA, "Shooting Star Prologue" },
    { DIVA, "Tell Me!! The Magical Lyric" },
    { DIVA, "starise" },
  });

export std::expected<Song, std::error_code>
find_song_for_track(const GameTrack& track)
{
    auto matches = songs | std::views::filter([&](const Song& s) { return song_matches_track(s, track); });

    auto it = std::ranges::begin(matches);
    if (it == std::ranges::end(matches))
        return std::unexpected(make_error_code(songbot_error::no_match));
    Song first = *it;
    ++it;
    if (!track.producer && it != std::ranges::end(matches))
        return std::unexpected(make_error_code(songbot_error::multiple_matches));
    return first;
}

export bool song_is_game_track(const Song& song)
{
    return std::ranges::any_of(diva_tracks, [&](const GameTrack& t) { return song_matches_track(song, t); });
}

export std::vector<DivaGames> get_song_games(const Song& song)
{
    std::vector<DivaGames> result;
    for (const auto& track : diva_tracks) {
        if (song_matches_track(song, track) && !std::ranges::contains(result, track.game)) {
            result.push_back(track.game);
        }
    }
    return result;
}

constexpr auto game_song_exists = [](const GameTrack& track) constexpr {
    return std::ranges::any_of(songs, [&](const Song& s) { return song_matches_track(s, track); });
};

static_assert(std::ranges::all_of(diva_tracks, game_song_exists),
              std::ranges::find_if_not(diva_tracks, game_song_exists)->song);
