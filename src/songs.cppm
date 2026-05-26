/*
    Songbot: Hatsune Miku Concert Database for Discord
    Copyright (C) 2025  Andrew Potter

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

module;

export module songs;

import std;
import uni_algo;
import magic_enum;
import util;

using namespace std::literals;

export enum Singer : std::uint32_t {
    NO_VIRTUAL_SINGER = 0,
    Miku  = 1 << 1,
    Rin   = 1 << 2,
    Len   = 1 << 3,
    Luka  = 1 << 4,
    MEIKO = 1 << 5,
    KAITO = 1 << 6,
    Teto  = 1 << 7,
    Gumi  = 1 << 8,
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

std::string singer_to_emoji(Singer s)
{
    std::ostringstream ss;
    if (magic_enum::enum_flags_test(s, Miku)) {
        ss << "<:miku:235217471982927874>";
    }
    if (magic_enum::enum_flags_test(s, Rin)) {
        ss << "<:rin:235215581278633984>";
    }
    if (magic_enum::enum_flags_test(s, Len)) {
        ss << "<:len:235217877446295553>";
    }
    if (magic_enum::enum_flags_test(s, Luka)) {
        ss << "<:luka:235216119403773952>";
    }
    if (magic_enum::enum_flags_test(s, MEIKO)) {
        ss << "<:meikolove:314486872317493260>";
    }
    if (magic_enum::enum_flags_test(s, KAITO)) {
        ss << "<:kaito:254038928921722880>";
    }
    if (magic_enum::enum_flags_test(s, Teto)) {
        ss << "<:tetolove:519149276907962388>";
    }
    if (magic_enum::enum_flags_test(s, Gumi)) {
       ss << "<:gumiblush:602030455671488522>";
    }
    return ss.str();
}

export struct Song
{
    using sv = std::string_view;
    using osv = std::optional<std::string_view>;
    using oui = std::optional<std::uint64_t>;
    constexpr Song(osv jp_name, osv romanji_name, sv name, Singer singer, sv producer, oui db_id = std::nullopt, osv disam = std::nullopt, std::optional<Singer> minor_roles = std::nullopt, osv emoji_override = std::nullopt) noexcept :
        jp_name(jp_name),
        romanji_name(romanji_name),
        name(name),
        singer(singer),
        producer(producer),
        vocadb_id(db_id),
        disambiguation(disam),
        minor_roles(minor_roles),
        emoji_override(emoji_override)
    {
    }
    constexpr Song() noexcept = default; // Needed for util::materialize
    std::optional<std::string_view> jp_name;
    std::optional<std::string_view> romanji_name;
    std::string_view name; // en
    Singer singer;
    std::string_view producer;
    std::optional<std::uint64_t> vocadb_id;
    std::optional<std::string_view> disambiguation;
    std::optional<Singer> minor_roles;
    std::optional<std::string_view> emoji_override; // keep last

    std::optional<std::string_view> cf_jp_name;
    std::optional<std::string_view> cf_romanji_name;
    std::string_view cf_name;
    std::string_view cf_producer;
};


template<typename T, typename Proj, std::size_t N>
constexpr auto get_sorted_songs(const std::array<T, N>& arr, Proj&& proj) -> std::array<T, N>
{
    std::array<T, N> sorted_arr = arr;
    std::ranges::stable_sort(sorted_arr, std::ranges::less{}, std::forward<Proj>(proj));
    return sorted_arr;
}

using std::nullopt;
/* Creates songs without casefolded fields */
constexpr std::vector<Song> generate_songs_incomplete()
{
    std::vector<Song> res = {
  {"🔪、🔪、🔪", "Knife, Knife, Knife", "Knife, Knife, Knife", Miku, "Kikuo", 404329},
  {nullopt, nullopt, "1 + 1", Miku, "doriko", 118797},
  {"いーあるふぁんくらぶ", "Ii Aru Fanclub", "1 2 FanClub", duet(Rin, Len), "Mikito-P", 149312},
  {"二次元ドリームフィーバー", "Nijigen Dream Fever", "2D Dream Fever", Miku, "PolyphonicBranch", 9376},
  {"39", "San Kyuu", "39 (Thank You)", Miku, "sasakure.UK, DECO*27", 14480, nullopt, nullopt, "<a:mikuarigathanks:941692452794933248>"},
  {nullopt, nullopt, "8HIT", duet(Rin, Len), "Wonderful☆Opportunity", 9210},
  {nullopt, nullopt, "ANIMAL", Len, "oQ", 359211, "oQ"},
  {nullopt, nullopt, "Acceleration (Breeze Remix)", Miku, "Clean Tears, T-ism", 188729},
  {"アゲアゲアゲイン", "Ageage Again", "Ageage Again", Miku, "Mitchie M", 38420},
  {"アカツキアライヴァル", "Akatsuki Arrival", "Daybreak Arrival", duet(Miku, Luka), "Last Note.", 9553},
  {"エイリアンエイリアン", "Alien Alien", "Alien Alien", Miku, "NayutalieN", 106773},
  {"すきなことだけでいいです", "Sukina Koto Dake de ii Desu", "All I Need Are Things I Like", Miku, "Pinocchio-P", 124436},
  {"劣等上等", "Rettou Joutou", "BRING IT ON!", duet(Rin, Len), "Giga-P", 192291},
  {nullopt, nullopt, "Birthday", Miku, "ryuryu", 127370},
  {nullopt, nullopt, "Blue Star", Miku, "Hachioji-P", 105439},
  {"脳内革命ガール", "Nounai Kakumei Girl", "Brain Revolution Girl", Miku, "MARETU", 38835},
  {"無頼ック自己ライザー", "Buraikku Jikorizer", "Buraikku Jikorizer", Len, "Jesus-P", 97905},
  {"右肩の蝶", "Migikata no Chou", "Butterfly on Your Right Shoulder", Len, "Nori-P", 1952},
  {nullopt, nullopt, "Caged Flower", KAITO, "Re:nG", 35256},
  {nullopt, nullopt, "Can't Make a Song!!", Miku, "beat_shobon", 182121},
  {"キャットフード", "Cat Food", "Cat Food", Miku, "doriko", 1024},
  {nullopt, nullopt, "Catch the Wave", Miku, "kz", 251481},
  {nullopt, nullopt, "Change me", MEIKO, "shu-tP", 3024},
  {"結ンデ開イテ羅刹ト骸", "Musunde Hiraite Rasetsu to Mukuro", "Close and Open, Demons and The Dead", Miku, "Hachi", 2982},
  {"カラフル×メロディ", "Colorful × Melody", "Colorful × Melody", duet(Miku, Rin), "Team MOER", 2920},
  {"ありふれたせかいせいふく", "Arifureta Sekai Seifuku", "Common World Domination", Miku, "Pinocchio-P", 13351},
  {"カルチャ", "Culture", "Culture", Miku, "Tsumiki", 445823},
  {"積乱雲グラフィティ", "Sekiranun Graffiti", "Cumulonimbus Cloud Graffiti", Miku, "ryo, Dixie Flatline", 2879},
  {nullopt, nullopt, "Cybernetic", Miku, "CircusP, Yunosuke", 178125},
  {"砂の惑星", "Suna no Wakusei", "DUNE", Miku, "Hachi", 157860},
  {"ダーリンダンス", "Darling Dance", "Darling Dance", Miku, "Kairiki Bear", 293286},
  {"しんでしまうとはなさけない！", "Shinde Shimau to wa Nasakenai!", "Death Should Not Have Taken Thee!", duet(Rin, Len), "Jesus-P", 17678},
  {nullopt, nullopt, "Decade", Miku, "Dixie Flatline", 183093},
  {"深海少女", "Shinkai Shoujo", "Deep-Sea Girl", Miku, "Yuuyu-P", 8735},
  {"ドクター＝ファンクビート", "Doctor=Funk Beat", "Doctor=Funk Beat", KAITO, "nyanyannya", 90017},
  {"ダブルラリアット", "Double Lariat", "Double Lariat", Luka, "Agoaniki-P", 3129, nullopt, nullopt, "<a:doublelariat:394562140096167937>"},
  {nullopt, nullopt, "Drag the ground", Miku, "Camellia", 51667, nullopt, nullopt, "<:racingmikuhappy:805737573653544972>"},
  {"ゆめゆめ", "Yumeyume", "Dream Dream", Miku, "DECO*27", 8290},
  {"ドリームレス・ドリームス", "Dreamless Dreams", "Dreamless Dreams", Miku, "Harumaki Gohan", 156001},
  {"エゴロック", "Ego Rock", "Ego Rock", Len, "Surii", 202936},
  {"えれくとりっく・えんじぇぅ", "Electric Angel", "Electric Angel", Miku, "Yasuo-P", 230750},
  {"エンヴィキャットウォーク", "Envy Cat Walk", "Envy Cat Walk", Miku, "Tohma", 453},
  {"それがあなたの幸せとしても", "Sore ga Anata no Shiawase to Shite mo", "Even If It's Your Happiness", Luka, "Heavenz", 26010},
  {nullopt, nullopt, "Fire◎Flower", Len, "halyosy", 6387},
  {"星のかけら", "Hoshi no Kakera", "Fragments of a Star", Miku, "Eiji Hirasawa", 293725},
  {"フロイライン＝ビブリォチカ", "Fräulein=Biblioteca", "Fräulein=Biblioteca", MEIKO, "nyanyannya", 82385},
  {nullopt, nullopt, "GEDO", Len, "daraku", 443372},
  {"ジェミニ", "Gemini", "Gemini", duet(Rin, Len), "Dixie Flatline", 8093},
  {"天才ロック", "Tensai Rock", "Genius Rock", Rin, "Karasuyasabou", 173475},
  {"幽霊東京", "Yuurei Tokyo", "Ghost City Tokyo", Miku, "Ayase", 262740},
  {"ゴーストルール", "Ghost Rule", "Ghost Rule", Miku, "DECO*27", 112085},
  {nullopt, nullopt, "Gimme×Gimme", duet(Rin, Miku), "Hachioji-P, Giga-P", 246033},
  {nullopt, nullopt, "Glass Wall", Miku, "Guitar Hero Piano Zero", 50132},
  {"いいねってYEAH!", "Ii Ne tte YEAH!", "Good is YEAH!", duet(Rin, Len), "Wonderful☆Opportunity", 415813},
  {"ヒバナ", "Hibana", "HIBANA", Miku, "DECO*27", 164074},
  {"命に嫌われている。", "Inochi ni Kirawarete iru.", "Hated by Life Itself", Miku, "Kanzaki Iori", 164273},
  {"ココロ", "Kokoro", "Heart", Rin, "Toraboruta-P", 1357 },
  {nullopt, nullopt, "Hello, Worker", Luka, "Hayashikei", 550},
  {"独りんぼエンヴィー", "Hitorinbo Envy", "Solitary Envy", Miku, "koyori", 18479},
  {nullopt, nullopt, "Highlight", Miku, "KIRA", 304790},
  {nullopt, nullopt, "Highway Lover", Luka, "Mikito-P", 239803},
  {"聖槍爆裂ボーイ", "Seisou Bakuretsu Boy", "Holy Lance Explosion Boy", Len, "Rerulili", 38393},
  {"ハイパーリアリティショウ", "Hyper Reality Show", "Hyper Reality Show", Miku, "Utsu-P", 232031},
  {"みくみくにしてあげる♪", "Miku Miku ni Shite Ageru♪", "I'll Miku-Miku You♪ (For Reals)", Miku, "MOSAIC.WAV×ika", 3853},
  {"不適切淑女", "Futekisetsu Shukujo", "Inappropriate Lady", MEIKO, "OSTER project", 183348},
  {nullopt, nullopt, "Intergalactic Bound", Miku, "Yunosuke, CircusP", 573584},
  {nullopt, nullopt, "Jump for Joy", duet(Luka, Miku), "EasyPop", 234902},
  {nullopt, nullopt, "Just Be Friends", Luka, "Dixie Flatline", 1360},
  {"からくりピエロ", "Karakuri Pierrot", "Karakuri Pierrot", Miku, "40mP", 1363},
  {nullopt, nullopt, "Karma", Rin, "CircusP, Creep-P", 114805},
  {"おこちゃま戦争", "Okochama Senso", "Kiddie War", duet(Rin, Len), "Giga", 44190},
  {"キレキャリオン", "Kire Carry On", "Kill Carry On", Miku, "Police Piccadilly", 143259},
  {"気まぐれメルシィ", "Kimagure Mercy", "Kimagure Mercy", Miku, "Hachioji-P", 121935},
  {nullopt, nullopt, "Last Night, Good Night", Miku, "kz", 2443},
  {"脱法ロック", "Dappo Rock", "Law-evading Rock", Len, "Neru", 127169},
  {"トリノコシティ", "Torinoko City", "Left-Behind City (Urbandonment)", Miku, "40mP", 1359},
  {"リテラシー", "Literacy", "Literacy", KAITO, "wotaku", 344890},
  {"こっち向いて Baby", "Kocchi Muite Baby", "Look This Way, Baby", Miku, "ryo", 2904},
  {"アイ", "Ai", "Love", Miku, "DECO*27", 215656, nullopt, nullopt, "<a:mikusnowrng:926685701494435870>"},
  {"恋色病棟", "Koi Iro Byoutou", "Love Ward", Miku, "OSTER project", 3015},
  {"愛言葉", "Ai Kotoba", "Love Words", Miku, "DECO*27", 3019},
  {"恋は戦争", "Koi wa Sensou", "Love is War", Miku, "ryo", 1320},
  {"好き！雪！本気マジック", "Suki! Yuki! Maji Magic", "Love! Snow! Really Magic", Miku, "Mitchie M", 47354, nullopt, nullopt, "<a:mikusnowrng:926685701494435870>"},
  {"忘却心中", "Boukyaku Shinjuu", "Lover's Suicide Oblivion", MEIKO, "OPA", 9000},
  {"ラッキー☆オーブ", "Lucky☆Orb", "Lucky☆Orb", Miku, "emon(Tes.)", 217889, nullopt, nullopt, "<:mikuwink:607623904797786152>"},
  {"ルカルカ★ナイトフィーバー", "Luka Luka★Night Fever", "Luka Luka★Night Fever", Luka, "samfree", 1435},
  {nullopt, nullopt, "M@GICAL☆CURE! LOVE ♥ SHOT!", Miku, "SAWTOWNE", 540085},
  {nullopt, nullopt, "METEOR", Miku, "DIVELA", 191838, "Mirai Meteor"},
  {"マージナル", "Marginal", "Marginal", Miku, "OSTER project", 2949},
  {"メランコリック", "Melancholic", "Melancholic", Rin, "Junky", 4129},
  {"メルト", "Melt", "Melt", Miku, "ryo", 1322},
  {"炉心融解", "Roshin Yuukai", "Meltdown", Rin, "iroha(sasaki)", 3022},
  {"メズマライザー", "Mesmerizer", "Mesmerizer", duet(Miku, Teto), "32ki", 610187},
  {"メテオ", "Meteor", "Meteor", Miku, "John Zeroness", 8175, "OG Meteor"},
  {nullopt, nullopt, "Midnight Surf", duet(MEIKO, KAITO), "asicamo", 435789},
  {nullopt, nullopt, "Miku", Miku, "Anamanaguchi", 115016, "Anamanaguchi"},
  {nullopt, nullopt, "MikuFiesta", Miku, "AlexTrip Sands", 256585, nullopt, nullopt, "<:mikufiesta:1404333620377817088>"},
  {"月西江", "Yuè Xī Jiāng", "Moon West River", Miku, "SolPie", 237976},
  {"魔法みたいなミュージック！", "Mahou Mitaina Music!", "Music Like Magic!", Miku, "OSTER project", 199152},
  {"Chentaku (Miku Cover)", nullopt, "My Love", Miku, "SonaOne", 177679},
  {"私の恋はヘルファイア", "Watashi no Koi wa Hellfire", "My Love is Hellfire", MEIKO, "SLAVE.V-V-R", 363931},
  {nullopt, nullopt, "Never Die", Luka, "Yuyoyuppe", 220959},
  {"新人類", "Shinjinrui", "New Human Race", Rin, "marasy, Jin, kemu", 480295},
  {nullopt, nullopt, "No Logic", Luka, "JimmyThumb-P", 1513},
  {nullopt, nullopt, "Nostalogic (MEIKO-SAN mix)", MEIKO, "yuukiss", 63663},
  {"ノヴァ6", nullopt, "Nova", Miku, "*Luna", 360978},
  {nullopt, nullopt, "Nyanyanyanyanyanyanya!", Miku, "daniwellP", 123},
  {nullopt, nullopt, "ODDS&ENDS", Miku, "ryo", 15662},
  {"大江戸ジュリアナイト", "Ohedo Julia-Night", "Ohedo Julia-Night", duet(Miku, KAITO), "Mitchie M", 164109},
  {nullopt, nullopt, "Over Flow(er)", Miku, "Noz.", 772578},
  {nullopt, nullopt, "Pane dhiria", KAITO, "Shinjou-P", 381},
  {nullopt, nullopt, "Parades", Miku, "whoo", 1141},
  {"完全性コンプレックス", "Kanzensei Complex", "Perfectionist Complex", Luka, "Yamikuro", 29120},
  {"ピアノ×フォルテ×スキャンダル", "Piano × Forte × Scandal", "Piano × Forte × Scandal", MEIKO, "OSTER project", 9035},
  {nullopt, nullopt, "Plaything", Miku, "Mizu", 483001},
  {"プシ", "Psi", "Psi", Miku, "r-906", 460547},
  {nullopt, nullopt, "REALITY", duet(MEIKO, KAITO), "Minus-P", 233962},
  {"ロキ", "Roki", "ROKI", duet(Rin, Len), "Mikito-P", 185363},
  {"桜ノ雨", "Sakura no Ame", "Sakura Rain", Miku, "halyosy, absorb", 8741},
  {"ラズベリー＊モンスター", "Raspberry＊Monster", "Raspberry＊Monster", Miku, "Honeyworks", 28549},
  {"レッドランドマーカー", "Red Land Marker", "Red Land Marker", MEIKO, "Twinfield", 450680},
  {nullopt, nullopt, "Reload Words", KAITO, "Sat", 26336},
  {"ラムネイドブルーの憧憬", "Ramunade Blue no Shoukei", "Remade Blue Longing", MEIKO, "Aotokei", 169614},
  {"リモコン", "Rimokon", "Remote Controller", duet(Rin, Len), "Wonderful☆Opportunity", 3387},
  {"ヒビカセ", "Hibikase", "Resonate", Miku, "Giga-P", 63276},
  {"ローリンガール", "Rolling Girl", "Rolling Girl", Miku, "wowaka", 1501},
  {"ロミオとシンデレラ", "Romeo to Cinderella", "Romeo and Cinderella", Miku, "doriko", 1032},
  {"四角い地球を丸くする", "Shikakui Chikyuu wo Maruku Suru", "Round Off the Square Earth", Miku, "TOKOTOKO", 178433, nullopt, nullopt, "<a:mikusnowrng:926685701494435870>"},
  {nullopt, nullopt, "SPiCa", Miku, "Toku-P", 1516},
  {nullopt, nullopt, "Satisfaction", Miku, "kz", 121110},
  {"秘密警察", "Himitsu Keisatsu", "Secret Police", Miku, "Buriru-P", 373},
  {"セカイ", "Sekai", "Sekai", Miku, "kemu, DECO*27", 290231},
  {nullopt, nullopt, "Sharing The World", Miku, "BIGHEAD", 66126},
  {"夜舞うシルエット", "Yomau Silhouette", "Silhouette Dancing in the Night", MEIKO, "Miyamori Bungaku", 542682},
  {nullopt, nullopt, "Snow Fairy Story", Miku, "40mP", 79094, nullopt, nullopt, "<a:mikusnowrng:926685701494435870>"},
  {"スノーマン", "Snowman", "Snowman", KAITO, "halyosy", 65736},
  {"シャボン", "Shabon", "Soap", Miku, "Kuriyama Yuri", 239350},
  {nullopt, nullopt, "Someday'z Coming", Luka, "Shoten Taro", 258338},
  {"紡唄 -つむぎうた-", "Tsumugi Uta", "Spinning Song", duet(Rin, Len), "DATEKEN", 2285},
  {"みかぼし", "Mikaboshi", "Star of Heaven", KAITO, "Satoru Takamura", 531972},
  {"星屑ユートピア", "Hoshikuzu Utopia", "Stardust Utopia", Luka, "otetsu", 1047},
  {nullopt, nullopt, "Starduster", Miku, "JimmyThumb-P", 2913},
  {"ストリーミングハート", "Streaming Heart", "Streaming Heart", Miku, "DECO*27", 48029},
  {"スイートマジック", "Sweet Magic", "Sweet Magic", Rin, "Junky", 11828},
  {nullopt, nullopt, "THUNDERBOLT", Miku, "jon-YAKITORY", 468978},
  {"テレキャスタービーボーイ", "Telecaster B Boy", "Telecaster B Boy", Len, "Surii", 233017},
  {nullopt, nullopt, "Tell Your World", Miku, "kz", 399060},
  {nullopt, nullopt, "Ten Thousand Stars", Miku, "CircusP", 247663},
  {"テオ", "Teo", "Teo", Miku, "Omoi", 161199},
  {"初音ミクの消失 -DEAD END-", "Hatsune Miku no Shoushitsu -DEAD END-", "The Disappearance of Hatsune Miku -DEAD END-", Miku, "cosMo", 2925},
  {"ハジメテノオト", "Hajimete no Oto", "The First Sound", Miku, "malo", 230107},
  {"初音ミクの激唱", "Hatsune Miku no Gekishou", "The Intense Voice of Hatsune Miku", Miku, "cosMo", 2927},
  {"白い雪のプリンセスは", "Shiroi Yuki no Princess wa", "The Snow White Princess is", Miku, "Noboru↑-P", 3312},
  {"歌に形はないけれど", "Uta ni Katachi wa Nai Keredo", "Though My Song Has No Shape", Miku, "doriko", 2322},
  {"千本桜", "Senbonzakura", "Thousand Cherry Blossoms", Miku, "Kurousa-P", 8394},
  {nullopt, nullopt, "Thousand Little Voices", Miku, "Vault Kid, Flanger Moose", 304504},
  {"千年の独奏歌", "Sennen no Dokusou Ka", "Thousand Year Solo", KAITO, "yanagi-P", 3155},
  {nullopt, nullopt, "Through The Night", Miku, "Slushii", 193831},
  {"東京テディベア", "Tokyo Teddy Bear", "Tokyo Teddy Bear", Rin, "Neru", 555},
  {"二息歩行", "Nisoku Hokou", "Two Breaths Walking", Miku, "DECO*27", 5859, nullopt, nullopt, "<a:TwoBreathHeart:841007262964121630>"},
  {"裏表ラバーズ", "Ura-omote Lovers", "Two-Sided Lovers", Miku, "wowaka", 1508},
  {"アンハッピーリフレイン", "Unhappy Refrain", "Unhappy Refrain", Miku, "wowaka", 1500},
  {"アンノウン・マザーグース", "Unknown Mother-Goose", "Unknown Mother-Goose", Miku, "wowaka", 164107},
  {"ヴァンパイア", "Vampire", "Vampire", Miku, "DECO*27", 321205},
  {"ぽっぴっぽー", "PoPiPo", "Vegetable Juice", Miku, "Lamaze-P", 4083},
  {nullopt, "Venus di Ujung Jari", "Venus at The Fingertips", Miku, "Mohax-2000", 7774},
  {"ビバハピ", "Viva Happy", "Viva Happy", Miku, "Mitchie M", 35603, nullopt, nullopt, "<:mikuhappy:658349436375793670>"},
  {"ぼかろころしあむ ", nullopt, "Vocalo-Colosseum", Rin, "DIVELA", 199492},
  {"ワンダーラスト", "Wanderlast", "Wanderlast", Luka, "sasakure.UK", 3254},
  {"あったかいと", "Attakaito", "Warm Kaito", KAITO, "halyosy", 107188},
  {nullopt, nullopt, "Weekender Girl", Miku, "kz, Hachioji-P", 15047},
  {"ワールドイズマイン", "World is Mine", "World is Mine", Miku, "ryo", 1326, nullopt, nullopt, "<:mikutriumph:510922356739276800>"},
  {"ワールズエンド・ダンスホール", "World's End Dancehall", "World's End Dancehall", duet(Miku, Luka), "wowaka", 20},
  {nullopt, nullopt, "Yellow", Miku, "kz", 2905},
  {nullopt, nullopt, "celluloid", Miku, "baker", 6489},
  {nullopt, nullopt, "glow", Miku, "keeno", 1797},
  {nullopt, nullopt, "imaginary love story", Miku, "Synthion", 481543},
  {nullopt, nullopt, "letter song", Miku, "doriko", 1077},
  {nullopt, nullopt, "lost and found", Luka, "ashcolor", 43499, nullopt, Miku},
  {nullopt, nullopt, "magnet", duet(Miku, Luka), "minato", 5166},
  {nullopt, nullopt, "on the rocks", duet(MEIKO, KAITO), "OSTER Project", 203921},
  {"アングレイデイズ", "Ungray Days", "ungray days", Rin, "Tsumiki", 282018},
  {nullopt, nullopt, "vivid", duet(Miku, Luka), "Utsu-P, Yuyoyuppe", 306270},
  {nullopt, nullopt, "Sweet Devil", Miku, "Hachioji-P", 1383},
  {"どうぶつ占い", "Doubutsu Uranai", "Animal Fortune-telling", Miku, "Scop", 5393},
  {nullopt, nullopt, "erase or zero", duet(Len,KAITO), "Crystal-P", 8247},
  {"スキキライ", "Suki Kirai", "Love-Hate", duet(Rin,Len), "HoneyWorks", 8739},
  {nullopt, nullopt, "shake it!", duet(Miku,Rin,Len), "emon(Tes.)", 11593},
  {nullopt, nullopt, "Leia", Luka, "Yuyoyuppe", 4980},
  {nullopt, nullopt, "FREELY TOMORROW", Miku, "Mitchie M", 5364},
  {nullopt, nullopt, "1/6 -out of the gravity-", Miku, "Vocaliod-P", 8246},
  {"カゲロウデイズ", "Kagerou Deizu", "Kagerou Daze", Miku, "Jin", 4979},
  {"心臓デモクラシー", "Shinzou Demokurashii", "Heart Democracy", Miku, "Mikito-P", 8809},
  {"ワンダーランドと羊の歌", "Wandaarando to Hitsuji no Uta", "Wonderland and the Sheep's Song", Miku, "Hachi", 2988},
  {nullopt, nullopt, "EARTH DAY", Miku, "HarryP", 323568},
  {"はじめまして地球人さん", "Hajimemashite Chikyuujin-san", "Nice to Meet You, Mr. Earthling", Miku, "Pinocchio-P", 68091},
  {"恋愛裁判", "Ren'ai Saiban", "Love Trial", Miku, "40mP", 57519},
  {"ロストワンの号哭", "Rosuto Wan no Goukoku", "Lost One's Weeping", Rin, "Neru", 19094},
  {"愛Dee", nullopt, "Ai Dee", duet(Miku,Luka), "Mitchie M", 13086},
  {nullopt, nullopt, "Packaged", Miku, "kz", 100671},
  {nullopt, nullopt, "Hand in Hand", Miku, "kz", 89726},
  {"39みゅーじっく！", "39みゅーじっく", "39 Music!", Miku, "Mikito-P", 127519, nullopt, nullopt , "<:makuharichan:630043704501075968>"},
  {nullopt, nullopt, "Strangers", Miku, "Heavenz", 12322},
  {"すろぉもぉしょん", nullopt, "SLoWMoTIoN", Miku, "Pinocchio-P", 56903},
  {"タイムマシン", nullopt, "Time Machine", Miku, "40mP", 1354},
  {"どりーみんチュチュ", nullopt, "Dreamin Chuchu", Luka, "emon(Tes.)", 47401, nullopt, duet(Miku,Rin), "<:chuchu:317055647826837504>"},
  {nullopt, nullopt, "Calc.", Miku, "JimmyThumb-P", 7801},
  {"ウミユリ海底譚", "Umiyuri Kaiteitan", "Tale of the Deep-sea Lily", Miku, "n-buna", 49871},
  {"テレカクシ思春期", "Terekakushi Shishunki", "Embarrassment-Hiding Adolescence", Len, "HoneyWorks", 42649},
  {nullopt, nullopt, "Baby Maniacs -Eight Mix-", Miku, "Hachioji-P", 126674},
  {nullopt, nullopt, "ray", Miku, "BUMP OF CHICKEN", 404792},
  {"なりすましゲンガー", "Narisumashi Genga", "Doubleganger", duet(Miku,Rin), "KulfiQ", 1932},
  {nullopt, nullopt, "Singularity", Miku, "keisei", 155305},
  {"ツギハギスタッカート", "Tsugihagi Staccato", "Patchwork Staccato", Miku, "toa", 58632},
  {"サイハテ", "Saihate", "The Farthest Ends", Miku, "Kobayashi Onyx", 459},
  {nullopt, nullopt, "TODAY THE FUTURE", Miku, "HarryP", 159554},
  {nullopt, nullopt, "DECORATOR", Miku, "kz, livetune", 45245, nullopt, duet(Rin,Len,Luka,MEIKO,KAITO)},
  {"孤独の果て", "Kodoku no Hate", "Solitude's End", Rin, "Hikarisyuyo", 18083},
  {"リバースユニバース", nullopt, "Reverse Universe", Miku, "NayutalieN", 238956},
  {"グリーンライツ・セレナーデ", nullopt, "Greenlights Serenade", Miku, "Omoi", 186877, nullopt, nullopt, "<a:mikuhyperwota:696421739298816020>"},
  {"愛の詩", "Ai no Uta", "Love Song", Miku, "LamazeP", 42733},
  {"快晴", "Kaisei", "Kaisei", Miku, "Orangestar", 164111},
  {"深海シティアンダーグラウンド", "Shinkai City Underground", "Deep Sea City Underground", Rin, "TanakaB", 11073},
  {"メインキャラクター", nullopt, "Main Character", Len, "*Luna", 123940},
  {"ある計画は今も密かに", "Aru Keikaku wa Ima mo Hisoka ni", "A Plan Is Still In Progress Covertly", Miku, "Shinra", 229183},
  {"ぶれないアイで", "Burenai ai de", "Burenai ai de", Miku, "Mitchie M", 66265},
  {"僕が夢を捨てて大人になるまで", "Boku ga Yume o Sutete Otona ni Naru made", "Until I throw away my dreams and become an adult", Miku, "Kasamura Tota", 207476},
  {"ブレス・ユア・ブレス", nullopt, "Bless Your Breath", Miku, "Takeaki Wada", 234901},
  {"太陽系デスコ", "Taiyoukei Desuko", "Solar System Disco", Miku, "NayutalieN", 773190},
  {nullopt, nullopt, "YY", Miku, "23.exe", 256450, nullopt, nullopt, "<a:mikupolydab:729383800525815888>"},
  {"まるいうなばら", "Marui Unabara", "Spheric Ocean", Miku, "GoBS", 269651},
  {nullopt, nullopt, "Amazing Dolce", duet(MEIKO,Rin,Len), "Hitoshizuku-P×Yama△", 121116},
  {"きみとぼくのレゾナンス", "Kimi to Boku no Rezonansu", "Resonance Between You and Me", MEIKO, "Nanameue-P", 284994},
  {"キミペディア", nullopt, "Kimipedia", duet(Rin,Len), "Junky", 176937},
  {"愛されなくても君がいる", "Aisarenakute mo Kimi ga Iru", "Because You're Here", Miku, "Pinocchio-P", 284993},
  {"え？あぁ、そう。", "E? Aa, Sou.", "Hm? Ah, Yes.", Miku, "Chouchou-P", 2716},
  {"ぽかぽかの星", "Pokapoka no Hoshi", "Poka Poka Planet", Miku, "Harumaki Gohan", 261660, nullopt, nullopt, "<:mikusip:657898170411515904>"},
  {"アルビノ", nullopt, "Albino", Miku, "buzzG", 1061},
  {"アルビノ -revive-", nullopt, "Albino -revive-", Miku, "buzzG", 247035},
  {"テルミーアンサー", nullopt, "Tell Me Answer", Rin, "kinoshita", 266250},
  {"星空クロノグラフ", "Hoshizora Chronograph", "Chronograph in the Starry Sky", MEIKO, "MINO-U", 83820},
  {nullopt, nullopt, "First Note", Miku, "blues", 330805},
  {"サンドリヨン", nullopt, "Cendrillon", duet(Miku,KAITO), "Signal-P", 7238},
  {"レイニースノードロップ", nullopt, "Rainy Snowdrop", KAITO, "Re:nG", 343869},
  {"インタビュア", nullopt, "Interviewer", Luka, "Kuwagata-P", 9538},
  {"初音天地開闢神話", "Hatsune Tenchikaibyaku Shinwa", "Hatsune Creation Myth", Miku, "cosMo", 343868},
  {"ネクストネスト", nullopt, "Next Nest", Miku, "TENKOMORI", 59428},
  {nullopt, nullopt, "FLASH", KAITO, "Kashii Moimi", 315565},
  {"#心がどっか寂しいんだ", "＃Kokoro ga Dokka Sabishiinda", "＃I Feel Kinda Lonely", Len, "Kanzaki Iori", 289363},
  {nullopt, nullopt, "Loading Memories", Miku, "Sekikomi Gohan", 388152},
  {"フューチャー・イヴ", nullopt, "FUTURE EVE", Miku, "sasakure.UK", 391129},
  {nullopt, nullopt, "Blessing", duet(Miku,Luka,Rin,Len,KAITO,MEIKO), "halyosy", 50703},
  {"すーぱーぬこになれんかった", "Suupaa Nuko ni Narenkatta", "I Couldn't Become a Super Cat After All", Len, "Mafumafu", 228773, nullopt, Rin},
  {nullopt, nullopt, "Snowmix♪", Miku, "marasy", 460669},
  {"神っぽいな", "Kamippoi na", "God-ish", Miku, "Pinocchio-P", 354245},
  {"ヘッジホッグ", nullopt, "Hedgehog", Rin, "Noz.", 329458},
  {"king妃jack躍", "king Ki jack Yaku", "King Queen Jack Dance", Miku, "Miyamori Bungaku", 471960},
  {"抜錨", "Batsubyou", "Weigh Anchor", Luka, "Nanahoshi Kangengakudan", 173702},
  {"敗走", nullopt, "Haisou", KAITO, "Kasamura Tota", 262958},
  {nullopt, nullopt, "drop pop candy", duet(Rin,Luka), "Giga", 60953},
  {"フェレス", nullopt, "Pheles", duet(Miku,MEIKO), "Kuriyama Yuri", 393333},
  {"ブループラネット", nullopt, "Blue Planet", Miku, "DECO*27", 525396},
  {"Birthday Song for ミク", nullopt, "Birthday Song for Miku", duet(Rin,Len,Luka,MEIKO,KAITO), "Mitchie M", 14339},
  {nullopt, nullopt, "HERO", Miku, "Ayase", 501613},
  {"ブリキノダンス", "Buriki no Dansu", "Tinplate's Dance", Miku, "Hinata Electric Works", 24149},
  {"混沌ブギ", nullopt, "Konton Boogie", Miku, "jon-YAKITORY", 525760},
  {nullopt, nullopt, "SUPERHERO", Len, "Mellowcle", 580445},
  {nullopt, nullopt, "Call!!", KAITO, "Matsubi", 503050},
  {nullopt, nullopt, "TYQOON", MEIKO, "Sohbana", 443687},
  {"流星のパルス", "Ryuusei no Parusu", "Pulse of The Meteor", Len, "*Luna", 354784},
  {"踊", nullopt, "Odo", duet(Rin,Len), "Giga × TeddyLoid × DECO*27", 370504},
  {"陽だまりのセツナ", "Hidamari no Setsuna", "A moment in the sun", duet(Miku,Luka), "Akano Y", 437831},
  {"初めての恋が終わる時", "Hajimete no Koi ga Owaru Toki", "When First Love Ends", Miku, "ryo", 1327},
  {"アンテナ39", nullopt, "Antenna 39", Miku, "Hiiragi Magnetite", 630460},
  {"ボルテッカー", nullopt, "Volt Tackle", Miku, "DECO*27", 532518},
  {"ヒアソビ", "Hiasobi", "Play With Fire", Miku, "Camellia", 392049},
  {"こちら、幸福安心委員会です。", "Kochira, Koufuku Anshin Iinkai desu.", "This is, the Happiness and Peace of Mind Committee.", Miku, "UtataP", 13260},
  {nullopt, nullopt, "MAGA MAGA", Luka, "Yurei Ichimonji", 580170},
  {"ラヴィ", nullopt, "Lavie", Len, "Surii", 449282},
  {"少女A", "Shoujo A", "Young Girl A", Rin, "Powapowa-P", 42111},
  {"ヴァニッシュ", nullopt, "Vanish", KAITO, "Guchiry", 401761},
  {"げんてん", "Genten", "origin", MEIKO, "Daibaku Hashin", 687114},
  {nullopt, nullopt, "Flyway", duet(KAITO,Len), "halyosy", 471637},
  {nullopt, nullopt, "stargazeR", Miku, "Kotsuban-P", 2922},
  {"黙ってロックをやれって言ってんの！", "Damatte Rock o Yare tte Itten no!", "DO THE ROCK!", duet(MEIKO,Miku,Rin,Luka), "Nekotachi Kotatsu", 640328},
  {"ストリートライト", nullopt, "Street Light", duet(Miku,Luka,Rin,Len,MEIKO,KAITO), "Negi Shower P", 746114},
  {"ラストラス", nullopt, "Lustrous", Miku, "*Luna", 789209},
  {"ステラ", "Stella", "Stella", Miku, "Kotsuban-P", 96665, nullopt, nullopt, "<a:mikusnowrng:926685701494435870>"},
  {"雪がとける前に", "Yuki ga Tokeru Mae ni", "Before the Snow Melts", Miku, "doriko", 109873, nullopt, nullopt, "<a:mikusnowrng:926685701494435870>"},
  {"スターナイトスノウ", "Star Night Snow", "Star Night Snow", Miku, "n-buna×Orangestar", 143132, nullopt, nullopt, "<a:mikusnowrng:926685701494435870>"},
  {"你好", "Nǐhǎo", "Hello", Miku, "MusikM", 166099},
  {"初嵐", "Chūlán", "First Storm", Miku, "DECO*27", 166780},
  {nullopt, nullopt, "Shining Star (Miku cover)", Miku, "Unknown", 326238},
  {"越过海岸线", "Yuèguò Hǎi'ànxiàn", "Crossing Over the Coastline", Miku, "kz", 206326},
  {nullopt, nullopt, "Pick Me Up", Miku, "Demon", 212572},
  {"COME BACK~重返巅峰~", "COME BACK ~Chóng Fǎn Diānfēng~", "COME BACK ~Returning to the Peak~", Miku, "Mikunya", 259351},
  {"踏步、出发", "Tàbù, Chūfā", "Step Forward", Miku, "MACHWOLF", 303981},
  {nullopt, nullopt, "My Stage With You", Miku, "cannibaltim", 373813},
  {"梦色星球", "Mèngsè Xīngqiú", "Dream Color Planet", Miku, "AzureHead", 642040},
  {"跨时空日记", "Kuà Shíkōng Rìjì", "Diary Across Time And Space", Miku, "Siren", 456358},
  {nullopt, "Project DIVA desu.", "It's Project DIVA.", Miku, "UtataP", 5484},
  {"サウンド", "Sound", "sound", Miku, "baker", 1340},
  {"恋スルVOC@LOID", "Koisuru VOC@LOID", "VOC@LOID in Love", Miku, "OSTER project", 7939},
  {nullopt, nullopt, "Dear cocoa girls", Miku, "Kosaki Satoru, Hata Aki", 2943},
  {nullopt, nullopt, "The secret garden", Miku, "Kosaki Satoru, Hata Aki", 2942},
  {"ミラクルペイント", "Miracle Paint", "Miracle Paint", Miku, "OSTER project", 3658},
  {nullopt, nullopt, "Innocence", Miku, "KazuP", 3027},
  {"ハト", "Hato", "White Dove", Miku, "Hadano-P", 108735},
  {"みくみく菌にご注意♪", "Miku Miku-kin ni Gochuui♪", "Beware of the Miku Miku Germs♪", Miku, "Hayaya-P", 278377},
  {"サヨナラ・グッバイ", "Sayonara·Goodbye", "Farewell Goodbye", Miku, "Noboru↑-P", 2652},
  {nullopt, nullopt, "Dear", Miku, "19's Sound Factory", 3478},
  {"教えて!! 魔法のLyric", "Oshiete!! Mahou no Lyric", "Tell Me!! The Magical Lyric", duet(Miku, MEIKO), "ChomP", 3274},
  {"パズル", "Puzzle", "Puzzle", Miku, "Kuwagata-P", 1319},
  {nullopt, nullopt, "VOiCE", Miku, "Lovely-P", 11877},
  {nullopt, nullopt, "Alice", Miku, "Fullkawa-P", 4051},
  {"あなたの歌姫", "Anata no Utahime", "Your Diva", Miku, "azuma", 2917},
  {nullopt, nullopt, "moon", Miku, "iroha(sasaki)", 5701},
  {nullopt, nullopt, "Promise", duet(Miku, Rin), "samfree", 1437},
  {nullopt, nullopt, "from Y to Y", duet(Miku, Luka), "JimmyThumb-P", 4230},
  {"ストロボナイツ", "Strobe Nights", "Strobe Nights", Miku, "kz", 2442},
  {"ファインダー", "Finder", "finder (DSLR remix-re:edit)", Miku, "kz", 291623},
  {"クローバー♣クラブ", "Clover♣Club", "Clover♣Club", Miku, "Yuuyu-P", 5833},
  {"電気の恋人 -Programmer’s Song-", "Denki no Koibito -Programmer's Song-", "Electric Lovers - I am Programmer's Song", Miku, "MOSAIC.WAV×ika", 3855},
  {nullopt, nullopt, "HATSUNEtive", Miku, "MOSAIC.WAV×ika", 3858},
  {"私は人間じゃないから.", "Watashi wa Ningen ja Nai kara.", "Maybe I'm not a human.", Miku, "Deadball-P", 8787},
  {"とある娼婦の恋", "Toaru Shoufu no Koi", "A Certain Prostitute's Love", duet(Miku, Rin), "Deadball-P", 17294},
  {"牛乳飲め！", "Gyuunyuu Nome!", "You Should Drink Milk!", Miku, "Deadball-P", 8790},
  {"木枯らしの朝", "Kogarashi no Asa", "Anyway the Wind Blows", Miku, "Deadball-P", 8791},
  {"筆おろし", "Fude Oroshi", "First Time", Miku, "Deadball-P", 2477},
  {"既成事実", "Kisei Jijitsu", "I Remember About You Forever", Miku, "Deadball-P", 8789},
  {nullopt, nullopt, "Far Away", Miku, "kz", 2941},
  {nullopt, nullopt, "Heart Beat", Miku, "kz", 5232},
  {nullopt, nullopt, "Crosslight", duet(Miku, Gumi), "kz", 1465},
  {"ブラック★ロックシューター", "Black★Rock Shooter", "Black★Rock Shooter", Miku, "ryo", 1323},
  {"＊ハロー、プラネット。", "*Hello, Planet.", "*Hello, Planet.", Miku, "sasakure.UK", 2924},
  {"番凩", "Tsugai Kogarashi", "Wintry Winds", duet(MEIKO, KAITO), "hinayukki@sigotositeP", 8241},
  {"タイムリミット", "Time Limit", "Time Limit", Miku, "Tatami-P", 2732},
  {nullopt, nullopt, "Ievan Polkka", Miku, "Otomania", 638, nullopt, nullopt, "<:leek:235219960425611264>"},
  {"崩壊歌姫 -disruptive diva-", "Houkai Utahime", "Disruptive Diva", Miku, "Machigerita-P", 3008},
  {nullopt, nullopt, "RIP=RELEASE", Luka, "minato", 7234},
  {nullopt, nullopt, "Japanese Ninja No.1", Luka, "Deadball-P", 2474},
  {nullopt, nullopt, "trick and treat",  duet(Rin, Len), "OSTER project", 3244},
  {"悪ノ娘", "Aku no Musume", "Daughter of Evil (The Princess of Lucifer)", Rin, "mothy", 1590},
  {"悪ノ召使", "Aku no Meshitsukai", "Servant of Evil (His Significance of Existence)", duet(Rin, Len), "mothy", 1358},
  {"いろは唄", "Iroha Uta", "Iroha Song", Rin, "Ginsaku", 2738},
  {"リンリンシグナル", "Rin Rin Signal", "Rin Rin Signal", duet(Rin, Len), "Signal-P", 2259},
  {nullopt, nullopt, "SPICE!", Len, "minato", 5181},
  {nullopt, nullopt, "ARiA", Miku, "Toku-P", 1723},
  {nullopt, nullopt, "01_ballade", Miku, "Eiji Hirasawa", 2241},
  {"私の時間", "Watashi no Jikan", "My Time", Miku, "Kuchibashi-P", 7235},
  {nullopt, nullopt, "BURNING", NO_VIRTUAL_SINGER, "Kodo"},
  {nullopt, nullopt, "SHAKE", Miku, "Kodo"},
  {"巴", "Tomoe", "Tomoe", NO_VIRTUAL_SINGER, "Kodo"},
  {"峰の風", "Mine no Kaze", "Peak of the Wind", Miku, "Kodo"},
  {"紅一葉", "Akahitoha", "A Single Red Leaf", Miku, "Kurousa-P", 7718},
  {"能管＋平胴", "Nokan＋hirado", "Flute＋Flat Frame", NO_VIRTUAL_SINGER, "Kodo"},
  {"三宅", "Miyake", "Miyake", NO_VIRTUAL_SINGER, "Kodo"},
  {"巡", "Meguru", "Patrol", NO_VIRTUAL_SINGER, "Kodo", nullopt, nullopt, Miku},
  {"族", "Zoku", "Tribe", Miku, "Kodo"},
  {"南部牛追歌", "Nanbu Ushioi Uta", "Southern Cattle-Chasing Song", Miku, "Kodo"},
  {"韋駄天", "Idaten", "Idaten", NO_VIRTUAL_SINGER, "Kodo"},
  {"NEPPUU〜熱風〜", "Neppuu〜Neppuu〜", "NEPPUU ~Blistering Wind~", Miku, "Mikito-P", 480845, nullopt, nullopt, "<a:mikubongo:768370491634614293>"},
  {"いのちもやしてたたけよ", "Inochi Moyashite Tatake yo", "Let Your Life Be Vigorous and Open Your Mouth", Miku, "Kodo"},
  {"祭りだヘイカモン", "Matsuri da Hey Come On", "It's a Festival, Hey, C'mon", Miku, "Pinocchio-P", 99595},
  {nullopt, nullopt, "LION", NO_VIRTUAL_SINGER, "Kodo"},
  {nullopt, nullopt, "Artifact", Miku, "buzzG", 848950},
  {"水色侵略", "Mizuiro Shinryaku", "Light Blue Invasion", Miku, "NayutalieN", 294036},
  {"世界の真ん中を歩く", "Sekai no Mannaka o Aruku", "Walking in the Center of the World", Miku, "natsushiro", 152288},
  {"バイオレンストリガー", "Violence Trigger", "Violence Trigger", Miku, "Hachioji-P", 219144},
  {"マカロン", "MACARON", "MACARON", Miku, "ATOLS", 15565},
  {"カガリビト", "Kagaribito", "Whipstitching Person", Miku, "millstones", 298},
  {"ビターチョコデコレーション", "Bitter Choco Decoration", "Bitter Chocolate Decoration", Miku, "syudou", 221277},
  {"未来最終戦争", "Mirai Saishuu Sensou", "Future Final Wars", Miku, "DIVELA", 271920},
  {"ロンリーユニバース", "Lonely Universe", "Lonely Universe", Miku, "Aqu3ra", 232181},
  {nullopt, nullopt, "Mag1c", Miku, "Xiǎo Miányáng magens", 843579},
  {"ポケットのモンスター", "Pocket no Monster", "The Pokémon Inside My Heart", Miku, "Pinocchio-P", 538028},
  {"シアンブルー", "Cyan Blue", "Cyan Blue", Miku, "Police Piccadilly", 887891},
  {"アイドル戦士", "Idol Senshi", "Idol Warrior", Miku, "Mitchie M", 760683},
  {"インビテーション！", "INVITATION!", "INVITATION!", Miku, "Negi ShowerP", 501614},
  {"愛言葉Ⅴ", "Ai Kotoba V", "Love Words V", Miku, "DECO*27", 915394},
  {"ハオ", "HAO", "HAO", Miku, "DECO*27", 640212},
  {"ハートアラモード", "Heart à la mode", "Heart à la mode", Miku, "DECO*27", 67964},
  {"テレパシ", "Telepathy", "Telepathy", Miku, "DECO*27", 752940},
  {"マシュマロ", "Marshmallow", "Marshmallow", Miku, "DECO*27", 848354},
  {"妄想税", "Mousouzei", "Delusion Tax", Miku, "DECO*27", 38916},
  {"モニタリング", "Monitoring", "Monitoring", Miku, "DECO*27", 668055},
  {"アニマル", "Animal", "Animal", Miku, "DECO*27", 371426, "Deco"},
  {"シンデレラ", "Cinderella", "Cinderella", Miku, "DECO*27", 346457},
  {"愛迷エレジー", "Aimai Elegy", "Aimai Elegy", Miku, "DECO*27", 42200},
  {"モザイクロール (Reloaded)", "Mozaik Role (Reloaded)", "Mozaik Role (Reloaded)", Miku, "DECO*27", 358478}, // Original is Gumi, so keep Reloaded here.
  {"弱虫モンブラン (Reloaded)", "Yowamushi Mont Blanc (Reloaded)", "Yowamushi Mont Blanc (Reloaded)", Miku, "DECO*27", 777659}, // Original is Gumi, so keep Reloaded here.
  {"乙女解剖", "Otome Kaibou", "Otome Dissection", Miku, "DECO*27", 222749},
  {"妄想感傷代償連盟", "Mousou Kanshou Daishou Renmei", "Delusional Sentimental Compensation Federation", Miku, "DECO*27", 131090},
  {"チェリーポップ", "Cherry Pop", "Cherry Pop", Miku, "DECO*27", 816725},
  {"おじゃま虫", "Ojamamushi", "Stickybug", Miku, "DECO*27", 48030},
  {"ラビットホール", "Rabbit Hole", "Rabbit Hole", Miku, "DECO*27", 500519},
  {"サラマンダー", "Salamander", "Salamander", Miku, "DECO*27", 376689},
  {"キメラ", "Chimera", "Chimera", Miku, "DECO*27", 396081},
  {"アンドロイドガール", "Android Girl", "Android Girl", Miku, "DECO*27", 230406},
  {nullopt, nullopt, "Reunion", NO_VIRTUAL_SINGER, "DECO*27", 230396},
  {"電気予報", "Denki Yohou", "Electricity Forecast", Miku, "inabakumori", 534385},
  {"ミライどんなだろう", "Mirai Donna Darou", "What Kind of Future", Miku, "Mitchie M", 536349},
  {"戦闘！初音ミク", "Sentou! Hatsune Miku", "Battle! (Hatsune Miku)", Miku, "cosMo", 557560},
  {"きみとそらをとぶ", "Kimi to Sora o Tobu", "Fly With You", duet(Miku, Luka), "Kasamura Tota", 560308},
  {"ガッチュー！", "Gotchu!", "I GOT YOU!", duet(Miku, Rin, Len), "Giga", 563199},
  {nullopt, nullopt, "JUVENILE", Miku, "Jin", 566239},
  {"俺ゴーストタイプ", "Ore Ghost Type", "I'm a Ghost Type", Miku, "syudou", 579184},
  {"ゴー！ビッパ団", "Go! Bippa Dan", "GO! Team BIPPA", duet(Miku, Rin, Len), "Wonderful☆Opportunity", 581632, nullopt, KAITO},
  {"ひゅ〜どろどろ", "Hyu~dorodoro", "Woo~oosh, Oozing", duet(Miku, MEIKO), "Van de Shop", 584100},
  {nullopt, nullopt, "Encounter", Miku, "Orangestar", 586628},
  {"むげんのチケット", "mugen no ticket", "Eon Ticket", duet(Miku, KAITO), "marasy", 586830},
  {nullopt, nullopt, "PARTY ROCK ETERNITY", Miku, "Hachioji-P", 589291},
  {"たびのまえ、たびのあと", "Tabi no Mae, Tabi no Ato", "Journey's Prequels, Journey's Traces", Miku, "iyowa", 592083},
  {"エスパーエスパー", "Esper Esper", "Esper Esper", Miku, "NayutalieN", 593626},
  {"メロメロイド", "MELLOMELLOID", "MELLOMELLOID", Miku, "Kairiki Bear", 594927},
  {nullopt, nullopt, "Glorious Day", Miku, "Eve", 598025},
  {"アフターエポックス", "After Epochs", "After Epochs", Miku, "sasakure.UK", 625986},
  {"チャンピオン", "Champion", "Champion", Miku, "Kanaria", 650687},
  {"しんかしんかしんか", "Shinka Shinka Shinka", "EVOLVE EVOLVE EVOLVE", Miku, "Sasuke Haraguchi", 709668},
  {"ファサード・クエスチョン", "Façade Question", "Façade Question", duet(Miku, Teto), "32ki", 771172},
  {"オーパーツ", "OOPÁRTS", "OOPÁRTS", Miku, "NILFRUITS", 840401},
  {"ドキドキ！", "Dokidoki!", "Dokidoki!", duet(Miku, Len), "Surii", 853916},
  {"たびだちのうた", "Tabidachi no Uta", "Departure Song", Miku, "Karasuyasabou", 906978},
  {"スパイラル・メロディーズ", "Spiral Melodies", "Spiral Melodies", Miku, "Omoi", 925294},
  {"クロスロード", "Crossroad", "Crossroad", Miku, "kz × TAKU INOUE", 929916},
  {nullopt, nullopt, "CONNECT:COMMUNE", Miku, "FLAVOR FOLEY", 907752},
  {nullopt, nullopt, "Room for a Fantasy", Miku, "nostraightanswer", 878942},
  {"空に免じて", "Sora ni Menjite", "Sora ni Menjite", Miku, "Kasamura Toota", 61041},
  {nullopt, nullopt, "HELLO, NEW WORLD!", Luka, "Nanao", 742688},
  {"死にたくない。", "Shinitaku Nai.", "I Don't Want to Die.", Len, "Usagi3", 400280},
  {"ジェヘナ", "Gehenna", "Gehenna", Miku, "wotaku", 248865},
  {"バッドシャーク", "Bad Shark", "Bad Shark", Rin, "niki", 478851},
  {"ドーピングダンス", "Doping Dance", "Doping Dance", Miku, "STEAKA", 425435},
  {"サロメ", "Salomé", "Salomé", MEIKO, "⌘HYNOME", 753184},
  {"エル・タンゴ・エゴイスタ", "El・Tango・Egoista", "El・Tango・Egoista", duet(KAITO, Luka), "nyanyannya", 146056},
  {"こたえて", "Kotaete", "Answer Me", duet(Miku, KAITO, MEIKO, Luka, Rin, Len), "imie", 884096},
  {"青炎", "Sei-ei", "Blue Fire", KAITO, "Sekikomi Gohan", 913761},
  {"泥中に咲く", "Deichuu ni Saku", "Blooming in the Mud", Miku, "HarryP", 220728},
  /* Diva songs */
  {"ひねくれ者", "Hinekuremono", "Jaded", Miku, "ryo", 1330},
  {"その一秒スローモーション", "Sono Ichibyou Slow Motion", "That One Second in Slow Motion", Miku, "ryo", 1329},
  {nullopt, nullopt, "Star Story", Miku, "kz", 8397},
  {"雨のちSweet*Drops", "Ame Nochi Sweet*Drops", "Sweet*Drops After the Rain", Miku, "OSTER project", 2948},
  {"フキゲンワルツ", "Fukigen Waltz", "Bad Mood Waltz", Miku, "OSTER project", 9237},
  {"Dreaming Leaf ‐ユメミルコトノハ‐", "Dreaming Leaf -Yume Miru Kotonoha-", "Dreaming Leaf -Dreaming Words-", Miku, "OSTER project", 5547},
  {"荒野と森と魔法の歌", "Kouya to Mori to Mahou no Uta", "Song of Wastelands, Forests, and Magic", Miku, "Toraboruta-P", 2946 },
  {"いのちの歌", "Inochi no Uta", "Song of Life", Miku, "Toraboruta-P", 2947 },
  {"天鵞絨アラベスク", "Biroudo Arabesque", "Velvet Arabesque", Miku, "Hata Aki", 2944 },
  {"ラブリスト更新中？", "Love List Koushinchuu?", "Updating My Love List?", Miku, "Hata Aki", 2945 },
  {"金の聖夜霜雪に朽ちて", "Kogane no Seiya Sousetsu ni Kuchite", "Golden Holy Night Rotting into the Frost and Snow", Miku, "Deadball-P", 2923},
  {nullopt, nullopt, "RING×RING×RING", Rin, "OSTER project", 5550},
  {"すすすす、すき、だあいすき", "SuSuSuSu, Suki, Daisuki", "I Like You, I Love You", Rin, "Jevanni-P", 4178 },
  {"モバイリ：センセーション", "MobiRe:Sensation", "MobiRe SenS@tion", Rin, "sasakure.UK", 5239 },
  {"自己嫌悪", "Jiko Ken'o", "Self-Hatred", Rin, "Ginsaku", 7717 },
  {nullopt, nullopt, "Transmit", Rin, "Signal-P", 2267 },
  {"レンラクマダー？", "Renraku Mada?", "Why Don't You Call Me Yet?", Rin, "Live-P", 3393 },
  {"那由他の彼方まで", "Nayuta no Kanata Made", "To Beyond a Duodecillion", duet(Miku, Rin, Len), "TsurishiP", 2914 },
  {"ぶっちぎりにしてあげる♪", "Bucchigiri ni Shite Ageru♪", "I'll Outrun You For Good♪", Rin, "BucchigiriP", 18485 },
  {"サンドスクレイパー -砂漠の特急線-", "Sandscraper -Sabaku no Tokkyuu Sen-", "Sandscraper -Desert Express Line-", Len, "Mikusagi-P", 16319 },
  {nullopt, nullopt, "Palette", Luka, "Yuyoyuppe", 1119},
  {"巡姫舞踊曲", "Megurihime Buyoukyoku", "Itinerating Diva's Dance Music", Luka, "No.D", 3262 },
  {"filozofio -Другой-", "filozofio -Drugoy-", "philosophy -Another-", Luka, "Pandolist-P", 2541 },
  {"トエト", "Toeto", "Toeto", Luka, "Toraboruta-P", 3240 },
  {"リンリンリンってしてくりん", "Rin Rin Rin tte Shite Kurin", "I'm Going to Do the Rin Rin Rin", Rin, "JevanniP", 33098 },
  {"イケ恋歌", "Ikerenka", "Cool Love Song", Len, "LeleleP", 850 },
  {nullopt, nullopt, "Soar", Miku, "minato", 5179 },
  {nullopt, nullopt, "ＳＥＴＳＵＮＡ", Miku, "SHIKI", 4321 },
  {"夕暮れノスタルジック -remix-", "Yuugure Nostalgic -remix-", "Sunset Nostalgic -remix-", Miku, "guriplus", 41600 },
  {nullopt, nullopt, "Love it!", Miku, "Clean Tears, T-ism", 5106},
  {"キコエテイマスカ・・・", "Kikoete Imasu ka...", "Can You Hear Me?", Miku, "G@POPO", 26826 },
  {nullopt, nullopt, "Shooting Star Prologue", Miku, "SOSOSO", 5817 },
  {nullopt, nullopt, "starise", Miku, "shimajiro", 41599 },
  /* Diva Arcade */
  {nullopt, nullopt, "AFTER BURNER", MEIKO, "PonzP", 41709 },
  {"数多の舞", "Amata no Mai", "Dance of Many", Miku, "HikutsuP", 2744 },
  {nullopt, nullopt, "Equation+**", Rin, "Powapowa-P", 166428 },
  {"イヤイヤ星人", "Iya Iya Seijin", "No-No Alien", Luka, "IyaiyaP", 2747 },
  {"嘘つきベティ", "Usotsuki Betty", "Liar Betty", Rin, "PolyphonicBranch", 2746 },
  {"オオカミガール", "Ookami Girl", "Wolf Girl", Miku, "kuraP", 3005 },
  {"片想いサンバ", "Kataomoi Samba", "One-Sided Love Samba", Miku, "OwataP", 3007 },
  {"カラフル×セクシィ", "Colorful × Sexy", "Colorful × Sexy", duet(Luka, MEIKO), "Team MOER", 2928 },
  {"カンタレラ", "Cantarella", "Cantarella", duet(Miku, KAITO), "Kurousa-P", 589259 },
  {"キップル・インダストリー", nullopt, "Kipple Industry, Inc.", Miku, "millstones", 4593 },
  {"巨大少女", "Kyodai Shoujo", "Gigantic Girl", Miku, "40mp", 653 },
  {"恋ノート////", "Koi Note////", "Love Note", Miku, "HattoriP, JevanniP", 12357 },
  {nullopt, nullopt, "Gothic and Loneliness ～I’m the very DIVA～", Rin, "Narushima Takashi", 13734 },
  {"さあ、どっち？", "Saa, Docchi?", "Now, Which?", duet(Len,Rin), "Hinata Haruhana", 2743 },
  {nullopt, nullopt, "saturation", Miku, "amyu", 2735 },
  {nullopt, nullopt, "ZIGG-ZAGG", Miku, "Junky", 3012 },
  {"ジュゲムシーケンサー", "Jugemu Sequencer", "Jugemu Sequencer", Miku, "Vocaliod-P", 896 },
  {nullopt, nullopt, "SYMPHONIC DIVE", Miku, "Re:nG", 435209 },
  {"スターライト☆リディアン", nullopt, "Starlite★Lydian", Miku, "Laa Laa~P", 3009 },
  {nullopt, nullopt, "slump", Miku, "Shibainu", 9361 },
  {nullopt, nullopt, "So much loving you★", Miku, "kofunP", 3469 },
  {"そいやっさぁ!!", "Soiyassaa!!", "Soiyassaa!!", duet(Len,Rin), "PrisonerP", 2749 },
  {"多重未来のカルテット～QUARTET THEME～", "Tajuu Mirai no Quartet ~QUARTET THEME~", "Multiple Future Quartet ~QUARTET THEME~", Miku, "Kusemono", 8974 },
  {"透明水彩", "Toumei Suisai", "Transparent Watercolors", Miku, "yasuo", 2737 },
  {"ナイトメア☆パーティーナイト", "Nightmare☆Party Night", "Nightmare☆Party Night", Miku, "KuchibashiP", 3004 },
  {"どうしてこうなった", "Doushite Kounatta", "How Did This Happen", Miku, "udongerge", 3002 },
  {"ネコミミアーカイブ", "Nekomimi Archive", "Cat Ear Archive", Miku, "KusoinakaP", 8900 },
  {"ねこみみスイッチ", "Nekomimi Switch", "Cat Ears Switch", Miku, "daniwell", 2910 },
  {"ハイスクール Days", "High School Days", "High School Days", Miku, "U-ji", 2748 },
  {"花舞月詠譚", "Hanamai Tsukuyomi Tan", "A Tale of Flower Petals and the Singing Moon", Luka, "Hoskey", 237415 },
  {"パラジクロロベンゼン", nullopt, "Paradichlorobenzene", duet(Len,Rin), "OwataP", 1890 },
  {"ピンクムーン", nullopt, "Pink Moon", Miku, "Okishi Jin", 2736 },
  {"ブラックゴールド", "Black Gold", "Black Gold", Luka, "otetsu", 82 },
  {"フランシスカ", nullopt, "Francisca", Rin, "MerazoomaP, YumehikariP", 9542 },
  {nullopt, nullopt, "break;down", Miku, "hmtk", 2750 },
  {"ペリコ・スペースシッパー", "Perico Space Shipper", "Perico Space Shipper", Miku, "OnecupP", 3006 },
  {nullopt, nullopt, "Holy Star", Miku, "Kouhei", 13655 },
  {"スーパーハイパーマスターファイヤーサンダーフリーザーアルテママダンテホーリースターバーストストリームブラックマジックダークメシアイカリャクゼンシュウチュウビッグバンアルティメットアタック", nullopt, "Super Hyper Master Fire Thunder Freezer Ultima Madante Holy Star Burst Stream Black Magic Dark Messiah Ikaryaku Zenshuuchuu Big Bang Ultimate Attack", Miku, "Emasaki", 316650 },
  {"ほしをつくるひと", "Hoshi o Tsukuru Hito", "The Star Maker", Len, "MazoP", 2741 },
  {"ほんとは分かってる", "Honto wa Wakatteru", "I Understand The Truth", Miku, "funakoshiP", 3018 },
  {"迷子ライフ", "Maigo Life", "Stray Life", Rin, "TOKOTOKO", 1142 },
  {nullopt, nullopt, "Magical Sound Shower", Miku, "Kusemono", 3013 },
  {"マスターオブパペッツ", "Master of Puppets", "Master of Puppets", duet(Miku,Luka), "Death Ohagi, Yurahonya", 2740 },
  {"迷的サイバネティックス", "Meiteki Cybernetics", "Stray Cybernetics", Luka, "otetsu", 1057 },
  {nullopt, nullopt, "melody...", Miku, "mikuru396", 2734 },
  {"妄想スケッチ", "Mousou Sketch", "Delusion Sketch", Miku, "40mP", 1367 },
  {"悠久", "Yuukyuu", "Song of Eternity", Miku, "Tiara, Jun", 6839 },
  {nullopt, nullopt, "LIKE THE WIND", Rin, "Kusemono, Kawaguchi Hiroshi", 42082 },
  {"ふたりで。", "Futari de.", "Together.", Miku, "Sasanomaly", 6161 },
  {nullopt, nullopt, "Rosary Pale", KAITO, "ShinjouP", 41707 },
  {nullopt, nullopt, "Absolunote", Miku, "Lemm", 8971 },
  {"ルシッドドリーミング", "Lucid Dreaming", "Lucid Dreaming", Miku, "naiveP", 5027 },
  {"アウト オブ エデン", nullopt, "Out Of Eden", Len, "Kouhei", 13921 },
  {nullopt, nullopt, "GO MY WAY!!", Miku, "Otomania", 251108 },
  {nullopt, nullopt, "relations", duet(Rin,Luka), "Koji Nakagawa, HaroP", 113488 },
  {nullopt, nullopt, "Endless Nightmare", duet(Luka,Miku), "EM, WEB-MIX", 106642 },
  {nullopt, nullopt, "Cardioid", Miku, "DATEKEN", 2290 },
  {nullopt, nullopt, "EXtend", Miku, "FB777", 26754 },
  {nullopt, nullopt, "Hometown", MEIKO, "SuzukazeP", 10221 },
  {"なんで? ", "Nande?", "Why?", Len, "rerulili", 5725 },
  {nullopt, nullopt, "Hallo World", Rin, "DuronII", 114293 },
  {nullopt, nullopt, "I'm Crazy For You", Miku, "SABA.U1", 114295 },
  {"猫なキミ", "Neko na Kimi", "The Cat-like You", Miku, "774P", 114296 },
  {"時にはsoftに、時にはdarkに", "Toki ni wa Soft ni, Toki ni wa Dark ni", "Sometimes Soft, Sometimes Dark", Miku, "NAV", 114297 },
  /* Diva extend */
  {"えでぃっともーどのうた", "Edit Mode no Uta", "Song of Edit Mode", duet(Miku,Rin,Len,Luka,MEIKO,KAITO), "LamazeP", 41598 },
  {nullopt, nullopt, "Start of Rainbow ～first step～", Miku, "Keiichi Sugiyama", 343187 },
  {"藍色の日、空翔ける ～second flight～", "Ai-iro no Hi, Sora Kakeru ～second flight～", "The Date of Indigo, Fly Sky ～second flight～", Miku, "Keiichi Sugiyama", 478422 },
  {"恋の祈り ～extend your wave～", "Koi no inori ～extend your wave～", "Prayer of Love ～extend your wave～", Miku, "Keiichi Sugiyama", 66424 },
  /* Diva f */
  {nullopt, nullopt, "DYE", Luka, "AVTechNO!", 2607 },
  {"サマーアイドル", nullopt, "Summer Idol", duet(Miku,Rin), "OSTER project", 15394 },
  {nullopt, nullopt, "ACUTE", duet(Miku,Luka,KAITO), "KurousaP", 552 },
  {"どういうことなの！？", "Dou Iu Koto na no!?", "What Do You Mean!?", Miku, "KuchibashiP", 3386 },
  {nullopt, nullopt, "Stay with me", MEIKO, "shu-t", 16558 },
  {"ハイハハイニ", "Hai wa Hai ni", "Ashes to Ashes", KAITO, "tennen", 5800 },
  {nullopt, nullopt, "WORLD'S END UMBRELLA", Miku, "HACHI", 16560 },
  {"モノクロ∞ブルースカイ", "Monochrome∞Blue Sky", "Monochrome∞Blue Sky", Miku, "Noboru", 2651 },
  {nullopt, "MEGANE", "GLASSES", Luka, "Ultra-Noob", 12056 },
  {"鏡音八八花合戦", "Kagamine Hachihachi Hana no Kassen", "Kagamine HachiHachi Flower Fight", duet(Len,Rin), "Mogiavelli", 13961 },
  {"ネトゲ廃人シュプレヒコール", "Netgame Haijin Sprechchor", "Online Game Addicts Sprechchor", Miku, "Satsuki ga Tenkomori", 12443 },
  {"天樂", "Tengaku", "Music of Heaven", Rin, "Yuuyu", 3269 },
  {"神曲", "Kamikyoku", "God-Tier Tune", Miku, "onewP, PinocchioP", 3389 },
  {"ネガポジ＊コンティニューズ", "Negaposi*Continues", "Negaposi*Continues", Miku, "sasakure.UK", 16580 },
  {nullopt, nullopt, "Sadistic.Music∞Factory", Miku, "cosMo@BousouP", 16061 },
  {"夢の続き", "Yume no Tsuzuki", "Continuation of Dreams", duet(Miku,Rin,Len,Luka), "Dixie Flatline", 16581 },
  {"夢喰い白黒バク", "Yumekui Shirokuro Baku", "Dream-Eating Monochrome Baku", Len, "Nem", 3636 },
  {"リンちゃんなう！", "Rin-chan Now!", "Rin-chan Now!", duet(Luka,Miku,Rin), "OwataP", 8678 },
  {"トリコロール・エア・ライン", nullopt, "Tricolore Airline", Miku, "atsuzoukun", 32167 },
  {"巴里映画少女", "Paris Eiga Shoujo", "Paris Cinema Girl", Miku, "apfel note", 50041 },
  {nullopt, nullopt, "SING&SMILE", Miku, "Re:nG", 3263 },
  {"唐傘さんが通る", "Karakasa-san ga Tooru", "Here Comes Mr. Umbrella", Len, "IyaiyaP", 55507 },
  {"デンパラダイム", "Denparadigm", "Electric Paradigm", Miku, "lumo", 28500 },
  {"システマティック・ラヴ", nullopt, "Systematic Love", Miku, "Camellia", 19060 },
  {"おはヨーデル", "Oha Yo-del!!!", "Good Morning Yodel!!", Miku, "Bakudan Poppy", 105237 },
  {"月向うまでのトラベル", "Tsuki Mukau Made no Travel", "Travel Beyond the Moon", duet(Rin,Len), "vilP", 71158 },
  {"ブラックノートに溺れさせて", "Black Note ni Obore Sasete", "Let Me Lose Myself in The Black Note", Miku, "Shun13", 39003 },
  {"キミに", "Kimi ni", "To You", Miku, "teaeye", 26232 },
  {"ナイト・オブ・ライト", nullopt, "Knight of Light", duet(KAITO,Miku), "TinySymphony", 23076 },
  {nullopt, nullopt, "Mellow Yellow", MEIKO, "SorrowfulP, MelissaP", 35300 },
  {"ぎずも", "Gizmo", "Gizmo", Miku, "uguis08", 29341 },
  {"エレクトロサチュレイタ", "Electrosaturator", "Electrosaturator", Miku, "tilt-six", 21064 },
  {"偶像無線", "Guuzou Musen", "Idol Radio", KAITO, "Daisuke Ohnuma", 89703 },
  {nullopt, nullopt, "Glory 3usi9", Miku, "nanou", 36611 },
  {nullopt, nullopt, "PIANO*GIRL", Miku, "OSTER project", 7800 },
  {"壊セ壊セ", "Kowase Kowase", "Break it, Break it!", MEIKO, "E.L.V.N", 3388 },
  {"指切り", "Yubikiri", "Pinky Promise", Miku, "scop", 4715 },
  {nullopt, nullopt, "soundless voice", Len, "HitoshizukuP", 7820 },
  {nullopt, nullopt, "Knife", duet(Miku,Rin,Len), "rerulili", 4478 },
  {nullopt, nullopt, "Blackjack", Luka, "YuchaP, kaichi", 3390 },
  {"アドレサンス", "Adolescence", "Adolescence", duet(Rin,Len), "Dios/SignalP", 2251 },
  {"君の体温", "Kimi no Taion", "Your Warmth", Miku, "Stag BeetleP", 1318 },
  {"骸骨楽団とリリア", "Gaikotsu Gakudan to Lilia", "Skeleton Orchestra and Lilia", Miku, "Tohma", 556 },
  {nullopt, nullopt, "LOL -lots of laugh-", Miku, "zoccon", 14205 },
  {"アマツキツネ", "Amatsu Kitsune", "The Celestial Fox", Rin, "marasy", 15691 },
  {nullopt, nullopt, "1925", Miku, "T-POCKET", 7319 },
  {"ジグソーパズル", nullopt, "Jigsaw Puzzle", duet(Len,Rin), "Mafumafu", 215140 },
  {"ジターバグ", nullopt, "Jitterbug", duet(Miku,MEIKO), "Kuriyama Yuri, Koh Hashikura", 256954 },
  {"ドラマツルギー", nullopt, "Dramaturgy", Miku, "Eve, Tomoki Numano", 170110 },
  /* diva X */
  {"罪の名前", "Tsumi no Namae", "The Name of the Sin", Miku, "ryo", 121112 },
  {"クノイチでも恋がしたい", "Kunoichi Demo Koi ga Shitai", "Even a Kunoichi Needs Love", duet(Miku,Rin), "MikitoP, Suzumu", 24039 },
  {"Mrs.Pumpkinの滑稽な夢 ", "Mrs. Pumpkin no Kokkei na Yume", "Humorous Dream of Mrs. Pumpkin", Miku, "HACHI", 1573 },
  {"卑怯戦隊うろたんだー", "Hikyou Sentai Urotander", "Coward Fighters Urotander", duet(Miku,KAITO,MEIKO), "ShinP", 235 },
  {"バビロン", "Babylon", "Babylon", Miku, "Tohma", 4989 },
  /* Project Mirai */
  {"逆さまレインボー", "Sakasama Rainbow", "Reverse Rainbow", duet(Rin,Miku), "sunzriverP", 7922 },
  {"ハロ／ハワユ", "Hello/How are you?", "Hello/How are you?", duet(Miku,Gumi), "nanou", 1416 },
  {"マトリョシカ", "Matryoshka", "Matryoshka", duet(Miku,Gumi), "HACHI", 368 },
  {"ハッピーシンセサイザ", "Happy Synthesizer", "Happy Synthesizer", duet(Luka,Gumi), "EasyPop", 3177 },
  /* Mirai 2 */
  {"エレクトリック・ラブ", "Electric Love", "Electric Love", Miku, "HachioujiP", 1389 },
  {"インビジブル", "Invisible", "Invisible", duet(Gumi,Rin), "kemu, Ore BananaP", 8251 },
  {"ドレミファロンド", "DoReMiFa Rondo", "DoReMiFa Rondo", Miku, "40mP", 8601 },
  {"子猫のパヤパヤ", "Koneko no Payapaya", "Payapaya Kitten", duet(Miku,MEIKO), "OnecupP", 5635 },
    };

    return res;
}

constexpr auto casefolded_song_names_tuple = [] {
  constexpr auto all_chars_data = util::generate_casefolded_fields<generate_songs_incomplete, 2, 4,
                                                                     &Song::jp_name, &Song::romanji_name, &Song::name, &Song::producer>();

    constexpr auto total_chars = std::get<2>(all_chars_data);
    std::array<char, total_chars> result_chars;
    const auto& allchars = std::get<0>(all_chars_data);
    std::ranges::copy(allchars | std::views::take(total_chars), result_chars.begin());

    const auto& string_lengths = std::get<1>(all_chars_data);
    constexpr auto total_string_lengths = std::get<3>(all_chars_data);
    std::array<std::size_t, total_string_lengths> result_string_lengths;
    std::ranges::copy(string_lengths | std::views::take(total_string_lengths), result_string_lengths.begin());
    return std::tuple{result_chars, result_string_lengths};
}();

consteval std::vector<Song> generate_songs()
{
    auto res = util::merge_casefolded_fields_from_tuple<Song, generate_songs_incomplete,
                                                        2, 4,
                                                        &Song::cf_jp_name,
                                                        &Song::cf_romanji_name,
                                                        &Song::cf_name,
                                                        &Song::cf_producer>(casefolded_song_names_tuple);
    std::ranges::stable_sort(res, {}, &Song::cf_name);
    return res;
}

export constexpr std::array songs = util::materialize<generate_songs>();

/* There must not be any duplicate songnames in songs. Its sorted, so just check adjacency. */
constexpr auto songs_have_same_names = [](auto l, auto r) constexpr {
    return l.cf_name == r.cf_name && l.disambiguation == r.disambiguation;
};
static_assert(std::ranges::adjacent_find(songs, songs_have_same_names) == std::ranges::end(songs),
              std::ranges::adjacent_find(songs, songs_have_same_names)->cf_name);

/* Everything needs a date. Sometimes. */
//constexpr auto song_has_no_date = [](const auto& song) constexpr { return song.published == 0y/0/0;};
//static_assert(std::ranges::none_of(songs, song_has_no_date),
//              std::ranges::find_if(songs, song_has_no_date)->name);

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

/* Songs should have a vocadb id unless they are NO_VIRTUAL_SINGER */
constexpr auto song_has_no_vocadb_id = [](const auto &song) constexpr {
    return !song.vocadb_id && (song.singer != NO_VIRTUAL_SINGER) && (song.producer != "Kodo"sv);
};
static_assert(std::ranges::none_of(songs, song_has_no_vocadb_id),
              std::ranges::find_if(songs, song_has_no_vocadb_id)->name);


export struct AltName
{
    constexpr AltName(std::string_view alt_name, std::string_view name) noexcept :
        alt_name(alt_name),
        name(name)
    { }
    constexpr AltName() noexcept = default; // Needed for util::materialize
    std::string_view alt_name;
    std::string_view name;
    std::string_view cf_alt_name;
};

constexpr std::vector<AltName> generate_altnames_incomplete()
{
    std::vector<AltName> res = {
            { "Colorful Melody", "Colorful × Melody"},
            { "Colorful x Melody", "Colorful × Melody"},
            { "Fire Flower", "Fire◎Flower"},
            { "FireFlower", "Fire◎Flower"},
            { "Piano Forte Scandal", "Piano × Forte × Scandal"},
            { "Piano x Forte x Scandal", "Piano × Forte × Scandal"},
            { "LLNF", "Luka Luka★Night Fever"},
            { "Luka Luka Night Fever", "Luka Luka★Night Fever"},
            { "Sand Planet", "DUNE"},
            { "Pigeon", "White Dove"},
            { "Beware of the Miku Miku Bacteria", "Beware of the Miku Miku Germs♪"},
            { "01_ballade", "Fragments of a Star"},
            { "01 ballade", "Fragments of a Star"},
            { "Repairers of the Deceptive World", "Whipstitching Person"},
            { "The Pokemon Inside My Heart", "The Pokémon Inside My Heart"},
            { "Heart a la mode", "Heart à la mode"},
            { "MKDR", "Delusional Sentimental Compensation Federation"},
            { "DSCF", "Delusional Sentimental Compensation Federation"},
            { "MKDR DSCF", "Delusional Sentimental Compensation Federation"},
            { "MKDR (DSCF)", "Delusional Sentimental Compensation Federation"},
            { "Though My Song Has No Form", "Though My Song Has No Shape"},
            { "Electrical Forecast", "Electricity Forecast"},
            { "GO! Team BIDOOF", "GO! Team BIPPA"},
            { "Facade Question", "Façade Question"},
            { "OOPARTS", "OOPÁRTS"},
            { "Requiem for the Phantasma [25,Dec]", "Golden Holy Night Rotting into the Frost and Snow" },
            { "Two-Faced Lovers", "Two-Sided Lovers" },
            { "Two Faced Lovers", "Two-Sided Lovers" },
            { "Mobairi Sensation", "MobiRe SenS@tion"},
            { "Mobire Sensation", "MobiRe SenS@tion"},
            { "Mobile Sensation", "MobiRe SenS@tion"},
            { "To the End of Infinity", "To Beyond a Duodecillion"},
            { "Can You Hear It?", "Can You Hear Me?"},
            { "Salome", "Salomé"},
            { "Unrequited Love Samba", "One-Sided Love Samba"},
            { "How'd It Get To Be Like This?", "How Did This Happen"},
            { "The Whimsy Girl", "The Cat-like You"},
            { "The MMORPG Addict's Anthem", "Online Game Addicts Sprechchor" },
            { "Sadistic Music Factory", "Sadistic.Music∞Factory" },
            { "Travel to the Other Side of the Moon", "Travel Beyond the Moon" },
            { "Pinky Swear", "Pinky Promise" },
            { "A Female Ninja, but I Want to Love", "Even a Kunoichi Needs Love" },
            { "Mrs. Pumpkin's Comical Dream", "Humorous Dream of Mrs. Pumpkin" },
    };
    return res;
}

constexpr auto casefolded_altnames_tuple = [] {
    constexpr auto all_chars_data = util::generate_casefolded_fields<generate_altnames_incomplete, 0, 1,
                                                                     &AltName::alt_name>();

    constexpr auto total_chars = std::get<2>(all_chars_data);
    std::array<char, total_chars> result_chars;
    const auto& allchars = std::get<0>(all_chars_data);
    std::ranges::copy(allchars | std::views::take(total_chars), result_chars.begin());

    const auto& string_lengths = std::get<1>(all_chars_data);
    constexpr auto total_string_lengths = std::get<3>(all_chars_data);
    std::array<std::size_t, total_string_lengths> result_string_lengths;
    std::ranges::copy(string_lengths | std::views::take(total_string_lengths), result_string_lengths.begin());
    return std::tuple{result_chars, result_string_lengths};
}();

consteval std::vector<AltName> generate_altnames()
{
    auto res = util::merge_casefolded_fields_from_tuple<AltName, generate_altnames_incomplete,
                                                        0, 1,
                                                        &AltName::cf_alt_name>(casefolded_altnames_tuple);
    std::ranges::stable_sort(res, {}, &AltName::cf_alt_name);
    return res;
}

export constexpr std::array alt_names = util::materialize<generate_altnames>();

export void
song_singer_emoji(std::ostream& os, const Song& song)
{
    if (song.emoji_override) {
        os << *song.emoji_override;
    } else {
        os << singer_to_emoji(song.singer);
    }
    if (song.minor_roles) {
        os << " with " << singer_to_emoji(*song.minor_roles);
    }
}

template <>
struct std::formatter<Song> {
private:
    bool no_emoji = false;
public:
    using context_type = std::format_context;

    constexpr auto parse(std::format_parse_context& ctx) {
        auto it = ctx.begin();
        if (it != ctx.end() && *it == 'e') {
            no_emoji = true;
            ++it;
        }
        return it;
    }

    constexpr auto format(const Song& song, std::format_context& ctx) const {
        std::ostringstream out;
        const bool is_linktext = song.vocadb_id.has_value();
        if (is_linktext) {
            out << '[';
        }
        if (song.jp_name) {
            out << util::escape_markdown(una::norm::to_nfc_utf8(*song.jp_name), is_linktext) << ' ';
            if (song.romanji_name && *song.cf_romanji_name != song.cf_name) {
                out << "(" << util::escape_markdown(una::norm::to_nfc_utf8(*song.romanji_name), is_linktext) << ") ";
            }
            out << "/ ";
        } else {
            // romanji but no jp could be other languages (Venus at the fingertips)
            if (song.romanji_name) {
                out << util::escape_markdown(una::norm::to_nfc_utf8(*song.romanji_name), is_linktext) << " / ";
            }

        }
        out << util::escape_markdown(song.name, is_linktext);
        if (is_linktext) {
            /* to_string avoids locale-dependent digit grouping in URLs */
            out << "](https://vocadb.net/S/" << std::to_string(*song.vocadb_id) << ')';
        }
        if (song.singer != NO_VIRTUAL_SINGER) {
            out << " feat. ";
            if (!no_emoji) {
                song_singer_emoji(out, song);
            } else {
                out << magic_enum::enum_flags_name(song.singer);
                if (song.minor_roles) {
                    out << " with " << magic_enum::enum_flags_name(*song.minor_roles);
                }
            }
        }
        out << " by " << util::escape_markdown(song.producer);
        if (song.singer == NO_VIRTUAL_SINGER
            && (song.minor_roles || song.emoji_override))
        {
            auto emoji = song.emoji_override.transform([](auto sv) { return std::string(sv); })
                .or_else([&song] { return song.minor_roles.transform(&singer_to_emoji); });
            if (emoji) {
                out << " with " << *emoji;
            }
        }
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

export [[nodiscard]] constexpr
std::optional<Song> lookup_song_strict(std::string_view needle, std::optional<std::string_view> producer = std::nullopt)
{
    const auto casefolded_needle = util::to_nfkc_casefold(needle);
    if (auto rng = std::ranges::equal_range(songs, casefolded_needle, std::ranges::less{}, &Song::cf_name);
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

export [[nodiscard]]
std::vector<Song> match_songs(std::string_view needle)
{
    auto cf_needle = util::to_nfkc_casefold(needle);
    const auto name_matches_needle = [needle = cf_needle]
        (const Song& song) constexpr {
        return std::ranges::contains_subrange(song.cf_name, needle);
    };
    auto comparitor = [](const Song& a, const Song& b) constexpr { return a.name < b.name; };
    auto res = songs | std::views::filter(name_matches_needle) | std::ranges::to<std::set>(comparitor);
    constexpr auto MAX_AUTOCOMPLETE_CHOICES = 25Z;

    if (res.size() >= MAX_AUTOCOMPLETE_CHOICES) {
        return std::views::common(res) | std::ranges::to<std::vector>();
    }

    const auto has_romanji = [](const auto &song) constexpr {
        return song.cf_romanji_name.has_value(); };
    const auto romanji_matches_needle = [needle = cf_needle]
        (const Song& song) {
        return std::ranges::contains_subrange(*song.cf_romanji_name, needle);
    };
    std::ranges::copy_if(std::views::filter(songs, has_romanji),
                         std::inserter(res, std::ranges::begin(res)),
                         romanji_matches_needle);

    if (res.size() >= MAX_AUTOCOMPLETE_CHOICES) {
        return std::views::common(res) | std::ranges::to<std::vector>();
    }

    const auto has_jp = [](const auto &song) constexpr {
        return song.cf_jp_name.has_value(); };
    const auto jp_matches_needle = [needle = cf_needle]
        (const Song& song) {
        return std::ranges::contains_subrange(*song.cf_jp_name, needle);
    };

    std::ranges::copy_if(std::views::filter(songs, has_jp),
                         std::inserter(res, std::ranges::begin(res)),
                         jp_matches_needle);

    if (res.size() >= MAX_AUTOCOMPLETE_CHOICES) {
        return std::views::common(res) | std::ranges::to<std::vector>();
    }


    const auto altname_matches_needle = [needle = cf_needle]
        (const AltName& altname) {
        return std::ranges::contains_subrange(altname.cf_alt_name, needle);
    };

    const auto altname_xform = [] (const AltName& altname) {
      return *lookup_song(altname.name);
    };

    std::ranges::copy(std::views::filter(alt_names, altname_matches_needle) |
                      std::views::transform(altname_xform),
                      std::inserter(res, std::ranges::begin(res)));

    return res | std::ranges::to<std::vector>();
}

export [[nodiscard]]
std::vector<std::tuple<std::int64_t, Song>> match_songs_indexed(std::string_view needle)
{
  auto indexed_songs = std::views::enumerate(songs);
  auto cf_needle = util::to_nfkc_casefold(needle);

  const auto name_matches_needle = [needle = cf_needle]
    (const auto& pair) constexpr {
    return std::ranges::contains_subrange(std::get<1>(pair).cf_name, needle);
  };
  auto comparitor = [](const auto& a, const auto& b) constexpr { return std::get<0>(a) < std::get<0>(b); };
  auto res = indexed_songs | std::views::filter(name_matches_needle) | std::ranges::to<std::set>(comparitor);

  constexpr auto MAX_AUTOCOMPLETE_CHOICES = 25Z;

  if (res.size() >= MAX_AUTOCOMPLETE_CHOICES) {
    return std::views::common(res) | std::ranges::to<std::vector>();
  }

  const auto has_romanji = [](const auto &pair) constexpr {
    return std::get<1>(pair).cf_romanji_name.has_value(); };
  const auto romanji_matches_needle = [needle = cf_needle]
    (const auto& pair) {
    return std::ranges::contains_subrange(*std::get<1>(pair).cf_romanji_name, needle);
  };
  std::ranges::copy_if(std::views::filter(indexed_songs, has_romanji),
                       std::inserter(res, std::ranges::begin(res)),
                       romanji_matches_needle);

  if (res.size() >= MAX_AUTOCOMPLETE_CHOICES) {
    return std::views::common(res) | std::ranges::to<std::vector>();
  }


  const auto has_jp = [](const auto &pair) constexpr {
    return std::get<1>(pair).cf_jp_name.has_value(); };
  const auto jp_matches_needle = [needle = cf_needle]
    (const auto& pair) {
    return std::ranges::contains_subrange(*std::get<1>(pair).cf_jp_name, needle);
  };

  std::ranges::copy_if(std::views::filter(indexed_songs, has_jp),
                       std::inserter(res, std::ranges::begin(res)),
                       jp_matches_needle);

  if (res.size() >= MAX_AUTOCOMPLETE_CHOICES) {
    return std::views::common(res) | std::ranges::to<std::vector>();
  }


  const auto altname_matches_needle = [needle = cf_needle]
    (const AltName& altname) {
    return std::ranges::contains_subrange(altname.cf_alt_name, needle);
  };

  const auto altname_xform = [&indexed_songs] (const AltName& altname) {
    return *std::ranges::find(indexed_songs, altname.name, [](const auto& pair) { return std::get<1>(pair).name; });
  };

  std::ranges::copy(std::views::filter(alt_names, altname_matches_needle) |
                    std::views::transform(altname_xform),
                    std::inserter(res, std::ranges::begin(res)));
  return res | std::ranges::to<std::vector>();

}

export [[nodiscard]]
std::vector<Song> match_producers(std::string_view needle)
{
  auto cf_needle = util::to_nfkc_casefold(needle);
  const auto producer_matches_needle = [needle = cf_needle]
    (const Song& song) constexpr {
    return std::ranges::contains_subrange(song.cf_producer, needle);
  };
  auto comparitor = [](const Song& a, const Song& b) constexpr { return a.name < b.name; };
  auto res = songs | std::views::filter(producer_matches_needle) | std::ranges::to<std::set>(comparitor);
  return std::views::common(res) | std::ranges::to<std::vector>();
}

export [[nodiscard]]
std::vector<std::tuple<std::int64_t, Song>> match_producers_indexed(std::string_view needle)
{
  auto indexed_songs = std::views::enumerate(songs);
  auto cf_needle = util::to_nfkc_casefold(needle);

  const auto producer_matches_needle = [needle = cf_needle]
    (const auto& pair) constexpr {
    return std::ranges::contains_subrange(std::get<1>(pair).cf_producer, needle);
  };
  auto comparitor = [](const auto& a, const auto& b) constexpr { return std::get<0>(a) < std::get<0>(b); };
  auto res = indexed_songs | std::views::filter(producer_matches_needle) | std::ranges::to<std::set>(comparitor);

  return std::views::common(res) | std::ranges::to<std::vector>();
}


export [[nodiscard]]
std::string
get_random_songname(auto &&rng_engine)
{
    std::uniform_int_distribution<size_t> dist(0, songs.size() - 1);
    const auto& song = songs[dist(rng_engine)];

    return std::format("{} by {}", song.name, song.producer);
}

export constexpr std::size_t AUTOCOMPLETE_CHOICE_NAME_MAX_LENGTH = 100;

/* Returns the longest prefix of s that is at most max_bytes bytes and ends on a grapheme cluster boundary. */
std::string_view utf8_truncate(std::string_view s, std::size_t max_bytes)
{
    if (s.size() <= max_bytes) return s;
    std::size_t safe_len = 0;
    for (auto cluster : una::ranges::grapheme::utf8_view{s}) {
        if (safe_len + cluster.size() > max_bytes) break;
        safe_len += cluster.size();
    }
    return s.substr(0, safe_len);
}

export [[nodiscard]]
std::string
get_autocomplete_text_for_song(const Song& song)
{
    constexpr std::size_t BY_SEP_LEN = 4; /* " by " */
    constexpr std::size_t MAX_PRODUCER = 40;
    constexpr std::size_t ELLIPSIS_LEN = 3;

    auto prod = song.producer.size() > MAX_PRODUCER
        ? std::string(utf8_truncate(song.producer, MAX_PRODUCER - ELLIPSIS_LEN)) + "..."
        : std::string(song.producer);
    const auto name_budget = AUTOCOMPLETE_CHOICE_NAME_MAX_LENGTH - BY_SEP_LEN - prod.size();
    auto name = song.name.size() > name_budget
        ? std::string(utf8_truncate(song.name, name_budget - ELLIPSIS_LEN)) + "..."
        : std::string(song.name);
    return una::norm::to_nfc_utf8(std::format("{} by {}", name, prod));
}

struct spreadsheet
{
    std::string_view jp_name;
    std::string_view producer;
    std::string_view singer;
};
