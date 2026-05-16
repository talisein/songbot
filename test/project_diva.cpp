import std;
import boost.ut;
import songs;
import project_diva;
import songbot.errors;

int main()
{
    using namespace boost::ut;
    using namespace std::literals;
    using namespace std::string_view_literals;
    using namespace boost::ut::literals;
    using namespace boost::ut::operators::terse;

    "find by name, no producer"_test = [] {
        auto result = find_song_for_track({DIVA, "Electric Angel"});
        expect(result.has_value());
        expect(eq("Yasuo-P"sv, result->producer));
    };

    "find by name and matching producer"_test = [] {
        auto result = find_song_for_track({DIVA, "Electric Angel", "Yasuo-P"});
        expect(result.has_value());
        expect(eq("Electric Angel"sv, result->name));
    };

    "wrong producer returns no_match"_test = [] {
        auto result = find_song_for_track({DIVA, "Electric Angel", "wrongP"});
        expect(not result.has_value());
        expect(eq(result.error(), make_error_code(songbot_error::no_match)));
    };

    "nonexistent song returns no_match"_test = [] {
        auto result = find_song_for_track({DIVA, "this does not exist"});
        expect(not result.has_value());
        expect(eq(result.error(), make_error_code(songbot_error::no_match)));
    };

    "name match is exact, not casefolded"_test = [] {
        /* "electric angel" should not match "Electric Angel" */
        auto result = find_song_for_track({DIVA, "electric angel"});
        expect(not result.has_value());
    };

    "all diva_tracks resolve without multiple_matches"_test = [] {
        for (const auto& track : diva_tracks) {
            auto result = find_song_for_track(track);
            if (!result.has_value()) {
                expect(eq(""sv, track.song)) << "find_song_for_track failed for: " << track.song;
            }
        }
    };

    return 0;
}
