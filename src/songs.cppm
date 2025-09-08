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
    std::optional<std::string_view> shortname;
    Singer singer;
    std::string_view producer;
};

template<std::size_t N>
consteval auto get_sorted_songs(const std::array<Song, N>& arr) -> std::array<Song, N>
{
    std::array<Song, N> sorted_arr = arr;
    std::ranges::stable_sort(sorted_arr, {}, &Song::songname);
    return sorted_arr;
}

constexpr std::array songs = get_sorted_songs(std::to_array<Song>({
        {"千本桜", "Senbonzakura", "Thousand Cherry Blossoms",
         std::nullopt, Miku, "Kurousa-P"},
        {"こっち向いて Baby", "Kocchi Muite Baby", "Look This Way, Baby",
         std::nullopt, Miku, "ryo"},
        {"マージナル", "Marginal", "Marginal",
         std::nullopt, Miku, "OSTER project"},
        {"恋色病棟", "Koi Iro Byoutou", "Love Ward",
         std::nullopt, Miku, "OSTER project"},
        {"カラフル×メロディ", "Colorful × Melody", "Colorful × Melody",
         "Colorful Melody", duet(Miku, Rin), "Team MOER"},
        {"Fire◎Flower", "Fire◎Flower", "Fire◎Flower",
         "Fire Flower", Len, "halyosy, absorb"},
        {"右肩の蝶", "Migikata no Chou", "Butterfly on Your Right Shoulder",
         std::nullopt, Len, "Nori-P"},
        {"メランコリック", "Melancholic", "Melancholic",
         std::nullopt, Rin, "Junky"},
        {"ココロ", "Kokoro", "Heart",
         std::nullopt, Rin, "Toraboruta-P"},
        {"トリノコシティ", "Torinoko City", "Left-Behind City (Urbandonment)",
         std::nullopt, Miku, "40mP"},
        {"結ンデ開イテ羅刹ト骸", "Musunde Hiraite Rasetsu to Mukuro", "Close and Open, Demons and The Dead",
         std::nullopt, Miku, "Hachi"},
        {"ロミオとシンデレラ", "Romeo to Cinderella", "Romeo and Cinderella",
         std::nullopt, Miku, "doriko"},
        {"ピアノ×フォルテ×スキャンダル", "Piano × Forte × Scandal", "Piano × Forte × Scandal",
         std::nullopt, MEIKO, "OSTER project"},
        {"Pane dhiria", "Pane dhiria", "Pane dhiria",
         std::nullopt, KAITO, "Shinjou-P"},
        {"千年の独奏歌", "Sennen no Dokusou Ka", "Thousand Year Solo",
         std::nullopt, KAITO, "yanagi-P"},
        {"ぽっぴっぽー", "PoPiPo", "PoPiPo",
         std::nullopt, Miku, "Lamaze-P"},
        {"白い雪のプリンセスは", "Shiroi Yuki no Princess wa", "The Snow White Princess is",
         std::nullopt, Miku, "Noboru↑-P"},
        {"Venus di Ujung Jari", "Venus di Ujung Jari", "Venus at The Fingertips",
         std::nullopt, Miku, "Mohax-2000"},
        {"ダブルラリアット", "Double Lariat", "Double Lariat",
         std::nullopt, Luka, "Agoaniki-P"},
        {"ルカルカ★ナイトフィーバー", "Luka Luka★Night Fever", "Luka Luka★Night Fever",
         std::nullopt, Luka, "samfree"},
        {"秘密警察", "Himitsu Keisatsu", "Secret Police",
         std::nullopt, Miku, "Buriru-P"},
        {"Yellow", "Yellow", "Yellow",
         std::nullopt, Miku, "kz"},
        {"初音ミクの激唱", "Hatsune Miku no Gekishou", "The Intense Voice of Hatsune Miku",
         std::nullopt, Miku, "cosMo"},
        {"メルト", "Melt", "Melt",
         std::nullopt, Miku, "ryo"},
        {"Tell Your World", "Tell Your World", "Tell Your World",
         std::nullopt, Miku, "kz"},
        {"みくみくにしてあげる♪", "Miku Miku ni Shite Ageru♪", "I'll Miku-Miku You♪ (For Reals)",
         std::nullopt, Miku, "ika"},
        {"letter song", "letter song", "letter song",
         std::nullopt, Miku, "doriko"},
        }));

static_assert(std::ranges::size(songs) > 10);
static_assert(std::ranges::adjacent_find(songs, {}, &Song::songname) == std::ranges::end(songs),
              std::ranges::adjacent_find(songs, {}, &Song::songname)->songname);

export consteval const Song& lookup(std::string_view name)
{
    if (auto it =std::ranges::find(songs, una::cases::to_casefold_utf8(name),
                                   [](auto &song) constexpr {return una::cases::to_casefold_utf8(song.songname);});
        it != std::ranges::end(songs))
    {
        return *it;
    }

    /* Romanji */
    auto romanji_view = songs | std::views::filter([](auto &song) constexpr { return song.romanji_songname.has_value(); });
    if (auto it = std::ranges::find(romanji_view,
                                    una::cases::to_casefold_utf8(name),
                                    [](auto &song) constexpr {return una::cases::to_casefold_utf8(*song.romanji_songname);});
        it != std::ranges::end(romanji_view))
    {
        return *it;
    }

    /* Short name */
    auto shortname_view = songs | std::views::filter([](auto &song) constexpr { return song.shortname.has_value(); });
    if (auto it = std::ranges::find(shortname_view,
                                     una::cases::to_casefold_utf8(name),
                                     [](auto &song) constexpr { return una::cases::to_casefold_utf8(*song.shortname); });
        it != std::ranges::end(shortname_view))
    {
        return *it;
    }

    throw std::exception();
}
