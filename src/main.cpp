import std;
import songs;
import magic_enum;

int main()
{
    std::println("Song is by {}", lookup("senbonzakura").producer);
    std::println("Song is by {} sung by {}", lookup("Colorful Melody").producer,
                 magic_enum::enum_flags_name(lookup("Colorful Melody").singer));
    return 0;
}
