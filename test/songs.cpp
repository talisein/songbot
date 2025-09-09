import std;
import boost.ut;
import songs;

int main()
{
    using namespace boost::ut;
    using namespace std::string_literals;
    using namespace std::string_view_literals;

    "altname"_test = [] {
        auto str = std::format("{}", lookup("LLNF"));
        expect(eq(str, "ルカルカ★ナイトフィーバー (Luka Luka★Night Fever) / Luka Luka★Night Fever feat. Luka by samfree"sv));
    };

    "jp"_test = [] {
        auto str = std::format("{}", lookup("恋色病棟"));
        expect(eq(str, "恋色病棟 (Koi Iro Byoutou) / Love Ward feat. Miku by OSTER project"sv));
    };

    return 0;
}
