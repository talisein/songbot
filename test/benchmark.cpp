import std;
import songs;
import concerts;
import project_diva;

int main()
{
    using namespace std::chrono;
    constexpr int reps = 1000;

    {
        int found = 0;
        auto start = steady_clock::now();
        for (int i = 0; i < reps; ++i)
            for (const auto& track : diva_tracks)
                if (find_song_for_track(track).has_value()) ++found;
        auto ns = duration_cast<nanoseconds>(steady_clock::now() - start).count();
        auto calls = reps * std::ssize(diva_tracks);
        std::println("find_song_for_track (game):    {:4} ns/call  ({} tracks x {} reps, {} found/rep)",
                     ns / calls, diva_tracks.size(), reps, found / reps);
    }

    {
        int found = 0;
        auto start = steady_clock::now();
        for (int i = 0; i < reps; ++i)
            for (const auto& song : songs)
                if (song_is_game_track(song)) ++found;
        auto ns = duration_cast<nanoseconds>(steady_clock::now() - start).count();
        auto calls = reps * std::ssize(songs);
        std::println("song_is_game_track:            {:4} ns/call  ({} songs x {} reps, {} found/rep)",
                     ns / calls, songs.size(), reps, found / reps);
    }

    {
        int found = 0;
        auto start = steady_clock::now();
        for (int i = 0; i < reps; ++i)
            for (const auto& track : get_setlists())
                if (find_song_for_track(track).has_value()) ++found;
        auto ns = duration_cast<nanoseconds>(steady_clock::now() - start).count();
        auto calls = reps * std::ssize(get_setlists());
        std::println("find_song_for_track (setlist): {:4} ns/call  ({} tracks x {} reps, {} found/rep)",
                     ns / calls, get_setlists().size(), reps, found / reps);
    }

    {
        int found = 0;
        auto start = steady_clock::now();
        for (int i = 0; i < reps; ++i)
            for (const auto& song : songs)
                if (song_is_concert_track(song)) ++found;
        auto ns = duration_cast<nanoseconds>(steady_clock::now() - start).count();
        auto calls = reps * std::ssize(songs);
        std::println("song_is_concert_track:         {:4} ns/call  ({} songs x {} reps, {} found/rep)",
                     ns / calls, songs.size(), reps, found / reps);
    }
}
