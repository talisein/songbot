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

export module vocadb.events;

import std;
import vocadb.api;

namespace vocadb {

using namespace std::literals;


constexpr std::array<additional_name, 3> names_release_event_2522 {{
  {"Japanese"sv, R"XYX(ミクFES'09（夏）)XYX"sv},
  {"Romaji"sv, R"XYX(Miku FES'09 (Natsu))XYX"sv},
  {"English"sv, R"XYX(Miku FES'09 (Summer))XYX"sv},
}};

constexpr std::array<web_link, 9> web_links_release_event_2522 {{
  {"Reference"sv, R"XYX(NicoNicoPedia)XYX"sv, R"XYX(https://dic.nicovideo.jp/a/%E3%83%9F%E3%82%AFfes%2709%28%E5%A4%8F%29)XYX"sv, 949 },
  {"Other"sv, R"XYX(HATSUNE MIKU OFFICIAL BLOG)XYX"sv, R"XYX(https://blog.piapro.net/2009/09/fes09.html)XYX"sv, 950 },
  {"Other"sv, R"XYX(Hatsune Miku LIVE Wiki)XYX"sv, R"XYX(https://www46.atwiki.jp/mikulive/pages/24.html)XYX"sv, 951 },
  {"Reference"sv, R"XYX(Vocaloid Wiki)XYX"sv, R"XYX(https://vocaloid.fandom.com/wiki/Miku_FES%2709_(Natsu))XYX"sv, 952 },
  {"Other"sv, R"XYX(ASCII.jp)XYX"sv, R"XYX(https://ascii.jp/elem/000/000/456/456009/)XYX"sv, 6547 },
  {"Other"sv, R"XYX(Website)XYX"sv, R"XYX(http://mikufes.jp/)XYX"sv, 6548 },
  {"Other"sv, R"XYX(NicoNicoLive)XYX"sv, R"XYX(http://www.nicovideo.jp/static/weblive/mikufes09/)XYX"sv, 6549 },
  {"Other"sv, R"XYX(Streaming+)XYX"sv, R"XYX(http://eplus.jp/miku-web)XYX"sv, 6550 },
  {"Other"sv, R"XYX(BARKS)XYX"sv, R"XYX(https://www.barks.jp/news/?id=1000051890)XYX"sv, 6551 },
}};


#if __has_embed("release_event_pic_orig_2522") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_orig_2522 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_orig_2522"
});
constexpr std::string_view release_event_mime_type_orig_2522 = "image/jpeg";
constexpr std::string_view release_event_file_ext_orig_2522 = "jpeg";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_orig_2522;
constexpr std::string_view release_event_mime_type_orig_2522 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_orig_2522;
#endif


#if __has_embed("release_event_pic_small_thumb_2522") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_small_thumb_2522 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_small_thumb_2522"
});
constexpr std::string_view release_event_mime_type_small_thumb_2522 = "image/png";
constexpr std::string_view release_event_file_ext_small_thumb_2522 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_small_thumb_2522;
constexpr std::string_view release_event_mime_type_small_thumb_2522 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_small_thumb_2522;
#endif


#if __has_embed("release_event_pic_thumb_2522") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_thumb_2522 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_thumb_2522"
});
constexpr std::string_view release_event_mime_type_thumb_2522 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_2522 = "???";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_thumb_2522;
constexpr std::string_view release_event_mime_type_thumb_2522 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_2522;
#endif


#if __has_embed("release_event_pic_tiny_thumb_2522") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_tiny_thumb_2522 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_tiny_thumb_2522"
});
constexpr std::string_view release_event_mime_type_tiny_thumb_2522 = "image/png";
constexpr std::string_view release_event_file_ext_tiny_thumb_2522 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_tiny_thumb_2522;
constexpr std::string_view release_event_mime_type_tiny_thumb_2522 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_tiny_thumb_2522;
#endif

constexpr picture picture_release_event_2522 = { R"XYX(image/jpeg)XYX"sv, std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/2522.jpg?v=8)XYX"sv, release_event_pic_orig_2522, release_event_mime_type_orig_2522, release_event_file_ext_orig_2522, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/2522.jpg?v=8)XYX"sv, release_event_pic_small_thumb_2522, release_event_mime_type_small_thumb_2522, release_event_file_ext_small_thumb_2522, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/2522.jpg?v=8)XYX"sv, release_event_pic_thumb_2522, release_event_mime_type_thumb_2522, release_event_file_ext_thumb_2522, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/2522.jpg?v=8)XYX"sv, release_event_pic_tiny_thumb_2522, release_event_mime_type_tiny_thumb_2522, release_event_file_ext_tiny_thumb_2522  };

constexpr std::array<additional_name, 2> names_release_event_2520 {{
  {"Japanese"sv, R"XYX(ミクの日感謝祭39's Giving Day)XYX"sv},
  {"Romaji"sv, R"XYX(Miku no Hi Kanshasai 39's Giving Day)XYX"sv},
}};

constexpr std::array<web_link, 3> web_links_release_event_2520 {{
  {"Other"sv, R"XYX(Official website)XYX"sv, R"XYX(http://miku.sega.jp/39/mikufes.html)XYX"sv, 948 },
  {"Reference"sv, R"XYX(NicoNicoPedia)XYX"sv, R"XYX(https://dic.nicovideo.jp/a/%E3%83%9F%E3%82%AF%E3%81%AE%E6%97%A5%E6%84%9F%E8%AC%9D%E7%A5%AD)XYX"sv, 1292 },
  {"Reference"sv, R"XYX(Vocaloid Wiki)XYX"sv, R"XYX(https://vocaloid.fandom.com/wiki/Miku_no_Hi_Kanshasai_39%27s_Giving_Day)XYX"sv, 1293 },
}};


#if __has_embed("release_event_pic_orig_2520") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_orig_2520 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_orig_2520"
});
constexpr std::string_view release_event_mime_type_orig_2520 = "image/gif";
constexpr std::string_view release_event_file_ext_orig_2520 = "gif";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_orig_2520;
constexpr std::string_view release_event_mime_type_orig_2520 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_orig_2520;
#endif


#if __has_embed("release_event_pic_small_thumb_2520") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_small_thumb_2520 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_small_thumb_2520"
});
constexpr std::string_view release_event_mime_type_small_thumb_2520 = "image/png";
constexpr std::string_view release_event_file_ext_small_thumb_2520 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_small_thumb_2520;
constexpr std::string_view release_event_mime_type_small_thumb_2520 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_small_thumb_2520;
#endif


#if __has_embed("release_event_pic_thumb_2520") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_thumb_2520 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_thumb_2520"
});
constexpr std::string_view release_event_mime_type_thumb_2520 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_2520 = "???";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_thumb_2520;
constexpr std::string_view release_event_mime_type_thumb_2520 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_2520;
#endif


#if __has_embed("release_event_pic_tiny_thumb_2520") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_tiny_thumb_2520 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_tiny_thumb_2520"
});
constexpr std::string_view release_event_mime_type_tiny_thumb_2520 = "image/png";
constexpr std::string_view release_event_file_ext_tiny_thumb_2520 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_tiny_thumb_2520;
constexpr std::string_view release_event_mime_type_tiny_thumb_2520 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_tiny_thumb_2520;
#endif

constexpr picture picture_release_event_2520 = { R"XYX(image/gif)XYX"sv, std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/2520.gif?v=8)XYX"sv, release_event_pic_orig_2520, release_event_mime_type_orig_2520, release_event_file_ext_orig_2520, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/2520.gif?v=8)XYX"sv, release_event_pic_small_thumb_2520, release_event_mime_type_small_thumb_2520, release_event_file_ext_small_thumb_2520, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/2520.gif?v=8)XYX"sv, release_event_pic_thumb_2520, release_event_mime_type_thumb_2520, release_event_file_ext_thumb_2520, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/2520.gif?v=8)XYX"sv, release_event_pic_tiny_thumb_2520, release_event_mime_type_tiny_thumb_2520, release_event_file_ext_tiny_thumb_2520  };

constexpr std::array<additional_name, 4> names_release_event_2523 {{
  {"English"sv, R"XYX(Hatsune Miku Live Party 2011 Tokyo)XYX"sv},
  {"Unspecified"sv, R"XYX(ミクパ 2011 Tokyo)XYX"sv},
  {"Japanese"sv, R"XYX(初音ミクライブパーティー 2011 Tokyo)XYX"sv},
  {"Unspecified"sv, R"XYX(MikuPa 2011 Tokyo)XYX"sv},
}};

constexpr std::array<web_link, 4> web_links_release_event_2523 {{
  {"Reference"sv, R"XYX(Vocaloid Wiki (Mikupa 2011 Sapporo))XYX"sv, R"XYX(https://vocaloid.fandom.com/wiki/Hatsune_Miku_Live_Party_2011_(Mikupa)/Sapporo)XYX"sv, 2527 },
  {"Reference"sv, R"XYX(Vocaloid Wiki (Mikupa 2011 Singapore))XYX"sv, R"XYX(https://vocaloid.fandom.com/wiki/Hatsune_Miku_Live_Party_2011_(Mikupa)/Singapore)XYX"sv, 2528 },
  {"Reference"sv, R"XYX(Vocaloid Wiki (Mikupa 2011 Tokyo))XYX"sv, R"XYX(https://vocaloid.fandom.com/wiki/Hatsune_Miku_Live_Party_2011_(Mikupa)/Tokyo)XYX"sv, 2529 },
  {"Other"sv, R"XYX(Website)XYX"sv, R"XYX(http://5pb.jp/mikupa/index_tokyo.html)XYX"sv, 2530 },
}};


#if __has_embed("release_event_pic_orig_2523") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_orig_2523 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_orig_2523"
});
constexpr std::string_view release_event_mime_type_orig_2523 = "image/png";
constexpr std::string_view release_event_file_ext_orig_2523 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_orig_2523;
constexpr std::string_view release_event_mime_type_orig_2523 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_orig_2523;
#endif


#if __has_embed("release_event_pic_small_thumb_2523") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_small_thumb_2523 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_small_thumb_2523"
});
constexpr std::string_view release_event_mime_type_small_thumb_2523 = "image/png";
constexpr std::string_view release_event_file_ext_small_thumb_2523 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_small_thumb_2523;
constexpr std::string_view release_event_mime_type_small_thumb_2523 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_small_thumb_2523;
#endif


#if __has_embed("release_event_pic_thumb_2523") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_thumb_2523 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_thumb_2523"
});
constexpr std::string_view release_event_mime_type_thumb_2523 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_2523 = "???";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_thumb_2523;
constexpr std::string_view release_event_mime_type_thumb_2523 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_2523;
#endif


#if __has_embed("release_event_pic_tiny_thumb_2523") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_tiny_thumb_2523 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_tiny_thumb_2523"
});
constexpr std::string_view release_event_mime_type_tiny_thumb_2523 = "image/png";
constexpr std::string_view release_event_file_ext_tiny_thumb_2523 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_tiny_thumb_2523;
constexpr std::string_view release_event_mime_type_tiny_thumb_2523 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_tiny_thumb_2523;
#endif

constexpr picture picture_release_event_2523 = { R"XYX(image/png)XYX"sv, std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/2523.png?v=12)XYX"sv, release_event_pic_orig_2523, release_event_mime_type_orig_2523, release_event_file_ext_orig_2523, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/2523.png?v=12)XYX"sv, release_event_pic_small_thumb_2523, release_event_mime_type_small_thumb_2523, release_event_file_ext_small_thumb_2523, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/2523.png?v=12)XYX"sv, release_event_pic_thumb_2523, release_event_mime_type_thumb_2523, release_event_file_ext_thumb_2523, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/2523.png?v=12)XYX"sv, release_event_pic_tiny_thumb_2523, release_event_mime_type_tiny_thumb_2523, release_event_file_ext_tiny_thumb_2523  };

constexpr std::array<additional_name, 4> names_release_event_2521 {{
  {"Japanese"sv, R"XYX(MIKUNOPOLIS in LOS ANGELES “はじめまして、初音ミクです”)XYX"sv},
  {"English"sv, R"XYX(MIKUNOPOLIS in LOS ANGELES “Happy to meet you, I'm HATSUNE MIKU”)XYX"sv},
  {"Romaji"sv, R"XYX(MIKUNOPOLIS in LOS ANGELES "Hajimemashite, Hatsune Miku Desu")XYX"sv},
  {"Unspecified"sv, R"XYX(MIKUNOPOLIS in LOS ANGELES “Happy to meet you! I'm HATSUNE MIKU”)XYX"sv},
}};

constexpr std::array<web_link, 2> web_links_release_event_2521 {{
  {"Other"sv, R"XYX(Official website)XYX"sv, R"XYX(http://miku.sega.jp/39/mikula.html)XYX"sv, 947 },
  {"Reference"sv, R"XYX(Official Album)XYX"sv, R"XYX(https://vocadb.net/Al/5061)XYX"sv, 7512 },
}};


#if __has_embed("release_event_pic_orig_2521") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_orig_2521 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_orig_2521"
});
constexpr std::string_view release_event_mime_type_orig_2521 = "image/png";
constexpr std::string_view release_event_file_ext_orig_2521 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_orig_2521;
constexpr std::string_view release_event_mime_type_orig_2521 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_orig_2521;
#endif


#if __has_embed("release_event_pic_small_thumb_2521") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_small_thumb_2521 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_small_thumb_2521"
});
constexpr std::string_view release_event_mime_type_small_thumb_2521 = "image/png";
constexpr std::string_view release_event_file_ext_small_thumb_2521 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_small_thumb_2521;
constexpr std::string_view release_event_mime_type_small_thumb_2521 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_small_thumb_2521;
#endif


#if __has_embed("release_event_pic_thumb_2521") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_thumb_2521 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_thumb_2521"
});
constexpr std::string_view release_event_mime_type_thumb_2521 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_2521 = "???";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_thumb_2521;
constexpr std::string_view release_event_mime_type_thumb_2521 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_2521;
#endif


#if __has_embed("release_event_pic_tiny_thumb_2521") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_tiny_thumb_2521 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_tiny_thumb_2521"
});
constexpr std::string_view release_event_mime_type_tiny_thumb_2521 = "image/png";
constexpr std::string_view release_event_file_ext_tiny_thumb_2521 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_tiny_thumb_2521;
constexpr std::string_view release_event_mime_type_tiny_thumb_2521 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_tiny_thumb_2521;
#endif

constexpr picture picture_release_event_2521 = { R"XYX(image/png)XYX"sv, std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/2521.png?v=6)XYX"sv, release_event_pic_orig_2521, release_event_mime_type_orig_2521, release_event_file_ext_orig_2521, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/2521.png?v=6)XYX"sv, release_event_pic_small_thumb_2521, release_event_mime_type_small_thumb_2521, release_event_file_ext_small_thumb_2521, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/2521.png?v=6)XYX"sv, release_event_pic_thumb_2521, release_event_mime_type_thumb_2521, release_event_file_ext_thumb_2521, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/2521.png?v=6)XYX"sv, release_event_pic_tiny_thumb_2521, release_event_mime_type_tiny_thumb_2521, release_event_file_ext_tiny_thumb_2521  };

constexpr std::array<additional_name, 4> names_release_event_2526 {{
  {"English"sv, R"XYX(Hatsune Miku Live Party 2011 Sapporo)XYX"sv},
  {"Unspecified"sv, R"XYX(ミクパ 2011 Sapporo)XYX"sv},
  {"Japanese"sv, R"XYX(初音ミクライブパーティー 2011 Sapporo)XYX"sv},
  {"Unspecified"sv, R"XYX(MikuPa 2011 Sapporo)XYX"sv},
}};

constexpr std::array<web_link, 4> web_links_release_event_2526 {{
  {"Other"sv, R"XYX(Website)XYX"sv, R"XYX(http://5pb.jp/mikupa/index_sapporo.html)XYX"sv, 964 },
  {"Reference"sv, R"XYX(Vocaloid Wiki (Mikupa 2011 Sapporo))XYX"sv, R"XYX(https://vocaloid.fandom.com/wiki/Hatsune_Miku_Live_Party_2011_(Mikupa)/Sapporo)XYX"sv, 2531 },
  {"Reference"sv, R"XYX(Vocaloid Wiki (Mikupa 2011 Singapore))XYX"sv, R"XYX(https://vocaloid.fandom.com/wiki/Hatsune_Miku_Live_Party_2011_(Mikupa)/Singapore)XYX"sv, 2532 },
  {"Reference"sv, R"XYX(Vocaloid Wiki (Mikupa 2011 Tokyo))XYX"sv, R"XYX(https://vocaloid.fandom.com/wiki/Hatsune_Miku_Live_Party_2011_(Mikupa)/Tokyo)XYX"sv, 2533 },
}};


#if __has_embed("release_event_pic_orig_2526") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_orig_2526 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_orig_2526"
});
constexpr std::string_view release_event_mime_type_orig_2526 = "image/png";
constexpr std::string_view release_event_file_ext_orig_2526 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_orig_2526;
constexpr std::string_view release_event_mime_type_orig_2526 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_orig_2526;
#endif


#if __has_embed("release_event_pic_small_thumb_2526") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_small_thumb_2526 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_small_thumb_2526"
});
constexpr std::string_view release_event_mime_type_small_thumb_2526 = "image/png";
constexpr std::string_view release_event_file_ext_small_thumb_2526 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_small_thumb_2526;
constexpr std::string_view release_event_mime_type_small_thumb_2526 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_small_thumb_2526;
#endif


#if __has_embed("release_event_pic_thumb_2526") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_thumb_2526 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_thumb_2526"
});
constexpr std::string_view release_event_mime_type_thumb_2526 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_2526 = "???";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_thumb_2526;
constexpr std::string_view release_event_mime_type_thumb_2526 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_2526;
#endif


#if __has_embed("release_event_pic_tiny_thumb_2526") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_tiny_thumb_2526 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_tiny_thumb_2526"
});
constexpr std::string_view release_event_mime_type_tiny_thumb_2526 = "image/png";
constexpr std::string_view release_event_file_ext_tiny_thumb_2526 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_tiny_thumb_2526;
constexpr std::string_view release_event_mime_type_tiny_thumb_2526 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_tiny_thumb_2526;
#endif

constexpr picture picture_release_event_2526 = { R"XYX(image/png)XYX"sv, std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/2526.png?v=8)XYX"sv, release_event_pic_orig_2526, release_event_mime_type_orig_2526, release_event_file_ext_orig_2526, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/2526.png?v=8)XYX"sv, release_event_pic_small_thumb_2526, release_event_mime_type_small_thumb_2526, release_event_file_ext_small_thumb_2526, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/2526.png?v=8)XYX"sv, release_event_pic_thumb_2526, release_event_mime_type_thumb_2526, release_event_file_ext_thumb_2526, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/2526.png?v=8)XYX"sv, release_event_pic_tiny_thumb_2526, release_event_mime_type_tiny_thumb_2526, release_event_file_ext_tiny_thumb_2526  };

constexpr std::array<additional_name, 4> names_release_event_2527 {{
  {"English"sv, R"XYX(Hatsune Miku Live Party 2011 Singapore)XYX"sv},
  {"Unspecified"sv, R"XYX(ミクパ 2011 Singapore)XYX"sv},
  {"Japanese"sv, R"XYX(初音ミクライブパーティー 2011 Singapore)XYX"sv},
  {"Unspecified"sv, R"XYX(MikuPa 2011 Singapore)XYX"sv},
}};

constexpr std::array<web_link, 4> web_links_release_event_2527 {{
  {"Other"sv, R"XYX(Website)XYX"sv, R"XYX(http://5pb.jp/mikupa/index_singapore.html)XYX"sv, 965 },
  {"Reference"sv, R"XYX(Vocaloid Wiki (Mikupa 2011 Sapporo))XYX"sv, R"XYX(https://vocaloid.fandom.com/wiki/Hatsune_Miku_Live_Party_2011_(Mikupa)/Sapporo)XYX"sv, 2534 },
  {"Reference"sv, R"XYX(Vocaloid Wiki (Mikupa 2011 Singapore))XYX"sv, R"XYX(https://vocaloid.fandom.com/wiki/Hatsune_Miku_Live_Party_2011_(Mikupa)/Singapore)XYX"sv, 2535 },
  {"Reference"sv, R"XYX(Vocaloid Wiki (Mikupa 2011 Tokyo))XYX"sv, R"XYX(https://vocaloid.fandom.com/wiki/Hatsune_Miku_Live_Party_2011_(Mikupa)/Tokyo)XYX"sv, 2536 },
}};


#if __has_embed("release_event_pic_orig_2527") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_orig_2527 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_orig_2527"
});
constexpr std::string_view release_event_mime_type_orig_2527 = "image/png";
constexpr std::string_view release_event_file_ext_orig_2527 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_orig_2527;
constexpr std::string_view release_event_mime_type_orig_2527 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_orig_2527;
#endif


#if __has_embed("release_event_pic_small_thumb_2527") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_small_thumb_2527 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_small_thumb_2527"
});
constexpr std::string_view release_event_mime_type_small_thumb_2527 = "image/png";
constexpr std::string_view release_event_file_ext_small_thumb_2527 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_small_thumb_2527;
constexpr std::string_view release_event_mime_type_small_thumb_2527 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_small_thumb_2527;
#endif


#if __has_embed("release_event_pic_thumb_2527") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_thumb_2527 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_thumb_2527"
});
constexpr std::string_view release_event_mime_type_thumb_2527 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_2527 = "???";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_thumb_2527;
constexpr std::string_view release_event_mime_type_thumb_2527 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_2527;
#endif


#if __has_embed("release_event_pic_tiny_thumb_2527") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_tiny_thumb_2527 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_tiny_thumb_2527"
});
constexpr std::string_view release_event_mime_type_tiny_thumb_2527 = "image/png";
constexpr std::string_view release_event_file_ext_tiny_thumb_2527 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_tiny_thumb_2527;
constexpr std::string_view release_event_mime_type_tiny_thumb_2527 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_tiny_thumb_2527;
#endif

constexpr picture picture_release_event_2527 = { R"XYX(image/png)XYX"sv, std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/2527.png?v=5)XYX"sv, release_event_pic_orig_2527, release_event_mime_type_orig_2527, release_event_file_ext_orig_2527, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/2527.png?v=5)XYX"sv, release_event_pic_small_thumb_2527, release_event_mime_type_small_thumb_2527, release_event_file_ext_small_thumb_2527, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/2527.png?v=5)XYX"sv, release_event_pic_thumb_2527, release_event_mime_type_thumb_2527, release_event_file_ext_thumb_2527, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/2527.png?v=5)XYX"sv, release_event_pic_tiny_thumb_2527, release_event_mime_type_tiny_thumb_2527, release_event_file_ext_tiny_thumb_2527  };

constexpr std::array<additional_name, 4> names_release_event_4056 {{
  {"English"sv, R"XYX(Hatsune Miku Live Party 2012 Tokyo)XYX"sv},
  {"Unspecified"sv, R"XYX(ミクパ 2012 Tokyo)XYX"sv},
  {"Japanese"sv, R"XYX(初音ミクライブパーティー 2012 Tokyo)XYX"sv},
  {"Unspecified"sv, R"XYX(MikuPa 2012 Tokyo)XYX"sv},
}};

constexpr std::array<web_link, 5> web_links_release_event_4056 {{
  {"Reference"sv, R"XYX(Vocaloid Wiki (Mikupa 2012 Tokyo))XYX"sv, R"XYX(https://vocaloid.fandom.com/wiki/Hatsune_Miku_Live_Party_2012_(Mikupa)/Tokyo)XYX"sv, 2537 },
  {"Reference"sv, R"XYX(Vocaloid Wiki (Mikupa 2012 Hong Kong))XYX"sv, R"XYX(https://vocaloid.fandom.com/wiki/Hatsune_Miku_Live_Party_2012_(Mikupa)/Hong_Kong_and_Taiwan)XYX"sv, 2538 },
  {"Reference"sv, R"XYX(Vocaloid Wiki (Mikupa 2012 Taiwan))XYX"sv, R"XYX(https://vocaloid.fandom.com/wiki/Hatsune_Miku_Live_Party_2012_(Mikupa)/Hong_Kong_and_Taiwan)XYX"sv, 2539 },
  {"Reference"sv, R"XYX(Vocaloid Wiki (Miku no Hi Dai Kanshasai 39's Giving Day))XYX"sv, R"XYX(https://vocaloid.fandom.com/wiki/Miku_no_Hi_Dai_Kanshasai_39%27s_Giving_Day)XYX"sv, 2541 },
  {"Reference"sv, R"XYX(VocaDB / Miku's Big Thanksgiving Day)XYX"sv, R"XYX(https://vocadb.net/E/1413/39s-giving-day-2012)XYX"sv, 2542 },
}};


#if __has_embed("release_event_pic_orig_4056") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_orig_4056 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_orig_4056"
});
constexpr std::string_view release_event_mime_type_orig_4056 = "image/png";
constexpr std::string_view release_event_file_ext_orig_4056 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_orig_4056;
constexpr std::string_view release_event_mime_type_orig_4056 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_orig_4056;
#endif


#if __has_embed("release_event_pic_small_thumb_4056") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_small_thumb_4056 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_small_thumb_4056"
});
constexpr std::string_view release_event_mime_type_small_thumb_4056 = "image/png";
constexpr std::string_view release_event_file_ext_small_thumb_4056 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_small_thumb_4056;
constexpr std::string_view release_event_mime_type_small_thumb_4056 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_small_thumb_4056;
#endif


#if __has_embed("release_event_pic_thumb_4056") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_thumb_4056 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_thumb_4056"
});
constexpr std::string_view release_event_mime_type_thumb_4056 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_4056 = "???";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_thumb_4056;
constexpr std::string_view release_event_mime_type_thumb_4056 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_4056;
#endif


#if __has_embed("release_event_pic_tiny_thumb_4056") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_tiny_thumb_4056 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_tiny_thumb_4056"
});
constexpr std::string_view release_event_mime_type_tiny_thumb_4056 = "image/png";
constexpr std::string_view release_event_file_ext_tiny_thumb_4056 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_tiny_thumb_4056;
constexpr std::string_view release_event_mime_type_tiny_thumb_4056 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_tiny_thumb_4056;
#endif

constexpr picture picture_release_event_4056 = { R"XYX(image/png)XYX"sv, std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/4056.png?v=10)XYX"sv, release_event_pic_orig_4056, release_event_mime_type_orig_4056, release_event_file_ext_orig_4056, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/4056.png?v=10)XYX"sv, release_event_pic_small_thumb_4056, release_event_mime_type_small_thumb_4056, release_event_file_ext_small_thumb_4056, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/4056.png?v=10)XYX"sv, release_event_pic_thumb_4056, release_event_mime_type_thumb_4056, release_event_file_ext_thumb_4056, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/4056.png?v=10)XYX"sv, release_event_pic_tiny_thumb_4056, release_event_mime_type_tiny_thumb_4056, release_event_file_ext_tiny_thumb_4056  };

constexpr std::array<additional_name, 3> names_release_event_1413 {{
  {"English"sv, R"XYX(Miku's Big Thanksgiving Day - Special 39's Production 2012)XYX"sv},
  {"Japanese"sv, R"XYX(ミクの日大感謝祭特番 - 制作日誌39 2012)XYX"sv},
  {"Romaji"sv, R"XYX(Miku No Hi Daikanshasai Tokuban - Seisaku Nisshi 39 2012)XYX"sv},
}};

constexpr std::array<web_link, 4> web_links_release_event_1413 {{
  {"Reference"sv, R"XYX(Vocaloid Wiki (Miku no Hi Dai Kanshasai 39's Giving Day))XYX"sv, R"XYX(https://vocaloid.fandom.com/wiki/Miku_no_Hi_Dai_Kanshasai_39%27s_Giving_Day)XYX"sv, 2543 },
  {"Other"sv, R"XYX(Website)XYX"sv, R"XYX(http://miku.sega.jp/39/)XYX"sv, 2544 },
  {"Reference"sv, R"XYX(Vocaloid Wiki (Mikupa 2012 Tokyo))XYX"sv, R"XYX(https://vocaloid.fandom.com/wiki/Hatsune_Miku_Live_Party_2012_(Mikupa)/Tokyo)XYX"sv, 2545 },
  {"Reference"sv, R"XYX(VocaDB / Hatsune Miku Live Party 2012 Tokyo)XYX"sv, R"XYX(https://vocadb.net/E/4056/hatsune-miku-live-party-2012-t)XYX"sv, 2546 },
}};


#if __has_embed("release_event_pic_orig_1413") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_orig_1413 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_orig_1413"
});
constexpr std::string_view release_event_mime_type_orig_1413 = "image/jpeg";
constexpr std::string_view release_event_file_ext_orig_1413 = "jpeg";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_orig_1413;
constexpr std::string_view release_event_mime_type_orig_1413 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_orig_1413;
#endif


#if __has_embed("release_event_pic_small_thumb_1413") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_small_thumb_1413 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_small_thumb_1413"
});
constexpr std::string_view release_event_mime_type_small_thumb_1413 = "image/png";
constexpr std::string_view release_event_file_ext_small_thumb_1413 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_small_thumb_1413;
constexpr std::string_view release_event_mime_type_small_thumb_1413 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_small_thumb_1413;
#endif


#if __has_embed("release_event_pic_thumb_1413") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_thumb_1413 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_thumb_1413"
});
constexpr std::string_view release_event_mime_type_thumb_1413 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_1413 = "???";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_thumb_1413;
constexpr std::string_view release_event_mime_type_thumb_1413 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_1413;
#endif


#if __has_embed("release_event_pic_tiny_thumb_1413") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_tiny_thumb_1413 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_tiny_thumb_1413"
});
constexpr std::string_view release_event_mime_type_tiny_thumb_1413 = "image/png";
constexpr std::string_view release_event_file_ext_tiny_thumb_1413 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_tiny_thumb_1413;
constexpr std::string_view release_event_mime_type_tiny_thumb_1413 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_tiny_thumb_1413;
#endif

constexpr picture picture_release_event_1413 = { R"XYX(image/jpeg)XYX"sv, std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/1413.jpg?v=12)XYX"sv, release_event_pic_orig_1413, release_event_mime_type_orig_1413, release_event_file_ext_orig_1413, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/1413.jpg?v=12)XYX"sv, release_event_pic_small_thumb_1413, release_event_mime_type_small_thumb_1413, release_event_file_ext_small_thumb_1413, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/1413.jpg?v=12)XYX"sv, release_event_pic_thumb_1413, release_event_mime_type_thumb_1413, release_event_file_ext_thumb_1413, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/1413.jpg?v=12)XYX"sv, release_event_pic_tiny_thumb_1413, release_event_mime_type_tiny_thumb_1413, release_event_file_ext_tiny_thumb_1413  };

constexpr std::array<additional_name, 4> names_release_event_2524 {{
  {"English"sv, R"XYX(Hatsune Miku Live Party 2012 Hong Kong)XYX"sv},
  {"Unspecified"sv, R"XYX(ミクパ 2012 Hong Kong)XYX"sv},
  {"Japanese"sv, R"XYX(初音ミクライブパーティー 2012 Hong Kong)XYX"sv},
  {"Unspecified"sv, R"XYX(MikuPa 2012 Hong Kong)XYX"sv},
}};

constexpr std::array<web_link, 4> web_links_release_event_2524 {{
  {"Other"sv, R"XYX(Website)XYX"sv, R"XYX(http://5pb.jp/mikupa/index_hktw.html)XYX"sv, 957 },
  {"Reference"sv, R"XYX(Vocaloid Wiki (Mikupa 2012 Hong Kong))XYX"sv, R"XYX(https://vocaloid.fandom.com/wiki/Hatsune_Miku_Live_Party_2012_(Mikupa)/Hong_Kong_and_Taiwan)XYX"sv, 2547 },
  {"Reference"sv, R"XYX(Vocaloid Wiki (Mikupa 2012 Taiwan))XYX"sv, R"XYX(https://vocaloid.fandom.com/wiki/Hatsune_Miku_Live_Party_2012_(Mikupa)/Hong_Kong_and_Taiwan)XYX"sv, 2548 },
  {"Reference"sv, R"XYX(Vocaloid Wiki (Mikupa 2012 Tokyo))XYX"sv, R"XYX(https://vocaloid.fandom.com/wiki/Hatsune_Miku_Live_Party_2012_(Mikupa)/Tokyo)XYX"sv, 2549 },
}};


#if __has_embed("release_event_pic_orig_2524") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_orig_2524 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_orig_2524"
});
constexpr std::string_view release_event_mime_type_orig_2524 = "image/png";
constexpr std::string_view release_event_file_ext_orig_2524 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_orig_2524;
constexpr std::string_view release_event_mime_type_orig_2524 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_orig_2524;
#endif


#if __has_embed("release_event_pic_small_thumb_2524") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_small_thumb_2524 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_small_thumb_2524"
});
constexpr std::string_view release_event_mime_type_small_thumb_2524 = "image/png";
constexpr std::string_view release_event_file_ext_small_thumb_2524 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_small_thumb_2524;
constexpr std::string_view release_event_mime_type_small_thumb_2524 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_small_thumb_2524;
#endif


#if __has_embed("release_event_pic_thumb_2524") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_thumb_2524 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_thumb_2524"
});
constexpr std::string_view release_event_mime_type_thumb_2524 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_2524 = "???";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_thumb_2524;
constexpr std::string_view release_event_mime_type_thumb_2524 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_2524;
#endif


#if __has_embed("release_event_pic_tiny_thumb_2524") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_tiny_thumb_2524 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_tiny_thumb_2524"
});
constexpr std::string_view release_event_mime_type_tiny_thumb_2524 = "image/png";
constexpr std::string_view release_event_file_ext_tiny_thumb_2524 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_tiny_thumb_2524;
constexpr std::string_view release_event_mime_type_tiny_thumb_2524 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_tiny_thumb_2524;
#endif

constexpr picture picture_release_event_2524 = { R"XYX(image/jpeg)XYX"sv, std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/2524.jpg?v=6)XYX"sv, release_event_pic_orig_2524, release_event_mime_type_orig_2524, release_event_file_ext_orig_2524, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/2524.jpg?v=6)XYX"sv, release_event_pic_small_thumb_2524, release_event_mime_type_small_thumb_2524, release_event_file_ext_small_thumb_2524, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/2524.jpg?v=6)XYX"sv, release_event_pic_thumb_2524, release_event_mime_type_thumb_2524, release_event_file_ext_thumb_2524, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/2524.jpg?v=6)XYX"sv, release_event_pic_tiny_thumb_2524, release_event_mime_type_tiny_thumb_2524, release_event_file_ext_tiny_thumb_2524  };

constexpr std::array<additional_name, 4> names_release_event_2510 {{
  {"English"sv, R"XYX(Hatsune Miku Live Party 2013 Sapporo)XYX"sv},
  {"Unspecified"sv, R"XYX(ミクパ 2013 Sapporo)XYX"sv},
  {"Japanese"sv, R"XYX(初音ミクライブパーティー 2013 Sapporo)XYX"sv},
  {"Unspecified"sv, R"XYX(MikuPa 2013 Sapporo)XYX"sv},
}};

constexpr std::array<web_link, 4> web_links_release_event_2510 {{
  {"Other"sv, R"XYX(Website)XYX"sv, R"XYX(http://5pb.jp/mikupa/index_sapporo2013.html)XYX"sv, 938 },
  {"Other"sv, R"XYX(Piapro 's blog)XYX"sv, R"XYX(https://blog.piapro.net/2012/12/2910.html)XYX"sv, 939 },
  {"Reference"sv, R"XYX(Vocaloid Wiki (Mikupa 2013 Kansai))XYX"sv, R"XYX(https://vocaloid.fandom.com/wiki/Hatsune_Miku_Live_Party_2013_(MikuPa)/Kansai)XYX"sv, 2553 },
  {"Reference"sv, R"XYX(Vocaloid Wiki (Mikupa 2013 Sapporo))XYX"sv, R"XYX(https://vocaloid.fandom.com/wiki/Hatsune_Miku_Live_Party_2013_(MikuPa)/Sapporo)XYX"sv, 2554 },
}};


#if __has_embed("release_event_pic_orig_2510") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_orig_2510 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_orig_2510"
});
constexpr std::string_view release_event_mime_type_orig_2510 = "image/jpeg";
constexpr std::string_view release_event_file_ext_orig_2510 = "jpeg";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_orig_2510;
constexpr std::string_view release_event_mime_type_orig_2510 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_orig_2510;
#endif


#if __has_embed("release_event_pic_small_thumb_2510") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_small_thumb_2510 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_small_thumb_2510"
});
constexpr std::string_view release_event_mime_type_small_thumb_2510 = "image/png";
constexpr std::string_view release_event_file_ext_small_thumb_2510 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_small_thumb_2510;
constexpr std::string_view release_event_mime_type_small_thumb_2510 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_small_thumb_2510;
#endif


#if __has_embed("release_event_pic_thumb_2510") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_thumb_2510 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_thumb_2510"
});
constexpr std::string_view release_event_mime_type_thumb_2510 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_2510 = "???";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_thumb_2510;
constexpr std::string_view release_event_mime_type_thumb_2510 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_2510;
#endif


#if __has_embed("release_event_pic_tiny_thumb_2510") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_tiny_thumb_2510 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_tiny_thumb_2510"
});
constexpr std::string_view release_event_mime_type_tiny_thumb_2510 = "image/png";
constexpr std::string_view release_event_file_ext_tiny_thumb_2510 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_tiny_thumb_2510;
constexpr std::string_view release_event_mime_type_tiny_thumb_2510 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_tiny_thumb_2510;
#endif

constexpr picture picture_release_event_2510 = { R"XYX(image/jpeg)XYX"sv, std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/2510.jpg?v=9)XYX"sv, release_event_pic_orig_2510, release_event_mime_type_orig_2510, release_event_file_ext_orig_2510, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/2510.jpg?v=9)XYX"sv, release_event_pic_small_thumb_2510, release_event_mime_type_small_thumb_2510, release_event_file_ext_small_thumb_2510, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/2510.jpg?v=9)XYX"sv, release_event_pic_thumb_2510, release_event_mime_type_thumb_2510, release_event_file_ext_thumb_2510, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/2510.jpg?v=9)XYX"sv, release_event_pic_tiny_thumb_2510, release_event_mime_type_tiny_thumb_2510, release_event_file_ext_tiny_thumb_2510  };

constexpr std::array<additional_name, 4> names_release_event_2511 {{
  {"English"sv, R"XYX(Hatsune Miku Live Party 2013 Kansai)XYX"sv},
  {"Unspecified"sv, R"XYX(ミクパ 2013 Kansai)XYX"sv},
  {"Japanese"sv, R"XYX(初音ミクライブパーティー 2013 Kansai)XYX"sv},
  {"Unspecified"sv, R"XYX(MikuPa 2013 Kansai)XYX"sv},
}};

constexpr std::array<web_link, 3> web_links_release_event_2511 {{
  {"Other"sv, R"XYX(Website)XYX"sv, R"XYX(http://5pb.jp/mikupa/index_kansai.html)XYX"sv, 940 },
  {"Other"sv, R"XYX(Vocaloid Wiki (Mikupa 2013 Kansai))XYX"sv, R"XYX(https://vocaloid.fandom.com/wiki/Hatsune_Miku_Live_Party_2013_(MikuPa)/Kansai)XYX"sv, 2555 },
  {"Other"sv, R"XYX(Vocaloid Wiki (Mikupa 2013 Sapporo))XYX"sv, R"XYX(https://vocaloid.fandom.com/wiki/Hatsune_Miku_Live_Party_2013_(MikuPa)/Sapporo)XYX"sv, 2556 },
}};


#if __has_embed("release_event_pic_orig_2511") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_orig_2511 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_orig_2511"
});
constexpr std::string_view release_event_mime_type_orig_2511 = "image/png";
constexpr std::string_view release_event_file_ext_orig_2511 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_orig_2511;
constexpr std::string_view release_event_mime_type_orig_2511 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_orig_2511;
#endif


#if __has_embed("release_event_pic_small_thumb_2511") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_small_thumb_2511 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_small_thumb_2511"
});
constexpr std::string_view release_event_mime_type_small_thumb_2511 = "image/png";
constexpr std::string_view release_event_file_ext_small_thumb_2511 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_small_thumb_2511;
constexpr std::string_view release_event_mime_type_small_thumb_2511 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_small_thumb_2511;
#endif


#if __has_embed("release_event_pic_thumb_2511") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_thumb_2511 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_thumb_2511"
});
constexpr std::string_view release_event_mime_type_thumb_2511 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_2511 = "???";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_thumb_2511;
constexpr std::string_view release_event_mime_type_thumb_2511 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_2511;
#endif


#if __has_embed("release_event_pic_tiny_thumb_2511") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_tiny_thumb_2511 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_tiny_thumb_2511"
});
constexpr std::string_view release_event_mime_type_tiny_thumb_2511 = "image/png";
constexpr std::string_view release_event_file_ext_tiny_thumb_2511 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_tiny_thumb_2511;
constexpr std::string_view release_event_mime_type_tiny_thumb_2511 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_tiny_thumb_2511;
#endif

constexpr picture picture_release_event_2511 = { R"XYX(image/jpeg)XYX"sv, std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/2511.jpg?v=10)XYX"sv, release_event_pic_orig_2511, release_event_mime_type_orig_2511, release_event_file_ext_orig_2511, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/2511.jpg?v=10)XYX"sv, release_event_pic_small_thumb_2511, release_event_mime_type_small_thumb_2511, release_event_file_ext_small_thumb_2511, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/2511.jpg?v=10)XYX"sv, release_event_pic_thumb_2511, release_event_mime_type_thumb_2511, release_event_file_ext_thumb_2511, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/2511.jpg?v=10)XYX"sv, release_event_pic_tiny_thumb_2511, release_event_mime_type_tiny_thumb_2511, release_event_file_ext_tiny_thumb_2511  };

constexpr std::array<additional_name, 4> names_release_event_2519 {{
  {"Japanese"sv, R"XYX(初音ミク「マジカルミライ 2013」)XYX"sv},
  {"English"sv, R"XYX(Hatsune Miku Magical Mirai 2013)XYX"sv},
  {"Unspecified"sv, R"XYX(マジカルミライ 2013)XYX"sv},
  {"Unspecified"sv, R"XYX(Magical Mirai 2013)XYX"sv},
}};

constexpr std::array<web_link, 1> web_links_release_event_2519 {{
  {"Other"sv, R"XYX(Website)XYX"sv, R"XYX(https://magicalmirai.com/2013/)XYX"sv, 946 },
}};


#if __has_embed("release_event_pic_orig_2519") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_orig_2519 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_orig_2519"
});
constexpr std::string_view release_event_mime_type_orig_2519 = "image/png";
constexpr std::string_view release_event_file_ext_orig_2519 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_orig_2519;
constexpr std::string_view release_event_mime_type_orig_2519 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_orig_2519;
#endif


#if __has_embed("release_event_pic_small_thumb_2519") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_small_thumb_2519 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_small_thumb_2519"
});
constexpr std::string_view release_event_mime_type_small_thumb_2519 = "image/png";
constexpr std::string_view release_event_file_ext_small_thumb_2519 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_small_thumb_2519;
constexpr std::string_view release_event_mime_type_small_thumb_2519 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_small_thumb_2519;
#endif


#if __has_embed("release_event_pic_thumb_2519") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_thumb_2519 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_thumb_2519"
});
constexpr std::string_view release_event_mime_type_thumb_2519 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_2519 = "???";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_thumb_2519;
constexpr std::string_view release_event_mime_type_thumb_2519 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_2519;
#endif


#if __has_embed("release_event_pic_tiny_thumb_2519") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_tiny_thumb_2519 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_tiny_thumb_2519"
});
constexpr std::string_view release_event_mime_type_tiny_thumb_2519 = "image/png";
constexpr std::string_view release_event_file_ext_tiny_thumb_2519 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_tiny_thumb_2519;
constexpr std::string_view release_event_mime_type_tiny_thumb_2519 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_tiny_thumb_2519;
#endif

constexpr picture picture_release_event_2519 = { R"XYX(image/jpeg)XYX"sv, std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/2519.jpg?v=4)XYX"sv, release_event_pic_orig_2519, release_event_mime_type_orig_2519, release_event_file_ext_orig_2519, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/2519.jpg?v=4)XYX"sv, release_event_pic_small_thumb_2519, release_event_mime_type_small_thumb_2519, release_event_file_ext_small_thumb_2519, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/2519.jpg?v=4)XYX"sv, release_event_pic_thumb_2519, release_event_mime_type_thumb_2519, release_event_file_ext_thumb_2519, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/2519.jpg?v=4)XYX"sv, release_event_pic_tiny_thumb_2519, release_event_mime_type_tiny_thumb_2519, release_event_file_ext_tiny_thumb_2519  };

constexpr std::array<additional_name, 2> names_release_event_1939 {{
  {"English"sv, R"XYX(Miku Expo 2014 Jakarta)XYX"sv},
  {"Unspecified"sv, R"XYX(HATSUNE MIKU EXPO 2014 IN INDONESIA)XYX"sv},
}};

constexpr std::array<web_link, 6> web_links_release_event_1939 {{
  {"Reference"sv, R"XYX(Vocaloid Wiki)XYX"sv, R"XYX(https://vocaloid.fandom.com/wiki/HATSUNE_MIKU_EXPO_2014_in_INDONESIA)XYX"sv, 960 },
  {"Commercial"sv, R"XYX(KarenT special)XYX"sv, R"XYX(https://karent.jp/special/mikuexpo14)XYX"sv, 1796 },
  {"Other"sv, R"XYX(MIKU EXPO in Indonesia Website)XYX"sv, R"XYX(https://mikuexpo.com/indonesia_top)XYX"sv, 1797 },
  {"Other"sv, R"XYX(mohax (VOCALO.ID) special interview)XYX"sv, R"XYX(https://mikuexpo.com/indonesia_karent#creator)XYX"sv, 1798 },
  {"Reference"sv, R"XYX(special Album)XYX"sv, R"XYX(https://vocadb.net/Al/9709)XYX"sv, 1799 },
  {"Other"sv, R"XYX(YouTube (special video))XYX"sv, R"XYX(https://youtu.be/Bo2LO4kWsyY)XYX"sv, 1800 },
}};


#if __has_embed("release_event_pic_orig_1939") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_orig_1939 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_orig_1939"
});
constexpr std::string_view release_event_mime_type_orig_1939 = "image/png";
constexpr std::string_view release_event_file_ext_orig_1939 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_orig_1939;
constexpr std::string_view release_event_mime_type_orig_1939 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_orig_1939;
#endif


#if __has_embed("release_event_pic_small_thumb_1939") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_small_thumb_1939 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_small_thumb_1939"
});
constexpr std::string_view release_event_mime_type_small_thumb_1939 = "image/png";
constexpr std::string_view release_event_file_ext_small_thumb_1939 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_small_thumb_1939;
constexpr std::string_view release_event_mime_type_small_thumb_1939 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_small_thumb_1939;
#endif


#if __has_embed("release_event_pic_thumb_1939") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_thumb_1939 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_thumb_1939"
});
constexpr std::string_view release_event_mime_type_thumb_1939 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_1939 = "???";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_thumb_1939;
constexpr std::string_view release_event_mime_type_thumb_1939 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_1939;
#endif


#if __has_embed("release_event_pic_tiny_thumb_1939") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_tiny_thumb_1939 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_tiny_thumb_1939"
});
constexpr std::string_view release_event_mime_type_tiny_thumb_1939 = "image/png";
constexpr std::string_view release_event_file_ext_tiny_thumb_1939 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_tiny_thumb_1939;
constexpr std::string_view release_event_mime_type_tiny_thumb_1939 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_tiny_thumb_1939;
#endif

constexpr picture picture_release_event_1939 = { R"XYX(image/png)XYX"sv, std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/1939.png?v=10)XYX"sv, release_event_pic_orig_1939, release_event_mime_type_orig_1939, release_event_file_ext_orig_1939, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/1939.png?v=10)XYX"sv, release_event_pic_small_thumb_1939, release_event_mime_type_small_thumb_1939, release_event_file_ext_small_thumb_1939, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/1939.png?v=10)XYX"sv, release_event_pic_thumb_1939, release_event_mime_type_thumb_1939, release_event_file_ext_thumb_1939, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/1939.png?v=10)XYX"sv, release_event_pic_tiny_thumb_1939, release_event_mime_type_tiny_thumb_1939, release_event_file_ext_tiny_thumb_1939  };

constexpr std::array<additional_name, 4> names_release_event_2517 {{
  {"Japanese"sv, R"XYX(初音ミク「マジカルミライ 2014」in OSAKA)XYX"sv},
  {"English"sv, R"XYX(Hatsune Miku Magical Mirai 2014 in OSAKA)XYX"sv},
  {"Unspecified"sv, R"XYX(マジカルミライ 2014 Osaka)XYX"sv},
  {"Unspecified"sv, R"XYX(Magical Mirai 2014 Osaka)XYX"sv},
}};

constexpr std::array<web_link, 4> web_links_release_event_2517 {{
  {"Other"sv, R"XYX(Website - OSAKA (JP))XYX"sv, R"XYX(https://magicalmirai.com/2014/ticket_osaka.html)XYX"sv, 944 },
  {"Other"sv, R"XYX(Website (JP))XYX"sv, R"XYX(https://magicalmirai.com/2014/)XYX"sv, 1897 },
  {"Other"sv, R"XYX(Website (EN))XYX"sv, R"XYX(https://magicalmirai.com/2014/index_en.html)XYX"sv, 1899 },
  {"Other"sv, R"XYX(Website - OSAKA (EN))XYX"sv, R"XYX(https://magicalmirai.com/2014/ticket_osaka_en.html)XYX"sv, 1900 },
}};


#if __has_embed("release_event_pic_orig_2517") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_orig_2517 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_orig_2517"
});
constexpr std::string_view release_event_mime_type_orig_2517 = "image/png";
constexpr std::string_view release_event_file_ext_orig_2517 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_orig_2517;
constexpr std::string_view release_event_mime_type_orig_2517 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_orig_2517;
#endif


#if __has_embed("release_event_pic_small_thumb_2517") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_small_thumb_2517 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_small_thumb_2517"
});
constexpr std::string_view release_event_mime_type_small_thumb_2517 = "image/png";
constexpr std::string_view release_event_file_ext_small_thumb_2517 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_small_thumb_2517;
constexpr std::string_view release_event_mime_type_small_thumb_2517 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_small_thumb_2517;
#endif


#if __has_embed("release_event_pic_thumb_2517") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_thumb_2517 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_thumb_2517"
});
constexpr std::string_view release_event_mime_type_thumb_2517 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_2517 = "???";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_thumb_2517;
constexpr std::string_view release_event_mime_type_thumb_2517 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_2517;
#endif


#if __has_embed("release_event_pic_tiny_thumb_2517") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_tiny_thumb_2517 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_tiny_thumb_2517"
});
constexpr std::string_view release_event_mime_type_tiny_thumb_2517 = "image/png";
constexpr std::string_view release_event_file_ext_tiny_thumb_2517 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_tiny_thumb_2517;
constexpr std::string_view release_event_mime_type_tiny_thumb_2517 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_tiny_thumb_2517;
#endif

constexpr picture picture_release_event_2517 = { R"XYX(image/jpeg)XYX"sv, std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/2517.jpg?v=6)XYX"sv, release_event_pic_orig_2517, release_event_mime_type_orig_2517, release_event_file_ext_orig_2517, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/2517.jpg?v=6)XYX"sv, release_event_pic_small_thumb_2517, release_event_mime_type_small_thumb_2517, release_event_file_ext_small_thumb_2517, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/2517.jpg?v=6)XYX"sv, release_event_pic_thumb_2517, release_event_mime_type_thumb_2517, release_event_file_ext_thumb_2517, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/2517.jpg?v=6)XYX"sv, release_event_pic_tiny_thumb_2517, release_event_mime_type_tiny_thumb_2517, release_event_file_ext_tiny_thumb_2517  };

constexpr std::array<additional_name, 1> names_release_event_1937 {{
  {"English"sv, R"XYX(Miku Expo 2014 Los Angeles)XYX"sv},
}};

constexpr std::array<web_link, 1> web_links_release_event_1937 {{
  {"Other"sv, R"XYX(Official website)XYX"sv, R"XYX(https://mikuexpo.com/la)XYX"sv, 961 },
}};


#if __has_embed("release_event_pic_orig_1937") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_orig_1937 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_orig_1937"
});
constexpr std::string_view release_event_mime_type_orig_1937 = "image/png";
constexpr std::string_view release_event_file_ext_orig_1937 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_orig_1937;
constexpr std::string_view release_event_mime_type_orig_1937 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_orig_1937;
#endif


#if __has_embed("release_event_pic_small_thumb_1937") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_small_thumb_1937 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_small_thumb_1937"
});
constexpr std::string_view release_event_mime_type_small_thumb_1937 = "image/png";
constexpr std::string_view release_event_file_ext_small_thumb_1937 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_small_thumb_1937;
constexpr std::string_view release_event_mime_type_small_thumb_1937 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_small_thumb_1937;
#endif


#if __has_embed("release_event_pic_thumb_1937") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_thumb_1937 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_thumb_1937"
});
constexpr std::string_view release_event_mime_type_thumb_1937 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_1937 = "???";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_thumb_1937;
constexpr std::string_view release_event_mime_type_thumb_1937 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_1937;
#endif


#if __has_embed("release_event_pic_tiny_thumb_1937") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_tiny_thumb_1937 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_tiny_thumb_1937"
});
constexpr std::string_view release_event_mime_type_tiny_thumb_1937 = "image/png";
constexpr std::string_view release_event_file_ext_tiny_thumb_1937 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_tiny_thumb_1937;
constexpr std::string_view release_event_mime_type_tiny_thumb_1937 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_tiny_thumb_1937;
#endif

constexpr picture picture_release_event_1937 = { R"XYX(image/png)XYX"sv, std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/1937.png?v=4)XYX"sv, release_event_pic_orig_1937, release_event_mime_type_orig_1937, release_event_file_ext_orig_1937, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/1937.png?v=4)XYX"sv, release_event_pic_small_thumb_1937, release_event_mime_type_small_thumb_1937, release_event_file_ext_small_thumb_1937, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/1937.png?v=4)XYX"sv, release_event_pic_thumb_1937, release_event_mime_type_thumb_1937, release_event_file_ext_thumb_1937, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/1937.png?v=4)XYX"sv, release_event_pic_tiny_thumb_1937, release_event_mime_type_tiny_thumb_1937, release_event_file_ext_tiny_thumb_1937  };

constexpr std::array<additional_name, 1> names_release_event_3792 {{
  {"English"sv, R"XYX(SNOW MIKU LIVE! 2015 presents MIKU EXPO Live Set)XYX"sv},
}};

constexpr std::array<web_link, 2> web_links_release_event_3792 {{
  {"Other"sv, R"XYX(Website)XYX"sv, R"XYX(https://snowmiku.com/2015/live_ticket.html)XYX"sv, 1928 },
  {"Other"sv, R"XYX(HATSUNE MIKU OFFICIAL BLOG)XYX"sv, R"XYX(https://blog.piapro.net/2015/02/u1502101_1.html)XYX"sv, 1929 },
}};


#if __has_embed("release_event_pic_orig_3792") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_orig_3792 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_orig_3792"
});
constexpr std::string_view release_event_mime_type_orig_3792 = "image/png";
constexpr std::string_view release_event_file_ext_orig_3792 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_orig_3792;
constexpr std::string_view release_event_mime_type_orig_3792 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_orig_3792;
#endif


#if __has_embed("release_event_pic_small_thumb_3792") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_small_thumb_3792 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_small_thumb_3792"
});
constexpr std::string_view release_event_mime_type_small_thumb_3792 = "image/png";
constexpr std::string_view release_event_file_ext_small_thumb_3792 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_small_thumb_3792;
constexpr std::string_view release_event_mime_type_small_thumb_3792 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_small_thumb_3792;
#endif


#if __has_embed("release_event_pic_thumb_3792") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_thumb_3792 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_thumb_3792"
});
constexpr std::string_view release_event_mime_type_thumb_3792 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_3792 = "???";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_thumb_3792;
constexpr std::string_view release_event_mime_type_thumb_3792 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_3792;
#endif


#if __has_embed("release_event_pic_tiny_thumb_3792") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_tiny_thumb_3792 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_tiny_thumb_3792"
});
constexpr std::string_view release_event_mime_type_tiny_thumb_3792 = "image/png";
constexpr std::string_view release_event_file_ext_tiny_thumb_3792 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_tiny_thumb_3792;
constexpr std::string_view release_event_mime_type_tiny_thumb_3792 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_tiny_thumb_3792;
#endif

constexpr picture picture_release_event_3792 = { R"XYX(image/jpeg)XYX"sv, std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/3792.jpg?v=4)XYX"sv, release_event_pic_orig_3792, release_event_mime_type_orig_3792, release_event_file_ext_orig_3792, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/3792.jpg?v=4)XYX"sv, release_event_pic_small_thumb_3792, release_event_mime_type_small_thumb_3792, release_event_file_ext_small_thumb_3792, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/3792.jpg?v=4)XYX"sv, release_event_pic_thumb_3792, release_event_mime_type_thumb_3792, release_event_file_ext_thumb_3792, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/3792.jpg?v=4)XYX"sv, release_event_pic_tiny_thumb_3792, release_event_mime_type_tiny_thumb_3792, release_event_file_ext_tiny_thumb_3792  };

constexpr std::array<additional_name, 1> names_release_event_1940 {{
  {"English"sv, R"XYX(Miku Expo 2015 Shanghai)XYX"sv},
}};

constexpr std::array<web_link, 1> web_links_release_event_1940 {{
  {"Reference"sv, R"XYX(Vocaloid Wiki)XYX"sv, R"XYX(https://vocaloid.fandom.com/wiki/HATSUNE_MIKU_EXPO_2015_in_SHANGHAI)XYX"sv, 963 },
}};


#if __has_embed("release_event_pic_orig_1940") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_orig_1940 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_orig_1940"
});
constexpr std::string_view release_event_mime_type_orig_1940 = "image/png";
constexpr std::string_view release_event_file_ext_orig_1940 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_orig_1940;
constexpr std::string_view release_event_mime_type_orig_1940 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_orig_1940;
#endif


#if __has_embed("release_event_pic_small_thumb_1940") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_small_thumb_1940 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_small_thumb_1940"
});
constexpr std::string_view release_event_mime_type_small_thumb_1940 = "image/png";
constexpr std::string_view release_event_file_ext_small_thumb_1940 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_small_thumb_1940;
constexpr std::string_view release_event_mime_type_small_thumb_1940 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_small_thumb_1940;
#endif


#if __has_embed("release_event_pic_thumb_1940") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_thumb_1940 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_thumb_1940"
});
constexpr std::string_view release_event_mime_type_thumb_1940 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_1940 = "???";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_thumb_1940;
constexpr std::string_view release_event_mime_type_thumb_1940 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_1940;
#endif


#if __has_embed("release_event_pic_tiny_thumb_1940") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_tiny_thumb_1940 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_tiny_thumb_1940"
});
constexpr std::string_view release_event_mime_type_tiny_thumb_1940 = "image/png";
constexpr std::string_view release_event_file_ext_tiny_thumb_1940 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_tiny_thumb_1940;
constexpr std::string_view release_event_mime_type_tiny_thumb_1940 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_tiny_thumb_1940;
#endif

constexpr picture picture_release_event_1940 = { R"XYX(image/png)XYX"sv, std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/1940.png?v=3)XYX"sv, release_event_pic_orig_1940, release_event_mime_type_orig_1940, release_event_file_ext_orig_1940, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/1940.png?v=3)XYX"sv, release_event_pic_small_thumb_1940, release_event_mime_type_small_thumb_1940, release_event_file_ext_small_thumb_1940, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/1940.png?v=3)XYX"sv, release_event_pic_thumb_1940, release_event_mime_type_thumb_1940, release_event_file_ext_thumb_1940, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/1940.png?v=3)XYX"sv, release_event_pic_tiny_thumb_1940, release_event_mime_type_tiny_thumb_1940, release_event_file_ext_tiny_thumb_1940  };

constexpr std::array<additional_name, 4> names_release_event_2514 {{
  {"Japanese"sv, R"XYX(初音ミク「マジカルミライ 2015」)XYX"sv},
  {"English"sv, R"XYX(Hatsune Miku Magical Mirai 2015)XYX"sv},
  {"Unspecified"sv, R"XYX(マジカルミライ 2015)XYX"sv},
  {"Unspecified"sv, R"XYX(Magical Mirai 2015)XYX"sv},
}};

constexpr std::array<web_link, 2> web_links_release_event_2514 {{
  {"Other"sv, R"XYX(Website (EN))XYX"sv, R"XYX(https://magicalmirai.com/2015/index_en.php)XYX"sv, 943 },
  {"Other"sv, R"XYX(Website (JP))XYX"sv, R"XYX(https://magicalmirai.com/2015/)XYX"sv, 1896 },
}};


#if __has_embed("release_event_pic_orig_2514") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_orig_2514 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_orig_2514"
});
constexpr std::string_view release_event_mime_type_orig_2514 = "image/png";
constexpr std::string_view release_event_file_ext_orig_2514 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_orig_2514;
constexpr std::string_view release_event_mime_type_orig_2514 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_orig_2514;
#endif


#if __has_embed("release_event_pic_small_thumb_2514") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_small_thumb_2514 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_small_thumb_2514"
});
constexpr std::string_view release_event_mime_type_small_thumb_2514 = "image/png";
constexpr std::string_view release_event_file_ext_small_thumb_2514 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_small_thumb_2514;
constexpr std::string_view release_event_mime_type_small_thumb_2514 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_small_thumb_2514;
#endif


#if __has_embed("release_event_pic_thumb_2514") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_thumb_2514 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_thumb_2514"
});
constexpr std::string_view release_event_mime_type_thumb_2514 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_2514 = "???";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_thumb_2514;
constexpr std::string_view release_event_mime_type_thumb_2514 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_2514;
#endif


#if __has_embed("release_event_pic_tiny_thumb_2514") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_tiny_thumb_2514 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_tiny_thumb_2514"
});
constexpr std::string_view release_event_mime_type_tiny_thumb_2514 = "image/png";
constexpr std::string_view release_event_file_ext_tiny_thumb_2514 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_tiny_thumb_2514;
constexpr std::string_view release_event_mime_type_tiny_thumb_2514 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_tiny_thumb_2514;
#endif

constexpr picture picture_release_event_2514 = { R"XYX(image/jpeg)XYX"sv, std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/2514.jpg?v=4)XYX"sv, release_event_pic_orig_2514, release_event_mime_type_orig_2514, release_event_file_ext_orig_2514, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/2514.jpg?v=4)XYX"sv, release_event_pic_small_thumb_2514, release_event_mime_type_small_thumb_2514, release_event_file_ext_small_thumb_2514, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/2514.jpg?v=4)XYX"sv, release_event_pic_thumb_2514, release_event_mime_type_thumb_2514, release_event_file_ext_thumb_2514, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/2514.jpg?v=4)XYX"sv, release_event_pic_tiny_thumb_2514, release_event_mime_type_tiny_thumb_2514, release_event_file_ext_tiny_thumb_2514  };

constexpr std::array<additional_name, 1> names_release_event_1399 {{
  {"English"sv, R"XYX(Miku Expo 2016 Fukuoka)XYX"sv},
}};

constexpr std::array<web_link, 0> web_links_release_event_1399 {{
}};


#if __has_embed("release_event_pic_orig_1399") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_orig_1399 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_orig_1399"
});
constexpr std::string_view release_event_mime_type_orig_1399 = "image/png";
constexpr std::string_view release_event_file_ext_orig_1399 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_orig_1399;
constexpr std::string_view release_event_mime_type_orig_1399 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_orig_1399;
#endif


#if __has_embed("release_event_pic_small_thumb_1399") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_small_thumb_1399 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_small_thumb_1399"
});
constexpr std::string_view release_event_mime_type_small_thumb_1399 = "image/png";
constexpr std::string_view release_event_file_ext_small_thumb_1399 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_small_thumb_1399;
constexpr std::string_view release_event_mime_type_small_thumb_1399 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_small_thumb_1399;
#endif


#if __has_embed("release_event_pic_thumb_1399") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_thumb_1399 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_thumb_1399"
});
constexpr std::string_view release_event_mime_type_thumb_1399 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_1399 = "???";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_thumb_1399;
constexpr std::string_view release_event_mime_type_thumb_1399 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_1399;
#endif


#if __has_embed("release_event_pic_tiny_thumb_1399") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_tiny_thumb_1399 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_tiny_thumb_1399"
});
constexpr std::string_view release_event_mime_type_tiny_thumb_1399 = "image/png";
constexpr std::string_view release_event_file_ext_tiny_thumb_1399 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_tiny_thumb_1399;
constexpr std::string_view release_event_mime_type_tiny_thumb_1399 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_tiny_thumb_1399;
#endif

constexpr picture picture_release_event_1399 = { R"XYX(image/jpeg)XYX"sv, std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/1399.jpg?v=8)XYX"sv, release_event_pic_orig_1399, release_event_mime_type_orig_1399, release_event_file_ext_orig_1399, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/1399.jpg?v=8)XYX"sv, release_event_pic_small_thumb_1399, release_event_mime_type_small_thumb_1399, release_event_file_ext_small_thumb_1399, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/1399.jpg?v=8)XYX"sv, release_event_pic_thumb_1399, release_event_mime_type_thumb_1399, release_event_file_ext_thumb_1399, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/1399.jpg?v=8)XYX"sv, release_event_pic_tiny_thumb_1399, release_event_mime_type_tiny_thumb_1399, release_event_file_ext_tiny_thumb_1399  };

constexpr std::array<additional_name, 1> names_release_event_1859 {{
  {"English"sv, R"XYX(Miku Expo 2016 Seattle)XYX"sv},
}};

constexpr std::array<web_link, 2> web_links_release_event_1859 {{
  {"Other"sv, R"XYX(mikuexpo.com)XYX"sv, R"XYX(http://mikuexpo.com/na2016/)XYX"sv, 612 },
  {"Other"sv, R"XYX(mikufan.com Setlist)XYX"sv, R"XYX(http://www.mikufan.com/hatsune-miku-expo-2016-in-north-america-seattle-concert-setlist-spoilers/#sthash.jKNG0ory.dpbs)XYX"sv, 613 },
}};


#if __has_embed("release_event_pic_orig_1859") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_orig_1859 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_orig_1859"
});
constexpr std::string_view release_event_mime_type_orig_1859 = "image/jpeg";
constexpr std::string_view release_event_file_ext_orig_1859 = "jpeg";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_orig_1859;
constexpr std::string_view release_event_mime_type_orig_1859 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_orig_1859;
#endif


#if __has_embed("release_event_pic_small_thumb_1859") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_small_thumb_1859 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_small_thumb_1859"
});
constexpr std::string_view release_event_mime_type_small_thumb_1859 = "image/png";
constexpr std::string_view release_event_file_ext_small_thumb_1859 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_small_thumb_1859;
constexpr std::string_view release_event_mime_type_small_thumb_1859 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_small_thumb_1859;
#endif


#if __has_embed("release_event_pic_thumb_1859") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_thumb_1859 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_thumb_1859"
});
constexpr std::string_view release_event_mime_type_thumb_1859 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_1859 = "???";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_thumb_1859;
constexpr std::string_view release_event_mime_type_thumb_1859 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_1859;
#endif


#if __has_embed("release_event_pic_tiny_thumb_1859") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_tiny_thumb_1859 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_tiny_thumb_1859"
});
constexpr std::string_view release_event_mime_type_tiny_thumb_1859 = "image/png";
constexpr std::string_view release_event_file_ext_tiny_thumb_1859 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_tiny_thumb_1859;
constexpr std::string_view release_event_mime_type_tiny_thumb_1859 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_tiny_thumb_1859;
#endif

constexpr picture picture_release_event_1859 = { R"XYX(image/jpeg)XYX"sv, std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/1859.jpg?v=5)XYX"sv, release_event_pic_orig_1859, release_event_mime_type_orig_1859, release_event_file_ext_orig_1859, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/1859.jpg?v=5)XYX"sv, release_event_pic_small_thumb_1859, release_event_mime_type_small_thumb_1859, release_event_file_ext_small_thumb_1859, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/1859.jpg?v=5)XYX"sv, release_event_pic_thumb_1859, release_event_mime_type_thumb_1859, release_event_file_ext_thumb_1859, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/1859.jpg?v=5)XYX"sv, release_event_pic_tiny_thumb_1859, release_event_mime_type_tiny_thumb_1859, release_event_file_ext_tiny_thumb_1859  };

constexpr std::array<additional_name, 1> names_release_event_1941 {{
  {"English"sv, R"XYX(Miku Expo 2016 New Taipei City)XYX"sv},
}};

constexpr std::array<web_link, 4> web_links_release_event_1941 {{
  {"Other"sv, R"XYX(Official website)XYX"sv, R"XYX(https://mikuexpo.com/tw2016/)XYX"sv, 966 },
  {"Official"sv, R"XYX(Facebook)XYX"sv, R"XYX(https://www.facebook.com/mikuexpo2016tw)XYX"sv, 967 },
  {"Other"sv, R"XYX(Mikufan)XYX"sv, R"XYX(https://www.mikufan.com/hatsune-miku-returns-to-taiwan-for-hatsune-miku-expo-2016-in-taiwan-on-stage-june-25th-26th/)XYX"sv, 968 },
  {"Reference"sv, R"XYX(Vocaloid Wiki)XYX"sv, R"XYX(https://vocaloid.fandom.com/wiki/HATSUNE_MIKU_EXPO_2016_in_TAIWAN)XYX"sv, 969 },
}};


#if __has_embed("release_event_pic_orig_1941") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_orig_1941 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_orig_1941"
});
constexpr std::string_view release_event_mime_type_orig_1941 = "image/png";
constexpr std::string_view release_event_file_ext_orig_1941 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_orig_1941;
constexpr std::string_view release_event_mime_type_orig_1941 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_orig_1941;
#endif


#if __has_embed("release_event_pic_small_thumb_1941") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_small_thumb_1941 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_small_thumb_1941"
});
constexpr std::string_view release_event_mime_type_small_thumb_1941 = "image/png";
constexpr std::string_view release_event_file_ext_small_thumb_1941 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_small_thumb_1941;
constexpr std::string_view release_event_mime_type_small_thumb_1941 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_small_thumb_1941;
#endif


#if __has_embed("release_event_pic_thumb_1941") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_thumb_1941 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_thumb_1941"
});
constexpr std::string_view release_event_mime_type_thumb_1941 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_1941 = "???";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_thumb_1941;
constexpr std::string_view release_event_mime_type_thumb_1941 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_1941;
#endif


#if __has_embed("release_event_pic_tiny_thumb_1941") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_tiny_thumb_1941 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_tiny_thumb_1941"
});
constexpr std::string_view release_event_mime_type_tiny_thumb_1941 = "image/png";
constexpr std::string_view release_event_file_ext_tiny_thumb_1941 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_tiny_thumb_1941;
constexpr std::string_view release_event_mime_type_tiny_thumb_1941 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_tiny_thumb_1941;
#endif

constexpr picture picture_release_event_1941 = { R"XYX(image/jpeg)XYX"sv, std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/1941.jpg?v=4)XYX"sv, release_event_pic_orig_1941, release_event_mime_type_orig_1941, release_event_file_ext_orig_1941, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/1941.jpg?v=4)XYX"sv, release_event_pic_small_thumb_1941, release_event_mime_type_small_thumb_1941, release_event_file_ext_small_thumb_1941, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/1941.jpg?v=4)XYX"sv, release_event_pic_thumb_1941, release_event_mime_type_thumb_1941, release_event_file_ext_thumb_1941, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/1941.jpg?v=4)XYX"sv, release_event_pic_tiny_thumb_1941, release_event_mime_type_tiny_thumb_1941, release_event_file_ext_tiny_thumb_1941  };

constexpr std::array<additional_name, 4> names_release_event_1398 {{
  {"Japanese"sv, R"XYX(初音ミク「マジカルミライ 2016」)XYX"sv},
  {"English"sv, R"XYX(Hatsune Miku Magical Mirai 2016)XYX"sv},
  {"Unspecified"sv, R"XYX(マジカルミライ 2016)XYX"sv},
  {"Unspecified"sv, R"XYX(Magical Mirai 2016)XYX"sv},
}};

constexpr std::array<web_link, 2> web_links_release_event_1398 {{
  {"Other"sv, R"XYX(Website (JP))XYX"sv, R"XYX(http://magicalmirai.com/2016/)XYX"sv, 192 },
  {"Other"sv, R"XYX(Website (EN))XYX"sv, R"XYX(https://magicalmirai.com/2016/index_en.php)XYX"sv, 1895 },
}};


#if __has_embed("release_event_pic_orig_1398") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_orig_1398 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_orig_1398"
});
constexpr std::string_view release_event_mime_type_orig_1398 = "image/png";
constexpr std::string_view release_event_file_ext_orig_1398 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_orig_1398;
constexpr std::string_view release_event_mime_type_orig_1398 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_orig_1398;
#endif


#if __has_embed("release_event_pic_small_thumb_1398") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_small_thumb_1398 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_small_thumb_1398"
});
constexpr std::string_view release_event_mime_type_small_thumb_1398 = "image/png";
constexpr std::string_view release_event_file_ext_small_thumb_1398 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_small_thumb_1398;
constexpr std::string_view release_event_mime_type_small_thumb_1398 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_small_thumb_1398;
#endif


#if __has_embed("release_event_pic_thumb_1398") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_thumb_1398 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_thumb_1398"
});
constexpr std::string_view release_event_mime_type_thumb_1398 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_1398 = "???";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_thumb_1398;
constexpr std::string_view release_event_mime_type_thumb_1398 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_1398;
#endif


#if __has_embed("release_event_pic_tiny_thumb_1398") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_tiny_thumb_1398 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_tiny_thumb_1398"
});
constexpr std::string_view release_event_mime_type_tiny_thumb_1398 = "image/png";
constexpr std::string_view release_event_file_ext_tiny_thumb_1398 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_tiny_thumb_1398;
constexpr std::string_view release_event_mime_type_tiny_thumb_1398 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_tiny_thumb_1398;
#endif

constexpr picture picture_release_event_1398 = { R"XYX(image/jpeg)XYX"sv, std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/1398.jpg?v=3)XYX"sv, release_event_pic_orig_1398, release_event_mime_type_orig_1398, release_event_file_ext_orig_1398, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/1398.jpg?v=3)XYX"sv, release_event_pic_small_thumb_1398, release_event_mime_type_small_thumb_1398, release_event_file_ext_small_thumb_1398, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/1398.jpg?v=3)XYX"sv, release_event_pic_thumb_1398, release_event_mime_type_thumb_1398, release_event_file_ext_thumb_1398, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/1398.jpg?v=3)XYX"sv, release_event_pic_tiny_thumb_1398, release_event_mime_type_tiny_thumb_1398, release_event_file_ext_tiny_thumb_1398  };

constexpr std::array<additional_name, 1> names_release_event_1943 {{
  {"English"sv, R"XYX(Miku Expo 2016 Shanghai)XYX"sv},
}};

constexpr std::array<web_link, 0> web_links_release_event_1943 {{
}};


#if __has_embed("release_event_pic_orig_1943") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_orig_1943 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_orig_1943"
});
constexpr std::string_view release_event_mime_type_orig_1943 = "image/png";
constexpr std::string_view release_event_file_ext_orig_1943 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_orig_1943;
constexpr std::string_view release_event_mime_type_orig_1943 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_orig_1943;
#endif


#if __has_embed("release_event_pic_small_thumb_1943") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_small_thumb_1943 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_small_thumb_1943"
});
constexpr std::string_view release_event_mime_type_small_thumb_1943 = "image/png";
constexpr std::string_view release_event_file_ext_small_thumb_1943 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_small_thumb_1943;
constexpr std::string_view release_event_mime_type_small_thumb_1943 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_small_thumb_1943;
#endif


#if __has_embed("release_event_pic_thumb_1943") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_thumb_1943 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_thumb_1943"
});
constexpr std::string_view release_event_mime_type_thumb_1943 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_1943 = "???";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_thumb_1943;
constexpr std::string_view release_event_mime_type_thumb_1943 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_1943;
#endif


#if __has_embed("release_event_pic_tiny_thumb_1943") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_tiny_thumb_1943 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_tiny_thumb_1943"
});
constexpr std::string_view release_event_mime_type_tiny_thumb_1943 = "image/png";
constexpr std::string_view release_event_file_ext_tiny_thumb_1943 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_tiny_thumb_1943;
constexpr std::string_view release_event_mime_type_tiny_thumb_1943 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_tiny_thumb_1943;
#endif

constexpr picture picture_release_event_1943 = { R"XYX(image/jpeg)XYX"sv, std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEventSeries/mainOrig/82.jpg?v=4)XYX"sv, release_event_pic_orig_1943, release_event_mime_type_orig_1943, release_event_file_ext_orig_1943, R"XYX(https://static.vocadb.net/img/ReleaseEventSeries/mainSmall/82.jpg?v=4)XYX"sv, release_event_pic_small_thumb_1943, release_event_mime_type_small_thumb_1943, release_event_file_ext_small_thumb_1943, R"XYX(https://static.vocadb.net/img/ReleaseEventSeries/mainThumb/82.jpg?v=4)XYX"sv, release_event_pic_thumb_1943, release_event_mime_type_thumb_1943, release_event_file_ext_thumb_1943, R"XYX(https://static.vocadb.net/img/ReleaseEventSeries/mainTiny/82.jpg?v=4)XYX"sv, release_event_pic_tiny_thumb_1943, release_event_mime_type_tiny_thumb_1943, release_event_file_ext_tiny_thumb_1943  };

constexpr std::array<additional_name, 4> names_release_event_2947 {{
  {"Japanese"sv, R"XYX(初音ミク×鼓童スペシャルライブ)XYX"sv},
  {"English"sv, R"XYX(Hatsune Miku × Kodō Special Live)XYX"sv},
  {"Unspecified"sv, R"XYX(初音ミク×鼓童　スペシャルライブ | Ｔｈｉｓ　ｉｓ　ＮＩＰＰＯＮ　プレミアムシアター)XYX"sv},
  {"Unspecified"sv, R"XYX(Hatsune Miku × Kodō Special Live | This is NIPPON Premium Theater)XYX"sv},
}};

constexpr std::array<web_link, 1> web_links_release_event_2947 {{
  {"Other"sv, R"XYX(Website)XYX"sv, R"XYX(https://kodo-miku.com/2017/index.html)XYX"sv, 1495 },
}};


#if __has_embed("release_event_pic_orig_2947") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_orig_2947 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_orig_2947"
});
constexpr std::string_view release_event_mime_type_orig_2947 = "image/png";
constexpr std::string_view release_event_file_ext_orig_2947 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_orig_2947;
constexpr std::string_view release_event_mime_type_orig_2947 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_orig_2947;
#endif


#if __has_embed("release_event_pic_small_thumb_2947") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_small_thumb_2947 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_small_thumb_2947"
});
constexpr std::string_view release_event_mime_type_small_thumb_2947 = "image/png";
constexpr std::string_view release_event_file_ext_small_thumb_2947 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_small_thumb_2947;
constexpr std::string_view release_event_mime_type_small_thumb_2947 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_small_thumb_2947;
#endif


#if __has_embed("release_event_pic_thumb_2947") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_thumb_2947 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_thumb_2947"
});
constexpr std::string_view release_event_mime_type_thumb_2947 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_2947 = "???";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_thumb_2947;
constexpr std::string_view release_event_mime_type_thumb_2947 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_2947;
#endif


#if __has_embed("release_event_pic_tiny_thumb_2947") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_tiny_thumb_2947 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_tiny_thumb_2947"
});
constexpr std::string_view release_event_mime_type_tiny_thumb_2947 = "image/png";
constexpr std::string_view release_event_file_ext_tiny_thumb_2947 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_tiny_thumb_2947;
constexpr std::string_view release_event_mime_type_tiny_thumb_2947 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_tiny_thumb_2947;
#endif

constexpr picture picture_release_event_2947 = { R"XYX(image/jpeg)XYX"sv, std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/2947.jpg?v=3)XYX"sv, release_event_pic_orig_2947, release_event_mime_type_orig_2947, release_event_file_ext_orig_2947, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/2947.jpg?v=3)XYX"sv, release_event_pic_small_thumb_2947, release_event_mime_type_small_thumb_2947, release_event_file_ext_small_thumb_2947, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/2947.jpg?v=3)XYX"sv, release_event_pic_thumb_2947, release_event_mime_type_thumb_2947, release_event_file_ext_thumb_2947, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/2947.jpg?v=3)XYX"sv, release_event_pic_tiny_thumb_2947, release_event_mime_type_tiny_thumb_2947, release_event_file_ext_tiny_thumb_2947  };

constexpr std::array<additional_name, 4> names_release_event_1397 {{
  {"Japanese"sv, R"XYX(初音ミク「マジカルミライ 2017」)XYX"sv},
  {"English"sv, R"XYX(Hatsune Miku Magical Mirai 2017)XYX"sv},
  {"Unspecified"sv, R"XYX(マジカルミライ 2017)XYX"sv},
  {"Unspecified"sv, R"XYX(Magical Mirai 2017)XYX"sv},
}};

constexpr std::array<web_link, 3> web_links_release_event_1397 {{
  {"Other"sv, R"XYX(Website (JP))XYX"sv, R"XYX(http://magicalmirai.com/2017/)XYX"sv, 191 },
  {"Other"sv, R"XYX(Website (EN))XYX"sv, R"XYX(http://magicalmirai.com/2017/index_en.html)XYX"sv, 193 },
  {"Reference"sv, R"XYX(Vocaloid Wiki)XYX"sv, R"XYX(http://vocaloid.wikia.com/wiki/Hatsune_Miku_Magical_Mirai_2017)XYX"sv, 354 },
}};


#if __has_embed("release_event_pic_orig_1397") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_orig_1397 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_orig_1397"
});
constexpr std::string_view release_event_mime_type_orig_1397 = "image/png";
constexpr std::string_view release_event_file_ext_orig_1397 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_orig_1397;
constexpr std::string_view release_event_mime_type_orig_1397 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_orig_1397;
#endif


#if __has_embed("release_event_pic_small_thumb_1397") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_small_thumb_1397 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_small_thumb_1397"
});
constexpr std::string_view release_event_mime_type_small_thumb_1397 = "image/png";
constexpr std::string_view release_event_file_ext_small_thumb_1397 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_small_thumb_1397;
constexpr std::string_view release_event_mime_type_small_thumb_1397 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_small_thumb_1397;
#endif


#if __has_embed("release_event_pic_thumb_1397") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_thumb_1397 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_thumb_1397"
});
constexpr std::string_view release_event_mime_type_thumb_1397 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_1397 = "???";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_thumb_1397;
constexpr std::string_view release_event_mime_type_thumb_1397 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_1397;
#endif


#if __has_embed("release_event_pic_tiny_thumb_1397") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_tiny_thumb_1397 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_tiny_thumb_1397"
});
constexpr std::string_view release_event_mime_type_tiny_thumb_1397 = "image/png";
constexpr std::string_view release_event_file_ext_tiny_thumb_1397 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_tiny_thumb_1397;
constexpr std::string_view release_event_mime_type_tiny_thumb_1397 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_tiny_thumb_1397;
#endif

constexpr picture picture_release_event_1397 = { R"XYX(image/jpeg)XYX"sv, std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/1397.jpg?v=13)XYX"sv, release_event_pic_orig_1397, release_event_mime_type_orig_1397, release_event_file_ext_orig_1397, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/1397.jpg?v=13)XYX"sv, release_event_pic_small_thumb_1397, release_event_mime_type_small_thumb_1397, release_event_file_ext_small_thumb_1397, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/1397.jpg?v=13)XYX"sv, release_event_pic_thumb_1397, release_event_mime_type_thumb_1397, release_event_file_ext_thumb_1397, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/1397.jpg?v=13)XYX"sv, release_event_pic_tiny_thumb_1397, release_event_mime_type_tiny_thumb_1397, release_event_file_ext_tiny_thumb_1397  };

constexpr std::array<additional_name, 3> names_release_event_1619 {{
  {"Unspecified"sv, R"XYX(未来（ミク）には君がいる·初音ミク２０１７上海ライブ)XYX"sv},
  {"Japanese"sv, R"XYX(未来有你·初音未来 2017 上海演唱会)XYX"sv},
  {"English"sv, R"XYX(HATSUNE MIKU with YOU 2017 CHINA FESTIVAL)XYX"sv},
}};

constexpr std::array<web_link, 4> web_links_release_event_1619 {{
  {"Other"sv, R"XYX(Announcement)XYX"sv, R"XYX(https://mp.weixin.qq.com/s/Tuec1cbKO9EzjGxTWht1sg)XYX"sv, 409 },
  {"Other"sv, R"XYX(Website)XYX"sv, R"XYX(https://www.scla.com.cn/events/hatsunemiku2017/)XYX"sv, 447 },
  {"Other"sv, R"XYX(Moegirlpedia)XYX"sv, R"XYX(https://zh.moegirl.org.cn/%E6%9C%AA%E6%9D%A5%E6%9C%89%E4%BD%A0%C2%B7%E5%88%9D%E9%9F%B3%E6%9C%AA%E6%9D%A52017%E6%BC%94%E5%94%B1%E4%BC%9A)XYX"sv, 1852 },
  {"Other"sv, R"XYX(HATSUNE MIKU OFFICIAL BLOG)XYX"sv, R"XYX(https://blog.piapro.net/2017/11/mon171120.html)XYX"sv, 1853 },
}};


#if __has_embed("release_event_pic_orig_1619") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_orig_1619 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_orig_1619"
});
constexpr std::string_view release_event_mime_type_orig_1619 = "image/png";
constexpr std::string_view release_event_file_ext_orig_1619 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_orig_1619;
constexpr std::string_view release_event_mime_type_orig_1619 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_orig_1619;
#endif


#if __has_embed("release_event_pic_small_thumb_1619") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_small_thumb_1619 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_small_thumb_1619"
});
constexpr std::string_view release_event_mime_type_small_thumb_1619 = "image/png";
constexpr std::string_view release_event_file_ext_small_thumb_1619 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_small_thumb_1619;
constexpr std::string_view release_event_mime_type_small_thumb_1619 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_small_thumb_1619;
#endif


#if __has_embed("release_event_pic_thumb_1619") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_thumb_1619 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_thumb_1619"
});
constexpr std::string_view release_event_mime_type_thumb_1619 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_1619 = "???";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_thumb_1619;
constexpr std::string_view release_event_mime_type_thumb_1619 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_1619;
#endif


#if __has_embed("release_event_pic_tiny_thumb_1619") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_tiny_thumb_1619 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_tiny_thumb_1619"
});
constexpr std::string_view release_event_mime_type_tiny_thumb_1619 = "image/png";
constexpr std::string_view release_event_file_ext_tiny_thumb_1619 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_tiny_thumb_1619;
constexpr std::string_view release_event_mime_type_tiny_thumb_1619 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_tiny_thumb_1619;
#endif

constexpr picture picture_release_event_1619 = { R"XYX(image/jpeg)XYX"sv, std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/1619.jpg?v=13)XYX"sv, release_event_pic_orig_1619, release_event_mime_type_orig_1619, release_event_file_ext_orig_1619, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/1619.jpg?v=13)XYX"sv, release_event_pic_small_thumb_1619, release_event_mime_type_small_thumb_1619, release_event_file_ext_small_thumb_1619, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/1619.jpg?v=13)XYX"sv, release_event_pic_thumb_1619, release_event_mime_type_thumb_1619, release_event_file_ext_thumb_1619, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/1619.jpg?v=13)XYX"sv, release_event_pic_tiny_thumb_1619, release_event_mime_type_tiny_thumb_1619, release_event_file_ext_tiny_thumb_1619  };

constexpr std::array<additional_name, 1> names_release_event_1584 {{
  {"English"sv, R"XYX(Miku Expo 2017 Kuala Lumpur)XYX"sv},
}};

constexpr std::array<web_link, 2> web_links_release_event_1584 {{
  {"Other"sv, R"XYX(Website)XYX"sv, R"XYX(http://mikuexpo.com/may2017/)XYX"sv, 377 },
  {"Other"sv, R"XYX(Youtube official highlights)XYX"sv, R"XYX(https://www.youtube.com/watch?v=AJEKjAaIp84)XYX"sv, 469 },
}};


#if __has_embed("release_event_pic_orig_1584") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_orig_1584 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_orig_1584"
});
constexpr std::string_view release_event_mime_type_orig_1584 = "image/png";
constexpr std::string_view release_event_file_ext_orig_1584 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_orig_1584;
constexpr std::string_view release_event_mime_type_orig_1584 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_orig_1584;
#endif


#if __has_embed("release_event_pic_small_thumb_1584") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_small_thumb_1584 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_small_thumb_1584"
});
constexpr std::string_view release_event_mime_type_small_thumb_1584 = "image/png";
constexpr std::string_view release_event_file_ext_small_thumb_1584 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_small_thumb_1584;
constexpr std::string_view release_event_mime_type_small_thumb_1584 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_small_thumb_1584;
#endif


#if __has_embed("release_event_pic_thumb_1584") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_thumb_1584 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_thumb_1584"
});
constexpr std::string_view release_event_mime_type_thumb_1584 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_1584 = "???";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_thumb_1584;
constexpr std::string_view release_event_mime_type_thumb_1584 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_1584;
#endif


#if __has_embed("release_event_pic_tiny_thumb_1584") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_tiny_thumb_1584 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_tiny_thumb_1584"
});
constexpr std::string_view release_event_mime_type_tiny_thumb_1584 = "image/png";
constexpr std::string_view release_event_file_ext_tiny_thumb_1584 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_tiny_thumb_1584;
constexpr std::string_view release_event_mime_type_tiny_thumb_1584 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_tiny_thumb_1584;
#endif

constexpr picture picture_release_event_1584 = { R"XYX(image/png)XYX"sv, std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/1584.png?v=6)XYX"sv, release_event_pic_orig_1584, release_event_mime_type_orig_1584, release_event_file_ext_orig_1584, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/1584.png?v=6)XYX"sv, release_event_pic_small_thumb_1584, release_event_mime_type_small_thumb_1584, release_event_file_ext_small_thumb_1584, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/1584.png?v=6)XYX"sv, release_event_pic_thumb_1584, release_event_mime_type_thumb_1584, release_event_file_ext_thumb_1584, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/1584.png?v=6)XYX"sv, release_event_pic_tiny_thumb_1584, release_event_mime_type_tiny_thumb_1584, release_event_file_ext_tiny_thumb_1584  };

constexpr std::array<additional_name, 1> names_release_event_1618 {{
  {"English"sv, R"XYX(SNOW MIKU LIVE! 2018)XYX"sv},
}};

constexpr std::array<web_link, 1> web_links_release_event_1618 {{
  {"Other"sv, R"XYX(Website)XYX"sv, R"XYX(http://snowmiku.com/2018/live_ticket.html)XYX"sv, 407 },
}};


#if __has_embed("release_event_pic_orig_1618") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_orig_1618 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_orig_1618"
});
constexpr std::string_view release_event_mime_type_orig_1618 = "image/png";
constexpr std::string_view release_event_file_ext_orig_1618 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_orig_1618;
constexpr std::string_view release_event_mime_type_orig_1618 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_orig_1618;
#endif


#if __has_embed("release_event_pic_small_thumb_1618") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_small_thumb_1618 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_small_thumb_1618"
});
constexpr std::string_view release_event_mime_type_small_thumb_1618 = "image/png";
constexpr std::string_view release_event_file_ext_small_thumb_1618 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_small_thumb_1618;
constexpr std::string_view release_event_mime_type_small_thumb_1618 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_small_thumb_1618;
#endif


#if __has_embed("release_event_pic_thumb_1618") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_thumb_1618 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_thumb_1618"
});
constexpr std::string_view release_event_mime_type_thumb_1618 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_1618 = "???";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_thumb_1618;
constexpr std::string_view release_event_mime_type_thumb_1618 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_1618;
#endif


#if __has_embed("release_event_pic_tiny_thumb_1618") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_tiny_thumb_1618 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_tiny_thumb_1618"
});
constexpr std::string_view release_event_mime_type_tiny_thumb_1618 = "image/png";
constexpr std::string_view release_event_file_ext_tiny_thumb_1618 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_tiny_thumb_1618;
constexpr std::string_view release_event_mime_type_tiny_thumb_1618 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_tiny_thumb_1618;
#endif

constexpr picture picture_release_event_1618 = { R"XYX(image/jpeg)XYX"sv, std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/1618.jpg?v=6)XYX"sv, release_event_pic_orig_1618, release_event_mime_type_orig_1618, release_event_file_ext_orig_1618, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/1618.jpg?v=6)XYX"sv, release_event_pic_small_thumb_1618, release_event_mime_type_small_thumb_1618, release_event_file_ext_small_thumb_1618, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/1618.jpg?v=6)XYX"sv, release_event_pic_thumb_1618, release_event_mime_type_thumb_1618, release_event_file_ext_thumb_1618, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/1618.jpg?v=6)XYX"sv, release_event_pic_tiny_thumb_1618, release_event_mime_type_tiny_thumb_1618, release_event_file_ext_tiny_thumb_1618  };

constexpr std::array<additional_name, 2> names_release_event_2948 {{
  {"Japanese"sv, R"XYX(Ｔｈｉｓ　ｉｓ　ＮＩＰＰＯＮ　プレミアムシアター 初音ミク×鼓童　スペシャルライブ　２０１８)XYX"sv},
  {"English"sv, R"XYX(This is NIPPON Premium Theater Hatsune Miku × Kodō Special Live 2018)XYX"sv},
}};

constexpr std::array<web_link, 1> web_links_release_event_2948 {{
  {"Other"sv, R"XYX(Website)XYX"sv, R"XYX(https://kodo-miku.com/2018/index.html)XYX"sv, 1496 },
}};


#if __has_embed("release_event_pic_orig_2948") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_orig_2948 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_orig_2948"
});
constexpr std::string_view release_event_mime_type_orig_2948 = "image/png";
constexpr std::string_view release_event_file_ext_orig_2948 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_orig_2948;
constexpr std::string_view release_event_mime_type_orig_2948 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_orig_2948;
#endif


#if __has_embed("release_event_pic_small_thumb_2948") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_small_thumb_2948 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_small_thumb_2948"
});
constexpr std::string_view release_event_mime_type_small_thumb_2948 = "image/png";
constexpr std::string_view release_event_file_ext_small_thumb_2948 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_small_thumb_2948;
constexpr std::string_view release_event_mime_type_small_thumb_2948 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_small_thumb_2948;
#endif


#if __has_embed("release_event_pic_thumb_2948") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_thumb_2948 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_thumb_2948"
});
constexpr std::string_view release_event_mime_type_thumb_2948 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_2948 = "???";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_thumb_2948;
constexpr std::string_view release_event_mime_type_thumb_2948 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_2948;
#endif


#if __has_embed("release_event_pic_tiny_thumb_2948") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_tiny_thumb_2948 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_tiny_thumb_2948"
});
constexpr std::string_view release_event_mime_type_tiny_thumb_2948 = "image/png";
constexpr std::string_view release_event_file_ext_tiny_thumb_2948 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_tiny_thumb_2948;
constexpr std::string_view release_event_mime_type_tiny_thumb_2948 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_tiny_thumb_2948;
#endif

constexpr picture picture_release_event_2948 = { R"XYX(image/jpeg)XYX"sv, std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/2948.jpg?v=5)XYX"sv, release_event_pic_orig_2948, release_event_mime_type_orig_2948, release_event_file_ext_orig_2948, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/2948.jpg?v=5)XYX"sv, release_event_pic_small_thumb_2948, release_event_mime_type_small_thumb_2948, release_event_file_ext_small_thumb_2948, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/2948.jpg?v=5)XYX"sv, release_event_pic_thumb_2948, release_event_mime_type_thumb_2948, release_event_file_ext_thumb_2948, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/2948.jpg?v=5)XYX"sv, release_event_pic_tiny_thumb_2948, release_event_mime_type_tiny_thumb_2948, release_event_file_ext_tiny_thumb_2948  };

constexpr std::array<additional_name, 1> names_release_event_1673 {{
  {"English"sv, R"XYX(Miku Expo 2018 Los Angeles)XYX"sv},
}};

constexpr std::array<web_link, 0> web_links_release_event_1673 {{
}};


#if __has_embed("release_event_pic_orig_1673") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_orig_1673 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_orig_1673"
});
constexpr std::string_view release_event_mime_type_orig_1673 = "image/png";
constexpr std::string_view release_event_file_ext_orig_1673 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_orig_1673;
constexpr std::string_view release_event_mime_type_orig_1673 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_orig_1673;
#endif


#if __has_embed("release_event_pic_small_thumb_1673") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_small_thumb_1673 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_small_thumb_1673"
});
constexpr std::string_view release_event_mime_type_small_thumb_1673 = "image/png";
constexpr std::string_view release_event_file_ext_small_thumb_1673 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_small_thumb_1673;
constexpr std::string_view release_event_mime_type_small_thumb_1673 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_small_thumb_1673;
#endif


#if __has_embed("release_event_pic_thumb_1673") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_thumb_1673 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_thumb_1673"
});
constexpr std::string_view release_event_mime_type_thumb_1673 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_1673 = "???";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_thumb_1673;
constexpr std::string_view release_event_mime_type_thumb_1673 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_1673;
#endif


#if __has_embed("release_event_pic_tiny_thumb_1673") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_tiny_thumb_1673 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_tiny_thumb_1673"
});
constexpr std::string_view release_event_mime_type_tiny_thumb_1673 = "image/png";
constexpr std::string_view release_event_file_ext_tiny_thumb_1673 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_tiny_thumb_1673;
constexpr std::string_view release_event_mime_type_tiny_thumb_1673 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_tiny_thumb_1673;
#endif

constexpr picture picture_release_event_1673 = { R"XYX(image/jpeg)XYX"sv, std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/1673.jpg?v=3)XYX"sv, release_event_pic_orig_1673, release_event_mime_type_orig_1673, release_event_file_ext_orig_1673, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/1673.jpg?v=3)XYX"sv, release_event_pic_small_thumb_1673, release_event_mime_type_small_thumb_1673, release_event_file_ext_small_thumb_1673, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/1673.jpg?v=3)XYX"sv, release_event_pic_thumb_1673, release_event_mime_type_thumb_1673, release_event_file_ext_thumb_1673, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/1673.jpg?v=3)XYX"sv, release_event_pic_tiny_thumb_1673, release_event_mime_type_tiny_thumb_1673, release_event_file_ext_tiny_thumb_1673  };

constexpr std::array<additional_name, 4> names_release_event_1561 {{
  {"Japanese"sv, R"XYX(初音ミク「マジカルミライ 2018」in OSAKA)XYX"sv},
  {"English"sv, R"XYX(Hatsune Miku Magical Mirai 2018 in OSAKA)XYX"sv},
  {"Unspecified"sv, R"XYX(マジカルミライ 2018 Osaka)XYX"sv},
  {"Unspecified"sv, R"XYX(Magical Mirai 2018 Osaka)XYX"sv},
}};

constexpr std::array<web_link, 4> web_links_release_event_1561 {{
  {"Other"sv, R"XYX(Website (JP))XYX"sv, R"XYX(http://magicalmirai.com/2018/)XYX"sv, 355 },
  {"Other"sv, R"XYX(Website (EN))XYX"sv, R"XYX(http://magicalmirai.com/2018/index_en.html)XYX"sv, 526 },
  {"Other"sv, R"XYX(Website - OSAKA (EN))XYX"sv, R"XYX(https://magicalmirai.com/2018/osaka_top_en.html)XYX"sv, 1891 },
  {"Other"sv, R"XYX(Website - OSAKA (JP))XYX"sv, R"XYX(https://magicalmirai.com/2018/osaka_top.html)XYX"sv, 1892 },
}};


#if __has_embed("release_event_pic_orig_1561") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_orig_1561 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_orig_1561"
});
constexpr std::string_view release_event_mime_type_orig_1561 = "image/png";
constexpr std::string_view release_event_file_ext_orig_1561 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_orig_1561;
constexpr std::string_view release_event_mime_type_orig_1561 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_orig_1561;
#endif


#if __has_embed("release_event_pic_small_thumb_1561") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_small_thumb_1561 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_small_thumb_1561"
});
constexpr std::string_view release_event_mime_type_small_thumb_1561 = "image/png";
constexpr std::string_view release_event_file_ext_small_thumb_1561 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_small_thumb_1561;
constexpr std::string_view release_event_mime_type_small_thumb_1561 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_small_thumb_1561;
#endif


#if __has_embed("release_event_pic_thumb_1561") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_thumb_1561 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_thumb_1561"
});
constexpr std::string_view release_event_mime_type_thumb_1561 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_1561 = "???";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_thumb_1561;
constexpr std::string_view release_event_mime_type_thumb_1561 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_1561;
#endif


#if __has_embed("release_event_pic_tiny_thumb_1561") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_tiny_thumb_1561 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_tiny_thumb_1561"
});
constexpr std::string_view release_event_mime_type_tiny_thumb_1561 = "image/png";
constexpr std::string_view release_event_file_ext_tiny_thumb_1561 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_tiny_thumb_1561;
constexpr std::string_view release_event_mime_type_tiny_thumb_1561 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_tiny_thumb_1561;
#endif

constexpr picture picture_release_event_1561 = { R"XYX(image/jpeg)XYX"sv, std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/1561.jpg?v=13)XYX"sv, release_event_pic_orig_1561, release_event_mime_type_orig_1561, release_event_file_ext_orig_1561, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/1561.jpg?v=13)XYX"sv, release_event_pic_small_thumb_1561, release_event_mime_type_small_thumb_1561, release_event_file_ext_small_thumb_1561, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/1561.jpg?v=13)XYX"sv, release_event_pic_thumb_1561, release_event_mime_type_thumb_1561, release_event_file_ext_thumb_1561, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/1561.jpg?v=13)XYX"sv, release_event_pic_tiny_thumb_1561, release_event_mime_type_tiny_thumb_1561, release_event_file_ext_tiny_thumb_1561  };

constexpr std::array<additional_name, 3> names_release_event_2085 {{
  {"English"sv, R"XYX(MIKU WITH YOU 2018 in Beijing)XYX"sv},
  {"Japanese"sv, R"XYX(未来有你 2018 in Beijing)XYX"sv},
  {"Unspecified"sv, R"XYX(HATSUNE MIKU WITH YOU 2018 in Beijing)XYX"sv},
}};

constexpr std::array<web_link, 3> web_links_release_event_2085 {{
  {"Other"sv, R"XYX(Website)XYX"sv, R"XYX(http://www.scla.com.cn/events/hatsunemiku2018/)XYX"sv, 812 },
  {"Other"sv, R"XYX(Mikufan.com)XYX"sv, R"XYX(https://www.mikufan.com/miku-with-you-2018-china-tour-starts-oct-13th-locations-dates-announced)XYX"sv, 814 },
  {"Reference"sv, R"XYX(Vocaloid Wiki)XYX"sv, R"XYX(http://vocaloid.wikia.com/wiki/MIKU_WITH_YOU_2018)XYX"sv, 910 },
}};


#if __has_embed("release_event_pic_orig_2085") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_orig_2085 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_orig_2085"
});
constexpr std::string_view release_event_mime_type_orig_2085 = "image/png";
constexpr std::string_view release_event_file_ext_orig_2085 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_orig_2085;
constexpr std::string_view release_event_mime_type_orig_2085 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_orig_2085;
#endif


#if __has_embed("release_event_pic_small_thumb_2085") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_small_thumb_2085 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_small_thumb_2085"
});
constexpr std::string_view release_event_mime_type_small_thumb_2085 = "image/png";
constexpr std::string_view release_event_file_ext_small_thumb_2085 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_small_thumb_2085;
constexpr std::string_view release_event_mime_type_small_thumb_2085 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_small_thumb_2085;
#endif


#if __has_embed("release_event_pic_thumb_2085") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_thumb_2085 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_thumb_2085"
});
constexpr std::string_view release_event_mime_type_thumb_2085 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_2085 = "???";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_thumb_2085;
constexpr std::string_view release_event_mime_type_thumb_2085 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_2085;
#endif


#if __has_embed("release_event_pic_tiny_thumb_2085") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_tiny_thumb_2085 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_tiny_thumb_2085"
});
constexpr std::string_view release_event_mime_type_tiny_thumb_2085 = "image/png";
constexpr std::string_view release_event_file_ext_tiny_thumb_2085 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_tiny_thumb_2085;
constexpr std::string_view release_event_mime_type_tiny_thumb_2085 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_tiny_thumb_2085;
#endif

constexpr picture picture_release_event_2085 = { R"XYX(image/jpeg)XYX"sv, std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/2085.jpg?v=14)XYX"sv, release_event_pic_orig_2085, release_event_mime_type_orig_2085, release_event_file_ext_orig_2085, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/2085.jpg?v=14)XYX"sv, release_event_pic_small_thumb_2085, release_event_mime_type_small_thumb_2085, release_event_file_ext_small_thumb_2085, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/2085.jpg?v=14)XYX"sv, release_event_pic_thumb_2085, release_event_mime_type_thumb_2085, release_event_file_ext_thumb_2085, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/2085.jpg?v=14)XYX"sv, release_event_pic_tiny_thumb_2085, release_event_mime_type_tiny_thumb_2085, release_event_file_ext_tiny_thumb_2085  };

constexpr std::array<additional_name, 1> names_release_event_1854 {{
  {"English"sv, R"XYX(Miku Expo 2018 Paris)XYX"sv},
}};

constexpr std::array<web_link, 3> web_links_release_event_1854 {{
  {"Other"sv, R"XYX(Website)XYX"sv, R"XYX(http://mikuexpo.com/europe2018/)XYX"sv, 607 },
  {"Other"sv, R"XYX(Japonismes)XYX"sv, R"XYX(https://japonismes.org/)XYX"sv, 628 },
  {"Reference"sv, R"XYX(Vocaloid Wiki)XYX"sv, R"XYX(http://vocaloid.wikia.com/wiki/HATSUNE_MIKU_EXPO_2018_EUROPE)XYX"sv, 906 },
}};


#if __has_embed("release_event_pic_orig_1854") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_orig_1854 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_orig_1854"
});
constexpr std::string_view release_event_mime_type_orig_1854 = "image/png";
constexpr std::string_view release_event_file_ext_orig_1854 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_orig_1854;
constexpr std::string_view release_event_mime_type_orig_1854 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_orig_1854;
#endif


#if __has_embed("release_event_pic_small_thumb_1854") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_small_thumb_1854 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_small_thumb_1854"
});
constexpr std::string_view release_event_mime_type_small_thumb_1854 = "image/png";
constexpr std::string_view release_event_file_ext_small_thumb_1854 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_small_thumb_1854;
constexpr std::string_view release_event_mime_type_small_thumb_1854 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_small_thumb_1854;
#endif


#if __has_embed("release_event_pic_thumb_1854") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_thumb_1854 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_thumb_1854"
});
constexpr std::string_view release_event_mime_type_thumb_1854 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_1854 = "???";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_thumb_1854;
constexpr std::string_view release_event_mime_type_thumb_1854 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_1854;
#endif


#if __has_embed("release_event_pic_tiny_thumb_1854") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_tiny_thumb_1854 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_tiny_thumb_1854"
});
constexpr std::string_view release_event_mime_type_tiny_thumb_1854 = "image/png";
constexpr std::string_view release_event_file_ext_tiny_thumb_1854 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_tiny_thumb_1854;
constexpr std::string_view release_event_mime_type_tiny_thumb_1854 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_tiny_thumb_1854;
#endif

constexpr picture picture_release_event_1854 = { R"XYX(image/png)XYX"sv, std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/1854.png?v=7)XYX"sv, release_event_pic_orig_1854, release_event_mime_type_orig_1854, release_event_file_ext_orig_1854, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/1854.png?v=7)XYX"sv, release_event_pic_small_thumb_1854, release_event_mime_type_small_thumb_1854, release_event_file_ext_small_thumb_1854, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/1854.png?v=7)XYX"sv, release_event_pic_thumb_1854, release_event_mime_type_thumb_1854, release_event_file_ext_thumb_1854, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/1854.png?v=7)XYX"sv, release_event_pic_tiny_thumb_1854, release_event_mime_type_tiny_thumb_1854, release_event_file_ext_tiny_thumb_1854  };

constexpr std::array<additional_name, 1> names_release_event_2422 {{
  {"English"sv, R"XYX(SNOW MIKU LIVE! 2019)XYX"sv},
}};

constexpr std::array<web_link, 2> web_links_release_event_2422 {{
  {"Other"sv, R"XYX(Mikufan.com)XYX"sv, R"XYX(https://www.mikufan.com/snow-miku-2019-main-visual-by-kei-snow-miku-live-2019-theme-song-preview-more/#sthash.253HD46r.dpbs)XYX"sv, 876 },
  {"Other"sv, R"XYX(Website)XYX"sv, R"XYX(https://snowmiku.com/2019/live_zepp.html)XYX"sv, 877 },
}};


#if __has_embed("release_event_pic_orig_2422") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_orig_2422 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_orig_2422"
});
constexpr std::string_view release_event_mime_type_orig_2422 = "image/png";
constexpr std::string_view release_event_file_ext_orig_2422 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_orig_2422;
constexpr std::string_view release_event_mime_type_orig_2422 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_orig_2422;
#endif


#if __has_embed("release_event_pic_small_thumb_2422") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_small_thumb_2422 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_small_thumb_2422"
});
constexpr std::string_view release_event_mime_type_small_thumb_2422 = "image/png";
constexpr std::string_view release_event_file_ext_small_thumb_2422 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_small_thumb_2422;
constexpr std::string_view release_event_mime_type_small_thumb_2422 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_small_thumb_2422;
#endif


#if __has_embed("release_event_pic_thumb_2422") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_thumb_2422 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_thumb_2422"
});
constexpr std::string_view release_event_mime_type_thumb_2422 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_2422 = "???";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_thumb_2422;
constexpr std::string_view release_event_mime_type_thumb_2422 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_2422;
#endif


#if __has_embed("release_event_pic_tiny_thumb_2422") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_tiny_thumb_2422 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_tiny_thumb_2422"
});
constexpr std::string_view release_event_mime_type_tiny_thumb_2422 = "image/png";
constexpr std::string_view release_event_file_ext_tiny_thumb_2422 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_tiny_thumb_2422;
constexpr std::string_view release_event_mime_type_tiny_thumb_2422 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_tiny_thumb_2422;
#endif

constexpr picture picture_release_event_2422 = { R"XYX(image/jpeg)XYX"sv, std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/2422.jpg?v=14)XYX"sv, release_event_pic_orig_2422, release_event_mime_type_orig_2422, release_event_file_ext_orig_2422, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/2422.jpg?v=14)XYX"sv, release_event_pic_small_thumb_2422, release_event_mime_type_small_thumb_2422, release_event_file_ext_small_thumb_2422, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/2422.jpg?v=14)XYX"sv, release_event_pic_thumb_2422, release_event_mime_type_thumb_2422, release_event_file_ext_thumb_2422, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/2422.jpg?v=14)XYX"sv, release_event_pic_tiny_thumb_2422, release_event_mime_type_tiny_thumb_2422, release_event_file_ext_tiny_thumb_2422  };

constexpr std::array<additional_name, 1> names_release_event_2489 {{
  {"English"sv, R"XYX(Miku Expo 2019 New Taipei City)XYX"sv},
}};

constexpr std::array<web_link, 1> web_links_release_event_2489 {{
  {"Other"sv, R"XYX(Mikufan.com)XYX"sv, R"XYX(https://www.mikufan.com/hatsune-miku-expo-2019-in-taiwan-finishes-concert-setlist-revealed/)XYX"sv, 1140 },
}};


#if __has_embed("release_event_pic_orig_2489") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_orig_2489 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_orig_2489"
});
constexpr std::string_view release_event_mime_type_orig_2489 = "image/png";
constexpr std::string_view release_event_file_ext_orig_2489 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_orig_2489;
constexpr std::string_view release_event_mime_type_orig_2489 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_orig_2489;
#endif


#if __has_embed("release_event_pic_small_thumb_2489") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_small_thumb_2489 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_small_thumb_2489"
});
constexpr std::string_view release_event_mime_type_small_thumb_2489 = "image/png";
constexpr std::string_view release_event_file_ext_small_thumb_2489 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_small_thumb_2489;
constexpr std::string_view release_event_mime_type_small_thumb_2489 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_small_thumb_2489;
#endif


#if __has_embed("release_event_pic_thumb_2489") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_thumb_2489 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_thumb_2489"
});
constexpr std::string_view release_event_mime_type_thumb_2489 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_2489 = "???";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_thumb_2489;
constexpr std::string_view release_event_mime_type_thumb_2489 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_2489;
#endif


#if __has_embed("release_event_pic_tiny_thumb_2489") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_tiny_thumb_2489 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_tiny_thumb_2489"
});
constexpr std::string_view release_event_mime_type_tiny_thumb_2489 = "image/png";
constexpr std::string_view release_event_file_ext_tiny_thumb_2489 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_tiny_thumb_2489;
constexpr std::string_view release_event_mime_type_tiny_thumb_2489 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_tiny_thumb_2489;
#endif

constexpr picture picture_release_event_2489 = { R"XYX(image/jpeg)XYX"sv, std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/2489.jpg?v=5)XYX"sv, release_event_pic_orig_2489, release_event_mime_type_orig_2489, release_event_file_ext_orig_2489, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/2489.jpg?v=5)XYX"sv, release_event_pic_small_thumb_2489, release_event_mime_type_small_thumb_2489, release_event_file_ext_small_thumb_2489, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/2489.jpg?v=5)XYX"sv, release_event_pic_thumb_2489, release_event_mime_type_thumb_2489, release_event_file_ext_thumb_2489, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/2489.jpg?v=5)XYX"sv, release_event_pic_tiny_thumb_2489, release_event_mime_type_tiny_thumb_2489, release_event_file_ext_tiny_thumb_2489  };

constexpr std::array<additional_name, 4> names_release_event_2515 {{
  {"Japanese"sv, R"XYX(初音ミク「マジカルミライ 2019」in OSAKA)XYX"sv},
  {"English"sv, R"XYX(Hatsune Miku Magical Mirai 2019 in OSAKA)XYX"sv},
  {"Unspecified"sv, R"XYX(マジカルミライ 2019 Osaka)XYX"sv},
  {"Unspecified"sv, R"XYX(Magical Mirai 2019 Osaka)XYX"sv},
}};

constexpr std::array<web_link, 4> web_links_release_event_2515 {{
  {"Other"sv, R"XYX(Website (JP))XYX"sv, R"XYX(https://magicalmirai.com/2019/)XYX"sv, 1883 },
  {"Other"sv, R"XYX(Website (EN))XYX"sv, R"XYX(https://magicalmirai.com/2019/index_en.html)XYX"sv, 1884 },
  {"Other"sv, R"XYX(Website - OSAKA (JP))XYX"sv, R"XYX(https://magicalmirai.com/2019/osaka_top.html)XYX"sv, 1885 },
  {"Other"sv, R"XYX(Website - OSAKA (EN))XYX"sv, R"XYX(https://magicalmirai.com/2019/osaka_top_en.html)XYX"sv, 1886 },
}};


#if __has_embed("release_event_pic_orig_2515") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_orig_2515 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_orig_2515"
});
constexpr std::string_view release_event_mime_type_orig_2515 = "image/png";
constexpr std::string_view release_event_file_ext_orig_2515 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_orig_2515;
constexpr std::string_view release_event_mime_type_orig_2515 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_orig_2515;
#endif


#if __has_embed("release_event_pic_small_thumb_2515") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_small_thumb_2515 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_small_thumb_2515"
});
constexpr std::string_view release_event_mime_type_small_thumb_2515 = "image/png";
constexpr std::string_view release_event_file_ext_small_thumb_2515 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_small_thumb_2515;
constexpr std::string_view release_event_mime_type_small_thumb_2515 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_small_thumb_2515;
#endif


#if __has_embed("release_event_pic_thumb_2515") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_thumb_2515 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_thumb_2515"
});
constexpr std::string_view release_event_mime_type_thumb_2515 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_2515 = "???";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_thumb_2515;
constexpr std::string_view release_event_mime_type_thumb_2515 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_2515;
#endif


#if __has_embed("release_event_pic_tiny_thumb_2515") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_tiny_thumb_2515 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_tiny_thumb_2515"
});
constexpr std::string_view release_event_mime_type_tiny_thumb_2515 = "image/png";
constexpr std::string_view release_event_file_ext_tiny_thumb_2515 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_tiny_thumb_2515;
constexpr std::string_view release_event_mime_type_tiny_thumb_2515 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_tiny_thumb_2515;
#endif

constexpr picture picture_release_event_2515 = { R"XYX(image/jpeg)XYX"sv, std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/2515.jpg?v=7)XYX"sv, release_event_pic_orig_2515, release_event_mime_type_orig_2515, release_event_file_ext_orig_2515, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/2515.jpg?v=7)XYX"sv, release_event_pic_small_thumb_2515, release_event_mime_type_small_thumb_2515, release_event_file_ext_small_thumb_2515, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/2515.jpg?v=7)XYX"sv, release_event_pic_thumb_2515, release_event_mime_type_thumb_2515, release_event_file_ext_thumb_2515, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/2515.jpg?v=7)XYX"sv, release_event_pic_tiny_thumb_2515, release_event_mime_type_tiny_thumb_2515, release_event_file_ext_tiny_thumb_2515  };

constexpr std::array<additional_name, 3> names_release_event_3752 {{
  {"English"sv, R"XYX(MIKU WITH YOU 2019 in Shanghai)XYX"sv},
  {"Japanese"sv, R"XYX(未来有你 2019 in Shanghai)XYX"sv},
  {"Unspecified"sv, R"XYX(HATSUNE MIKU WITH YOU 2019 in Shanghai)XYX"sv},
}};

constexpr std::array<web_link, 2> web_links_release_event_3752 {{
  {"Other"sv, R"XYX(Website)XYX"sv, R"XYX(https://www.scla.com.cn/events/hatsunemiku2019/)XYX"sv, 1844 },
  {"Other"sv, R"XYX(Mikufan.com)XYX"sv, R"XYX(https://www.mikufan.com/miku-with-you-2019-live-performance-confirmed-for-shanghai-four-main-visuals-revealed/)XYX"sv, 1845 },
}};


#if __has_embed("release_event_pic_orig_3752") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_orig_3752 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_orig_3752"
});
constexpr std::string_view release_event_mime_type_orig_3752 = "image/png";
constexpr std::string_view release_event_file_ext_orig_3752 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_orig_3752;
constexpr std::string_view release_event_mime_type_orig_3752 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_orig_3752;
#endif


#if __has_embed("release_event_pic_small_thumb_3752") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_small_thumb_3752 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_small_thumb_3752"
});
constexpr std::string_view release_event_mime_type_small_thumb_3752 = "image/png";
constexpr std::string_view release_event_file_ext_small_thumb_3752 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_small_thumb_3752;
constexpr std::string_view release_event_mime_type_small_thumb_3752 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_small_thumb_3752;
#endif


#if __has_embed("release_event_pic_thumb_3752") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_thumb_3752 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_thumb_3752"
});
constexpr std::string_view release_event_mime_type_thumb_3752 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_3752 = "???";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_thumb_3752;
constexpr std::string_view release_event_mime_type_thumb_3752 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_3752;
#endif


#if __has_embed("release_event_pic_tiny_thumb_3752") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_tiny_thumb_3752 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_tiny_thumb_3752"
});
constexpr std::string_view release_event_mime_type_tiny_thumb_3752 = "image/png";
constexpr std::string_view release_event_file_ext_tiny_thumb_3752 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_tiny_thumb_3752;
constexpr std::string_view release_event_mime_type_tiny_thumb_3752 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_tiny_thumb_3752;
#endif

constexpr picture picture_release_event_3752 = { R"XYX(image/jpeg)XYX"sv, std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/3752.jpg?v=2)XYX"sv, release_event_pic_orig_3752, release_event_mime_type_orig_3752, release_event_file_ext_orig_3752, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/3752.jpg?v=2)XYX"sv, release_event_pic_small_thumb_3752, release_event_mime_type_small_thumb_3752, release_event_file_ext_small_thumb_3752, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/3752.jpg?v=2)XYX"sv, release_event_pic_thumb_3752, release_event_mime_type_thumb_3752, release_event_file_ext_thumb_3752, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/3752.jpg?v=2)XYX"sv, release_event_pic_tiny_thumb_3752, release_event_mime_type_tiny_thumb_3752, release_event_file_ext_tiny_thumb_3752  };

constexpr std::array<additional_name, 1> names_release_event_2786 {{
  {"Japanese"sv, R"XYX(Miku Expo 2020 London)XYX"sv},
}};

constexpr std::array<web_link, 1> web_links_release_event_2786 {{
  {"Official"sv, R"XYX(Facebook)XYX"sv, R"XYX(https://www.facebook.com/events/2412779312331207/)XYX"sv, 1257 },
}};


#if __has_embed("release_event_pic_orig_2786") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_orig_2786 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_orig_2786"
});
constexpr std::string_view release_event_mime_type_orig_2786 = "image/png";
constexpr std::string_view release_event_file_ext_orig_2786 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_orig_2786;
constexpr std::string_view release_event_mime_type_orig_2786 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_orig_2786;
#endif


#if __has_embed("release_event_pic_small_thumb_2786") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_small_thumb_2786 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_small_thumb_2786"
});
constexpr std::string_view release_event_mime_type_small_thumb_2786 = "image/png";
constexpr std::string_view release_event_file_ext_small_thumb_2786 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_small_thumb_2786;
constexpr std::string_view release_event_mime_type_small_thumb_2786 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_small_thumb_2786;
#endif


#if __has_embed("release_event_pic_thumb_2786") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_thumb_2786 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_thumb_2786"
});
constexpr std::string_view release_event_mime_type_thumb_2786 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_2786 = "???";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_thumb_2786;
constexpr std::string_view release_event_mime_type_thumb_2786 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_2786;
#endif


#if __has_embed("release_event_pic_tiny_thumb_2786") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_tiny_thumb_2786 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_tiny_thumb_2786"
});
constexpr std::string_view release_event_mime_type_tiny_thumb_2786 = "image/png";
constexpr std::string_view release_event_file_ext_tiny_thumb_2786 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_tiny_thumb_2786;
constexpr std::string_view release_event_mime_type_tiny_thumb_2786 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_tiny_thumb_2786;
#endif

constexpr picture picture_release_event_2786 = { R"XYX(image/jpeg)XYX"sv, std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/2786.jpg?v=7)XYX"sv, release_event_pic_orig_2786, release_event_mime_type_orig_2786, release_event_file_ext_orig_2786, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/2786.jpg?v=7)XYX"sv, release_event_pic_small_thumb_2786, release_event_mime_type_small_thumb_2786, release_event_file_ext_small_thumb_2786, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/2786.jpg?v=7)XYX"sv, release_event_pic_thumb_2786, release_event_mime_type_thumb_2786, release_event_file_ext_thumb_2786, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/2786.jpg?v=7)XYX"sv, release_event_pic_tiny_thumb_2786, release_event_mime_type_tiny_thumb_2786, release_event_file_ext_tiny_thumb_2786  };

constexpr std::array<additional_name, 2> names_release_event_2939 {{
  {"Japanese"sv, R"XYX(ニコニコネット超会議2020夏✕HATSUNE MIKU LIVE - UNTITLED 0 -)XYX"sv},
  {"Romaji"sv, R"XYX(Nico Nico Net Chokaigi 2020 Natsu ✕ HATSUNE MIKU LIVE - UNTITLED 0 -)XYX"sv},
}};

constexpr std::array<web_link, 2> web_links_release_event_2939 {{
  {"Other"sv, R"XYX(Piapro Blog Post)XYX"sv, R"XYX(https://blog.piapro.net/2020/07/mo202004061-1.html)XYX"sv, 1476 },
  {"Other"sv, R"XYX(Website)XYX"sv, R"XYX(https://chokaigi.jp/2020summer/plan/mikulive.html)XYX"sv, 1477 },
}};


#if __has_embed("release_event_pic_orig_2939") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_orig_2939 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_orig_2939"
});
constexpr std::string_view release_event_mime_type_orig_2939 = "image/png";
constexpr std::string_view release_event_file_ext_orig_2939 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_orig_2939;
constexpr std::string_view release_event_mime_type_orig_2939 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_orig_2939;
#endif


#if __has_embed("release_event_pic_small_thumb_2939") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_small_thumb_2939 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_small_thumb_2939"
});
constexpr std::string_view release_event_mime_type_small_thumb_2939 = "image/png";
constexpr std::string_view release_event_file_ext_small_thumb_2939 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_small_thumb_2939;
constexpr std::string_view release_event_mime_type_small_thumb_2939 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_small_thumb_2939;
#endif


#if __has_embed("release_event_pic_thumb_2939") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_thumb_2939 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_thumb_2939"
});
constexpr std::string_view release_event_mime_type_thumb_2939 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_2939 = "???";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_thumb_2939;
constexpr std::string_view release_event_mime_type_thumb_2939 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_2939;
#endif


#if __has_embed("release_event_pic_tiny_thumb_2939") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_tiny_thumb_2939 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_tiny_thumb_2939"
});
constexpr std::string_view release_event_mime_type_tiny_thumb_2939 = "image/png";
constexpr std::string_view release_event_file_ext_tiny_thumb_2939 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_tiny_thumb_2939;
constexpr std::string_view release_event_mime_type_tiny_thumb_2939 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_tiny_thumb_2939;
#endif

constexpr picture picture_release_event_2939 = { R"XYX(image/png)XYX"sv, std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/2939.png?v=4)XYX"sv, release_event_pic_orig_2939, release_event_mime_type_orig_2939, release_event_file_ext_orig_2939, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/2939.png?v=4)XYX"sv, release_event_pic_small_thumb_2939, release_event_mime_type_small_thumb_2939, release_event_file_ext_small_thumb_2939, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/2939.png?v=4)XYX"sv, release_event_pic_thumb_2939, release_event_mime_type_thumb_2939, release_event_file_ext_thumb_2939, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/2939.png?v=4)XYX"sv, release_event_pic_tiny_thumb_2939, release_event_mime_type_tiny_thumb_2939, release_event_file_ext_tiny_thumb_2939  };

constexpr std::array<additional_name, 2> names_release_event_2952 {{
  {"Japanese"sv, R"XYX(初音ミク GALAXY LIVE 2020)XYX"sv},
  {"English"sv, R"XYX(Hatsune Miku GALAXY LIVE 2020)XYX"sv},
}};

constexpr std::array<web_link, 1> web_links_release_event_2952 {{
  {"Other"sv, R"XYX(Crypton Future Media (Press release))XYX"sv, R"XYX(https://www.crypton.co.jp/cfm/news/2020/09/03galaxylive2020)XYX"sv, 1506 },
}};


#if __has_embed("release_event_pic_orig_2952") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_orig_2952 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_orig_2952"
});
constexpr std::string_view release_event_mime_type_orig_2952 = "image/png";
constexpr std::string_view release_event_file_ext_orig_2952 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_orig_2952;
constexpr std::string_view release_event_mime_type_orig_2952 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_orig_2952;
#endif


#if __has_embed("release_event_pic_small_thumb_2952") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_small_thumb_2952 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_small_thumb_2952"
});
constexpr std::string_view release_event_mime_type_small_thumb_2952 = "image/png";
constexpr std::string_view release_event_file_ext_small_thumb_2952 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_small_thumb_2952;
constexpr std::string_view release_event_mime_type_small_thumb_2952 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_small_thumb_2952;
#endif


#if __has_embed("release_event_pic_thumb_2952") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_thumb_2952 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_thumb_2952"
});
constexpr std::string_view release_event_mime_type_thumb_2952 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_2952 = "???";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_thumb_2952;
constexpr std::string_view release_event_mime_type_thumb_2952 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_2952;
#endif


#if __has_embed("release_event_pic_tiny_thumb_2952") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_tiny_thumb_2952 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_tiny_thumb_2952"
});
constexpr std::string_view release_event_mime_type_tiny_thumb_2952 = "image/png";
constexpr std::string_view release_event_file_ext_tiny_thumb_2952 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_tiny_thumb_2952;
constexpr std::string_view release_event_mime_type_tiny_thumb_2952 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_tiny_thumb_2952;
#endif

constexpr picture picture_release_event_2952 = { R"XYX(image/jpeg)XYX"sv, std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/2952.jpg?v=9)XYX"sv, release_event_pic_orig_2952, release_event_mime_type_orig_2952, release_event_file_ext_orig_2952, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/2952.jpg?v=9)XYX"sv, release_event_pic_small_thumb_2952, release_event_mime_type_small_thumb_2952, release_event_file_ext_small_thumb_2952, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/2952.jpg?v=9)XYX"sv, release_event_pic_thumb_2952, release_event_mime_type_thumb_2952, release_event_file_ext_thumb_2952, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/2952.jpg?v=9)XYX"sv, release_event_pic_tiny_thumb_2952, release_event_mime_type_tiny_thumb_2952, release_event_file_ext_tiny_thumb_2952  };

constexpr std::array<additional_name, 4> names_release_event_2758 {{
  {"Unspecified"sv, R"XYX(マジカルミライ 2020 Osaka)XYX"sv},
  {"Unspecified"sv, R"XYX(Magical Mirai 2020 Osaka)XYX"sv},
  {"English"sv, R"XYX(Hatsune Miku Magical Mirai 2020 in OSAKA)XYX"sv},
  {"Japanese"sv, R"XYX(初音ミク「マジカルミライ 2020」in OSAKA)XYX"sv},
}};

constexpr std::array<web_link, 8> web_links_release_event_2758 {{
  {"Other"sv, R"XYX(Website (JP))XYX"sv, R"XYX(https://magicalmirai.com/2020/osaka/)XYX"sv, 1382 },
  {"Other"sv, R"XYX(Website (EN))XYX"sv, R"XYX(https://magicalmirai.com/2020/osaka/index_en.html)XYX"sv, 1383 },
  {"Official"sv, R"XYX(Twitter (Postponement))XYX"sv, R"XYX(https://twitter.com/magicalmirai/status/1260761661066973184?s=19)XYX"sv, 1426 },
  {"Official"sv, R"XYX(Twitter (New dates))XYX"sv, R"XYX(https://twitter.com/magicalmirai/status/1281048322694713344?s=19)XYX"sv, 1460 },
  {"Other"sv, R"XYX(Online Live Information (EN))XYX"sv, R"XYX(https://magicalmirai.com/2020/osaka/special_en.html#special_online)XYX"sv, 1584 },
  {"Other"sv, R"XYX(PIA LIVE STREAM)XYX"sv, R"XYX(https://w.pia.jp/a/magicalmirai2020-osaka-plseng/)XYX"sv, 1585 },
  {"Other"sv, R"XYX(KKBOX (Streaming))XYX"sv, R"XYX(https://kklivetw.kktix.cc/events/magicalmirai2020)XYX"sv, 1586 },
  {"Other"sv, R"XYX(Online Live Information (JP))XYX"sv, R"XYX(https://magicalmirai.com/2020/osaka/special.html#special_online)XYX"sv, 1587 },
}};


#if __has_embed("release_event_pic_orig_2758") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_orig_2758 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_orig_2758"
});
constexpr std::string_view release_event_mime_type_orig_2758 = "image/png";
constexpr std::string_view release_event_file_ext_orig_2758 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_orig_2758;
constexpr std::string_view release_event_mime_type_orig_2758 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_orig_2758;
#endif


#if __has_embed("release_event_pic_small_thumb_2758") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_small_thumb_2758 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_small_thumb_2758"
});
constexpr std::string_view release_event_mime_type_small_thumb_2758 = "image/png";
constexpr std::string_view release_event_file_ext_small_thumb_2758 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_small_thumb_2758;
constexpr std::string_view release_event_mime_type_small_thumb_2758 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_small_thumb_2758;
#endif


#if __has_embed("release_event_pic_thumb_2758") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_thumb_2758 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_thumb_2758"
});
constexpr std::string_view release_event_mime_type_thumb_2758 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_2758 = "???";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_thumb_2758;
constexpr std::string_view release_event_mime_type_thumb_2758 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_2758;
#endif


#if __has_embed("release_event_pic_tiny_thumb_2758") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_tiny_thumb_2758 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_tiny_thumb_2758"
});
constexpr std::string_view release_event_mime_type_tiny_thumb_2758 = "image/png";
constexpr std::string_view release_event_file_ext_tiny_thumb_2758 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_tiny_thumb_2758;
constexpr std::string_view release_event_mime_type_tiny_thumb_2758 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_tiny_thumb_2758;
#endif

constexpr picture picture_release_event_2758 = { R"XYX(image/jpeg)XYX"sv, std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/2758.jpg?v=17)XYX"sv, release_event_pic_orig_2758, release_event_mime_type_orig_2758, release_event_file_ext_orig_2758, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/2758.jpg?v=17)XYX"sv, release_event_pic_small_thumb_2758, release_event_mime_type_small_thumb_2758, release_event_file_ext_small_thumb_2758, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/2758.jpg?v=17)XYX"sv, release_event_pic_thumb_2758, release_event_mime_type_thumb_2758, release_event_file_ext_thumb_2758, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/2758.jpg?v=17)XYX"sv, release_event_pic_tiny_thumb_2758, release_event_mime_type_tiny_thumb_2758, release_event_file_ext_tiny_thumb_2758  };

constexpr std::array<additional_name, 3> names_release_event_3250 {{
  {"English"sv, R"XYX(MIKU WITH YOU 2020)XYX"sv},
  {"Japanese"sv, R"XYX(未来有你 2020)XYX"sv},
  {"Unspecified"sv, R"XYX(HATSUNE MIKU WITH YOU 2020)XYX"sv},
}};

constexpr std::array<web_link, 2> web_links_release_event_3250 {{
  {"Official"sv, R"XYX(Weibo (Announcement))XYX"sv, R"XYX(https://weibo.com/5582567326/JqeAidAw5)XYX"sv, 1574 },
  {"Other"sv, R"XYX(HATSUNE MIKU OFFICIAL BLOG)XYX"sv, R"XYX(https://blog.piapro.net/2020/10/zh2010211.html)XYX"sv, 1709 },
}};


#if __has_embed("release_event_pic_orig_3250") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_orig_3250 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_orig_3250"
});
constexpr std::string_view release_event_mime_type_orig_3250 = "image/jpeg";
constexpr std::string_view release_event_file_ext_orig_3250 = "jpeg";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_orig_3250;
constexpr std::string_view release_event_mime_type_orig_3250 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_orig_3250;
#endif


#if __has_embed("release_event_pic_small_thumb_3250") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_small_thumb_3250 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_small_thumb_3250"
});
constexpr std::string_view release_event_mime_type_small_thumb_3250 = "image/png";
constexpr std::string_view release_event_file_ext_small_thumb_3250 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_small_thumb_3250;
constexpr std::string_view release_event_mime_type_small_thumb_3250 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_small_thumb_3250;
#endif


#if __has_embed("release_event_pic_thumb_3250") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_thumb_3250 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_thumb_3250"
});
constexpr std::string_view release_event_mime_type_thumb_3250 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_3250 = "???";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_thumb_3250;
constexpr std::string_view release_event_mime_type_thumb_3250 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_3250;
#endif


#if __has_embed("release_event_pic_tiny_thumb_3250") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_tiny_thumb_3250 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_tiny_thumb_3250"
});
constexpr std::string_view release_event_mime_type_tiny_thumb_3250 = "image/png";
constexpr std::string_view release_event_file_ext_tiny_thumb_3250 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_tiny_thumb_3250;
constexpr std::string_view release_event_mime_type_tiny_thumb_3250 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_tiny_thumb_3250;
#endif

constexpr picture picture_release_event_3250 = { R"XYX(image/jpeg)XYX"sv, std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/3250.jpg?v=6)XYX"sv, release_event_pic_orig_3250, release_event_mime_type_orig_3250, release_event_file_ext_orig_3250, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/3250.jpg?v=6)XYX"sv, release_event_pic_small_thumb_3250, release_event_mime_type_small_thumb_3250, release_event_file_ext_small_thumb_3250, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/3250.jpg?v=6)XYX"sv, release_event_pic_thumb_3250, release_event_mime_type_thumb_3250, release_event_file_ext_thumb_3250, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/3250.jpg?v=6)XYX"sv, release_event_pic_tiny_thumb_3250, release_event_mime_type_tiny_thumb_3250, release_event_file_ext_tiny_thumb_3250  };

constexpr std::array<additional_name, 2> names_release_event_3224 {{
  {"English"sv, R"XYX(Miku Expo 2021 Online)XYX"sv},
  {"Unspecified"sv, R"XYX(HATSUNE MIKU EXPO 2021 Online)XYX"sv},
}};

constexpr std::array<web_link, 10> web_links_release_event_3224 {{
  {"Official"sv, R"XYX(Twitter)XYX"sv, R"XYX(https://twitter.com/mikuexpo/status/1314385636560838656/)XYX"sv, 1563 },
  {"Other"sv, R"XYX(Kickstarter)XYX"sv, R"XYX(https://www.kickstarter.com/projects/cryptonfuturemedia/hatsune-miku-global-concert-hatsune-miku-expo-2021-online)XYX"sv, 1588 },
  {"Other"sv, R"XYX(Website (EN))XYX"sv, R"XYX(https://mikuexpo.com/online2021/index_en.html)XYX"sv, 1704 },
  {"Other"sv, R"XYX(Website (JP))XYX"sv, R"XYX(https://mikuexpo.com/online2021/index.html)XYX"sv, 1705 },
  {"Other"sv, R"XYX(Website - Sub-events (EN))XYX"sv, R"XYX(https://mikuexpo.com/online2021/events_en.html)XYX"sv, 1811 },
  {"Other"sv, R"XYX(Website - Sub-events (JP))XYX"sv, R"XYX(https://mikuexpo.com/online2021/events.html)XYX"sv, 1812 },
  {"Reference"sv, R"XYX(MIKU EXPO Digital Stars 2021 Online)XYX"sv, R"XYX(https://vocadb.net/E/3706/miku-expo-digital-stars-2021-o)XYX"sv, 1813 },
  {"Reference"sv, R"XYX(HATSUNE MIKU EXPO 2021 Online Song Contest)XYX"sv, R"XYX(https://vocadb.net/E/3252/miku-expo-song-contest-2021)XYX"sv, 1814 },
  {"Other"sv, R"XYX(HATSUNE MIKU OFFICIAL BLOG)XYX"sv, R"XYX(https://blog.piapro.net/2021/04/ta2104061.html)XYX"sv, 1843 },
  {"Other"sv, R"XYX(#MIKU WORLD GALLERY)XYX"sv, R"XYX(https://paint.mikuexpo.com/MikuWorldGallery/)XYX"sv, 2050 },
}};


#if __has_embed("release_event_pic_orig_3224") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_orig_3224 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_orig_3224"
});
constexpr std::string_view release_event_mime_type_orig_3224 = "image/png";
constexpr std::string_view release_event_file_ext_orig_3224 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_orig_3224;
constexpr std::string_view release_event_mime_type_orig_3224 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_orig_3224;
#endif


#if __has_embed("release_event_pic_small_thumb_3224") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_small_thumb_3224 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_small_thumb_3224"
});
constexpr std::string_view release_event_mime_type_small_thumb_3224 = "image/png";
constexpr std::string_view release_event_file_ext_small_thumb_3224 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_small_thumb_3224;
constexpr std::string_view release_event_mime_type_small_thumb_3224 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_small_thumb_3224;
#endif


#if __has_embed("release_event_pic_thumb_3224") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_thumb_3224 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_thumb_3224"
});
constexpr std::string_view release_event_mime_type_thumb_3224 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_3224 = "???";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_thumb_3224;
constexpr std::string_view release_event_mime_type_thumb_3224 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_3224;
#endif


#if __has_embed("release_event_pic_tiny_thumb_3224") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_tiny_thumb_3224 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_tiny_thumb_3224"
});
constexpr std::string_view release_event_mime_type_tiny_thumb_3224 = "image/png";
constexpr std::string_view release_event_file_ext_tiny_thumb_3224 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_tiny_thumb_3224;
constexpr std::string_view release_event_mime_type_tiny_thumb_3224 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_tiny_thumb_3224;
#endif

constexpr picture picture_release_event_3224 = { R"XYX(image/jpeg)XYX"sv, std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/3224.jpg?v=18)XYX"sv, release_event_pic_orig_3224, release_event_mime_type_orig_3224, release_event_file_ext_orig_3224, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/3224.jpg?v=18)XYX"sv, release_event_pic_small_thumb_3224, release_event_mime_type_small_thumb_3224, release_event_file_ext_small_thumb_3224, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/3224.jpg?v=18)XYX"sv, release_event_pic_thumb_3224, release_event_mime_type_thumb_3224, release_event_file_ext_thumb_3224, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/3224.jpg?v=18)XYX"sv, release_event_pic_tiny_thumb_3224, release_event_mime_type_tiny_thumb_3224, release_event_file_ext_tiny_thumb_3224  };

constexpr std::array<additional_name, 2> names_release_event_3305 {{
  {"Japanese"sv, R"XYX(初音ミク「マジカルミライ 2021」in OSAKA)XYX"sv},
  {"English"sv, R"XYX(Hatsune Miku "Magical Mirai 2021" in OSAKA)XYX"sv},
}};

constexpr std::array<web_link, 3> web_links_release_event_3305 {{
  {"Other"sv, R"XYX(Website (JP))XYX"sv, R"XYX(https://magicalmirai.com/2021/osaka_ticket.html)XYX"sv, 2312 },
  {"Other"sv, R"XYX(Website (EN))XYX"sv, R"XYX(https://magicalmirai.com/2021/osaka_overview_en.html)XYX"sv, 2313 },
  {"Reference"sv, R"XYX(Creators Market 2021 OSAKA)XYX"sv, R"XYX(https://vocadb.net/E/4030/magical-mirai-creators-market-)XYX"sv, 2558 },
}};


#if __has_embed("release_event_pic_orig_3305") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_orig_3305 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_orig_3305"
});
constexpr std::string_view release_event_mime_type_orig_3305 = "image/png";
constexpr std::string_view release_event_file_ext_orig_3305 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_orig_3305;
constexpr std::string_view release_event_mime_type_orig_3305 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_orig_3305;
#endif


#if __has_embed("release_event_pic_small_thumb_3305") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_small_thumb_3305 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_small_thumb_3305"
});
constexpr std::string_view release_event_mime_type_small_thumb_3305 = "image/png";
constexpr std::string_view release_event_file_ext_small_thumb_3305 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_small_thumb_3305;
constexpr std::string_view release_event_mime_type_small_thumb_3305 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_small_thumb_3305;
#endif


#if __has_embed("release_event_pic_thumb_3305") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_thumb_3305 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_thumb_3305"
});
constexpr std::string_view release_event_mime_type_thumb_3305 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_3305 = "???";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_thumb_3305;
constexpr std::string_view release_event_mime_type_thumb_3305 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_3305;
#endif


#if __has_embed("release_event_pic_tiny_thumb_3305") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_tiny_thumb_3305 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_tiny_thumb_3305"
});
constexpr std::string_view release_event_mime_type_tiny_thumb_3305 = "image/png";
constexpr std::string_view release_event_file_ext_tiny_thumb_3305 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_tiny_thumb_3305;
constexpr std::string_view release_event_mime_type_tiny_thumb_3305 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_tiny_thumb_3305;
#endif

constexpr picture picture_release_event_3305 = { R"XYX(image/jpeg)XYX"sv, std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/3305.jpg?v=7)XYX"sv, release_event_pic_orig_3305, release_event_mime_type_orig_3305, release_event_file_ext_orig_3305, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/3305.jpg?v=7)XYX"sv, release_event_pic_small_thumb_3305, release_event_mime_type_small_thumb_3305, release_event_file_ext_small_thumb_3305, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/3305.jpg?v=7)XYX"sv, release_event_pic_thumb_3305, release_event_mime_type_thumb_3305, release_event_file_ext_thumb_3305, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/3305.jpg?v=7)XYX"sv, release_event_pic_tiny_thumb_3305, release_event_mime_type_tiny_thumb_3305, release_event_file_ext_tiny_thumb_3305  };

constexpr std::array<additional_name, 2> names_release_event_3979 {{
  {"Japanese"sv, R"XYX(初音ミク GALAXY LIVE 2021)XYX"sv},
  {"English"sv, R"XYX(Hatsune Miku GALAXY LIVE 2021)XYX"sv},
}};

constexpr std::array<web_link, 2> web_links_release_event_3979 {{
  {"Other"sv, R"XYX(Crypton Future Media (Press Release))XYX"sv, R"XYX(https://www.crypton.co.jp/cfm/news/2021/08/31galaxy21)XYX"sv, 2402 },
  {"Other"sv, R"XYX(HATSUNE MIKU OFFICIAL BLOG)XYX"sv, R"XYX(https://blog.piapro.net/2021/08/a2108311.html)XYX"sv, 2403 },
}};


#if __has_embed("release_event_pic_orig_3979") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_orig_3979 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_orig_3979"
});
constexpr std::string_view release_event_mime_type_orig_3979 = "image/png";
constexpr std::string_view release_event_file_ext_orig_3979 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_orig_3979;
constexpr std::string_view release_event_mime_type_orig_3979 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_orig_3979;
#endif


#if __has_embed("release_event_pic_small_thumb_3979") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_small_thumb_3979 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_small_thumb_3979"
});
constexpr std::string_view release_event_mime_type_small_thumb_3979 = "image/png";
constexpr std::string_view release_event_file_ext_small_thumb_3979 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_small_thumb_3979;
constexpr std::string_view release_event_mime_type_small_thumb_3979 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_small_thumb_3979;
#endif


#if __has_embed("release_event_pic_thumb_3979") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_thumb_3979 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_thumb_3979"
});
constexpr std::string_view release_event_mime_type_thumb_3979 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_3979 = "???";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_thumb_3979;
constexpr std::string_view release_event_mime_type_thumb_3979 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_3979;
#endif


#if __has_embed("release_event_pic_tiny_thumb_3979") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_tiny_thumb_3979 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_tiny_thumb_3979"
});
constexpr std::string_view release_event_mime_type_tiny_thumb_3979 = "image/png";
constexpr std::string_view release_event_file_ext_tiny_thumb_3979 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_tiny_thumb_3979;
constexpr std::string_view release_event_mime_type_tiny_thumb_3979 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_tiny_thumb_3979;
#endif

constexpr picture picture_release_event_3979 = { R"XYX(image/png)XYX"sv, std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/3979.png?v=6)XYX"sv, release_event_pic_orig_3979, release_event_mime_type_orig_3979, release_event_file_ext_orig_3979, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/3979.png?v=6)XYX"sv, release_event_pic_small_thumb_3979, release_event_mime_type_small_thumb_3979, release_event_file_ext_small_thumb_3979, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/3979.png?v=6)XYX"sv, release_event_pic_thumb_3979, release_event_mime_type_thumb_3979, release_event_file_ext_thumb_3979, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/3979.png?v=6)XYX"sv, release_event_pic_tiny_thumb_3979, release_event_mime_type_tiny_thumb_3979, release_event_file_ext_tiny_thumb_3979  };

constexpr std::array<additional_name, 3> names_release_event_4058 {{
  {"English"sv, R"XYX(MIKU WITH YOU 2021)XYX"sv},
  {"Japanese"sv, R"XYX(未来有你 2021)XYX"sv},
  {"Unspecified"sv, R"XYX(HATSUNE MIKU WITH YOU 2021)XYX"sv},
}};

constexpr std::array<web_link, 1> web_links_release_event_4058 {{
  {"Official"sv, R"XYX(Weibo (Announcement))XYX"sv, R"XYX(https://weibo.com/5582567326/L1a3K5EUz)XYX"sv, 2563 },
}};


#if __has_embed("release_event_pic_orig_4058") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_orig_4058 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_orig_4058"
});
constexpr std::string_view release_event_mime_type_orig_4058 = "image/png";
constexpr std::string_view release_event_file_ext_orig_4058 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_orig_4058;
constexpr std::string_view release_event_mime_type_orig_4058 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_orig_4058;
#endif


#if __has_embed("release_event_pic_small_thumb_4058") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_small_thumb_4058 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_small_thumb_4058"
});
constexpr std::string_view release_event_mime_type_small_thumb_4058 = "image/png";
constexpr std::string_view release_event_file_ext_small_thumb_4058 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_small_thumb_4058;
constexpr std::string_view release_event_mime_type_small_thumb_4058 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_small_thumb_4058;
#endif


#if __has_embed("release_event_pic_thumb_4058") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_thumb_4058 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_thumb_4058"
});
constexpr std::string_view release_event_mime_type_thumb_4058 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_4058 = "???";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_thumb_4058;
constexpr std::string_view release_event_mime_type_thumb_4058 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_4058;
#endif


#if __has_embed("release_event_pic_tiny_thumb_4058") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_tiny_thumb_4058 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_tiny_thumb_4058"
});
constexpr std::string_view release_event_mime_type_tiny_thumb_4058 = "image/png";
constexpr std::string_view release_event_file_ext_tiny_thumb_4058 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_tiny_thumb_4058;
constexpr std::string_view release_event_mime_type_tiny_thumb_4058 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_tiny_thumb_4058;
#endif

constexpr picture picture_release_event_4058 = { R"XYX(image/jpeg)XYX"sv, std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/4058.jpg?v=5)XYX"sv, release_event_pic_orig_4058, release_event_mime_type_orig_4058, release_event_file_ext_orig_4058, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/4058.jpg?v=5)XYX"sv, release_event_pic_small_thumb_4058, release_event_mime_type_small_thumb_4058, release_event_file_ext_small_thumb_4058, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/4058.jpg?v=5)XYX"sv, release_event_pic_thumb_4058, release_event_mime_type_thumb_4058, release_event_file_ext_thumb_4058, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/4058.jpg?v=5)XYX"sv, release_event_pic_tiny_thumb_4058, release_event_mime_type_tiny_thumb_4058, release_event_file_ext_tiny_thumb_4058  };

constexpr std::array<additional_name, 3> names_release_event_4114 {{
  {"Unspecified"sv, R"XYX(HATSUNE MIKU EXPO ЯƎWIИᗡ)XYX"sv},
  {"English"sv, R"XYX(Miku Expo Rewind)XYX"sv},
  {"Unspecified"sv, R"XYX(HATSUNE MIKU EXPO Rewind)XYX"sv},
}};

constexpr std::array<web_link, 5> web_links_release_event_4114 {{
  {"Other"sv, R"XYX(Website (EN))XYX"sv, R"XYX(https://mikuexpo.com/rewind2022/index_en.html)XYX"sv, 2663 },
  {"Other"sv, R"XYX(Website (JP))XYX"sv, R"XYX(https://mikuexpo.com/rewind2022/index.html)XYX"sv, 2664 },
  {"Other"sv, R"XYX(HATSUNE MIKU OFFICIAL BLOG)XYX"sv, R"XYX(https://blog.piapro.net/2021/12/ta2112241.html)XYX"sv, 2665 },
  {"Other"sv, R"XYX(Crypton Future Media (Press Release))XYX"sv, R"XYX(https://www.crypton.co.jp/cfm/news/2021/12/24me22rewind)XYX"sv, 3071 },
  {"Reference"sv, R"XYX(MIKU EXPO Digital Stars 2022 Online)XYX"sv, R"XYX(https://vocadb.net/E/4276/miku-expo-digital-stars-2022-o)XYX"sv, 3072 },
}};


#if __has_embed("release_event_pic_orig_4114") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_orig_4114 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_orig_4114"
});
constexpr std::string_view release_event_mime_type_orig_4114 = "image/png";
constexpr std::string_view release_event_file_ext_orig_4114 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_orig_4114;
constexpr std::string_view release_event_mime_type_orig_4114 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_orig_4114;
#endif


#if __has_embed("release_event_pic_small_thumb_4114") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_small_thumb_4114 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_small_thumb_4114"
});
constexpr std::string_view release_event_mime_type_small_thumb_4114 = "image/png";
constexpr std::string_view release_event_file_ext_small_thumb_4114 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_small_thumb_4114;
constexpr std::string_view release_event_mime_type_small_thumb_4114 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_small_thumb_4114;
#endif

constexpr std::array<std::uint8_t, 0> release_event_pic_thumb_4114;
constexpr std::string_view release_event_mime_type_thumb_4114 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_4114;


#if __has_embed("release_event_pic_tiny_thumb_4114") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_tiny_thumb_4114 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_tiny_thumb_4114"
});
constexpr std::string_view release_event_mime_type_tiny_thumb_4114 = "image/png";
constexpr std::string_view release_event_file_ext_tiny_thumb_4114 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_tiny_thumb_4114;
constexpr std::string_view release_event_mime_type_tiny_thumb_4114 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_tiny_thumb_4114;
#endif

constexpr picture picture_release_event_4114 = { R"XYX(image/jpeg)XYX"sv, std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/4114.jpg?v=15)XYX"sv, release_event_pic_orig_4114, release_event_mime_type_orig_4114, release_event_file_ext_orig_4114, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/4114.jpg?v=15)XYX"sv, release_event_pic_small_thumb_4114, release_event_mime_type_small_thumb_4114, release_event_file_ext_small_thumb_4114, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/4114.jpg?v=15)XYX"sv, release_event_pic_thumb_4114, release_event_mime_type_thumb_4114, release_event_file_ext_thumb_4114, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/4114.jpg?v=15)XYX"sv, release_event_pic_tiny_thumb_4114, release_event_mime_type_tiny_thumb_4114, release_event_file_ext_tiny_thumb_4114  };

constexpr std::array<additional_name, 2> names_release_event_4161 {{
  {"Japanese"sv, R"XYX(鏡音リン・レン Happy 14th Birthday Party「Two You☆★」)XYX"sv},
  {"English"sv, R"XYX(Kagamine Rin・Len Happy 14th Birthday Party "Two You☆★")XYX"sv},
}};

constexpr std::array<web_link, 3> web_links_release_event_4161 {{
  {"Other"sv, R"XYX(Website)XYX"sv, R"XYX(https://piapro.net/rinlen14thbd/live/)XYX"sv, 2801 },
  {"Official"sv, R"XYX(Twitter)XYX"sv, R"XYX(https://twitter.com/rinlen_live)XYX"sv, 2802 },
  {"Other"sv, R"XYX(ePlus)XYX"sv, R"XYX(https://ib.eplus.jp/rinlen14thbd)XYX"sv, 3290 },
}};


#if __has_embed("release_event_pic_orig_4161") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_orig_4161 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_orig_4161"
});
constexpr std::string_view release_event_mime_type_orig_4161 = "image/png";
constexpr std::string_view release_event_file_ext_orig_4161 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_orig_4161;
constexpr std::string_view release_event_mime_type_orig_4161 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_orig_4161;
#endif


#if __has_embed("release_event_pic_small_thumb_4161") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_small_thumb_4161 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_small_thumb_4161"
});
constexpr std::string_view release_event_mime_type_small_thumb_4161 = "image/png";
constexpr std::string_view release_event_file_ext_small_thumb_4161 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_small_thumb_4161;
constexpr std::string_view release_event_mime_type_small_thumb_4161 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_small_thumb_4161;
#endif


#if __has_embed("release_event_pic_thumb_4161") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_thumb_4161 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_thumb_4161"
});
constexpr std::string_view release_event_mime_type_thumb_4161 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_4161 = "???";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_thumb_4161;
constexpr std::string_view release_event_mime_type_thumb_4161 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_4161;
#endif


#if __has_embed("release_event_pic_tiny_thumb_4161") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_tiny_thumb_4161 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_tiny_thumb_4161"
});
constexpr std::string_view release_event_mime_type_tiny_thumb_4161 = "image/png";
constexpr std::string_view release_event_file_ext_tiny_thumb_4161 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_tiny_thumb_4161;
constexpr std::string_view release_event_mime_type_tiny_thumb_4161 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_tiny_thumb_4161;
#endif

constexpr picture picture_release_event_4161 = { R"XYX(image/jpeg)XYX"sv, std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/4161.jpg?v=9)XYX"sv, release_event_pic_orig_4161, release_event_mime_type_orig_4161, release_event_file_ext_orig_4161, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/4161.jpg?v=9)XYX"sv, release_event_pic_small_thumb_4161, release_event_mime_type_small_thumb_4161, release_event_file_ext_small_thumb_4161, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/4161.jpg?v=9)XYX"sv, release_event_pic_thumb_4161, release_event_mime_type_thumb_4161, release_event_file_ext_thumb_4161, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/4161.jpg?v=9)XYX"sv, release_event_pic_tiny_thumb_4161, release_event_mime_type_tiny_thumb_4161, release_event_file_ext_tiny_thumb_4161  };

constexpr std::array<additional_name, 3> names_release_event_4233 {{
  {"Japanese"sv, R"XYX(初音ミク「マジカルミライ」10th Anniversary in OSAKA)XYX"sv},
  {"English"sv, R"XYX(Hatsune Miku "Magical Mirai" 10th Anniversary in OSAKA)XYX"sv},
  {"Unspecified"sv, R"XYX(初音ミク「マジカルミライ 2022」in OSAKA)XYX"sv},
}};

constexpr std::array<web_link, 4> web_links_release_event_4233 {{
  {"Other"sv, R"XYX(Website (JP))XYX"sv, R"XYX(https://magicalmirai.com/10th/)XYX"sv, 2974 },
  {"Other"sv, R"XYX(Website (EN))XYX"sv, R"XYX(https://magicalmirai.com/10th/index_en.html)XYX"sv, 2975 },
  {"Other"sv, R"XYX(Website - OSAKA (EN))XYX"sv, R"XYX(https://magicalmirai.com/10th/osaka_overview_en.html)XYX"sv, 2976 },
  {"Other"sv, R"XYX(Website - OSAKA (JP))XYX"sv, R"XYX(https://magicalmirai.com/10th/osaka_ticket.html)XYX"sv, 2977 },
}};


#if __has_embed("release_event_pic_orig_4233") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_orig_4233 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_orig_4233"
});
constexpr std::string_view release_event_mime_type_orig_4233 = "image/png";
constexpr std::string_view release_event_file_ext_orig_4233 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_orig_4233;
constexpr std::string_view release_event_mime_type_orig_4233 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_orig_4233;
#endif


#if __has_embed("release_event_pic_small_thumb_4233") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_small_thumb_4233 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_small_thumb_4233"
});
constexpr std::string_view release_event_mime_type_small_thumb_4233 = "image/png";
constexpr std::string_view release_event_file_ext_small_thumb_4233 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_small_thumb_4233;
constexpr std::string_view release_event_mime_type_small_thumb_4233 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_small_thumb_4233;
#endif


#if __has_embed("release_event_pic_thumb_4233") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_thumb_4233 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_thumb_4233"
});
constexpr std::string_view release_event_mime_type_thumb_4233 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_4233 = "???";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_thumb_4233;
constexpr std::string_view release_event_mime_type_thumb_4233 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_4233;
#endif


#if __has_embed("release_event_pic_tiny_thumb_4233") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_tiny_thumb_4233 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_tiny_thumb_4233"
});
constexpr std::string_view release_event_mime_type_tiny_thumb_4233 = "image/png";
constexpr std::string_view release_event_file_ext_tiny_thumb_4233 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_tiny_thumb_4233;
constexpr std::string_view release_event_mime_type_tiny_thumb_4233 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_tiny_thumb_4233;
#endif

constexpr picture picture_release_event_4233 = { R"XYX(image/jpeg)XYX"sv, std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/4233.jpg?v=8)XYX"sv, release_event_pic_orig_4233, release_event_mime_type_orig_4233, release_event_file_ext_orig_4233, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/4233.jpg?v=8)XYX"sv, release_event_pic_small_thumb_4233, release_event_mime_type_small_thumb_4233, release_event_file_ext_small_thumb_4233, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/4233.jpg?v=8)XYX"sv, release_event_pic_thumb_4233, release_event_mime_type_thumb_4233, release_event_file_ext_thumb_4233, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/4233.jpg?v=8)XYX"sv, release_event_pic_tiny_thumb_4233, release_event_mime_type_tiny_thumb_4233, release_event_file_ext_tiny_thumb_4233  };

constexpr std::array<additional_name, 2> names_release_event_4490 {{
  {"English"sv, R"XYX(Miku Expo Rewind+)XYX"sv},
  {"Unspecified"sv, R"XYX(HATSUNE MIKU EXPO Rewind+)XYX"sv},
}};

constexpr std::array<web_link, 8> web_links_release_event_4490 {{
  {"Other"sv, R"XYX(Website (EN))XYX"sv, R"XYX(https://mikuexpo.com/rewind2022/index_en.html)XYX"sv, 3507 },
  {"Other"sv, R"XYX(Website (JP))XYX"sv, R"XYX(https://mikuexpo.com/rewind2022/index.html)XYX"sv, 3508 },
  {"Other"sv, R"XYX(Crypton Future Media (Press Release))XYX"sv, R"XYX(https://www.crypton.co.jp/cfm/news/2022/08/19rewindplus)XYX"sv, 3509 },
  {"Official"sv, R"XYX(Twitter (Announcement))XYX"sv, R"XYX(https://twitter.com/mikuexpo/status/1562984796724559872)XYX"sv, 3510 },
  {"Other"sv, R"XYX(Google Docs (Song request survey))XYX"sv, R"XYX(https://docs.google.com/forms/d/e/1FAIpQLSfMmeS1ltbz4AFCSBNblp5_wDcRviBIlGLITnLcTpw6uYUSYQ/viewform)XYX"sv, 3511 },
  {"Reference"sv, R"XYX(Song Remix Contest)XYX"sv, R"XYX(https://vocadb.net/E/4491)XYX"sv, 3517 },
  {"Reference"sv, R"XYX(MIKU EXPO Rewind+ Digital Stars Online)XYX"sv, R"XYX(https://vocadb.net/E/4670)XYX"sv, 5239 },
  {"Official"sv, R"XYX(Twitter (Timetable))XYX"sv, R"XYX(https://twitter.com/mikuexpo/status/1580741653110792192)XYX"sv, 5240 },
}};


#if __has_embed("release_event_pic_orig_4490") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_orig_4490 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_orig_4490"
});
constexpr std::string_view release_event_mime_type_orig_4490 = "image/png";
constexpr std::string_view release_event_file_ext_orig_4490 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_orig_4490;
constexpr std::string_view release_event_mime_type_orig_4490 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_orig_4490;
#endif


#if __has_embed("release_event_pic_small_thumb_4490") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_small_thumb_4490 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_small_thumb_4490"
});
constexpr std::string_view release_event_mime_type_small_thumb_4490 = "image/png";
constexpr std::string_view release_event_file_ext_small_thumb_4490 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_small_thumb_4490;
constexpr std::string_view release_event_mime_type_small_thumb_4490 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_small_thumb_4490;
#endif

constexpr std::array<std::uint8_t, 0> release_event_pic_thumb_4490;
constexpr std::string_view release_event_mime_type_thumb_4490 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_4490;


#if __has_embed("release_event_pic_tiny_thumb_4490") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_tiny_thumb_4490 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_tiny_thumb_4490"
});
constexpr std::string_view release_event_mime_type_tiny_thumb_4490 = "image/png";
constexpr std::string_view release_event_file_ext_tiny_thumb_4490 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_tiny_thumb_4490;
constexpr std::string_view release_event_mime_type_tiny_thumb_4490 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_tiny_thumb_4490;
#endif

constexpr picture picture_release_event_4490 = { R"XYX(image/jpeg)XYX"sv, std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/4490.jpg?v=8)XYX"sv, release_event_pic_orig_4490, release_event_mime_type_orig_4490, release_event_file_ext_orig_4490, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/4490.jpg?v=8)XYX"sv, release_event_pic_small_thumb_4490, release_event_mime_type_small_thumb_4490, release_event_file_ext_small_thumb_4490, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/4490.jpg?v=8)XYX"sv, release_event_pic_thumb_4490, release_event_mime_type_thumb_4490, release_event_file_ext_thumb_4490, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/4490.jpg?v=8)XYX"sv, release_event_pic_tiny_thumb_4490, release_event_mime_type_tiny_thumb_4490, release_event_file_ext_tiny_thumb_4490  };

constexpr std::array<additional_name, 3> names_release_event_4235 {{
  {"Japanese"sv, R"XYX(初音ミク「マジカルミライ」10th Anniversary in SAPPORO)XYX"sv},
  {"English"sv, R"XYX(Hatsune Miku "Magical Mirai" 10th Anniversary in SAPPORO)XYX"sv},
  {"Unspecified"sv, R"XYX(初音ミク「マジカルミライ 2022」in SAPPORO)XYX"sv},
}};

constexpr std::array<web_link, 5> web_links_release_event_4235 {{
  {"Other"sv, R"XYX(Website - SAPPORO (JP))XYX"sv, R"XYX(https://magicalmirai.com/10th/sapporo_ticket.html)XYX"sv, 2982 },
  {"Other"sv, R"XYX(Website - SAPPORO (EN))XYX"sv, R"XYX(https://magicalmirai.com/10th/sapporo_overview_en.html)XYX"sv, 2983 },
  {"Other"sv, R"XYX(Website (JP))XYX"sv, R"XYX(https://magicalmirai.com/10th/)XYX"sv, 2984 },
  {"Other"sv, R"XYX(Website (EN))XYX"sv, R"XYX(https://magicalmirai.com/10th/index_en.html)XYX"sv, 2985 },
  {"Reference"sv, R"XYX(SNOW MIKU 2023)XYX"sv, R"XYX(https://vocadb.net/E/4818/snow-miku-2023)XYX"sv, 5505 },
}};


#if __has_embed("release_event_pic_orig_4235") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_orig_4235 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_orig_4235"
});
constexpr std::string_view release_event_mime_type_orig_4235 = "image/png";
constexpr std::string_view release_event_file_ext_orig_4235 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_orig_4235;
constexpr std::string_view release_event_mime_type_orig_4235 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_orig_4235;
#endif


#if __has_embed("release_event_pic_small_thumb_4235") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_small_thumb_4235 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_small_thumb_4235"
});
constexpr std::string_view release_event_mime_type_small_thumb_4235 = "image/png";
constexpr std::string_view release_event_file_ext_small_thumb_4235 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_small_thumb_4235;
constexpr std::string_view release_event_mime_type_small_thumb_4235 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_small_thumb_4235;
#endif


#if __has_embed("release_event_pic_thumb_4235") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_thumb_4235 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_thumb_4235"
});
constexpr std::string_view release_event_mime_type_thumb_4235 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_4235 = "???";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_thumb_4235;
constexpr std::string_view release_event_mime_type_thumb_4235 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_4235;
#endif


#if __has_embed("release_event_pic_tiny_thumb_4235") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_tiny_thumb_4235 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_tiny_thumb_4235"
});
constexpr std::string_view release_event_mime_type_tiny_thumb_4235 = "image/png";
constexpr std::string_view release_event_file_ext_tiny_thumb_4235 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_tiny_thumb_4235;
constexpr std::string_view release_event_mime_type_tiny_thumb_4235 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_tiny_thumb_4235;
#endif

constexpr picture picture_release_event_4235 = { R"XYX(image/jpeg)XYX"sv, std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/4235.jpg?v=9)XYX"sv, release_event_pic_orig_4235, release_event_mime_type_orig_4235, release_event_file_ext_orig_4235, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/4235.jpg?v=9)XYX"sv, release_event_pic_small_thumb_4235, release_event_mime_type_small_thumb_4235, release_event_file_ext_small_thumb_4235, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/4235.jpg?v=9)XYX"sv, release_event_pic_thumb_4235, release_event_mime_type_thumb_4235, release_event_file_ext_thumb_4235, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/4235.jpg?v=9)XYX"sv, release_event_pic_tiny_thumb_4235, release_event_mime_type_tiny_thumb_4235, release_event_file_ext_tiny_thumb_4235  };

constexpr std::array<additional_name, 2> names_release_event_4765 {{
  {"Japanese"sv, R"XYX(初音ミク JAPAN TOUR 2023 〜THUNDERBOLT〜 名古屋)XYX"sv},
  {"English"sv, R"XYX(HATSUNE MIKU JAPAN TOUR 2023 〜THUNDERBOLT〜 NAGOYA)XYX"sv},
}};

constexpr std::array<web_link, 0> web_links_release_event_4765 {{
}};


#if __has_embed("release_event_pic_orig_4765") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_orig_4765 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_orig_4765"
});
constexpr std::string_view release_event_mime_type_orig_4765 = "image/png";
constexpr std::string_view release_event_file_ext_orig_4765 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_orig_4765;
constexpr std::string_view release_event_mime_type_orig_4765 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_orig_4765;
#endif


#if __has_embed("release_event_pic_small_thumb_4765") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_small_thumb_4765 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_small_thumb_4765"
});
constexpr std::string_view release_event_mime_type_small_thumb_4765 = "image/png";
constexpr std::string_view release_event_file_ext_small_thumb_4765 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_small_thumb_4765;
constexpr std::string_view release_event_mime_type_small_thumb_4765 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_small_thumb_4765;
#endif


#if __has_embed("release_event_pic_thumb_4765") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_thumb_4765 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_thumb_4765"
});
constexpr std::string_view release_event_mime_type_thumb_4765 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_4765 = "???";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_thumb_4765;
constexpr std::string_view release_event_mime_type_thumb_4765 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_4765;
#endif


#if __has_embed("release_event_pic_tiny_thumb_4765") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_tiny_thumb_4765 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_tiny_thumb_4765"
});
constexpr std::string_view release_event_mime_type_tiny_thumb_4765 = "image/png";
constexpr std::string_view release_event_file_ext_tiny_thumb_4765 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_tiny_thumb_4765;
constexpr std::string_view release_event_mime_type_tiny_thumb_4765 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_tiny_thumb_4765;
#endif

constexpr picture picture_release_event_4765 = { R"XYX(image/jpeg)XYX"sv, std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/4765.jpg?v=7)XYX"sv, release_event_pic_orig_4765, release_event_mime_type_orig_4765, release_event_file_ext_orig_4765, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/4765.jpg?v=7)XYX"sv, release_event_pic_small_thumb_4765, release_event_mime_type_small_thumb_4765, release_event_file_ext_small_thumb_4765, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/4765.jpg?v=7)XYX"sv, release_event_pic_thumb_4765, release_event_mime_type_thumb_4765, release_event_file_ext_thumb_4765, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/4765.jpg?v=7)XYX"sv, release_event_pic_tiny_thumb_4765, release_event_mime_type_tiny_thumb_4765, release_event_file_ext_tiny_thumb_4765  };

constexpr std::array<additional_name, 2> names_release_event_5910 {{
  {"Japanese"sv, R"XYX(初音ミク×鼓童スペシャルライブ２０２３ ～結～)XYX"sv},
  {"Romaji"sv, R"XYX(Hatsune Miku × Kodō Special Live 2023 ~Yui~)XYX"sv},
}};

constexpr std::array<web_link, 5> web_links_release_event_5910 {{
  {"Other"sv, R"XYX(HATSUNE MIKU OFFICIAL BLOG)XYX"sv, R"XYX(https://blog.piapro.net/2023/02/mon2302151.html)XYX"sv, 6813 },
  {"Other"sv, R"XYX(Ticket PIA)XYX"sv, R"XYX(https://w.pia.jp/t/kodo-miku-t/)XYX"sv, 6814 },
  {"Other"sv, R"XYX(Website)XYX"sv, R"XYX(https://kodo-miku.com/)XYX"sv, 6815 },
  {"Other"sv, R"XYX(PR TIMES)XYX"sv, R"XYX(https://prtimes.jp/main/html/rd/p/000000183.000052709.html)XYX"sv, 6816 },
  {"Official"sv, R"XYX(Twitter (Announcement))XYX"sv, R"XYX(https://twitter.com/kodo_miku/status/1625676398202617858)XYX"sv, 6817 },
}};


#if __has_embed("release_event_pic_orig_5910") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_orig_5910 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_orig_5910"
});
constexpr std::string_view release_event_mime_type_orig_5910 = "image/png";
constexpr std::string_view release_event_file_ext_orig_5910 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_orig_5910;
constexpr std::string_view release_event_mime_type_orig_5910 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_orig_5910;
#endif


#if __has_embed("release_event_pic_small_thumb_5910") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_small_thumb_5910 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_small_thumb_5910"
});
constexpr std::string_view release_event_mime_type_small_thumb_5910 = "image/png";
constexpr std::string_view release_event_file_ext_small_thumb_5910 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_small_thumb_5910;
constexpr std::string_view release_event_mime_type_small_thumb_5910 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_small_thumb_5910;
#endif


#if __has_embed("release_event_pic_thumb_5910") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_thumb_5910 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_thumb_5910"
});
constexpr std::string_view release_event_mime_type_thumb_5910 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_5910 = "???";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_thumb_5910;
constexpr std::string_view release_event_mime_type_thumb_5910 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_5910;
#endif


#if __has_embed("release_event_pic_tiny_thumb_5910") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_tiny_thumb_5910 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_tiny_thumb_5910"
});
constexpr std::string_view release_event_mime_type_tiny_thumb_5910 = "image/png";
constexpr std::string_view release_event_file_ext_tiny_thumb_5910 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_tiny_thumb_5910;
constexpr std::string_view release_event_mime_type_tiny_thumb_5910 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_tiny_thumb_5910;
#endif

constexpr picture picture_release_event_5910 = { R"XYX(image/jpeg)XYX"sv, std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/5910.jpg?v=2)XYX"sv, release_event_pic_orig_5910, release_event_mime_type_orig_5910, release_event_file_ext_orig_5910, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/5910.jpg?v=2)XYX"sv, release_event_pic_small_thumb_5910, release_event_mime_type_small_thumb_5910, release_event_file_ext_small_thumb_5910, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/5910.jpg?v=2)XYX"sv, release_event_pic_thumb_5910, release_event_mime_type_thumb_5910, release_event_file_ext_thumb_5910, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/5910.jpg?v=2)XYX"sv, release_event_pic_tiny_thumb_5910, release_event_mime_type_tiny_thumb_5910, release_event_file_ext_tiny_thumb_5910  };

constexpr std::array<additional_name, 2> names_release_event_6045 {{
  {"Japanese"sv, R"XYX(初音ミク「マジカルミライ 2023」in OSAKA)XYX"sv},
  {"English"sv, R"XYX(Hatsune Miku "Magical Mirai 2023" in OSAKA)XYX"sv},
}};

constexpr std::array<web_link, 8> web_links_release_event_6045 {{
  {"Other"sv, R"XYX(Website (JP))XYX"sv, R"XYX(https://magicalmirai.com/2023/)XYX"sv, 7062 },
  {"Other"sv, R"XYX(Website (EN))XYX"sv, R"XYX(https://magicalmirai.com/2023/index_en.html)XYX"sv, 7063 },
  {"Other"sv, R"XYX(Website - OSAKA (JP))XYX"sv, R"XYX(https://magicalmirai.com/2023/osaka_ticket.html)XYX"sv, 7066 },
  {"Other"sv, R"XYX(Website - OSAKA (EN))XYX"sv, R"XYX(https://magicalmirai.com/2023/osaka_ticket_en.html)XYX"sv, 7067 },
  {"Other"sv, R"XYX(HATSUNE MIKU OFFICIAL BLOG)XYX"sv, R"XYX(https://blog.piapro.net/2023/03/b2303091.html)XYX"sv, 7068 },
  {"Official"sv, R"XYX(Twitter (Announcement) (EN))XYX"sv, R"XYX(https://twitter.com/cfm_miku_en/status/1633659602930917377)XYX"sv, 7069 },
  {"Official"sv, R"XYX(Twitter (Announcement) (JP))XYX"sv, R"XYX(https://twitter.com/magicalmirai/status/1633652189238554624)XYX"sv, 7070 },
  {"Other"sv, R"XYX(PR TIMES)XYX"sv, R"XYX(https://prtimes.jp/main/html/rd/p/000000196.000052709.html)XYX"sv, 7071 },
}};


#if __has_embed("release_event_pic_orig_6045") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_orig_6045 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_orig_6045"
});
constexpr std::string_view release_event_mime_type_orig_6045 = "image/png";
constexpr std::string_view release_event_file_ext_orig_6045 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_orig_6045;
constexpr std::string_view release_event_mime_type_orig_6045 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_orig_6045;
#endif


#if __has_embed("release_event_pic_small_thumb_6045") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_small_thumb_6045 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_small_thumb_6045"
});
constexpr std::string_view release_event_mime_type_small_thumb_6045 = "image/png";
constexpr std::string_view release_event_file_ext_small_thumb_6045 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_small_thumb_6045;
constexpr std::string_view release_event_mime_type_small_thumb_6045 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_small_thumb_6045;
#endif


#if __has_embed("release_event_pic_thumb_6045") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_thumb_6045 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_thumb_6045"
});
constexpr std::string_view release_event_mime_type_thumb_6045 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_6045 = "???";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_thumb_6045;
constexpr std::string_view release_event_mime_type_thumb_6045 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_6045;
#endif


#if __has_embed("release_event_pic_tiny_thumb_6045") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_tiny_thumb_6045 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_tiny_thumb_6045"
});
constexpr std::string_view release_event_mime_type_tiny_thumb_6045 = "image/png";
constexpr std::string_view release_event_file_ext_tiny_thumb_6045 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_tiny_thumb_6045;
constexpr std::string_view release_event_mime_type_tiny_thumb_6045 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_tiny_thumb_6045;
#endif

constexpr picture picture_release_event_6045 = { R"XYX(image/jpeg)XYX"sv, std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/6045.jpg?v=9)XYX"sv, release_event_pic_orig_6045, release_event_mime_type_orig_6045, release_event_file_ext_orig_6045, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/6045.jpg?v=9)XYX"sv, release_event_pic_small_thumb_6045, release_event_mime_type_small_thumb_6045, release_event_file_ext_small_thumb_6045, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/6045.jpg?v=9)XYX"sv, release_event_pic_thumb_6045, release_event_mime_type_thumb_6045, release_event_file_ext_thumb_6045, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/6045.jpg?v=9)XYX"sv, release_event_pic_tiny_thumb_6045, release_event_mime_type_tiny_thumb_6045, release_event_file_ext_tiny_thumb_6045  };

constexpr std::array<additional_name, 2> names_release_event_5751 {{
  {"English"sv, R"XYX(Miku Expo 2023 VR)XYX"sv},
  {"Unspecified"sv, R"XYX(HATSUNE MIKU EXPO 2023 VR)XYX"sv},
}};

constexpr std::array<web_link, 11> web_links_release_event_5751 {{
  {"Official"sv, R"XYX(Twitter (Announcement) (1))XYX"sv, R"XYX(https://twitter.com/mikuexpo/status/1607197780468195328)XYX"sv, 6511 },
  {"Other"sv, R"XYX(PR TIMES)XYX"sv, R"XYX(https://prtimes.jp/main/html/rd/p/000000163.000052709.html)XYX"sv, 6512 },
  {"Other"sv, R"XYX(Crypton Future Media (Press Release))XYX"sv, R"XYX(https://www.crypton.co.jp/cfm/news/2022/12/26me23vr)XYX"sv, 6513 },
  {"Other"sv, R"XYX(Kickstarter)XYX"sv, R"XYX(https://www.kickstarter.com/projects/cryptonfuturemedia/hatsune-miku-global-concert-hatsune-miku-expo-2023-vr)XYX"sv, 6756 },
  {"Official"sv, R"XYX(Twitter (Announcement) (2))XYX"sv, R"XYX(https://twitter.com/mikuexpo/status/1622420905317240833)XYX"sv, 6757 },
  {"Other"sv, R"XYX(HATSUNE MIKU OFFICIAL BLOG (1))XYX"sv, R"XYX(https://blog.piapro.net/2023/02/o2302061.html)XYX"sv, 6758 },
  {"Other"sv, R"XYX(HATSUNE MIKU OFFICIAL BLOG (2))XYX"sv, R"XYX(https://blog.piapro.net/2023/03/o2303171.html)XYX"sv, 7183 },
  {"Other"sv, R"XYX(Website (EN))XYX"sv, R"XYX(https://mikuexpo.com/vr2023/index_en.html)XYX"sv, 7325 },
  {"Other"sv, R"XYX(Website (JP))XYX"sv, R"XYX(https://mikuexpo.com/vr2023/index.html)XYX"sv, 7326 },
  {"Official"sv, R"XYX(Twitter (Timetable))XYX"sv, R"XYX(https://twitter.com/mikuexpo/status/1714467552838209763)XYX"sv, 8183 },
  {"Official"sv, R"XYX(Twitter (Content Warning notice))XYX"sv, R"XYX(https://twitter.com/mikuexpo/status/1723488274654892171)XYX"sv, 8289 },
}};


#if __has_embed("release_event_pic_orig_5751") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_orig_5751 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_orig_5751"
});
constexpr std::string_view release_event_mime_type_orig_5751 = "image/png";
constexpr std::string_view release_event_file_ext_orig_5751 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_orig_5751;
constexpr std::string_view release_event_mime_type_orig_5751 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_orig_5751;
#endif


#if __has_embed("release_event_pic_small_thumb_5751") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_small_thumb_5751 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_small_thumb_5751"
});
constexpr std::string_view release_event_mime_type_small_thumb_5751 = "image/png";
constexpr std::string_view release_event_file_ext_small_thumb_5751 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_small_thumb_5751;
constexpr std::string_view release_event_mime_type_small_thumb_5751 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_small_thumb_5751;
#endif


#if __has_embed("release_event_pic_thumb_5751") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_thumb_5751 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_thumb_5751"
});
constexpr std::string_view release_event_mime_type_thumb_5751 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_5751 = "???";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_thumb_5751;
constexpr std::string_view release_event_mime_type_thumb_5751 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_5751;
#endif


#if __has_embed("release_event_pic_tiny_thumb_5751") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_tiny_thumb_5751 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_tiny_thumb_5751"
});
constexpr std::string_view release_event_mime_type_tiny_thumb_5751 = "image/png";
constexpr std::string_view release_event_file_ext_tiny_thumb_5751 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_tiny_thumb_5751;
constexpr std::string_view release_event_mime_type_tiny_thumb_5751 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_tiny_thumb_5751;
#endif

constexpr picture picture_release_event_5751 = { R"XYX(image/jpeg)XYX"sv, std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/5751.jpg?v=13)XYX"sv, release_event_pic_orig_5751, release_event_mime_type_orig_5751, release_event_file_ext_orig_5751, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/5751.jpg?v=13)XYX"sv, release_event_pic_small_thumb_5751, release_event_mime_type_small_thumb_5751, release_event_file_ext_small_thumb_5751, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/5751.jpg?v=13)XYX"sv, release_event_pic_thumb_5751, release_event_mime_type_thumb_5751, release_event_file_ext_thumb_5751, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/5751.jpg?v=13)XYX"sv, release_event_pic_tiny_thumb_5751, release_event_mime_type_tiny_thumb_5751, release_event_file_ext_tiny_thumb_5751  };

constexpr std::array<additional_name, 2> names_release_event_6539 {{
  {"English"sv, R"XYX(MK15th project MEIKO＆KAITO Online Concert)XYX"sv},
  {"Japanese"sv, R"XYX(MK15th project MEIKO＆KAITO オンラインコンサート)XYX"sv},
}};

constexpr std::array<web_link, 1> web_links_release_event_6539 {{
  {"Other"sv, R"XYX(HATSUNE MIKU OFFICIAL BLOG)XYX"sv, R"XYX(https://blog.piapro.net/2023/09/nk2309141.html)XYX"sv, 7982 },
}};


#if __has_embed("release_event_pic_orig_6539") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_orig_6539 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_orig_6539"
});
constexpr std::string_view release_event_mime_type_orig_6539 = "image/jpeg";
constexpr std::string_view release_event_file_ext_orig_6539 = "jpeg";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_orig_6539;
constexpr std::string_view release_event_mime_type_orig_6539 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_orig_6539;
#endif


#if __has_embed("release_event_pic_small_thumb_6539") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_small_thumb_6539 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_small_thumb_6539"
});
constexpr std::string_view release_event_mime_type_small_thumb_6539 = "image/jpeg";
constexpr std::string_view release_event_file_ext_small_thumb_6539 = "jpeg";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_small_thumb_6539;
constexpr std::string_view release_event_mime_type_small_thumb_6539 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_small_thumb_6539;
#endif


#if __has_embed("release_event_pic_thumb_6539") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_thumb_6539 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_thumb_6539"
});
constexpr std::string_view release_event_mime_type_thumb_6539 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_6539 = "???";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_thumb_6539;
constexpr std::string_view release_event_mime_type_thumb_6539 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_6539;
#endif


#if __has_embed("release_event_pic_tiny_thumb_6539") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_tiny_thumb_6539 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_tiny_thumb_6539"
});
constexpr std::string_view release_event_mime_type_tiny_thumb_6539 = "image/jpeg";
constexpr std::string_view release_event_file_ext_tiny_thumb_6539 = "jpeg";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_tiny_thumb_6539;
constexpr std::string_view release_event_mime_type_tiny_thumb_6539 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_tiny_thumb_6539;
#endif

constexpr picture picture_release_event_6539 = { R"XYX(image/jpeg)XYX"sv, std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/6539.jpg?v=6)XYX"sv, release_event_pic_orig_6539, release_event_mime_type_orig_6539, release_event_file_ext_orig_6539, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/6539.jpg?v=6)XYX"sv, release_event_pic_small_thumb_6539, release_event_mime_type_small_thumb_6539, release_event_file_ext_small_thumb_6539, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/6539.jpg?v=6)XYX"sv, release_event_pic_thumb_6539, release_event_mime_type_thumb_6539, release_event_file_ext_thumb_6539, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/6539.jpg?v=6)XYX"sv, release_event_pic_tiny_thumb_6539, release_event_mime_type_tiny_thumb_6539, release_event_file_ext_tiny_thumb_6539  };

constexpr std::array<additional_name, 3> names_release_event_6986 {{
  {"Japanese"sv, R"XYX(MIKU FES'24 (春)〜Happy 16th Birthday〜)XYX"sv},
  {"Romaji"sv, R"XYX(MIKU FES'24 (Haru)〜Happy 16th Birthday〜)XYX"sv},
  {"English"sv, R"XYX(MIKU FES'24 (Spring)〜Happy 16th Birthday〜)XYX"sv},
}};

constexpr std::array<web_link, 2> web_links_release_event_6986 {{
  {"Official"sv, R"XYX(Twitter)XYX"sv, R"XYX(https://twitter.com/cfm_miku/status/1748273235702235618)XYX"sv, 8532 },
  {"Other"sv, R"XYX(Official Page)XYX"sv, R"XYX(https://mikufes24spring.jp/)XYX"sv, 8583 },
}};


#if __has_embed("release_event_pic_orig_6986") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_orig_6986 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_orig_6986"
});
constexpr std::string_view release_event_mime_type_orig_6986 = "image/jpeg";
constexpr std::string_view release_event_file_ext_orig_6986 = "jpeg";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_orig_6986;
constexpr std::string_view release_event_mime_type_orig_6986 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_orig_6986;
#endif


#if __has_embed("release_event_pic_small_thumb_6986") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_small_thumb_6986 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_small_thumb_6986"
});
constexpr std::string_view release_event_mime_type_small_thumb_6986 = "image/jpeg";
constexpr std::string_view release_event_file_ext_small_thumb_6986 = "jpeg";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_small_thumb_6986;
constexpr std::string_view release_event_mime_type_small_thumb_6986 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_small_thumb_6986;
#endif


#if __has_embed("release_event_pic_thumb_6986") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_thumb_6986 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_thumb_6986"
});
constexpr std::string_view release_event_mime_type_thumb_6986 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_6986 = "???";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_thumb_6986;
constexpr std::string_view release_event_mime_type_thumb_6986 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_6986;
#endif


#if __has_embed("release_event_pic_tiny_thumb_6986") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_tiny_thumb_6986 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_tiny_thumb_6986"
});
constexpr std::string_view release_event_mime_type_tiny_thumb_6986 = "image/jpeg";
constexpr std::string_view release_event_file_ext_tiny_thumb_6986 = "jpeg";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_tiny_thumb_6986;
constexpr std::string_view release_event_mime_type_tiny_thumb_6986 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_tiny_thumb_6986;
#endif

constexpr picture picture_release_event_6986 = { R"XYX(image/jpeg)XYX"sv, std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/6986.jpg?v=13)XYX"sv, release_event_pic_orig_6986, release_event_mime_type_orig_6986, release_event_file_ext_orig_6986, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/6986.jpg?v=13)XYX"sv, release_event_pic_small_thumb_6986, release_event_mime_type_small_thumb_6986, release_event_file_ext_small_thumb_6986, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/6986.jpg?v=13)XYX"sv, release_event_pic_thumb_6986, release_event_mime_type_thumb_6986, release_event_file_ext_thumb_6986, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/6986.jpg?v=13)XYX"sv, release_event_pic_tiny_thumb_6986, release_event_mime_type_tiny_thumb_6986, release_event_file_ext_tiny_thumb_6986  };

constexpr std::array<additional_name, 1> names_release_event_6516 {{
  {"English"sv, R"XYX(Miku Expo 2024 Vancouver )XYX"sv},
}};

constexpr std::array<web_link, 1> web_links_release_event_6516 {{
  {"Other"sv, R"XYX(Official Webpage)XYX"sv, R"XYX(https://mikuexpo.com/na2024/)XYX"sv, 7951 },
}};


#if __has_embed("release_event_pic_orig_6516") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_orig_6516 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_orig_6516"
});
constexpr std::string_view release_event_mime_type_orig_6516 = "image/jpeg";
constexpr std::string_view release_event_file_ext_orig_6516 = "jpeg";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_orig_6516;
constexpr std::string_view release_event_mime_type_orig_6516 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_orig_6516;
#endif


#if __has_embed("release_event_pic_small_thumb_6516") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_small_thumb_6516 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_small_thumb_6516"
});
constexpr std::string_view release_event_mime_type_small_thumb_6516 = "image/jpeg";
constexpr std::string_view release_event_file_ext_small_thumb_6516 = "jpeg";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_small_thumb_6516;
constexpr std::string_view release_event_mime_type_small_thumb_6516 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_small_thumb_6516;
#endif


#if __has_embed("release_event_pic_thumb_6516") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_thumb_6516 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_thumb_6516"
});
constexpr std::string_view release_event_mime_type_thumb_6516 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_6516 = "???";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_thumb_6516;
constexpr std::string_view release_event_mime_type_thumb_6516 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_6516;
#endif


#if __has_embed("release_event_pic_tiny_thumb_6516") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_tiny_thumb_6516 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_tiny_thumb_6516"
});
constexpr std::string_view release_event_mime_type_tiny_thumb_6516 = "image/jpeg";
constexpr std::string_view release_event_file_ext_tiny_thumb_6516 = "jpeg";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_tiny_thumb_6516;
constexpr std::string_view release_event_mime_type_tiny_thumb_6516 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_tiny_thumb_6516;
#endif

constexpr picture picture_release_event_6516 = { R"XYX(image/jpeg)XYX"sv, std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/6516.jpg?v=9)XYX"sv, release_event_pic_orig_6516, release_event_mime_type_orig_6516, release_event_file_ext_orig_6516, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/6516.jpg?v=9)XYX"sv, release_event_pic_small_thumb_6516, release_event_mime_type_small_thumb_6516, release_event_file_ext_small_thumb_6516, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/6516.jpg?v=9)XYX"sv, release_event_pic_thumb_6516, release_event_mime_type_thumb_6516, release_event_file_ext_thumb_6516, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/6516.jpg?v=9)XYX"sv, release_event_pic_tiny_thumb_6516, release_event_mime_type_tiny_thumb_6516, release_event_file_ext_tiny_thumb_6516  };

constexpr std::array<additional_name, 3> names_release_event_7673 {{
  {"English"sv, R"XYX(MIKU WITH YOU 2024 in Shanghai)XYX"sv},
  {"Japanese"sv, R"XYX(未来有你 2024 in Shanghai)XYX"sv},
  {"Unspecified"sv, R"XYX(HATSUNE MIKU WITH YOU 2024 in Shanghai)XYX"sv},
}};

constexpr std::array<web_link, 0> web_links_release_event_7673 {{
}};


#if __has_embed("release_event_pic_orig_7673") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_orig_7673 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_orig_7673"
});
constexpr std::string_view release_event_mime_type_orig_7673 = "image/jpeg";
constexpr std::string_view release_event_file_ext_orig_7673 = "jpeg";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_orig_7673;
constexpr std::string_view release_event_mime_type_orig_7673 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_orig_7673;
#endif


#if __has_embed("release_event_pic_small_thumb_7673") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_small_thumb_7673 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_small_thumb_7673"
});
constexpr std::string_view release_event_mime_type_small_thumb_7673 = "image/jpeg";
constexpr std::string_view release_event_file_ext_small_thumb_7673 = "jpeg";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_small_thumb_7673;
constexpr std::string_view release_event_mime_type_small_thumb_7673 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_small_thumb_7673;
#endif


#if __has_embed("release_event_pic_thumb_7673") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_thumb_7673 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_thumb_7673"
});
constexpr std::string_view release_event_mime_type_thumb_7673 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_7673 = "???";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_thumb_7673;
constexpr std::string_view release_event_mime_type_thumb_7673 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_7673;
#endif


#if __has_embed("release_event_pic_tiny_thumb_7673") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_tiny_thumb_7673 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_tiny_thumb_7673"
});
constexpr std::string_view release_event_mime_type_tiny_thumb_7673 = "image/jpeg";
constexpr std::string_view release_event_file_ext_tiny_thumb_7673 = "jpeg";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_tiny_thumb_7673;
constexpr std::string_view release_event_mime_type_tiny_thumb_7673 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_tiny_thumb_7673;
#endif

constexpr picture picture_release_event_7673 = { R"XYX(image/jpeg)XYX"sv, std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/7673.jpg?v=4)XYX"sv, release_event_pic_orig_7673, release_event_mime_type_orig_7673, release_event_file_ext_orig_7673, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/7673.jpg?v=4)XYX"sv, release_event_pic_small_thumb_7673, release_event_mime_type_small_thumb_7673, release_event_file_ext_small_thumb_7673, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/7673.jpg?v=4)XYX"sv, release_event_pic_thumb_7673, release_event_mime_type_thumb_7673, release_event_file_ext_thumb_7673, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/7673.jpg?v=4)XYX"sv, release_event_pic_tiny_thumb_7673, release_event_mime_type_tiny_thumb_7673, release_event_file_ext_tiny_thumb_7673  };

constexpr std::array<additional_name, 2> names_release_event_7214 {{
  {"Japanese"sv, R"XYX(初音ミク「マジカルミライ 2024」in FUKUOKA)XYX"sv},
  {"English"sv, R"XYX(Hatsune Miku "Magical Mirai 2024" in FUKUOKA)XYX"sv},
}};

constexpr std::array<web_link, 1> web_links_release_event_7214 {{
  {"Other"sv, R"XYX(Website (EN))XYX"sv, R"XYX(https://magicalmirai.com/2024/fukuoka_ticket_en.html)XYX"sv, 8914 },
}};


#if __has_embed("release_event_pic_orig_7214") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_orig_7214 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_orig_7214"
});
constexpr std::string_view release_event_mime_type_orig_7214 = "image/jpeg";
constexpr std::string_view release_event_file_ext_orig_7214 = "jpeg";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_orig_7214;
constexpr std::string_view release_event_mime_type_orig_7214 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_orig_7214;
#endif


#if __has_embed("release_event_pic_small_thumb_7214") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_small_thumb_7214 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_small_thumb_7214"
});
constexpr std::string_view release_event_mime_type_small_thumb_7214 = "image/jpeg";
constexpr std::string_view release_event_file_ext_small_thumb_7214 = "jpeg";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_small_thumb_7214;
constexpr std::string_view release_event_mime_type_small_thumb_7214 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_small_thumb_7214;
#endif


#if __has_embed("release_event_pic_thumb_7214") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_thumb_7214 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_thumb_7214"
});
constexpr std::string_view release_event_mime_type_thumb_7214 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_7214 = "???";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_thumb_7214;
constexpr std::string_view release_event_mime_type_thumb_7214 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_7214;
#endif


#if __has_embed("release_event_pic_tiny_thumb_7214") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_tiny_thumb_7214 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_tiny_thumb_7214"
});
constexpr std::string_view release_event_mime_type_tiny_thumb_7214 = "image/jpeg";
constexpr std::string_view release_event_file_ext_tiny_thumb_7214 = "jpeg";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_tiny_thumb_7214;
constexpr std::string_view release_event_mime_type_tiny_thumb_7214 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_tiny_thumb_7214;
#endif

constexpr picture picture_release_event_7214 = { R"XYX(image/jpeg)XYX"sv, std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/7214.jpg?v=9)XYX"sv, release_event_pic_orig_7214, release_event_mime_type_orig_7214, release_event_file_ext_orig_7214, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/7214.jpg?v=9)XYX"sv, release_event_pic_small_thumb_7214, release_event_mime_type_small_thumb_7214, release_event_file_ext_small_thumb_7214, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/7214.jpg?v=9)XYX"sv, release_event_pic_thumb_7214, release_event_mime_type_thumb_7214, release_event_file_ext_thumb_7214, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/7214.jpg?v=9)XYX"sv, release_event_pic_tiny_thumb_7214, release_event_mime_type_tiny_thumb_7214, release_event_file_ext_tiny_thumb_7214  };

constexpr std::array<additional_name, 1> names_release_event_7266 {{
  {"English"sv, R"XYX(Miku Expo 2024 London)XYX"sv},
}};

constexpr std::array<web_link, 1> web_links_release_event_7266 {{
  {"Other"sv, R"XYX(Official Webpage)XYX"sv, R"XYX(https://mikuexpo.com/europe2024/)XYX"sv, 8998 },
}};


#if __has_embed("release_event_pic_orig_7266") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_orig_7266 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_orig_7266"
});
constexpr std::string_view release_event_mime_type_orig_7266 = "image/jpeg";
constexpr std::string_view release_event_file_ext_orig_7266 = "jpeg";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_orig_7266;
constexpr std::string_view release_event_mime_type_orig_7266 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_orig_7266;
#endif


#if __has_embed("release_event_pic_small_thumb_7266") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_small_thumb_7266 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_small_thumb_7266"
});
constexpr std::string_view release_event_mime_type_small_thumb_7266 = "image/jpeg";
constexpr std::string_view release_event_file_ext_small_thumb_7266 = "jpeg";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_small_thumb_7266;
constexpr std::string_view release_event_mime_type_small_thumb_7266 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_small_thumb_7266;
#endif


#if __has_embed("release_event_pic_thumb_7266") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_thumb_7266 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_thumb_7266"
});
constexpr std::string_view release_event_mime_type_thumb_7266 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_7266 = "???";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_thumb_7266;
constexpr std::string_view release_event_mime_type_thumb_7266 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_7266;
#endif


#if __has_embed("release_event_pic_tiny_thumb_7266") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_tiny_thumb_7266 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_tiny_thumb_7266"
});
constexpr std::string_view release_event_mime_type_tiny_thumb_7266 = "image/jpeg";
constexpr std::string_view release_event_file_ext_tiny_thumb_7266 = "jpeg";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_tiny_thumb_7266;
constexpr std::string_view release_event_mime_type_tiny_thumb_7266 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_tiny_thumb_7266;
#endif

constexpr picture picture_release_event_7266 = { R"XYX(image/jpeg)XYX"sv, std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/7266.jpg?v=6)XYX"sv, release_event_pic_orig_7266, release_event_mime_type_orig_7266, release_event_file_ext_orig_7266, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/7266.jpg?v=6)XYX"sv, release_event_pic_small_thumb_7266, release_event_mime_type_small_thumb_7266, release_event_file_ext_small_thumb_7266, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/7266.jpg?v=6)XYX"sv, release_event_pic_thumb_7266, release_event_mime_type_thumb_7266, release_event_file_ext_thumb_7266, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/7266.jpg?v=6)XYX"sv, release_event_pic_tiny_thumb_7266, release_event_mime_type_tiny_thumb_7266, release_event_file_ext_tiny_thumb_7266  };

constexpr std::array<additional_name, 1> names_release_event_7765 {{
  {"English"sv, R"XYX(Miku Expo 2024 Auckland)XYX"sv},
}};

constexpr std::array<web_link, 1> web_links_release_event_7765 {{
  {"Other"sv, R"XYX(Official Webpage)XYX"sv, R"XYX(https://mikuexpo.com/nzaus2024/)XYX"sv, 9713 },
}};


#if __has_embed("release_event_pic_orig_7765") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_orig_7765 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_orig_7765"
});
constexpr std::string_view release_event_mime_type_orig_7765 = "image/jpeg";
constexpr std::string_view release_event_file_ext_orig_7765 = "jpeg";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_orig_7765;
constexpr std::string_view release_event_mime_type_orig_7765 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_orig_7765;
#endif


#if __has_embed("release_event_pic_small_thumb_7765") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_small_thumb_7765 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_small_thumb_7765"
});
constexpr std::string_view release_event_mime_type_small_thumb_7765 = "image/jpeg";
constexpr std::string_view release_event_file_ext_small_thumb_7765 = "jpeg";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_small_thumb_7765;
constexpr std::string_view release_event_mime_type_small_thumb_7765 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_small_thumb_7765;
#endif


#if __has_embed("release_event_pic_thumb_7765") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_thumb_7765 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_thumb_7765"
});
constexpr std::string_view release_event_mime_type_thumb_7765 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_7765 = "???";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_thumb_7765;
constexpr std::string_view release_event_mime_type_thumb_7765 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_7765;
#endif


#if __has_embed("release_event_pic_tiny_thumb_7765") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_tiny_thumb_7765 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_tiny_thumb_7765"
});
constexpr std::string_view release_event_mime_type_tiny_thumb_7765 = "image/jpeg";
constexpr std::string_view release_event_file_ext_tiny_thumb_7765 = "jpeg";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_tiny_thumb_7765;
constexpr std::string_view release_event_mime_type_tiny_thumb_7765 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_tiny_thumb_7765;
#endif

constexpr picture picture_release_event_7765 = { R"XYX(image/jpeg)XYX"sv, std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/7765.jpg?v=3)XYX"sv, release_event_pic_orig_7765, release_event_mime_type_orig_7765, release_event_file_ext_orig_7765, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/7765.jpg?v=3)XYX"sv, release_event_pic_small_thumb_7765, release_event_mime_type_small_thumb_7765, release_event_file_ext_small_thumb_7765, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/7765.jpg?v=3)XYX"sv, release_event_pic_thumb_7765, release_event_mime_type_thumb_7765, release_event_file_ext_thumb_7765, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/7765.jpg?v=3)XYX"sv, release_event_pic_tiny_thumb_7765, release_event_mime_type_tiny_thumb_7765, release_event_file_ext_tiny_thumb_7765  };

constexpr std::array<additional_name, 2> names_release_event_8380 {{
  {"Japanese"sv, R"XYX(初音ミク JAPAN TOUR 2025 〜BLOOMING〜 大阪)XYX"sv},
  {"English"sv, R"XYX(HATSUNE MIKU JAPAN TOUR 2025 〜BLOOMING〜 OSAKA)XYX"sv},
}};

constexpr std::array<web_link, 0> web_links_release_event_8380 {{
}};


#if __has_embed("release_event_pic_orig_8380") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_orig_8380 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_orig_8380"
});
constexpr std::string_view release_event_mime_type_orig_8380 = "image/png";
constexpr std::string_view release_event_file_ext_orig_8380 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_orig_8380;
constexpr std::string_view release_event_mime_type_orig_8380 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_orig_8380;
#endif


#if __has_embed("release_event_pic_small_thumb_8380") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_small_thumb_8380 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_small_thumb_8380"
});
constexpr std::string_view release_event_mime_type_small_thumb_8380 = "image/png";
constexpr std::string_view release_event_file_ext_small_thumb_8380 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_small_thumb_8380;
constexpr std::string_view release_event_mime_type_small_thumb_8380 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_small_thumb_8380;
#endif


#if __has_embed("release_event_pic_thumb_8380") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_thumb_8380 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_thumb_8380"
});
constexpr std::string_view release_event_mime_type_thumb_8380 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_8380 = "???";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_thumb_8380;
constexpr std::string_view release_event_mime_type_thumb_8380 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_8380;
#endif


#if __has_embed("release_event_pic_tiny_thumb_8380") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_tiny_thumb_8380 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_tiny_thumb_8380"
});
constexpr std::string_view release_event_mime_type_tiny_thumb_8380 = "image/png";
constexpr std::string_view release_event_file_ext_tiny_thumb_8380 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_tiny_thumb_8380;
constexpr std::string_view release_event_mime_type_tiny_thumb_8380 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_tiny_thumb_8380;
#endif

constexpr picture picture_release_event_8380 = { R"XYX(image/png)XYX"sv, std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/8380.png?v=5)XYX"sv, release_event_pic_orig_8380, release_event_mime_type_orig_8380, release_event_file_ext_orig_8380, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/8380.png?v=5)XYX"sv, release_event_pic_small_thumb_8380, release_event_mime_type_small_thumb_8380, release_event_file_ext_small_thumb_8380, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/8380.png?v=5)XYX"sv, release_event_pic_thumb_8380, release_event_mime_type_thumb_8380, release_event_file_ext_thumb_8380, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/8380.png?v=5)XYX"sv, release_event_pic_tiny_thumb_8380, release_event_mime_type_tiny_thumb_8380, release_event_file_ext_tiny_thumb_8380  };

constexpr std::array<additional_name, 2> names_release_event_8768 {{
  {"Japanese"sv, R"XYX(初音ミク「マジカルミライ 2025」in SENDAI)XYX"sv},
  {"English"sv, R"XYX(Hatsune Miku "Magical Mirai 2025" in SENDAI)XYX"sv},
}};

constexpr std::array<web_link, 1> web_links_release_event_8768 {{
  {"Other"sv, R"XYX(Website)XYX"sv, R"XYX(https://magicalmirai.com/2025/)XYX"sv, 11366 },
}};


#if __has_embed("release_event_pic_orig_8768") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_orig_8768 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_orig_8768"
});
constexpr std::string_view release_event_mime_type_orig_8768 = "image/jpeg";
constexpr std::string_view release_event_file_ext_orig_8768 = "jpeg";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_orig_8768;
constexpr std::string_view release_event_mime_type_orig_8768 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_orig_8768;
#endif


#if __has_embed("release_event_pic_small_thumb_8768") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_small_thumb_8768 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_small_thumb_8768"
});
constexpr std::string_view release_event_mime_type_small_thumb_8768 = "image/jpeg";
constexpr std::string_view release_event_file_ext_small_thumb_8768 = "jpeg";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_small_thumb_8768;
constexpr std::string_view release_event_mime_type_small_thumb_8768 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_small_thumb_8768;
#endif


#if __has_embed("release_event_pic_thumb_8768") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_thumb_8768 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_thumb_8768"
});
constexpr std::string_view release_event_mime_type_thumb_8768 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_8768 = "???";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_thumb_8768;
constexpr std::string_view release_event_mime_type_thumb_8768 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_8768;
#endif


#if __has_embed("release_event_pic_tiny_thumb_8768") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_tiny_thumb_8768 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_tiny_thumb_8768"
});
constexpr std::string_view release_event_mime_type_tiny_thumb_8768 = "image/jpeg";
constexpr std::string_view release_event_file_ext_tiny_thumb_8768 = "jpeg";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_tiny_thumb_8768;
constexpr std::string_view release_event_mime_type_tiny_thumb_8768 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_tiny_thumb_8768;
#endif

constexpr picture picture_release_event_8768 = { R"XYX(image/jpeg)XYX"sv, std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/8768.jpg?v=9)XYX"sv, release_event_pic_orig_8768, release_event_mime_type_orig_8768, release_event_file_ext_orig_8768, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/8768.jpg?v=9)XYX"sv, release_event_pic_small_thumb_8768, release_event_mime_type_small_thumb_8768, release_event_file_ext_small_thumb_8768, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/8768.jpg?v=9)XYX"sv, release_event_pic_thumb_8768, release_event_mime_type_thumb_8768, release_event_file_ext_thumb_8768, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/8768.jpg?v=9)XYX"sv, release_event_pic_tiny_thumb_8768, release_event_mime_type_tiny_thumb_8768, release_event_file_ext_tiny_thumb_8768  };

constexpr std::array<additional_name, 1> names_release_event_9341 {{
  {"English"sv, R"XYX(Miku Expo 2025 Bangkok)XYX"sv},
}};

constexpr std::array<web_link, 1> web_links_release_event_9341 {{
  {"Other"sv, R"XYX(Website)XYX"sv, R"XYX(https://mikuexpo.com/asia2025/)XYX"sv, 12284 },
}};


#if __has_embed("release_event_pic_orig_9341") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_orig_9341 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_orig_9341"
});
constexpr std::string_view release_event_mime_type_orig_9341 = "image/jpeg";
constexpr std::string_view release_event_file_ext_orig_9341 = "jpeg";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_orig_9341;
constexpr std::string_view release_event_mime_type_orig_9341 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_orig_9341;
#endif


#if __has_embed("release_event_pic_small_thumb_9341") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_small_thumb_9341 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_small_thumb_9341"
});
constexpr std::string_view release_event_mime_type_small_thumb_9341 = "image/jpeg";
constexpr std::string_view release_event_file_ext_small_thumb_9341 = "jpeg";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_small_thumb_9341;
constexpr std::string_view release_event_mime_type_small_thumb_9341 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_small_thumb_9341;
#endif


#if __has_embed("release_event_pic_thumb_9341") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_thumb_9341 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_thumb_9341"
});
constexpr std::string_view release_event_mime_type_thumb_9341 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_9341 = "???";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_thumb_9341;
constexpr std::string_view release_event_mime_type_thumb_9341 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_9341;
#endif


#if __has_embed("release_event_pic_tiny_thumb_9341") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_tiny_thumb_9341 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_tiny_thumb_9341"
});
constexpr std::string_view release_event_mime_type_tiny_thumb_9341 = "image/jpeg";
constexpr std::string_view release_event_file_ext_tiny_thumb_9341 = "jpeg";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_tiny_thumb_9341;
constexpr std::string_view release_event_mime_type_tiny_thumb_9341 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_tiny_thumb_9341;
#endif

constexpr picture picture_release_event_9341 = { R"XYX(image/jpeg)XYX"sv, std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/9341.jpg?v=3)XYX"sv, release_event_pic_orig_9341, release_event_mime_type_orig_9341, release_event_file_ext_orig_9341, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/9341.jpg?v=3)XYX"sv, release_event_pic_small_thumb_9341, release_event_mime_type_small_thumb_9341, release_event_file_ext_small_thumb_9341, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/9341.jpg?v=3)XYX"sv, release_event_pic_thumb_9341, release_event_mime_type_thumb_9341, release_event_file_ext_thumb_9341, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/9341.jpg?v=3)XYX"sv, release_event_pic_tiny_thumb_9341, release_event_mime_type_tiny_thumb_9341, release_event_file_ext_tiny_thumb_9341  };

constexpr std::array<additional_name, 3> names_release_event_9644 {{
  {"English"sv, R"XYX(MIKU WITH YOU 2025 in Shanghai)XYX"sv},
  {"Japanese"sv, R"XYX(未来有你 2025 in Shanghai)XYX"sv},
  {"Unspecified"sv, R"XYX(HATSUNE MIKU WITH YOU 2025 in Shanghai)XYX"sv},
}};

constexpr std::array<web_link, 1> web_links_release_event_9644 {{
  {"Other"sv, R"XYX(Weibo)XYX"sv, R"XYX(https://m.weibo.cn/detail/5204573494710825)XYX"sv, 12690 },
}};


#if __has_embed("release_event_pic_orig_9644") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_orig_9644 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_orig_9644"
});
constexpr std::string_view release_event_mime_type_orig_9644 = "image/jpeg";
constexpr std::string_view release_event_file_ext_orig_9644 = "jpeg";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_orig_9644;
constexpr std::string_view release_event_mime_type_orig_9644 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_orig_9644;
#endif


#if __has_embed("release_event_pic_small_thumb_9644") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_small_thumb_9644 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_small_thumb_9644"
});
constexpr std::string_view release_event_mime_type_small_thumb_9644 = "image/jpeg";
constexpr std::string_view release_event_file_ext_small_thumb_9644 = "jpeg";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_small_thumb_9644;
constexpr std::string_view release_event_mime_type_small_thumb_9644 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_small_thumb_9644;
#endif


#if __has_embed("release_event_pic_thumb_9644") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_thumb_9644 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_thumb_9644"
});
constexpr std::string_view release_event_mime_type_thumb_9644 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_9644 = "???";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_thumb_9644;
constexpr std::string_view release_event_mime_type_thumb_9644 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_9644;
#endif


#if __has_embed("release_event_pic_tiny_thumb_9644") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_tiny_thumb_9644 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_tiny_thumb_9644"
});
constexpr std::string_view release_event_mime_type_tiny_thumb_9644 = "image/jpeg";
constexpr std::string_view release_event_file_ext_tiny_thumb_9644 = "jpeg";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_tiny_thumb_9644;
constexpr std::string_view release_event_mime_type_tiny_thumb_9644 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_tiny_thumb_9644;
#endif

constexpr picture picture_release_event_9644 = { R"XYX(image/jpeg)XYX"sv, std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/9644.jpg?v=3)XYX"sv, release_event_pic_orig_9644, release_event_mime_type_orig_9644, release_event_file_ext_orig_9644, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/9644.jpg?v=3)XYX"sv, release_event_pic_small_thumb_9644, release_event_mime_type_small_thumb_9644, release_event_file_ext_small_thumb_9644, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/9644.jpg?v=3)XYX"sv, release_event_pic_thumb_9644, release_event_mime_type_thumb_9644, release_event_file_ext_thumb_9644, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/9644.jpg?v=3)XYX"sv, release_event_pic_tiny_thumb_9644, release_event_mime_type_tiny_thumb_9644, release_event_file_ext_tiny_thumb_9644  };

constexpr std::array<additional_name, 2> names_release_event_9642 {{
  {"Japanese"sv, R"XYX(初音ミク LAWSON 50th Anniversary Special LIVE)XYX"sv},
  {"English"sv, R"XYX(Hatsune Miku LAWSON 50th Anniversary Special LIVE)XYX"sv},
}};

constexpr std::array<web_link, 4> web_links_release_event_9642 {{
  {"Other"sv, R"XYX(Website)XYX"sv, R"XYX(https://l-tike.com/concert/lawson50th_260117_0118/)XYX"sv, 12686 },
  {"Official"sv, R"XYX(Piapro Blog (1))XYX"sv, R"XYX(https://blog.piapro.net/2025/09/ni25090201.html)XYX"sv, 12687 },
  {"Official"sv, R"XYX(Piapro Blog (2))XYX"sv, R"XYX(https://blog.piapro.net/2025/09/ni25092301.html)XYX"sv, 13304 },
  {"Official"sv, R"XYX(Piapro Blog (3))XYX"sv, R"XYX(https://blog.piapro.net/2025/10/ni25100301.html)XYX"sv, 13305 },
}};


#if __has_embed("release_event_pic_orig_9642") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_orig_9642 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_orig_9642"
});
constexpr std::string_view release_event_mime_type_orig_9642 = "image/jpeg";
constexpr std::string_view release_event_file_ext_orig_9642 = "jpeg";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_orig_9642;
constexpr std::string_view release_event_mime_type_orig_9642 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_orig_9642;
#endif


#if __has_embed("release_event_pic_small_thumb_9642") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_small_thumb_9642 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_small_thumb_9642"
});
constexpr std::string_view release_event_mime_type_small_thumb_9642 = "image/jpeg";
constexpr std::string_view release_event_file_ext_small_thumb_9642 = "jpeg";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_small_thumb_9642;
constexpr std::string_view release_event_mime_type_small_thumb_9642 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_small_thumb_9642;
#endif


#if __has_embed("release_event_pic_thumb_9642") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_thumb_9642 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_thumb_9642"
});
constexpr std::string_view release_event_mime_type_thumb_9642 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_9642 = "???";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_thumb_9642;
constexpr std::string_view release_event_mime_type_thumb_9642 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_9642;
#endif


#if __has_embed("release_event_pic_tiny_thumb_9642") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_tiny_thumb_9642 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_tiny_thumb_9642"
});
constexpr std::string_view release_event_mime_type_tiny_thumb_9642 = "image/jpeg";
constexpr std::string_view release_event_file_ext_tiny_thumb_9642 = "jpeg";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_tiny_thumb_9642;
constexpr std::string_view release_event_mime_type_tiny_thumb_9642 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_tiny_thumb_9642;
#endif

constexpr picture picture_release_event_9642 = { R"XYX(image/jpeg)XYX"sv, std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/9642.jpg?v=6)XYX"sv, release_event_pic_orig_9642, release_event_mime_type_orig_9642, release_event_file_ext_orig_9642, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/9642.jpg?v=6)XYX"sv, release_event_pic_small_thumb_9642, release_event_mime_type_small_thumb_9642, release_event_file_ext_small_thumb_9642, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/9642.jpg?v=6)XYX"sv, release_event_pic_thumb_9642, release_event_mime_type_thumb_9642, release_event_file_ext_thumb_9642, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/9642.jpg?v=6)XYX"sv, release_event_pic_tiny_thumb_9642, release_event_mime_type_tiny_thumb_9642, release_event_file_ext_tiny_thumb_9642  };

constexpr std::array<additional_name, 3> names_release_event_9401 {{
  {"English"sv, R"XYX(Hello)XYX"sv},
  {"Unspecified"sv, R"XYX(デコミク LIVE starring 初音ミク 『Hello』Produced by DECO*27 / OTOIRO)XYX"sv},
  {"Unspecified"sv, R"XYX(DECOMiku LIVE starring Hatsune Miku 『Hello』Produced by DECO*27 / OTOIRO)XYX"sv},
}};

constexpr std::array<web_link, 2> web_links_release_event_9401 {{
  {"Other"sv, R"XYX(Website)XYX"sv, R"XYX(https://otoiro.co.jp/live/decomikulive2026)XYX"sv, 12346 },
  {"Official"sv, R"XYX(X (Twitter))XYX"sv, R"XYX(https://x.com/DecoMiku_Live)XYX"sv, 12347 },
}};


#if __has_embed("release_event_pic_orig_9401") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_orig_9401 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_orig_9401"
});
constexpr std::string_view release_event_mime_type_orig_9401 = "image/png";
constexpr std::string_view release_event_file_ext_orig_9401 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_orig_9401;
constexpr std::string_view release_event_mime_type_orig_9401 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_orig_9401;
#endif


#if __has_embed("release_event_pic_small_thumb_9401") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_small_thumb_9401 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_small_thumb_9401"
});
constexpr std::string_view release_event_mime_type_small_thumb_9401 = "image/png";
constexpr std::string_view release_event_file_ext_small_thumb_9401 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_small_thumb_9401;
constexpr std::string_view release_event_mime_type_small_thumb_9401 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_small_thumb_9401;
#endif


#if __has_embed("release_event_pic_thumb_9401") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_thumb_9401 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_thumb_9401"
});
constexpr std::string_view release_event_mime_type_thumb_9401 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_9401 = "???";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_thumb_9401;
constexpr std::string_view release_event_mime_type_thumb_9401 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_thumb_9401;
#endif


#if __has_embed("release_event_pic_tiny_thumb_9401") == __STDC_EMBED_FOUND__
constexpr std::array release_event_pic_tiny_thumb_9401 = std::to_array<std::uint8_t>({
    #embed "release_event_pic_tiny_thumb_9401"
});
constexpr std::string_view release_event_mime_type_tiny_thumb_9401 = "image/png";
constexpr std::string_view release_event_file_ext_tiny_thumb_9401 = "png";
#else
constexpr std::array<std::uint8_t, 0> release_event_pic_tiny_thumb_9401;
constexpr std::string_view release_event_mime_type_tiny_thumb_9401 = "inode/x-empty";
constexpr std::string_view release_event_file_ext_tiny_thumb_9401;
#endif

constexpr picture picture_release_event_9401 = { R"XYX(image/png)XYX"sv, std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/9401.png?v=8)XYX"sv, release_event_pic_orig_9401, release_event_mime_type_orig_9401, release_event_file_ext_orig_9401, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/9401.png?v=8)XYX"sv, release_event_pic_small_thumb_9401, release_event_mime_type_small_thumb_9401, release_event_file_ext_small_thumb_9401, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/9401.png?v=8)XYX"sv, release_event_pic_thumb_9401, release_event_mime_type_thumb_9401, release_event_file_ext_thumb_9401, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/9401.png?v=8)XYX"sv, release_event_pic_tiny_thumb_9401, release_event_mime_type_tiny_thumb_9401, release_event_file_ext_tiny_thumb_9401  };

export constexpr std::array<release_event, 68> events {{
  {R"XYX(ミクFES'09（夏）, Miku FES'09 (Natsu))XYX"sv, "Concert"sv, 2009y/8/31, R"XYX(Hatsune Miku's 2nd anniversary festival.

**Concert Schedule**:

* **August 31st, 2009 (Mon.)**
OPEN 18:00 / START19:00 (JST))XYX"sv, std::nullopt, 2522, picture_release_event_2522, R"XYX(Miku FES'09 (Summer))XYX"sv, names_release_event_2522, std::nullopt, 0, std::nullopt, 219, R"(ミクFES'09（夏）)", "Approved"sv, R"XYX(miku-fes09-natsu)XYX"sv, R"XYX(新木場 StudioCoast)XYX"sv, web_links_release_event_2522 },
  {R"XYX(ミクの日感謝祭39's Giving Day)XYX"sv, "Concert"sv, 2010y/3/9, std::nullopt, std::nullopt, 2520, picture_release_event_2520, R"XYX(Miku no Hi Kanshasai 39's Giving Day)XYX"sv, names_release_event_2520, std::nullopt, 0, std::nullopt, 3952, R"(ミクの日感謝祭 39's Giving Day Project DIVA presents 初音ミク・ソロコンサート～こんばんは、初音ミクです。〜)", "Finished"sv, R"XYX(miku-no-hi-kanshasai-39s-givin)XYX"sv, R"XYX(Zepp Tokyo in Odaiba)XYX"sv, web_links_release_event_2520 },
  {R"XYX(初音ミクライブパーティー 2011 Tokyo, ミクパ 2011 Tokyo, MikuPa 2011 Tokyo)XYX"sv, "Concert"sv, 2011y/3/9, R"XYX(18:00 OPEN ／19:00 START／21:30 CLOSE 予定
___
Concert dates:

- March 9, 2011 (Tokyo)
- August 17, 2011 (Sapporo)
- November 11, 2011 (Singapore))XYX"sv, std::nullopt, 2523, picture_release_event_2523, R"XYX(Hatsune Miku Live Party 2011 Tokyo)XYX"sv, names_release_event_2523, 219, 2011, R"XYX(Tokyo)XYX"sv, 3953, R"(Hatsune Miku Live Party 2011 Mikupa♪ Tokyo)", "Finished"sv, R"XYX(hatsune-miku-live-party-2011-t)XYX"sv, R"XYX(Zepp Tokyo)XYX"sv, web_links_release_event_2523 },
  {R"XYX(MIKUNOPOLIS in LOS ANGELES “はじめまして、初音ミクです”, MIKUNOPOLIS in LOS ANGELES "Hajimemashite, Hatsune Miku Desu", MIKUNOPOLIS in LOS ANGELES “Happy to meet you! I'm HATSUNE MIKU”)XYX"sv, "Concert"sv, 2011y/7/2, std::nullopt, std::nullopt, 2521, picture_release_event_2521, R"XYX(MIKUNOPOLIS in LOS ANGELES “Happy to meet you, I'm HATSUNE MIKU”)XYX"sv, names_release_event_2521, std::nullopt, 0, std::nullopt, 84, R"(MIKUNOPOLIS in LOS ANGELES “Happy to meet you, I'm HATSUNE MIKU”)", "Finished"sv, R"XYX(mikunopolis-in-los-angeles-haj)XYX"sv, R"XYX(Nokia theater)XYX"sv, web_links_release_event_2521 },
  {R"XYX(初音ミクライブパーティー 2011 Sapporo, ミクパ 2011 Sapporo, MikuPa 2011 Sapporo)XYX"sv, "Unspecified"sv, 2011y/8/16, R"XYX(初日公演
8月16日(火)＝17:00 OPEN 18:00 START 20:00 CLOSE予定
二日目公演
8月17日(水)＝15:00 OPEN 16:00 START 18:00 CLOSE予定
___
Concert dates:

- March 9, 2011 (Tokyo)
- August 17, 2011 (Sapporo)
- November 11, 2011 (Singapore))XYX"sv, 2011y/8/17, 2526, picture_release_event_2526, R"XYX(Hatsune Miku Live Party 2011 Sapporo)XYX"sv, names_release_event_2526, 219, 2011, R"XYX(Sapporo)XYX"sv, 12, R"(Hatsune Miku Live Party 2011 Mikupa♪ Sapporo)", "Finished"sv, R"XYX(hatsune-miku-live-party-2011-s)XYX"sv, R"XYX(札幌市教育文化会館 大ホール)XYX"sv, web_links_release_event_2526 },
  {R"XYX(初音ミクライブパーティー 2011 Singapore, ミクパ 2011 Singapore, MikuPa 2011 Singapore)XYX"sv, "Unspecified"sv, 2011y/11/11, R"XYX(Fri, Nov 11, OPEN 18:00／START 19:00
___
Concert dates:

- March 9, 2011 (Tokyo)
- August 17, 2011 (Sapporo)
- November 11, 2011 (Singapore))XYX"sv, std::nullopt, 2527, picture_release_event_2527, R"XYX(Hatsune Miku Live Party 2011 Singapore)XYX"sv, names_release_event_2527, 219, 2011, R"XYX(Singapore)XYX"sv, 1, R"(Hatsune Miku Live Party 2011 Mikupa♪ Singapore)", "Finished"sv, R"XYX(hatsune-miku-live-party-2011-s)XYX"sv, R"XYX(Suntec Singapore Exhibition Hall 402)XYX"sv, web_links_release_event_2527 },
  {R"XYX(初音ミクライブパーティー 2012 Tokyo, ミクパ 2012 Tokyo, MikuPa 2012 Tokyo)XYX"sv, "Unspecified"sv, 2012y/3/8, R"XYX("Hatsune Miku Live Party 2012 (MikuPa)" was held at Tokyo Dome City Hall on March 8, 2012. It was accompanied by the "Miku no Hi Dai Kanshasai 39's Giving Day" concert on the 9th.
___
Concert dates:

- March 8, 2012 (Tokyo)
- October 2, 2012 (Hong Kong)
- October 6, 2012 (Taiwan))XYX"sv, std::nullopt, 4056, picture_release_event_4056, R"XYX(Hatsune Miku Live Party 2012 Tokyo)XYX"sv, names_release_event_4056, 219, 2012, R"XYX(Tokyo)XYX"sv, 217, R"(Hatsune Miku Live Party 2012 Mikupa♪ Tokyo)", "Finished"sv, R"XYX(hatsune-miku-live-party-2012-t)XYX"sv, std::nullopt, web_links_release_event_4056 },
  {R"XYX(ミクの日大感謝祭特番 - 制作日誌39 2012, Miku No Hi Daikanshasai Tokuban - Seisaku Nisshi 39 2012)XYX"sv, "Unspecified"sv, 2012y/3/9, R"XYX("Miku no Hi Dai Kanshasai 39's Giving Day" was held on March 9 and featured both the original -Project DIVA- Arcade graphics. It was accompaned by "Hatsune Miku Live Party 2012 (Mikupa)" the day before. The event took place at Tokyo Dome City Hall.)XYX"sv, std::nullopt, 1413, picture_release_event_1413, R"XYX(Miku's Big Thanksgiving Day - Special 39's Production 2012)XYX"sv, names_release_event_1413, 84, 2012, std::nullopt, 218, R"(Miku's Big Thanksgiving Day - Special 39's Production)", "Finished"sv, R"XYX(miku-no-hi-daikanshasai-tokuba)XYX"sv, R"XYX(Tokyo Dome City Hall)XYX"sv, web_links_release_event_1413 },
  {R"XYX(初音ミクライブパーティー 2012 Hong Kong, ミクパ 2012 Hong Kong, MikuPa 2012 Hong Kong)XYX"sv, "Unspecified"sv, 2012y/10/2, R"XYX(昼公演 14:00／15:00
夜公演 19:00／20:00
___
Concert dates:

- March 8, 2012 (Tokyo)
- October 2, 2012 (Hong Kong)
- October 6, 2012 (Taiwan))XYX"sv, std::nullopt, 2524, picture_release_event_2524, R"XYX(Hatsune Miku Live Party 2012 Hong Kong)XYX"sv, names_release_event_2524, 219, 2012, R"XYX(Hong Kong)XYX"sv, 31, R"(Hatsune Miku Live Party 2012 Mikupa♪ Hong Kong and Taiwan)", "Finished"sv, R"XYX(hatsune-miku-live-party-2012-h)XYX"sv, R"XYX(KITEC Star Hall)XYX"sv, web_links_release_event_2524 },
  {R"XYX(初音ミクライブパーティー 2013 Sapporo, ミクパ 2013 Sapporo, MikuPa 2013 Sapporo)XYX"sv, "Concert"sv, 2013y/2/9, R"XYX(2月9日（土）昼公演 13:00　夜公演 18:00
2月10日（日）昼公演 12:00　夜公演 17:00
___
Concert dates:

- February 9, 2013 (Sapporo)
- February 10, 2013 (Sapporo)
- March 9, 2013 (Kansai))XYX"sv, 2013y/2/10, 2510, picture_release_event_2510, R"XYX(Hatsune Miku Live Party 2013 Sapporo)XYX"sv, names_release_event_2510, 219, 2013, R"XYX(Sapporo)XYX"sv, 82, R"(Hatsune Miku Live Party 2013 Mikupa♪ Sapporo)", "Finished"sv, R"XYX(hatsune-miku-live-party-2013-s)XYX"sv, R"XYX(札幌市民ホール)XYX"sv, web_links_release_event_2510 },
  {R"XYX(初音ミクライブパーティー 2013 Kansai, ミクパ 2013 Kansai, MikuPa 2013 Kansai)XYX"sv, "Concert"sv, 2013y/3/9, R"XYX(artists :
鈴木 啓（Band Master/Manipulator）
木下浩二（Guitar）
中村康太（Guitar）
TABOKUN（Bass）
菊嶋"KIKU"亮一（Drums）
今井 隼（Keyboard）
若森さちこ（Percussion）
___
Concert dates:

- February 9, 2013 (Sapporo)
- February 10, 2013 (Sapporo)
- March 9, 2013 (Kansai))XYX"sv, std::nullopt, 2511, picture_release_event_2511, R"XYX(Hatsune Miku Live Party 2013 Kansai)XYX"sv, names_release_event_2511, 219, 2013, R"XYX(Kansai)XYX"sv, 3954, R"(Hatsune Miku Live Party 2013 Mikupa♪ Kansai)", "Finished"sv, R"XYX(hatsune-miku-live-party-2013-k)XYX"sv, R"XYX(和歌山ビッグホエール)XYX"sv, web_links_release_event_2511 },
  {R"XYX(初音ミク「マジカルミライ 2013」, マジカルミライ 2013, Magical Mirai 2013)XYX"sv, "Unspecified"sv, 2013y/8/30, R"XYX(Daytime : OPEN 12:30 / Showtime 13:30 / Curtain 15:00
Night : OPEN 17:30 / Showtime 19:30)XYX"sv, std::nullopt, 2519, picture_release_event_2519, R"XYX(Hatsune Miku Magical Mirai 2013)XYX"sv, names_release_event_2519, 81, 2013, std::nullopt, 114, R"(Hatsune Miku Magical Mirai 2013)", "Finished"sv, R"XYX(hatsune-miku-magical-mirai-201)XYX"sv, R"XYX(横浜アリーナ)XYX"sv, web_links_release_event_2519 },
  {R"XYX(HATSUNE MIKU EXPO 2014 IN INDONESIA)XYX"sv, "Unspecified"sv, 2014y/5/28, R"XYX(May 28th
The 1st show :Open : 18:30 -Start : 19:30 -
May 29th
The 2nd show :Open : 12:00 -Start : 13:00 -
The 3rd show :Open : 18:30 -Start : 19:30 -)XYX"sv, 2014y/5/29, 1939, picture_release_event_1939, R"XYX(Miku Expo 2014 Jakarta)XYX"sv, names_release_event_1939, 82, 2014, R"XYX(Jakarta)XYX"sv, 213, R"(Miku Expo 2014 Indonesia)", "Finished"sv, R"XYX(miku-expo-2014-jakarta)XYX"sv, std::nullopt, web_links_release_event_1939 },
  {R"XYX(初音ミク「マジカルミライ 2014」in OSAKA, マジカルミライ 2014 Osaka, Magical Mirai 2014 Osaka)XYX"sv, "Unspecified"sv, 2014y/8/30, R"XYX(**Live Show**:
INTEX Osaka Hall 5
August 30th(Sat.)

* 1st Show (Evening): OPEN 11:30 / START 12:30
* 2nd Show (Noon): OPEN 16:00 / START 17:00

**Exhibition**:
INTEX Osaka Hall 4
August 30th(Sat.)

Art by [MONQ](https://vocadb.net/Ar/2200))XYX"sv, std::nullopt, 2517, picture_release_event_2517, R"XYX(Hatsune Miku Magical Mirai 2014 in OSAKA)XYX"sv, names_release_event_2517, 81, 2014, R"XYX(Osaka)XYX"sv, 214, R"(Hatsune Miku Magical Mirai 2014)", "Approved"sv, R"XYX(hatsune-miku-magical-mirai-201)XYX"sv, R"XYX(インテックス大阪)XYX"sv, web_links_release_event_2517 },
  {std::nullopt, "Unspecified"sv, 2014y/10/11, R"XYX(1st Show Oct. 11, 2014
START : 7:00pm (DOORS OPEN : 6:00pm)

2nd Show Oct. 12, 2014
START : 12:30pm (DOORS OPEN : 11:30am))XYX"sv, 2014y/10/12, 1937, picture_release_event_1937, R"XYX(Miku Expo 2014 Los Angeles)XYX"sv, names_release_event_1937, 82, 2014, R"XYX(Los Angeles)XYX"sv, 221, R"(Miku Expo 2014 USA)", "Draft"sv, R"XYX(miku-expo-2014-los-angeles)XYX"sv, R"XYX(Nokia Theatre)XYX"sv, web_links_release_event_1937 },
  {std::nullopt, "Unspecified"sv, 2015y/2/7, R"XYX(**Concert Schedule**:

**February 7th(Sat.)**
Daytime: OPEN: 12:00／START: 13:00
Nighttime: OPEN: 18:00／START: 19:00

**February 8th(Sun.)**
Daytime: OPEN: 12:00／START: 13:00
Nighttime: OPEN: 17:00／START: 18:00

Art by [iXima](https://vocadb.net/Ar/2230))XYX"sv, 2015y/2/8, 3792, picture_release_event_3792, R"XYX(SNOW MIKU LIVE! 2015 presents MIKU EXPO Live Set)XYX"sv, names_release_event_3792, 204, 2015, R"XYX(presents MIKU EXPO Live Set)XYX"sv, 3951, R"(SNOW MIKU LIVE! 2015 presents MIKU EXPO Live Set)", "Finished"sv, R"XYX(snow-miku-live-2015-presents-m)XYX"sv, R"XYX(Zepp Sapporo（北海道）)XYX"sv, web_links_release_event_3792 },
  {std::nullopt, "Unspecified"sv, 2015y/6/27, R"XYX(2015-06-27
day show : 9:30 12:00, night show 16:30 18:00
2015-06-28
day show : 9:30 12:00, night show 16:30 18:00)XYX"sv, 2015y/6/28, 1940, picture_release_event_1940, R"XYX(Miku Expo 2015 Shanghai)XYX"sv, names_release_event_1940, 82, 2015, R"XYX(Shanghai)XYX"sv, 2868, R"(Miku Expo 2015 China)", "Draft"sv, R"XYX(miku-expo-2015-shanghai)XYX"sv, R"XYX(E-Sports Arena)XYX"sv, web_links_release_event_1940 },
  {R"XYX(初音ミク「マジカルミライ 2015」, マジカルミライ 2015, Magical Mirai 2015)XYX"sv, "Unspecified"sv, 2015y/9/4, R"XYX(**Live Show**:
Nippon Budokan
September 4th(Fri.) - 5th(Sat.)

* 1st and 3rd show (Noon): OPEN 17:30 / START 18:30
* 2nd show (Evening): OPEN 11:00 / START 12:30

**Exhibition**:
Science Museum
September 4th(Fri.) - 6th(Sun.)

Art by [穂嶋](https://vocadb.net/Ar/11782))XYX"sv, 2015y/9/6, 2514, picture_release_event_2514, R"XYX(Hatsune Miku Magical Mirai 2015)XYX"sv, names_release_event_2514, 81, 2015, std::nullopt, 3985, R"(Hatsune Miku Magical Mirai 2015)", "Approved"sv, R"XYX(hatsune-miku-magical-mirai-201)XYX"sv, R"XYX(日本武道館)XYX"sv, web_links_release_event_2514 },
  {std::nullopt, "Unspecified"sv, 2016y/3/23, R"XYX(2016.3.23
Night Show
18:00 / 19:00

2016.3.24
Night Show
18:00 / 19:00
)XYX"sv, 2016y/3/24, 1399, picture_release_event_1399, R"XYX(Miku Expo 2016 Fukuoka)XYX"sv, names_release_event_1399, 82, 2016, R"XYX(Fukuoka)XYX"sv, 6570, R"(Miku Expo 2016 Japan)", "Finished"sv, R"XYX(miku-expo-2016-fukuoka)XYX"sv, R"XYX(Zepp Fukuoka)XYX"sv, web_links_release_event_1399 },
  {std::nullopt, "Unspecified"sv, 2016y/4/23, std::nullopt, std::nullopt, 1859, picture_release_event_1859, R"XYX(Miku Expo 2016 Seattle)XYX"sv, names_release_event_1859, 82, 2016, R"XYX(Seattle)XYX"sv, 6571, R"(Miku Expo 2016 North America)", "Finished"sv, R"XYX(miku-expo-2016-seattle)XYX"sv, R"XYX(Seattle, Washington: WaMu Theater)XYX"sv, web_links_release_event_1859 },
  {std::nullopt, "Unspecified"sv, 2016y/6/25, std::nullopt, 2016y/6/26, 1941, picture_release_event_1941, R"XYX(Miku Expo 2016 New Taipei City)XYX"sv, names_release_event_1941, 82, 2016, R"XYX(New Taipei City)XYX"sv, 6572, R"(Miku Expo 2016 Taiwan)", "Finished"sv, R"XYX(miku-expo-2016-new-taipei-city)XYX"sv, R"XYX(New Taipei City Exhibition Hall)XYX"sv, web_links_release_event_1941 },
  {R"XYX(初音ミク「マジカルミライ 2016」, マジカルミライ 2016, Magical Mirai 2016)XYX"sv, "Unspecified"sv, 2016y/9/9, R"XYX(**Live Show**:
Makuhari Messe International Exhibition Hall 9
September 10th(Sat.) - 11th(Sun.)

**Exhibition**:
Makuhari Messe International Exhibition Hall 10 & 11
September 9th(Fri.) - 11th(Sun.)

Art by [LENA[A-7]](https://vocadb.net/Ar/83909))XYX"sv, 2016y/9/11, 1398, picture_release_event_1398, R"XYX(Hatsune Miku Magical Mirai 2016)XYX"sv, names_release_event_1398, 81, 2016, std::nullopt, 6652, R"(Hatsune Miku Magical Mirai 2016)", "Approved"sv, R"XYX(hatsune-miku-magical-mirai-201)XYX"sv, R"XYX(幕張メッセ国際展示場 / Makuhari Messe International Exhibition Hall)XYX"sv, web_links_release_event_1398 },
  {std::nullopt, "Unspecified"sv, 2016y/12/3, std::nullopt, 2016y/12/4, 1943, picture_release_event_1943, R"XYX(Miku Expo 2016 Shanghai)XYX"sv, names_release_event_1943, 82, 2016, R"XYX(Shanghai)XYX"sv, 6950, R"(Miku Expo 2016 China)", "Draft"sv, R"XYX(miku-expo-2016-shanghai)XYX"sv, R"XYX(Shanghai Happy Valley)XYX"sv, web_links_release_event_1943 },
  {R"XYX(初音ミク×鼓童スペシャルライブ, 初音ミク×鼓童　スペシャルライブ | Ｔｈｉｓ　ｉｓ　ＮＩＰＰＯＮ　プレミアムシアター, Hatsune Miku × Kodō Special Live | This is NIPPON Premium Theater)XYX"sv, "Unspecified"sv, 2017y/3/4, std::nullopt, 2017y/3/5, 2947, picture_release_event_2947, R"XYX(Hatsune Miku × Kodō Special Live)XYX"sv, names_release_event_2947, 255, 0, std::nullopt, 7024, R"(Hatsune Miku × Kodō Special Live)", "Finished"sv, R"XYX(hatsune-miku--kod-special-live)XYX"sv, R"XYX(NHK Hall (Shibuya, Tokyo))XYX"sv, web_links_release_event_2947 },
  {R"XYX(初音ミク「マジカルミライ 2017」, マジカルミライ 2017, Magical Mirai 2017)XYX"sv, "Unspecified"sv, 2017y/9/1, R"XYX(**Live Show**:
Makuhari Messe International Exhibition Hall 3
September 1st(Fri.) - 3rd(Sun.)

* September 2nd and 3rd had two shows each, noon and evening.

**Exhibition**:
Makuhari Messe International Exhibition Hall 1, 2
September 1st(Fri.) - 3rd(Sun.)

* Tickets were available by applying to a lottery or purchasing accommodation plan. Accommodation plans were sold first-come, first-served -basis. There were separate lottery and accommodation plans for Japanese attendees and foreigners.

Art by [iXima](https://vocadb.net/Ar/2230))XYX"sv, 2017y/9/3, 1397, picture_release_event_1397, R"XYX(Hatsune Miku Magical Mirai 2017)XYX"sv, names_release_event_1397, 81, 2017, std::nullopt, 6915, R"(Hatsune Miku Magical Mirai 2017)", "Approved"sv, R"XYX(hatsune-miku-magical-mirai-201)XYX"sv, R"XYX(Makuhari Messe)XYX"sv, web_links_release_event_1397 },
  {R"XYX(未来有你·初音未来 2017 上海演唱会, 未来（ミク）には君がいる·初音ミク２０１７上海ライブ)XYX"sv, "Concert"sv, 2017y/11/25, std::nullopt, std::nullopt, 1619, picture_release_event_1619, R"XYX(HATSUNE MIKU with YOU 2017 CHINA FESTIVAL)XYX"sv, names_release_event_1619, 173, 2017, R"XYX(in Shanghai)XYX"sv, 7384, R"(HATSUNE MIKU with YOU 2017 CHINA FESTIVAL)", "Finished"sv, R"XYX(hatsune-miku-with-you-2017-chi)XYX"sv, R"XYX(上海新国际博览中心E5馆)XYX"sv, web_links_release_event_1619 },
  {std::nullopt, "Unspecified"sv, 2017y/12/16, R"XYX(Door: 6PM Show: 8PM)XYX"sv, std::nullopt, 1584, picture_release_event_1584, R"XYX(Miku Expo 2017 Kuala Lumpur)XYX"sv, names_release_event_1584, 82, 2017, R"XYX(Kuala Lumpur)XYX"sv, 7404, R"(Miku Expo 2017 Malaysia)", "Draft"sv, R"XYX(miku-expo-2017-kuala-lumpur)XYX"sv, R"XYX(Kuala Lumpur Axiata Arena(Bukit Jalil))XYX"sv, web_links_release_event_1584 },
  {std::nullopt, "Concert"sv, 2018y/2/9, R"XYX(**Concert Schedule**:

**February 9th(Fri.)**
Daytime: OPEN: 13:00 / START: 14:00
Nighttime: OPEN: 18:00 / START: 19:00

**February 10th(Sat.)**
Daytime: OPEN: 13:00 / START: 14:00
Nighttime: OPEN: 17:00 / START: 18:00

Art by [やすも](https://vocadb.net/Ar/63429))XYX"sv, 2018y/2/10, 1618, picture_release_event_1618, R"XYX(SNOW MIKU LIVE! 2018)XYX"sv, names_release_event_1618, 204, 2018, std::nullopt, 7339, R"(SNOW MIKU LIVE! 2018)", "Finished"sv, R"XYX(snow-miku-live-2018)XYX"sv, R"XYX(Zepp Sapporo（北海道）)XYX"sv, web_links_release_event_1618 },
  {R"XYX(Ｔｈｉｓ　ｉｓ　ＮＩＰＰＯＮ　プレミアムシアター 初音ミク×鼓童　スペシャルライブ　２０１８)XYX"sv, "Unspecified"sv, 2018y/6/2, R"XYX(■ Date and time:
・June 2, 2018 (Saturday)
 Open 12:00 / Start 13:00
 Open 18:00 / Start 19:00
・June 3, 2018 (Sunday)
 Open 12:00 / Start 13:00

* All times JST)XYX"sv, 2018y/6/3, 2948, picture_release_event_2948, R"XYX(This is NIPPON Premium Theater Hatsune Miku × Kodō Special Live 2018)XYX"sv, names_release_event_2948, 255, 0, std::nullopt, 8961, R"(Hatsune Miku × Kodō Special Live 2018)", "Finished"sv, R"XYX(this-is-nippon-premium-theater)XYX"sv, R"XYX(NHK Hall (Shibuya, Tokyo))XYX"sv, web_links_release_event_2948 },
  {std::nullopt, "Unspecified"sv, 2018y/6/29, std::nullopt, std::nullopt, 1673, picture_release_event_1673, R"XYX(Miku Expo 2018 Los Angeles)XYX"sv, names_release_event_1673, 82, 2018, R"XYX(Los Angeles)XYX"sv, 7758, R"(Miku Expo 2018 North America)", "Finished"sv, R"XYX(miku-expo-2018-los-angeles)XYX"sv, R"XYX(Microsoft Theater)XYX"sv, web_links_release_event_1673 },
  {R"XYX(初音ミク「マジカルミライ 2018」in OSAKA, マジカルミライ 2018 Osaka, Magical Mirai 2018 Osaka)XYX"sv, "Unspecified"sv, 2018y/8/25, R"XYX(**Live Show**:
INTEX Osaka A ZONE, Hall 5
August 25th(Sat.) - 26th(Sun.)

**Exhibition**:
INTEX Osaka Hall 4
August 25th(Sat.) - 26th(Sun.)

Art by [Mika Pikazo](https://vocadb.net/Ar/32604))XYX"sv, 2018y/8/26, 1561, picture_release_event_1561, R"XYX(Hatsune Miku Magical Mirai 2018 in OSAKA)XYX"sv, names_release_event_1561, 81, 2018, R"XYX(Osaka)XYX"sv, 7852, R"(Hatsune Miku Magical Mirai 2018)", "Approved"sv, R"XYX(hatsune-miku-magical-mirai-201)XYX"sv, R"XYX(INTEX Osaka, Osaka, Japan)XYX"sv, web_links_release_event_1561 },
  {R"XYX(未来有你 2018 in Beijing, HATSUNE MIKU WITH YOU 2018 in Beijing)XYX"sv, "Unspecified"sv, 2018y/10/13, R"XYX(Art by Nekosakana

Main visual (Website) by YYB)XYX"sv, std::nullopt, 2085, picture_release_event_2085, R"XYX(MIKU WITH YOU 2018 in Beijing)XYX"sv, names_release_event_2085, 173, 2018, R"XYX(in Beijing)XYX"sv, 7986, R"(MIKU WITH YOU 2018)", "Finished"sv, R"XYX(miku-with-you-2018-in-beijing)XYX"sv, R"XYX(五棵松M空间 (M Space))XYX"sv, web_links_release_event_2085 },
  {std::nullopt, "Unspecified"sv, 2018y/12/1, R"XYX(Samedi 1 décembre 2018 - 20h30
48° 49′ 26″ N, 2° 14′ 00″ E)XYX"sv, std::nullopt, 1854, picture_release_event_1854, R"XYX(Miku Expo 2018 Paris)XYX"sv, names_release_event_1854, 82, 2018, R"XYX(Paris)XYX"sv, 7979, R"(Miku Expo 2018 Paris)", "Finished"sv, R"XYX(miku-expo-2018-paris)XYX"sv, R"XYX(La Seine Musicale, Île Seguin, 92100 Boulogne-Billancourt)XYX"sv, web_links_release_event_1854 },
  {std::nullopt, "Unspecified"sv, 2019y/2/9, R"XYX(**Concert Schedule**:

**February 9th(Sat.)**
Daytime: OPEN: 13:00 / START: 14:00
Nighttime: OPEN: 18:00 / START: 19:00

**February 10th(Sun.)**
Daytime: OPEN: 13:00 / START: 14:00
Nighttime: OPEN: 17:00 / START: 18:00

Art by [KEI](https://vocadb.net/Ar/9213))XYX"sv, 2019y/2/10, 2422, picture_release_event_2422, R"XYX(SNOW MIKU LIVE! 2019)XYX"sv, names_release_event_2422, 204, 2019, std::nullopt, 8099, R"(SNOW MIKU LIVE! 2019 )", "Finished"sv, R"XYX(snow-miku-live-2019)XYX"sv, R"XYX(Zepp Sapporo（北海道）)XYX"sv, web_links_release_event_2422 },
  {std::nullopt, "Unspecified"sv, 2019y/5/11, std::nullopt, std::nullopt, 2489, picture_release_event_2489, R"XYX(Miku Expo 2019 New Taipei City)XYX"sv, names_release_event_2489, 82, 2019, R"XYX(New Taipei City)XYX"sv, 8103, R"(Miku Expo 2019 New Taipei City)", "Finished"sv, R"XYX(miku-expo-2019-new-taipei-city)XYX"sv, R"XYX(New Taipei City Exhibition Hall)XYX"sv, web_links_release_event_2489 },
  {R"XYX(初音ミク「マジカルミライ 2019」in OSAKA, マジカルミライ 2019 Osaka, Magical Mirai 2019 Osaka)XYX"sv, "Unspecified"sv, 2019y/8/9, R"XYX(Magical Mirai 2019's theme is "Future Circus"

**Live Show**:
INTEX Osaka Hall 5A
August 10th(Sat.) - 11th(Sun.)

**Exhibition**:
INTEX Osaka Hall 4,5B
August 9th(Fri.) - 11th(Sun.)

Art by [ni02](https://vocadb.net/Ar/74337))XYX"sv, 2019y/8/11, 2515, picture_release_event_2515, R"XYX(Hatsune Miku Magical Mirai 2019 in OSAKA)XYX"sv, names_release_event_2515, 81, 2019, R"XYX(Osaka)XYX"sv, 8102, R"(Hatsune Miku Magical Mirai 2019 in OSAKA)", "Approved"sv, R"XYX(hatsune-miku-magical-mirai-201)XYX"sv, R"XYX(インテックス大阪)XYX"sv, web_links_release_event_2515 },
  {R"XYX(未来有你 2019 in Shanghai, HATSUNE MIKU WITH YOU 2019 in Shanghai)XYX"sv, "Unspecified"sv, 2019y/11/2, std::nullopt, 2019y/11/3, 3752, picture_release_event_3752, R"XYX(MIKU WITH YOU 2019 in Shanghai)XYX"sv, names_release_event_3752, 173, 2019, R"XYX(in Shanghai)XYX"sv, 9359, R"(MIKU WITH YOU 2019)", "Finished"sv, R"XYX(miku-with-you-2019-in-shanghai)XYX"sv, R"XYX(1862 Theater)XYX"sv, web_links_release_event_3752 },
  {std::nullopt, "Unspecified"sv, 2020y/1/11, R"XYX(17:00 to 22:00)XYX"sv, std::nullopt, 2786, picture_release_event_2786, R"XYX(Miku Expo 2020 London)XYX"sv, names_release_event_2786, 82, 2020, std::nullopt, 8631, R"(Miku Expo 2020 London/Berlin)", "Draft"sv, R"XYX(miku-expo-2020-london)XYX"sv, R"XYX(O2 Academy Brixton)XYX"sv, web_links_release_event_2786 },
  {R"XYX(ニコニコネット超会議2020夏✕HATSUNE MIKU LIVE - UNTITLED 0 -)XYX"sv, "Concert"sv, 2020y/8/9, R"XYX(A live performance at the opening of the Nico Nico Net Chokaigi 2020 Summer event.

Date & Starting time: August 9th, 2020, 7pm JST
Time Shift Deadline: September 8th, 2020, 11:59pm JST
Net Ticket: [Purchase link](https://secure.live.nicovideo.jp/event/lv327105822)
Price: 4,800 Nico Nico Points (4,800 yen including tax)
Purchase Deadline: September 7th, 2020, 11:59pm JST)XYX"sv, std::nullopt, 2939, picture_release_event_2939, R"XYX(Nico Nico Net Chokaigi 2020 Natsu ✕ HATSUNE MIKU LIVE - UNTITLED 0 -)XYX"sv, names_release_event_2939, std::nullopt, 0, std::nullopt, 8940, R"(HATSUNE MIKU LIVE - UNTITLED 0 - )", "Finished"sv, R"XYX(nico-nico-net-chokaigi-2020-na)XYX"sv, std::nullopt, web_links_release_event_2939 },
  {R"XYX(初音ミク GALAXY LIVE 2020)XYX"sv, "Concert"sv, 2020y/9/26, R"XYX(**Concert Schedule**:

DAY 1: September 26th, 2020 19:00 (OPEN 18:30)
DAY 2: September 27th, 2020 19:00 (OPEN 18:30)

* All times JST.

**Venue**:

INSPIX LIVE ([App Store](https://apps.apple.com/jp/app/inspix-live/id1471497988) / [Google Play](https://play.google.com/store/apps/details?id=com.pulse227.inspix&hl=ja))

**Admission Tickets start (free)**:

September 5th, 2020 12:00
* Tickets are required to enter.
* Tickets can be obtained after installing the app and registering as a free member.

Art by [のう](https://vocadb.net/Ar/10026), Design by [kannnu](https://twitter.com/sirakannnu))XYX"sv, 2020y/9/27, 2952, picture_release_event_2952, R"XYX(Hatsune Miku GALAXY LIVE 2020)XYX"sv, names_release_event_2952, 314, 2020, std::nullopt, 9083, R"(Hatsune Miku GALAXY LIVE 2020)", "Finished"sv, R"XYX(hatsune-miku-galaxy-live-2020)XYX"sv, R"XYX(INSPIX LIVE)XYX"sv, web_links_release_event_2952 },
  {R"XYX(初音ミク「マジカルミライ 2020」in OSAKA, マジカルミライ 2020 Osaka, Magical Mirai 2020 Osaka)XYX"sv, "Unspecified"sv, 2020y/11/27, R"XYX(Magical Mirai 2020’s theme is “MATSURI”.

**Live Show**:
INTEX Osaka Hall 5A
November 28th(Sat.) - 29th(Sun.)

**Exhibition**:
INTEX Osaka Hall 3, 4
November 27th(Fri.) - 29th(Sun.)

The concert was also streamed online on November 29th(Sun.).

Art by [藤ちょこ](https://vocadb.net/Ar/9328))XYX"sv, 2020y/11/29, 2758, picture_release_event_2758, R"XYX(Hatsune Miku Magical Mirai 2020 in OSAKA)XYX"sv, names_release_event_2758, 81, 2020, R"XYX(Osaka)XYX"sv, 9131, R"(Hatsune Miku Magical Mirai 2020 in OSAKA)", "Approved"sv, R"XYX(hatsune-miku-magical-mirai-202)XYX"sv, R"XYX(INTEX Osaka Hall 4,5A)XYX"sv, web_links_release_event_2758 },
  {R"XYX(未来有你 2020, HATSUNE MIKU WITH YOU 2020)XYX"sv, "Unspecified"sv, 2020y/12/25, std::nullopt, std::nullopt, 3250, picture_release_event_3250, R"XYX(MIKU WITH YOU 2020)XYX"sv, names_release_event_3250, 173, 2020, std::nullopt, 9192, R"(MIKU WITH YOU 2020)", "Finished"sv, R"XYX(miku-with-you-2020)XYX"sv, std::nullopt, web_links_release_event_3250 },
  {R"XYX(HATSUNE MIKU EXPO 2021 Online)XYX"sv, "Unspecified"sv, 2021y/6/6, R"XYX(First ever online MIKU EXPO live concert, the show was funded through [Kickstarter](https://www.kickstarter.com/projects/cryptonfuturemedia/hatsune-miku-global-concert-hatsune-miku-expo-2021-online) and was streamed for free.

**Concert Schedule**:

* **June 6th(Sun.)**
1st Show: Daytime (OPEN 10:00 / START 12:30 / CLOSE 2:00)
2nd Show: Nighttime (OPEN 5:00 / START 7:30 / CLOSE 9:00)
3rd Show: Nighttime (OPEN 9:00 / START 11:30 / CLOSE 1:00)

* All times JST

**Streaming Platform**: YouTube Live ([HatsuneMiku](https://www.youtube.com/channel/UCJwGWV914kBlV4dKRn7AEFA)) / Twitch ([@cfm_official](https://www.twitch.tv/cfm_official))

**Sub-events**:

* [MIKU EXPO Digital Stars 2021 Online](https://vocadb.net/E/3706/miku-expo-digital-stars-2021-o)
* [#MIKU WORLD GALLERY](https://paint.mikuexpo.com/MikuWorldGallery/)
* LET'S PAINT 3.0

Art by ryota)XYX"sv, std::nullopt, 3224, picture_release_event_3224, R"XYX(Miku Expo 2021 Online)XYX"sv, names_release_event_3224, 82, 2021, std::nullopt, 9596, R"(HATSUNE MIKU EXPO 2021 Online)", "Approved"sv, R"XYX(miku-expo-2021-online)XYX"sv, R"XYX(YouTube Live / Twitch)XYX"sv, web_links_release_event_3224 },
  {R"XYX(初音ミク「マジカルミライ 2021」in OSAKA)XYX"sv, "Unspecified"sv, 2021y/10/22, R"XYX(Magical Mirai 2021’s theme is “Fairy Tale Fantasy”.

**Live Show**:
INTEX Osaka Hall 5A
October 22nd(Fri.) - 24th(Sun.)

**Exhibition**:
INTEX Osaka Hall 4
October 22nd(Fri.) - 24th(Sun.)

Art by [左](https://vocadb.net/Ar/3104))XYX"sv, 2021y/10/24, 3305, picture_release_event_3305, R"XYX(Hatsune Miku "Magical Mirai 2021" in OSAKA)XYX"sv, names_release_event_3305, 81, 2021, std::nullopt, 9909, R"(Hatsune Miku Magical Mirai 2021)", "Approved"sv, R"XYX(hatsune-miku-magical-mirai-202)XYX"sv, std::nullopt, web_links_release_event_3305 },
  {R"XYX(初音ミク GALAXY LIVE 2021)XYX"sv, "Unspecified"sv, 2021y/12/18, R"XYX(Art by れおえん)XYX"sv, 2021y/12/19, 3979, picture_release_event_3979, R"XYX(Hatsune Miku GALAXY LIVE 2021)XYX"sv, names_release_event_3979, 314, 2021, std::nullopt, 9993, R"(Hatsune Miku GALAXY LIVE 2021)", "Finished"sv, R"XYX(hatsune-miku-galaxy-live-2021)XYX"sv, R"XYX(INSPIX LIVE)XYX"sv, web_links_release_event_3979 },
  {R"XYX(未来有你 2021, HATSUNE MIKU WITH YOU 2021)XYX"sv, "Unspecified"sv, 2021y/12/25, R"XYX(Art by Liita)XYX"sv, std::nullopt, 4058, picture_release_event_4058, R"XYX(MIKU WITH YOU 2021)XYX"sv, names_release_event_4058, 173, 2021, std::nullopt, 10011, R"(MIKU WITH YOU 2021)", "Finished"sv, R"XYX(miku-with-you-2021)XYX"sv, std::nullopt, web_links_release_event_4058 },
  {R"XYX(HATSUNE MIKU EXPO ЯƎWIИᗡ, HATSUNE MIKU EXPO Rewind)XYX"sv, "Concert"sv, 2022y/6/5, R"XYX(Livestream concert of selected clips from past MIKU EXPO performances, streamed for free.

**Concert Schedule**:

* **June 5th(Sun.)**
1st Show: Daytime (OPEN 10:30 / START 12:30 / CLOSE 2:00)
2nd Show: Nighttime (OPEN 5:30 / START 7:30 / CLOSE 9:00)
3rd Show: Nighttime (OPEN 9:30 / START 11:30 / CLOSE 1:00)

* All times JST

**Streaming Platform**: YouTube Live ([HatsuneMiku](https://www.youtube.com/channel/UCJwGWV914kBlV4dKRn7AEFA)) / Twitch ([@cfm_official](https://www.twitch.tv/cfm_official))

**Sub-events**:

* Let’s paint 3.9
* MIKU EXPO Rewind Gallery
* [MIKU EXPO Digital Stars 2022 Online](https://vocadb.net/E/4276/miku-expo-digital-stars-2022-o)

Art by [Zambiie](https://twitter.com/Margikrap))XYX"sv, std::nullopt, 4114, picture_release_event_4114, R"XYX(Miku Expo Rewind)XYX"sv, names_release_event_4114, 82, 2022, std::nullopt, 10387, R"(HATSUNE MIKU EXPO Rewind)", "Finished"sv, R"XYX(miku-expo-rewind)XYX"sv, R"XYX(YouTube Live / Twitch)XYX"sv, web_links_release_event_4114 },
  {R"XYX(鏡音リン・レン Happy 14th Birthday Party「Two You☆★」)XYX"sv, "Concert"sv, 2022y/7/7, R"XYX(Kagamine Rin and Len first solo live concert.

**Concert Schedule**:

* **DAY1 July 7th(Thu.)**
Daytime: RIN PARTY (OPEN 13:00 / START 14:00)
Nighttime: RIN&LEN PARTY (OPEN 18:00 / START 19:00)

* **DAY2 July 8th(Fri.)**
Daytime: LEN PARTY (OPEN 13:00 / START 14:00)
Nighttime: RIN&LEN PARTY (OPEN 18:00 / START 19:00)

* All times JST

Art by [たま](https://vocadb.net/Ar/1724))XYX"sv, 2022y/7/8, 4161, picture_release_event_4161, R"XYX(Kagamine Rin・Len Happy 14th Birthday Party "Two You☆★")XYX"sv, names_release_event_4161, std::nullopt, 0, std::nullopt, 10469, R"(Kagamine Rin・Len Happy 14th Birthday Party "Two You☆★")", "Finished"sv, R"XYX(kagamine-rinlen-happy-14th-bir)XYX"sv, std::nullopt, web_links_release_event_4161 },
  {R"XYX(初音ミク「マジカルミライ」10th Anniversary in OSAKA, 初音ミク「マジカルミライ 2022」in OSAKA)XYX"sv, "Unspecified"sv, 2022y/8/12, R"XYX(Magical Mirai 10th anniversary theme is "retro-future".

**Live Show**:
INTEX Osaka Hall 5A
August 12th(Fri.) - 14th(Sun.)

**Exhibition**:
INTEX Osaka Hall 4
August 12th(Fri.) - 14th(Sun.)

Art by [KEI](https://vocadb.net/Ar/9213))XYX"sv, 2022y/8/14, 4233, picture_release_event_4233, R"XYX(Hatsune Miku "Magical Mirai" 10th Anniversary in OSAKA)XYX"sv, names_release_event_4233, 81, 2022, std::nullopt, 10556, R"(Hatsune Miku "Magical Mirai" 10th Anniversary (OSAKA & TOKYO))", "Approved"sv, R"XYX(hatsune-miku-magical-mirai-10t)XYX"sv, std::nullopt, web_links_release_event_4233 },
  {R"XYX(HATSUNE MIKU EXPO Rewind+)XYX"sv, "Unspecified"sv, 2022y/11/6, R"XYX(New augmented edition of the [HATSUNE MIKU EXPO Rewind](https://vocadb.net/E/4114/hatsune-miku-expo-rewind) event, including new footage that has not been released in archives or on DVD. Streamed for free.

**Concert Schedule**:

* **November 6th(Sun.)**
1st Show: OPEN 9:00 / START 10:30 / CLOSE 13:00
2nd Show: OPEN 16:00 / START 17:30 / CLOSE 20:00

* All times JST

**Streaming Platform**: YouTube Live ([HatsuneMiku](https://www.youtube.com/channel/UCJwGWV914kBlV4dKRn7AEFA)) / Twitch ([@cfm_official](https://www.twitch.tv/cfm_official))

**Sub-events**:

* Let’s paint 3.939
* MIKU EXPO Rewind+ Gallery
* MIKU EXPO Rewind+ Digital Stars Online

Art by [Zambiie](https://twitter.com/Margikrap))XYX"sv, std::nullopt, 4490, picture_release_event_4490, R"XYX(Miku Expo Rewind+)XYX"sv, names_release_event_4490, 82, 2022, std::nullopt, 10913, R"(HATSUNE MIKU EXPO Rewind+)", "Finished"sv, R"XYX(miku-expo-rewind)XYX"sv, R"XYX(YouTube Live / Twitch)XYX"sv, web_links_release_event_4490 },
  {R"XYX(初音ミク「マジカルミライ」10th Anniversary in SAPPORO, 初音ミク「マジカルミライ 2022」in SAPPORO)XYX"sv, "Unspecified"sv, 2023y/2/4, R"XYX(Magical Mirai 10th anniversary theme is "retro-future".

Held in conjunction with [SNOW MIKU 2023](https://vocadb.net/E/4818/snow-miku-2023)

**Concert Schedule**:

* **DAY1 February 4th(Sat.)**
1st Show: OPEN 11:30 / START 12:30
2nd Show: OPEN 15:00 / START 16:00

* **DAY2 February 5th(Sun.)**
1st Show: OPEN 11:30 / START 12:30
2nd Show: OPEN 15:00 / START 16:00

* All times JST

Art by [KEI](https://vocadb.net/Ar/9213))XYX"sv, 2023y/2/5, 4235, picture_release_event_4235, R"XYX(Hatsune Miku "Magical Mirai" 10th Anniversary in SAPPORO)XYX"sv, names_release_event_4235, 81, 2023, std::nullopt, 12354, R"(Hatsune Miku "Magical Mirai" 10th Anniversary (SAPPORO))", "Finished"sv, R"XYX(hatsune-miku-magical-mirai-10t)XYX"sv, std::nullopt, web_links_release_event_4235 },
  {R"XYX(初音ミク JAPAN TOUR 2023 〜THUNDERBOLT〜 名古屋)XYX"sv, "Unspecified"sv, 2023y/2/23, R"XYX(**Concert Schedule**:

* **February 23rd, 2023 (Thu.)**
1st Show: OPEN 12:00 / START 13:00
2nd Show: OPEN 17:00 / START 18:00

* All times JST)XYX"sv, std::nullopt, 4765, picture_release_event_4765, R"XYX(HATSUNE MIKU JAPAN TOUR 2023 〜THUNDERBOLT〜 NAGOYA)XYX"sv, names_release_event_4765, 408, 1, std::nullopt, 12457, R"(初音ミク JAPAN TOUR 2023 〜THUNDERBOLT〜)", "Finished"sv, R"XYX(hatsune-miku-japan-tour-2023-t)XYX"sv, R"XYX(Zepp Nagoya)XYX"sv, web_links_release_event_4765 },
  {R"XYX(初音ミク×鼓童スペシャルライブ２０２３ ～結～)XYX"sv, "Unspecified"sv, 2023y/6/3, R"XYX(Hatsune Miku x Kodo last live performance.

**Concert Schedule**

* **June 3rd, 2023 (Sat.)**
1st Show: OPEN 12:00 / START 13:00
2nd Show: OPEN 18:00 / START 19:00 

* **June 4th, 2023 (Sun.)**
OPEN 12:00 / START 13:00

* All times JST)XYX"sv, 2023y/6/4, 5910, picture_release_event_5910, R"XYX(Hatsune Miku × Kodō Special Live 2023 ~Yui~)XYX"sv, names_release_event_5910, 255, 2023, std::nullopt, 13030, R"(Hatsune Miku × Kodō Special Live 2023 ~Yui~)", "Finished"sv, R"XYX(hatsune-miku--kod-special-live)XYX"sv, std::nullopt, web_links_release_event_5910 },
  {R"XYX(初音ミク「マジカルミライ 2023」in OSAKA)XYX"sv, "Unspecified"sv, 2023y/8/11, R"XYX(Magical Mirai 2023 theme is "[HERO](https://vocadb.net/S/501613)".

**Concert Schedule**:

* **DAY 1 August 11th, 2023 (Fri.)**
OPEN 17:30 / START 18:30 / CLOSE 20:30

* **DAY 2 August 12th, 2023 (Sat.)**
**1st Show**: OPEN 11:30 / START 12:30 / CLOSE 14:30
**2nd Show**: OPEN 16:30 / START 17:30 / CLOSE 19:30

* **DAY 3 August 13th, 2023 (Sun.)**
**1st Show**: OPEN 11:30 / START 12:30 / CLOSE 14:30
**2nd Show**: OPEN 16:30 / START 17:30 / CLOSE 19:30

* **Venue**: INTEX Osaka Hall 5A

* **Exhibition**: INTEX Osaka Hall 4,5B
August 11th (Fri.) ~ August 13th (Sun.)

* All times JST

Art by [LAM](https://vocadb.net/Ar/59773))XYX"sv, 2023y/8/13, 6045, picture_release_event_6045, R"XYX(Hatsune Miku "Magical Mirai 2023" in OSAKA)XYX"sv, names_release_event_6045, 81, 2023, std::nullopt, 13440, R"(Hatsune Miku "Magical Mirai" 2023)", "Approved"sv, R"XYX(hatsune-miku-magical-mirai-202)XYX"sv, std::nullopt, web_links_release_event_6045 },
  {R"XYX(HATSUNE MIKU EXPO 2023 VR)XYX"sv, "Unspecified"sv, 2023y/11/12, R"XYX(MIKU EXPO's first ever VR online concert, produced through a crowdfunding campaign on Kickstarter.

The show will be streamed for free both in VR and as a concert video.

**Concert schedule** 
* **November 12th, 2023**
1st Show: (OPEN 9:00 / START 11:00 / CLOSE 12:15)
2nd Show: (OPEN 15:00 / START 17:00 / CLOSE 18:15)
3rd Show: (OPEN 19:00 / START 21:00 / CLOSE 22:15)

* All times JST

**Streaming Platform**: YouTube Live ([HatsuneMiku](https://www.youtube.com/channel/UCJwGWV914kBlV4dKRn7AEFA)) / Twitch ([@cfm_official](https://www.twitch.tv/cfm_official))

**Sub-events**:

* Let’s paint 4.0
* #MIKU WORLD GALLERY
* [MIKU EXPO Digital Stars 2023 Online](https://vocadb.net/E/6510/miku-expo-digital-stars-2023-o)

Art by Bukurote)XYX"sv, std::nullopt, 5751, picture_release_event_5751, R"XYX(Miku Expo 2023 VR)XYX"sv, names_release_event_5751, 82, 2023, std::nullopt, 14426, R"(HATSUNE MIKU EXPO 2023 VR Setlist)", "Finished"sv, R"XYX(miku-expo-2023-vr)XYX"sv, std::nullopt, web_links_release_event_5751 },
  {R"XYX(MK15th project MEIKO＆KAITO オンラインコンサート)XYX"sv, "Concert"sv, 2024y/2/24, R"XYX(A short online concert celebrating MEIKO and KAITO's 15th anniversary.

**Concert Schedule:** February 24, 2024 (Sat) 19:00 ~ 20:00 JST

**Streaming Platform:** YouTube ([HatsuneMiku](https://www.youtube.com/channel/UCJwGWV914kBlV4dKRn7AEFA)))XYX"sv, std::nullopt, 6539, picture_release_event_6539, R"XYX(MK15th project MEIKO＆KAITO Online Concert)XYX"sv, names_release_event_6539, std::nullopt, 0, std::nullopt, 15303, R"(MK15th project　MEIKO&KAITO オンラインコンサート)", "Finished"sv, R"XYX(mk15th-project-meikokaito-onli)XYX"sv, std::nullopt, web_links_release_event_6539 },
  {R"XYX(MIKU FES'24 (春)〜Happy 16th Birthday〜, MIKU FES'24 (Haru)〜Happy 16th Birthday〜)XYX"sv, "Concert"sv, 2024y/3/31, std::nullopt, std::nullopt, 6986, picture_release_event_6986, R"XYX(MIKU FES'24 (Spring)〜Happy 16th Birthday〜)XYX"sv, names_release_event_6986, std::nullopt, 0, std::nullopt, 16628, R"(MIKU FES'24 (春)〜Happy 16th Birthday〜)", "Finished"sv, R"XYX(miku-fes24-haruhappy-16th-birt)XYX"sv, std::nullopt, web_links_release_event_6986 },
  {std::nullopt, "Unspecified"sv, 2024y/4/4, R"XYX(HATSUNE MIKU EXPO returns to North America to celebrate its 10th anniversary!)XYX"sv, std::nullopt, 6516, picture_release_event_6516, R"XYX(Miku Expo 2024 Vancouver )XYX"sv, names_release_event_6516, 82, 2024, std::nullopt, 16544, R"(Miku Expo 2024 North America)", "Draft"sv, R"XYX(miku-expo-2024-vancouver)XYX"sv, R"XYX(Thunderbird Arena)XYX"sv, web_links_release_event_6516 },
  {R"XYX(未来有你 2024 in Shanghai, HATSUNE MIKU WITH YOU 2024 in Shanghai)XYX"sv, "Unspecified"sv, 2024y/7/13, std::nullopt, 2024y/7/14, 7673, picture_release_event_7673, R"XYX(MIKU WITH YOU 2024 in Shanghai)XYX"sv, names_release_event_7673, 173, 2024, R"XYX(in Shanghai)XYX"sv, 17590, R"(MIKU WITH YOU 2024)", "Draft"sv, R"XYX(miku-with-you-2024-in-shanghai)XYX"sv, R"XYX(前滩31演艺中心·大剧场)XYX"sv, web_links_release_event_7673 },
  {R"XYX(初音ミク「マジカルミライ 2024」in FUKUOKA)XYX"sv, "Unspecified"sv, 2024y/8/17, R"XYX(Magical Mirai 2024’s theme is “FAN FUN TRIP”.

**Live Show**:
Fukuoka Sunpalace
August 17th(Sat.) - 18th(Sun.)

**Exhibition**:
FUKUOKA CONVENTION CENTER 2,4,5F
August 17th(Sat.) - 18th(Sun.)

Art by [たま](https://vocadb.net/Ar/1724))XYX"sv, 2024y/8/18, 7214, picture_release_event_7214, R"XYX(Hatsune Miku "Magical Mirai 2024" in FUKUOKA)XYX"sv, names_release_event_7214, 81, 2024, std::nullopt, 17933, R"(Hatsune Miku "Magical Mirai" 2024)", "Finished"sv, R"XYX(hatsune-miku-magical-mirai-202)XYX"sv, R"XYX(Fukuoka Sunpalace, FUKUOKA CONVENTION CENTER 2･4･5F)XYX"sv, web_links_release_event_7214 },
  {std::nullopt, "Unspecified"sv, 2024y/10/26, R"XYX(The HATSUNE MIKU EXPO 10th anniversary celebrations continue in Europe!)XYX"sv, std::nullopt, 7266, picture_release_event_7266, R"XYX(Miku Expo 2024 London)XYX"sv, names_release_event_7266, 82, 2024, std::nullopt, 18446, R"(Miku Expo 2024 Europe)", "Finished"sv, R"XYX(miku-expo-2024-london)XYX"sv, R"XYX(OVO Arena Wembley)XYX"sv, web_links_release_event_7266 },
  {std::nullopt, "Unspecified"sv, 2024y/11/15, std::nullopt, std::nullopt, 7765, picture_release_event_7765, R"XYX(Miku Expo 2024 Auckland)XYX"sv, names_release_event_7765, 82, 2024, R"XYX(Auckland)XYX"sv, 18583, R"(Miku Expo 2024 New Zealand & Australia)", "Draft"sv, R"XYX(miku-expo-2024-auckland)XYX"sv, R"XYX(Spark Arena)XYX"sv, web_links_release_event_7765 },
  {R"XYX(初音ミク JAPAN TOUR 2025 〜BLOOMING〜 大阪)XYX"sv, "Unspecified"sv, 2025y/4/19, std::nullopt, std::nullopt, 8380, picture_release_event_8380, R"XYX(HATSUNE MIKU JAPAN TOUR 2025 〜BLOOMING〜 OSAKA)XYX"sv, names_release_event_8380, 799, 1, std::nullopt, 19957, R"(初音ミク JAPAN TOUR 2025 〜BLOOMING〜)", "Finished"sv, R"XYX(hatsune-miku-japan-tour-2025-b)XYX"sv, std::nullopt, web_links_release_event_8380 },
  {R"XYX(初音ミク「マジカルミライ 2025」in SENDAI)XYX"sv, "Unspecified"sv, 2025y/8/1, R"XYX(Magical Mirai 2025’s theme is “Starry River in the Sky”.

**Live Show**:
Sendai Sunplaza
August 1st(Fri.) - 3rd(Sun.)

**Exhibition**:
Near Sendai Station
August 1st(Fri.) - 3rd(Sun.)

Art by [Tiv](https://vocadb.net/Ar/161497))XYX"sv, 2025y/8/3, 8768, picture_release_event_8768, R"XYX(Hatsune Miku "Magical Mirai 2025" in SENDAI)XYX"sv, names_release_event_8768, 81, 2025, std::nullopt, 20912, R"(Hatsune Miku "Magical Mirai" 2025)", "Finished"sv, R"XYX(hatsune-miku-magical-mirai-202)XYX"sv, std::nullopt, web_links_release_event_8768 },
  {std::nullopt, "Unspecified"sv, 2025y/11/5, std::nullopt, std::nullopt, 9341, picture_release_event_9341, R"XYX(Miku Expo 2025 Bangkok)XYX"sv, names_release_event_9341, 82, 2025, R"XYX(Bangkok)XYX"sv, 22929, R"(Miku Expo 2025 Asia)", "Finished"sv, R"XYX(miku-expo-2025-bangkok)XYX"sv, R"XYX(UOB LIVE)XYX"sv, web_links_release_event_9341 },
  {R"XYX(未来有你 2025 in Shanghai, HATSUNE MIKU WITH YOU 2025 in Shanghai)XYX"sv, "Unspecified"sv, 2025y/12/20, std::nullopt, 2025y/12/21, 9644, picture_release_event_9644, R"XYX(MIKU WITH YOU 2025 in Shanghai)XYX"sv, names_release_event_9644, 173, 2025, R"XYX(in Shanghai)XYX"sv, 23552, R"(MIKU WITH YOU 2025)", "Draft"sv, R"XYX(miku-with-you-2025-in-shanghai)XYX"sv, R"XYX(Jing'an Sports Center)XYX"sv, web_links_release_event_9644 },
  {R"XYX(初音ミク LAWSON 50th Anniversary Special LIVE)XYX"sv, "Concert"sv, 2026y/1/17, std::nullopt, 2026y/1/19, 9642, picture_release_event_9642, R"XYX(Hatsune Miku LAWSON 50th Anniversary Special LIVE)XYX"sv, names_release_event_9642, std::nullopt, 0, std::nullopt, 23957, R"(初音ミク LAWSON 50th Anniversary Special LIVE)", "Finished"sv, R"XYX(hatsune-miku-lawson-50th-anniv)XYX"sv, std::nullopt, web_links_release_event_9642 },
  {R"XYX(デコミク LIVE starring 初音ミク 『Hello』Produced by DECO*27 / OTOIRO, DECOMiku LIVE starring Hatsune Miku 『Hello』Produced by DECO*27 / OTOIRO)XYX"sv, "Concert"sv, 2026y/2/14, std::nullopt, std::nullopt, 9401, picture_release_event_9401, R"XYX(Hello)XYX"sv, names_release_event_9401, std::nullopt, 0, std::nullopt, std::nullopt, std::nullopt, "Draft"sv, R"XYX(hello)XYX"sv, R"XYX(国立代々木競技場第一体育館)XYX"sv, web_links_release_event_9401 },
}};


} // namespace vocadb
