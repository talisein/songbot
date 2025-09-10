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

    return 0;
}
