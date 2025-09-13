module;

export module songs;

import std;
import uni_algo;
import magic_enum;
import util;

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

template <typename VT, std::size_t CAP> struct oversized_array
{
    std::array<VT, CAP> data{};
    std::size_t size;
    constexpr auto begin() const { return data.begin(); }
    constexpr auto end() const { return data.begin() + size; }
};


template <>
struct magic_enum::customize::enum_range<Singer> {
  static constexpr bool is_flags = true;
};

export struct Song
{
    using sv = std::string_view;
    using osv = std::optional<std::string_view>;
    Song(osv jp_name, osv romanji_name, sv name, Singer singer, sv producer, std::chrono::year_month_day published = 0y/0/0, osv disam = std::nullopt) noexcept :
        jp_name(jp_name),
        romanji_name(romanji_name),
        name(name),
        singer(singer),
        producer(producer),
        published(published),
        disambiguation(disam),
        cf_jp_name(jp_name.transform(&util::to_nfkc_casefold)),
        cf_romanji_name(romanji_name.transform(&util::to_nfkc_casefold)),
        cf_name(util::to_nfkc_casefold(name))
    {
    }

    std::optional<std::string_view> jp_name;
    std::optional<std::string_view> romanji_name;
    std::string_view name; // en
    Singer singer;
    std::string_view producer;
    std::chrono::year_month_day published;
    std::optional<std::string_view> disambiguation; // keep last

    std::optional<std::string> cf_jp_name;
    std::optional<std::string> cf_romanji_name;
    std::string cf_name;
};

struct SongStore
{
    std::string foo;
    std::string bar;
};

template<typename T, typename Proj, std::size_t N>
constexpr auto get_sorted_songs(const std::array<T, N>& arr, Proj&& proj) -> std::array<T, N>
{
    std::array<T, N> sorted_arr = arr;
    std::ranges::stable_sort(sorted_arr, std::ranges::less{}, std::forward<Proj>(proj));
    return sorted_arr;
}

export const std::array songs = get_sorted_songs(std::to_array<Song>({
  {"🔪、🔪、🔪", "Knife, Knife, Knife", "Knife, Knife, Knife", Miku, "Kikuo"},
  {std::nullopt, std::nullopt, "1 + 1", Miku, "doriko"},
  {"いーあるふぁんくらぶ", "Ii Aru Fanclub", "1 2 FanClub", duet(Rin, Len), "Mikito-P", 2012y/8/15},
  {"いーあるふぁんくらぶ", "Ii Aru Fanclub", "1 2 FanClub (Chinese ver.)", duet(Rin, Len), "Mikito-P", 2012y/8/15, "Chinese ver."},
  {"二次元ドリームフィーバー", "Nijigen Dream Fever", "2D Dream Fever", Miku, "PolyphonicBranch"},
  {"39", "San Kyuu", "39 (Thank You)", Miku, "sasakure.UK, DECO*27"},
  {std::nullopt, std::nullopt, "8HIT", duet(Rin, Len), "Wonderful☆Opportunity"},
  {std::nullopt, std::nullopt, "ANIMAL", Len, "oQ"},
  {std::nullopt, std::nullopt, "Acceleration (Breeze Remix)", Miku, "Clean Tears, T-ism"},
  {"アゲアゲアゲイン", "Ageage Again", "Ageage Again", Miku, "Mitchie M"},
  {"アカツキアライヴァル", "Akatsuki Arrival", "Daybreak Arrival", duet(Miku, Luka), "Last Note."},
  {"エイリアンエイリアン", "Alien Alien", "Alien Alien", Miku, "NayutalieN"},
  {"すきなことだけでいいです", "Sukina Koto Dake de ii Desu", "All I Need Are Things I Like", Miku, "Pinocchio-P"},
  {"劣等上等", "Rettou Joutou", "BRING IT ON!", duet(Rin, Len), "Giga-P"},
  {std::nullopt, std::nullopt, "Birthday", Miku, "ryuryu"},
  {std::nullopt, std::nullopt, "Blue Star", Miku, "Hachioji-P"},
  {"脳内革命ガール", "Nounai Kakumei Girl", "Brain Revolution Girl", Miku, "MARETU"},
  {"無頼ック自己ライザー", "Buraikku Jikorizer", "Buraikku Jikorizer", Len, "Jesus-P"},
  {"右肩の蝶", "Migikata no Chou", "Butterfly on Your Right Shoulder", Len, "Nori-P", 2009y/3/31},
  {std::nullopt, std::nullopt, "Caged Flower", KAITO, "Re:nG"},
  {std::nullopt, std::nullopt, "Can't Make a Song!!", Miku, "beat_shobon"},
  {"キャットフード", "Cat Food", "Cat Food", Miku, "doriko"},
  {std::nullopt, std::nullopt, "Catch the Wave", Miku, "kz"},
  {std::nullopt, std::nullopt, "Change me", MEIKO, "shu-tP"},
  {"結ンデ開イテ羅刹ト骸", "Musunde Hiraite Rasetsu to Mukuro", "Close and Open, Demons and The Dead", Miku, "Hachi", 2009y/7/5},
  {"カラフル×メロディ", "Colorful × Melody", "Colorful × Melody", duet(Miku, Rin), "Team MOER", 2010y/7/2},
  {"ありふれたせかいせいふく", "Arifureta Sekai Seifuku", "Common World Domination", Miku, "Pinocchio-P"},
  {"カルチャ", "Culture", "Culture", Miku, "Tsumiki"},
  {"積乱雲グラフィティ", "Sekiranun Graffiti", "Cumulonimbus Cloud Graffiti", Miku, "ryo, Dixie Flatline"},
  {std::nullopt, std::nullopt, "Cybernetic", Miku, "CircusP, Yunosuke"},
  {"砂の惑星", "Suna no Wakusei", "DUNE", Miku, "Hachi"},
  {"ダーリンダンス", "Darling Dance", "Darling Dance", Miku, "Kairiki Bear"},
  {"しんでしまうとはなさけない！", "Shinde Shimau to wa Nasakenai!", "Death Should Not Have Taken Thee!", duet(Rin, Len), "Jesus-P"},
  {std::nullopt, std::nullopt, "Decade", Miku, "Dixie Flatline"},
  {"深海少女", "Shinkai Shoujo", "Deep-Sea Girl", Miku, "Yuuyu-P"},
  {"ドクター＝ファンクビート", "Doctor=Funk Beat", "Doctor=Funk Beat", KAITO, "nyanyannya"},
  {"ダブルラリアット", "Double Lariat", "Double Lariat", Luka, "Agoaniki-P", 2009y/2/4},
  {std::nullopt, std::nullopt, "Drag the ground", Miku, "Camellia"},
  {"ゆめゆめ", "Yumeyume", "Dream Dream", Miku, "DECO*27"},
  {"ドリームレス・ドリームス", "Dreamless Dreams", "Dreamless Dreams", Miku, "Harumaki Gohan"},
  {"エゴロック", "Ego Rock", "Ego Rock", Len, "Surii"},
  {"えれくとりっく・えんじぇぅ", "Electric Angel", "Electric Angel", Miku, "Yasuo-P"},
  {"エンヴィキャットウォーク", "Envy Cat Walk", "Envy Cat Walk", Miku, "Tohma"},
  {"それがあなたの幸せとしても", "Sore ga Anata no Shiawase to Shite mo", "Even If It's Your Happiness", Luka, "Heavenz"},
  {std::nullopt, std::nullopt, "Fire◎Flower", Len, "halyosy", 2008y/8/2},
  {"星のかけら", "Hoshi no Kakera", "Fragments of a Star", Miku, "Eiji Hirasawa"},
  {"フロイライン＝ビブリォチカ", "Fräulein=Biblioteca", "Fräulein=Biblioteca", MEIKO, "nyanyannya"},
  {std::nullopt, std::nullopt, "GEDO", Len, "daraku"},
  {"ジェミニ", "Gemini", "Gemini", duet(Rin, Len), "Dixie Flatline"},
  {"天才ロック", "Tensai Rock", "Genius Rock", Rin, "Karasuyasabou"},
  {"幽霊東京", "Yuurei Tokyo", "Ghost City Tokyo", Miku, "Ayase"},
  {"ゴーストルール", "Ghost Rule", "Ghost Rule", Miku, "DECO*27"},
  {std::nullopt, std::nullopt, "Gimme×Gimme", duet(Rin, Miku), "Hachioji-P, Giga-P"},
  {std::nullopt, std::nullopt, "Glass Wall", Miku, "Guitar Hero Piano Zero"},
  {"いいねってYEAH!", "Ii Ne tte YEAH!", "Good is YEAH!", duet(Rin, Len), "Wonderful☆Opportunity"},
  {"ヒバナ", "Hibana", "HIBANA", Miku, "DECO*27"},
  {"命に嫌われている。", "Inochi ni Kirawarete iru.", "Hated by Life Itself", Miku, "Kanzaki Iori"},
  {"ココロ", "Kokoro", "Heart", Rin, "Toraboruta-P", 2008y/3/2},
  {std::nullopt, std::nullopt, "Hello, Worker", Luka, "Hayashikei"},
  {"独りんぼエンヴィー", "Hitorinbo Envy", "Hide and Seek Envy", Miku, "koyori"},
  {std::nullopt, std::nullopt, "Highlight", Miku, "KIRA"},
  {std::nullopt, std::nullopt, "Highway Lover", Luka, "Mikito-P"},
  {"聖槍爆裂ボーイ", "Seisou Bakuretsu Boy", "Holy Lance Explosion Boy", Len, "Rerulili"},
  {"ハイパーリアリティショウ", "Hyper Reality Show", "Hyper Reality Show", Miku, "Utsu-P"},
  {"みくみくにしてあげる♪", "Miku Miku ni Shite Ageru♪", "I'll Miku-Miku You♪ (For Reals)", Miku, "ika", 2007y/9/19},
  {"不適切淑女", "Futekisetsu Shukujo", "Inappropriate Lady", MEIKO, "OSTER project"},
  {std::nullopt, std::nullopt, "Intergalactic Bound", Miku, "Yunosuke, CircusP"},
  {std::nullopt, std::nullopt, "Jump for Joy", duet(Luka, Miku), "EasyPop"},
  {std::nullopt, std::nullopt, "Just Be Friends", Luka, "Dixie Flatline"},
  {std::nullopt, std::nullopt, "Just Be Friends (Eng ver.)", Luka, "Dixie Flatline, Rockleetist"},
  {"からくりピエロ", "Karakuri Pierrot", "Karakuri Pierrot", Miku, "40mP"},
  {std::nullopt, std::nullopt, "Karma", Rin, "CircusP, Creep-P"},
  {"おこちゃま戦争", "Okochama Senso", "Kiddie War", duet(Rin, Len), "Giga"},
  {"キレキャリオン", "Kire Carry On", "Kill Carry On", Miku, "Police Piccadilly"},
  {"気まぐれメルシィ", "Kimagure Mercy", "Kimagure Mercy", Miku, "Hachioji-P"},
  {std::nullopt, std::nullopt, "Last Night, Good Night", Miku, "kz"},
  {"脱法ロック", "Dappo Rock", "Law-evading Rock", Len, "Neru"},
  {"トリノコシティ", "Torinoko City", "Left-Behind City (Urbandonment)", Miku, "40mP", 2010y/7/29},
  {"リテラシー", "Literacy", "Literacy", KAITO, "wotaku"},
  {"こっち向いて Baby", "Kocchi Muite Baby", "Look This Way, Baby", Miku, "ryo", 2010y/7/2},
  {"アイ", "Ai", "Love", Miku, "DECO*27"},
  {"恋色病棟", "Koi Iro Byoutou", "Love Ward", Miku, "OSTER project", 2009y/6/16},
  {"愛言葉", "Ai Kotoba", "Love Words", Miku, "DECO*27"},
  {"恋は戦争", "Koi wa Sensou", "Love is War", Miku, "ryo"},
  {"好き！雪！本気マジック", "Suki! Yuki! Maji Magic", "Love! Snow! Really Magic", Miku, "Mitchie M"},
  {"忘却心中", "Boukyaku Shinjuu", "Lover's Suicide Oblivion", MEIKO, "OPA"},
  {"ラッキー☆オーブ", "Lucky☆Orb", "Lucky☆Orb", Miku, "emon(Tes.)"},
  {"ルカルカ★ナイトフィーバー", "Luka Luka★Night Fever", "Luka Luka★Night Fever", Luka, "samfree", 2009y/2/12},
  {std::nullopt, std::nullopt, "M@GICAL☆CURE! LOVE ♥ SHOT!", Miku, "SAWTOWNE, Sena Kiryuin"},
  {std::nullopt, std::nullopt, "METEOR", Miku, "DIVELA", 2018y/3/28, "Mirai Meteor"},
  {"マージナル", "Marginal", "Marginal", Miku, "OSTER project", 2008y/12/15},
  {"メランコリック", "Melancholic", "Melancholic", Rin, "Junky", 2010y/4/2010},
  {"メルト", "Melt", "Melt", Miku, "ryo", 2007y/12/7},
  {"炉心融解", "Roshin Yuukai", "Meltdown", Rin, "iroha(sasaki)"},
  {"メズマライザー", "Mesmerizer", "Mesmerizer", duet(Miku, Teto), "32ki"},
  {"メテオ", "Meteor", "Meteor", Miku, "John Zeroness", 2011y/3/20, "OG Meteor"},
  {std::nullopt, std::nullopt, "Midnight Surf", duet(MEIKO, KAITO), "asicamo"},
  {std::nullopt, std::nullopt, "Miku", Miku, "Anamanaguchi", 2016y/5/27, "Anamanaguchi"},
  {std::nullopt, std::nullopt, "MikuFiesta", Miku, "AlexTrip Sands"},
  {"月西江", "Yuè Xī Jiāng", "Moon West River", Miku, "SolPie"},
  {"魔法みたいなミュージック！", "Mahou Mitaina Music!", "Music Like Magic!", Miku, "OSTER project"},
  {"Chentaku (Miku Cover)", std::nullopt, "My Love", Miku, "Zizan Razak"},
  {"私の恋はヘルファイア", "Watashi no Koi wa Hellfire", "My Love is Hellfire", MEIKO, "SLAVE.V-V-R"},
  {std::nullopt, std::nullopt, "Never Die", Luka, "Yuyoyuppe"},
  {"新人類", "Shinjinrui", "New Human Race", Rin, "marasy, Jin, kemu"},
  {std::nullopt, std::nullopt, "No Logic", Luka, "JimmyThumb-P"},
  {std::nullopt, std::nullopt, "Nostalogic", MEIKO, "yuukiss"},
  {"ノヴァ", std::nullopt, "Nova", Miku, "*Luna"},
  {std::nullopt, std::nullopt, "Nyanyanyanyanyanyanya!", Miku, "daniwellP"},
  {std::nullopt, std::nullopt, "ODDS&ENDS", Miku, "ryo"},
  {"大江戸ジュリアナイト", "Ohedo Julia-Night", "Ohedo Julia-Night", duet(Miku, KAITO), "Mitchie M"},
  {std::nullopt, std::nullopt, "Over Flow(er)", Miku, "Noz."},
  {std::nullopt, std::nullopt, "Pane dhiria", KAITO, "Shinjou-P", 2010y/1/19},
  {std::nullopt, std::nullopt, "Parades", Miku, "whoo"},
  {"完全性コンプレックス", "Kanzensei Complex", "Perfectionist Complex", Luka, "Yamikuro"},
  {"ピアノ×フォルテ×スキャンダル", "Piano × Forte × Scandal", "Piano × Forte × Scandal", MEIKO, "OSTER project", 2008y/12/19},
  {std::nullopt, std::nullopt, "Plaything", Miku, "Mizu"},
  {"プシ", "Psi", "Psi", Miku, "r-906"},
  {std::nullopt, std::nullopt, "REALITY", duet(MEIKO, KAITO), "Minus-P"},
  {"ロキ", "Roki", "ROKI", duet(Rin, Len), "Mikito-P"},
  {"桜ノ雨", "Sakura no Ame", "Rain of Cherry Blossom Petals", Miku, "halyosy, absorb"},
  {"ラズベリー＊モンスター", "Raspberry＊Monster", "Raspberry＊Monster", Miku, "Honeyworks"},
  {"レッドランドマーカー", "Red Land Marker", "Red Land Marker", MEIKO, "Twinfield"},
  {std::nullopt, std::nullopt, "Reload Words", KAITO, "Sat"},
  {"ラムネイドブルーの憧憬", "Ramunade Blue no Shoukei", "Remade Blue Longing", MEIKO, "Aotokei"},
  {"リモコン", "Rimokon", "Remote Controller", duet(Rin, Len), "Wonderful☆Opportunity"},
  {"ヒビカセ", "Hibikase", "Resonate", Miku, "Giga-P"},
  {"ローリンガール", "Rolling Girl", "Rolling Girl", Miku, "wowaka"},
  {"ロミオとシンデレラ", "Romeo to Cinderella", "Romeo and Cinderella", Miku, "doriko", 2009y/4/5},
  {"四角い地球を丸くする", "Shikakui Chikyuu wo Maruku Suru", "Round Off the Square Earth", Miku, "TOKOTOKO"},
  {std::nullopt, std::nullopt, "SPiCa", Miku, "Toku-P"},
  {std::nullopt, std::nullopt, "Satisfaction", Miku, "kz"},
  {"秘密警察", "Himitsu Keisatsu", "Secret Police", Miku, "Buriru-P", 2010y/11/9},
  {"セカイ", "Sekai", "Sekai", Miku, "kemu, DECO*27"},
  {std::nullopt, std::nullopt, "Sharing The World", Miku, "BIGHEAD, ELEKI, Kei Suzuki"},
  {std::nullopt, std::nullopt, "Sharing The World (Spanish ver.)", Miku, "BIGHEAD, Maubox"},
  {"夜舞うシルエット", "Yomau Silhouette", "Silhouette Dancing in the Night", MEIKO, "Miyamori Bungaku"},
  {std::nullopt, std::nullopt, "Snow Fairy Story", Miku, "40mP"},
  {"スノーマン", "Snowman", "Snowman", KAITO, "halyosy"},
  {"シャボン", "Shabon", "Soap", Miku, "Kuriyama Yuri"},
  {std::nullopt, std::nullopt, "Someday'z Coming", Luka, "Shoten Taro"},
  {"紡唄 -つむぎうた-", "Tsumugi Uta", "Spinning Song", duet(Rin, Len), "DATEKEN", 2009y/2/5},
  {"紡唄 -つむぎうた-", "Tsumugi Uta", "Spinning Song (Chinese Ver.)", duet(Rin, Len), "DATEKEN", 2009y/2/5, "Chinese Ver."},
  {"みかぼし", "Mikaboshi", "Star of Heaven", KAITO, "Satoru Takamura"},
  {"星屑ユートピア", "Hoshikuzu Utopia", "Stardust Utopia", Luka, "otetsu"},
  {std::nullopt, std::nullopt, "Starduster", Miku, "JimmyThumb-P"},
  {"ストリーミングハート", "Streaming Heart", "Streaming Heart", Miku, "DECO*27"},
  {"スイートマジック", "Sweet Magic", "Sweet Magic", Rin, "Junky"},
  {std::nullopt, std::nullopt, "THUNDERBOLT", Miku, "jon-YAKITORY"},
  {"テレキャスタービーボーイ", "Telecaster B Boy", "Telecaster B Boy", Len, "Surii"},
  {std::nullopt, std::nullopt, "Tell Your World", Miku, "kz", 2012y/3/12},
  {std::nullopt, std::nullopt, "Ten Thousand Stars", Miku, "CircusP"},
  {"テオ", "Teo", "Teo", Miku, "Omoi"},
  {"初音ミクの消失 -DEAD END-", "Hatsune Miku no Shoushitsu -DEAD END-", "The Disappearance of Hatsune Miku -DEAD END-", Miku, "cosMo"},
  {"ハジメテノオト", "Hajimete no Oto", "The First Sound", Miku, "malo"},
  {"初音ミクの激唱", "Hatsune Miku no Gekishou", "The Intense Voice of Hatsune Miku", Miku, "cosMo", 2010y/7/9},
  {"白い雪のプリンセスは", "Shiroi Yuki no Princess wa", "The Snow White Princess is", Miku, "Noboru↑-P", 2010y/2/21},
  {"歌に形はないけれど", "Uta ni Katachi wa Nai Keredo", "Though My Song Has No Shape (Chinese Ver.)", Miku, "doriko", 2008y/1/19, "Chinese Ver."},
  {"歌に形はないけれど", "Uta ni Katachi wa Nai Keredo", "Though My Song Has No Shape", Miku, "doriko", 2008y/1/19},
  {"千本桜", "Senbonzakura", "Thousand Cherry Blossoms", Miku, "Kurousa-P", 2011y/9/17},
  {std::nullopt, std::nullopt, "Thousand Little Voices", Miku, "Vault Kid, Flanger Moose"},
  {"千年の独奏歌", "Sennen no Dokusou Ka", "Thousand Year Solo", KAITO, "yanagi-P", 2008y/4/27},
  {std::nullopt, std::nullopt, "Through The Night", Miku, "Slushii"},
  {"東京テディベア", "Tokyo Teddy Bear", "Tokyo Teddy Bear", Rin, "Neru"},
  {"二息歩行", "Nisoku Hokou", "Two Breaths Walking", Miku, "DECO*27"},
  {"裏表ラバーズ", "Ura-omote Lovers", "Two-Sided Lovers", Miku, "wowaka"},
  {"アンハッピーリフレイン", "Unhappy Refrain", "Unhappy Refrain", Miku, "wowaka"},
  {"アンノウン・マザーグース", "Unknown Mother-Goose", "Unknown Mother Goose", Miku, "wowaka"},
  {"ヴァンパイア", "Vampire", "Vampire", Miku, "DECO*27"},
  {"ぽっぴっぽー", "PoPiPo", "Vegetable Juice", Miku, "Lamaze-P", 2008y/12/11},
  {std::nullopt, "Venus di Ujung Jari", "Venus at The Fingertips", Miku, "Mohax-2000", 2011y/6/6},
  {"ビバハピ", "Viva Happy", "Viva Happy", Miku, "Mitchie M"},
  {"ぼかろころしあむ ", std::nullopt, "Vocalo-Colosseum", Rin, "DIVELA"},
  {"ワンダーラスト", "Wanderlast", "Wanderlast", Luka, "sasakure.UK"},
  {"あったかいと", "Attakaito", "Warm Kaito", KAITO, "halyosy"},
  {std::nullopt, std::nullopt, "Weekender Girl", Miku, "kz, Hachioji-P"},
  {"ワールドイズマイン", "World is Mine", "World is Mine", Miku, "ryo"},
  {"ワールズエンド・ダンスホール", "World's End Dancehall", "World's End Dancehall", duet(Miku, Luka), "wowaka"},
  {std::nullopt, std::nullopt, "Yellow", Miku, "kz", 2010y/7/2},
  {std::nullopt, std::nullopt, "celluloid", Miku, "baker"},
  {std::nullopt, std::nullopt, "glow", Miku, "keeno"},
  {std::nullopt, std::nullopt, "imaginary love story", Miku, "Synthion"},
  {std::nullopt, std::nullopt, "letter song", Miku, "doriko", 2008y/6/26},
  {std::nullopt, std::nullopt, "lost and found", Luka, "ashcolor"},
  {std::nullopt, std::nullopt, "magnet", duet(Miku, Luka), "minato"},
  {std::nullopt, std::nullopt, "on the rocks", duet(MEIKO, KAITO), "OSTER Project"},
  {"アングレイデイズ", "Ungray Days", "ungray days", Rin, "Tsumiki"},
  {std::nullopt, std::nullopt, "vivid", duet(Miku, Luka), "Utsu-P, Yuyoyuppe"},

}), &Song::cf_name);

/* There must not be any duplicate songnames in songs. Its sorted, so just check adjacency. */
constexpr auto songs_have_same_names = [](auto l, auto r) constexpr {
    return l.name == r.name && l.disambiguation == r.disambiguation;
};
//static_assert(std::ranges::adjacent_find(songs, songs_have_same_names) == std::ranges::end(songs),
//              std::ranges::adjacent_find(songs, songs_have_same_names)->name);

/* Everything needs a date. Sometimes. */
constexpr auto song_has_no_date = [](const auto& song) constexpr { return song.published == 0y/0/0;};
//static_assert(std::ranges::none_of(songs, song_has_no_date),
//              std::ranges::find_if(songs, song_has_no_date)->name);

/* jp_name shouldn't equal name */
constexpr auto song_has_same_jp_en_name = [](const auto& song) constexpr { return song.jp_name.transform([sn = song.name](auto &jp_name) constexpr -> bool { return jp_name == sn; }).value_or(false); };
//static_assert(std::ranges::none_of(songs, song_has_same_jp_en_name),
//              std::ranges::find_if(songs, song_has_same_jp_en_name)->name);

/* romanji shouldn't equal jp_name */
constexpr auto song_has_same_jp_romanji_name = [](const auto& song) constexpr {
    return song.romanji_name.transform([jp_sn = song.jp_name](auto &romanji_name) constexpr -> bool { return romanji_name == jp_sn; }).value_or(false);
};
//static_assert(std::ranges::none_of(songs, song_has_same_jp_romanji_name),
//              std::ranges::find_if(songs, song_has_same_jp_romanji_name)->name);

export struct AltName
{
    AltName(std::string_view alt_name, std::string_view name) :
        alt_name(alt_name),
        name(name),
        cf_alt_name(util::to_nfkc_casefold(alt_name))
    { }
    std::string_view alt_name;
    std::string_view name;
    std::string cf_alt_name;
};

export const std::array alt_names = get_sorted_songs(std::to_array<AltName>({
            { "Colorful Melody", "Colorful × Melody"},
            { "Colorful x Melody", "Colorful × Melody"},
            { "Fire Flower", "Fire◎Flower"},
            { "FireFlower", "Fire◎Flower"},
            { "Piano Forte Scandal", "Piano × Forte × Scandal"},
            { "Piano x Forte x Scandal", "Piano × Forte × Scandal"},
            { "LLNF", "Luka Luka★Night Fever"},
            { "Luka Luka Night Fever", "Luka Luka★Night Fever"},
        }), &AltName::cf_alt_name);

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

    auto producer_rng = rng | util::make_needle_filter<&Song::producer>(*producer);

    if (std::ranges::distance(producer_rng) == 1)
        return *std::ranges::begin(producer_rng);

    return std::nullopt;
}

export [[nodiscard]] constexpr
std::optional<Song> lookup_song(std::string_view needle, std::optional<std::string_view> producer = std::nullopt)
{
    const auto casefolded_needle = util::to_nfkc_casefold(needle);
    if (auto rng = std::ranges::equal_range(songs, casefolded_needle, std::ranges::less{}, &Song::cf_name);
        !std::ranges::empty(rng))
    {
        return lookup1(std::move(rng), producer);
    }

    /* Romanji */
    if (auto rng = songs | util::make_needle_filter<&Song::cf_romanji_name>(casefolded_needle);
        !std::ranges::empty(rng))
    {
        return lookup1(std::move(rng), producer);
    }

    /* Alt name */
    if (auto alt_rng = alt_names | util::make_needle_filter<&AltName::cf_alt_name>(casefolded_needle);
        !std::ranges::empty(alt_rng))
    {
        if (std::ranges::distance(alt_rng) != 1) return std::nullopt;

        auto rng = songs | util::make_needle_filter<&Song::name>(std::ranges::begin(alt_rng)->name);
        return lookup1(std::move(rng), producer);
    }

    /* Try japanese */
    if (auto rng = songs | util::make_needle_filter<&Song::cf_jp_name>(casefolded_needle);
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
