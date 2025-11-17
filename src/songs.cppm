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
  {"いーあるふぁんくらぶ", "Ii Aru Fanclub", "1 2 FanClub", duet(Rin, Len), "Mikito-P", 15785},
  {"いーあるふぁんくらぶ", "Ii Aru Fanclub", "1 2 FanClub (Chinese ver.)", duet(Rin, Len), "Mikito-P", 15785, "Chinese ver."},
  {"二次元ドリームフィーバー", "Nijigen Dream Fever", "2D Dream Fever", Miku, "PolyphonicBranch", 9376},
  {"39", "San Kyuu", "39 (Thank You)", Miku, "sasakure.UK, DECO*27", 14480, nullopt, nullopt, "<a:mikuarigathanks:941692452794933248>"},
  {nullopt, nullopt, "8HIT", duet(Rin, Len), "Wonderful☆Opportunity", 9210},
  {nullopt, nullopt, "ANIMAL", Len, "oQ", 359211},
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
  {nullopt, nullopt, "Just Be Friends (English ver.)", Luka, "Dixie Flatline, Rockleetist", 69073},
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
  {nullopt, nullopt, "Sharing The World (Spanish ver.)", Miku, "BIGHEAD, Maubox", 182370},
  {"夜舞うシルエット", "Yomau Silhouette", "Silhouette Dancing in the Night", MEIKO, "Miyamori Bungaku", 542682},
  {nullopt, nullopt, "Snow Fairy Story", Miku, "40mP", 79094, nullopt, nullopt, "<a:mikusnowrng:926685701494435870>"},
  {"スノーマン", "Snowman", "Snowman", KAITO, "halyosy", 65736},
  {"シャボン", "Shabon", "Soap", Miku, "Kuriyama Yuri", 239350},
  {nullopt, nullopt, "Someday'z Coming", Luka, "Shoten Taro", 258338},
  {"紡唄 -つむぎうた-", "Tsumugi Uta", "Spinning Song", duet(Rin, Len), "DATEKEN", 2285},
  {"紡唄 -つむぎうた-", "Tsumugi Uta", "Spinning Song (Chinese ver.)", duet(Rin, Len), "DATEKEN", 221275, "Chinese ver."},
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
  {"歌に形はないけれど", "Uta ni Katachi wa Nai Keredo", "Though My Song Has No Shape (Chinese ver.)", Miku, "doriko", 326239, "Chinese ver."},
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
  {nullopt, nullopt, "celluloid", Miku, "baker", 289839},
  {nullopt, nullopt, "glow", Miku, "keeno", 1797},
  {nullopt, nullopt, "imaginary love story", Miku, "Synthion", 481543},
  {nullopt, nullopt, "letter song", Miku, "doriko", 1077},
  {nullopt, nullopt, "lost and found", Luka, "ashcolor", 43499, nullopt, Miku},
  {nullopt, nullopt, "magnet", duet(Miku, Luka), "minato", 5166},
  {nullopt, nullopt, "on the rocks", duet(MEIKO, KAITO), "OSTER Project", 203921},
  {"アングレイデイズ", "Ungray Days", "ungray days", Rin, "Tsumiki", 282018},
  {nullopt, nullopt, "vivid", duet(Miku, Luka), "Utsu-P, Yuyoyuppe", 306270},//MEOWWWWWWWWWWWWWWWWWWW
  {nullopt, nullopt, "Sweet Devil", Miku, "Hachioji-P"},
  {"どうぶつ占い", "Doubutsu Uranai", "Animal Fortune-telling", Miku, "Scop"},
  {nullopt, nullopt, "erase or zero", duet(Len,KAITO), "Crystal-P"},
  {"スキキライ", "Suki Kirai", "Love-Hate", duet(Rin,Len), "HoneyWorks"},
  {nullopt, nullopt, "shake it!", duet(Miku,Rin,Len), "emon(Tes.)"},
  {nullopt, nullopt, "Leia", Luka, "Yuyoyuppe"},
  {nullopt, nullopt, "FREELY TOMORROW", Miku, "Mitchie M"},
  {nullopt, nullopt, "1/6 -out of the gravity-", Miku, "Vocaliod-P"},
  {"カゲロウデイズ", "Kagerou Deizu", "Kagerou Daze", Miku, "Jin"},
  {"心臓デモクラシー", "Shinzou Demokurashii", "Heart Democracy", Miku, "Mikito-P"},
  {"ワンダーランドと羊の歌", "Wandaarando to Hitsuji no Uta", "Wonderland and the Sheep's Song", Miku, "Hachi"},
  {nullopt, nullopt, "EARTH DAY", Miku, "HarryP"},
  {"はじめまして地球人さん", "Hajimemashite Chikyuujin-san", "Nice to Meet You, Mr. Earthling", Miku, "Pinocchio-P"},
  {"恋愛裁判", "Ren'ai Saiban", "Love Trial", Miku, "40mP"},
  {"ロストワンの号哭", "Rosuto Wan no Goukoku", "Lost One's Weeping", Rin, "Neru"},
  {"愛Dee", nullopt, "Ai Dee", duet(Miku,Luka), "Mitchie M"},
  {nullopt, nullopt, "Packaged", Miku, "livetune"},
  {nullopt, nullopt, "Hand in Hand", Miku, "livetune"},
  {"39みゅーじっく！", "39みゅーじっく", "39 Music!", Miku, "Mikito-P", nullopt, nullopt, nullopt , "<:makuharichan:630043704501075968>"},
  {nullopt, nullopt, "Strangers", Miku, "Heavenz"},
  {"すろぉもぉしょん", nullopt, "SLoWMoTIoN", Miku, "Pinocchio-P"},
  {"タイムマシン", nullopt, "Time Machine", Miku, "40mP"},
  {"どりーみんチュチュ", nullopt, "Dreamin Chuchu", Luka, "emon(Tes.)", nullopt, nullopt, duet(Miku,Rin), "<:chuchu:317055647826837504>"},
  {nullopt, nullopt, "Calc.", Miku, "JimmyThumb-P"},
  {"ウミユリ海底譚", "Umiyuri Kaiteitan", "Tale of the Deep-sea Lily", Miku, "n-buna"},
  {"テレカクシ思春期", "Terekakushi Shishunki", "Embarrassment-Hiding Adolescence", Len, "HoneyWorks"},
  {nullopt, nullopt, "Baby Maniacs -Eight Mix-", Miku, "Hachioji-P"},
  {nullopt, nullopt, "ray", Miku, "BUMP OF CHICKEN"},
  {"なりすましゲンガー", "Narisumashi Genga", "Doubleganger", duet(Miku,Rin), "KulfiQ"},
  {nullopt, nullopt, "Singularity", Miku, "keisei"},
  {"ツギハギスタッカート", "Tsugihagi Staccato", "Patchwork Staccato", Miku, "toa"},
  {"サイハテ", "Saihate", "The Farthest Ends", Miku, "Kobayashi Onyx"},
  {nullopt, nullopt, "TODAY THE FUTURE", Miku, "HarryP"},
  {nullopt, nullopt, "DECORATOR", Miku, "livetune", nullopt, nullopt, duet(Rin,Len,Luka,MEIKO,KAITO)},
  {"孤独の果て", "Kodoku no Hate", "Solitude's End", Rin, "Hikarisyuyo"},
  {"リバースユニバース", nullopt, "Reverse Universe", Miku, "NayutalieN"},
  {"グリーンライツ・セレナーデ", nullopt, "Greenlights Serenade", Miku, "Omoi", nullopt, nullopt, nullopt, "<a:mikuhyperwota:696421739298816020>"},
  {"愛の詩", "Ai no Uta", "Love Song", Miku, "LamazeP"},
  {"快晴", "Kaisei", "Kaisei", Miku, "Orangestar"},
  {"深海シティアンダーグラウンド", "Shinkai City Underground", "Deep Sea City Underground", Rin, "TanakaB"},
  {"メインキャラクター", nullopt, "Main Character", Len, "*Luna"},
  {"ある計画は今も密かに", "Aru Keikaku wa Ima mo Hisoka ni", "A Plan Is Still In Progress Covertly", Miku, "Shinra"},
  {"ぶれないアイで", "Burenai ai de", "Burenai ai de", Miku, "Mitchie M"},
  {"僕が夢を捨てて大人になるまで", "Boku ga Yume o Sutete Otona ni Naru made", "Until I throw away my dreams and become an adult", Miku, "Kasamura Tota"},
  {"ブレス・ユア・ブレス", nullopt, "Bless Your Breath", Miku, "Takeaki Wada"},
  {"太陽系デスコ", "Taiyoukei Desuko", "Solar System Disco", Miku, "NayutalieN"},
  {nullopt, nullopt, "YY", Miku, "23.exe", nullopt, nullopt, nullopt, "<a:mikupolydab:729383800525815888>"},
  {"まるいうなばら", "Marui Unabara", "Spheric Ocean", Miku, "GoBS"},
  {nullopt, nullopt, "Amazing Dolce", duet(MEIKO,Rin,Len), "Hitoshizuku-P×Yama△"},
  {"きみとぼくのレゾナンス", "Kimi to Boku no Rezonansu", "Resonance Between You and Me", MEIKO, "Nanameue-P"},
  {"キミペディア", nullopt, "Kimipedia", duet(Rin,Len), "Junky"},
  {"愛されなくても君がいる", "Aisarenakute mo Kimi ga Iru", "Because You're Here", Miku, "Pinocchio-P"},
  {"え？あぁ、そう。", "E? Aa, Sou.", "Hm? Ah, Yes.", Miku, "Chouchou-P"},
  {"ぽかぽかの星", "Pokapoka no Hoshi", "Poka Poka Planet", Miku, "Harumaki Gohan", nullopt, nullopt, nullopt, "<:mikusip:657898170411515904>"},
  {"アルビノ -revive-", nullopt, "Albino", Miku, "buzzG"},
  {"テルミーアンサー", nullopt, "Tell Me Answer", Rin, "kinoshita"},
  {"星空クロノグラフ", "Hoshizora Chronograph", "Chronograph in the Starry Sky", MEIKO, "MINO-U"},
  {nullopt, nullopt, "First Note", Miku, "blues"},
  {"サンドリヨン", nullopt, "Cendrillon", duet(Miku,KAITO), "Signal-P"},
  {"レイニースノードロップ", nullopt, "Rainy Snowdrop", KAITO, "Re:nG"},
  {"インタビュア", nullopt, "Interviewer", Luka, "Kuwagata-P"},
  {"初音天地開闢神話", "Hatsune Tenchikaibyaku Shinwa", "Hatsune Creation Myth", Miku, "cosMo"},
  {"ネクストネスト", nullopt, "Next Nest", Miku, "TENKOMORI"},
  {nullopt, nullopt, "FLASH", KAITO, "Kashii Moimi"},
  {"#心がどっか寂しいんだ", "＃Kokoro ga Dokka Sabishiinda", "＃I Feel Kinda Lonely", Len, "Kanzaki Iori"},
  {nullopt, nullopt, "Loading Memories", Miku, "Sekikomi Gohan"},
  {"フューチャー・イヴ", nullopt, "FUTURE EVE", Miku, "sasakure.UK"},
  {nullopt, nullopt, "Blessing", duet(Miku,Luka,Rin,Len,KAITO,MEIKO), "halyosy"},
  {"すーぱーぬこになれんかった", "Suupaa Nuko ni Narenkatta", "I Couldn't Become a Super Cat After All", Len, "Mafumafu", nullopt, nullopt, Rin},
  {nullopt, nullopt, "Snowmix♪", Miku, "marasy"},
  {"神っぽいな", "Kamippoi na", "God-ish", Miku, "Pinocchio-P"},
  {"ヘッジホッグ", nullopt, "Hedgehog", Rin, "Noz."},
  {"king妃jack躍", "king Ki jack Yaku", "King Queen Jack Dance", Miku, "Miyamori Bungaku"},
  {"抜錨", "Batsubyou", "Weigh Anchor", Luka, "Nanahoshi Kangengakudan"},
  {"敗走", nullopt, "Haisou", KAITO, "Kasamura Tota"},
  {nullopt, nullopt, "drop pop candy", duet(Rin,Luka), "GigaReol"},
  {"フェレス", nullopt, "Pheles", duet(Miku,MEIKO), "Kuriyama Yuri"},
  {"ブループラネット", nullopt, "Blue Planet", Miku, "DECO*27"},
  {"Birthday Song for ミク", nullopt, "Birthday Song for Miku", duet(Rin,Len,Luka,MEIKO,KAITO), "Mitchie M"},
  {nullopt, nullopt, "HERO", Miku, "Ayase"},
  {"ブリキノダンス", "Buriki no Dansu", "Tinplate's Dance", Miku, "Hinata Electric Works"},
  {"混沌ブギ", nullopt, "Konton Boogie", Miku, "jon-YAKITORY"},
  {nullopt, nullopt, "SUPERHERO", Len, "Mellowcle"},
  {nullopt, nullopt, "Call!!", KAITO, "Matsubi"},
  {nullopt, nullopt, "TYQOON", MEIKO, "Sohbana"},
  {"流星のパルス", "Ryuusei no Parusu", "Pulse of The Meteor", Len, "*Luna"},
  {"踊", nullopt, "Odo", duet(Rin,Len), "Giga × TeddyLoid × DECO*27"},
  {"陽だまりのセツナ", "Hidamari no Setsuna", "A moment in the sun", duet(Miku,Luka), "Akano Y"},
  {"初めての恋が終わる時", "Hajimete no Koi ga Owaru Toki", "When First Love Ends", Miku, "ryo"},
  {"アンテナ39", nullopt, "Antenna 39", Miku, "Hiiragi Magnetite"},
  {"ボルテッカー", nullopt, "Volt Tackle", Miku, "DECO*27"},
  {"ヒアソビ", "Hiasobi", "Play With Fire", Miku, "Camellia"},
  {"こちら、幸福安心委員会です。", "Kochira, Koufuku Anshin Iinkai desu.", "This is, the Happiness and Peace of Mind Committee.", Miku, "UtataP"},
  {nullopt, nullopt, "MAGA MAGA", Luka, "Yurei Ichimonji"},
  {"ラヴィ", nullopt, "Lavie", Len, "Surii"},
  {"少女A", "Shoujo A", "Young Girl A", Rin, "Powapowa-P"},
  {"ヴァニッシュ", nullopt, "Vanish", KAITO, "Guchiry"},
  {"げんてん", "Genten", "origin", MEIKO, "Daibaku Hashin"},
  {nullopt, nullopt, "Flyway", duet(KAITO,Len), "halyosy"},
  {nullopt, nullopt, "stargazeR", Miku, "Kotsuban-P"},
  {"黙ってロックをやれって言ってんの！", "Damatte Rock o Yare tte Itten no!", "DO THE ROCK!", duet(MEIKO,Miku,Rin,Luka), "Nekotachi Kotatsu"},
  {"ストリートライト", nullopt, "Street Light", duet(Miku,Luka,Rin,Len,MEIKO,KAITO), "Negi Shower P"},
  {"ラストラス", nullopt, "Lustrous", Miku, "*Luna"},
  {"ステラ", "Stella", "Stella", Miku, "Kotsuban-P", nullopt, nullopt, nullopt, "<a:mikusnowrng:926685701494435870>"},
  {"雪がとける前に", "Yuki ga Tokeru Mae ni", "Before the Snow Melts", Miku, "doriko", nullopt, nullopt, nullopt, "<a:mikusnowrng:926685701494435870>"},
  {"スターナイトスノウ", "Star Night Snow", "Star Night Snow", Miku, "n-buna×Orangestar", nullopt, nullopt, nullopt, "<a:mikusnowrng:926685701494435870>"},
  {"你好", "Nǐhǎo", "Hello", Miku, "MusikM"},
  {"初嵐", "Chūlán", "First Storm", Miku, "DECO*27"},
  {nullopt, nullopt, "Shining Star (Miku cover)", Miku, "Unknown", 326238},
  {"越过海岸线", "Yuèguò Hǎi'ànxiàn", "Crossing Over the Coastline", Miku, "kz"},
  {nullopt, nullopt, "Pick Me Up", Miku, "Demon"},
  {"COME BACK~重返巅峰~", "COME BACK ~Chóng Fǎn Diānfēng~", "COME BACK ~Returning to the Peak~", Miku, "Mikunya"},
  {"踏步、出发", "Tàbù, Chūfā", "Step Forward", Miku, "MACHWOLF"},
  {nullopt, nullopt, "My Stage With You", Miku, "cannibaltim"},
  {"梦色星球", "Mèngsè Xīngqiú", "Dream Color Planet", Miku, "AzureHead"},
  {"跨时空日记", "Kuà Shíkōng Rìjì", "Diary Across Time And Space", Miku, "Siren"},
  {nullopt, "Project DIVA desu.", "It's Project DIVA.", Miku, "UtataP"},
  {"サウンド", "Sound", "sound", Miku, "baker"},
  {"恋スルVOC@LOID", "Koisuru VOC@LOID", "VOC@LOID in Love", Miku, "OSTER project"},
  {nullopt, nullopt, "Dear cocoa girls", Miku, "Hata Aki, Kosaku Satoru"},
  {nullopt, nullopt, "The secret garden", Miku, "Hata Aki, Kosaki Satoru"},
  {"ミラクルペイント", "Miracle Paint", "Miracle Paint", Miku, "OSTER project"},
  {nullopt, nullopt, "Innocence", Miku, "KazuP"},
  {"ハト", "Hato", "White Dove", Miku, "Hadano-P"},
  {"みくみく菌にご注意♪", "Miku Miku-kin ni Gochuui♪", "Beware of the Miku Miku Germs♪", Miku, "Hayaya-P"},
  {"サヨナラ・グッバイ", "Sayonara·Goodbye", "Farewell Goodbye", Miku, "Noboru↑-P"},
  {nullopt, nullopt, "Dear", Miku, "19's Sound Factory"},
  {"教えて!! 魔法のLyric", "Oshiete!! Mahou no Lyric", "Tell Me!! The Magical Lyric", duet(Miku, MEIKO), "Chom-P"},
  {"パズル", "Puzzle", "Puzzle", Miku, "Kuwagata-P"},
  {nullopt, nullopt, "VOiCE", Miku, "Lovely-P"},
  {nullopt, nullopt, "Alice", Miku, "Furukawa-P"},
  {"あなたの歌姫", "Anata no Utahime", "Your Diva", Miku, "azuma"},
  {nullopt, nullopt, "moon", Miku, "iroha(sasaki)"},
  {nullopt, nullopt, "Promise", duet(Miku, Rin), "samfree"},
  {nullopt, nullopt, "from Y to Y", duet(Miku, Luka), "JimmyThumb-P"},
  {"ストロボナイツ", "Strobe Nights", "Strobe Nights", Miku, "kz"},
  {"ファインダー", "Finder", "finder", Miku, "kz"},
  {"クローバー♣クラブ", "Clover♣Club", "Clover♣Club", Miku, "Yuuyu-P"},
  {nullopt, nullopt, "World's End Dancehall (English ver.)", duet(Miku, Luka), "wowaka"},
  {"電気の恋人 -Programmer’s Song-", "Denki no Koibito -Programmer's Song-", "Electric Lovers - I am Programmer's Song", Miku, "MOSAIC.WAV×ika"},
  {nullopt, nullopt, "HATSUNEtive", Miku, "MOSAIC.WAV×ika"},
  {"私は人間じゃないから.", "Watashi wa Ningen ja Nai kara.", "Maybe I'm not a human.", Miku, "Deadball-P"},
  {"とある娼婦の恋", "Toaru Shoufu no Koi", "A Certain Prostitute's Love", duet(Miku, Rin), "Deadball-P"},
  {"牛乳飲め！", "Gyuunyuu Nome!", "You Should Drink Milk!", Miku, "Deadball-P"},
  {"木枯らしの朝", "Kogarashi no Asa", "Anyway the Wind Blows", Miku, "Deadball-P"},
  {"筆おろし", "Fude Oroshi", "First Time", Miku, "Deadball-P"},
  {"既成事実", "Kisei Jijitsu", "I Remember About You Forever", Miku, "Deadball-P"},
  {nullopt, nullopt, "Far Away", Miku, "kz"},
  {nullopt, nullopt, "Heart Beat", Miku, "kz", 5232},
  {nullopt, nullopt, "Crosslight", duet(Miku, Gumi), "kz"},
  {"ブラック★ロックシューター", "Black★Rock Shooter", "Black★Rock Shooter", Miku, "ryo"},
  {"＊ハロー、プラネット。", "*Hello, Planet.", "*Hello, Planet.", Miku, "sasakure.UK"},
  {"番凩", "Tsugai Kogarashi", "Wintry Winds", duet(MEIKO, KAITO), "hinayukki@sigotositeP"},
  {"タイムリミット", "Time Limit", "Time Limit", Miku, "Tatami-P"},
  {nullopt, nullopt, "Ievan Polkka", Miku, "Otomania", nullopt, nullopt, nullopt, "<:leek:235219960425611264>"},
  {"崩壊歌姫 -disruptive diva-", "Houkai Utahime", "Disruptive Diva", Miku, "Machigerita-P"},
  {nullopt, nullopt, "RIP=RELEASE", Luka, "minato"},
  {nullopt, nullopt, "Japanese Ninja No.1", Luka, "Deadball-P"},
  {nullopt, nullopt, "trick and treat",  duet(Rin, Len), "OSTER project"},
  {"悪ノ娘", "Aku no Musume", "Daughter of Evil (The Princess of Lucifer)", Rin, "mothy"},
  {"悪ノ召使", "Aku no Meshitsukai", "Servant of Evil (His Significance of Existence)", duet(Rin, Len), "mothy"},
  {"いろは唄", "Iroha Uta", "Iroha Song", Rin, "Ginsaku"},
  {"リンリンシグナル", "Rin Rin Signal", "Rin Rin Signal", duet(Rin, Len), "Signal-P"},
  {nullopt, nullopt, "SPICE!", Len, "minato"},
  {nullopt, nullopt, "ARiA", Miku, "Toku-P"},
  {nullopt, nullopt, "01_ballade", Miku, "Eiji Hirasawa", 2241},
  {"私の時間", "Watashi no Jikan", "My Time", Miku, "Kuchibashi-P"},
  {nullopt, nullopt, "BURNING", NO_VIRTUAL_SINGER, "Kodo"},
  {nullopt, nullopt, "SHAKE", Miku, "Kodo"},
  {"巴", "Tomoe", "Tomoe", NO_VIRTUAL_SINGER, "Kodo"},
  {"峰の風", "Mine no Kaze", "Peak of the Wind", Miku, "Kodo"},
  {"紅一葉", "Akahitoha", "A Single Red Leaf", Miku, "Kurousa-P"},
  {"能管＋平胴", "Nokan＋hirado", "Flute＋Flat Frame", NO_VIRTUAL_SINGER, "Kodo"},
  {"三宅", "Miyake", "Miyake", NO_VIRTUAL_SINGER, "Kodo"},
  {"巡", "Meguru", "Patrol", NO_VIRTUAL_SINGER, "Kodo", nullopt, nullopt, Miku},
  {"族", "Zoku", "Tribe", Miku, "Kodo"},
  {"南部牛追歌", "Nanbu Ushioi Uta", "Southern Cattle-Chasing Song", Miku, "Kodo"},
  {"韋駄天", "Idaten", "Idaten", NO_VIRTUAL_SINGER, "Kodo"},
  {"NEPPUU〜熱風〜", "Neppuu〜Neppuu〜", "NEPPUU ~Blistering Wind~", Miku, "Mikito-P", nullopt, nullopt, nullopt, "<a:mikubongo:768370491634614293>"},
  {"いのちもやしてたたけよ", "Inochi Moyashite Tatake yo", "Let Your Life Be Vigorous and Open Your Mouth", Miku, "Kodo"},
  {"祭りだヘイカモン", "Matsuri da Hey Come On", "It's a Festival, Hey, C'mon", Miku, "Pinocchio-P"},
  {nullopt, nullopt, "LION", NO_VIRTUAL_SINGER, "Kodo"},
  {nullopt, nullopt, "Artifact", Miku, "buzzG"},
  {"水色侵略", "Mizuiro Shinryaku", "Light Blue Invasion", Miku, "NayutalieN", 294036},
  {"世界の真ん中を歩く", "Sekai no Mannaka o Aruku", "Walking in the Center of the World", Miku, "natsushiro", 152288},
  {"バイオレンストリガー", "Violence Trigger", "Violence Trigger", Miku, "Hachioji-P", 219144},
  {"マカロン", "MACARON", "MACARON", Miku, "ATOLS", 15565},
  {"カガリビト", "Kagaribito", "Whipstitching Person", Miku, "millstones", 298},
  {"ビターチョコデコレーション", "Bitter Choco Decoration", "Bitter Chocolate Decoration", Miku, "syudou", 221277},
  {"未来最終戦争", "Mirai Saishuu Sensou", "Future Final Wars", Miku, "DIVELA", 271920},
  {"ロンリーユニバース", "Lonely Universe", "Lonely Universe", Miku, "Aqu3ra", 232181},
    };

    return res;
}

constexpr auto casefolded_song_names_tuple = [] {
    constexpr auto all_chars_data = util::generate_casefolded_fields<generate_songs_incomplete, 2, 3,
                                                                     &Song::jp_name, &Song::romanji_name, &Song::name>();

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
                                                        2, 3,
                                                        &Song::cf_jp_name,
                                                        &Song::cf_romanji_name,
                                                        &Song::cf_name>(casefolded_song_names_tuple);
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
        if (song.vocadb_id) {
            out << '[';
        }
        if (song.jp_name) {
            out << util::escape_markdown(una::norm::to_nfc_utf8(*song.jp_name)) << ' ';
            if (song.romanji_name && *song.cf_romanji_name != song.cf_name) {
                out << "(" << util::escape_markdown(una::norm::to_nfc_utf8(*song.romanji_name)) << ") ";
            }
            out << "/ ";
        } else {
            // romanji but no jp could be other languages (Venus at the fingertips)
            if (song.romanji_name) {
                out << util::escape_markdown(una::norm::to_nfc_utf8(*song.romanji_name)) << " / ";
            }

        }
        out << song.name;
        if (song.vocadb_id) {
            out << "](https://vocadb.net/S/" << *song.vocadb_id << ')';
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

    if (res.size() >= 25) {
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

    if (res.size() >= 25) {
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

    if (res.size() >= 25) {
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
std::string
get_random_songname(auto &&rng_engine)
{
    std::uniform_int_distribution<size_t> dist(0, songs.size() - 1);
    const auto& song = songs[dist(rng_engine)];

    return std::format("{} by {}", song.name, song.producer);
}

struct spreadsheet
{
    std::string_view jp_name;
    std::string_view producer;
    std::string_view singer;
};
