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
        auto str = std::format("{}", "Fire◎Flower"_song);
        expect(eq(str, "Fire◎Flower feat. Len by halyosy"sv));
    };

    "altname"_test = [] {
        auto str = std::format("{}", "LLNF"_song);
        expect(eq(str, "ルカルカ★ナイトフィーバー (Luka Luka★Night Fever) / Luka Luka★Night Fever feat. Luka by samfree"sv));
    };


    "jp"_test = [] {
        auto str = std::format("{}", "恋色病棟"_song);
        expect(eq(str, "恋色病棟 (Koi Iro Byoutou) / Love Ward feat. Miku by OSTER project"sv));
    };

    "date"_test = [] {
        auto song = "fire flower"_song;
        expect(eq(song.published, 2008y/8/2));
        expect(eq(std::format("{:%B %e, %Y}", song.published), "August  2, 2008"sv));
    };

    "disambiguate"_test = [] {
        constexpr static auto mirai = *lookup_song("meteor", "divela");
        expect(eq("DIVELA"sv, mirai.producer));
        constexpr static auto good = *lookup_song("meteor", "john zeroness");
        expect(eq("John Zeroness"sv, good.producer));
    };

    "Not found"_test = [] {
        expect(not(lookup_song("this song does not exist yet").has_value()));
    };

    return 0;
}
