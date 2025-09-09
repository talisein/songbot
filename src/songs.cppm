module;

export module songs;

import std;
import uni_algo;
import magic_enum;
using namespace std::literals;

export enum Singer : std::uint32_t {
    Miku  = 1 << 1,
    Rin   = 1 << 2,
    Len   = 1 << 3,
    Luka  = 1 << 4,
    MEIKO = 1 << 5,
    KAITO = 1 << 6,
    Teto  = 1 << 7,
};

template<typename... T> requires (std::is_same_v<T, Singer> && ...)
constexpr
enum Singer duet(T... singer)
{
    return static_cast<Singer>((singer | ...));
}

template <>
struct magic_enum::customize::enum_range<Singer> {
  static constexpr bool is_flags = true;
};

export struct Song
{
    std::optional<std::string_view> jp_songname;
    std::optional<std::string_view> romanji_songname;
    std::string_view songname; // en
    Singer singer;
    std::string_view producer;
    std::chrono::year_month_day published;
};

template<auto Proj>
constexpr auto make_casefold_proj()
{
    return [](const auto& obj) constexpr {
        return una::cases::to_casefold_utf8(una::norm::to_nfkc_utf8(std::invoke(Proj, obj)));
    };
}

template<auto Proj>
constexpr auto make_opt_casefold_proj()
{
    return [](const auto& obj) constexpr {
        return una::cases::to_casefold_utf8(una::norm::to_nfkc_utf8(std::invoke(Proj, obj).value()));
    };
}

template<auto Proj>
constexpr auto make_opt_filter()
{
    return std::views::filter([](const auto& obj) constexpr -> bool {
        return std::invoke(Proj, obj).has_value();
    });
}


template<typename T, typename Proj, std::size_t N>
consteval auto get_sorted_songs(const std::array<T, N>& arr, Proj&& proj) -> std::array<T, N>
{
    std::array<T, N> sorted_arr = arr;
    std::ranges::stable_sort(sorted_arr, std::ranges::less{}, std::forward<Proj>(proj));
    return sorted_arr;
}

export constexpr std::array songs = get_sorted_songs(std::to_array<Song>({
  {"千本桜", "Senbonzakura", "Thousand Cherry Blossoms", Miku, "Kurousa-P", 2011y/9/17},
  {"こっち向いて Baby", "Kocchi Muite Baby", "Look This Way, Baby", Miku, "ryo", 2010y/7/2},
  {"マージナル", "Marginal", "Marginal", Miku, "OSTER project", 2008y/12/15},
  {"恋色病棟", "Koi Iro Byoutou", "Love Ward", Miku, "OSTER project", 2009y/6/16},
  {"カラフル×メロディ", "Colorful × Melody", "Colorful × Melody", duet(Miku, Rin), "Team MOER", 2010y/7/2},
  {std::nullopt, std::nullopt, "Fire◎Flower", Len, "halyosy", 2008y/8/2},
  {"右肩の蝶", "Migikata no Chou", "Butterfly on Your Right Shoulder", Len, "Nori-P", 2009y/3/31},
  {"メランコリック", "Melancholic", "Melancholic", Rin, "Junky", 2010y/4/2010},
  {"ココロ", "Kokoro", "Heart", Rin, "Toraboruta-P", 2008y/3/2},
  {"トリノコシティ", "Torinoko City", "Left-Behind City (Urbandonment)", Miku, "40mP", 2010y/7/29},
  {"結ンデ開イテ羅刹ト骸", "Musunde Hiraite Rasetsu to Mukuro", "Close and Open, Demons and The Dead", Miku, "Hachi", 2009y/7/5},
  {"ロミオとシンデレラ", "Romeo to Cinderella", "Romeo and Cinderella", Miku, "doriko", 2009y/4/5},
  {"ピアノ×フォルテ×スキャンダル", "Piano × Forte × Scandal", "Piano × Forte × Scandal", MEIKO, "OSTER project", 2008y/12/19},
  {std::nullopt, std::nullopt, "Pane dhiria", KAITO, "Shinjou-P", 2010y/1/19},
  {"千年の独奏歌", "Sennen no Dokusou Ka", "Thousand Year Solo", KAITO, "yanagi-P", 2008y/4/27},
  {"ぽっぴっぽー", "PoPiPo", "Vegetable Juice", Miku, "Lamaze-P", 2008y/12/11},
  {"白い雪のプリンセスは", "Shiroi Yuki no Princess wa", "The Snow White Princess is", Miku, "Noboru↑-P", 2010y/2/21},
  {std::nullopt, "Venus di Ujung Jari", "Venus at The Fingertips", Miku, "Mohax-2000", 2011y/6/6},
  {"ダブルラリアット", "Double Lariat", "Double Lariat", Luka, "Agoaniki-P", 2009y/2/4},
  {"ルカルカ★ナイトフィーバー", "Luka Luka★Night Fever", "Luka Luka★Night Fever", Luka, "samfree", 2009y/2/12},
  {"秘密警察", "Himitsu Keisatsu", "Secret Police", Miku, "Buriru-P", 2010y/11/9},
  {std::nullopt, std::nullopt, "Yellow", Miku, "kz", 2010y/7/2},
  {"初音ミクの激唱", "Hatsune Miku no Gekishou", "The Intense Voice of Hatsune Miku", Miku, "cosMo", 2010y/7/9},
  {"メルト", "Melt", "Melt", Miku, "ryo", 2007y/12/7},
  {std::nullopt, std::nullopt, "Tell Your World", Miku, "kz", 2012y/3/12},
  {"みくみくにしてあげる♪", "Miku Miku ni Shite Ageru♪", "I'll Miku-Miku You♪ (For Reals)", Miku, "ika", 2007y/9/19},
  {std::nullopt, std::nullopt, "letter song", Miku, "doriko", 2008y/6/26},
}), make_casefold_proj<&Song::songname>());

/* There must not be any duplicate songnames in songs. Its sorted, so just check adjacency. */
static_assert(std::ranges::adjacent_find(songs, {}, &Song::songname) == std::ranges::end(songs),
              std::ranges::adjacent_find(songs, {}, &Song::songname)->songname);
/* Everything needs a date. Sometimes. */
static_assert(std::ranges::none_of(songs, [](auto date) { return date == 0y/0/0; }, &Song::published),
              std::ranges::find_if(songs, [](auto song) { return song.published == 0y/0/0;})->songname);
/* jp_songname shouldn't equal songname */
static_assert(std::ranges::none_of(songs, [](const Song& song) constexpr {
    return song.jp_songname.transform([sn = song.songname](auto &jp_songname) constexpr -> bool { return jp_songname == sn; }).value_or(false);
}),
    std::ranges::find_if(songs, [](const Song& song) constexpr -> bool { return song.jp_songname.transform([sn = song.songname](auto &jp_songname){ return jp_songname == sn; }).value_or(false);  })->songname);
/* romanji shouldn't equal jp_songname */
static_assert(std::ranges::none_of(songs, [](const Song& song) constexpr {
    return song.romanji_songname.transform([jp_sn = song.jp_songname](auto &romanji_songname) constexpr -> bool { return romanji_songname == jp_sn; }).value_or(false);
}),
    std::ranges::find_if(songs, [](const Song& song) constexpr -> bool { return song.romanji_songname.transform([jp_sn = song.jp_songname](auto &romanji_songname){ return romanji_songname == jp_sn; }).value_or(false);  })->songname);

struct AltName
{
    std::string_view alt_name;
    std::string_view name;
};

constexpr std::array alt_names = get_sorted_songs(std::to_array<AltName>({
            { "Colorful Melody", "Colorful × Melody"},
            { "Colorful x Melody", "Colorful × Melody"},
            { "Fire Flower", "Fire◎Flower"},
            { "FireFlower", "Fire◎Flower"},
            { "Piano Forte Scandal", "Piano × Forte × Scandal"},
            { "Piano x Forte x Scandal", "Piano × Forte × Scandal"},
            { "LLNF", "Luka Luka★Night Fever"},
            { "Luka Luka Night Fever", "Luka Luka★Night Fever"},
        }), &AltName::alt_name);

/* Every AltName::name must exist in songs */
static_assert(std::ranges::all_of(alt_names,
                                  [](auto &name) constexpr { return std::ranges::contains(songs, name, &Song::songname); },
                                  &AltName::name),
              std::ranges::find_if_not(alt_names,
                                       [](auto &name) constexpr { return std::ranges::contains(songs, name, &Song::songname); },
                                       &AltName::name)->name);

template <>
struct std::formatter<Song> {
    constexpr auto parse(std::format_parse_context& ctx) {
        return ctx.begin();
    }

    constexpr auto format(const Song& song, std::format_context& ctx) const {
        std::ostringstream out;
        if (song.jp_songname) {
            out << una::norm::to_nfc_utf8(*song.jp_songname) << ' ';
            if (song.romanji_songname) {
                out << "(" << una::norm::to_nfc_utf8(*song.romanji_songname) << ") ";
            }
            out << "/ ";
        } else {
            // romanji but no jp could be other languages (Venus at the fingertips)
            if (song.romanji_songname) {
                out << una::norm::to_nfc_utf8(*song.romanji_songname) << " / ";
            }

        }
        out << song.songname << " feat. " << magic_enum::enum_flags_name(song.singer) << " by " << song.producer;
        return std::ranges::copy(std::move(out).str(), ctx.out()).out;
    }
};

export consteval const Song& lookup(std::string_view needle)
{
    auto casefolded_needle = una::cases::to_casefold_utf8(una::norm::to_nfkc_utf8(needle));
    if (auto it = std::ranges::lower_bound(songs, casefolded_needle, std::ranges::less{}, make_casefold_proj<&Song::songname>());
        it != std::ranges::end(songs) && una::cases::to_casefold_utf8(una::norm::to_nfkc_utf8(it->songname)) == casefolded_needle)
    {
        return *it;
    }

    /* Romanji */
    auto romanji_view = songs | make_opt_filter<&Song::romanji_songname>();
    if (auto it = std::ranges::find(romanji_view,
                                    casefolded_needle,
                                    make_opt_casefold_proj<&Song::romanji_songname>());
        it != std::ranges::end(romanji_view))
    {
        return *it;
    }

    /* Alt name */
    if (auto alt_it = std::ranges::find(alt_names,
                                        casefolded_needle,
                                        make_casefold_proj<&AltName::alt_name>());
        alt_it != std::ranges::end(alt_names))
    {
        // No need to casefold
        auto it = std::ranges::find(songs, alt_it->name, &Song::songname);
        return *it;
    }

    /* Try japanese */
    auto jp_view = songs | make_opt_filter<&Song::jp_songname>();
    if (auto it = std::ranges::find(jp_view,
                                    casefolded_needle,
                                    make_opt_casefold_proj<&Song::jp_songname>());
        it != std::ranges::end(jp_view))
    {
        return *it;
    }

    throw std::exception();
}
