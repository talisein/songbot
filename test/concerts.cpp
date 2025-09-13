import std;
import boost.ut;
import songs;
import concerts;

int main()
{
    using namespace boost::ut;
    using namespace std::literals;
    using namespace std::string_view_literals;
    using namespace boost::ut::literals;
    using namespace boost::ut::operators::terse;

    "concert"_test = [] {
        auto c = setlists[0];
        expect(eq(1, c.pos));
        expect(eq("ME2014IN"sv, c.concert));
        auto song = lookup_song(c.song);
        expect(eq("Kurousa-P"sv, song->producer));
    };

    "setlist"_test = [] {
        auto rng = get_setlist("ME2014IN");
        expect(eq("ME2014IN"sv, std::ranges::begin(rng)->concert));
        expect(eq("Senbonzakura"sv, lookup_song(std::ranges::begin(rng)->song)->romanji_name.value()));
    };

    "match concerts"_test = [] {
        auto vec = match_concerts("2014");
        expect(eq(2UZ, vec.size()));
        expect(eq("ME2014IN"sv, vec[0].short_name));
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
    };

    "all"_test = [] {
        for (auto track : setlists) {
            auto song = lookup_song(track.song);
            if (!song.has_value()) {
                expect(eq(""sv, track.song));
            }
        }
    };

    return 0;
}
