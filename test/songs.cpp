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

    "No Same Names"_test = [] {
/* There must not be any duplicate songnames in songs. Its sorted, so just check adjacency. */
        auto songs_have_same_names = [](auto l, auto r) -> bool {
            return static_cast<bool>(l.cf_name == r.cf_name) && static_cast<bool>(l.disambiguation == r.disambiguation);
        };

        auto sorted_songs = songs;
        std::ranges::sort(sorted_songs, std::ranges::less{}, &Song::cf_name);
        auto it = std::ranges::adjacent_find(sorted_songs, songs_have_same_names);
        expect(it == std::ranges::end(sorted_songs)) << [&] { return std::format("Song {} ({}) is duplicated", it->name, it->cf_name); };
    };

    "No same JP names"_test = [] {
        auto songs_have_same_jp_names = [](const Song& l, const Song& r) -> bool {
            return static_cast<bool>(*l.cf_jp_name == *r.cf_jp_name) && static_cast<bool>(l.disambiguation == r.disambiguation);
        };
        std::vector<Song> jp_songs = std::views::filter(songs, [](const auto& song) { return song.jp_name.has_value(); } ) | std::ranges::to<std::vector>();
        std::ranges::sort(jp_songs, std::ranges::less{}, &Song::cf_jp_name);
        auto it = std::ranges::adjacent_find(jp_songs, songs_have_same_jp_names);
        expect(it == std::ranges::end(jp_songs)) <<
            [&] { return std::format("Song {} ({}) is duplicated", *it->jp_name, *it->cf_jp_name); };
    };

    "No same romanji names"_test = [] {
        auto songs_have_same_romanji_names = [](const Song& l, const Song& r) -> bool {
            return static_cast<bool>(*l.cf_romanji_name == *r.cf_romanji_name) && static_cast<bool>(l.disambiguation == r.disambiguation);
        };
        std::vector<Song> romanji_songs = std::views::filter(songs, [](const auto& song) { return song.romanji_name.has_value(); } ) | std::ranges::to<std::vector>();
        std::ranges::sort(romanji_songs, std::ranges::less{}, &Song::cf_romanji_name);
        auto it = std::ranges::adjacent_find(romanji_songs, songs_have_same_romanji_names);
        expect(it == std::ranges::end(romanji_songs)) <<
            [&] { return std::format("Song {} ({}) is duplicated", *it->romanji_name, *it->cf_romanji_name); };
    };

/* Everything needs a date. Sometimes. */
//        constexpr auto song_has_no_date = [](const auto& song) constexpr { return song.published == 0y/0/0;};
//static_assert(std::ranges::none_of(songs, song_has_no_date),
//              std::ranges::find_if(songs, song_has_no_date)->name);

    "jp_name shouldn't equal name"_test = [] {
        constexpr auto song_has_same_jp_en_name = [](const auto& song) constexpr { return song.jp_name.transform([sn = song.name](auto &jp_name) constexpr -> bool { return jp_name == sn; }).value_or(false); };
        expect(std::ranges::none_of(songs, song_has_same_jp_en_name)) <<
            [&] { return std::format("jp_name==name for {}", std::ranges::find_if(songs, song_has_same_jp_en_name)->name); };
    };

    "romanji shouldn't equal jp_name"_test = [] {
        constexpr auto song_has_same_jp_romanji_name = [](const auto& song) constexpr {
            return song.romanji_name.transform([jp_sn = song.jp_name](auto &romanji_name) constexpr -> bool { return romanji_name == jp_sn; }).value_or(false);
        };
        expect(std::ranges::none_of(songs, song_has_same_jp_romanji_name)) <<
            [&] { return std::format("romanji==jp_name for {}", std::ranges::find_if(songs, song_has_same_jp_romanji_name)->name); };
    };

    "songname"_test = [] {
        auto str = std::format("{}", *lookup_song("Fire◎Flower"));
        expect(eq(str, "[Fire◎Flower](https://vocadb.net/S/6387) feat. <:len:235217877446295553> by halyosy"sv));
    };

    "altname"_test = [] {
        auto str = std::format("{}", *lookup_song("LLNF"));
        expect(eq(str, "[ルカルカ★ナイトフィーバー / Luka Luka★Night Fever](https://vocadb.net/S/1435) feat. <:luka:235216119403773952> by samfree"sv));

        auto str2 = std::format("{}", *lookup_song("llnf"));
        expect(eq(str2, "[ルカルカ★ナイトフィーバー / Luka Luka★Night Fever](https://vocadb.net/S/1435) feat. <:luka:235216119403773952> by samfree"sv));
    };

    "Every AltName::name must exist in songs"_test = [] {
        expect(std::ranges::all_of(alt_names,
                                   [](auto &name) constexpr { return std::ranges::contains(songs, name, &Song::name); },
                                   &AltName::name)) <<
            [&] { return std::format("AltName {} doesn't exist in songs",
                                     std::ranges::find_if_not(alt_names,
                                                              [](auto &name) constexpr { return std::ranges::contains(songs, name, &Song::name); },
                                                              &AltName::name)->name); };
    };

    "jp"_test = [] {
        auto str = std::format("{}", *lookup_song("恋色病棟"));
        expect(eq(str, "[恋色病棟 (Koi Iro Byoutou) / Love Ward](https://vocadb.net/S/3015) feat. <:miku:235217471982927874> by OSTER project"sv));
    };

/*    "date"_test = [] {
        auto song = *lookup_song("fire flower");
        expect(eq(song.published, 2008y/8/2));
        expect(eq(std::format("{:%B %e, %Y}", song.published), "August  2, 2008"sv));
        };*/

    "disambiguate"_test = [] {
        expect(not(lookup_song("meteor").has_value()));
        expect(not(lookup_song("meteor", "divela").has_value()));
        auto mirai = lookup_song("meteor", "DIVELA");
        expect(mirai.has_value());
        expect(eq("DIVELA"sv, mirai->producer));
        auto good = *lookup_song("meteor", "John Zeroness");
        expect(eq("John Zeroness"sv, good.producer));
    };

    "Not found"_test = [] {
        expect(not(lookup_song("this song does not exist yet").has_value()));
    };

    "match"_test = [] {
        auto songs = match_songs("senbon");

        expect(eq(1UZ, songs.size()));

        songs = match_songs("roki");
        expect(eq(1UZ, songs.size()));

        songs = match_songs("LLNF");
        expect(eq(1UZ, songs.size()));

    };

    "kodo"_test = [] {
        auto song = lookup_song("Meguru");
        expect(song.has_value());
        expect(eq(std::format("{}", *song), "巡 (Meguru) / Patrol by Kodo with <:miku:235217471982927874>"sv));
    };

    return 0;

}
