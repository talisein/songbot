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


/* Start Song 121116: Amazing Dolce */

constexpr std::array<additional_name, 1> names_song_121116 {{
  {"English"sv, R"XYX(Amazing Dolce)XYX"sv},
}};

constexpr std::array<web_link, 2> web_links_song_121116 {{
  {"Reference"sv, R"XYX(Vocaloid Wiki)XYX"sv, R"XYX(http://vocaloid.wikia.com/wiki/Amazing_Dolce)XYX"sv, 50953 },
  {"Other"sv, R"XYX(Youtube - Off Vocal)XYX"sv, R"XYX(https://www.youtube.com/watch?v=YqYEYo_fFMA)XYX"sv, 97772 },
}};


#if __has_embed("song_pic_orig_121116") == __STDC_EMBED_FOUND__
constexpr std::array song_pic_orig_121116 = std::to_array<std::uint8_t>({
    #embed "song_pic_orig_121116"
});
constexpr std::string_view song_mime_type_orig_121116 = "image/jpeg";
constexpr std::string_view song_file_ext_orig_121116 = "jpeg";
#else
constexpr std::array<std::uint8_t, 0> song_pic_orig_121116;
constexpr std::string_view song_mime_type_orig_121116 = "inode/x-empty";
constexpr std::string_view song_file_ext_orig_121116;
#endif

constexpr std::array<std::uint8_t, 0> song_pic_small_thumb_121116;
constexpr std::string_view song_mime_type_small_thumb_121116 = "inode/x-empty";
constexpr std::string_view song_file_ext_small_thumb_121116;


#if __has_embed("song_pic_thumb_121116") == __STDC_EMBED_FOUND__
constexpr std::array song_pic_thumb_121116 = std::to_array<std::uint8_t>({
    #embed "song_pic_thumb_121116"
});
constexpr std::string_view song_mime_type_thumb_121116 = "image/jpeg";
constexpr std::string_view song_file_ext_thumb_121116 = "jpeg";
#else
constexpr std::array<std::uint8_t, 0> song_pic_thumb_121116;
constexpr std::string_view song_mime_type_thumb_121116 = "inode/x-empty";
constexpr std::string_view song_file_ext_thumb_121116;
#endif

constexpr std::array<std::uint8_t, 0> song_pic_tiny_thumb_121116;
constexpr std::string_view song_mime_type_tiny_thumb_121116 = "inode/x-empty";
constexpr std::string_view song_file_ext_tiny_thumb_121116;

constexpr picture picture_song_121116 = { std::nullopt, std::nullopt, R"XYX(https://i1.ytimg.com/vi/lnPnSVcrJfg/hqdefault.jpg)XYX"sv, song_pic_orig_121116, song_mime_type_orig_121116, song_file_ext_orig_121116, std::nullopt, song_pic_small_thumb_121116, song_mime_type_small_thumb_121116, song_file_ext_small_thumb_121116, R"XYX(https://i.ytimg.com/vi/lnPnSVcrJfg/default.jpg)XYX"sv, song_pic_thumb_121116, song_mime_type_thumb_121116, song_file_ext_thumb_121116, std::nullopt, song_pic_tiny_thumb_121116, song_mime_type_tiny_thumb_121116, song_file_ext_tiny_thumb_121116  };

constexpr std::array<song_artists, 7> song_artists_song_121116 {{
  { artist_t{ R"XYX(ひとしずくP, さも, samo, samorira9, 히토시즈쿠P)XYX"sv, "Producer"sv, false, 103, R"XYX(HitoshizukuP)XYX"sv, R"XYX(image/jpeg)XYX"sv, std::nullopt, "Approved"sv, 29 }, "Producer"sv, "Default"sv, 278543, false, false, R"XYX(HitoshizukuP)XYX"sv, "Default"sv },
  { artist_t{ R"XYX(やま△, Yamasankakkei, Shoma, 야마△)XYX"sv, "Producer"sv, false, 499, R"XYX(yama△)XYX"sv, R"XYX(image/png)XYX"sv, std::nullopt, "Approved"sv, 22 }, "Producer"sv, "Default"sv, 278544, false, false, R"XYX(yama△)XYX"sv, "Default"sv },
  { artist_t{ R"XYX(メイコV3 (Power))XYX"sv, "Vocaloid"sv, false, 15948, R"XYX(MEIKO V3 (Power))XYX"sv, R"XYX(image/png)XYX"sv, 2014y/2/4, "Finished"sv, 15 }, "Vocalist"sv, "Default"sv, 278944, false, false, R"XYX(MEIKO V3 (Power))XYX"sv, "Default"sv },
  { artist_t{ R"XYX(鏡音リン Append (Power))XYX"sv, "Vocaloid"sv, false, 347, R"XYX(Kagamine Rin Append (Power))XYX"sv, R"XYX(image/png)XYX"sv, 2010y/12/27, "Approved"sv, 20 }, "Vocalist"sv, "Default"sv, 278945, false, false, R"XYX(Kagamine Rin Append (Power))XYX"sv, "Default"sv },
  { artist_t{ R"XYX(鏡音レン Append (Power))XYX"sv, "Vocaloid"sv, false, 350, R"XYX(Kagamine Len Append (Power))XYX"sv, R"XYX(image/png)XYX"sv, 2010y/12/27, "Approved"sv, 18 }, "Vocalist"sv, "Default"sv, 278946, false, false, R"XYX(Kagamine Len Append (Power))XYX"sv, "Default"sv },
  { artist_t{ R"XYX(鈴ノ助)XYX"sv, "Illustrator"sv, false, 2123, R"XYX(Suzunosuke)XYX"sv, R"XYX(image/jpeg)XYX"sv, std::nullopt, "Approved"sv, 12 }, "Illustrator"sv, "Illustrator"sv, 846530, false, false, R"XYX(Suzunosuke)XYX"sv, "Illustrator"sv },
  { artist_t{ R"XYX(とさお, Tosao, anarchylily)XYX"sv, "Animator"sv, false, 2124, R"XYX(TSO)XYX"sv, R"XYX(image/jpeg)XYX"sv, std::nullopt, "Finished"sv, 10 }, "Animator"sv, "Animator"sv, 846531, false, false, R"XYX(TSO)XYX"sv, "Animator"sv },
}};

constexpr std::array<std::string_view, 1> culture_codes_song_121116 {{
"ja"sv, }};

constexpr std::array<song_pv, 3> pvs_song_121116 {{
  { R"XYX(ひとしずく×やま△ （Hitoshizuku_Yamasankakkei）)XYX"sv, std::nullopt, false, R"XYX(std::nullopt)XYX"sv, 453932, 238, R"XYX(【MEIKO＆鏡音リン・レン】Amazing Dolce【オリジナル曲】)XYX"sv, 2021y/1/22, R"XYX(lnPnSVcrJfg)XYX"sv, "Youtube"sv, "Original"sv, R"XYX(https://i.ytimg.com/vi/lnPnSVcrJfg/default.jpg)XYX"sv, R"XYX(https://youtu.be/lnPnSVcrJfg)XYX"sv },
  { R"XYX(ひとしずくP)XYX"sv, std::nullopt, false, R"XYX(std::nullopt)XYX"sv, 453933, 237, R"XYX(【MEIKO＆鏡音リン・レン】Amazing Dolce【オリジナル曲】)XYX"sv, 2021y/1/22, R"XYX(sm38158162)XYX"sv, "NicoNicoDouga"sv, "Original"sv, R"XYX(https://nicovideo.cdn.nimg.jp/thumbnails/38158162/38158162.10942252)XYX"sv, R"XYX(http://www.nicovideo.jp/watch/sm38158162)XYX"sv },
  { R"XYX(Hitoshizuku and Yama - Topic)XYX"sv, std::nullopt, false, R"XYX(std::nullopt)XYX"sv, 1125968, 238, R"XYX(Amazing Dolce (feat. 鏡音リン & 鏡音レン & MEIKO))XYX"sv, 2020y/4/4, R"XYX(3hCbkkfzF88)XYX"sv, "Youtube"sv, "Original"sv, R"XYX(https://i.ytimg.com/vi/3hCbkkfzF88/default.jpg)XYX"sv, R"XYX(https://youtu.be/3hCbkkfzF88)XYX"sv },
}};

/* End Song 121116: Amazing Dolce */

/* Start Song 3015: Love-Colored Ward */

constexpr std::array<additional_name, 4> names_song_3015 {{
  {"Japanese"sv, R"XYX(恋色病棟)XYX"sv},
  {"English"sv, R"XYX(Love-Colored Ward)XYX"sv},
  {"Romaji"sv, R"XYX(Koi Iro Byoutou)XYX"sv},
  {"Unspecified"sv, R"XYX(Love Ward)XYX"sv},
}};

constexpr std::array<web_link, 6> web_links_song_3015 {{
  {"Reference"sv, R"XYX(Vocaloid Wiki)XYX"sv, R"XYX(https://vocaloid.fandom.com/wiki/恋色病棟_(Koi_Iro_Byoutou))XYX"sv, 15683 },
  {"Reference"sv, R"XYX(NicoNicoPedia)XYX"sv, R"XYX(http://dic.nicovideo.jp/v/sm7361534)XYX"sv, 15684 },
  {"Official"sv, R"XYX(FuwaFuwaCinnamon)XYX"sv, R"XYX(http://fuwafuwacinnamon.sakura.ne.jp/music/koiiro.html)XYX"sv, 15685 },
  {"Reference"sv, R"XYX(MikuWiki)XYX"sv, R"XYX(http://www5.atwiki.jp/hmiku/pages/5614.html)XYX"sv, 86502 },
  {"Reference"sv, R"XYX(Pixiv Encyclopedia)XYX"sv, R"XYX(https://dic.pixiv.net/a/恋色病棟)XYX"sv, 86504 },
  {"Reference"sv, R"XYX(Vocaloid Lyrics Wiki)XYX"sv, R"XYX(https://vocaloidlyrics.miraheze.org/wiki/恋色病棟_(Koi_Iro_Byoutou))XYX"sv, 86505 },
}};


#if __has_embed("song_pic_orig_3015") == __STDC_EMBED_FOUND__
constexpr std::array song_pic_orig_3015 = std::to_array<std::uint8_t>({
    #embed "song_pic_orig_3015"
});
constexpr std::string_view song_mime_type_orig_3015 = "image/jpeg";
constexpr std::string_view song_file_ext_orig_3015 = "jpeg";
#else
constexpr std::array<std::uint8_t, 0> song_pic_orig_3015;
constexpr std::string_view song_mime_type_orig_3015 = "inode/x-empty";
constexpr std::string_view song_file_ext_orig_3015;
#endif

constexpr std::array<std::uint8_t, 0> song_pic_small_thumb_3015;
constexpr std::string_view song_mime_type_small_thumb_3015 = "inode/x-empty";
constexpr std::string_view song_file_ext_small_thumb_3015;


#if __has_embed("song_pic_thumb_3015") == __STDC_EMBED_FOUND__
constexpr std::array song_pic_thumb_3015 = std::to_array<std::uint8_t>({
    #embed "song_pic_thumb_3015"
});
constexpr std::string_view song_mime_type_thumb_3015 = "image/jpeg";
constexpr std::string_view song_file_ext_thumb_3015 = "jpeg";
#else
constexpr std::array<std::uint8_t, 0> song_pic_thumb_3015;
constexpr std::string_view song_mime_type_thumb_3015 = "inode/x-empty";
constexpr std::string_view song_file_ext_thumb_3015;
#endif

constexpr std::array<std::uint8_t, 0> song_pic_tiny_thumb_3015;
constexpr std::string_view song_mime_type_tiny_thumb_3015 = "inode/x-empty";
constexpr std::string_view song_file_ext_tiny_thumb_3015;

constexpr picture picture_song_3015 = { std::nullopt, std::nullopt, R"XYX(https://i1.ytimg.com/vi/tPnIwDBk09k/hqdefault.jpg)XYX"sv, song_pic_orig_3015, song_mime_type_orig_3015, song_file_ext_orig_3015, std::nullopt, song_pic_small_thumb_3015, song_mime_type_small_thumb_3015, song_file_ext_small_thumb_3015, R"XYX(https://nicovideo.cdn.nimg.jp/thumbnails/7361534/7361534)XYX"sv, song_pic_thumb_3015, song_mime_type_thumb_3015, song_file_ext_thumb_3015, std::nullopt, song_pic_tiny_thumb_3015, song_mime_type_tiny_thumb_3015, song_file_ext_tiny_thumb_3015  };

constexpr std::array<song_artists, 3> song_artists_song_3015 {{
  { artist_t{ R"XYX(初音ミク, 初音未来, Chūyīn Wèilái, 하츠네 미쿠, 初音未來)XYX"sv, "Vocaloid"sv, false, 1, R"XYX(Hatsune Miku)XYX"sv, R"XYX(image/png)XYX"sv, 2007y/8/31, "Locked"sv, 39 }, "Vocalist"sv, "Default"sv, 5336, false, false, R"XYX(Hatsune Miku)XYX"sv, "Default"sv },
  { artist_t{ R"XYX(不破志奈, ふわしな, fuwacina , テスロ, TESRO, ロゼット, ROSET, ふわふわシナモン, Fuwafuwa Cinnamon, ふたなりP, FutanariP, FTNR-P)XYX"sv, "Producer"sv, false, 58, R"XYX(OSTER project)XYX"sv, R"XYX(image/jpeg)XYX"sv, std::nullopt, "Approved"sv, 40 }, "Producer"sv, "Default"sv, 5337, false, false, R"XYX(OSTER project)XYX"sv, "Default"sv },
  { artist_t{ R"XYX(Yおじ, Yおじちゃん, Y Oji-chan, Yおじさん, Y Oji-san)XYX"sv, "Illustrator"sv, false, 9810, R"XYX(Y Oji)XYX"sv, R"XYX(image/jpeg)XYX"sv, std::nullopt, "Finished"sv, 10 }, "Illustrator"sv, "Illustrator"sv, 91675, false, false, R"XYX(Y Oji)XYX"sv, "Default"sv },
}};

constexpr std::array<std::string_view, 1> culture_codes_song_3015 {{
"ja"sv, }};

constexpr std::array<song_pv, 5> pvs_song_3015 {{
  { R"XYX(ふわふわシナモン)XYX"sv, std::nullopt, false, R"XYX(std::nullopt)XYX"sv, 107558, 246, R"XYX(【初音ミク】恋色病棟【オリジナル曲】)XYX"sv, 2009y/6/16, R"XYX(sm7361534)XYX"sv, "NicoNicoDouga"sv, "Original"sv, R"XYX(https://nicovideo.cdn.nimg.jp/thumbnails/7361534/7361534)XYX"sv, R"XYX(http://www.nicovideo.jp/watch/sm7361534)XYX"sv },
  { R"XYX(descentsubs @Vocaloid)XYX"sv, std::nullopt, false, R"XYX(std::nullopt)XYX"sv, 353095, 247, R"XYX(OSTERProject ft. 初音ミク - Love-Colored Ward 恋色病棟 (English Subtitles))XYX"sv, 2014y/12/30, R"XYX(xxbhLY5jn_I)XYX"sv, "Youtube"sv, "Other"sv, R"XYX(https://i.ytimg.com/vi/xxbhLY5jn_I/default.jpg)XYX"sv, R"XYX(https://youtu.be/xxbhLY5jn_I)XYX"sv },
  { R"XYX(OSTER projectテスロ&ロゼット)XYX"sv, std::nullopt, false, R"XYX(std::nullopt)XYX"sv, 438117, 247, R"XYX(【official MV】恋色病棟 feat. 初音ミク)XYX"sv, 2020y/11/15, R"XYX(tPnIwDBk09k)XYX"sv, "Youtube"sv, "Original"sv, R"XYX(https://i.ytimg.com/vi/tPnIwDBk09k/default.jpg)XYX"sv, R"XYX(https://youtu.be/tPnIwDBk09k)XYX"sv },
  { R"XYX(ふわふわシナモン)XYX"sv, std::nullopt, false, R"XYX({"Timestamp":"20090616191121"})XYX"sv, 458244, 246, R"XYX(恋色病棟)XYX"sv, 2009y/6/16, R"XYX(v05ztwtbfytkdgjg)XYX"sv, "Piapro"sv, "Original"sv, std::nullopt, R"XYX(http://piapro.jp/content/v05ztwtbfytkdgjg)XYX"sv },
  { R"XYX(reddevils500a)XYX"sv, std::nullopt, false, R"XYX(std::nullopt)XYX"sv, 1187688, 247, R"XYX(【Miku Hatsune PV】 Love Ward 【VOCALOID Original Song】)XYX"sv, 2009y/6/18, R"XYX(oPXottYqzvw)XYX"sv, "Youtube"sv, "Reprint"sv, R"XYX(https://i.ytimg.com/vi/oPXottYqzvw/default.jpg)XYX"sv, R"XYX(https://youtu.be/oPXottYqzvw)XYX"sv },
}};

/* End Song 3015: Love-Colored Ward */

/* Start Song 256585: MikuFiesta */

constexpr std::array<additional_name, 1> names_song_256585 {{
  {"English"sv, R"XYX(MikuFiesta)XYX"sv},
}};

constexpr std::array<web_link, 0> web_links_song_256585 {{
}};


#if __has_embed("song_pic_orig_256585") == __STDC_EMBED_FOUND__
constexpr std::array song_pic_orig_256585 = std::to_array<std::uint8_t>({
    #embed "song_pic_orig_256585"
});
constexpr std::string_view song_mime_type_orig_256585 = "image/jpeg";
constexpr std::string_view song_file_ext_orig_256585 = "jpeg";
#else
constexpr std::array<std::uint8_t, 0> song_pic_orig_256585;
constexpr std::string_view song_mime_type_orig_256585 = "inode/x-empty";
constexpr std::string_view song_file_ext_orig_256585;
#endif

constexpr std::array<std::uint8_t, 0> song_pic_small_thumb_256585;
constexpr std::string_view song_mime_type_small_thumb_256585 = "inode/x-empty";
constexpr std::string_view song_file_ext_small_thumb_256585;


#if __has_embed("song_pic_thumb_256585") == __STDC_EMBED_FOUND__
constexpr std::array song_pic_thumb_256585 = std::to_array<std::uint8_t>({
    #embed "song_pic_thumb_256585"
});
constexpr std::string_view song_mime_type_thumb_256585 = "image/jpeg";
constexpr std::string_view song_file_ext_thumb_256585 = "jpeg";
#else
constexpr std::array<std::uint8_t, 0> song_pic_thumb_256585;
constexpr std::string_view song_mime_type_thumb_256585 = "inode/x-empty";
constexpr std::string_view song_file_ext_thumb_256585;
#endif

constexpr std::array<std::uint8_t, 0> song_pic_tiny_thumb_256585;
constexpr std::string_view song_mime_type_tiny_thumb_256585 = "inode/x-empty";
constexpr std::string_view song_file_ext_tiny_thumb_256585;

constexpr picture picture_song_256585 = { std::nullopt, std::nullopt, R"XYX(https://i1.ytimg.com/vi/TMdHGvrwyJc/hqdefault.jpg)XYX"sv, song_pic_orig_256585, song_mime_type_orig_256585, song_file_ext_orig_256585, std::nullopt, song_pic_small_thumb_256585, song_mime_type_small_thumb_256585, song_file_ext_small_thumb_256585, R"XYX(https://i.ytimg.com/vi/TMdHGvrwyJc/default.jpg)XYX"sv, song_pic_thumb_256585, song_mime_type_thumb_256585, song_file_ext_thumb_256585, std::nullopt, song_pic_tiny_thumb_256585, song_mime_type_tiny_thumb_256585, song_file_ext_tiny_thumb_256585  };

constexpr std::array<song_artists, 5> song_artists_song_256585 {{
  { artist_t{ R"XYX(Alexander Contreras, Divas En Salsa, AlexTripSands)XYX"sv, "Producer"sv, false, 15362, R"XYX(AlexTrip Sands)XYX"sv, R"XYX(image/jpeg)XYX"sv, std::nullopt, "Finished"sv, 33 }, "Producer"sv, "Default"sv, 678427, false, false, R"XYX(AlexTrip Sands)XYX"sv, "Default"sv },
  { artist_t{ R"XYX(初音ミク, 初音未来, Chūyīn Wèilái, 하츠네 미쿠, 初音未來)XYX"sv, "Vocaloid"sv, false, 1, R"XYX(Hatsune Miku)XYX"sv, R"XYX(image/png)XYX"sv, 2007y/8/31, "Locked"sv, 39 }, "Vocalist"sv, "Default"sv, 683864, false, false, R"XYX(Hatsune Miku)XYX"sv, "Default"sv },
  { artist_t{ R"XYX(Pimi, Pimichis, Pimichi)XYX"sv, "Illustrator"sv, false, 60294, R"XYX(Pimienta Kast)XYX"sv, R"XYX(image/jpeg)XYX"sv, std::nullopt, "Finished"sv, 7 }, "Illustrator"sv, "Illustrator"sv, 746571, false, false, R"XYX(Pimienta Kast)XYX"sv, "Default"sv },
  { artist_t{ R"XYX(初音ミク V4 (English), 初音ミク V4X (English), Hatsune Miku V4X (English))XYX"sv, "Vocaloid"sv, false, 49724, R"XYX(Hatsune Miku V4 (English))XYX"sv, R"XYX(image/png)XYX"sv, 2016y/8/31, "Finished"sv, 27 }, "Vocalist"sv, "Default"sv, 790606, false, true, R"XYX(Hatsune Miku V4 (English))XYX"sv, "Default"sv },
  { artist_t{ R"XYX(クリプトン・フューチャー・メディア, CFM, クリプトン・フューチャー・メディア（株）, Crypton Future Media, Inc., SONICWIRE)XYX"sv, "Label"sv, false, 25, R"XYX(Crypton Future Media)XYX"sv, R"XYX(image/gif)XYX"sv, std::nullopt, "Locked"sv, 28 }, "Label"sv, "Default"sv, 1962716, false, false, R"XYX(Crypton Future Media)XYX"sv, "Default"sv },
}};

constexpr std::array<std::string_view, 1> culture_codes_song_256585 {{
"es"sv, }};

constexpr std::array<song_pv, 3> pvs_song_256585 {{
  { R"XYX(HatsuneMiku)XYX"sv, std::nullopt, false, R"XYX(std::nullopt)XYX"sv, 373508, 256, R"XYX(【初音ミク】MikuFiesta by AlexTrip Sands MIKU EXPO 5th Anniv. Grand Prize【Hatsune Miku】)XYX"sv, 2019y/11/19, R"XYX(TMdHGvrwyJc)XYX"sv, "Youtube"sv, "Original"sv, R"XYX(https://i.ytimg.com/vi/TMdHGvrwyJc/default.jpg)XYX"sv, R"XYX(https://youtu.be/TMdHGvrwyJc)XYX"sv },
  { R"XYX(Divas en Salsa)XYX"sv, std::nullopt, true, R"XYX(std::nullopt)XYX"sv, 745143, 244, R"XYX(AlexTrip Sands Ft. Hatsune Miku - MikuFiesta [MIKU EXPO 5th Anniversary Song Contest Grand Prize])XYX"sv, 2019y/10/11, R"XYX(694072993 divasensalsa/mikufiesta)XYX"sv, "SoundCloud"sv, "Original"sv, R"XYX(https://i1.sndcdn.com/artworks-000610805809-38bn1f-large.jpg)XYX"sv, R"XYX(http://soundcloud.com/divasensalsa/mikufiesta)XYX"sv },
  { R"XYX(AlexTrip Sands - Topic)XYX"sv, std::nullopt, false, R"XYX(std::nullopt)XYX"sv, 935344, 247, R"XYX(MikuFiesta (feat. 初音ミク))XYX"sv, 2024y/4/16, R"XYX(yIPT7lIgr1s)XYX"sv, "Youtube"sv, "Original"sv, R"XYX(https://i.ytimg.com/vi/yIPT7lIgr1s/default.jpg)XYX"sv, R"XYX(https://youtu.be/yIPT7lIgr1s)XYX"sv },
}};

/* End Song 256585: MikuFiesta */

/* Start Song 772578: Over Flow(er) */

constexpr std::array<additional_name, 1> names_song_772578 {{
  {"English"sv, R"XYX(Over Flow(er))XYX"sv},
}};

constexpr std::array<web_link, 2> web_links_song_772578 {{
  {"Reference"sv, R"XYX(VocaDB / Concert event)XYX"sv, R"XYX(https://vocadb.net/Es/799/hatsune-miku-japan-tour-2025-b)XYX"sv, 170615 },
  {"Reference"sv, R"XYX(Vocaloid Lyrics Wiki)XYX"sv, R"XYX(https://vocaloidlyrics.miraheze.org/wiki/Over_Flow(er))XYX"sv, 188793 },
}};


#if __has_embed("song_pic_orig_772578") == __STDC_EMBED_FOUND__
constexpr std::array song_pic_orig_772578 = std::to_array<std::uint8_t>({
    #embed "song_pic_orig_772578"
});
constexpr std::string_view song_mime_type_orig_772578 = "image/jpeg";
constexpr std::string_view song_file_ext_orig_772578 = "jpeg";
#else
constexpr std::array<std::uint8_t, 0> song_pic_orig_772578;
constexpr std::string_view song_mime_type_orig_772578 = "inode/x-empty";
constexpr std::string_view song_file_ext_orig_772578;
#endif

constexpr std::array<std::uint8_t, 0> song_pic_small_thumb_772578;
constexpr std::string_view song_mime_type_small_thumb_772578 = "inode/x-empty";
constexpr std::string_view song_file_ext_small_thumb_772578;


#if __has_embed("song_pic_thumb_772578") == __STDC_EMBED_FOUND__
constexpr std::array song_pic_thumb_772578 = std::to_array<std::uint8_t>({
    #embed "song_pic_thumb_772578"
});
constexpr std::string_view song_mime_type_thumb_772578 = "image/jpeg";
constexpr std::string_view song_file_ext_thumb_772578 = "jpeg";
#else
constexpr std::array<std::uint8_t, 0> song_pic_thumb_772578;
constexpr std::string_view song_mime_type_thumb_772578 = "inode/x-empty";
constexpr std::string_view song_file_ext_thumb_772578;
#endif

constexpr std::array<std::uint8_t, 0> song_pic_tiny_thumb_772578;
constexpr std::string_view song_mime_type_tiny_thumb_772578 = "inode/x-empty";
constexpr std::string_view song_file_ext_tiny_thumb_772578;

constexpr picture picture_song_772578 = { std::nullopt, std::nullopt, R"XYX(https://i1.ytimg.com/vi/gJHaCNYjYjM/hqdefault.jpg)XYX"sv, song_pic_orig_772578, song_mime_type_orig_772578, song_file_ext_orig_772578, std::nullopt, song_pic_small_thumb_772578, song_mime_type_small_thumb_772578, song_file_ext_small_thumb_772578, R"XYX(https://i.ytimg.com/vi/gJHaCNYjYjM/default.jpg)XYX"sv, song_pic_thumb_772578, song_mime_type_thumb_772578, song_file_ext_thumb_772578, std::nullopt, song_pic_tiny_thumb_772578, song_mime_type_tiny_thumb_772578, song_file_ext_tiny_thumb_772578  };

constexpr std::array<song_artists, 4> song_artists_song_772578 {{
  { artist_t{ R"XYX(cosaji)XYX"sv, "Producer"sv, false, 61928, R"XYX(Noz.)XYX"sv, R"XYX(image/jpeg)XYX"sv, std::nullopt, "Finished"sv, 8 }, "Producer"sv, "Default"sv, 2195799, false, false, R"XYX(Noz.)XYX"sv, "Default"sv },
  { artist_t{ R"XYX(初音ミク, 初音未来, Chūyīn Wèilái, 하츠네 미쿠, 初音未來)XYX"sv, "Vocaloid"sv, false, 1, R"XYX(Hatsune Miku)XYX"sv, R"XYX(image/png)XYX"sv, 2007y/8/31, "Locked"sv, 39 }, "Vocalist"sv, "Default"sv, 2195800, false, false, R"XYX(Hatsune Miku)XYX"sv, "Default"sv },
  { artist_t{ R"XYX(クリプトン・フューチャー・メディア, CFM, クリプトン・フューチャー・メディア（株）, Crypton Future Media, Inc., SONICWIRE)XYX"sv, "Label"sv, false, 25, R"XYX(Crypton Future Media)XYX"sv, R"XYX(image/gif)XYX"sv, std::nullopt, "Locked"sv, 28 }, "Label"sv, "Default"sv, 2195831, false, false, R"XYX(Crypton Future Media)XYX"sv, "Default"sv },
  { artist_t{ R"XYX(コバヤシケイ)XYX"sv, "Animator"sv, false, 115674, R"XYX(Kobayashi Kei)XYX"sv, R"XYX(image/jpeg)XYX"sv, std::nullopt, "Finished"sv, 3 }, "Animator"sv, "Animator"sv, 2196047, false, false, R"XYX(Kobayashi Kei)XYX"sv, "Animator"sv },
}};

constexpr std::array<std::string_view, 1> culture_codes_song_772578 {{
"ja"sv, }};

constexpr std::array<song_pv, 4> pvs_song_772578 {{
  { R"XYX(Hatsune Miku)XYX"sv, std::nullopt, false, R"XYX(std::nullopt)XYX"sv, 1166984, 244, R"XYX(Over Flow(er) / Noz. feat. 初音ミク)XYX"sv, 2025y/4/4, R"XYX(gJHaCNYjYjM)XYX"sv, "Youtube"sv, "Original"sv, R"XYX(https://i.ytimg.com/vi/gJHaCNYjYjM/default.jpg)XYX"sv, R"XYX(https://youtu.be/gJHaCNYjYjM)XYX"sv },
  { std::nullopt, std::nullopt, false, R"XYX(std::nullopt)XYX"sv, 1167002, 243, R"XYX(Over Flow(er) / Noz. feat. 初音ミク)XYX"sv, 2025y/4/4, R"XYX(so44827731)XYX"sv, "NicoNicoDouga"sv, "Original"sv, R"XYX(https://nicovideo.cdn.nimg.jp/thumbnails/44827731/44827731.62157510)XYX"sv, R"XYX(http://www.nicovideo.jp/watch/so44827731)XYX"sv },
  { R"XYX(初音未来_Crypton)XYX"sv, std::nullopt, false, R"XYX({"Aid":114272688409405,"Bvid":"BV18hZ1YaEwz","Cid":29211690004})XYX"sv, 1180204, 244, R"XYX(Over Flow(er) / Noz. feat. 初音未来)XYX"sv, 2025y/4/5, R"XYX(114272688409405)XYX"sv, "Bilibili"sv, "Original"sv, R"XYX(http://i1.hdslb.com/bfs/archive/6d1a3a96c197e2228cd987e47ba3508b46025a35.jpg)XYX"sv, R"XYX(https://www.bilibili.com/video/av114272688409405)XYX"sv },
  { R"XYX(Noz. - Topic)XYX"sv, std::nullopt, false, R"XYX(std::nullopt)XYX"sv, 1180205, 245, R"XYX(Over Flow (er) (feat. 初音ミク))XYX"sv, 2025y/4/3, R"XYX(P2jq75-tgok)XYX"sv, "Youtube"sv, "Original"sv, R"XYX(https://i.ytimg.com/vi/P2jq75-tgok/default.jpg)XYX"sv, R"XYX(https://youtu.be/P2jq75-tgok)XYX"sv },
}};

/* End Song 772578: Over Flow(er) */

export constexpr std::array<song, 4> songs {{
  {std::nullopt, song_artists_song_121116, R"XYX(HitoshizukuP, yama△ feat. various)XYX"sv, 2016y/3/24, R"XYX(Amazing Dolce)XYX"sv, "English"sv, std::nullopt, 34, 121116, std::chrono::seconds(239), picture_song_121116, 156000, std::nullopt, 90000, R"XYX(Amazing Dolce)XYX"sv, names_song_121116, std::nullopt, 2016y/12/31, pvs_song_121116, "NicoNicoDouga, Youtube"sv, 240, "Original"sv, "Finished"sv, R"XYX(https://i.ytimg.com/vi/lnPnSVcrJfg/default.jpg)XYX"sv, 19, web_links_song_121116, culture_codes_song_121116},
  {R"XYX(恋色病棟, Koi Iro Byoutou, Love Ward)XYX"sv, song_artists_song_3015, R"XYX(OSTER project feat. Hatsune Miku)XYX"sv, 2011y/11/7, R"XYX(恋色病棟)XYX"sv, "Japanese"sv, std::nullopt, 102, 3015, std::chrono::seconds(247), picture_song_3015, 172000, std::nullopt, 172000, R"XYX(Love-Colored Ward)XYX"sv, names_song_3015, std::nullopt, 2009y/6/16, pvs_song_3015, "NicoNicoDouga, Youtube, Piapro"sv, 516, "Original"sv, "Finished"sv, R"XYX(https://nicovideo.cdn.nimg.jp/thumbnails/7361534/7361534)XYX"sv, 24, web_links_song_3015, culture_codes_song_3015},
  {std::nullopt, song_artists_song_256585, R"XYX(AlexTrip Sands feat. Hatsune Miku)XYX"sv, 2019y/10/11, R"XYX(MikuFiesta)XYX"sv, "English"sv, std::nullopt, 39, 256585, std::chrono::seconds(244), picture_song_256585, std::nullopt, std::nullopt, std::nullopt, R"XYX(MikuFiesta)XYX"sv, names_song_256585, std::nullopt, 2019y/10/11, pvs_song_256585, "Youtube"sv, 193, "Original"sv, "Finished"sv, R"XYX(https://i.ytimg.com/vi/TMdHGvrwyJc/default.jpg)XYX"sv, 15, web_links_song_256585, culture_codes_song_256585},
  {std::nullopt, song_artists_song_772578, R"XYX(Noz. feat. Hatsune Miku)XYX"sv, 2025y/4/4, R"XYX(Over Flow(er))XYX"sv, "English"sv, std::nullopt, 13, 772578, std::chrono::seconds(245), picture_song_772578, std::nullopt, std::nullopt, std::nullopt, R"XYX(Over Flow(er))XYX"sv, names_song_772578, std::nullopt, 2025y/4/4, pvs_song_772578, "NicoNicoDouga, Youtube, Bilibili"sv, 85, "Original"sv, "Finished"sv, R"XYX(https://i.ytimg.com/vi/gJHaCNYjYjM/default.jpg)XYX"sv, 12, web_links_song_772578, culture_codes_song_772578},
}};


} // namespace vocadb
