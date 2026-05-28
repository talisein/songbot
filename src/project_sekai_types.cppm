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

export module project_sekai:types;

import std;
import util;
import magic_enum;
import songs;

using namespace std::literals;

export enum SekaiUnit
{
  VSG,
  LEO,
  MMJ,
  VBS,
  WxS,
  N25,
  OTHER
};

export struct SekaiTrack
{
  using sv = std::string_view;
  using osv = std::optional<std::string_view>;
  using osi = std::optional<std::uint64_t>;

  constexpr SekaiTrack(osi id, SekaiUnit unit, sv song,
                       osv producer = std::nullopt,
                       osv remix = std::nullopt,
                       osi remix_id = std::nullopt) noexcept :
    id(id),
    unit(unit),
    song(song),
    producer(producer),
    remix(remix),
    remix_id(remix_id)
  {
  }

  osi id;
  SekaiUnit unit;
  sv song;
  osv producer;
  osv remix;
  osi remix_id;
};
