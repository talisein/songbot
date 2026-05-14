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

export module concerts:types;

import std;
import util;
import magic_enum;

using namespace std::literals;

export enum ConcertSeries
{
    MIKUFES,
    MIKUSGIVINGS_DAY,
    MIKUNOPOLIS,
    MIKU_EXPO, // 82
    MAGICAL_MIRAI, // 81
    SNOW_MIKU, // 204
    MIKUPA, // EventSeries 219
    MIKU_WITH_YOU, // 173
    JAPAN_TOUR,
    KODO, // 255
    ANNIVERSARY,
    NICONICO,
    GALAXY,
    NO_SERIES,
};

export enum ConcertTour
{
    MIKUFES09,
    SANKYUGD,
    MP2011Tokyo,
    Mikunopolis,
    MP2011Sapporo,
    MP2011SG,
    MP2012Tokyo,
    SANKYUGDF,
    MP2012HKTW,
    MP2013Sapporo,
    MP2013Kansai,
    MM2013,
    ME2014IN,
    MM2014,
    ME2014LANY,
    SM2015,
    ME2015,
    MM2015,
    ME2016JP,
    ME2016NA,
    ME2016TW,
    MM2016,
    ME2016CN,
    KODO2017,
    MM2017,
    MWY2017,
    ME2017MY,
    SM2018,
    KODO2018,
    ME2018NA,
    MM2018,
    MWY2018,
    ME2018EU,
    SM2019,
    ME2019TWHK,
    MM2019,
    MWY2019,
    ME2020EU,
    ZERO,
    MM2020,
    MWY2020,
    ME2021,
    MM2021,
    MWY2021,
    MEREWIND,
    MM2022,
    MEREWINDPLUS,
    MM10Sapporo,
    Thunderbolt,
    KODO2023,
    MM2023,
    ME2023VR,
    MIKUFES24,
    ME2024NA,
    MWY2024,
    MM2024,
    ME2024EU,
    ME2024NZAU,
    Blooming,
    MM2025,
    KAGA14,
    MK15,
    ME2025,
    GALAXY2020,
    GALAXY2021,
    MWY2025,
    LAWSON,
    DECO,
    VOLTAGE,
    ME2026NA,
    MM2026,
    ME2026EU
};

export constexpr std::string_view
tour_to_string(ConcertTour tour)
{
//    return magic_enum::enum_name(tour);
    using namespace std::literals;
    return magic_enum::enum_switch([] (auto val) -> std::string_view{
        constexpr ConcertTour tour = val;
        switch (tour) {
            case MIKUFES09:     return "MikuFES09"sv;
            case MIKUFES24:     return "MikuFES24"sv;
            case SANKYUGD:      return "39GD"sv;
            case SANKYUGDF:     return "F39GD"sv;
/*          case MP2011Tokyo:   return "MikuPa 2011 Tokyo"sv;
            case MP2011Sapporo: return "MikuPa 2011 Sapporo"sv;
            case MP2011SG:      return "MikuPa 2011 Singapore"sv;
            case MP2012Tokyo:   return "MikuPa 2012 Tokyo"sv;
            case MP2012HKTW:    return "MikuPa 2012 HKTW"sv;
            case MP2013Sapporo: return "MikuPa 2013 Sapporo"sv;
            case MP2013Kansai:  return "MikuPa 2013 Kansai"sv;*/
            case MM2022:        return "MM10th"sv;
            case MM10Sapporo:   return "MM10th Sapporo"sv;
            case KAGA14:        return "Kagamine 14th"sv;
            case ZERO:          return "Untitled 0"sv;
            case GALAXY2020:    return "Galaxy 2020"sv;
            case GALAXY2021:    return "Galaxy 2021"sv;
            case MEREWIND:      return "MERewind"sv;
            case MEREWINDPLUS:  return "MERewind+"sv;
            default:
                return magic_enum::enum_name(tour);
        }
        }, tour, std::string_view());
}

export constexpr std::optional<ConcertTour>
tour_from_string(std::string_view tour)
{
    auto needle = util::to_nfkc_casefold(tour);
    constexpr auto tours = magic_enum::enum_values<ConcertTour>();
    auto it = std::ranges::find(tours,
                                needle,
                                [](ConcertTour tour) constexpr { return util::to_nfkc_casefold(tour_to_string(tour)); });
    if (it != std::ranges::end(tours))
        return *it;
    return std::nullopt;
}

export struct Concert
{
    ConcertSeries series;
    std::string_view name;
    ConcertTour short_name;
    std::chrono::year_month_day date; // first day in series
    std::optional<std::chrono::year_month_day> last_date;
    std::optional<std::uint64_t> vocadb_event_id; // "ReleaseEvent"
};

export struct live_event
{
    ConcertTour tour;
    std::uint64_t vocadb_id;
    std::chrono::zoned_seconds start_time;
    std::string_view location_name;
    std::string_view location_link;
};

export struct SetlistTrack
{
    ConcertTour concert_short_name;
    int pos;
    std::string_view song;
    std::optional<std::string_view> producer;
    std::optional<std::string_view> variant; // E.g. setlist A, setlist B.
    std::optional<std::string_view> remix; // E.g. -Reloaded-
    std::optional<std::uint64_t> remix_id; // vocadb id for reloaded
    std::optional<std::string_view> emoji_override; // Darkness
};

export struct song_frequency
{
    std::string_view song_name;
    std::optional<std::string_view> producer;
    size_t count;
};
