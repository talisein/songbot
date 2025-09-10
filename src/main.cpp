import std;
import songs;
import magic_enum;
import uni_algo;
int main()
{
    for (const auto& song : songs) {
        std::println("{}", song);
    }

    std::println("\nSong is {}", "senbonzakura"_song);
    std::println("Song is {}", "Colorful x Melody"_song);
    std::println("Song is {}", "恋色病棟"_song);
    std::println("Song is {}", "LLNF"_song);

    return 0;
}
