module;

export module songs;

import std;
import uni_algo;
import magic_enum;

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
        {"千本桜", "Senbonzakura", "Thousand Cherry Blossoms",
         Miku, "Kurousa-P"},
        {"こっち向いて Baby", "Kocchi Muite Baby", "Look This Way, Baby",
         Miku, "ryo"},
        {"マージナル", "Marginal", "Marginal",
         Miku, "OSTER project"},
        {"恋色病棟", "Koi Iro Byoutou", "Love Ward",
         Miku, "OSTER project"},
        {"カラフル×メロディ", "Colorful × Melody", "Colorful × Melody",
         duet(Miku, Rin), "Team MOER"},
        {std::nullopt, std::nullopt, "Fire◎Flower",
         Len, "halyosy, absorb"},
        {"右肩の蝶", "Migikata no Chou", "Butterfly on Your Right Shoulder",
         Len, "Nori-P"},
        {"メランコリック", "Melancholic", "Melancholic",
         Rin, "Junky"},
        {"ココロ", "Kokoro", "Heart",
         Rin, "Toraboruta-P"},
        {"トリノコシティ", "Torinoko City", "Left-Behind City (Urbandonment)",
         Miku, "40mP"},
        {"結ンデ開イテ羅刹ト骸", "Musunde Hiraite Rasetsu to Mukuro", "Close and Open, Demons and The Dead",
         Miku, "Hachi"},
        {"ロミオとシンデレラ", "Romeo to Cinderella", "Romeo and Cinderella",
         Miku, "doriko"},
        {"ピアノ×フォルテ×スキャンダル", "Piano × Forte × Scandal", "Piano × Forte × Scandal",
         MEIKO, "OSTER project"},
        {std::nullopt, std::nullopt, "Pane dhiria",
         KAITO, "Shinjou-P"},
        {"千年の独奏歌", "Sennen no Dokusou Ka", "Thousand Year Solo",
         KAITO, "yanagi-P"},
        {"ぽっぴっぽー", "PoPiPo", "PoPiPo",
         Miku, "Lamaze-P"},
        {"白い雪のプリンセスは", "Shiroi Yuki no Princess wa", "The Snow White Princess is",
         Miku, "Noboru↑-P"},
        {std::nullopt, "Venus di Ujung Jari", "Venus at The Fingertips",
         Miku, "Mohax-2000"},
        {"ダブルラリアット", "Double Lariat", "Double Lariat",
         Luka, "Agoaniki-P"},
        {"ルカルカ★ナイトフィーバー", "Luka Luka★Night Fever", "Luka Luka★Night Fever",
         Luka, "samfree"},
        {"秘密警察", "Himitsu Keisatsu", "Secret Police",
         Miku, "Buriru-P"},
        {std::nullopt, std::nullopt, "Yellow",
         Miku, "kz"},
        {"初音ミクの激唱", "Hatsune Miku no Gekishou", "The Intense Voice of Hatsune Miku",
         Miku, "cosMo"},
        {"メルト", "Melt", "Melt",
         Miku, "ryo"},
        {std::nullopt, std::nullopt, "Tell Your World",
         Miku, "kz"},
        {"みくみくにしてあげる♪", "Miku Miku ni Shite Ageru♪", "I'll Miku-Miku You♪ (For Reals)",
         Miku, "ika"},
        {std::nullopt, std::nullopt, "letter song",
         Miku, "doriko"},
        }), make_casefold_proj<&Song::songname>());

static_assert(std::ranges::size(songs) > 10);
/* There must not be any duplicate songnames in songs */
static_assert(std::ranges::adjacent_find(songs, {}, &Song::songname) == std::ranges::end(songs),
              std::ranges::adjacent_find(songs, {}, &Song::songname)->songname);
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

    auto format(const Song& song, std::format_context& ctx) const {
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
