export module concerts:data;

import :types;
import :raw_data;
import std;
import songs;
import util;

export constexpr auto exact_song_track_match = [](const Song& song, const SetlistTrack& track) constexpr {
  return song.name == track.song && song.producer == track.producer.value_or(song.producer);
};

namespace {
    constexpr bool always_true(const SetlistTrack&) { return true; }
    constexpr ConcertSeries tour_to_series(ConcertTour t) {
      auto c = std::ranges::find(concerts, t, &Concert::short_name);
      return c->series;
    }
    constexpr bool is_miku_expo(const SetlistTrack& t) {
      return tour_to_series(t.concert_short_name) == MIKU_EXPO;
    }
    constexpr bool is_mirai(const SetlistTrack& t) {
      return tour_to_series(t.concert_short_name) == MAGICAL_MIRAI;
    }
    constexpr bool is_miku_with_you(const SetlistTrack& t) {
      return tour_to_series(t.concert_short_name) == MIKU_WITH_YOU;
    }
    constexpr bool is_mikupa(const SetlistTrack& t) {
      return tour_to_series(t.concert_short_name) == MIKUPA;
    }
    constexpr bool is_snow_miku(const SetlistTrack& t) {
      return tour_to_series(t.concert_short_name) == SNOW_MIKU;
    }

    template<auto Filter = always_true>
    consteval auto generate_song_frequency()
    {
        std::vector<song_frequency> freqs;
        auto tracks = std::views::filter(setlists, Filter) | std::ranges::to<std::vector>();
        std::ranges::stable_sort(tracks, [](const auto &l, const auto &r) {
          if (l.song == r.song) {
            return std::ranges::less{}(l.producer, r.producer);
          } else {
            return std::ranges::less{}(l.song, r.song);
          }
        });
        std::string_view prev_song;
        std::optional<std::string_view> prev_producer;
        std::size_t count = 0;
        auto out = std::back_inserter(freqs);
        for (auto track : tracks) {
            if (track.song == prev_song && track.producer == prev_producer) {
                ++count;
            } else { /* name != prev_name */
                if (count != 0) {
                    out = song_frequency{prev_song, prev_producer, count};
                    prev_song = track.song;
                    prev_producer = track.producer;
                    count = 1;
                } else {
                    prev_song = track.song;
                    prev_producer = track.producer;
                    count = 1;
                }
            }
        }
        out = song_frequency{prev_song, prev_producer, count};

        std::ranges::stable_sort(freqs, std::ranges::greater{}, &song_frequency::count);
        return freqs;
    }
}

export constexpr std::array song_frequencies = util::materialize<generate_song_frequency<>>();

export constexpr auto setlists_by_song = util::materialize<[]() {
    auto copy = setlists;
    std::ranges::sort(copy, {}, &SetlistTrack::song);
    return copy;
}>();
export constexpr std::array song_frequencies_expo = util::materialize<generate_song_frequency<is_miku_expo>>();
export constexpr std::array song_frequencies_mirai = util::materialize<generate_song_frequency<is_mirai>>();
export constexpr std::array song_frequencies_mwy = util::materialize<generate_song_frequency<is_miku_with_you>>();
export constexpr std::array song_frequencies_mikupa = util::materialize<generate_song_frequency<is_mikupa>>();
export constexpr std::array song_frequencies_snowmiku = util::materialize<generate_song_frequency<is_snow_miku>>();
