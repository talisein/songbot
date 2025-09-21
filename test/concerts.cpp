import std;
import boost.ut;
import songs;
import concerts;
import util;
import magic_enum;

int main()
{
    using namespace boost::ut;
    using namespace std::literals;
    using namespace std::string_view_literals;
    using namespace boost::ut::literals;
    using namespace boost::ut::operators::terse;

    "Every concert series needs to exist"_test = [] {
        constexpr auto concert_series_exists = [](const SetlistTrack& track) constexpr -> bool { return std::ranges::contains(concerts, track.concert_short_name, &Concert::short_name); };
        expect(std::ranges::all_of(setlists, concert_series_exists)) << [&] {
            return magic_enum::enum_name(std::ranges::find_if_not(setlists, concert_series_exists)->concert_short_name); };
    };

    "Every song needs to exist"_test = [] {
        constexpr auto song_exists = [](const SetlistTrack& track) constexpr -> bool { return lookup_song_strict(track.song, track.producer).has_value(); };
        expect(std::ranges::all_of(setlists, song_exists)) << [&] {
            return std::ranges::find_if_not(setlists, song_exists)->song; };
    };

    "Every setlist position in a series must exist."_test = [] {
        auto setlist_positions_skipped = [](const Concert& concert) -> bool {
            auto tracks = setlists | util::make_needle_filter<&SetlistTrack::concert_short_name>(concert.short_name) | std::ranges::to<std::vector>();
            std::ranges::stable_sort(tracks, {}, &SetlistTrack::pos);
            auto rng = std::views::slide(tracks, 2);
            for (auto pair : rng) {
                auto it = std::ranges::begin(pair);
                auto first = it->pos;
                auto second = (++it)->pos;
                if ((second - first) > 1)
                    return true;
            }
            return false;
        };
        expect(std::ranges::none_of(concerts, setlist_positions_skipped)) << [&] {
            return magic_enum::enum_name(std::ranges::find_if(concerts, setlist_positions_skipped)->short_name);
        };
    };

    "concert"_test = [] {
        auto c = setlists[0];
        expect(eq(1, c.pos));
        expect(eq(MIKUFES09, c.concert_short_name));
        auto song = lookup_song(c.song);
        expect(eq("MOSAIC.WAV×ika"sv, song->producer));
    };

    "setlist"_test = [] {
        auto rng = get_setlist("ME2014IN");
        expect(eq(ME2014IN, std::ranges::begin(rng)->concert_short_name));
        expect(eq("Senbonzakura"sv, lookup_song(std::ranges::begin(rng)->song)->romanji_name.value()));
    };

    "setlist case insensitive"_test = [] {
        auto rng = get_setlist("me2014in");
        expect(eq(ME2014IN, std::ranges::begin(rng)->concert_short_name));
        expect(eq("Senbonzakura"sv, lookup_song(std::ranges::begin(rng)->song)->romanji_name.value()));
    };

    "match concerts"_test = [] {
        auto vec = match_concerts("2014");
        expect(eq(3UZ, vec.size()));
        expect(eq(ME2014IN, vec[0].short_name));
    };

    "no match concert"_test = [] {
        auto resp = lookup_concert("this does not exist");
        expect(not(resp));
    };

    "casefold concert"_test = [] {
        auto resp = lookup_concert("me2014in");
        expect(resp.has_value());
        resp = lookup_concert("ME2014IN");
        expect(resp.has_value());
        resp = lookup_concert("mm10th sapporo");
        expect(resp.has_value());
        expect(resp->short_name == MM10Sapporo);
    };

    "all"_test = [] {
        for (auto track : setlists) {
            auto song = lookup_song(track.song, track.producer);
            if (!song.has_value()) {
                expect(eq(""sv, track.song));
            }
        }
    };

    "Check the case!"_test = [] {
        for (auto track : setlists) {
            auto song = lookup_song(track.song, track.producer);
            if (song) {
                expect(eq(song->name, track.song));
            }
        }
    };

    return 0;
}
