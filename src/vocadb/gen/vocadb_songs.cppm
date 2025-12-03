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

/* THIS IS A GENERATED FILE, DO NOT EDIT DIRECTLY */

module;

export module vocadb.songs;

import std;
import vocadb.api;

namespace vocadb {

using namespace std::literals;


/* Start Song 2924: *Hello, Planet. */

constexpr std::array<additional_name, 2> names_song_2924 {{
  {"Japanese"sv, R"XYX(＊ハロー、プラネット。)XYX"sv},
  {"English"sv, R"XYX(*Hello, Planet.)XYX"sv},
}};

constexpr std::array<web_link, 6> web_links_song_2924 {{
  {"Reference"sv, R"XYX(Vocaloid Wiki)XYX"sv, R"XYX(http://vocaloid.wikia.com/wiki/%EF%BC%8A%E3%83%8F%E3%83%AD%E3%83%BC%E3%80%81%E3%83%97%E3%83%A9%E3%83%8D%E3%83%83%E3%83%88%E3%80%82_(%EF%BC%8AHello,_Planet.))XYX"sv, 2803 },
  {"Reference"sv, R"XYX(NicoNicoPedia)XYX"sv, R"XYX(http://dic.nicovideo.jp/v/sm7138245)XYX"sv, 8155 },
  {"Commercial"sv, R"XYX(Spotify)XYX"sv, R"XYX(https://play.spotify.com/track/1mzhH0i5vu4EHaBieD44GA)XYX"sv, 62450 },
  {"Reference"sv, R"XYX(MikuWiki)XYX"sv, R"XYX(http://www5.atwiki.jp/hmiku/pages/5355.html)XYX"sv, 62451 },
  {"Reference"sv, R"XYX(UtaiteDB)XYX"sv, R"XYX(http://utaitedb.net/S/4188)XYX"sv, 67551 },
  {"Reference"sv, R"XYX(Vocaloid Lyrics Wiki)XYX"sv, R"XYX(https://vocaloidlyrics.miraheze.org/wiki/＊ハロー、プラネット。_(＊Hello,_Planet.))XYX"sv, 74018 },
}};


#if __has_embed("song_pic_orig_2924.jpg") == __STDC_EMBED_FOUND__
constexpr std::array song_pic_orig_2924 = std::to_array<std::uint8_t>({
    #embed "song_pic_orig_2924.jpg"
});
#else
constexpr std::array<std::uint8_t, 0> song_pic_orig_2924;
#endif

constexpr std::array<std::uint8_t, 0> song_pic_small_thumb_2924;


#if __has_embed("song_pic_thumb_2924.jpg") == __STDC_EMBED_FOUND__
constexpr std::array song_pic_thumb_2924 = std::to_array<std::uint8_t>({
    #embed "song_pic_thumb_2924.jpg"
});
#else
constexpr std::array<std::uint8_t, 0> song_pic_thumb_2924;
#endif

constexpr std::array<std::uint8_t, 0> song_pic_tiny_thumb_2924;

constexpr picture picture_song_2924 = { std::nullopt, std::nullopt, R"XYX(https://i1.ytimg.com/vi/4wnKSR--bKI/hqdefault.jpg)XYX"sv, song_pic_orig_2924, std::nullopt, song_pic_small_thumb_2924, R"XYX(https://nicovideo.cdn.nimg.jp/thumbnails/7138245/7138245)XYX"sv, song_pic_thumb_2924, std::nullopt, song_pic_tiny_thumb_2924  };

constexpr std::array<song_artists, 2> song_artists_song_2924 {{
  { artist_t{ R"XYX(初音ミク, 初音未来, Chūyīn Wèilái, 하츠네 미쿠, 初音未來)XYX"sv, "Vocaloid"sv, false, 1, R"XYX(Hatsune Miku)XYX"sv, R"XYX(image/png)XYX"sv, 2007y/8/31, "Locked"sv, 39 }, "Vocalist"sv, "Default"sv, 1597, false, false, R"XYX(Hatsune Miku)XYX"sv, "Default"sv },
  { artist_t{ R"XYX(ささくれUK, ささくれP, ササクレ・ユーケイ, TJ.Hangneil)XYX"sv, "Producer"sv, false, 51, R"XYX(sasakure.UK)XYX"sv, R"XYX(image/jpeg)XYX"sv, std::nullopt, "Approved"sv, 41 }, "Producer, Animator"sv, "Animator, Composer"sv, 1598, false, false, R"XYX(sasakure.UK)XYX"sv, "Animator, Composer"sv },
}};

constexpr std::array<std::string_view, 1> culture_codes_song_2924 {{
"ja"sv, }};

constexpr std::array<song_pv, 5> pvs_song_2924 {{
  { R"XYX(sasakure.UK)XYX"sv, std::nullopt, false, R"XYX(std::nullopt)XYX"sv, 137850, 305, R"XYX(【初音ミクオリジナル曲】＊ハロー、プラネット。【ドットPV】)XYX"sv, 2009y/5/23, R"XYX(sm7138245)XYX"sv, "NicoNicoDouga"sv, "Original"sv, R"XYX(https://nicovideo.cdn.nimg.jp/thumbnails/7138245/7138245)XYX"sv, R"XYX(http://www.nicovideo.jp/watch/sm7138245)XYX"sv },
  { R"XYX(mimosa0creeping)XYX"sv, std::nullopt, false, R"XYX(std::nullopt)XYX"sv, 753892, 306, R"XYX(【初音ミクオリジナル曲】＊ハロー、プラネット。【ドットPV付き】)XYX"sv, 2010y/12/10, R"XYX(4wnKSR--bKI)XYX"sv, "Youtube"sv, "Reprint"sv, R"XYX(https://i.ytimg.com/vi/4wnKSR--bKI/default.jpg)XYX"sv, R"XYX(https://youtu.be/4wnKSR--bKI)XYX"sv },
  { R"XYX(LordKeldor)XYX"sv, std::nullopt, false, R"XYX(std::nullopt)XYX"sv, 905339, 306, R"XYX(【初音ミクオリジナル曲】＊ハロー、プラネット。【ドットPV付き】)XYX"sv, 2009y/5/26, R"XYX(_dlyIyfd9s0)XYX"sv, "Youtube"sv, "Reprint"sv, R"XYX(https://i.ytimg.com/vi/_dlyIyfd9s0/default.jpg)XYX"sv, R"XYX(https://youtu.be/_dlyIyfd9s0)XYX"sv },
  { R"XYX(KataGatar)XYX"sv, std::nullopt, false, R"XYX(std::nullopt)XYX"sv, 905340, 306, R"XYX(Hatsune Miku -"＊ハロー、プラネット。(*Hello, Planet.)" English subbed)XYX"sv, 2009y/5/25, R"XYX(WHFMb3q9IeY)XYX"sv, "Youtube"sv, "Reprint"sv, R"XYX(https://i.ytimg.com/vi/WHFMb3q9IeY/default.jpg)XYX"sv, R"XYX(https://youtu.be/WHFMb3q9IeY)XYX"sv },
  { R"XYX(VOCALOMUSIC)XYX"sv, std::nullopt, false, R"XYX(std::nullopt)XYX"sv, 1169767, 307, R"XYX(02 ＊ハロー、プラネット。)XYX"sv, 2023y/5/27, R"XYX(6Dzk4Nr1E6c)XYX"sv, "Youtube"sv, "Other"sv, R"XYX(https://i.ytimg.com/vi/6Dzk4Nr1E6c/default.jpg)XYX"sv, R"XYX(https://youtu.be/6Dzk4Nr1E6c)XYX"sv },
}};

/* End Song 2924: *Hello, Planet. */

/* Start Song 188729: Acceleration (Breeze Remix) */

constexpr std::array<additional_name, 2> names_song_188729 {{
  {"English"sv, R"XYX(Acceleration (Breeze Remix))XYX"sv},
  {"Unspecified"sv, R"XYX(Acceleration (New Version))XYX"sv},
}};

constexpr std::array<web_link, 3> web_links_song_188729 {{
  {"Official"sv, R"XYX(Off-vocal (SoundCloud))XYX"sv, R"XYX(https://soundcloud.com/cleantears/acceleration-new-version-off-vocal)XYX"sv, 70507 },
  {"Reference"sv, R"XYX(MikuWiki)XYX"sv, R"XYX(https://w.atwiki.jp/hmiku/pages/37425.html)XYX"sv, 112085 },
  {"Official"sv, R"XYX(Piapro (Illustration))XYX"sv, R"XYX(https://piapro.jp/t/GixW)XYX"sv, 112086 },
}};


#if __has_embed("song_pic_orig_188729.jpg") == __STDC_EMBED_FOUND__
constexpr std::array song_pic_orig_188729 = std::to_array<std::uint8_t>({
    #embed "song_pic_orig_188729.jpg"
});
#else
constexpr std::array<std::uint8_t, 0> song_pic_orig_188729;
#endif

constexpr std::array<std::uint8_t, 0> song_pic_small_thumb_188729;


#if __has_embed("song_pic_thumb_188729.jpg") == __STDC_EMBED_FOUND__
constexpr std::array song_pic_thumb_188729 = std::to_array<std::uint8_t>({
    #embed "song_pic_thumb_188729.jpg"
});
#else
constexpr std::array<std::uint8_t, 0> song_pic_thumb_188729;
#endif

constexpr std::array<std::uint8_t, 0> song_pic_tiny_thumb_188729;

constexpr picture picture_song_188729 = { std::nullopt, std::nullopt, R"XYX(https://i1.ytimg.com/vi/KLX5xaDQSZ4/hqdefault.jpg)XYX"sv, song_pic_orig_188729, std::nullopt, song_pic_small_thumb_188729, R"XYX(https://nicovideo.cdn.nimg.jp/thumbnails/32982184/32982184)XYX"sv, song_pic_thumb_188729, std::nullopt, song_pic_tiny_thumb_188729  };

constexpr std::array<song_artists, 4> song_artists_song_188729 {{
  { artist_t{ R"XYX(勝史, Masafumi)XYX"sv, "Producer"sv, false, 20, R"XYX(Clean Tears)XYX"sv, R"XYX(image/jpeg)XYX"sv, std::nullopt, "Approved"sv, 38 }, "Producer"sv, "Composer, Lyricist"sv, 478302, false, false, R"XYX(Clean Tears)XYX"sv, "Composer, Lyricist"sv },
  { artist_t{ R"XYX(初音ミク V3 (Solid))XYX"sv, "Vocaloid"sv, false, 11834, R"XYX(Hatsune Miku V3 (Solid))XYX"sv, R"XYX(image/png)XYX"sv, 2013y/9/26, "Finished"sv, 16 }, "Vocalist"sv, "Default"sv, 478303, false, false, R"XYX(Hatsune Miku V3 (Solid))XYX"sv, "Default"sv },
  { artist_t{ std::nullopt, "Lyricist"sv, false, 1436, R"XYX(T-ism)XYX"sv, R"XYX(image/jpeg)XYX"sv, std::nullopt, "Finished"sv, 7 }, "Other"sv, "Lyricist"sv, 478304, false, false, R"XYX(T-ism)XYX"sv, "Lyricist"sv },
  { artist_t{ R"XYX(あてこ)XYX"sv, "Illustrator"sv, false, 71525, R"XYX(Ateko)XYX"sv, R"XYX(image/jpeg)XYX"sv, std::nullopt, "Finished"sv, 1 }, "Illustrator"sv, "Illustrator"sv, 1113197, false, false, R"XYX(Ateko)XYX"sv, "Default"sv },
}};

constexpr std::array<std::string_view, 1> culture_codes_song_188729 {{
"ja"sv, }};

constexpr std::array<song_pv, 5> pvs_song_188729 {{
  { R"XYX(Clean Tears)XYX"sv, std::nullopt, false, R"XYX(std::nullopt)XYX"sv, 273365, 292, R"XYX(【初音ミク】Acceleration (New Version)【オリジナル曲】)XYX"sv, 2018y/4/1, R"XYX(sm32982184)XYX"sv, "NicoNicoDouga"sv, "Original"sv, R"XYX(https://nicovideo.cdn.nimg.jp/thumbnails/32982184/32982184)XYX"sv, R"XYX(http://www.nicovideo.jp/watch/sm32982184)XYX"sv },
  { R"XYX(Clean Tears)XYX"sv, std::nullopt, false, R"XYX(std::nullopt)XYX"sv, 273366, 293, R"XYX(Clean Tears - Acceleration (New Version) feat.初音ミク)XYX"sv, 2018y/4/1, R"XYX(KLX5xaDQSZ4)XYX"sv, "Youtube"sv, "Original"sv, R"XYX(https://i.ytimg.com/vi/KLX5xaDQSZ4/default.jpg)XYX"sv, R"XYX(https://youtu.be/KLX5xaDQSZ4)XYX"sv },
  { R"XYX(HypershadowX5)XYX"sv, std::nullopt, false, R"XYX(std::nullopt)XYX"sv, 295798, 294, R"XYX(Clean Tears - Breeze - 02 Acceleration (Breeze Remix))XYX"sv, 2018y/9/20, R"XYX(JlYe9ZVE48o)XYX"sv, "Youtube"sv, "Other"sv, R"XYX(https://i.ytimg.com/vi/JlYe9ZVE48o/default.jpg)XYX"sv, R"XYX(https://youtu.be/JlYe9ZVE48o)XYX"sv },
  { R"XYX(阿赫official)XYX"sv, std::nullopt, false, R"XYX({"Aid":21514673,"Bvid":"BV1gW411T7sg","Cid":35417772})XYX"sv, 508870, 292, R"XYX(【初音ミク】Acceleration (New Version)【Clean Tears】)XYX"sv, 2018y/4/1, R"XYX(21514673)XYX"sv, "Bilibili"sv, "Reprint"sv, R"XYX(http://i0.hdslb.com/bfs/archive/8476889398c70883b65227c0836186e16bde5154.jpg)XYX"sv, R"XYX(https://www.bilibili.com/video/av21514673)XYX"sv },
  { R"XYX(Clean Tears - Topic)XYX"sv, std::nullopt, false, R"XYX(std::nullopt)XYX"sv, 849837, 293, R"XYX(Acceleration (Breeze Remix) (feat. Hatsune Miku))XYX"sv, 2022y/7/27, R"XYX(iKHdGDuWjIo)XYX"sv, "Youtube"sv, "Original"sv, R"XYX(https://i.ytimg.com/vi/iKHdGDuWjIo/default.jpg)XYX"sv, R"XYX(https://youtu.be/iKHdGDuWjIo)XYX"sv },
}};

/* End Song 188729: Acceleration (Breeze Remix) */

/* Start Song 284993: Because You're Here */

constexpr std::array<additional_name, 5> names_song_284993 {{
  {"Japanese"sv, R"XYX(愛されなくても君がいる)XYX"sv},
  {"English"sv, R"XYX(Because You're Here)XYX"sv},
  {"Romaji"sv, R"XYX(Aisarenakute mo Kimi ga Iru)XYX"sv},
  {"Unspecified"sv, R"XYX(就算没有爱 只要有你就好)XYX"sv},
  {"Unspecified"sv, R"XYX(사랑받지 못해도 네가 있어)XYX"sv},
}};

constexpr std::array<web_link, 10> web_links_song_284993 {{
  {"Reference"sv, R"XYX(Vocaloid Lyrics Wiki)XYX"sv, R"XYX(https://vocaloidlyrics.miraheze.org/wiki/愛されなくても君がいる_(Aisarenakute_mo_Kimi_ga_Iru))XYX"sv, 94636 },
  {"Reference"sv, R"XYX(MikuWiki)XYX"sv, R"XYX(https://w.atwiki.jp/hmiku/sp/pages/41635.html)XYX"sv, 94637 },
  {"Reference"sv, R"XYX(Sekaipedia)XYX"sv, R"XYX(https://www.sekaipedia.org/wiki/Aisarenakute_mo_Kimi_ga_Iru)XYX"sv, 190019 },
  {"Reference"sv, R"XYX(Project SEKAI Wiki)XYX"sv, R"XYX(https://projectsekai.fandom.com/wiki/Aisarenakute_mo_Kimi_ga_Iru)XYX"sv, 190020 },
  {"Reference"sv, R"XYX(Vocaloid Wiki)XYX"sv, R"XYX(https://vocaloid.fandom.com/wiki/愛されなくても君がいる_(Aisarenakute_mo_Kimi_ga_Iru))XYX"sv, 190021 },
  {"Reference"sv, R"XYX(Pixiv Encyclopedia)XYX"sv, R"XYX(https://dic.pixiv.net/a/愛されなくても君がいる)XYX"sv, 190022 },
  {"Reference"sv, R"XYX(NicoNicoPedia)XYX"sv, R"XYX(https://dic.nicovideo.jp/v/sm37223770)XYX"sv, 190023 },
  {"Reference"sv, R"XYX(Namu Wiki)XYX"sv, R"XYX(https://namu.wiki/w/사랑받지 못해도 네가 있어)XYX"sv, 190024 },
  {"Reference"sv, R"XYX(Moegirlpedia (zh-cn))XYX"sv, R"XYX(https://zh.moegirl.org.cn/就算没有爱_只要有你就好)XYX"sv, 190025 },
  {"Official"sv, R"XYX(X (Twitter) post by りお)XYX"sv, R"XYX(https://x.com/rio9u9/status/1286158110776688640)XYX"sv, 190026 },
}};


#if __has_embed("song_pic_orig_284993.jpg") == __STDC_EMBED_FOUND__
constexpr std::array song_pic_orig_284993 = std::to_array<std::uint8_t>({
    #embed "song_pic_orig_284993.jpg"
});
#else
constexpr std::array<std::uint8_t, 0> song_pic_orig_284993;
#endif

constexpr std::array<std::uint8_t, 0> song_pic_small_thumb_284993;


#if __has_embed("song_pic_thumb_284993.jpg") == __STDC_EMBED_FOUND__
constexpr std::array song_pic_thumb_284993 = std::to_array<std::uint8_t>({
    #embed "song_pic_thumb_284993.jpg"
});
#else
constexpr std::array<std::uint8_t, 0> song_pic_thumb_284993;
#endif

constexpr std::array<std::uint8_t, 0> song_pic_tiny_thumb_284993;

constexpr picture picture_song_284993 = { std::nullopt, std::nullopt, R"XYX(https://i1.ytimg.com/vi/ygY2qObZv24/hqdefault.jpg)XYX"sv, song_pic_orig_284993, std::nullopt, song_pic_small_thumb_284993, R"XYX(https://i.ytimg.com/vi/ygY2qObZv24/default.jpg)XYX"sv, song_pic_thumb_284993, std::nullopt, song_pic_tiny_thumb_284993  };

constexpr std::array<song_artists, 9> song_artists_song_284993 {{
  { artist_t{ R"XYX(ピノキオピー, ピノキオP, 工藤大発見, DAIHAKKEN, Kudou Daihakken, 匹诺曹P, 피노키오피)XYX"sv, "Producer"sv, false, 28, R"XYX(PinocchioP)XYX"sv, R"XYX(image/jpeg)XYX"sv, std::nullopt, "Approved"sv, 37 }, "Producer"sv, "Default"sv, 762570, false, false, R"XYX(PinocchioP)XYX"sv, "Default"sv },
  { artist_t{ R"XYX(初音ミク, 初音未来, Chūyīn Wèilái, 하츠네 미쿠, 初音未來)XYX"sv, "Vocaloid"sv, false, 1, R"XYX(Hatsune Miku)XYX"sv, R"XYX(image/png)XYX"sv, 2007y/8/31, "Locked"sv, 39 }, "Vocalist"sv, "Default"sv, 762571, false, false, R"XYX(Hatsune Miku)XYX"sv, "Default"sv },
  { artist_t{ R"XYX(ヤヅキ, 激おこP, ヤヅキ激おこＰ, Yaduki GekiokoP, Yaduki Maru, YADSUKI GEKIOKOP, YADSUKI GEKIOKO P)XYX"sv, "Producer"sv, false, 522, R"XYX(Yaduki)XYX"sv, R"XYX(image/jpeg)XYX"sv, std::nullopt, "Finished"sv, 22 }, "Other"sv, "Instrumentalist"sv, 775491, false, false, R"XYX(Yaduki)XYX"sv, "Instrumentalist"sv },
  { artist_t{ R"XYX(齊藤雄磨, Saitou Yuuma, サイトウユウマ, はっぴ太朗)XYX"sv, "Animator"sv, false, 3327, R"XYX(Yuma Saito)XYX"sv, R"XYX(image/jpeg)XYX"sv, std::nullopt, "Finished"sv, 11 }, "Other"sv, "Other"sv, 775492, false, true, R"XYX(Yuma Saito)XYX"sv, "Other"sv },
  { artist_t{ R"XYX(ツインテール今村)XYX"sv, "Illustrator"sv, false, 25358, R"XYX(Twintail Imamura)XYX"sv, R"XYX(image/png)XYX"sv, std::nullopt, "Finished"sv, 5 }, "Other"sv, "Other"sv, 775493, false, true, R"XYX(Twintail Imamura)XYX"sv, "Other"sv },
  { artist_t{ std::nullopt, "Animator"sv, false, 168129, R"XYX(桑原正基)XYX"sv, std::nullopt, std::nullopt, "Draft"sv, 1 }, "Animator"sv, "Animator"sv, 2390327, false, false, R"XYX(桑原正基)XYX"sv, "Animator"sv },
  { artist_t{ std::nullopt, "OtherIndividual"sv, false, 168128, R"XYX(10second)XYX"sv, std::nullopt, std::nullopt, "Finished"sv, 1 }, "Other"sv, "Other"sv, 2390328, false, false, R"XYX(10second)XYX"sv, "Other"sv },
  { artist_t{ R"XYX(りお, り　お, Ri　o)XYX"sv, "OtherIndividual"sv, false, 168135, R"XYX(Rio)XYX"sv, R"XYX(image/jpeg)XYX"sv, std::nullopt, "Finished"sv, 3 }, "Other"sv, "Other"sv, 2390329, false, false, R"XYX(Rio)XYX"sv, "Other"sv },
  { artist_t{ R"XYX(田仲マイケル)XYX"sv, "OtherIndividual"sv, false, 168134, R"XYX(Michael Tanaka)XYX"sv, std::nullopt, std::nullopt, "Draft"sv, 1 }, "Other"sv, "Other"sv, 2390330, false, false, R"XYX(Michael Tanaka)XYX"sv, "Other"sv },
}};

constexpr std::array<std::string_view, 1> culture_codes_song_284993 {{
"ja"sv, }};

constexpr std::array<song_pv, 5> pvs_song_284993 {{
  { R"XYX(ピノキオピー PINOCCHIOP OFFICIAL CHANNEL)XYX"sv, std::nullopt, false, R"XYX(std::nullopt)XYX"sv, 416059, 270, R"XYX(ピノキオピー - 愛されなくても君がいる / PinocchioP - Because You’re Here)XYX"sv, 2020y/7/22, R"XYX(ygY2qObZv24)XYX"sv, "Youtube"sv, "Original"sv, R"XYX(https://i.ytimg.com/vi/ygY2qObZv24/default.jpg)XYX"sv, R"XYX(https://youtu.be/ygY2qObZv24)XYX"sv },
  { R"XYX(ピノキオピー)XYX"sv, std::nullopt, false, R"XYX(std::nullopt)XYX"sv, 416060, 270, R"XYX(愛されなくても君がいる / 初音ミク)XYX"sv, 2020y/7/22, R"XYX(sm37223770)XYX"sv, "NicoNicoDouga"sv, "Original"sv, R"XYX(https://nicovideo.cdn.nimg.jp/thumbnails/37223770/37223770.96835470)XYX"sv, R"XYX(http://www.nicovideo.jp/watch/sm37223770)XYX"sv },
  { R"XYX(ピノキオピー_official)XYX"sv, std::nullopt, false, R"XYX({"Aid":371470351,"Bvid":"BV1BZ4y1T7w9","Cid":215205880})XYX"sv, 416080, 271, R"XYX(【初音ミク】就算没有爱 只要有你就好【ピノキオピー】)XYX"sv, 2020y/7/22, R"XYX(371470351)XYX"sv, "Bilibili"sv, "Original"sv, R"XYX(http://i0.hdslb.com/bfs/archive/42d9cc1068928dcb9e986b263cfea91956b991f3.jpg)XYX"sv, R"XYX(https://www.bilibili.com/video/av371470351)XYX"sv },
  { R"XYX(PinocchioP - Topic)XYX"sv, std::nullopt, false, R"XYX(std::nullopt)XYX"sv, 527748, 272, R"XYX(愛されなくても君がいる)XYX"sv, 2021y/3/2, R"XYX(wSRziiXJHT8)XYX"sv, "Youtube"sv, "Original"sv, R"XYX(https://i.ytimg.com/vi/wSRziiXJHT8/default.jpg)XYX"sv, R"XYX(https://youtu.be/wSRziiXJHT8)XYX"sv },
  { R"XYX(PinocchioP - Topic)XYX"sv, std::nullopt, false, R"XYX(std::nullopt)XYX"sv, 561764, 273, R"XYX(愛されなくても君がいる (feat. 初音ミク))XYX"sv, 2021y/3/2, R"XYX(p5va3VZrkwE)XYX"sv, "Youtube"sv, "Original"sv, R"XYX(https://i.ytimg.com/vi/p5va3VZrkwE/default.jpg)XYX"sv, R"XYX(https://youtu.be/p5va3VZrkwE)XYX"sv },
}};

/* End Song 284993: Because You're Here */

/* Start Song 8247: erase or zero */

constexpr std::array<additional_name, 1> names_song_8247 {{
  {"English"sv, R"XYX(erase or zero)XYX"sv},
}};

constexpr std::array<web_link, 5> web_links_song_8247 {{
  {"Reference"sv, R"XYX(Vocaloid Wiki)XYX"sv, R"XYX(http://vocaloid.wikia.com/wiki/Erase_or_zero)XYX"sv, 72642 },
  {"Commercial"sv, R"XYX(Spotify (マジカルミライ2014))XYX"sv, R"XYX(https://open.spotify.com/track/2KvOas5tcBfvnOuwMkcOHB)XYX"sv, 81441 },
  {"Reference"sv, R"XYX(MikuWiki)XYX"sv, R"XYX(http://www5.atwiki.jp/hmiku/pages/954.html)XYX"sv, 81442 },
  {"Reference"sv, R"XYX(UtaiteDB)XYX"sv, R"XYX(https://utaitedb.net/S/41158)XYX"sv, 84064 },
  {"Commercial"sv, R"XYX(Spotify)XYX"sv, R"XYX(https://open.spotify.com/track/396tVnKqmG32TeMtSBvUS2?si=248c5325628c4910)XYX"sv, 128306 },
}};


#if __has_embed("song_pic_orig_8247.jpg") == __STDC_EMBED_FOUND__
constexpr std::array song_pic_orig_8247 = std::to_array<std::uint8_t>({
    #embed "song_pic_orig_8247.jpg"
});
#else
constexpr std::array<std::uint8_t, 0> song_pic_orig_8247;
#endif

constexpr std::array<std::uint8_t, 0> song_pic_small_thumb_8247;


#if __has_embed("song_pic_thumb_8247.jpg") == __STDC_EMBED_FOUND__
constexpr std::array song_pic_thumb_8247 = std::to_array<std::uint8_t>({
    #embed "song_pic_thumb_8247.jpg"
});
#else
constexpr std::array<std::uint8_t, 0> song_pic_thumb_8247;
#endif

constexpr std::array<std::uint8_t, 0> song_pic_tiny_thumb_8247;

constexpr picture picture_song_8247 = { std::nullopt, std::nullopt, R"XYX(https://i1.ytimg.com/vi/QX1L2veQFxU/hqdefault.jpg)XYX"sv, song_pic_orig_8247, std::nullopt, song_pic_small_thumb_8247, R"XYX(https://nicovideo.cdn.nimg.jp/thumbnails/3307158/3307158)XYX"sv, song_pic_thumb_8247, std::nullopt, song_pic_tiny_thumb_8247  };

constexpr std::array<song_artists, 5> song_artists_song_8247 {{
  { artist_t{ R"XYX(クリスタルP, HzEdge, sawamurah, 河又圭一, Keiichi Kawamata)XYX"sv, "Producer"sv, false, 732, R"XYX(CrystalP)XYX"sv, R"XYX(image/jpeg)XYX"sv, std::nullopt, "Finished"sv, 21 }, "Producer"sv, "Composer, Lyricist, VoiceManipulator"sv, 4434, false, false, R"XYX(CrystalP)XYX"sv, "Composer, Lyricist, VoiceManipulator"sv },
  { artist_t{ R"XYX(カイト)XYX"sv, "Vocaloid"sv, false, 71, R"XYX(KAITO)XYX"sv, R"XYX(image/png)XYX"sv, 2006y/2/14, "Locked"sv, 33 }, "Vocalist"sv, "Default"sv, 4435, false, false, R"XYX(KAITO)XYX"sv, "Default"sv },
  { artist_t{ R"XYX(鏡音レン, 鏡音連, 카가미네 렌, 镜音连)XYX"sv, "Vocaloid"sv, false, 15, R"XYX(Kagamine Len)XYX"sv, R"XYX(image/png)XYX"sv, 2007y/12/27, "Locked"sv, 32 }, "Vocalist"sv, "Default"sv, 4436, false, false, R"XYX(Kagamine Len)XYX"sv, "Default"sv },
  { artist_t{ std::nullopt, "Producer"sv, false, 2466, R"XYX(bestgt)XYX"sv, R"XYX(image/jpeg)XYX"sv, std::nullopt, "Finished"sv, 3 }, "Producer"sv, "VoiceManipulator"sv, 26957, false, false, R"XYX(bestgt)XYX"sv, "VoiceManipulator"sv },
  { artist_t{ std::nullopt, "Illustrator"sv, false, 95150, R"XYX(yukito)XYX"sv, R"XYX(image/jpeg)XYX"sv, std::nullopt, "Finished"sv, 2 }, "Illustrator"sv, "Illustrator"sv, 975657, false, false, R"XYX(yukito)XYX"sv, "Default"sv },
}};

constexpr std::array<std::string_view, 1> culture_codes_song_8247 {{
"ja"sv, }};

constexpr std::array<song_pv, 3> pvs_song_8247 {{
  { R"XYX(HzEdge)XYX"sv, std::nullopt, false, R"XYX(std::nullopt)XYX"sv, 108616, 229, R"XYX(【鏡音レン＆KAITO】erase or zero【デュエット/オリジナル】)XYX"sv, 2008y/5/13, R"XYX(sm3307158)XYX"sv, "NicoNicoDouga"sv, "Original"sv, R"XYX(https://nicovideo.cdn.nimg.jp/thumbnails/3307158/3307158)XYX"sv, R"XYX(http://www.nicovideo.jp/watch/sm3307158)XYX"sv },
  { R"XYX(hinatamarun)XYX"sv, std::nullopt, false, R"XYX(std::nullopt)XYX"sv, 408236, 230, R"XYX(【鏡音レン＆KAITO】erase or zero【デュエット/オリジナル】)XYX"sv, 2008y/5/15, R"XYX(Z7rOjnWxEq8)XYX"sv, "Youtube"sv, "Reprint"sv, R"XYX(https://i.ytimg.com/vi/Z7rOjnWxEq8/default.jpg)XYX"sv, R"XYX(https://youtu.be/Z7rOjnWxEq8)XYX"sv },
  { R"XYX(HzEdge - Topic)XYX"sv, std::nullopt, false, R"XYX(std::nullopt)XYX"sv, 779336, 231, R"XYX(erase or zero (feat. KAITO & Kagamine Len))XYX"sv, 2020y/4/4, R"XYX(QX1L2veQFxU)XYX"sv, "Youtube"sv, "Original"sv, R"XYX(https://i.ytimg.com/vi/QX1L2veQFxU/default.jpg)XYX"sv, R"XYX(https://youtu.be/QX1L2veQFxU)XYX"sv },
}};

/* End Song 8247: erase or zero */

/* Start Song 6387: Fire◎Flower */

constexpr std::array<additional_name, 1> names_song_6387 {{
  {"English"sv, R"XYX(Fire◎Flower)XYX"sv},
}};

constexpr std::array<web_link, 8> web_links_song_6387 {{
  {"Reference"sv, R"XYX(Vocaloid Wiki)XYX"sv, R"XYX(http://vocaloid.wikia.com/wiki/Fire%E2%97%8EFlower)XYX"sv, 3305 },
  {"Reference"sv, R"XYX(NicoNicoPedia)XYX"sv, R"XYX(http://dic.nicovideo.jp/v/sm4153727)XYX"sv, 3306 },
  {"Reference"sv, R"XYX(Pixiv Encyclopedia)XYX"sv, R"XYX(http://dic.pixiv.net/a/Fire%E2%97%8EFlower)XYX"sv, 3307 },
  {"Reference"sv, R"XYX(MikuWiki)XYX"sv, R"XYX(http://www5.atwiki.jp/hmiku/pages/1799.html)XYX"sv, 21076 },
  {"Official"sv, R"XYX(Piapro / Instrumental)XYX"sv, R"XYX(http://piapro.jp/t/VwHN)XYX"sv, 21077 },
  {"Official"sv, R"XYX(Piapro / Lyrics)XYX"sv, R"XYX(http://piapro.jp/t/kYj5)XYX"sv, 21078 },
  {"Reference"sv, R"XYX(UtaiteDB)XYX"sv, R"XYX(http://utaitedb.net/S/2077)XYX"sv, 21079 },
  {"Reference"sv, R"XYX(Vocaloid Lyrics Wiki)XYX"sv, R"XYX(https://vocaloidlyrics.miraheze.org/wiki/Fire%E2%97%8EFlower)XYX"sv, 57667 },
}};


#if __has_embed("song_pic_orig_6387.jpg") == __STDC_EMBED_FOUND__
constexpr std::array song_pic_orig_6387 = std::to_array<std::uint8_t>({
    #embed "song_pic_orig_6387.jpg"
});
#else
constexpr std::array<std::uint8_t, 0> song_pic_orig_6387;
#endif

constexpr std::array<std::uint8_t, 0> song_pic_small_thumb_6387;


#if __has_embed("song_pic_thumb_6387.jpg") == __STDC_EMBED_FOUND__
constexpr std::array song_pic_thumb_6387 = std::to_array<std::uint8_t>({
    #embed "song_pic_thumb_6387.jpg"
});
#else
constexpr std::array<std::uint8_t, 0> song_pic_thumb_6387;
#endif

constexpr std::array<std::uint8_t, 0> song_pic_tiny_thumb_6387;

constexpr picture picture_song_6387 = { std::nullopt, std::nullopt, R"XYX(https://i1.ytimg.com/vi/myEsj-qf73A/hqdefault.jpg)XYX"sv, song_pic_orig_6387, std::nullopt, song_pic_small_thumb_6387, R"XYX(https://i.ytimg.com/vi/myEsj-qf73A/default.jpg)XYX"sv, song_pic_thumb_6387, std::nullopt, song_pic_tiny_thumb_6387  };

constexpr std::array<song_artists, 5> song_artists_song_6387 {{
  { artist_t{ R"XYX(森晴義, Mori Haruyoshi, ハルヨシ, 하루요시)XYX"sv, "Producer"sv, false, 715, R"XYX(halyosy)XYX"sv, R"XYX(image/jpeg)XYX"sv, std::nullopt, "Finished"sv, 22 }, "Producer"sv, "Composer, Lyricist"sv, 4233, false, false, R"XYX(halyosy)XYX"sv, "Composer, Lyricist"sv },
  { artist_t{ R"XYX(鏡音レン, 鏡音連, 카가미네 렌, 镜音连)XYX"sv, "Vocaloid"sv, false, 15, R"XYX(Kagamine Len)XYX"sv, R"XYX(image/png)XYX"sv, 2007y/12/27, "Locked"sv, 32 }, "Vocalist"sv, "Default"sv, 4234, false, false, R"XYX(Kagamine Len)XYX"sv, "Default"sv },
  { artist_t{ R"XYX(中村博, hiroshi)XYX"sv, "Producer"sv, false, 1756, R"XYX(is)XYX"sv, R"XYX(image/jpeg)XYX"sv, std::nullopt, "Finished"sv, 6 }, "Producer"sv, "Arranger"sv, 94877, false, false, R"XYX(is)XYX"sv, "Arranger"sv },
  { artist_t{ R"XYX(わかな, nagamoo)XYX"sv, "Illustrator"sv, false, 9219, R"XYX(Wakana)XYX"sv, std::nullopt, std::nullopt, "Draft"sv, 5 }, "Illustrator"sv, "Illustrator"sv, 94878, false, false, R"XYX(Wakana)XYX"sv, "Illustrator"sv },
  { artist_t{ R"XYX(ざっと)XYX"sv, "OtherVocalist"sv, false, 1997, R"XYX(that)XYX"sv, R"XYX(image/png)XYX"sv, std::nullopt, "Finished"sv, 6 }, "Animator"sv, "Animator"sv, 94879, false, false, R"XYX(that)XYX"sv, "Animator"sv },
}};

constexpr std::array<std::string_view, 1> culture_codes_song_6387 {{
"ja"sv, }};

constexpr std::array<song_pv, 3> pvs_song_6387 {{
  { R"XYX(Halyosy Moly)XYX"sv, std::nullopt, false, R"XYX(std::nullopt)XYX"sv, 90392, 261, R"XYX(Fire◎Flower / 鏡音レン [ Fire Flower / halyosy feat. Kagamine Len] [OriginalSong])XYX"sv, 2008y/8/3, R"XYX(myEsj-qf73A)XYX"sv, "Youtube"sv, "Original"sv, R"XYX(https://i.ytimg.com/vi/myEsj-qf73A/default.jpg)XYX"sv, R"XYX(https://youtu.be/myEsj-qf73A)XYX"sv },
  { R"XYX(halyosy)XYX"sv, std::nullopt, false, R"XYX(std::nullopt)XYX"sv, 90393, 261, R"XYX(Fire◎Flower)XYX"sv, 2008y/8/3, R"XYX(3x0nxjqy88w54vnl)XYX"sv, "Piapro"sv, "Original"sv, std::nullopt, R"XYX(http://piapro.jp/content/3x0nxjqy88w54vnl)XYX"sv },
  { R"XYX(halyosy)XYX"sv, std::nullopt, false, R"XYX(std::nullopt)XYX"sv, 98548, 260, R"XYX(【鏡音レン】Fire◎Flower【オリジナル曲】)XYX"sv, 2008y/8/2, R"XYX(sm4153727)XYX"sv, "NicoNicoDouga"sv, "Original"sv, R"XYX(https://nicovideo.cdn.nimg.jp/thumbnails/4153727/4153727)XYX"sv, R"XYX(http://www.nicovideo.jp/watch/sm4153727)XYX"sv },
}};

/* End Song 6387: Fire◎Flower */

/* Start Song 1797: glow */

constexpr std::array<additional_name, 1> names_song_1797 {{
  {"English"sv, R"XYX(glow)XYX"sv},
}};

constexpr std::array<web_link, 11> web_links_song_1797 {{
  {"Reference"sv, R"XYX(MikuWiki)XYX"sv, R"XYX(http://www5.atwiki.jp/hmiku/pages/10599.html)XYX"sv, 591 },
  {"Reference"sv, R"XYX(NicoNicoPedia)XYX"sv, R"XYX(http://dic.nicovideo.jp/v/sm11209477)XYX"sv, 3721 },
  {"Official"sv, R"XYX(Piapro / Karaoke)XYX"sv, R"XYX(http://piapro.jp/t/wXQJ)XYX"sv, 9606 },
  {"Official"sv, R"XYX(Piapro / Karaoke (key: -3))XYX"sv, R"XYX(http://piapro.jp/t/LbUc)XYX"sv, 9607 },
  {"Reference"sv, R"XYX(UtaiteDB)XYX"sv, R"XYX(http://utaitedb.net/S/1379)XYX"sv, 25066 },
  {"Commercial"sv, R"XYX(Spotify)XYX"sv, R"XYX(https://play.spotify.com/track/4Aw2k8epSZp7dWbrePpDLY)XYX"sv, 68159 },
  {"Reference"sv, R"XYX(Vocaloid Lyrics Wiki)XYX"sv, R"XYX(https://vocaloidlyrics.miraheze.org/wiki/Glow/keeno)XYX"sv, 75334 },
  {"Commercial"sv, R"XYX(Spotify (マジカルミライ2014))XYX"sv, R"XYX(https://play.spotify.com/track/6uUC9WZjJTYuFps4sd9YhY)XYX"sv, 79190 },
  {"Reference"sv, R"XYX(Project Sekai Wiki)XYX"sv, R"XYX(https://projectsekai.fandom.com/wiki/Glow)XYX"sv, 146328 },
  {"Reference"sv, R"XYX(Vocaloid Wiki)XYX"sv, R"XYX(https://vocaloid.fandom.com/wiki/Glow/keeno)XYX"sv, 156991 },
  {"Reference"sv, R"XYX(UtaiteDB (Hekiru Shiina ver.))XYX"sv, R"XYX(https://utaitedb.net/S/69359)XYX"sv, 167072 },
}};


#if __has_embed("song_pic_orig_1797.jpg") == __STDC_EMBED_FOUND__
constexpr std::array song_pic_orig_1797 = std::to_array<std::uint8_t>({
    #embed "song_pic_orig_1797.jpg"
});
#else
constexpr std::array<std::uint8_t, 0> song_pic_orig_1797;
#endif

constexpr std::array<std::uint8_t, 0> song_pic_small_thumb_1797;


#if __has_embed("song_pic_thumb_1797.jpg") == __STDC_EMBED_FOUND__
constexpr std::array song_pic_thumb_1797 = std::to_array<std::uint8_t>({
    #embed "song_pic_thumb_1797.jpg"
});
#else
constexpr std::array<std::uint8_t, 0> song_pic_thumb_1797;
#endif

constexpr std::array<std::uint8_t, 0> song_pic_tiny_thumb_1797;

constexpr picture picture_song_1797 = { std::nullopt, std::nullopt, R"XYX(https://i1.ytimg.com/vi/6BHNFYk6w-M/hqdefault.jpg)XYX"sv, song_pic_orig_1797, std::nullopt, song_pic_small_thumb_1797, R"XYX(https://nicovideo.cdn.nimg.jp/thumbnails/11209477/11209477)XYX"sv, song_pic_thumb_1797, std::nullopt, song_pic_tiny_thumb_1797  };

constexpr std::array<song_artists, 3> song_artists_song_1797 {{
  { artist_t{ R"XYX(初音ミク Append (Dark))XYX"sv, "Vocaloid"sv, false, 75, R"XYX(Hatsune Miku Append (Dark))XYX"sv, R"XYX(image/png)XYX"sv, 2010y/4/30, "Locked"sv, 23 }, "Vocalist"sv, "Default"sv, 5345, false, false, R"XYX(Hatsune Miku Append (Dark))XYX"sv, "Default"sv },
  { artist_t{ R"XYX(キーノ)XYX"sv, "Producer"sv, false, 288, R"XYX(keeno)XYX"sv, R"XYX(image/png)XYX"sv, std::nullopt, "Approved"sv, 19 }, "Producer"sv, "Default"sv, 5346, false, false, R"XYX(keeno)XYX"sv, "Default"sv },
  { artist_t{ R"XYX(麺類子)XYX"sv, "Illustrator"sv, false, 3197, R"XYX(Menruiko)XYX"sv, R"XYX(image/png)XYX"sv, std::nullopt, "Finished"sv, 14 }, "Illustrator"sv, "Illustrator"sv, 146787, false, false, R"XYX(Menruiko)XYX"sv, "Illustrator"sv },
}};

constexpr std::array<std::string_view, 1> culture_codes_song_1797 {{
"ja"sv, }};

constexpr std::array<song_pv, 4> pvs_song_1797 {{
  { R"XYX(Keeno)XYX"sv, std::nullopt, false, R"XYX(std::nullopt)XYX"sv, 98102, 283, R"XYX(【初音ミクDark】　glow　【オリジナル】)XYX"sv, 2010y/6/28, R"XYX(sm11209477)XYX"sv, "NicoNicoDouga"sv, "Original"sv, R"XYX(https://nicovideo.cdn.nimg.jp/thumbnails/11209477/11209477)XYX"sv, R"XYX(http://www.nicovideo.jp/watch/sm11209477)XYX"sv },
  { R"XYX(Keeno)XYX"sv, std::nullopt, false, R"XYX({"Timestamp":"20100628231225"})XYX"sv, 352985, 288, R"XYX(glow   【初音ミクDark オリジナル】)XYX"sv, 2010y/6/28, R"XYX(o6ntcen5r3kmf6ws)XYX"sv, "Piapro"sv, "Original"sv, R"XYX(https://cdn.piapro.jp/thumb_i/4k/4korobetndcv4777_20110805221513_0500_0500.png)XYX"sv, R"XYX(http://piapro.jp/content/o6ntcen5r3kmf6ws)XYX"sv },
  { R"XYX(xichlotour)XYX"sv, std::nullopt, false, R"XYX(std::nullopt)XYX"sv, 542545, 284, R"XYX([Vocaloid] Glow - Miku Append Dark [Vietsub])XYX"sv, 2012y/9/25, R"XYX(YJAP8LU4keg)XYX"sv, "Youtube"sv, "Other"sv, R"XYX(https://i.ytimg.com/vi/YJAP8LU4keg/default.jpg)XYX"sv, R"XYX(https://youtu.be/YJAP8LU4keg)XYX"sv },
  { R"XYX(Siriuslex)XYX"sv, std::nullopt, false, R"XYX(std::nullopt)XYX"sv, 1179355, 284, R"XYX(【初音ミクDark】　glow　【オリジナル】)XYX"sv, 2012y/4/17, R"XYX(6BHNFYk6w-M)XYX"sv, "Youtube"sv, "Reprint"sv, R"XYX(https://i.ytimg.com/vi/6BHNFYk6w-M/default.jpg)XYX"sv, R"XYX(https://youtu.be/6BHNFYk6w-M)XYX"sv },
}};

/* End Song 1797: glow */

/* Start Song 329458: Hedgehog */

constexpr std::array<additional_name, 3> names_song_329458 {{
  {"Japanese"sv, R"XYX(ヘッジホッグ)XYX"sv},
  {"English"sv, R"XYX(Hedgehog)XYX"sv},
  {"Unspecified"sv, R"XYX(헤지호그)XYX"sv},
}};

constexpr std::array<web_link, 0> web_links_song_329458 {{
}};


#if __has_embed("song_pic_orig_329458.jpg") == __STDC_EMBED_FOUND__
constexpr std::array song_pic_orig_329458 = std::to_array<std::uint8_t>({
    #embed "song_pic_orig_329458.jpg"
});
#else
constexpr std::array<std::uint8_t, 0> song_pic_orig_329458;
#endif

constexpr std::array<std::uint8_t, 0> song_pic_small_thumb_329458;


#if __has_embed("song_pic_thumb_329458.jpg") == __STDC_EMBED_FOUND__
constexpr std::array song_pic_thumb_329458 = std::to_array<std::uint8_t>({
    #embed "song_pic_thumb_329458.jpg"
});
#else
constexpr std::array<std::uint8_t, 0> song_pic_thumb_329458;
#endif

constexpr std::array<std::uint8_t, 0> song_pic_tiny_thumb_329458;

constexpr picture picture_song_329458 = { std::nullopt, std::nullopt, R"XYX(https://i1.ytimg.com/vi/ajNGy63FhBY/hqdefault.jpg)XYX"sv, song_pic_orig_329458, std::nullopt, song_pic_small_thumb_329458, R"XYX(https://nicovideo.cdn.nimg.jp/thumbnails/38630030/38630030.61648809)XYX"sv, song_pic_thumb_329458, std::nullopt, song_pic_tiny_thumb_329458  };

constexpr std::array<song_artists, 2> song_artists_song_329458 {{
  { artist_t{ R"XYX(cosaji)XYX"sv, "Producer"sv, false, 61928, R"XYX(Noz.)XYX"sv, R"XYX(image/jpeg)XYX"sv, std::nullopt, "Finished"sv, 8 }, "Vocalist, Producer"sv, "Composer, Vocalist"sv, 893548, false, false, R"XYX(Noz.)XYX"sv, "Composer, Vocalist"sv },
  { artist_t{ R"XYX(鏡音リン, 鏡音鈴, 카가미네 린, 镜音铃)XYX"sv, "Vocaloid"sv, false, 14, R"XYX(Kagamine Rin)XYX"sv, R"XYX(image/png)XYX"sv, 2007y/12/27, "Locked"sv, 34 }, "Vocalist"sv, "Default"sv, 893549, false, false, R"XYX(Kagamine Rin)XYX"sv, "Default"sv },
}};

constexpr std::array<std::string_view, 1> culture_codes_song_329458 {{
"ja"sv, }};

constexpr std::array<song_pv, 3> pvs_song_329458 {{
  { R"XYX(Noz.)XYX"sv, std::nullopt, false, R"XYX(std::nullopt)XYX"sv, 480097, 214, R"XYX(『ヘッジホッグ』／ 鏡音リン)XYX"sv, 2021y/4/24, R"XYX(sm38630030)XYX"sv, "NicoNicoDouga"sv, "Original"sv, R"XYX(https://nicovideo.cdn.nimg.jp/thumbnails/38630030/38630030.61648809)XYX"sv, R"XYX(http://www.nicovideo.jp/watch/sm38630030)XYX"sv },
  { R"XYX(Noz. Official)XYX"sv, std::nullopt, false, R"XYX(std::nullopt)XYX"sv, 480204, 215, R"XYX(Noz. - 『ヘッジホッグ』(Hedgehog) / Kagamine Rin)XYX"sv, 2021y/4/24, R"XYX(ajNGy63FhBY)XYX"sv, "Youtube"sv, "Original"sv, R"XYX(https://i.ytimg.com/vi/ajNGy63FhBY/default.jpg)XYX"sv, R"XYX(https://youtu.be/ajNGy63FhBY)XYX"sv },
  { R"XYX(Various Artists - Topic)XYX"sv, std::nullopt, false, R"XYX(std::nullopt)XYX"sv, 793792, 217, R"XYX(Hedgehog (feat. Kagamine Rin))XYX"sv, 2023y/6/30, R"XYX(66sAiFOPiD8)XYX"sv, "Youtube"sv, "Original"sv, R"XYX(https://i.ytimg.com/vi/66sAiFOPiD8/default.jpg)XYX"sv, R"XYX(https://youtu.be/66sAiFOPiD8)XYX"sv },
}};

/* End Song 329458: Hedgehog */

/* Start Song 481543: imaginary love story */

constexpr std::array<additional_name, 1> names_song_481543 {{
  {"English"sv, R"XYX(imaginary love story)XYX"sv},
}};

constexpr std::array<web_link, 0> web_links_song_481543 {{
}};


#if __has_embed("song_pic_orig_481543.jpg") == __STDC_EMBED_FOUND__
constexpr std::array song_pic_orig_481543 = std::to_array<std::uint8_t>({
    #embed "song_pic_orig_481543.jpg"
});
#else
constexpr std::array<std::uint8_t, 0> song_pic_orig_481543;
#endif

constexpr std::array<std::uint8_t, 0> song_pic_small_thumb_481543;


#if __has_embed("song_pic_thumb_481543.jpg") == __STDC_EMBED_FOUND__
constexpr std::array song_pic_thumb_481543 = std::to_array<std::uint8_t>({
    #embed "song_pic_thumb_481543.jpg"
});
#else
constexpr std::array<std::uint8_t, 0> song_pic_thumb_481543;
#endif

constexpr std::array<std::uint8_t, 0> song_pic_tiny_thumb_481543;

constexpr picture picture_song_481543 = { std::nullopt, std::nullopt, R"XYX(https://i1.ytimg.com/vi/dmHeXH1YthI/hqdefault.jpg)XYX"sv, song_pic_orig_481543, std::nullopt, song_pic_small_thumb_481543, R"XYX(https://i.ytimg.com/vi/dmHeXH1YthI/default.jpg)XYX"sv, song_pic_thumb_481543, std::nullopt, song_pic_tiny_thumb_481543  };

constexpr std::array<song_artists, 4> song_artists_song_481543 {{
  { artist_t{ std::nullopt, "Producer"sv, false, 117165, R"XYX(Synthion)XYX"sv, R"XYX(image/jpeg)XYX"sv, std::nullopt, "Finished"sv, 7 }, "Producer"sv, "Default"sv, 1332945, false, false, R"XYX(Synthion)XYX"sv, "Default"sv },
  { artist_t{ R"XYX(初音ミク V4 (English), 初音ミク V4X (English), Hatsune Miku V4X (English))XYX"sv, "Vocaloid"sv, false, 49724, R"XYX(Hatsune Miku V4 (English))XYX"sv, R"XYX(image/png)XYX"sv, 2016y/8/31, "Finished"sv, 27 }, "Vocalist"sv, "Default"sv, 1332949, false, false, R"XYX(Hatsune Miku V4 (English))XYX"sv, "Default"sv },
  { artist_t{ R"XYX(ぶくろて)XYX"sv, "Illustrator"sv, false, 127081, R"XYX(Bukurote)XYX"sv, R"XYX(image/jpeg)XYX"sv, std::nullopt, "Finished"sv, 3 }, "Illustrator"sv, "Illustrator"sv, 1524030, false, false, R"XYX(Bukurote)XYX"sv, "Illustrator"sv },
  { artist_t{ R"XYX(クリプトン・フューチャー・メディア, CFM, クリプトン・フューチャー・メディア（株）, Crypton Future Media, Inc., SONICWIRE)XYX"sv, "Label"sv, false, 25, R"XYX(Crypton Future Media)XYX"sv, R"XYX(image/gif)XYX"sv, std::nullopt, "Locked"sv, 28 }, "Label"sv, "Default"sv, 1962750, false, false, R"XYX(Crypton Future Media)XYX"sv, "Default"sv },
}};

constexpr std::array<std::string_view, 1> culture_codes_song_481543 {{
"en"sv, }};

constexpr std::array<song_pv, 2> pvs_song_481543 {{
  { R"XYX(HatsuneMiku)XYX"sv, std::nullopt, false, R"XYX(std::nullopt)XYX"sv, 738780, 248, R"XYX(【MIKU EXPO 2023 VR】Synthion feat. Hatsune Miku - “imaginary love story” Lyric Video)XYX"sv, 2023y/3/11, R"XYX(dmHeXH1YthI)XYX"sv, "Youtube"sv, "Original"sv, R"XYX(https://i.ytimg.com/vi/dmHeXH1YthI/default.jpg)XYX"sv, R"XYX(https://youtu.be/dmHeXH1YthI)XYX"sv },
  { R"XYX(Synthion - Topic)XYX"sv, std::nullopt, false, R"XYX(std::nullopt)XYX"sv, 987357, 248, R"XYX(imaginary love story (feat. 初音ミク))XYX"sv, 2023y/11/1, R"XYX(CRIBcoYxALA)XYX"sv, "Youtube"sv, "Original"sv, R"XYX(https://i.ytimg.com/vi/CRIBcoYxALA/default.jpg)XYX"sv, R"XYX(https://youtu.be/CRIBcoYxALA)XYX"sv },
}};

/* End Song 481543: imaginary love story */

/* Start Song 183348: Inappropriate Lady */

constexpr std::array<additional_name, 4> names_song_183348 {{
  {"Japanese"sv, R"XYX(不適切淑女)XYX"sv},
  {"Romaji"sv, R"XYX(Futekisetsu Shukujo)XYX"sv},
  {"English"sv, R"XYX(Inappropriate Lady)XYX"sv},
  {"Unspecified"sv, R"XYX(Improper Lady)XYX"sv},
}};

constexpr std::array<web_link, 4> web_links_song_183348 {{
  {"Official"sv, R"XYX(Nico Commons - Karaoke)XYX"sv, R"XYX(http://commons.nicovideo.jp/material/nc173053)XYX"sv, 68025 },
  {"Reference"sv, R"XYX(Vocaloid Lyrics Wiki)XYX"sv, R"XYX(https://vocaloidlyrics.miraheze.org/wiki/%E4%B8%8D%E9%81%A9%E5%88%87%E6%B7%91%E5%A5%B3_(Futekisetsu_Shukujo))XYX"sv, 68079 },
  {"Reference"sv, R"XYX(MikuWiki)XYX"sv, R"XYX(https://www5.atwiki.jp/hmiku/pages/37245.html)XYX"sv, 68080 },
  {"Official"sv, R"XYX(OSTER project's Website)XYX"sv, R"XYX(http://fuwafuwacinnamon.sakura.ne.jp/music/futekisetsu.html)XYX"sv, 68081 },
}};


#if __has_embed("song_pic_orig_183348.jpg") == __STDC_EMBED_FOUND__
constexpr std::array song_pic_orig_183348 = std::to_array<std::uint8_t>({
    #embed "song_pic_orig_183348.jpg"
});
#else
constexpr std::array<std::uint8_t, 0> song_pic_orig_183348;
#endif

constexpr std::array<std::uint8_t, 0> song_pic_small_thumb_183348;


#if __has_embed("song_pic_thumb_183348.jpg") == __STDC_EMBED_FOUND__
constexpr std::array song_pic_thumb_183348 = std::to_array<std::uint8_t>({
    #embed "song_pic_thumb_183348.jpg"
});
#else
constexpr std::array<std::uint8_t, 0> song_pic_thumb_183348;
#endif

constexpr std::array<std::uint8_t, 0> song_pic_tiny_thumb_183348;

constexpr picture picture_song_183348 = { std::nullopt, std::nullopt, R"XYX(https://i1.ytimg.com/vi/EQYkdMBdx70/hqdefault.jpg)XYX"sv, song_pic_orig_183348, std::nullopt, song_pic_small_thumb_183348, R"XYX(https://nicovideo.cdn.nimg.jp/thumbnails/32685535/32685535)XYX"sv, song_pic_thumb_183348, std::nullopt, song_pic_tiny_thumb_183348  };

constexpr std::array<song_artists, 3> song_artists_song_183348 {{
  { artist_t{ R"XYX(不破志奈, ふわしな, fuwacina , テスロ, TESRO, ロゼット, ROSET, ふわふわシナモン, Fuwafuwa Cinnamon, ふたなりP, FutanariP, FTNR-P)XYX"sv, "Producer"sv, false, 58, R"XYX(OSTER project)XYX"sv, R"XYX(image/jpeg)XYX"sv, std::nullopt, "Approved"sv, 40 }, "Producer"sv, "Default"sv, 462150, false, false, R"XYX(OSTER project)XYX"sv, "Default"sv },
  { artist_t{ R"XYX(フ子)XYX"sv, "Illustrator"sv, false, 64309, R"XYX(Fuco)XYX"sv, R"XYX(image/jpeg)XYX"sv, std::nullopt, "Finished"sv, 4 }, "Illustrator"sv, "Illustrator"sv, 462151, false, false, R"XYX(Fuco)XYX"sv, "Default"sv },
  { artist_t{ R"XYX(メイコV3 (Unknown))XYX"sv, "Vocaloid"sv, false, 15811, R"XYX(MEIKO V3 (Unknown))XYX"sv, R"XYX(image/png)XYX"sv, 2014y/2/4, "Finished"sv, 18 }, "Vocalist"sv, "Default"sv, 462152, false, false, R"XYX(MEIKO V3 (Unknown))XYX"sv, "Default"sv },
}};

constexpr std::array<std::string_view, 1> culture_codes_song_183348 {{
"ja"sv, }};

constexpr std::array<song_pv, 4> pvs_song_183348 {{
  { R"XYX(ふわふわシナモン)XYX"sv, std::nullopt, false, R"XYX(std::nullopt)XYX"sv, 264742, 254, R"XYX(【MEIKO】不適切淑女【オリジナル曲】)XYX"sv, 2018y/2/4, R"XYX(sm32685535)XYX"sv, "NicoNicoDouga"sv, "Original"sv, R"XYX(https://nicovideo.cdn.nimg.jp/thumbnails/32685535/32685535)XYX"sv, R"XYX(http://www.nicovideo.jp/watch/sm32685535)XYX"sv },
  { R"XYX(fuwacina)XYX"sv, std::nullopt, false, R"XYX(std::nullopt)XYX"sv, 264743, 255, R"XYX(【VOCALOID】不適切淑女 【MEIKO】)XYX"sv, 2018y/2/4, R"XYX(EQYkdMBdx70)XYX"sv, "Youtube"sv, "Original"sv, R"XYX(https://i.ytimg.com/vi/EQYkdMBdx70/default.jpg)XYX"sv, R"XYX(https://youtu.be/EQYkdMBdx70)XYX"sv },
  { R"XYX(よんあか)XYX"sv, std::nullopt, false, R"XYX(std::nullopt)XYX"sv, 265170, 0, R"XYX(【MEIKO】不適切淑女【OSTER Project】)XYX"sv, 2018y/2/4, R"XYX(19134905)XYX"sv, "Bilibili"sv, "Reprint"sv, R"XYX(https://i1.hdslb.com/bfs/archive/679ed17e6d80f1104acf89da7cbae427f38a5b61.jpg)XYX"sv, R"XYX(https://www.bilibili.com/video/av19134905)XYX"sv },
  { R"XYX(OSTER Project - Topic)XYX"sv, std::nullopt, false, R"XYX(std::nullopt)XYX"sv, 567039, 256, R"XYX(不適切淑女)XYX"sv, 2019y/1/9, R"XYX(PEDGc50T4FA)XYX"sv, "Youtube"sv, "Original"sv, R"XYX(https://i.ytimg.com/vi/PEDGc50T4FA/default.jpg)XYX"sv, R"XYX(https://youtu.be/PEDGc50T4FA)XYX"sv },
}};

/* End Song 183348: Inappropriate Lady */

/* Start Song 2443: Last Night, Good Night */

constexpr std::array<additional_name, 1> names_song_2443 {{
  {"English"sv, R"XYX(Last Night, Good Night)XYX"sv},
}};

constexpr std::array<web_link, 16> web_links_song_2443 {{
  {"Reference"sv, R"XYX(MikuWiki)XYX"sv, R"XYX(http://www5.atwiki.jp/hmiku/pages/1916.html)XYX"sv, 159 },
  {"Commercial"sv, R"XYX(iTunes (GB))XYX"sv, R"XYX(https://itunes.apple.com/gb/music-video/last-night-good-night-feat./id648801992)XYX"sv, 2379 },
  {"Reference"sv, R"XYX(Vocaloid Wiki)XYX"sv, R"XYX(http://vocaloid.fandom.com/wiki/Last_Night%2C_Good_Night)XYX"sv, 2605 },
  {"Reference"sv, R"XYX(NicoNicoPedia)XYX"sv, R"XYX(http://dic.nicovideo.jp/v/sm4141643)XYX"sv, 4401 },
  {"Reference"sv, R"XYX(UtaiteDB)XYX"sv, R"XYX(http://utaitedb.net/S/11411)XYX"sv, 10696 },
  {"Official"sv, R"XYX(Pixiv (Illustration 1))XYX"sv, R"XYX(http://www.pixiv.net/member_illust.php?mode=medium&illust_id=1311855)XYX"sv, 44247 },
  {"Official"sv, R"XYX(Pixiv (Illustration 2))XYX"sv, R"XYX(http://www.pixiv.net/member_illust.php?mode=medium&illust_id=1298383)XYX"sv, 44248 },
  {"Official"sv, R"XYX(Pixiv (Illustration 3))XYX"sv, R"XYX(http://www.pixiv.net/member_illust.php?mode=medium&illust_id=1281967)XYX"sv, 44249 },
  {"Official"sv, R"XYX(Pixiv (Illustration 4))XYX"sv, R"XYX(http://www.pixiv.net/member_illust.php?mode=medium&illust_id=1311347)XYX"sv, 44250 },
  {"Official"sv, R"XYX(DeviantArt (Illustration 1))XYX"sv, R"XYX(http://redjuice999.deviantart.com/art/Last-Night-Good-Night-93480155)XYX"sv, 44251 },
  {"Official"sv, R"XYX(DeviantArt (Illustration 3))XYX"sv, R"XYX(http://redjuice999.deviantart.com/art/Eternal-Song-92083811)XYX"sv, 44252 },
  {"Official"sv, R"XYX(DeviantArt (Illustration 2))XYX"sv, R"XYX(http://redjuice999.deviantart.com/art/Farewell-92183244)XYX"sv, 44253 },
  {"Reference"sv, R"XYX(Vocaloid Lyrics Wiki)XYX"sv, R"XYX(https://vocaloidlyrics.miraheze.org/wiki/Last_Night%2C_Good_Night)XYX"sv, 74194 },
  {"Commercial"sv, R"XYX(Spotify (マジカルミライ2014))XYX"sv, R"XYX(https://open.spotify.com/track/3uHi6KtSfHKs86DZyUfLvl)XYX"sv, 85231 },
  {"Reference"sv, R"XYX(Pixiv Encyclopedia)XYX"sv, R"XYX(https://dic.pixiv.net/a/LastNight%2CGoodNight)XYX"sv, 156636 },
  {"Reference"sv, R"XYX(Moegirlpedia (zh-cn))XYX"sv, R"XYX(https://zh.moegirl.org.cn/Last_Night,_Good_Night)XYX"sv, 156637 },
}};


#if __has_embed("song_pic_orig_2443.jpg") == __STDC_EMBED_FOUND__
constexpr std::array song_pic_orig_2443 = std::to_array<std::uint8_t>({
    #embed "song_pic_orig_2443.jpg"
});
#else
constexpr std::array<std::uint8_t, 0> song_pic_orig_2443;
#endif

constexpr std::array<std::uint8_t, 0> song_pic_small_thumb_2443;


#if __has_embed("song_pic_thumb_2443.jpg") == __STDC_EMBED_FOUND__
constexpr std::array song_pic_thumb_2443 = std::to_array<std::uint8_t>({
    #embed "song_pic_thumb_2443.jpg"
});
#else
constexpr std::array<std::uint8_t, 0> song_pic_thumb_2443;
#endif

constexpr std::array<std::uint8_t, 0> song_pic_tiny_thumb_2443;

constexpr picture picture_song_2443 = { std::nullopt, std::nullopt, R"XYX(https://i1.ytimg.com/vi/T6mMMYSqlM4/hqdefault.jpg)XYX"sv, song_pic_orig_2443, std::nullopt, song_pic_small_thumb_2443, R"XYX(https://i.ytimg.com/vi/T6mMMYSqlM4/default.jpg)XYX"sv, song_pic_thumb_2443, std::nullopt, song_pic_tiny_thumb_2443  };

constexpr std::array<song_artists, 3> song_artists_song_2443 {{
  { artist_t{ R"XYX(RE:NDZ, ダイソンP, Daison P)XYX"sv, "Producer"sv, false, 89, R"XYX(kz)XYX"sv, R"XYX(image/jpeg)XYX"sv, std::nullopt, "Approved"sv, 29 }, "Producer"sv, "Default"sv, 1168, false, false, R"XYX(kz)XYX"sv, "Default"sv },
  { artist_t{ R"XYX(初音ミク, 初音未来, Chūyīn Wèilái, 하츠네 미쿠, 初音未來)XYX"sv, "Vocaloid"sv, false, 1, R"XYX(Hatsune Miku)XYX"sv, R"XYX(image/png)XYX"sv, 2007y/8/31, "Locked"sv, 39 }, "Vocalist"sv, "Default"sv, 1169, false, false, R"XYX(Hatsune Miku)XYX"sv, "Default"sv },
  { artist_t{ R"XYX(しる, shiru)XYX"sv, "Illustrator"sv, false, 2589, R"XYX(redjuice)XYX"sv, R"XYX(image/jpeg)XYX"sv, std::nullopt, "Approved"sv, 14 }, "Animator, Illustrator"sv, "Animator, Illustrator"sv, 77217, false, false, R"XYX(redjuice)XYX"sv, "Animator, Illustrator"sv },
}};

constexpr std::array<std::string_view, 1> culture_codes_song_2443 {{
"ja"sv, }};

constexpr std::array<song_pv, 6> pvs_song_2443 {{
  { R"XYX(kzlivetune)XYX"sv, std::nullopt, false, R"XYX(std::nullopt)XYX"sv, 137812, 384, R"XYX(livetune - Last Night, Good Night)XYX"sv, 2011y/12/15, R"XYX(T6mMMYSqlM4)XYX"sv, "Youtube"sv, "Original"sv, R"XYX(https://i.ytimg.com/vi/T6mMMYSqlM4/default.jpg)XYX"sv, R"XYX(https://youtu.be/T6mMMYSqlM4)XYX"sv },
  { R"XYX(kz)XYX"sv, std::nullopt, false, R"XYX(std::nullopt)XYX"sv, 137813, 383, R"XYX(初音ミクがオリジナル曲を歌ってくれました「Last Night, Good Night」)XYX"sv, 2008y/7/31, R"XYX(sm4141643)XYX"sv, "NicoNicoDouga"sv, "Original"sv, R"XYX(https://nicovideo.cdn.nimg.jp/thumbnails/4141643/4141643)XYX"sv, R"XYX(http://www.nicovideo.jp/watch/sm4141643)XYX"sv },
  { R"XYX(redjuice)XYX"sv, std::nullopt, false, R"XYX(std::nullopt)XYX"sv, 288579, 382, R"XYX(Last Night, Good Night PV)XYX"sv, 2008y/8/1, R"XYX(1448583)XYX"sv, "Vimeo"sv, "Original"sv, R"XYX(http://i.vimeocdn.com/video/151675499_100x75.jpg)XYX"sv, R"XYX(http://vimeo.com/1448583)XYX"sv },
  { R"XYX(soundares)XYX"sv, std::nullopt, false, R"XYX(std::nullopt)XYX"sv, 288580, 384, R"XYX(Miku's "Last night, Good night" with English Lyric)XYX"sv, 2008y/8/28, R"XYX(jf1pg3NI6Do)XYX"sv, "Youtube"sv, "Other"sv, R"XYX(https://i.ytimg.com/vi/jf1pg3NI6Do/default.jpg)XYX"sv, R"XYX(https://youtu.be/jf1pg3NI6Do)XYX"sv },
  { R"XYX(livetune+ - Topic)XYX"sv, std::nullopt, false, R"XYX(std::nullopt)XYX"sv, 446109, 381, R"XYX(Last Night, Good Night)XYX"sv, 2018y/7/10, R"XYX(DS1UvDjX-qo)XYX"sv, "Youtube"sv, "Original"sv, R"XYX(https://i.ytimg.com/vi/DS1UvDjX-qo/default.jpg)XYX"sv, R"XYX(https://youtu.be/DS1UvDjX-qo)XYX"sv },
  { R"XYX(hatunemikulove)XYX"sv, std::nullopt, false, R"XYX(std::nullopt)XYX"sv, 452468, 384, R"XYX(初音ミク Last Night, Good Night)XYX"sv, 2009y/1/15, R"XYX(zDldRF1CUBI)XYX"sv, "Youtube"sv, "Reprint"sv, R"XYX(https://i.ytimg.com/vi/zDldRF1CUBI/default.jpg)XYX"sv, R"XYX(https://youtu.be/zDldRF1CUBI)XYX"sv },
}};

/* End Song 2443: Last Night, Good Night */

/* Start Song 1435: Luka Luka★Night Fever */

constexpr std::array<additional_name, 2> names_song_1435 {{
  {"Japanese"sv, R"XYX(ルカルカ★ナイトフィーバー)XYX"sv},
  {"English"sv, R"XYX(Luka Luka★Night Fever)XYX"sv},
}};

constexpr std::array<web_link, 13> web_links_song_1435 {{
  {"Reference"sv, R"XYX(NicoNicoPedia)XYX"sv, R"XYX(http://dic.nicovideo.jp/v/sm6119955)XYX"sv, 4641 },
  {"Reference"sv, R"XYX(MikuWiki)XYX"sv, R"XYX(http://www5.atwiki.jp/hmiku/pages/4251.html)XYX"sv, 4642 },
  {"Reference"sv, R"XYX(Vocaloid Wiki)XYX"sv, R"XYX(https://vocaloid.fandom.com/wiki/ルカルカ★ナイトフィーバー_(Luka_Luka★Night_Fever))XYX"sv, 4643 },
  {"Reference"sv, R"XYX(Vocaloid Lyrics Wiki)XYX"sv, R"XYX(https://vocaloidlyrics.miraheze.org/wiki/ルカルカ★ナイトフィーバー_(Luka_Luka★Night_Fever))XYX"sv, 25132 },
  {"Commercial"sv, R"XYX(Amazon)XYX"sv, R"XYX(https://www.amazon.com/dp/B00SYAQXHC/)XYX"sv, 33175 },
  {"Official"sv, R"XYX(Piapro - illustration by 春アキ)XYX"sv, R"XYX(http://piapro.jp/t/c3W_)XYX"sv, 64111 },
  {"Reference"sv, R"XYX(UtaiteDB)XYX"sv, R"XYX(http://utaitedb.net/S/8530)XYX"sv, 64634 },
  {"Reference"sv, R"XYX(Wikipedia (JP))XYX"sv, R"XYX(https://ja.wikipedia.org/wiki/%E3%83%AB%E3%82%AB%E3%83%AB%E3%82%AB%E2%98%85%E3%83%8A%E3%82%A4%E3%83%88%E3%83%95%E3%82%A3%E3%83%BC%E3%83%90%E3%83%BC)XYX"sv, 72868 },
  {"Official"sv, R"XYX(Pixiv - illustration by 春アキ)XYX"sv, R"XYX(https://www.pixiv.net/member_illust.php?mode=medium&illust_id=2909411)XYX"sv, 75733 },
  {"Commercial"sv, R"XYX(Spotify)XYX"sv, R"XYX(https://open.spotify.com/track/4jLy2AGvZhiboczAV8bBK5)XYX"sv, 85232 },
  {"Reference"sv, R"XYX(Wikipedia (ZH))XYX"sv, R"XYX(https://zh.wikipedia.org/wiki/LukaLuka%E2%98%85NightFever)XYX"sv, 156620 },
  {"Reference"sv, R"XYX(Pixiv Encyclopedia)XYX"sv, R"XYX(https://dic.pixiv.net/a/%E3%83%AB%E3%82%AB%E3%83%AB%E3%82%AB%E2%98%85%E3%83%8A%E3%82%A4%E3%83%88%E3%83%95%E3%82%A3%E3%83%BC%E3%83%90%E3%83%BC)XYX"sv, 156621 },
  {"Reference"sv, R"XYX(Moegirlpedia (zh-cn))XYX"sv, R"XYX(https://zh.moegirl.org.cn/LUKALUKA_NIGHT_FEVER)XYX"sv, 156622 },
}};


#if __has_embed("song_pic_orig_1435.jpg") == __STDC_EMBED_FOUND__
constexpr std::array song_pic_orig_1435 = std::to_array<std::uint8_t>({
    #embed "song_pic_orig_1435.jpg"
});
#else
constexpr std::array<std::uint8_t, 0> song_pic_orig_1435;
#endif

constexpr std::array<std::uint8_t, 0> song_pic_small_thumb_1435;


#if __has_embed("song_pic_thumb_1435.jpg") == __STDC_EMBED_FOUND__
constexpr std::array song_pic_thumb_1435 = std::to_array<std::uint8_t>({
    #embed "song_pic_thumb_1435.jpg"
});
#else
constexpr std::array<std::uint8_t, 0> song_pic_thumb_1435;
#endif

constexpr std::array<std::uint8_t, 0> song_pic_tiny_thumb_1435;

constexpr picture picture_song_1435 = { std::nullopt, std::nullopt, R"XYX(https://i1.ytimg.com/vi/v1iomlLD3jc/hqdefault.jpg)XYX"sv, song_pic_orig_1435, std::nullopt, song_pic_small_thumb_1435, R"XYX(https://nicovideo.cdn.nimg.jp/thumbnails/6119955/6119955)XYX"sv, song_pic_thumb_1435, std::nullopt, song_pic_tiny_thumb_1435  };

constexpr std::array<song_artists, 3> song_artists_song_1435 {{
  { artist_t{ R"XYX(SAM, かんぴょう巻き, Kanpyoumaki, 佐野貴幸, Sano Takayuki)XYX"sv, "Producer"sv, false, 52, R"XYX(samfree)XYX"sv, R"XYX(image/jpeg)XYX"sv, std::nullopt, "Approved"sv, 18 }, "Producer"sv, "Default"sv, 716, false, false, R"XYX(samfree)XYX"sv, "Default"sv },
  { artist_t{ R"XYX(巡音ルカ, 巡音流歌, 메구리네 루카)XYX"sv, "Vocaloid"sv, false, 2, R"XYX(Megurine Luka)XYX"sv, R"XYX(image/png)XYX"sv, 2009y/1/30, "Locked"sv, 24 }, "Vocalist"sv, "Default"sv, 717, false, false, R"XYX(Megurine Luka)XYX"sv, "Default"sv },
  { artist_t{ R"XYX(春アキ, 春日アキラ, Haruhi Akira, haru_aki, scl_HaruAki)XYX"sv, "Animator"sv, false, 2128, R"XYX(Haru Aki)XYX"sv, R"XYX(image/jpeg)XYX"sv, std::nullopt, "Finished"sv, 11 }, "Illustrator"sv, "Illustrator"sv, 115745, false, false, R"XYX(Haru Aki)XYX"sv, "Illustrator"sv },
}};

constexpr std::array<std::string_view, 1> culture_codes_song_1435 {{
"ja"sv, }};

constexpr std::array<song_pv, 4> pvs_song_1435 {{
  { R"XYX(samfree)XYX"sv, std::nullopt, false, R"XYX(std::nullopt)XYX"sv, 282497, 239, R"XYX(巡音ルカ「ルカルカ★ナイトフィーバー」【オリジナル曲】)XYX"sv, 2009y/2/12, R"XYX(sm6119955)XYX"sv, "NicoNicoDouga"sv, "Original"sv, R"XYX(https://nicovideo.cdn.nimg.jp/thumbnails/6119955/6119955)XYX"sv, R"XYX(http://www.nicovideo.jp/watch/sm6119955)XYX"sv },
  { R"XYX(LATprojectV3)XYX"sv, std::nullopt, false, R"XYX(std::nullopt)XYX"sv, 355180, 240, R"XYX(巡音ルカ「ルカルカ★ナイトフィーバー」【オリジナル曲】)XYX"sv, 2013y/9/22, R"XYX(v1iomlLD3jc)XYX"sv, "Youtube"sv, "Reprint"sv, R"XYX(https://i.ytimg.com/vi/v1iomlLD3jc/default.jpg)XYX"sv, R"XYX(https://youtu.be/v1iomlLD3jc)XYX"sv },
  { R"XYX(googoo888)XYX"sv, std::nullopt, false, R"XYX(std::nullopt)XYX"sv, 355182, 242, R"XYX([1080P Full風] Luka Luka★Night Fever ルカルカ★ナイトフィーバー 巡音ルカ Project DIVA English lyrics romaji subtitles)XYX"sv, 2012y/9/15, R"XYX(ScSW9C3DF18)XYX"sv, "Youtube"sv, "Other"sv, R"XYX(https://i.ytimg.com/vi/ScSW9C3DF18/default.jpg)XYX"sv, R"XYX(https://youtu.be/ScSW9C3DF18)XYX"sv },
  { R"XYX(hatunemikulove)XYX"sv, std::nullopt, false, R"XYX(std::nullopt)XYX"sv, 452298, 240, R"XYX(巡音ルカ ルカルカ★ナイトフィーバー)XYX"sv, 2009y/9/6, R"XYX(5BJYOy6gp_8)XYX"sv, "Youtube"sv, "Reprint"sv, R"XYX(https://i.ytimg.com/vi/5BJYOy6gp_8/default.jpg)XYX"sv, R"XYX(https://youtu.be/5BJYOy6gp_8)XYX"sv },
}};

/* End Song 1435: Luka Luka★Night Fever */

/* Start Song 480845: NEPPUU ~Blistering Wind~ */

constexpr std::array<additional_name, 5> names_song_480845 {{
  {"Japanese"sv, R"XYX(NEPPUU〜熱風〜)XYX"sv},
  {"English"sv, R"XYX(NEPPUU ~Blistering Wind~)XYX"sv},
  {"Unspecified"sv, R"XYX(NEPPUU)XYX"sv},
  {"Romaji"sv, R"XYX(NEPPUU ~Neppuu~)XYX"sv},
  {"Unspecified"sv, R"XYX(HOT WIND)XYX"sv},
}};

constexpr std::array<web_link, 1> web_links_song_480845 {{
  {"Reference"sv, R"XYX(Vocaloid Lyrics Wiki)XYX"sv, R"XYX(https://vocaloidlyrics.miraheze.org/wiki/NEPPUU%E3%80%9C%E7%86%B1%E9%A2%A8%E3%80%9C_(Neppuu))XYX"sv, 166922 },
}};


#if __has_embed("song_pic_orig_480845.jpg") == __STDC_EMBED_FOUND__
constexpr std::array song_pic_orig_480845 = std::to_array<std::uint8_t>({
    #embed "song_pic_orig_480845.jpg"
});
#else
constexpr std::array<std::uint8_t, 0> song_pic_orig_480845;
#endif

constexpr std::array<std::uint8_t, 0> song_pic_small_thumb_480845;


#if __has_embed("song_pic_thumb_480845.jpg") == __STDC_EMBED_FOUND__
constexpr std::array song_pic_thumb_480845 = std::to_array<std::uint8_t>({
    #embed "song_pic_thumb_480845.jpg"
});
#else
constexpr std::array<std::uint8_t, 0> song_pic_thumb_480845;
#endif

constexpr std::array<std::uint8_t, 0> song_pic_tiny_thumb_480845;

constexpr picture picture_song_480845 = { std::nullopt, std::nullopt, R"XYX(https://i1.ytimg.com/vi/DmACzPgHYjQ/hqdefault.jpg)XYX"sv, song_pic_orig_480845, std::nullopt, song_pic_small_thumb_480845, R"XYX(https://i.ytimg.com/vi/DmACzPgHYjQ/default.jpg)XYX"sv, song_pic_thumb_480845, std::nullopt, song_pic_tiny_thumb_480845  };

constexpr std::array<song_artists, 7> song_artists_song_480845 {{
  { artist_t{ R"XYX(みきとP, 愛島, Aijima, 미키토P)XYX"sv, "Producer"sv, false, 876, R"XYX(MikitoP)XYX"sv, R"XYX(image/jpeg)XYX"sv, std::nullopt, "Approved"sv, 30 }, "Producer"sv, "Default"sv, 1330755, false, false, R"XYX(MikitoP)XYX"sv, "Default"sv },
  { artist_t{ R"XYX(友達募集P, Tomodachi BoshuuP)XYX"sv, "Producer"sv, false, 2131, R"XYX(tomoboP)XYX"sv, R"XYX(image/png)XYX"sv, std::nullopt, "Finished"sv, 10 }, "Other"sv, "Mastering"sv, 1330757, false, false, R"XYX(tomoboP)XYX"sv, "Mastering"sv },
  { artist_t{ R"XYX(波多ヒロ, 竜宮ツカサ, Ryuuguu Tsukasa, マンボウの姉, Manbou no Ane, hata hiro)XYX"sv, "Illustrator"sv, false, 2569, R"XYX(hatahiro)XYX"sv, R"XYX(image/jpeg)XYX"sv, std::nullopt, "Finished"sv, 15 }, "Illustrator"sv, "Illustrator"sv, 1330758, false, false, R"XYX(hatahiro)XYX"sv, "Default"sv },
  { artist_t{ R"XYX(とさお, Tosao, anarchylily)XYX"sv, "Animator"sv, false, 2124, R"XYX(TSO)XYX"sv, R"XYX(image/jpeg)XYX"sv, std::nullopt, "Finished"sv, 10 }, "Animator"sv, "Animator"sv, 1330759, false, false, R"XYX(TSO)XYX"sv, "Animator"sv },
  { artist_t{ R"XYX(鼓童, Kodou)XYX"sv, "OtherGroup"sv, false, 56929, R"XYX(Kodō)XYX"sv, R"XYX(image/jpeg)XYX"sv, std::nullopt, "Finished"sv, 5 }, "Other"sv, "Other"sv, 1330760, false, false, R"XYX(Kodō)XYX"sv, "Other"sv },
  { artist_t{ R"XYX(初音ミク V4X (Solid))XYX"sv, "Vocaloid"sv, false, 50235, R"XYX(Hatsune Miku V4X (Solid))XYX"sv, R"XYX(image/png)XYX"sv, 2016y/8/31, "Finished"sv, 9 }, "Vocalist"sv, "Default"sv, 1331854, false, false, R"XYX(Hatsune Miku V4X (Solid))XYX"sv, "Default"sv },
  { artist_t{ R"XYX(クリプトン・フューチャー・メディア, CFM, クリプトン・フューチャー・メディア（株）, Crypton Future Media, Inc., SONICWIRE)XYX"sv, "Label"sv, false, 25, R"XYX(Crypton Future Media)XYX"sv, R"XYX(image/gif)XYX"sv, std::nullopt, "Locked"sv, 28 }, "Label"sv, "Default"sv, 1962006, false, false, R"XYX(Crypton Future Media)XYX"sv, "Default"sv },
}};

constexpr std::array<std::string_view, 2> culture_codes_song_480845 {{
"ja"sv, "en"sv, }};

constexpr std::array<song_pv, 4> pvs_song_480845 {{
  { R"XYX(HatsuneMiku)XYX"sv, std::nullopt, false, R"XYX(std::nullopt)XYX"sv, 737543, 276, R"XYX(NEPPUU〜熱風〜 / みきとP feat.初音ミク)XYX"sv, 2023y/3/7, R"XYX(DmACzPgHYjQ)XYX"sv, "Youtube"sv, "Original"sv, R"XYX(https://i.ytimg.com/vi/DmACzPgHYjQ/default.jpg)XYX"sv, R"XYX(https://youtu.be/DmACzPgHYjQ)XYX"sv },
  { std::nullopt, std::nullopt, false, R"XYX(std::nullopt)XYX"sv, 737544, 276, R"XYX(NEPPUU〜熱風〜 / みきとP feat.初音ミク)XYX"sv, 2023y/3/7, R"XYX(so41876213)XYX"sv, "NicoNicoDouga"sv, "Original"sv, R"XYX(https://nicovideo.cdn.nimg.jp/thumbnails/41876213/41876213.42598284)XYX"sv, R"XYX(http://www.nicovideo.jp/watch/so41876213)XYX"sv },
  { R"XYX(初音未来_Crypton)XYX"sv, std::nullopt, false, R"XYX({"Aid":438039554,"Bvid":"BV1nj41137qk","Cid":1041157496})XYX"sv, 737545, 277, R"XYX(NEPPU〜熱風〜 / みきとP feat.初音未来)XYX"sv, 2023y/3/7, R"XYX(438039554)XYX"sv, "Bilibili"sv, "Original"sv, R"XYX(http://i0.hdslb.com/bfs/archive/70c3080e7749ddad01463bec442b0ed13cfa7913.jpg)XYX"sv, R"XYX(https://www.bilibili.com/video/av438039554)XYX"sv },
  { R"XYX(MikitoP - Topic)XYX"sv, std::nullopt, false, R"XYX(std::nullopt)XYX"sv, 991879, 277, R"XYX(NEPPUU～熱風～ (feat. Hatsune Miku))XYX"sv, 2023y/6/5, R"XYX(YxTSW_u4774)XYX"sv, "Youtube"sv, "Original"sv, R"XYX(https://i.ytimg.com/vi/YxTSW_u4774/default.jpg)XYX"sv, R"XYX(https://youtu.be/YxTSW_u4774)XYX"sv },
}};

/* End Song 480845: NEPPUU ~Blistering Wind~ */

/* Start Song 169614: Ramnade blue longing */

constexpr std::array<additional_name, 3> names_song_169614 {{
  {"Japanese"sv, R"XYX(ラムネイドブルーの憧憬)XYX"sv},
  {"English"sv, R"XYX(Ramnade blue longing)XYX"sv},
  {"Romaji"sv, R"XYX(Ramunade Blue no Shoukei)XYX"sv},
}};

constexpr std::array<web_link, 0> web_links_song_169614 {{
}};


#if __has_embed("song_pic_orig_169614.jpg") == __STDC_EMBED_FOUND__
constexpr std::array song_pic_orig_169614 = std::to_array<std::uint8_t>({
    #embed "song_pic_orig_169614.jpg"
});
#else
constexpr std::array<std::uint8_t, 0> song_pic_orig_169614;
#endif

constexpr std::array<std::uint8_t, 0> song_pic_small_thumb_169614;


#if __has_embed("song_pic_thumb_169614.jpg") == __STDC_EMBED_FOUND__
constexpr std::array song_pic_thumb_169614 = std::to_array<std::uint8_t>({
    #embed "song_pic_thumb_169614.jpg"
});
#else
constexpr std::array<std::uint8_t, 0> song_pic_thumb_169614;
#endif

constexpr std::array<std::uint8_t, 0> song_pic_tiny_thumb_169614;

constexpr picture picture_song_169614 = { std::nullopt, std::nullopt, R"XYX(https://i1.ytimg.com/vi/tT1tEcvAaQM/hqdefault.jpg)XYX"sv, song_pic_orig_169614, std::nullopt, song_pic_small_thumb_169614, R"XYX(https://nicovideo.cdn.nimg.jp/thumbnails/32056116/32056116)XYX"sv, song_pic_thumb_169614, std::nullopt, song_pic_tiny_thumb_169614  };

constexpr std::array<song_artists, 4> song_artists_song_169614 {{
  { artist_t{ R"XYX(アオトケイ, Fuji(141hP), Aotokei, SeA0)XYX"sv, "Producer"sv, false, 6177, R"XYX(Aoto Kei)XYX"sv, R"XYX(image/jpeg)XYX"sv, std::nullopt, "Finished"sv, 19 }, "Producer"sv, "Default"sv, 419938, false, false, R"XYX(Aoto Kei)XYX"sv, "Default"sv },
  { artist_t{ R"XYX(movie_YY)XYX"sv, "Illustrator"sv, false, 50230, R"XYX(Y_Y)XYX"sv, R"XYX(image/jpeg)XYX"sv, std::nullopt, "Finished"sv, 7 }, "Illustrator"sv, "Illustrator"sv, 419947, false, false, R"XYX(Y_Y)XYX"sv, "Illustrator"sv },
  { artist_t{ R"XYX(びじー)XYX"sv, "Producer"sv, false, 1780, R"XYX(busy...)XYX"sv, R"XYX(image/png)XYX"sv, std::nullopt, "Finished"sv, 15 }, "Other"sv, "Instrumentalist"sv, 419948, false, false, R"XYX(busy...)XYX"sv, "Instrumentalist"sv },
  { artist_t{ R"XYX(メイコV3 (Power))XYX"sv, "Vocaloid"sv, false, 15948, R"XYX(MEIKO V3 (Power))XYX"sv, R"XYX(image/png)XYX"sv, 2014y/2/4, "Finished"sv, 15 }, "Vocalist"sv, "Default"sv, 1801741, false, false, R"XYX(MEIKO V3 (Power))XYX"sv, "Default"sv },
}};

constexpr std::array<std::string_view, 1> culture_codes_song_169614 {{
"ja"sv, }};

constexpr std::array<song_pv, 4> pvs_song_169614 {{
  { R"XYX(aotokei)XYX"sv, std::nullopt, false, R"XYX(std::nullopt)XYX"sv, 245734, 271, R"XYX(ラムネイドブルーの憧憬/feat.MEIKO)XYX"sv, 2017y/10/7, R"XYX(sm32056116)XYX"sv, "NicoNicoDouga"sv, "Original"sv, R"XYX(https://nicovideo.cdn.nimg.jp/thumbnails/32056116/32056116)XYX"sv, R"XYX(http://www.nicovideo.jp/watch/sm32056116)XYX"sv },
  { R"XYX(aotokei official)XYX"sv, std::nullopt, false, R"XYX(std::nullopt)XYX"sv, 245738, 272, R"XYX(ラムネイドブルーの憧憬/feat.MEIKO)XYX"sv, 2017y/10/7, R"XYX(tT1tEcvAaQM)XYX"sv, "Youtube"sv, "Original"sv, R"XYX(https://i.ytimg.com/vi/tT1tEcvAaQM/default.jpg)XYX"sv, R"XYX(https://youtu.be/tT1tEcvAaQM)XYX"sv },
  { R"XYX(Aoto Kei - Topic)XYX"sv, std::nullopt, false, R"XYX(std::nullopt)XYX"sv, 1033719, 272, R"XYX(ラムネイドブルーの憧憬 (feat. MEIKO))XYX"sv, 2024y/3/26, R"XYX(8rjHF933hrY)XYX"sv, "Youtube"sv, "Original"sv, R"XYX(https://i.ytimg.com/vi/8rjHF933hrY/default.jpg)XYX"sv, R"XYX(https://youtu.be/8rjHF933hrY)XYX"sv },
  { R"XYX(Aoto Kei - Topic)XYX"sv, std::nullopt, false, R"XYX(std::nullopt)XYX"sv, 1232030, 268, R"XYX(ラムネイドブルーの憧憬 (feat. MEIKO))XYX"sv, 2019y/7/3, R"XYX(O5e2cFNxdJA)XYX"sv, "Youtube"sv, "Original"sv, R"XYX(https://i.ytimg.com/vi/O5e2cFNxdJA/default.jpg)XYX"sv, R"XYX(https://youtu.be/O5e2cFNxdJA)XYX"sv },
}};

/* End Song 169614: Ramnade blue longing */

/* Start Song 182370: Sharing The World [ SPANISH VER ] */

constexpr std::array<additional_name, 2> names_song_182370 {{
  {"English"sv, R"XYX(Sharing The World [ SPANISH VER ])XYX"sv},
  {"Unspecified"sv, R"XYX(Sharing The World)XYX"sv},
}};

constexpr std::array<web_link, 0> web_links_song_182370 {{
}};


#if __has_embed("song_pic_orig_182370.jpg") == __STDC_EMBED_FOUND__
constexpr std::array song_pic_orig_182370 = std::to_array<std::uint8_t>({
    #embed "song_pic_orig_182370.jpg"
});
#else
constexpr std::array<std::uint8_t, 0> song_pic_orig_182370;
#endif

constexpr std::array<std::uint8_t, 0> song_pic_small_thumb_182370;


#if __has_embed("song_pic_thumb_182370.jpg") == __STDC_EMBED_FOUND__
constexpr std::array song_pic_thumb_182370 = std::to_array<std::uint8_t>({
    #embed "song_pic_thumb_182370.jpg"
});
#else
constexpr std::array<std::uint8_t, 0> song_pic_thumb_182370;
#endif

constexpr std::array<std::uint8_t, 0> song_pic_tiny_thumb_182370;

constexpr picture picture_song_182370 = { std::nullopt, std::nullopt, R"XYX(https://i1.ytimg.com/vi/98a7GpD2qa0/hqdefault.jpg)XYX"sv, song_pic_orig_182370, std::nullopt, song_pic_small_thumb_182370, R"XYX(https://i.ytimg.com/vi/98a7GpD2qa0/default.jpg)XYX"sv, song_pic_thumb_182370, std::nullopt, song_pic_tiny_thumb_182370  };

constexpr std::array<song_artists, 6> song_artists_song_182370 {{
  { artist_t{ R"XYX(初音ミク, 初音未来, Chūyīn Wèilái, 하츠네 미쿠, 初音未來)XYX"sv, "Vocaloid"sv, false, 1, R"XYX(Hatsune Miku)XYX"sv, R"XYX(image/png)XYX"sv, 2007y/8/31, "Locked"sv, 39 }, "Vocalist"sv, "Default"sv, 459144, false, false, R"XYX(Hatsune Miku)XYX"sv, "Default"sv },
  { artist_t{ R"XYX(Elekitel, エレキP, ELEKI)XYX"sv, "Producer"sv, false, 2733, R"XYX(BIGHEAD)XYX"sv, R"XYX(image/jpeg)XYX"sv, std::nullopt, "Finished"sv, 42 }, "Producer"sv, "Default"sv, 459145, false, false, R"XYX(BIGHEAD)XYX"sv, "Default"sv },
  { artist_t{ R"XYX(初音ミク V3 (English), 初音ミク英語版, Hatsune Miku Eigo-ban)XYX"sv, "Vocaloid"sv, false, 958, R"XYX(Hatsune Miku V3 (English))XYX"sv, R"XYX(image/png)XYX"sv, 2013y/8/30, "Approved"sv, 33 }, "Vocalist"sv, "Default"sv, 459146, false, true, R"XYX(Hatsune Miku V3 (English))XYX"sv, "Default"sv },
  { artist_t{ std::nullopt, "Circle"sv, false, 21591, R"XYX(Maubox)XYX"sv, R"XYX(image/png)XYX"sv, std::nullopt, "Finished"sv, 15 }, "Circle"sv, "Default"sv, 459147, false, false, R"XYX(Maubox)XYX"sv, "Default"sv },
  { artist_t{ std::nullopt, "Producer"sv, false, 21563, R"XYX(Ankari)XYX"sv, R"XYX(image/png)XYX"sv, std::nullopt, "Finished"sv, 17 }, "Producer"sv, "VoiceManipulator"sv, 688093, false, false, R"XYX(Ankari)XYX"sv, "VoiceManipulator"sv },
  { artist_t{ R"XYX(rainpuddles)XYX"sv, "Illustrator"sv, false, 65225, R"XYX(Lluvia)XYX"sv, R"XYX(image/jpeg)XYX"sv, std::nullopt, "Finished"sv, 7 }, "Other"sv, "Lyricist"sv, 688094, false, false, R"XYX(Lluvia)XYX"sv, "Lyricist"sv },
}};

constexpr std::array<std::string_view, 1> culture_codes_song_182370 {{
"es"sv, }};

constexpr std::array<song_pv, 2> pvs_song_182370 {{
  { R"XYX(FORESIGHT STUDIO OFFICIAL)XYX"sv, std::nullopt, false, R"XYX(std::nullopt)XYX"sv, 263272, 250, R"XYX(Sharing The World feat.Hatsune Miku [ SPANISH VER ] by BIGHEAD)XYX"sv, 2018y/1/24, R"XYX(98a7GpD2qa0)XYX"sv, "Youtube"sv, "Original"sv, R"XYX(https://i.ytimg.com/vi/98a7GpD2qa0/default.jpg)XYX"sv, R"XYX(https://youtu.be/98a7GpD2qa0)XYX"sv },
  { R"XYX(BIGHEAD - Topic)XYX"sv, std::nullopt, false, R"XYX(std::nullopt)XYX"sv, 690699, 250, R"XYX(Sharing the World SPANISH Ver. (feat. Hatsune Miku))XYX"sv, 2020y/8/6, R"XYX(fuDtz_yyvRs)XYX"sv, "Youtube"sv, "Original"sv, R"XYX(https://i.ytimg.com/vi/fuDtz_yyvRs/default.jpg)XYX"sv, R"XYX(https://youtu.be/fuDtz_yyvRs)XYX"sv },
}};

/* End Song 182370: Sharing The World [ SPANISH VER ] */

/* Start Song 155305: Singularity */

constexpr std::array<additional_name, 1> names_song_155305 {{
  {"English"sv, R"XYX(Singularity)XYX"sv},
}};

constexpr std::array<web_link, 1> web_links_song_155305 {{
  {"Official"sv, R"XYX(Result announcement by official Hatsune Miku Channel)XYX"sv, R"XYX(https://www.youtube.com/watch?v=Ishsal1mZvk&t=0s)XYX"sv, 54677 },
}};


#if __has_embed("song_pic_orig_155305.jpg") == __STDC_EMBED_FOUND__
constexpr std::array song_pic_orig_155305 = std::to_array<std::uint8_t>({
    #embed "song_pic_orig_155305.jpg"
});
#else
constexpr std::array<std::uint8_t, 0> song_pic_orig_155305;
#endif

constexpr std::array<std::uint8_t, 0> song_pic_small_thumb_155305;


#if __has_embed("song_pic_thumb_155305.jpg") == __STDC_EMBED_FOUND__
constexpr std::array song_pic_thumb_155305 = std::to_array<std::uint8_t>({
    #embed "song_pic_thumb_155305.jpg"
});
#else
constexpr std::array<std::uint8_t, 0> song_pic_thumb_155305;
#endif

constexpr std::array<std::uint8_t, 0> song_pic_tiny_thumb_155305;

constexpr picture picture_song_155305 = { std::nullopt, std::nullopt, R"XYX(https://i1.ytimg.com/vi/Blc2HbNaUsg/hqdefault.jpg)XYX"sv, song_pic_orig_155305, std::nullopt, song_pic_small_thumb_155305, R"XYX(https://nicovideo.cdn.nimg.jp/thumbnails/31405153/31405153)XYX"sv, song_pic_thumb_155305, std::nullopt, song_pic_tiny_thumb_155305  };

constexpr std::array<song_artists, 3> song_artists_song_155305 {{
  { artist_t{ R"XYX(初音ミク, 初音未来, Chūyīn Wèilái, 하츠네 미쿠, 初音未來)XYX"sv, "Vocaloid"sv, false, 1, R"XYX(Hatsune Miku)XYX"sv, R"XYX(image/png)XYX"sv, 2007y/8/31, "Locked"sv, 39 }, "Vocalist"sv, "Default"sv, 374046, false, false, R"XYX(Hatsune Miku)XYX"sv, "Default"sv },
  { artist_t{ std::nullopt, "Producer"sv, false, 2741, R"XYX(keisei)XYX"sv, R"XYX(image/jpeg)XYX"sv, std::nullopt, "Finished"sv, 23 }, "Producer"sv, "Default"sv, 374047, false, false, R"XYX(keisei)XYX"sv, "Default"sv },
  { artist_t{ R"XYX(piarsk)XYX"sv, "Illustrator"sv, false, 48532, R"XYX(rsk)XYX"sv, R"XYX(image/jpeg)XYX"sv, std::nullopt, "Finished"sv, 4 }, "Animator, Illustrator"sv, "Animator, Illustrator"sv, 387169, false, false, R"XYX(rsk)XYX"sv, "Animator, Illustrator"sv },
}};

constexpr std::array<std::string_view, 1> culture_codes_song_155305 {{
"ja"sv, }};

constexpr std::array<song_pv, 5> pvs_song_155305 {{
  { R"XYX(keisei_1092)XYX"sv, std::nullopt, false, R"XYX({"Timestamp":"20170402203115"})XYX"sv, 224106, 266, R"XYX(Singularity)XYX"sv, 2017y/4/2, R"XYX(mws1govf19rhfo4o)XYX"sv, "Piapro"sv, "Original"sv, std::nullopt, R"XYX(http://piapro.jp/content/mws1govf19rhfo4o)XYX"sv },
  { R"XYX(keisei_1092)XYX"sv, std::nullopt, false, R"XYX(std::nullopt)XYX"sv, 230337, 252, R"XYX(初音ミクオリジナル曲「Singularity」)XYX"sv, 2017y/6/16, R"XYX(sm31405153)XYX"sv, "NicoNicoDouga"sv, "Original"sv, R"XYX(https://nicovideo.cdn.nimg.jp/thumbnails/31405153/31405153)XYX"sv, R"XYX(http://www.nicovideo.jp/watch/sm31405153)XYX"sv },
  { R"XYX(keisei)XYX"sv, std::nullopt, false, R"XYX(std::nullopt)XYX"sv, 230386, 253, R"XYX(Hatsune Miku Original Song "Singularity")XYX"sv, 2017y/6/17, R"XYX(Blc2HbNaUsg)XYX"sv, "Youtube"sv, "Original"sv, R"XYX(https://i.ytimg.com/vi/Blc2HbNaUsg/default.jpg)XYX"sv, R"XYX(https://youtu.be/Blc2HbNaUsg)XYX"sv },
  { R"XYX(keisei)XYX"sv, std::nullopt, false, R"XYX(std::nullopt)XYX"sv, 230434, 252, R"XYX(Singularity (feat. Hatsune Miku))XYX"sv, 2017y/6/17, R"XYX(328523702 keisei_1092/singularity-feat-hatsune-miku)XYX"sv, "SoundCloud"sv, "Original"sv, R"XYX(https://i1.sndcdn.com/avatars-000121683554-8bvcn8-large.jpg)XYX"sv, R"XYX(http://soundcloud.com/keisei_1092/singularity-feat-hatsune-miku)XYX"sv },
  { R"XYX(Keisei - Topic)XYX"sv, std::nullopt, false, R"XYX(std::nullopt)XYX"sv, 525337, 255, R"XYX(Singularity (feat. Hatsune Miku))XYX"sv, 2020y/4/3, R"XYX(UHh9KZ3i-8A)XYX"sv, "Youtube"sv, "Original"sv, R"XYX(https://i.ytimg.com/vi/UHh9KZ3i-8A/default.jpg)XYX"sv, R"XYX(https://youtu.be/UHh9KZ3i-8A)XYX"sv },
}};

/* End Song 155305: Singularity */

/* Start Song 18083: End of Solitude */

constexpr std::array<additional_name, 6> names_song_18083 {{
  {"Romaji"sv, R"XYX(Kodoku no Hate)XYX"sv},
  {"English"sv, R"XYX(End of Solitude)XYX"sv},
  {"Japanese"sv, R"XYX(孤独の果て)XYX"sv},
  {"Unspecified"sv, R"XYX(Solitude's End)XYX"sv},
  {"Unspecified"sv, R"XYX(The End of Solitude)XYX"sv},
  {"Unspecified"sv, R"XYX(고독의 끝)XYX"sv},
}};

constexpr std::array<web_link, 6> web_links_song_18083 {{
  {"Official"sv, R"XYX(Piapro / Karaoke (without chorus))XYX"sv, R"XYX(http://piapro.jp/t/02IY)XYX"sv, 18556 },
  {"Reference"sv, R"XYX(MikuWiki)XYX"sv, R"XYX(http://www5.atwiki.jp/hmiku/pages/6151.html)XYX"sv, 18557 },
  {"Reference"sv, R"XYX(NicoNicoPedia)XYX"sv, R"XYX(http://dic.nicovideo.jp/v/sm7882150)XYX"sv, 18558 },
  {"Reference"sv, R"XYX(UtaiteDB)XYX"sv, R"XYX(http://utaitedb.net/S/16392)XYX"sv, 18559 },
  {"Reference"sv, R"XYX(Vocaloid Lyrics Wiki)XYX"sv, R"XYX(https://vocaloidlyrics.miraheze.org/wiki/%E5%AD%A4%E7%8B%AC%E3%81%AE%E6%9E%9C%E3%81%A6_(Kodoku_no_Hate))XYX"sv, 54046 },
  {"Reference"sv, R"XYX(Vocaloid Wiki)XYX"sv, R"XYX(https://vocaloid.fandom.com/wiki/%E5%AD%A4%E7%8B%AC%E3%81%AE%E6%9E%9C%E3%81%A6_(Kodoku_no_Hate))XYX"sv, 181573 },
}};


#if __has_embed("song_pic_orig_18083.jpg") == __STDC_EMBED_FOUND__
constexpr std::array song_pic_orig_18083 = std::to_array<std::uint8_t>({
    #embed "song_pic_orig_18083.jpg"
});
#else
constexpr std::array<std::uint8_t, 0> song_pic_orig_18083;
#endif

constexpr std::array<std::uint8_t, 0> song_pic_small_thumb_18083;


#if __has_embed("song_pic_thumb_18083.jpg") == __STDC_EMBED_FOUND__
constexpr std::array song_pic_thumb_18083 = std::to_array<std::uint8_t>({
    #embed "song_pic_thumb_18083.jpg"
});
#else
constexpr std::array<std::uint8_t, 0> song_pic_thumb_18083;
#endif

constexpr std::array<std::uint8_t, 0> song_pic_tiny_thumb_18083;

constexpr picture picture_song_18083 = { std::nullopt, std::nullopt, R"XYX(https://i1.ytimg.com/vi/hvklQRYBwsE/hqdefault.jpg)XYX"sv, song_pic_orig_18083, std::nullopt, song_pic_small_thumb_18083, R"XYX(https://nicovideo.cdn.nimg.jp/thumbnails/7882150/7882150)XYX"sv, song_pic_thumb_18083, std::nullopt, song_pic_tiny_thumb_18083  };

constexpr std::array<song_artists, 3> song_artists_song_18083 {{
  { artist_t{ R"XYX(光収容, Hikarisyuyo, 광수용, 히카리 슈요)XYX"sv, "Producer"sv, false, 19, R"XYX(Hikari Syuyo)XYX"sv, R"XYX(image/jpeg)XYX"sv, std::nullopt, "Finished"sv, 23 }, "Producer"sv, "Default"sv, 27273, false, false, R"XYX(Hikari Syuyo)XYX"sv, "Default"sv },
  { artist_t{ R"XYX(鏡音リン, 鏡音鈴, 카가미네 린, 镜音铃)XYX"sv, "Vocaloid"sv, false, 14, R"XYX(Kagamine Rin)XYX"sv, R"XYX(image/png)XYX"sv, 2007y/12/27, "Locked"sv, 34 }, "Vocalist"sv, "Default"sv, 27274, false, false, R"XYX(Kagamine Rin)XYX"sv, "Default"sv },
  { artist_t{ R"XYX(ULOG'Be)XYX"sv, "Animator"sv, false, 1500, R"XYX(NEGI)XYX"sv, R"XYX(image/jpeg)XYX"sv, std::nullopt, "Finished"sv, 17 }, "Animator"sv, "Animator"sv, 192493, false, false, R"XYX(NEGI)XYX"sv, "Animator"sv },
}};

constexpr std::array<std::string_view, 1> culture_codes_song_18083 {{
"ja"sv, }};

constexpr std::array<song_pv, 4> pvs_song_18083 {{
  { R"XYX(Melissa Marquez)XYX"sv, std::nullopt, false, R"XYX(std::nullopt)XYX"sv, 98834, 263, R"XYX(【鏡音リン】 孤独の果て 【PV付きオリジナル】)XYX"sv, 2011y/12/2, R"XYX(qbTsoTSSPXc)XYX"sv, "Youtube"sv, "Reprint"sv, R"XYX(https://i.ytimg.com/vi/qbTsoTSSPXc/default.jpg)XYX"sv, R"XYX(https://youtu.be/qbTsoTSSPXc)XYX"sv },
  { R"XYX(hikari)XYX"sv, std::nullopt, false, R"XYX(std::nullopt)XYX"sv, 98839, 262, R"XYX(【鏡音リン】 孤独の果て 【PV付きオリジナル】)XYX"sv, 2009y/8/9, R"XYX(sm7882150)XYX"sv, "NicoNicoDouga"sv, "Original"sv, R"XYX(https://nicovideo.cdn.nimg.jp/thumbnails/7882150/7882150)XYX"sv, R"XYX(http://www.nicovideo.jp/watch/sm7882150)XYX"sv },
  { R"XYX(tony31706)XYX"sv, std::nullopt, false, R"XYX(std::nullopt)XYX"sv, 98841, 263, R"XYX(【鏡音リン】 孤独の果て 【PV付きオリジナル】中文字幕)XYX"sv, 2009y/8/14, R"XYX(EPjIlshV9OQ)XYX"sv, "Youtube"sv, "Other"sv, R"XYX(https://i.ytimg.com/vi/EPjIlshV9OQ/default.jpg)XYX"sv, R"XYX(https://youtu.be/EPjIlshV9OQ)XYX"sv },
  { R"XYX(Hikarisyuyo - Topic)XYX"sv, std::nullopt, false, R"XYX(std::nullopt)XYX"sv, 509294, 263, R"XYX(孤独の果て (feat. Kagamine Rin))XYX"sv, 2020y/4/3, R"XYX(hvklQRYBwsE)XYX"sv, "Youtube"sv, "Original"sv, R"XYX(https://i.ytimg.com/vi/hvklQRYBwsE/default.jpg)XYX"sv, R"XYX(https://youtu.be/hvklQRYBwsE)XYX"sv },
}};

/* End Song 18083: End of Solitude */

/* Start Song 1340: sound */

constexpr std::array<additional_name, 3> names_song_1340 {{
  {"English"sv, R"XYX(sound)XYX"sv},
  {"Japanese"sv, R"XYX(サウンド)XYX"sv},
  {"Unspecified"sv, R"XYX(사운드)XYX"sv},
}};

constexpr std::array<web_link, 4> web_links_song_1340 {{
  {"Reference"sv, R"XYX(Hatsune Miku wiki)XYX"sv, R"XYX(http://www5.atwiki.jp/hmiku/pages/138.html)XYX"sv, 32 },
  {"Reference"sv, R"XYX(Vocaloid Wiki)XYX"sv, R"XYX(http://vocaloid.wikia.com/wiki/サウンド_(sound))XYX"sv, 11338 },
  {"Official"sv, R"XYX(Piapro (Karaoke))XYX"sv, R"XYX(https://piapro.jp/t/q7AQ)XYX"sv, 96202 },
  {"Official"sv, R"XYX(Piapro (Karaoke, male key))XYX"sv, R"XYX(https://piapro.jp/t/xS17)XYX"sv, 96203 },
}};


#if __has_embed("song_pic_orig_1340.jpg") == __STDC_EMBED_FOUND__
constexpr std::array song_pic_orig_1340 = std::to_array<std::uint8_t>({
    #embed "song_pic_orig_1340.jpg"
});
#else
constexpr std::array<std::uint8_t, 0> song_pic_orig_1340;
#endif

constexpr std::array<std::uint8_t, 0> song_pic_small_thumb_1340;


#if __has_embed("song_pic_thumb_1340.jpg") == __STDC_EMBED_FOUND__
constexpr std::array song_pic_thumb_1340 = std::to_array<std::uint8_t>({
    #embed "song_pic_thumb_1340.jpg"
});
#else
constexpr std::array<std::uint8_t, 0> song_pic_thumb_1340;
#endif

constexpr std::array<std::uint8_t, 0> song_pic_tiny_thumb_1340;

constexpr picture picture_song_1340 = { std::nullopt, std::nullopt, R"XYX(https://i1.ytimg.com/vi/6xj70esQvKw/hqdefault.jpg)XYX"sv, song_pic_orig_1340, std::nullopt, song_pic_small_thumb_1340, R"XYX(https://nicovideo.cdn.nimg.jp/thumbnails/1583280/1583280)XYX"sv, song_pic_thumb_1340, std::nullopt, song_pic_tiny_thumb_1340  };

constexpr std::array<song_artists, 2> song_artists_song_1340 {{
  { artist_t{ R"XYX(FIFA-P, kisk, kisk_baker, kisk baker, Hattori Keisuke, KeisukeHattori, むぅ, Muu)XYX"sv, "Producer"sv, false, 127, R"XYX(baker)XYX"sv, R"XYX(image/jpeg)XYX"sv, std::nullopt, "Approved"sv, 27 }, "Producer"sv, "Default"sv, 387, false, false, R"XYX(baker)XYX"sv, "Default"sv },
  { artist_t{ R"XYX(初音ミク, 初音未来, Chūyīn Wèilái, 하츠네 미쿠, 初音未來)XYX"sv, "Vocaloid"sv, false, 1, R"XYX(Hatsune Miku)XYX"sv, R"XYX(image/png)XYX"sv, 2007y/8/31, "Locked"sv, 39 }, "Vocalist"sv, "Default"sv, 388, false, false, R"XYX(Hatsune Miku)XYX"sv, "Default"sv },
}};

constexpr std::array<std::string_view, 1> culture_codes_song_1340 {{
"ja"sv, }};

constexpr std::array<song_pv, 5> pvs_song_1340 {{
  { R"XYX(baker)XYX"sv, std::nullopt, false, R"XYX(std::nullopt)XYX"sv, 106705, 188, R"XYX(「サウンド」　song by 初音ミク)XYX"sv, 2007y/11/21, R"XYX(sm1583280)XYX"sv, "NicoNicoDouga"sv, "Original"sv, R"XYX(https://nicovideo.cdn.nimg.jp/thumbnails/1583280/1583280)XYX"sv, R"XYX(http://www.nicovideo.jp/watch/sm1583280)XYX"sv },
  { R"XYX(baker)XYX"sv, std::nullopt, true, R"XYX(std::nullopt)XYX"sv, 633014, 189, R"XYX(test)XYX"sv, 2007y/11/21, R"XYX(sm1582930)XYX"sv, "NicoNicoDouga"sv, "Original"sv, R"XYX(https://nicovideo.cdn.nimg.jp/thumbnails/1582930/1582930)XYX"sv, R"XYX(http://www.nicovideo.jp/watch/sm1582930)XYX"sv },
  { R"XYX(baker)XYX"sv, std::nullopt, true, R"XYX(std::nullopt)XYX"sv, 633015, 189, R"XYX(test)XYX"sv, 2007y/11/21, R"XYX(sm1583163)XYX"sv, "NicoNicoDouga"sv, "Original"sv, R"XYX(https://nicovideo.cdn.nimg.jp/thumbnails/1583163/1583163)XYX"sv, R"XYX(http://www.nicovideo.jp/watch/sm1583163)XYX"sv },
  { R"XYX(yukkie1969)XYX"sv, std::nullopt, false, R"XYX(std::nullopt)XYX"sv, 753457, 190, R"XYX(「サウンド」SONG by 初音ミク)XYX"sv, 2007y/11/22, R"XYX(6xj70esQvKw)XYX"sv, "Youtube"sv, "Reprint"sv, R"XYX(https://i.ytimg.com/vi/6xj70esQvKw/default.jpg)XYX"sv, R"XYX(https://youtu.be/6xj70esQvKw)XYX"sv },
  { R"XYX(deadnendo)XYX"sv, std::nullopt, false, R"XYX(std::nullopt)XYX"sv, 1080957, 190, R"XYX(「サウンド」 song by 初音ミク)XYX"sv, 2008y/2/24, R"XYX(78x3Tie3w0U)XYX"sv, "Youtube"sv, "Reprint"sv, R"XYX(https://i.ytimg.com/vi/78x3Tie3w0U/default.jpg)XYX"sv, R"XYX(https://youtu.be/78x3Tie3w0U)XYX"sv },
}};

/* End Song 1340: sound */

/* Start Song 531972: Star of Heaven */

constexpr std::array<additional_name, 3> names_song_531972 {{
  {"Japanese"sv, R"XYX(みかぼし)XYX"sv},
  {"Romaji"sv, R"XYX(Mikaboshi)XYX"sv},
  {"English"sv, R"XYX(Star of Heaven)XYX"sv},
}};

constexpr std::array<web_link, 0> web_links_song_531972 {{
}};


#if __has_embed("song_pic_orig_531972.jpg") == __STDC_EMBED_FOUND__
constexpr std::array song_pic_orig_531972 = std::to_array<std::uint8_t>({
    #embed "song_pic_orig_531972.jpg"
});
#else
constexpr std::array<std::uint8_t, 0> song_pic_orig_531972;
#endif

constexpr std::array<std::uint8_t, 0> song_pic_small_thumb_531972;


#if __has_embed("song_pic_thumb_531972.jpg") == __STDC_EMBED_FOUND__
constexpr std::array song_pic_thumb_531972 = std::to_array<std::uint8_t>({
    #embed "song_pic_thumb_531972.jpg"
});
#else
constexpr std::array<std::uint8_t, 0> song_pic_thumb_531972;
#endif

constexpr std::array<std::uint8_t, 0> song_pic_tiny_thumb_531972;

constexpr picture picture_song_531972 = { std::nullopt, std::nullopt, R"XYX(https://i1.ytimg.com/vi/tITBe-xkaBQ/hqdefault.jpg)XYX"sv, song_pic_orig_531972, std::nullopt, song_pic_small_thumb_531972, R"XYX(https://i.ytimg.com/vi/tITBe-xkaBQ/default.jpg)XYX"sv, song_pic_thumb_531972, std::nullopt, song_pic_tiny_thumb_531972  };

constexpr std::array<song_artists, 5> song_artists_song_531972 {{
  { artist_t{ R"XYX(篁惺, Satoru Takamura, 3106, 3106.com, さとる)XYX"sv, "Producer"sv, false, 9864, R"XYX(3106。)XYX"sv, R"XYX(image/jpeg)XYX"sv, std::nullopt, "Finished"sv, 12 }, "Producer"sv, "Default"sv, 1482226, false, false, R"XYX(3106。)XYX"sv, "Default"sv },
  { artist_t{ R"XYX(カイト)XYX"sv, "Vocaloid"sv, false, 71, R"XYX(KAITO)XYX"sv, R"XYX(image/png)XYX"sv, 2006y/2/14, "Locked"sv, 33 }, "Vocalist"sv, "Default"sv, 1482227, false, false, R"XYX(KAITO)XYX"sv, "Default"sv },
  { artist_t{ R"XYX(カイトV3 (Straight))XYX"sv, "Vocaloid"sv, false, 5588, R"XYX(KAITO V3 (Straight))XYX"sv, R"XYX(image/png)XYX"sv, 2013y/2/15, "Finished"sv, 16 }, "Vocalist"sv, "Default"sv, 1482252, false, true, R"XYX(KAITO V3 (Straight))XYX"sv, "Default"sv },
  { artist_t{ R"XYX(カイトV3 (Whisper))XYX"sv, "Vocaloid"sv, false, 5590, R"XYX(KAITO V3 (Whisper))XYX"sv, R"XYX(image/png)XYX"sv, 2013y/2/15, "Finished"sv, 15 }, "Vocalist"sv, "Default"sv, 1482253, false, true, R"XYX(KAITO V3 (Whisper))XYX"sv, "Default"sv },
  { artist_t{ R"XYX(カイトV3 (Soft))XYX"sv, "Vocaloid"sv, false, 5589, R"XYX(KAITO V3 (Soft))XYX"sv, R"XYX(image/png)XYX"sv, 2013y/2/15, "Finished"sv, 14 }, "Vocalist"sv, "Default"sv, 1482254, false, true, R"XYX(KAITO V3 (Soft))XYX"sv, "Default"sv },
}};

constexpr std::array<std::string_view, 0> culture_codes_song_531972 {{
}};

constexpr std::array<song_pv, 1> pvs_song_531972 {{
  { R"XYX(MaryRosea101)XYX"sv, std::nullopt, false, R"XYX(std::nullopt)XYX"sv, 1287891, 239, R"XYX(みかぼし KAITO)XYX"sv, 2025y/9/29, R"XYX(tITBe-xkaBQ)XYX"sv, "Youtube"sv, "Reprint"sv, R"XYX(https://i.ytimg.com/vi/tITBe-xkaBQ/default.jpg)XYX"sv, R"XYX(https://youtu.be/tITBe-xkaBQ)XYX"sv },
}};

/* End Song 531972: Star of Heaven */

/* Start Song 49871: Tale of the Deep-Sea Lily */

constexpr std::array<additional_name, 4> names_song_49871 {{
  {"Japanese"sv, R"XYX(ウミユリ海底譚)XYX"sv},
  {"Romaji"sv, R"XYX(Umiyuri Kaitei Tan)XYX"sv},
  {"English"sv, R"XYX(Tale of the Deep-Sea Lily)XYX"sv},
  {"Unspecified"sv, R"XYX(Sea Lily Deep Sea Tale)XYX"sv},
}};

constexpr std::array<web_link, 13> web_links_song_49871 {{
  {"Reference"sv, R"XYX(UtaiteDB)XYX"sv, R"XYX(http://utaitedb.net/S/1495)XYX"sv, 8468 },
  {"Reference"sv, R"XYX(NicoNicoPedia)XYX"sv, R"XYX(http://dic.nicovideo.jp/v/sm22960446)XYX"sv, 18280 },
  {"Reference"sv, R"XYX(MikuWiki)XYX"sv, R"XYX(http://www5.atwiki.jp/hmiku/pages/28547.html)XYX"sv, 18281 },
  {"Official"sv, R"XYX(Piapro / Instrumental)XYX"sv, R"XYX(http://piapro.jp/t/tXBa)XYX"sv, 18282 },
  {"Official"sv, R"XYX(Piapro / Instrumental (no mastering))XYX"sv, R"XYX(http://piapro.jp/t/dTfG)XYX"sv, 18283 },
  {"Reference"sv, R"XYX(Vocaloid Lyrics Wiki)XYX"sv, R"XYX(https://vocaloidlyrics.miraheze.org/wiki/%E3%82%A6%E3%83%9F%E3%83%A6%E3%83%AA%E6%B5%B7%E5%BA%95%E8%AD%9A_%28Umiyuri_Kanteitan%29)XYX"sv, 27748 },
  {"Reference"sv, R"XYX(Vocaloid Wiki)XYX"sv, R"XYX(http://vocaloid.fandom.com/wiki/%E3%82%A6%E3%83%9F%E3%83%A6%E3%83%AA%E6%B5%B7%E5%BA%95%E8%AD%9A_(Umiyuri_Kaiteitan))XYX"sv, 50210 },
  {"Reference"sv, R"XYX(Moegirlpedia (zh-cn))XYX"sv, R"XYX(https://zh.moegirl.org.cn/%E6%B5%B7%E7%99%BE%E5%90%88%E6%B5%B7%E5%BA%95%E8%B0%AD)XYX"sv, 163903 },
  {"Reference"sv, R"XYX(Namu Wiki)XYX"sv, R"XYX(https://en.namu.wiki/w/%EA%B0%AF%EB%82%98%EB%A6%AC%20%ED%95%B4%EC%A0%80%EB%8B%B4)XYX"sv, 163904 },
  {"Reference"sv, R"XYX(Pixiv Encyclopedia)XYX"sv, R"XYX(https://dic.pixiv.net/a/%E3%82%A6%E3%83%9F%E3%83%A6%E3%83%AA%E6%B5%B7%E5%BA%95%E8%AD%9A)XYX"sv, 163906 },
  {"Reference"sv, R"XYX(Project SEKAI Wiki)XYX"sv, R"XYX(https://projectsekai.fandom.com/wiki/Umiyuri_Kaiteitan)XYX"sv, 163907 },
  {"Other"sv, R"XYX(Sekaipedia)XYX"sv, R"XYX(https://www.sekaipedia.org/wiki/Umiyuri_Kaiteitan)XYX"sv, 163908 },
  {"Reference"sv, R"XYX(RemyWiki)XYX"sv, R"XYX(https://remywiki.com/Umiyuri_kaiteitan)XYX"sv, 163909 },
}};


#if __has_embed("song_pic_orig_49871.jpg") == __STDC_EMBED_FOUND__
constexpr std::array song_pic_orig_49871 = std::to_array<std::uint8_t>({
    #embed "song_pic_orig_49871.jpg"
});
#else
constexpr std::array<std::uint8_t, 0> song_pic_orig_49871;
#endif

constexpr std::array<std::uint8_t, 0> song_pic_small_thumb_49871;


#if __has_embed("song_pic_thumb_49871.jpg") == __STDC_EMBED_FOUND__
constexpr std::array song_pic_thumb_49871 = std::to_array<std::uint8_t>({
    #embed "song_pic_thumb_49871.jpg"
});
#else
constexpr std::array<std::uint8_t, 0> song_pic_thumb_49871;
#endif

constexpr std::array<std::uint8_t, 0> song_pic_tiny_thumb_49871;

constexpr picture picture_song_49871 = { std::nullopt, std::nullopt, R"XYX(https://i1.ytimg.com/vi/7JANm3jOb2k/hqdefault.jpg)XYX"sv, song_pic_orig_49871, std::nullopt, song_pic_small_thumb_49871, R"XYX(https://nicovideo.cdn.nimg.jp/thumbnails/22960446/22960446)XYX"sv, song_pic_thumb_49871, std::nullopt, song_pic_tiny_thumb_49871  };

constexpr std::array<song_artists, 3> song_artists_song_49871 {{
  { artist_t{ R"XYX(ナブナ, Nabuna, 나부나)XYX"sv, "Producer"sv, false, 3258, R"XYX(n-buna)XYX"sv, R"XYX(image/png)XYX"sv, std::nullopt, "Finished"sv, 26 }, "Producer"sv, "Default"sv, 415548, false, false, R"XYX(n-buna)XYX"sv, "Default"sv },
  { artist_t{ R"XYX(あわしま, Misuzu Nakamura)XYX"sv, "Animator"sv, false, 3288, R"XYX(Awashima)XYX"sv, R"XYX(image/jpeg)XYX"sv, std::nullopt, "Finished"sv, 8 }, "Animator"sv, "Default"sv, 415549, false, false, R"XYX(Awashima)XYX"sv, "Default"sv },
  { artist_t{ R"XYX(初音ミク V3 (Dark))XYX"sv, "Vocaloid"sv, false, 11835, R"XYX(Hatsune Miku V3 (Dark))XYX"sv, R"XYX(image/png)XYX"sv, 2013y/9/26, "Finished"sv, 13 }, "Vocalist"sv, "Default"sv, 2066091, false, false, R"XYX(Hatsune Miku V3 (Dark))XYX"sv, "Default"sv },
}};

constexpr std::array<std::string_view, 1> culture_codes_song_49871 {{
"ja"sv, }};

constexpr std::array<song_pv, 6> pvs_song_49871 {{
  { R"XYX(n-buna)XYX"sv, std::nullopt, false, R"XYX(std::nullopt)XYX"sv, 143063, 238, R"XYX(【初音ミク】 ウミユリ海底譚 【オリジナル曲】)XYX"sv, 2014y/2/24, R"XYX(sm22960446)XYX"sv, "NicoNicoDouga"sv, "Original"sv, R"XYX(https://nicovideo.cdn.nimg.jp/thumbnails/22960446/22960446)XYX"sv, R"XYX(http://www.nicovideo.jp/watch/sm22960446)XYX"sv },
  { R"XYX(Vervain subs)XYX"sv, std::nullopt, false, R"XYX(std::nullopt)XYX"sv, 229939, 239, R"XYX(Hatsune Miku - Sea Lily Deep Sea Tale (Sub Eng + Ita))XYX"sv, 2014y/3/15, R"XYX(qbNhJU2Pq-4)XYX"sv, "Youtube"sv, "Other"sv, R"XYX(https://i.ytimg.com/vi/qbNhJU2Pq-4/default.jpg)XYX"sv, R"XYX(https://youtu.be/qbNhJU2Pq-4)XYX"sv },
  { R"XYX(n-buna / ヨルシカ official)XYX"sv, std::nullopt, false, R"XYX(std::nullopt)XYX"sv, 265617, 239, R"XYX(【初音ミク】 ウミユリ海底譚 【オリジナル曲】)XYX"sv, 2017y/4/21, R"XYX(7JANm3jOb2k)XYX"sv, "Youtube"sv, "Original"sv, R"XYX(https://i.ytimg.com/vi/7JANm3jOb2k/default.jpg)XYX"sv, R"XYX(https://youtu.be/7JANm3jOb2k)XYX"sv },
  { R"XYX(n-buna)XYX"sv, std::nullopt, false, R"XYX({"Timestamp":"20140224203011"})XYX"sv, 349989, 238, R"XYX(ウミユリ海底譚)XYX"sv, 2014y/2/24, R"XYX(uyj33fvq9lh309ul)XYX"sv, "Piapro"sv, "Original"sv, std::nullopt, R"XYX(http://piapro.jp/content/uyj33fvq9lh309ul)XYX"sv },
  { R"XYX(n-buna - Topic)XYX"sv, std::nullopt, false, R"XYX(std::nullopt)XYX"sv, 997238, 237, R"XYX(ウミユリ海底譚)XYX"sv, 2020y/4/15, R"XYX(4CHmkLhW13s)XYX"sv, "Youtube"sv, "Original"sv, R"XYX(https://i.ytimg.com/vi/4CHmkLhW13s/default.jpg)XYX"sv, R"XYX(https://youtu.be/4CHmkLhW13s)XYX"sv },
  { R"XYX(n-buna - Topic)XYX"sv, std::nullopt, false, R"XYX(std::nullopt)XYX"sv, 1225269, 238, R"XYX(ウミユリ海底譚)XYX"sv, 2019y/3/8, R"XYX(H4JuDL4N-_c)XYX"sv, "Youtube"sv, "Original"sv, R"XYX(https://i.ytimg.com/vi/H4JuDL4N-_c/default.jpg)XYX"sv, R"XYX(https://youtu.be/H4JuDL4N-_c)XYX"sv },
}};

/* End Song 49871: Tale of the Deep-Sea Lily */

/* Start Song 164107: Unknown Mother-Goose */

constexpr std::array<additional_name, 4> names_song_164107 {{
  {"Japanese"sv, R"XYX(アンノウン・マザーグース)XYX"sv},
  {"English"sv, R"XYX(Unknown Mother-Goose)XYX"sv},
  {"Unspecified"sv, R"XYX(Unknown Mother Goose)XYX"sv},
  {"Unspecified"sv, R"XYX(不为人知的鹅妈妈童谣)XYX"sv},
}};

constexpr std::array<web_link, 8> web_links_song_164107 {{
  {"Reference"sv, R"XYX(Vocaloid Wiki)XYX"sv, R"XYX(http://vocaloid.fandom.com/wiki/%E3%82%A2%E3%83%B3%E3%83%8E%E3%82%A6%E3%83%B3%E3%83%BB%E3%83%9E%E3%82%B6%E3%83%BC%E3%82%B0%E3%83%BC%E3%82%B9_%28Unknown_Mother-Goose%29)XYX"sv, 60311 },
  {"Reference"sv, R"XYX(MikuWiki)XYX"sv, R"XYX(https://www5.atwiki.jp/hmiku/pages/36575.html)XYX"sv, 60312 },
  {"Reference"sv, R"XYX(NicoNicoPedia)XYX"sv, R"XYX(http://dic.nicovideo.jp/v/sm31791630)XYX"sv, 60315 },
  {"Reference"sv, R"XYX(UtaiteDB)XYX"sv, R"XYX(http://utaitedb.net/S/36655)XYX"sv, 60378 },
  {"Reference"sv, R"XYX(Vocaloid Lyrics Wiki)XYX"sv, R"XYX(https://vocaloidlyrics.miraheze.org/wiki/%E3%82%A2%E3%83%B3%E3%83%8E%E3%82%A6%E3%83%B3%E3%83%BB%E3%83%9E%E3%82%B6%E3%83%BC%E3%82%B0%E3%83%BC%E3%82%B9_(Unknown_Mother_Goose))XYX"sv, 60848 },
  {"Reference"sv, R"XYX(Pixiv Encyclopedia)XYX"sv, R"XYX(https://dic.pixiv.net/a/%E3%82%A2%E3%83%B3%E3%83%8E%E3%82%A6%E3%83%B3%E3%83%BB%E3%83%9E%E3%82%B6%E3%83%BC%E3%82%B0%E3%83%BC%E3%82%B9)XYX"sv, 82943 },
  {"Reference"sv, R"XYX(Moegirlpedia)XYX"sv, R"XYX(https://zh.moegirl.org/Unknown_Mother-Goose)XYX"sv, 82944 },
  {"Official"sv, R"XYX(Pixiv (Illustration))XYX"sv, R"XYX(https://www.pixiv.net/member_illust.php?mode=medium&illust_id=64598919)XYX"sv, 82952 },
}};


#if __has_embed("song_pic_orig_164107.jpg") == __STDC_EMBED_FOUND__
constexpr std::array song_pic_orig_164107 = std::to_array<std::uint8_t>({
    #embed "song_pic_orig_164107.jpg"
});
#else
constexpr std::array<std::uint8_t, 0> song_pic_orig_164107;
#endif

constexpr std::array<std::uint8_t, 0> song_pic_small_thumb_164107;


#if __has_embed("song_pic_thumb_164107.jpg") == __STDC_EMBED_FOUND__
constexpr std::array song_pic_thumb_164107 = std::to_array<std::uint8_t>({
    #embed "song_pic_thumb_164107.jpg"
});
#else
constexpr std::array<std::uint8_t, 0> song_pic_thumb_164107;
#endif

constexpr std::array<std::uint8_t, 0> song_pic_tiny_thumb_164107;

constexpr picture picture_song_164107 = { std::nullopt, std::nullopt, R"XYX(https://i1.ytimg.com/vi/P_CSdxSGfaA/hqdefault.jpg)XYX"sv, song_pic_orig_164107, std::nullopt, song_pic_small_thumb_164107, R"XYX(https://nicovideo.cdn.nimg.jp/thumbnails/31791630/31791630)XYX"sv, song_pic_thumb_164107, std::nullopt, song_pic_tiny_thumb_164107  };

constexpr std::array<song_artists, 6> song_artists_song_164107 {{
  { artist_t{ R"XYX(現実逃避P, GenjitsutouhiP)XYX"sv, "Producer"sv, false, 53, R"XYX(wowaka)XYX"sv, R"XYX(image/jpeg)XYX"sv, std::nullopt, "Approved"sv, 41 }, "Vocalist, Producer, Animator, Illustrator"sv, "Animator, Composer, Illustrator, Vocalist"sv, 402630, false, false, R"XYX(wowaka)XYX"sv, "Animator, Composer, Illustrator, Vocalist"sv },
  { artist_t{ R"XYX(シノダナオキ, 衝動的の人, Shoudou-teki no Hito, cakebox)XYX"sv, "Producer"sv, false, 3348, R"XYX(Shinoda Naoki)XYX"sv, R"XYX(image/jpeg)XYX"sv, std::nullopt, "Finished"sv, 12 }, "Other"sv, "Instrumentalist"sv, 408378, false, false, R"XYX(Shinoda Naoki)XYX"sv, "Instrumentalist"sv },
  { artist_t{ R"XYX(イガラシ, Igarashi, ygarshy)XYX"sv, "Instrumentalist"sv, false, 3341, R"XYX(Ygarshi)XYX"sv, R"XYX(image/png)XYX"sv, std::nullopt, "Finished"sv, 11 }, "Other"sv, "Instrumentalist"sv, 408379, false, false, R"XYX(Ygarshi)XYX"sv, "Instrumentalist"sv },
  { artist_t{ R"XYX(ゆーまお, Hayashi Yuma)XYX"sv, "Instrumentalist"sv, false, 2558, R"XYX(Yumao)XYX"sv, R"XYX(image/png)XYX"sv, std::nullopt, "Finished"sv, 9 }, "Other"sv, "Instrumentalist"sv, 408380, false, false, R"XYX(Yumao)XYX"sv, "Instrumentalist"sv },
  { artist_t{ R"XYX(ヒトリエ)XYX"sv, "Circle"sv, false, 66878, R"XYX(Hitorie)XYX"sv, R"XYX(image/jpeg)XYX"sv, std::nullopt, "Finished"sv, 7 }, "Circle"sv, "Default"sv, 500187, false, false, R"XYX(Hitorie)XYX"sv, "Default"sv },
  { artist_t{ R"XYX(初音ミク V4X (Dark))XYX"sv, "Vocaloid"sv, false, 50233, R"XYX(Hatsune Miku V4X (Dark))XYX"sv, R"XYX(image/png)XYX"sv, 2016y/8/31, "Finished"sv, 10 }, "Vocalist"sv, "Default"sv, 754774, false, false, R"XYX(Hatsune Miku V4X (Dark))XYX"sv, "Default"sv },
}};

constexpr std::array<std::string_view, 1> culture_codes_song_164107 {{
"ja"sv, }};

constexpr std::array<song_pv, 3> pvs_song_164107 {{
  { R"XYX(wowaka)XYX"sv, std::nullopt, false, R"XYX(std::nullopt)XYX"sv, 239933, 285, R"XYX(wowaka『アンノウン・マザーグース』feat. 初音ミク)XYX"sv, 2017y/8/22, R"XYX(sm31791630)XYX"sv, "NicoNicoDouga"sv, "Original"sv, R"XYX(https://nicovideo.cdn.nimg.jp/thumbnails/31791630/31791630)XYX"sv, R"XYX(http://www.nicovideo.jp/watch/sm31791630)XYX"sv },
  { R"XYX(ヒトリエ / wowaka)XYX"sv, std::nullopt, false, R"XYX(std::nullopt)XYX"sv, 239934, 286, R"XYX(wowaka 『アンノウン・マザーグース』feat. 初音ミク / wowaka - Unknown Mother-Goose (Official Video) ft. Hatsune Miku)XYX"sv, 2017y/8/22, R"XYX(P_CSdxSGfaA)XYX"sv, "Youtube"sv, "Original"sv, R"XYX(https://i.ytimg.com/vi/P_CSdxSGfaA/default.jpg)XYX"sv, R"XYX(https://youtu.be/P_CSdxSGfaA)XYX"sv },
  { R"XYX(Forgetfulsubs)XYX"sv, std::nullopt, false, R"XYX(std::nullopt)XYX"sv, 242042, 286, R"XYX(【Wowaka】Unknown Mother Goose - eng sub 【Hatsune Miku】)XYX"sv, 2017y/8/23, R"XYX(gr5Csep6yFM)XYX"sv, "Youtube"sv, "Other"sv, R"XYX(https://i.ytimg.com/vi/gr5Csep6yFM/default.jpg)XYX"sv, R"XYX(https://youtu.be/gr5Csep6yFM)XYX"sv },
}};

/* End Song 164107: Unknown Mother-Goose */

export constexpr std::array<song, 20> songs {{
  {R"XYX(＊ハロー、プラネット。)XYX"sv, song_artists_song_2924, R"XYX(sasakure.UK feat. Hatsune Miku)XYX"sv, 2011y/11/6, R"XYX(＊ハロー、プラネット。)XYX"sv, "Japanese"sv, std::nullopt, 150, 2924, std::chrono::seconds(305), picture_song_2924, 150000, std::nullopt, 150000, R"XYX(*Hello, Planet.)XYX"sv, names_song_2924, std::nullopt, 2008y/9/23, pvs_song_2924, "NicoNicoDouga, Youtube"sv, 781, "Original"sv, "Approved"sv, R"XYX(https://nicovideo.cdn.nimg.jp/thumbnails/7138245/7138245)XYX"sv, 32, web_links_song_2924, culture_codes_song_2924},
  {R"XYX(Acceleration (New Version))XYX"sv, song_artists_song_188729, R"XYX(Clean Tears feat. Hatsune Miku V3 (Solid))XYX"sv, 2018y/4/1, R"XYX(Acceleration (Breeze Remix))XYX"sv, "English"sv, std::nullopt, 15, 188729, std::chrono::seconds(292), picture_song_188729, std::nullopt, std::nullopt, std::nullopt, R"XYX(Acceleration (Breeze Remix))XYX"sv, names_song_188729, 5113, 2018y/4/1, pvs_song_188729, "NicoNicoDouga, Youtube, Bilibili"sv, 111, "Remix"sv, "Finished"sv, R"XYX(https://nicovideo.cdn.nimg.jp/thumbnails/32982184/32982184)XYX"sv, 13, web_links_song_188729, culture_codes_song_188729},
  {R"XYX(愛されなくても君がいる, Aisarenakute mo Kimi ga Iru, 就算没有爱 只要有你就好, 사랑받지 못해도 네가 있어)XYX"sv, song_artists_song_284993, R"XYX(PinocchioP feat. Hatsune Miku)XYX"sv, 2020y/6/15, R"XYX(愛されなくても君がいる)XYX"sv, "Japanese"sv, std::nullopt, 87, 284993, std::chrono::seconds(270), picture_song_284993, 150000, std::nullopt, 150000, R"XYX(Because You're Here)XYX"sv, names_song_284993, std::nullopt, 2020y/7/22, pvs_song_284993, "NicoNicoDouga, Youtube, Bilibili"sv, 496, "Original"sv, "Approved"sv, R"XYX(https://i.ytimg.com/vi/ygY2qObZv24/default.jpg)XYX"sv, 18, web_links_song_284993, culture_codes_song_284993},
  {std::nullopt, song_artists_song_8247, R"XYX(CrystalP, bestgt feat. KAITO, Kagamine Len)XYX"sv, 2012y/1/12, R"XYX(erase or zero)XYX"sv, "English"sv, std::nullopt, 49, 8247, std::chrono::seconds(229), picture_song_8247, 138000, std::nullopt, 138000, R"XYX(erase or zero)XYX"sv, names_song_8247, std::nullopt, 2008y/5/13, pvs_song_8247, "NicoNicoDouga, Youtube"sv, 295, "Original"sv, "Finished"sv, R"XYX(https://nicovideo.cdn.nimg.jp/thumbnails/3307158/3307158)XYX"sv, 31, web_links_song_8247, culture_codes_song_8247},
  {std::nullopt, song_artists_song_6387, R"XYX(halyosy, is feat. Kagamine Len)XYX"sv, 2012y/1/1, R"XYX(Fire◎Flower)XYX"sv, "English"sv, std::nullopt, 55, 6387, std::chrono::seconds(260), picture_song_6387, 175000, std::nullopt, 175000, R"XYX(Fire◎Flower)XYX"sv, names_song_6387, std::nullopt, 2008y/8/2, pvs_song_6387, "NicoNicoDouga, Youtube, Piapro"sv, 379, "Original"sv, "Approved"sv, R"XYX(https://i.ytimg.com/vi/myEsj-qf73A/default.jpg)XYX"sv, 24, web_links_song_6387, culture_codes_song_6387},
  {std::nullopt, song_artists_song_1797, R"XYX(keeno feat. Hatsune Miku Append (Dark))XYX"sv, 2011y/11/2, R"XYX(glow)XYX"sv, "English"sv, std::nullopt, 97, 1797, std::chrono::seconds(283), picture_song_1797, 85010, std::nullopt, 85010, R"XYX(glow)XYX"sv, names_song_1797, std::nullopt, 2010y/6/28, pvs_song_1797, "NicoNicoDouga, Youtube, Piapro"sv, 515, "Original"sv, "Finished"sv, R"XYX(https://nicovideo.cdn.nimg.jp/thumbnails/11209477/11209477)XYX"sv, 39, web_links_song_1797, culture_codes_song_1797},
  {R"XYX(ヘッジホッグ, 헤지호그)XYX"sv, song_artists_song_329458, R"XYX(Noz. feat. Kagamine Rin)XYX"sv, 2021y/4/25, R"XYX(ヘッジホッグ)XYX"sv, "Japanese"sv, std::nullopt, 15, 329458, std::chrono::seconds(214), picture_song_329458, std::nullopt, std::nullopt, std::nullopt, R"XYX(Hedgehog)XYX"sv, names_song_329458, std::nullopt, 2021y/4/24, pvs_song_329458, "NicoNicoDouga, Youtube"sv, 103, "Original"sv, "Finished"sv, R"XYX(https://nicovideo.cdn.nimg.jp/thumbnails/38630030/38630030.61648809)XYX"sv, 9, web_links_song_329458, culture_codes_song_329458},
  {std::nullopt, song_artists_song_481543, R"XYX(Synthion feat. Hatsune Miku V4 (English))XYX"sv, 2023y/3/11, R"XYX(imaginary love story)XYX"sv, "English"sv, std::nullopt, 17, 481543, std::chrono::seconds(248), picture_song_481543, std::nullopt, std::nullopt, std::nullopt, R"XYX(imaginary love story)XYX"sv, names_song_481543, std::nullopt, 2023y/3/11, pvs_song_481543, "Youtube"sv, 121, "Original"sv, "Finished"sv, R"XYX(https://i.ytimg.com/vi/dmHeXH1YthI/default.jpg)XYX"sv, 10, web_links_song_481543, culture_codes_song_481543},
  {R"XYX(不適切淑女, Futekisetsu Shukujo, Improper Lady)XYX"sv, song_artists_song_183348, R"XYX(OSTER project feat. MEIKO V3 (Unknown))XYX"sv, 2018y/2/4, R"XYX(不適切淑女)XYX"sv, "Japanese"sv, std::nullopt, 10, 183348, std::chrono::seconds(254), picture_song_183348, std::nullopt, std::nullopt, std::nullopt, R"XYX(Inappropriate Lady)XYX"sv, names_song_183348, std::nullopt, 2018y/2/4, pvs_song_183348, "NicoNicoDouga, Youtube, Bilibili"sv, 74, "Original"sv, "Finished"sv, R"XYX(https://nicovideo.cdn.nimg.jp/thumbnails/32685535/32685535)XYX"sv, 20, web_links_song_183348, culture_codes_song_183348},
  {std::nullopt, song_artists_song_2443, R"XYX(kz feat. Hatsune Miku)XYX"sv, 2011y/11/4, R"XYX(Last Night, Good Night)XYX"sv, "English"sv, std::nullopt, 209, 2443, std::chrono::seconds(396), picture_song_2443, std::nullopt, std::nullopt, std::nullopt, R"XYX(Last Night, Good Night)XYX"sv, names_song_2443, std::nullopt, 2008y/7/31, pvs_song_2443, "NicoNicoDouga, Youtube, Vimeo"sv, 1007, "Original"sv, "Approved"sv, R"XYX(https://i.ytimg.com/vi/T6mMMYSqlM4/default.jpg)XYX"sv, 36, web_links_song_2443, culture_codes_song_2443},
  {R"XYX(ルカルカ★ナイトフィーバー)XYX"sv, song_artists_song_1435, R"XYX(samfree feat. Megurine Luka)XYX"sv, 2011y/11/1, R"XYX(ルカルカ★ナイトフィーバー)XYX"sv, "Japanese"sv, std::nullopt, 244, 1435, std::chrono::seconds(239), picture_song_1435, 160000, std::nullopt, 160000, R"XYX(Luka Luka★Night Fever)XYX"sv, names_song_1435, std::nullopt, 2009y/2/12, pvs_song_1435, "NicoNicoDouga, Youtube"sv, 1250, "Original"sv, "Approved"sv, R"XYX(https://nicovideo.cdn.nimg.jp/thumbnails/6119955/6119955)XYX"sv, 26, web_links_song_1435, culture_codes_song_1435},
  {R"XYX(NEPPUU〜熱風〜, NEPPUU ~Neppuu~, NEPPUU, HOT WIND)XYX"sv, song_artists_song_480845, R"XYX(MikitoP feat. Hatsune Miku V4X (Solid))XYX"sv, 2023y/3/7, R"XYX(NEPPUU〜熱風〜)XYX"sv, "Japanese"sv, std::nullopt, 16, 480845, std::chrono::seconds(276), picture_song_480845, std::nullopt, std::nullopt, std::nullopt, R"XYX(NEPPUU ~Blistering Wind~)XYX"sv, names_song_480845, std::nullopt, 2023y/3/7, pvs_song_480845, "NicoNicoDouga, Youtube, Bilibili"sv, 92, "Original"sv, "Finished"sv, R"XYX(https://i.ytimg.com/vi/DmACzPgHYjQ/default.jpg)XYX"sv, 17, web_links_song_480845, culture_codes_song_480845},
  {R"XYX(ラムネイドブルーの憧憬, Ramunade Blue no Shoukei)XYX"sv, song_artists_song_169614, R"XYX(Aoto Kei feat. MEIKO V3 (Power))XYX"sv, 2017y/10/7, R"XYX(ラムネイドブルーの憧憬)XYX"sv, "Japanese"sv, std::nullopt, 11, 169614, std::chrono::seconds(271), picture_song_169614, std::nullopt, std::nullopt, std::nullopt, R"XYX(Ramnade blue longing)XYX"sv, names_song_169614, std::nullopt, 2017y/10/7, pvs_song_169614, "NicoNicoDouga, Youtube"sv, 69, "Original"sv, "Finished"sv, R"XYX(https://nicovideo.cdn.nimg.jp/thumbnails/32056116/32056116)XYX"sv, 13, web_links_song_169614, culture_codes_song_169614},
  {R"XYX(Sharing The World)XYX"sv, song_artists_song_182370, R"XYX(BIGHEAD, Ankari, Maubox feat. Hatsune Miku)XYX"sv, 2018y/1/24, R"XYX(Sharing The World [ SPANISH VER ])XYX"sv, "English"sv, std::nullopt, 0, 182370, std::chrono::seconds(250), picture_song_182370, std::nullopt, std::nullopt, std::nullopt, R"XYX(Sharing The World [ SPANISH VER ])XYX"sv, names_song_182370, 66126, 2018y/1/24, pvs_song_182370, "Youtube"sv, 8, "Cover"sv, "Finished"sv, R"XYX(https://i.ytimg.com/vi/98a7GpD2qa0/default.jpg)XYX"sv, 11, web_links_song_182370, culture_codes_song_182370},
  {std::nullopt, song_artists_song_155305, R"XYX(keisei feat. Hatsune Miku)XYX"sv, 2017y/4/30, R"XYX(Singularity)XYX"sv, "English"sv, std::nullopt, 17, 155305, std::chrono::seconds(266), picture_song_155305, std::nullopt, std::nullopt, std::nullopt, R"XYX(Singularity)XYX"sv, names_song_155305, std::nullopt, 2017y/4/2, pvs_song_155305, "NicoNicoDouga, Youtube, SoundCloud, Piapro"sv, 123, "Original"sv, "Finished"sv, R"XYX(https://nicovideo.cdn.nimg.jp/thumbnails/31405153/31405153)XYX"sv, 16, web_links_song_155305, culture_codes_song_155305},
  {R"XYX(孤独の果て, Kodoku no Hate, Solitude's End, The End of Solitude, 고독의 끝)XYX"sv, song_artists_song_18083, R"XYX(Hikari Syuyo feat. Kagamine Rin)XYX"sv, 2012y/11/12, R"XYX(孤独の果て)XYX"sv, "Japanese"sv, std::nullopt, 78, 18083, std::chrono::seconds(263), picture_song_18083, std::nullopt, std::nullopt, std::nullopt, R"XYX(End of Solitude)XYX"sv, names_song_18083, std::nullopt, 2009y/8/9, pvs_song_18083, "NicoNicoDouga, Youtube"sv, 362, "Original"sv, "Finished"sv, R"XYX(https://nicovideo.cdn.nimg.jp/thumbnails/7882150/7882150)XYX"sv, 20, web_links_song_18083, culture_codes_song_18083},
  {R"XYX(サウンド, 사운드)XYX"sv, song_artists_song_1340, R"XYX(baker feat. Hatsune Miku)XYX"sv, 2011y/11/1, R"XYX(サウンド)XYX"sv, "Japanese"sv, std::nullopt, 54, 1340, std::chrono::seconds(188), picture_song_1340, 162000, std::nullopt, 162000, R"XYX(sound)XYX"sv, names_song_1340, 579521, 2007y/11/21, pvs_song_1340, "NicoNicoDouga, Youtube"sv, 264, "Remaster"sv, "Finished"sv, R"XYX(https://nicovideo.cdn.nimg.jp/thumbnails/1583280/1583280)XYX"sv, 24, web_links_song_1340, culture_codes_song_1340},
  {R"XYX(みかぼし, Mikaboshi)XYX"sv, song_artists_song_531972, R"XYX(3106。 feat. KAITO)XYX"sv, 2023y/9/27, R"XYX(みかぼし)XYX"sv, "Japanese"sv, std::nullopt, 4, 531972, std::chrono::seconds(238), picture_song_531972, std::nullopt, std::nullopt, std::nullopt, R"XYX(Star of Heaven)XYX"sv, names_song_531972, std::nullopt, 2013y/6/23, pvs_song_531972, "Youtube"sv, 12, "Original"sv, "Finished"sv, R"XYX(https://i.ytimg.com/vi/tITBe-xkaBQ/default.jpg)XYX"sv, 3, web_links_song_531972, culture_codes_song_531972},
  {R"XYX(ウミユリ海底譚, Umiyuri Kaitei Tan, Sea Lily Deep Sea Tale)XYX"sv, song_artists_song_49871, R"XYX(n-buna feat. Hatsune Miku V3 (Dark))XYX"sv, 2014y/2/24, R"XYX(ウミユリ海底譚)XYX"sv, "Japanese"sv, std::nullopt, 120, 49871, std::chrono::seconds(238), picture_song_49871, 240000, std::nullopt, 240000, R"XYX(Tale of the Deep-Sea Lily)XYX"sv, names_song_49871, std::nullopt, 2014y/2/24, pvs_song_49871, "NicoNicoDouga, Youtube, Piapro"sv, 561, "Original"sv, "Approved"sv, R"XYX(https://nicovideo.cdn.nimg.jp/thumbnails/22960446/22960446)XYX"sv, 29, web_links_song_49871, culture_codes_song_49871},
  {R"XYX(アンノウン・マザーグース, Unknown Mother Goose, 不为人知的鹅妈妈童谣)XYX"sv, song_artists_song_164107, R"XYX(wowaka, Hitorie feat. Hatsune Miku V4X (Dark))XYX"sv, 2017y/8/4, R"XYX(アンノウン・マザーグース)XYX"sv, "Japanese"sv, std::nullopt, 339, 164107, std::chrono::seconds(285), picture_song_164107, std::nullopt, std::nullopt, std::nullopt, R"XYX(Unknown Mother-Goose)XYX"sv, names_song_164107, std::nullopt, 2017y/8/22, pvs_song_164107, "NicoNicoDouga, Youtube"sv, 1486, "Original"sv, "Approved"sv, R"XYX(https://nicovideo.cdn.nimg.jp/thumbnails/31791630/31791630)XYX"sv, 30, web_links_song_164107, culture_codes_song_164107},
}};


} // namespace vocadb
