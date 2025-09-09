import std;
import songs;
import magic_enum;
import uni_algo;
int main()
{
    for (const auto& song : songs) {
        std::println("{}", song);
    }
    std::println("Song is {}", lookup("senbonzakura"));
    std::println("Song is {}", lookup("Colorful x Melody"));
    std::println("Song is {}", lookup("恋色病棟"));
    std::println("Song is {}", lookup("LLNF"));

    return 0;
}
