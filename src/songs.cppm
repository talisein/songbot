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
    std::optional<std::string_view> jp_name;
    std::optional<std::string_view> romanji_name;
    std::string_view name; // en
    Singer singer;
    std::string_view producer;
    std::chrono::year_month_day published;
    std::optional<std::string_view> disambiguation; // keep last
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
  {std::nullopt, std::nullopt, "Miku", Miku, "Anamanaguchi", 2016y/5/27, "Anamanaguchi"},
  {std::nullopt, std::nullopt, "METEOR", Miku, "DIVELA", 2018y/3/28, "Mirai Meteor"},
  {"メテオ", "Meteor", "Meteor", Miku, "John Zeroness", 2011y/3/20, "OG Meteor"},
}), make_casefold_proj<&Song::name>());

/* There must not be any duplicate songnames in songs. Its sorted, so just check adjacency. */
constexpr auto songs_have_same_names = [](auto l, auto r) constexpr {
    return l.name == r.name && l.disambiguation == r.disambiguation;
};
static_assert(std::ranges::adjacent_find(songs, songs_have_same_names) == std::ranges::end(songs),
              std::ranges::adjacent_find(songs, songs_have_same_names)->name);

/* Everything needs a date. Sometimes. */
constexpr auto song_has_no_date = [](const auto& song) constexpr { return song.published == 0y/0/0;};
static_assert(std::ranges::none_of(songs, song_has_no_date),
              std::ranges::find_if(songs, song_has_no_date)->name);

/* jp_name shouldn't equal name */
constexpr auto song_has_same_jp_en_name = [](const auto& song) constexpr { return song.jp_name.transform([sn = song.name](auto &jp_name) constexpr -> bool { return jp_name == sn; }).value_or(false); };
static_assert(std::ranges::none_of(songs, song_has_same_jp_en_name),
              std::ranges::find_if(songs, song_has_same_jp_en_name)->name);

/* romanji shouldn't equal jp_name */
constexpr auto song_has_same_jp_romanji_name = [](const auto& song) constexpr {
    return song.romanji_name.transform([jp_sn = song.jp_name](auto &romanji_name) constexpr -> bool { return romanji_name == jp_sn; }).value_or(false);
};
static_assert(std::ranges::none_of(songs, song_has_same_jp_romanji_name),
              std::ranges::find_if(songs, song_has_same_jp_romanji_name)->name);

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
                                  [](auto &name) constexpr { return std::ranges::contains(songs, name, &Song::name); },
                                  &AltName::name),
              std::ranges::find_if_not(alt_names,
                                       [](auto &name) constexpr { return std::ranges::contains(songs, name, &Song::name); },
                                       &AltName::name)->name);

template <>
struct std::formatter<Song> {
    constexpr auto parse(std::format_parse_context& ctx) {
        return ctx.begin();
    }

    constexpr auto format(const Song& song, std::format_context& ctx) const {
        std::ostringstream out;
        if (song.jp_name) {
            out << una::norm::to_nfc_utf8(*song.jp_name) << ' ';
            if (song.romanji_name) {
                out << "(" << una::norm::to_nfc_utf8(*song.romanji_name) << ") ";
            }
            out << "/ ";
        } else {
            // romanji but no jp could be other languages (Venus at the fingertips)
            if (song.romanji_name) {
                out << una::norm::to_nfc_utf8(*song.romanji_name) << " / ";
            }

        }
        out << song.name << " feat. " << magic_enum::enum_flags_name(song.singer) << " by " << song.producer;
        return std::ranges::copy(std::move(out).str(), ctx.out()).out;
    }
};

[[nodiscard]] constexpr
std::optional<Song>
lookup1(auto&& rng, std::optional<std::string_view> producer = std::nullopt)
{
    if (std::ranges::distance(rng) == 1)
        return *std::ranges::begin(rng);

    if (!producer) return std::nullopt;

    auto producer_rng = std::ranges::equal_range(rng,
                                                 una::cases::to_casefold_utf8(una::norm::to_nfkc_utf8(*producer)),
                                                 std::ranges::less{},
                                                 make_casefold_proj<&Song::producer>());

    if (std::ranges::distance(producer_rng) == 1)
        return *std::ranges::begin(producer_rng);

    return std::nullopt;
}

template<auto Proj, typename T>
constexpr auto make_needle_filter(T&& casefolded_needle)
{
    return std::views::filter([needle = std::forward<T>(casefolded_needle)](const auto& obj) constexpr -> bool {
        auto &val = std::invoke(Proj, obj);
        if constexpr (std::is_same_v<std::remove_cvref_t<decltype(val)>, std::optional<std::string_view>>) {
            if (val.has_value()) {
                return needle == una::cases::to_casefold_utf8(una::norm::to_nfkc_utf8(*val));
            }
            return false;
        } else {
            return needle == una::cases::to_casefold_utf8(una::norm::to_nfkc_utf8(val));
        }
    });
}

export [[nodiscard]] constexpr
std::optional<Song> lookup_song(std::string_view needle, std::optional<std::string_view> producer = std::nullopt)
{
    const auto casefolded_needle = una::cases::to_casefold_utf8(una::norm::to_nfkc_utf8(needle));
    if (auto rng = std::ranges::equal_range(songs, casefolded_needle, std::ranges::less{}, make_casefold_proj<&Song::name>());
        !std::ranges::empty(rng))
    {
        return lookup1(std::move(rng), producer);
    }

    /* Romanji */
    auto romanji_view = songs | make_opt_filter<&Song::romanji_name>();
    if (auto rng = songs | make_needle_filter<&Song::romanji_name>(casefolded_needle);
        !std::ranges::empty(rng))
    {
        return lookup1(std::move(rng), producer);
    }

    /* Alt name */
    if (auto alt_rng = alt_names | make_needle_filter<&AltName::alt_name>(casefolded_needle);
        !std::ranges::empty(alt_rng))
    {
        if (std::ranges::distance(alt_rng) != 1) return std::nullopt;

        auto rng = songs | make_needle_filter<&Song::name>(una::cases::to_casefold_utf8(una::norm::to_nfkc_utf8(std::ranges::begin(alt_rng)->name)));
        return lookup1(std::move(rng), producer);
    }

    /* Try japanese */
    if (auto rng = songs | make_needle_filter<&Song::jp_name>(casefolded_needle);
        !std::ranges::empty(rng))
    {
        return lookup1(std::move(rng), producer);
    }

    return std::nullopt;
}

export consteval
Song operator ""_song(const char* short_name, std::size_t len)
{
    return *lookup_song({short_name, len});
}
