import std;
import boost.ut;
import songs;

int main()
{
    using namespace boost::ut;
    using namespace std::literals;
    using namespace std::string_view_literals;
    using namespace boost::ut::literals;
    using namespace boost::ut::operators::terse;

    "songname"_test = [] {
        auto str = std::format("{}", lookup("Fire◎Flower"));
        expect(eq(str, "Fire◎Flower feat. Len by halyosy"sv));
    };

    "altname"_test = [] {
        auto str = std::format("{}", lookup("LLNF"));
        expect(eq(str, "ルカルカ★ナイトフィーバー (Luka Luka★Night Fever) / Luka Luka★Night Fever feat. Luka by samfree"sv));
    };


    "jp"_test = [] {
        auto str = std::format("{}", lookup("恋色病棟"));
        expect(eq(str, "恋色病棟 (Koi Iro Byoutou) / Love Ward feat. Miku by OSTER project"sv));
    };

    "date"_test = [] {
        auto song = lookup("fire flower");
        expect(eq(song.published, 2008y/8/2));
        expect(eq(std::format("{:%B %e, %Y}", song.published), "August  2, 2008"sv));
    };

    "disambiguate"_test = [] {
        constexpr static auto mirai = lookup("meteor", "divela");
        expect(eq("DIVELA"sv, mirai.producer));
        constexpr static auto good = lookup("meteor", "john zeroness");
        expect(eq("John Zeroness"sv, good.producer));
    };

    "Not found"_test = [] {
        expect(throws([] { (void)lookup("this song does not exist yet"); }));
    };

    return 0;
}
