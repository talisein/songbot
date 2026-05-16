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

export module project_diva:types;

import std;
import util;
import magic_enum;
import songs;

using namespace std::literals;

export enum DivaGames
{
  DIVA,
  DIVA_ARCADE,
  DIVA_2ND,
  DIVA_EXTEND,
  DIVA_F,
  DIVA_FT,
  DIVA_MEGA39,
  DIVA_F2,
  DIVA_X,
  MIRAI,
  MIRAI_2,
  MIRAI_DX,
};

export struct GameTrack
{
  using sv = std::string_view;
  using osv = std::optional<std::string_view>;
  using osi = std::optional<std::uint64_t>;

  constexpr GameTrack(DivaGames game,
                      sv song,
                      osv producer = std::nullopt,
                      osv variant = std::nullopt,
                      osv remix = std::nullopt,
                      osi remix_id = std::nullopt,
                      osv emoji_override = std::nullopt) noexcept :
    game(game),
    song(song),
    producer(producer),
    variant(variant),
    remix(remix),
    remix_id(remix_id),
    emoji_override(emoji_override)
  {
  }

  DivaGames game;
  std::string_view song;
  std::optional<std::string_view> producer;
  std::optional<std::string_view> variant; // E.g. setlist A, setlist B.
  std::optional<std::string_view> remix; // E.g. -Reloaded-
  std::optional<std::uint64_t> remix_id; // vocadb id for reloaded
  std::optional<std::string_view> emoji_override; // Darkness
};

export constexpr std::string_view diva_game_short_name(DivaGames g) noexcept
{
    switch (g) {
        case DIVA:        return "PD1";
        case DIVA_ARCADE: return "PDA";
        case DIVA_2ND:    return "PD2";
        case DIVA_EXTEND: return "PDEX";
        case DIVA_F:      return "PDF";
        case DIVA_FT:     return "PDFT";
        case DIVA_MEGA39: return "PDM39";
        case DIVA_F2:     return "PDF2";
        case DIVA_X:      return "PDX";
        case MIRAI:       return "PM";
        case MIRAI_2:     return "PM2";
        case MIRAI_DX:    return "PMDX";
        default:          return magic_enum::enum_name(g);
    }
}

constexpr bool song_matches_track(const Song& s, const GameTrack& track)
{
    return s.name == track.song &&
           track.producer.transform([&](const auto& p) { return s.producer == p; }).value_or(true);
}
