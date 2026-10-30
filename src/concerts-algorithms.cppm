export module concerts:algorithms;

import :types;
import :raw_data;
import :data;
import std;
import songs;
import songbot.errors;
import util;
import uni_algo;
import magic_enum;

using namespace std::literals;

static_assert(std::ranges::is_sorted(concerts, {}, &Concert::date),
              magic_enum::enum_name(std::ranges::is_sorted_until(concerts, {}, &Concert::date)->short_name));

export [[nodiscard]] constexpr
std::optional<Concert> lookup_concert(ConcertTour tour)
{
    auto it = std::ranges::find(concerts, tour, &Concert::short_name);
    if (it == std::ranges::end(concerts)) return std::nullopt;
    return *it;
}

export [[nodiscard]] constexpr
std::optional<Concert> lookup_concert(std::string_view tour)
{
    auto t = tour_from_string(tour);
    if (!t) return std::nullopt;
    return lookup_concert(*t);
}

export [[nodiscard]]
std::vector<Concert> match_concerts(std::string_view needle)
{
    const auto name_matches_needle = [needle = util::to_nfkc_casefold(needle)]
        (const Concert& concert) constexpr {
        return std::ranges::contains_subrange(util::to_nfkc_casefold(tour_to_string(concert.short_name)), needle) ||
               std::ranges::contains_subrange(util::to_nfkc_casefold(concert.name), needle);
    };
    return concerts | std::views::filter(name_matches_needle) | std::ranges::to<std::vector>();
}

export consteval
const Concert& operator ""_live(const char* short_name, std::size_t len)
{
    return *lookup_concert({short_name, len});
}

export constexpr size_t get_song_frequency_rank(std::string_view song_name)
{
    auto rng = song_frequencies | std::views::enumerate;
    auto it = std::ranges::find(rng, song_name,
                                [&](const auto& tuple) { return std::get<1>(tuple).song_name; });
    if (it == std::ranges::end(rng)) {
        return songs.size();
    } else {
        return std::get<0>(*it) + 1;
    }
}

export constexpr size_t get_song_frequency(std::string_view song_name)
{
    auto rng = song_frequencies;
    auto it = std::ranges::find(rng, song_name, &song_frequency::song_name);
    if (it == std::ranges::end(rng)) {
        return 0;
    } else {
        return it->count;
    }
}

constexpr bool song_matches_track(const Song& s, const SetlistTrack& track)
{
    return s.name == track.song &&
           track.producer.transform([&](const auto& p) { return s.producer == p; }).value_or(true);
}

export std::expected<Song, std::error_code>
find_song_for_track(const SetlistTrack& track)
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

export bool song_is_concert_track(const Song& song)
{
    auto [first, last] = std::ranges::equal_range(setlists_by_song, song.name, {}, &SetlistTrack::song);
    return std::ranges::any_of(first, last, [&](const SetlistTrack& t) { return song_matches_track(song, t); });
}

/* Check that all concerts are ordered chronologically */
constexpr auto get_track_date = [](const auto& track) constexpr {
    return std::ranges::find_if(concerts, [&track](const auto &concert) constexpr {
        return concert.short_name == track.concert_short_name;
    })->date;
};
static_assert(std::ranges::is_sorted(setlists, {}, get_track_date),
              magic_enum::enum_name(std::ranges::is_sorted_until(setlists, {}, get_track_date)->concert_short_name));

/* Check that every concert has a setlist defined */
constexpr auto concert_has_setlist = [](const auto &concert) constexpr {
    return std::ranges::contains(setlists, concert.short_name, &SetlistTrack::concert_short_name) || concert.date >= util::get_build_date();
};

static_assert(std::ranges::all_of(concerts, concert_has_setlist),
              magic_enum::enum_name(std::ranges::find_if_not(concerts, concert_has_setlist)->short_name));

export [[nodiscard]]
auto get_setlist(auto short_name)
{
    auto concert = lookup_concert(short_name);
    if (!concert) return std::vector<SetlistTrack>();
    return std::views::all(setlists)
           | std::views::filter([&](const auto &track) { return track.concert_short_name == concert->short_name; })
           | std::ranges::to<std::vector>();
}

export std::span<const SetlistTrack> get_setlists() { return setlists; }
export std::span<const Concert> get_concerts() { return concerts; }

namespace {
  named_zone JST;
  named_zone VANCOUVER_TZ;
  named_zone PST;
  named_zone PHOENIX_TZ;
  named_zone MST;
  named_zone DENVER_TZ;
  named_zone CST;
  named_zone EST;
  named_zone DETROIT_TZ;
  named_zone TORONTO_TZ;
  named_zone MEXICO_CITY_TZ;
  named_zone AUCKLAND_TZ;
  named_zone BRISBANE_TZ;
  named_zone SYDNEY_TZ;
  named_zone MELBOURNE_TZ;
  named_zone PERTH_TZ;
  named_zone BANGKOK_TZ;
  named_zone HONGKONG_TZ;
  named_zone JAKARTA_TZ;
  named_zone MANILA_TZ;
  named_zone SINGAPORE_TZ;
  named_zone KUALALUMPUR_TZ;
  named_zone TAIPEI_TZ;
  named_zone SEOUL_TZ;
  named_zone SHANGHAI_TZ;
  named_zone CHICAGO_TZ;
  named_zone LONDON_TZ;
  named_zone BRUSSELS_TZ;
  named_zone AMSTERDAM_TZ;
  named_zone BERLIN_TZ;
  named_zone DUSSELDORF_TZ;
  named_zone PARIS_TZ;
  named_zone MADRID_TZ;

  std::once_flag live_events_init_flag;
  std::vector<live_event> live_events_storage;

  named_zone locate(std::string_view name)
  {
    return { std::chrono::locate_zone(name), name };
  }

  void init_live_events()
  {
    try {
      JST            = locate("Asia/Tokyo");
      VANCOUVER_TZ   = locate("America/Vancouver");
      PST            = locate("America/Los_Angeles");
      PHOENIX_TZ     = locate("America/Phoenix");
      MST            = locate("America/Denver");
      DENVER_TZ      = locate("America/Denver");
      CST            = locate("America/Chicago");
      EST            = locate("America/New_York");
      DETROIT_TZ     = locate("America/Detroit");
      TORONTO_TZ     = locate("America/Toronto");
      MEXICO_CITY_TZ = locate("America/Mexico_City");
      AUCKLAND_TZ    = locate("Pacific/Auckland");
      BRISBANE_TZ    = locate("Australia/Brisbane");
      SYDNEY_TZ      = locate("Australia/Sydney");
      MELBOURNE_TZ   = locate("Australia/Melbourne");
      PERTH_TZ       = locate("Australia/Perth");
      BANGKOK_TZ     = locate("Asia/Bangkok");
      HONGKONG_TZ    = locate("Asia/Hong_Kong");
      JAKARTA_TZ     = locate("Asia/Jakarta");
      MANILA_TZ      = locate("Asia/Manila");
      SINGAPORE_TZ   = locate("Asia/Singapore");
      KUALALUMPUR_TZ = locate("Asia/Kuala_Lumpur");
      TAIPEI_TZ      = locate("Asia/Taipei");
      SEOUL_TZ       = locate("Asia/Seoul");
      SHANGHAI_TZ    = locate("Asia/Shanghai");
      CHICAGO_TZ     = locate("America/Chicago");
      LONDON_TZ      = locate("Europe/London");
      BRUSSELS_TZ    = locate("Europe/Brussels");
      AMSTERDAM_TZ   = locate("Europe/Amsterdam");
      BERLIN_TZ      = locate("Europe/Berlin");
      DUSSELDORF_TZ  = locate("Europe/Berlin");
      PARIS_TZ       = locate("Europe/Paris");
      MADRID_TZ      = locate("Europe/Madrid");
    } catch (std::runtime_error &e) {
      std::println(std::cerr, "Failed to load required timezones. This is likely due to an incompatibility between the latest tzdb 20204b and GCC 14s stdlib, see bug 116657.\nSpecific error: {}\nTerminating", e.what());
      exit(1);
    }
    using namespace std::literals;
    using std::chrono::local_days;
    live_events_storage = {
      { VOLTAGE,  9613,  { JST,            local_days{2026y/3/20}  + 12h }, "LaLa arena TOKYO-BAY",                    "Funabashi",    "https://maps.app.goo.gl/xFEqpXcYepPaVM237" },
      { VOLTAGE,  9613,  { JST,            local_days{2026y/3/20}  + 18h }, "LaLa arena TOKYO-BAY",                    "Funabashi",    "https://maps.app.goo.gl/xFEqpXcYepPaVM237" },
      { VOLTAGE,  9613,  { JST,            local_days{2026y/3/21}  + 12h }, "LaLa arena TOKYO-BAY",                    "Funabashi",    "https://maps.app.goo.gl/xFEqpXcYepPaVM237" },
      { VOLTAGE,  9613,  { JST,            local_days{2026y/3/21}  + 18h }, "LaLa arena TOKYO-BAY",                    "Funabashi",    "https://maps.app.goo.gl/xFEqpXcYepPaVM237" },
      { VOLTAGE,  9613,  { JST,            local_days{2026y/3/22}  + 12h }, "LaLa arena TOKYO-BAY",                    "Funabashi",    "https://maps.app.goo.gl/xFEqpXcYepPaVM237" },
      { VOLTAGE,  9613,  { JST,            local_days{2026y/3/22}  + 18h }, "LaLa arena TOKYO-BAY",                    "Funabashi",    "https://maps.app.goo.gl/xFEqpXcYepPaVM237" },
      { ME2026NA, 9811,  { CHICAGO_TZ,     local_days{2026y/4/12}  + 20h }, "The Auditorium",                          "Chicago",      "https://maps.app.goo.gl/P28CZKX5aN67CzDd6" },
      { ME2026NA, 9811,  { CHICAGO_TZ,     local_days{2026y/4/13}  + 20h }, "The Auditorium",                          "Chicago",      "https://maps.app.goo.gl/P28CZKX5aN67CzDd6" },
      { ME2026NA, 9812,  { DENVER_TZ,      local_days{2026y/4/15}  + 20h }, "Mission Ballroom",                        "Denver",       "https://maps.app.goo.gl/B4yZexmBzc517P3F7" },
      { ME2026NA, 9813,  { VANCOUVER_TZ,   local_days{2026y/4/18}  + 20h }, "Doug Mitchell Thunderbird Sports Centre", "Vancouver",    "https://maps.app.goo.gl/qKD91YFLbUkc9V559" },
      { ME2026NA, 9814,  { PST,            local_days{2026y/4/20}  + 20h }, "WAMU Theater",                            "Seattle",      "https://maps.app.goo.gl/bym2QCvo9JBZgukw6" },
      { ME2026NA, 9815,  { PST,            local_days{2026y/4/22}  + 20h }, "San Jose Civic",                          "San Jose",     "https://maps.app.goo.gl/qPuR3TnKVfSKQbYt5" },
      { ME2026NA, 9815,  { PST,            local_days{2026y/4/23}  + 20h }, "San Jose Civic",                          "San Jose",     "https://maps.app.goo.gl/qPuR3TnKVfSKQbYt5" },
      { ME2026NA, 9816,  { PST,            local_days{2026y/4/25}  + 20h }, "Peacock Theater",                         "Los Angeles",  "https://maps.app.goo.gl/cNvgYsUXZKyD1psAA" },
      { ME2026NA, 9816,  { PST,            local_days{2026y/4/26}  + 20h }, "Peacock Theater",                         "Los Angeles",  "https://maps.app.goo.gl/cNvgYsUXZKyD1psAA" },
      { ME2026NA, 9817,  { PHOENIX_TZ,     local_days{2026y/4/28}  + 20h }, "Desert Diamond Arena",                    "Glendale",     "https://maps.app.goo.gl/4x3GqU7c84hNeb3G8" },
      { ME2026NA, 9818,  { CST,            local_days{2026y/4/30}  + 20h }, "Texas Trust CU Theatre",                  "Grand Prairie","https://maps.app.goo.gl/pDy6ARcbAMbh9VoN6" },
      { ME2026NA, 9819,  { CST,            local_days{2026y/5/1}   + 20h }, "H-E-B Center at Cedar Park",              "Cedar Park",   "https://maps.app.goo.gl/F2TqY3cRPpXs6vgL8" },
      { ME2026NA, 9820,  { EST,            local_days{2026y/5/3}   + 20h }, "Gas South Arena",                         "Duluth",       "https://maps.app.goo.gl/mpStYrFULStsCLZz8" },
      { ME2026NA, 9821,  { EST,            local_days{2026y/5/5}   + 20h }, "The Anthem",                              "Washington",   "https://maps.app.goo.gl/5GHNFc4djSfgey3J9" },
      { ME2026NA, 9822,  { EST,            local_days{2026y/5/7}   + 20h }, "Prudencial Center",                       "Newark",       "https://maps.app.goo.gl/krmFYX3bx3ETjWoF6" },
      { ME2026NA, 9823,  { EST,            local_days{2026y/5/10}  + 20h }, "Wang Theatre at the Boch Center",         "Boston",       "https://maps.app.goo.gl/dcsQsVz9ovb59vFUA" },
      { ME2026NA, 9823,  { EST,            local_days{2026y/5/11}  + 20h }, "Wang Theatre at the Boch Center",         "Boston",       "https://maps.app.goo.gl/dcsQsVz9ovb59vFUA" },
      { ME2026NA, 9824,  { TORONTO_TZ,     local_days{2026y/5/13}  + 20h }, "TD Coliseum",                             "Hamilton",     "https://maps.app.goo.gl/erep1AemU7w9LrqY9" },
      { ME2026NA, 9825,  { MEXICO_CITY_TZ, local_days{2026y/5/19}  + 20h }, "Pepsi Center WTC",                        "Mexico City",  "https://maps.app.goo.gl/HTv12b5NkAHucHz47" },
      { MM2026,   12249, { JST,            local_days{2026y/7/24}  + 12h }, "ACT CITY Hamamatsu Main Hall",            "Hamamatsu",    "https://maps.app.goo.gl/B4WdBR8UxaM82qNT8" },
      { MM2026,   12249, { JST,            local_days{2026y/7/24}  + 16h + 30min }, "ACT CITY Hamamatsu Main Hall",    "Hamamatsu",    "https://maps.app.goo.gl/B4WdBR8UxaM82qNT8" },
      { MM2026,   12249, { JST,            local_days{2026y/7/25}  + 12h }, "ACT CITY Hamamatsu Main Hall",            "Hamamatsu",    "https://maps.app.goo.gl/B4WdBR8UxaM82qNT8" },
      { MM2026,   12249, { JST,            local_days{2026y/7/25}  + 16h + 30min }, "ACT CITY Hamamatsu Main Hall",    "Hamamatsu",    "https://maps.app.goo.gl/B4WdBR8UxaM82qNT8" },
      { MM2026,   12249, { JST,            local_days{2026y/7/26}  + 12h }, "ACT CITY Hamamatsu Main Hall",            "Hamamatsu",    "https://maps.app.goo.gl/B4WdBR8UxaM82qNT8" },
      { MM2026,   12249, { JST,            local_days{2026y/7/26}  + 16h + 30min }, "ACT CITY Hamamatsu Main Hall",    "Hamamatsu",    "https://maps.app.goo.gl/B4WdBR8UxaM82qNT8" },
      { MM2026,   12250, { JST,            local_days{2026y/8/14}  + 12h }, "INTEX Osaka Hall 5A",                     "Osaka",        "https://maps.app.goo.gl/SAWVstxBHiy7yGNv6" },
      { MM2026,   12250, { JST,            local_days{2026y/8/14}  + 16h + 30min }, "INTEX Osaka Hall 5A",             "Osaka",        "https://maps.app.goo.gl/SAWVstxBHiy7yGNv6" },
      { MM2026,   12250, { JST,            local_days{2026y/8/15}  + 12h }, "INTEX Osaka Hall 5A",                     "Osaka",        "https://maps.app.goo.gl/SAWVstxBHiy7yGNv6" },
      { MM2026,   12250, { JST,            local_days{2026y/8/15}  + 16h + 30min }, "INTEX Osaka Hall 5A",             "Osaka",        "https://maps.app.goo.gl/SAWVstxBHiy7yGNv6" },
      { MM2026,   12250, { JST,            local_days{2026y/8/16}  + 12h }, "INTEX Osaka Hall 5A",                     "Osaka",        "https://maps.app.goo.gl/SAWVstxBHiy7yGNv6" },
      { MM2026,   12250, { JST,            local_days{2026y/8/16}  + 16h + 30min }, "INTEX Osaka Hall 5A",             "Osaka",        "https://maps.app.goo.gl/SAWVstxBHiy7yGNv6" },
      { MM2026,   12251, { JST,            local_days{2026y/8/28}  + 12h }, "Makuhari Messe International Exhibition Hall 9",         "Chiba",        "https://maps.app.goo.gl/GYaL5bzGHLwL2xLt6" },
      { MM2026,   12251, { JST,            local_days{2026y/8/28}  + 16h + 30min }, "Makuhari Messe International Exhibition Hall 9", "Chiba",        "https://maps.app.goo.gl/GYaL5bzGHLwL2xLt6" },
      { MM2026,   12251, { JST,            local_days{2026y/8/29}  + 12h }, "Makuhari Messe International Exhibition Hall 9",         "Chiba",        "https://maps.app.goo.gl/GYaL5bzGHLwL2xLt6" },
      { MM2026,   12251, { JST,            local_days{2026y/8/29}  + 16h + 30min }, "Makuhari Messe International Exhibition Hall 9", "Chiba",        "https://maps.app.goo.gl/GYaL5bzGHLwL2xLt6" },
      { MM2026,   12251, { JST,            local_days{2026y/8/30}  + 12h }, "Makuhari Messe International Exhibition Hall 9",         "Chiba",        "https://maps.app.goo.gl/GYaL5bzGHLwL2xLt6" },
      { MM2026,   12251, { JST,            local_days{2026y/8/30}  + 16h + 30min }, "Makuhari Messe International Exhibition Hall 9", "Chiba",        "https://maps.app.goo.gl/GYaL5bzGHLwL2xLt6" },
      { MWY2026,  13120, { SHANGHAI_TZ,    local_days{2026y/10/31}  + 14h }, "Shanghai Jing'an Sports Center",          "Shanghai",     "https://maps.app.goo.gl/okQjZ99233fdEa8U8" },
      { MWY2026,  13120, { SHANGHAI_TZ,    local_days{2026y/10/31}  + 19h }, "Shanghai Jing'an Sports Center",          "Shanghai",     "https://maps.app.goo.gl/okQjZ99233fdEa8U8" },
      { MWY2026,  13120, { SHANGHAI_TZ,    local_days{2026y/11/1 }  + 14h }, "Shanghai Jing'an Sports Center",          "Shanghai",     "https://maps.app.goo.gl/okQjZ99233fdEa8U8" },
      { MWY2026,  13120, { SHANGHAI_TZ,    local_days{2026y/11/1 }  + 19h }, "Shanghai Jing'an Sports Center",          "Shanghai",     "https://maps.app.goo.gl/okQjZ99233fdEa8U8" },
      { ME2026EU, 12222, { LONDON_TZ,      local_days{2026y/11/12} + 20h }, "The O2",                                  "London",       "https://maps.app.goo.gl/wc6fh8pVJogAUaWcA" },
      { ME2026EU, 12223, { BRUSSELS_TZ,    local_days{2026y/11/14} + 20h }, "ING Arena",                               "Brussels",     "https://maps.app.goo.gl/qXoKyoWRaDYGWhJ4A" },
      { ME2026EU, 12224, { AMSTERDAM_TZ,   local_days{2026y/11/15} + 20h }, "AFAS Live",                               "Amsterdam",    "https://maps.app.goo.gl/qNVDzeBM5vsT2rvj7" },
      { ME2026EU, 12225, { BERLIN_TZ,      local_days{2026y/11/17} + 20h }, "Velodrom",                                "Berlin",       "https://maps.app.goo.gl/JxVfuKYQ11xtSfec7" },
      { ME2026EU, 12226, { DUSSELDORF_TZ,  local_days{2026y/11/20} + 20h }, "PSD Bank Dome",                           "Düsseldorf",   "https://maps.app.goo.gl/goJ2uA8sYsw8HPas9" },
      { ME2026EU, 12227, { PARIS_TZ,       local_days{2026y/11/22} + 20h }, "Accor Arena",                             "Paris",        "https://maps.app.goo.gl/WnapRimvbmGaGFc57" },
      { ME2026EU, 12228, { MADRID_TZ,      local_days{2026y/11/25} + 20h }, "Palacio Vistalegre",                      "Madrid",       "https://maps.app.goo.gl/jBdeiWfbBmNx78R37" },
      { SM2027,   13226, { JST,            local_days{2027y/2/5}   + 13h }, "Zepp Sapporo",                            "Sapporo",      "https://maps.app.goo.gl/TFLmo89RNEkPkCeU8" },
      { SM2027,   13226, { JST,            local_days{2027y/2/5}   + 17h }, "Zepp Sapporo",                            "Sapporo",      "https://maps.app.goo.gl/TFLmo89RNEkPkCeU8" },
      { SM2027,   13226, { JST,            local_days{2027y/2/6}   + 13h }, "Zepp Sapporo",                            "Sapporo",      "https://maps.app.goo.gl/TFLmo89RNEkPkCeU8" },
      { SM2027,   13226, { JST,            local_days{2027y/2/6}   + 17h }, "Zepp Sapporo",                            "Sapporo",      "https://maps.app.goo.gl/TFLmo89RNEkPkCeU8" },
      { SM2027,   13226, { JST,            local_days{2027y/2/7}   + 13h }, "Zepp Sapporo",                            "Sapporo",      "https://maps.app.goo.gl/TFLmo89RNEkPkCeU8" },
      { SM2027,   13226, { JST,            local_days{2027y/2/7}   + 17h }, "Zepp Sapporo",                            "Sapporo",      "https://maps.app.goo.gl/TFLmo89RNEkPkCeU8" },
    };
  }
} // namespace

export [[nodiscard]]
const std::vector<live_event>& get_live_events()
{
    std::call_once(live_events_init_flag, init_live_events);
    return live_events_storage;
}

export [[nodiscard]]
std::optional<std::chrono::sys_seconds> latest_show_start(ConcertTour tour)
{
    const auto& events = get_live_events();
    auto times = events
        | std::views::filter([tour](const auto& e) { return e.tour == tour; })
        | std::views::transform([](const auto& e) { return e.start_time.get_sys_time(); });
    if (std::ranges::empty(times)) return std::nullopt;
    return std::ranges::max(times);
}

export [[nodiscard]] bool
is_past_spoiler_window(const SetlistTrack& track)
{
    if (auto latest = latest_show_start(track.concert_short_name)) {
        constexpr auto show_duration = std::chrono::hours{3};
        return std::chrono::system_clock::now() > *latest + show_duration;
    }
    /* fallback for concerts without known show times */
    constexpr auto spoiler_duration = std::chrono::hours{36};
    auto concert = lookup_concert(track.concert_short_name);
    if (!concert) return true;
    return (std::chrono::system_clock::now() -
            static_cast<std::chrono::sys_days>(concert->last_date.value_or(concert->date)))
           > spoiler_duration;
}

export void
track_singer_emoji(std::ostream& os, const SetlistTrack& track, const Song& song)
{
  if (track.emoji_override) {
    os << *track.emoji_override;
  } else {
    song_singer_emoji(os, song);
  }
}
