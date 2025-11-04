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

#include "vocadb-api.hpp"

export module vocadb.events;

import std;

namespace vocadb {

using namespace std::literals;


/* Miku FES'09 (Summer) */
constexpr std::array<additional_name, 3> names_2522 {{
  {"Romaji"sv, R"XYX(Miku FES'09 (Natsu))XYX"sv},
  {"English"sv, R"XYX(Miku FES'09 (Summer))XYX"sv},
  {"Japanese"sv, R"XYX(ミクFES'09（夏）)XYX"sv},
}};

/* Miku FES'09 (Summer) */
constexpr std::array<web_link, 9> web_links_2522 {{
  {"Reference"sv, "NicoNicoPedia"sv, "https://dic.nicovideo.jp/a/%E3%83%9F%E3%82%AFfes%2709%28%E5%A4%8F%29"sv, 949 },
  {"Other"sv, "HATSUNE MIKU OFFICIAL BLOG"sv, "https://blog.piapro.net/2009/09/fes09.html"sv, 950 },
  {"Other"sv, "Hatsune Miku LIVE Wiki"sv, "https://www46.atwiki.jp/mikulive/pages/24.html"sv, 951 },
  {"Reference"sv, "Vocaloid Wiki"sv, "https://vocaloid.fandom.com/wiki/Miku_FES%2709_(Natsu)"sv, 952 },
  {"Other"sv, "ASCII.jp"sv, "https://ascii.jp/elem/000/000/456/456009/"sv, 6547 },
  {"Other"sv, "Website"sv, "http://mikufes.jp/"sv, 6548 },
  {"Other"sv, "NicoNicoLive"sv, "http://www.nicovideo.jp/static/weblive/mikufes09/"sv, 6549 },
  {"Other"sv, "Streaming+"sv, "http://eplus.jp/miku-web"sv, 6550 },
  {"Other"sv, "BARKS"sv, "https://www.barks.jp/news/?id=1000051890"sv, 6551 },
}};

/* Miku FES'09 (Summer) */

#if __has_embed("event_pic_orig_2522.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_orig_2522 = std::to_array<std::uint8_t>({
    #embed "event_pic_orig_2522.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_orig_2522;
#endif


#if __has_embed("event_pic_small_thumb_2522.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_small_thumb_2522 = std::to_array<std::uint8_t>({
    #embed "event_pic_small_thumb_2522.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_small_thumb_2522;
#endif


#if __has_embed("event_pic_thumb_2522.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_thumb_2522 = std::to_array<std::uint8_t>({
    #embed "event_pic_thumb_2522.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_thumb_2522;
#endif


#if __has_embed("event_pic_tiny_thumb_2522.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_tiny_thumb_2522 = std::to_array<std::uint8_t>({
    #embed "event_pic_tiny_thumb_2522.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_tiny_thumb_2522;
#endif

constexpr release_event_picture event_picture_2522 = { "image/jpeg", std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/2522.jpg?v=8)XYX"sv, event_pic_orig_2522, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/2522.jpg?v=8)XYX"sv, event_pic_small_thumb_2522, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/2522.jpg?v=8)XYX"sv, event_pic_thumb_2522, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/2522.jpg?v=8)XYX"sv, event_pic_tiny_thumb_2522  };

/* Miku no Hi Kanshasai 39's Giving Day */
constexpr std::array<additional_name, 2> names_2520 {{
  {"Romaji"sv, R"XYX(Miku no Hi Kanshasai 39's Giving Day)XYX"sv},
  {"Japanese"sv, R"XYX(ミクの日感謝祭39's Giving Day)XYX"sv},
}};

/* Miku no Hi Kanshasai 39's Giving Day */
constexpr std::array<web_link, 3> web_links_2520 {{
  {"Other"sv, "Official website"sv, "http://miku.sega.jp/39/mikufes.html"sv, 948 },
  {"Reference"sv, "NicoNicoPedia"sv, "https://dic.nicovideo.jp/a/%E3%83%9F%E3%82%AF%E3%81%AE%E6%97%A5%E6%84%9F%E8%AC%9D%E7%A5%AD"sv, 1292 },
  {"Reference"sv, "Vocaloid Wiki"sv, "https://vocaloid.fandom.com/wiki/Miku_no_Hi_Kanshasai_39%27s_Giving_Day"sv, 1293 },
}};

/* Miku no Hi Kanshasai 39's Giving Day */

#if __has_embed("event_pic_orig_2520.gif") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_orig_2520 = std::to_array<std::uint8_t>({
    #embed "event_pic_orig_2520.gif"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_orig_2520;
#endif


#if __has_embed("event_pic_small_thumb_2520.gif") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_small_thumb_2520 = std::to_array<std::uint8_t>({
    #embed "event_pic_small_thumb_2520.gif"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_small_thumb_2520;
#endif


#if __has_embed("event_pic_thumb_2520.gif") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_thumb_2520 = std::to_array<std::uint8_t>({
    #embed "event_pic_thumb_2520.gif"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_thumb_2520;
#endif


#if __has_embed("event_pic_tiny_thumb_2520.gif") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_tiny_thumb_2520 = std::to_array<std::uint8_t>({
    #embed "event_pic_tiny_thumb_2520.gif"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_tiny_thumb_2520;
#endif

constexpr release_event_picture event_picture_2520 = { "image/gif", std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/2520.gif?v=8)XYX"sv, event_pic_orig_2520, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/2520.gif?v=8)XYX"sv, event_pic_small_thumb_2520, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/2520.gif?v=8)XYX"sv, event_pic_thumb_2520, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/2520.gif?v=8)XYX"sv, event_pic_tiny_thumb_2520  };

/* Hatsune Miku Live Party 2011 Tokyo */
constexpr std::array<additional_name, 4> names_2523 {{
  {"English"sv, R"XYX(Hatsune Miku Live Party 2011 Tokyo)XYX"sv},
  {"Unspecified"sv, R"XYX(ミクパ 2011 Tokyo)XYX"sv},
  {"Japanese"sv, R"XYX(初音ミクライブパーティー 2011 Tokyo)XYX"sv},
  {"Unspecified"sv, R"XYX(MikuPa 2011 Tokyo)XYX"sv},
}};

/* Hatsune Miku Live Party 2011 Tokyo */
constexpr std::array<web_link, 4> web_links_2523 {{
  {"Reference"sv, "Vocaloid Wiki (Mikupa 2011 Sapporo)"sv, "https://vocaloid.fandom.com/wiki/Hatsune_Miku_Live_Party_2011_(Mikupa)/Sapporo"sv, 2527 },
  {"Reference"sv, "Vocaloid Wiki (Mikupa 2011 Singapore)"sv, "https://vocaloid.fandom.com/wiki/Hatsune_Miku_Live_Party_2011_(Mikupa)/Singapore"sv, 2528 },
  {"Reference"sv, "Vocaloid Wiki (Mikupa 2011 Tokyo)"sv, "https://vocaloid.fandom.com/wiki/Hatsune_Miku_Live_Party_2011_(Mikupa)/Tokyo"sv, 2529 },
  {"Other"sv, "Website"sv, "http://5pb.jp/mikupa/index_tokyo.html"sv, 2530 },
}};

/* Hatsune Miku Live Party 2011 Tokyo */

#if __has_embed("event_pic_orig_2523.png") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_orig_2523 = std::to_array<std::uint8_t>({
    #embed "event_pic_orig_2523.png"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_orig_2523;
#endif


#if __has_embed("event_pic_small_thumb_2523.png") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_small_thumb_2523 = std::to_array<std::uint8_t>({
    #embed "event_pic_small_thumb_2523.png"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_small_thumb_2523;
#endif


#if __has_embed("event_pic_thumb_2523.png") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_thumb_2523 = std::to_array<std::uint8_t>({
    #embed "event_pic_thumb_2523.png"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_thumb_2523;
#endif


#if __has_embed("event_pic_tiny_thumb_2523.png") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_tiny_thumb_2523 = std::to_array<std::uint8_t>({
    #embed "event_pic_tiny_thumb_2523.png"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_tiny_thumb_2523;
#endif

constexpr release_event_picture event_picture_2523 = { "image/png", std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/2523.png?v=12)XYX"sv, event_pic_orig_2523, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/2523.png?v=12)XYX"sv, event_pic_small_thumb_2523, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/2523.png?v=12)XYX"sv, event_pic_thumb_2523, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/2523.png?v=12)XYX"sv, event_pic_tiny_thumb_2523  };

/* MIKUNOPOLIS in LOS ANGELES “Happy to meet you, I'm HATSUNE MIKU” */
constexpr std::array<additional_name, 4> names_2521 {{
  {"Japanese"sv, R"XYX(MIKUNOPOLIS in LOS ANGELES “はじめまして、初音ミクです”)XYX"sv},
  {"English"sv, R"XYX(MIKUNOPOLIS in LOS ANGELES “Happy to meet you, I'm HATSUNE MIKU”)XYX"sv},
  {"Romaji"sv, R"XYX(MIKUNOPOLIS in LOS ANGELES "Hajimemashite, Hatsune Miku Desu")XYX"sv},
  {"Unspecified"sv, R"XYX(MIKUNOPOLIS in LOS ANGELES “Happy to meet you! I'm HATSUNE MIKU”)XYX"sv},
}};

/* MIKUNOPOLIS in LOS ANGELES “Happy to meet you, I'm HATSUNE MIKU” */
constexpr std::array<web_link, 2> web_links_2521 {{
  {"Other"sv, "Official website"sv, "http://miku.sega.jp/39/mikula.html"sv, 947 },
  {"Reference"sv, "Official Album"sv, "https://vocadb.net/Al/5061"sv, 7512 },
}};

/* MIKUNOPOLIS in LOS ANGELES “Happy to meet you, I'm HATSUNE MIKU” */

#if __has_embed("event_pic_orig_2521.png") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_orig_2521 = std::to_array<std::uint8_t>({
    #embed "event_pic_orig_2521.png"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_orig_2521;
#endif


#if __has_embed("event_pic_small_thumb_2521.png") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_small_thumb_2521 = std::to_array<std::uint8_t>({
    #embed "event_pic_small_thumb_2521.png"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_small_thumb_2521;
#endif


#if __has_embed("event_pic_thumb_2521.png") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_thumb_2521 = std::to_array<std::uint8_t>({
    #embed "event_pic_thumb_2521.png"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_thumb_2521;
#endif


#if __has_embed("event_pic_tiny_thumb_2521.png") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_tiny_thumb_2521 = std::to_array<std::uint8_t>({
    #embed "event_pic_tiny_thumb_2521.png"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_tiny_thumb_2521;
#endif

constexpr release_event_picture event_picture_2521 = { "image/png", std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/2521.png?v=6)XYX"sv, event_pic_orig_2521, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/2521.png?v=6)XYX"sv, event_pic_small_thumb_2521, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/2521.png?v=6)XYX"sv, event_pic_thumb_2521, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/2521.png?v=6)XYX"sv, event_pic_tiny_thumb_2521  };

/* Hatsune Miku Live Party 2011 Sapporo */
constexpr std::array<additional_name, 4> names_2526 {{
  {"English"sv, R"XYX(Hatsune Miku Live Party 2011 Sapporo)XYX"sv},
  {"Unspecified"sv, R"XYX(ミクパ 2011 Sapporo)XYX"sv},
  {"Japanese"sv, R"XYX(初音ミクライブパーティー 2011 Sapporo)XYX"sv},
  {"Unspecified"sv, R"XYX(MikuPa 2011 Sapporo)XYX"sv},
}};

/* Hatsune Miku Live Party 2011 Sapporo */
constexpr std::array<web_link, 4> web_links_2526 {{
  {"Other"sv, "Website"sv, "http://5pb.jp/mikupa/index_sapporo.html"sv, 964 },
  {"Reference"sv, "Vocaloid Wiki (Mikupa 2011 Sapporo)"sv, "https://vocaloid.fandom.com/wiki/Hatsune_Miku_Live_Party_2011_(Mikupa)/Sapporo"sv, 2531 },
  {"Reference"sv, "Vocaloid Wiki (Mikupa 2011 Singapore)"sv, "https://vocaloid.fandom.com/wiki/Hatsune_Miku_Live_Party_2011_(Mikupa)/Singapore"sv, 2532 },
  {"Reference"sv, "Vocaloid Wiki (Mikupa 2011 Tokyo)"sv, "https://vocaloid.fandom.com/wiki/Hatsune_Miku_Live_Party_2011_(Mikupa)/Tokyo"sv, 2533 },
}};

/* Hatsune Miku Live Party 2011 Sapporo */

#if __has_embed("event_pic_orig_2526.png") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_orig_2526 = std::to_array<std::uint8_t>({
    #embed "event_pic_orig_2526.png"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_orig_2526;
#endif


#if __has_embed("event_pic_small_thumb_2526.png") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_small_thumb_2526 = std::to_array<std::uint8_t>({
    #embed "event_pic_small_thumb_2526.png"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_small_thumb_2526;
#endif


#if __has_embed("event_pic_thumb_2526.png") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_thumb_2526 = std::to_array<std::uint8_t>({
    #embed "event_pic_thumb_2526.png"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_thumb_2526;
#endif


#if __has_embed("event_pic_tiny_thumb_2526.png") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_tiny_thumb_2526 = std::to_array<std::uint8_t>({
    #embed "event_pic_tiny_thumb_2526.png"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_tiny_thumb_2526;
#endif

constexpr release_event_picture event_picture_2526 = { "image/png", std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/2526.png?v=8)XYX"sv, event_pic_orig_2526, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/2526.png?v=8)XYX"sv, event_pic_small_thumb_2526, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/2526.png?v=8)XYX"sv, event_pic_thumb_2526, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/2526.png?v=8)XYX"sv, event_pic_tiny_thumb_2526  };

/* Hatsune Miku Live Party 2011 Singapore */
constexpr std::array<additional_name, 4> names_2527 {{
  {"English"sv, R"XYX(Hatsune Miku Live Party 2011 Singapore)XYX"sv},
  {"Unspecified"sv, R"XYX(ミクパ 2011 Singapore)XYX"sv},
  {"Japanese"sv, R"XYX(初音ミクライブパーティー 2011 Singapore)XYX"sv},
  {"Unspecified"sv, R"XYX(MikuPa 2011 Singapore)XYX"sv},
}};

/* Hatsune Miku Live Party 2011 Singapore */
constexpr std::array<web_link, 4> web_links_2527 {{
  {"Other"sv, "Website"sv, "http://5pb.jp/mikupa/index_singapore.html"sv, 965 },
  {"Reference"sv, "Vocaloid Wiki (Mikupa 2011 Sapporo)"sv, "https://vocaloid.fandom.com/wiki/Hatsune_Miku_Live_Party_2011_(Mikupa)/Sapporo"sv, 2534 },
  {"Reference"sv, "Vocaloid Wiki (Mikupa 2011 Singapore)"sv, "https://vocaloid.fandom.com/wiki/Hatsune_Miku_Live_Party_2011_(Mikupa)/Singapore"sv, 2535 },
  {"Reference"sv, "Vocaloid Wiki (Mikupa 2011 Tokyo)"sv, "https://vocaloid.fandom.com/wiki/Hatsune_Miku_Live_Party_2011_(Mikupa)/Tokyo"sv, 2536 },
}};

/* Hatsune Miku Live Party 2011 Singapore */

#if __has_embed("event_pic_orig_2527.png") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_orig_2527 = std::to_array<std::uint8_t>({
    #embed "event_pic_orig_2527.png"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_orig_2527;
#endif


#if __has_embed("event_pic_small_thumb_2527.png") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_small_thumb_2527 = std::to_array<std::uint8_t>({
    #embed "event_pic_small_thumb_2527.png"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_small_thumb_2527;
#endif


#if __has_embed("event_pic_thumb_2527.png") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_thumb_2527 = std::to_array<std::uint8_t>({
    #embed "event_pic_thumb_2527.png"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_thumb_2527;
#endif


#if __has_embed("event_pic_tiny_thumb_2527.png") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_tiny_thumb_2527 = std::to_array<std::uint8_t>({
    #embed "event_pic_tiny_thumb_2527.png"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_tiny_thumb_2527;
#endif

constexpr release_event_picture event_picture_2527 = { "image/png", std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/2527.png?v=5)XYX"sv, event_pic_orig_2527, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/2527.png?v=5)XYX"sv, event_pic_small_thumb_2527, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/2527.png?v=5)XYX"sv, event_pic_thumb_2527, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/2527.png?v=5)XYX"sv, event_pic_tiny_thumb_2527  };

/* Hatsune Miku Live Party 2012 Tokyo */
constexpr std::array<additional_name, 4> names_4056 {{
  {"English"sv, R"XYX(Hatsune Miku Live Party 2012 Tokyo)XYX"sv},
  {"Unspecified"sv, R"XYX(ミクパ 2012 Tokyo)XYX"sv},
  {"Japanese"sv, R"XYX(初音ミクライブパーティー 2012 Tokyo)XYX"sv},
  {"Unspecified"sv, R"XYX(MikuPa 2012 Tokyo)XYX"sv},
}};

/* Hatsune Miku Live Party 2012 Tokyo */
constexpr std::array<web_link, 5> web_links_4056 {{
  {"Reference"sv, "Vocaloid Wiki (Mikupa 2012 Tokyo)"sv, "https://vocaloid.fandom.com/wiki/Hatsune_Miku_Live_Party_2012_(Mikupa)/Tokyo"sv, 2537 },
  {"Reference"sv, "Vocaloid Wiki (Mikupa 2012 Hong Kong)"sv, "https://vocaloid.fandom.com/wiki/Hatsune_Miku_Live_Party_2012_(Mikupa)/Hong_Kong_and_Taiwan"sv, 2538 },
  {"Reference"sv, "Vocaloid Wiki (Mikupa 2012 Taiwan)"sv, "https://vocaloid.fandom.com/wiki/Hatsune_Miku_Live_Party_2012_(Mikupa)/Hong_Kong_and_Taiwan"sv, 2539 },
  {"Reference"sv, "Vocaloid Wiki (Miku no Hi Dai Kanshasai 39's Giving Day)"sv, "https://vocaloid.fandom.com/wiki/Miku_no_Hi_Dai_Kanshasai_39%27s_Giving_Day"sv, 2541 },
  {"Reference"sv, "VocaDB / Miku's Big Thanksgiving Day"sv, "https://vocadb.net/E/1413/39s-giving-day-2012"sv, 2542 },
}};

/* Hatsune Miku Live Party 2012 Tokyo */

#if __has_embed("event_pic_orig_4056.png") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_orig_4056 = std::to_array<std::uint8_t>({
    #embed "event_pic_orig_4056.png"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_orig_4056;
#endif


#if __has_embed("event_pic_small_thumb_4056.png") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_small_thumb_4056 = std::to_array<std::uint8_t>({
    #embed "event_pic_small_thumb_4056.png"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_small_thumb_4056;
#endif


#if __has_embed("event_pic_thumb_4056.png") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_thumb_4056 = std::to_array<std::uint8_t>({
    #embed "event_pic_thumb_4056.png"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_thumb_4056;
#endif


#if __has_embed("event_pic_tiny_thumb_4056.png") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_tiny_thumb_4056 = std::to_array<std::uint8_t>({
    #embed "event_pic_tiny_thumb_4056.png"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_tiny_thumb_4056;
#endif

constexpr release_event_picture event_picture_4056 = { "image/png", std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/4056.png?v=10)XYX"sv, event_pic_orig_4056, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/4056.png?v=10)XYX"sv, event_pic_small_thumb_4056, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/4056.png?v=10)XYX"sv, event_pic_thumb_4056, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/4056.png?v=10)XYX"sv, event_pic_tiny_thumb_4056  };

/* Miku's Big Thanksgiving Day - Special 39's Production 2012 */
constexpr std::array<additional_name, 3> names_1413 {{
  {"English"sv, R"XYX(Miku's Big Thanksgiving Day - Special 39's Production 2012)XYX"sv},
  {"Japanese"sv, R"XYX(ミクの日大感謝祭特番 - 制作日誌39 2012)XYX"sv},
  {"Romaji"sv, R"XYX(Miku No Hi Daikanshasai Tokuban - Seisaku Nisshi 39 2012)XYX"sv},
}};

/* Miku's Big Thanksgiving Day - Special 39's Production 2012 */
constexpr std::array<web_link, 4> web_links_1413 {{
  {"Reference"sv, "Vocaloid Wiki (Miku no Hi Dai Kanshasai 39's Giving Day)"sv, "https://vocaloid.fandom.com/wiki/Miku_no_Hi_Dai_Kanshasai_39%27s_Giving_Day"sv, 2543 },
  {"Other"sv, "Website"sv, "http://miku.sega.jp/39/"sv, 2544 },
  {"Reference"sv, "Vocaloid Wiki (Mikupa 2012 Tokyo)"sv, "https://vocaloid.fandom.com/wiki/Hatsune_Miku_Live_Party_2012_(Mikupa)/Tokyo"sv, 2545 },
  {"Reference"sv, "VocaDB / Hatsune Miku Live Party 2012 Tokyo"sv, "https://vocadb.net/E/4056/hatsune-miku-live-party-2012-t"sv, 2546 },
}};

/* Miku's Big Thanksgiving Day - Special 39's Production 2012 */

#if __has_embed("event_pic_orig_1413.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_orig_1413 = std::to_array<std::uint8_t>({
    #embed "event_pic_orig_1413.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_orig_1413;
#endif


#if __has_embed("event_pic_small_thumb_1413.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_small_thumb_1413 = std::to_array<std::uint8_t>({
    #embed "event_pic_small_thumb_1413.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_small_thumb_1413;
#endif


#if __has_embed("event_pic_thumb_1413.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_thumb_1413 = std::to_array<std::uint8_t>({
    #embed "event_pic_thumb_1413.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_thumb_1413;
#endif


#if __has_embed("event_pic_tiny_thumb_1413.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_tiny_thumb_1413 = std::to_array<std::uint8_t>({
    #embed "event_pic_tiny_thumb_1413.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_tiny_thumb_1413;
#endif

constexpr release_event_picture event_picture_1413 = { "image/jpeg", std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/1413.jpg?v=12)XYX"sv, event_pic_orig_1413, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/1413.jpg?v=12)XYX"sv, event_pic_small_thumb_1413, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/1413.jpg?v=12)XYX"sv, event_pic_thumb_1413, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/1413.jpg?v=12)XYX"sv, event_pic_tiny_thumb_1413  };

/* Hatsune Miku Live Party 2012 Hong Kong */
constexpr std::array<additional_name, 4> names_2524 {{
  {"English"sv, R"XYX(Hatsune Miku Live Party 2012 Hong Kong)XYX"sv},
  {"Unspecified"sv, R"XYX(ミクパ 2012 Hong Kong)XYX"sv},
  {"Japanese"sv, R"XYX(初音ミクライブパーティー 2012 Hong Kong)XYX"sv},
  {"Unspecified"sv, R"XYX(MikuPa 2012 Hong Kong)XYX"sv},
}};

/* Hatsune Miku Live Party 2012 Hong Kong */
constexpr std::array<web_link, 4> web_links_2524 {{
  {"Other"sv, "Website"sv, "http://5pb.jp/mikupa/index_hktw.html"sv, 957 },
  {"Reference"sv, "Vocaloid Wiki (Mikupa 2012 Hong Kong)"sv, "https://vocaloid.fandom.com/wiki/Hatsune_Miku_Live_Party_2012_(Mikupa)/Hong_Kong_and_Taiwan"sv, 2547 },
  {"Reference"sv, "Vocaloid Wiki (Mikupa 2012 Taiwan)"sv, "https://vocaloid.fandom.com/wiki/Hatsune_Miku_Live_Party_2012_(Mikupa)/Hong_Kong_and_Taiwan"sv, 2548 },
  {"Reference"sv, "Vocaloid Wiki (Mikupa 2012 Tokyo)"sv, "https://vocaloid.fandom.com/wiki/Hatsune_Miku_Live_Party_2012_(Mikupa)/Tokyo"sv, 2549 },
}};

/* Hatsune Miku Live Party 2012 Hong Kong */

#if __has_embed("event_pic_orig_2524.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_orig_2524 = std::to_array<std::uint8_t>({
    #embed "event_pic_orig_2524.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_orig_2524;
#endif


#if __has_embed("event_pic_small_thumb_2524.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_small_thumb_2524 = std::to_array<std::uint8_t>({
    #embed "event_pic_small_thumb_2524.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_small_thumb_2524;
#endif


#if __has_embed("event_pic_thumb_2524.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_thumb_2524 = std::to_array<std::uint8_t>({
    #embed "event_pic_thumb_2524.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_thumb_2524;
#endif


#if __has_embed("event_pic_tiny_thumb_2524.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_tiny_thumb_2524 = std::to_array<std::uint8_t>({
    #embed "event_pic_tiny_thumb_2524.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_tiny_thumb_2524;
#endif

constexpr release_event_picture event_picture_2524 = { "image/jpeg", std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/2524.jpg?v=6)XYX"sv, event_pic_orig_2524, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/2524.jpg?v=6)XYX"sv, event_pic_small_thumb_2524, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/2524.jpg?v=6)XYX"sv, event_pic_thumb_2524, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/2524.jpg?v=6)XYX"sv, event_pic_tiny_thumb_2524  };

/* Hatsune Miku Live Party 2013 Sapporo */
constexpr std::array<additional_name, 4> names_2510 {{
  {"English"sv, R"XYX(Hatsune Miku Live Party 2013 Sapporo)XYX"sv},
  {"Unspecified"sv, R"XYX(ミクパ 2013 Sapporo)XYX"sv},
  {"Japanese"sv, R"XYX(初音ミクライブパーティー 2013 Sapporo)XYX"sv},
  {"Unspecified"sv, R"XYX(MikuPa 2013 Sapporo)XYX"sv},
}};

/* Hatsune Miku Live Party 2013 Sapporo */
constexpr std::array<web_link, 4> web_links_2510 {{
  {"Other"sv, "Website"sv, "http://5pb.jp/mikupa/index_sapporo2013.html"sv, 938 },
  {"Other"sv, "Piapro 's blog"sv, "https://blog.piapro.net/2012/12/2910.html"sv, 939 },
  {"Reference"sv, "Vocaloid Wiki (Mikupa 2013 Kansai)"sv, "https://vocaloid.fandom.com/wiki/Hatsune_Miku_Live_Party_2013_(MikuPa)/Kansai"sv, 2553 },
  {"Reference"sv, "Vocaloid Wiki (Mikupa 2013 Sapporo)"sv, "https://vocaloid.fandom.com/wiki/Hatsune_Miku_Live_Party_2013_(MikuPa)/Sapporo"sv, 2554 },
}};

/* Hatsune Miku Live Party 2013 Sapporo */

#if __has_embed("event_pic_orig_2510.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_orig_2510 = std::to_array<std::uint8_t>({
    #embed "event_pic_orig_2510.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_orig_2510;
#endif


#if __has_embed("event_pic_small_thumb_2510.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_small_thumb_2510 = std::to_array<std::uint8_t>({
    #embed "event_pic_small_thumb_2510.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_small_thumb_2510;
#endif


#if __has_embed("event_pic_thumb_2510.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_thumb_2510 = std::to_array<std::uint8_t>({
    #embed "event_pic_thumb_2510.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_thumb_2510;
#endif


#if __has_embed("event_pic_tiny_thumb_2510.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_tiny_thumb_2510 = std::to_array<std::uint8_t>({
    #embed "event_pic_tiny_thumb_2510.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_tiny_thumb_2510;
#endif

constexpr release_event_picture event_picture_2510 = { "image/jpeg", std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/2510.jpg?v=9)XYX"sv, event_pic_orig_2510, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/2510.jpg?v=9)XYX"sv, event_pic_small_thumb_2510, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/2510.jpg?v=9)XYX"sv, event_pic_thumb_2510, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/2510.jpg?v=9)XYX"sv, event_pic_tiny_thumb_2510  };

/* Hatsune Miku Live Party 2013 Kansai */
constexpr std::array<additional_name, 4> names_2511 {{
  {"English"sv, R"XYX(Hatsune Miku Live Party 2013 Kansai)XYX"sv},
  {"Unspecified"sv, R"XYX(ミクパ 2013 Kansai)XYX"sv},
  {"Japanese"sv, R"XYX(初音ミクライブパーティー 2013 Kansai)XYX"sv},
  {"Unspecified"sv, R"XYX(MikuPa 2013 Kansai)XYX"sv},
}};

/* Hatsune Miku Live Party 2013 Kansai */
constexpr std::array<web_link, 3> web_links_2511 {{
  {"Other"sv, "Website"sv, "http://5pb.jp/mikupa/index_kansai.html"sv, 940 },
  {"Other"sv, "Vocaloid Wiki (Mikupa 2013 Kansai)"sv, "https://vocaloid.fandom.com/wiki/Hatsune_Miku_Live_Party_2013_(MikuPa)/Kansai"sv, 2555 },
  {"Other"sv, "Vocaloid Wiki (Mikupa 2013 Sapporo)"sv, "https://vocaloid.fandom.com/wiki/Hatsune_Miku_Live_Party_2013_(MikuPa)/Sapporo"sv, 2556 },
}};

/* Hatsune Miku Live Party 2013 Kansai */

#if __has_embed("event_pic_orig_2511.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_orig_2511 = std::to_array<std::uint8_t>({
    #embed "event_pic_orig_2511.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_orig_2511;
#endif


#if __has_embed("event_pic_small_thumb_2511.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_small_thumb_2511 = std::to_array<std::uint8_t>({
    #embed "event_pic_small_thumb_2511.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_small_thumb_2511;
#endif


#if __has_embed("event_pic_thumb_2511.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_thumb_2511 = std::to_array<std::uint8_t>({
    #embed "event_pic_thumb_2511.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_thumb_2511;
#endif


#if __has_embed("event_pic_tiny_thumb_2511.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_tiny_thumb_2511 = std::to_array<std::uint8_t>({
    #embed "event_pic_tiny_thumb_2511.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_tiny_thumb_2511;
#endif

constexpr release_event_picture event_picture_2511 = { "image/jpeg", std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/2511.jpg?v=10)XYX"sv, event_pic_orig_2511, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/2511.jpg?v=10)XYX"sv, event_pic_small_thumb_2511, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/2511.jpg?v=10)XYX"sv, event_pic_thumb_2511, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/2511.jpg?v=10)XYX"sv, event_pic_tiny_thumb_2511  };

/* Hatsune Miku Magical Mirai 2013 */
constexpr std::array<additional_name, 4> names_2519 {{
  {"Japanese"sv, R"XYX(初音ミク「マジカルミライ 2013」)XYX"sv},
  {"English"sv, R"XYX(Hatsune Miku Magical Mirai 2013)XYX"sv},
  {"Unspecified"sv, R"XYX(マジカルミライ 2013)XYX"sv},
  {"Unspecified"sv, R"XYX(Magical Mirai 2013)XYX"sv},
}};

/* Hatsune Miku Magical Mirai 2013 */
constexpr std::array<web_link, 1> web_links_2519 {{
  {"Other"sv, "Website"sv, "https://magicalmirai.com/2013/"sv, 946 },
}};

/* Hatsune Miku Magical Mirai 2013 */

#if __has_embed("event_pic_orig_2519.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_orig_2519 = std::to_array<std::uint8_t>({
    #embed "event_pic_orig_2519.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_orig_2519;
#endif


#if __has_embed("event_pic_small_thumb_2519.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_small_thumb_2519 = std::to_array<std::uint8_t>({
    #embed "event_pic_small_thumb_2519.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_small_thumb_2519;
#endif


#if __has_embed("event_pic_thumb_2519.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_thumb_2519 = std::to_array<std::uint8_t>({
    #embed "event_pic_thumb_2519.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_thumb_2519;
#endif


#if __has_embed("event_pic_tiny_thumb_2519.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_tiny_thumb_2519 = std::to_array<std::uint8_t>({
    #embed "event_pic_tiny_thumb_2519.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_tiny_thumb_2519;
#endif

constexpr release_event_picture event_picture_2519 = { "image/jpeg", std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/2519.jpg?v=4)XYX"sv, event_pic_orig_2519, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/2519.jpg?v=4)XYX"sv, event_pic_small_thumb_2519, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/2519.jpg?v=4)XYX"sv, event_pic_thumb_2519, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/2519.jpg?v=4)XYX"sv, event_pic_tiny_thumb_2519  };

/* Miku Expo 2014 Jakarta */
constexpr std::array<additional_name, 2> names_1939 {{
  {"English"sv, R"XYX(Miku Expo 2014 Jakarta)XYX"sv},
  {"Unspecified"sv, R"XYX(HATSUNE MIKU EXPO 2014 IN INDONESIA)XYX"sv},
}};

/* Miku Expo 2014 Jakarta */
constexpr std::array<web_link, 6> web_links_1939 {{
  {"Reference"sv, "Vocaloid Wiki"sv, "https://vocaloid.fandom.com/wiki/HATSUNE_MIKU_EXPO_2014_in_INDONESIA"sv, 960 },
  {"Other"sv, "mohax (VOCALO.ID) special interview"sv, "https://mikuexpo.com/indonesia_karent#creator"sv, 1798 },
  {"Reference"sv, "special Album"sv, "https://vocadb.net/Al/9709"sv, 1799 },
  {"Other"sv, "YouTube (special video)"sv, "https://youtu.be/Bo2LO4kWsyY"sv, 1800 },
  {"Commercial"sv, "KarenT special"sv, "https://karent.jp/special/mikuexpo14"sv, 1796 },
  {"Other"sv, "MIKU EXPO in Indonesia Website"sv, "https://mikuexpo.com/indonesia_top"sv, 1797 },
}};

/* Miku Expo 2014 Jakarta */

#if __has_embed("event_pic_orig_1939.png") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_orig_1939 = std::to_array<std::uint8_t>({
    #embed "event_pic_orig_1939.png"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_orig_1939;
#endif


#if __has_embed("event_pic_small_thumb_1939.png") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_small_thumb_1939 = std::to_array<std::uint8_t>({
    #embed "event_pic_small_thumb_1939.png"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_small_thumb_1939;
#endif


#if __has_embed("event_pic_thumb_1939.png") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_thumb_1939 = std::to_array<std::uint8_t>({
    #embed "event_pic_thumb_1939.png"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_thumb_1939;
#endif


#if __has_embed("event_pic_tiny_thumb_1939.png") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_tiny_thumb_1939 = std::to_array<std::uint8_t>({
    #embed "event_pic_tiny_thumb_1939.png"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_tiny_thumb_1939;
#endif

constexpr release_event_picture event_picture_1939 = { "image/png", std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/1939.png?v=10)XYX"sv, event_pic_orig_1939, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/1939.png?v=10)XYX"sv, event_pic_small_thumb_1939, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/1939.png?v=10)XYX"sv, event_pic_thumb_1939, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/1939.png?v=10)XYX"sv, event_pic_tiny_thumb_1939  };

/* Hatsune Miku Magical Mirai 2014 in OSAKA */
constexpr std::array<additional_name, 4> names_2517 {{
  {"Japanese"sv, R"XYX(初音ミク「マジカルミライ 2014」in OSAKA)XYX"sv},
  {"English"sv, R"XYX(Hatsune Miku Magical Mirai 2014 in OSAKA)XYX"sv},
  {"Unspecified"sv, R"XYX(マジカルミライ 2014 Osaka)XYX"sv},
  {"Unspecified"sv, R"XYX(Magical Mirai 2014 Osaka)XYX"sv},
}};

/* Hatsune Miku Magical Mirai 2014 in OSAKA */
constexpr std::array<web_link, 4> web_links_2517 {{
  {"Other"sv, "Website - OSAKA (JP)"sv, "https://magicalmirai.com/2014/ticket_osaka.html"sv, 944 },
  {"Other"sv, "Website (JP)"sv, "https://magicalmirai.com/2014/"sv, 1897 },
  {"Other"sv, "Website (EN)"sv, "https://magicalmirai.com/2014/index_en.html"sv, 1899 },
  {"Other"sv, "Website - OSAKA (EN)"sv, "https://magicalmirai.com/2014/ticket_osaka_en.html"sv, 1900 },
}};

/* Hatsune Miku Magical Mirai 2014 in OSAKA */

#if __has_embed("event_pic_orig_2517.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_orig_2517 = std::to_array<std::uint8_t>({
    #embed "event_pic_orig_2517.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_orig_2517;
#endif


#if __has_embed("event_pic_small_thumb_2517.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_small_thumb_2517 = std::to_array<std::uint8_t>({
    #embed "event_pic_small_thumb_2517.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_small_thumb_2517;
#endif


#if __has_embed("event_pic_thumb_2517.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_thumb_2517 = std::to_array<std::uint8_t>({
    #embed "event_pic_thumb_2517.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_thumb_2517;
#endif


#if __has_embed("event_pic_tiny_thumb_2517.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_tiny_thumb_2517 = std::to_array<std::uint8_t>({
    #embed "event_pic_tiny_thumb_2517.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_tiny_thumb_2517;
#endif

constexpr release_event_picture event_picture_2517 = { "image/jpeg", std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/2517.jpg?v=6)XYX"sv, event_pic_orig_2517, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/2517.jpg?v=6)XYX"sv, event_pic_small_thumb_2517, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/2517.jpg?v=6)XYX"sv, event_pic_thumb_2517, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/2517.jpg?v=6)XYX"sv, event_pic_tiny_thumb_2517  };

/* Miku Expo 2014 Los Angeles */
constexpr std::array<additional_name, 1> names_1937 {{
  {"English"sv, R"XYX(Miku Expo 2014 Los Angeles)XYX"sv},
}};

/* Miku Expo 2014 Los Angeles */
constexpr std::array<web_link, 1> web_links_1937 {{
  {"Other"sv, "Official website"sv, "https://mikuexpo.com/la"sv, 961 },
}};

/* Miku Expo 2014 Los Angeles */

#if __has_embed("event_pic_orig_1937.png") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_orig_1937 = std::to_array<std::uint8_t>({
    #embed "event_pic_orig_1937.png"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_orig_1937;
#endif


#if __has_embed("event_pic_small_thumb_1937.png") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_small_thumb_1937 = std::to_array<std::uint8_t>({
    #embed "event_pic_small_thumb_1937.png"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_small_thumb_1937;
#endif


#if __has_embed("event_pic_thumb_1937.png") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_thumb_1937 = std::to_array<std::uint8_t>({
    #embed "event_pic_thumb_1937.png"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_thumb_1937;
#endif


#if __has_embed("event_pic_tiny_thumb_1937.png") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_tiny_thumb_1937 = std::to_array<std::uint8_t>({
    #embed "event_pic_tiny_thumb_1937.png"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_tiny_thumb_1937;
#endif

constexpr release_event_picture event_picture_1937 = { "image/png", std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/1937.png?v=4)XYX"sv, event_pic_orig_1937, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/1937.png?v=4)XYX"sv, event_pic_small_thumb_1937, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/1937.png?v=4)XYX"sv, event_pic_thumb_1937, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/1937.png?v=4)XYX"sv, event_pic_tiny_thumb_1937  };

/* SNOW MIKU LIVE! 2015 presents MIKU EXPO Live Set */
constexpr std::array<additional_name, 1> names_3792 {{
  {"English"sv, R"XYX(SNOW MIKU LIVE! 2015 presents MIKU EXPO Live Set)XYX"sv},
}};

/* SNOW MIKU LIVE! 2015 presents MIKU EXPO Live Set */
constexpr std::array<web_link, 2> web_links_3792 {{
  {"Other"sv, "Website"sv, "https://snowmiku.com/2015/live_ticket.html"sv, 1928 },
  {"Other"sv, "HATSUNE MIKU OFFICIAL BLOG"sv, "https://blog.piapro.net/2015/02/u1502101_1.html"sv, 1929 },
}};

/* SNOW MIKU LIVE! 2015 presents MIKU EXPO Live Set */

#if __has_embed("event_pic_orig_3792.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_orig_3792 = std::to_array<std::uint8_t>({
    #embed "event_pic_orig_3792.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_orig_3792;
#endif


#if __has_embed("event_pic_small_thumb_3792.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_small_thumb_3792 = std::to_array<std::uint8_t>({
    #embed "event_pic_small_thumb_3792.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_small_thumb_3792;
#endif


#if __has_embed("event_pic_thumb_3792.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_thumb_3792 = std::to_array<std::uint8_t>({
    #embed "event_pic_thumb_3792.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_thumb_3792;
#endif


#if __has_embed("event_pic_tiny_thumb_3792.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_tiny_thumb_3792 = std::to_array<std::uint8_t>({
    #embed "event_pic_tiny_thumb_3792.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_tiny_thumb_3792;
#endif

constexpr release_event_picture event_picture_3792 = { "image/jpeg", std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/3792.jpg?v=4)XYX"sv, event_pic_orig_3792, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/3792.jpg?v=4)XYX"sv, event_pic_small_thumb_3792, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/3792.jpg?v=4)XYX"sv, event_pic_thumb_3792, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/3792.jpg?v=4)XYX"sv, event_pic_tiny_thumb_3792  };

/* Miku Expo 2015 Shanghai */
constexpr std::array<additional_name, 1> names_1940 {{
  {"English"sv, R"XYX(Miku Expo 2015 Shanghai)XYX"sv},
}};

/* Miku Expo 2015 Shanghai */
constexpr std::array<web_link, 1> web_links_1940 {{
  {"Reference"sv, "Vocaloid Wiki"sv, "https://vocaloid.fandom.com/wiki/HATSUNE_MIKU_EXPO_2015_in_SHANGHAI"sv, 963 },
}};

/* Miku Expo 2015 Shanghai */

#if __has_embed("event_pic_orig_1940.png") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_orig_1940 = std::to_array<std::uint8_t>({
    #embed "event_pic_orig_1940.png"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_orig_1940;
#endif


#if __has_embed("event_pic_small_thumb_1940.png") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_small_thumb_1940 = std::to_array<std::uint8_t>({
    #embed "event_pic_small_thumb_1940.png"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_small_thumb_1940;
#endif


#if __has_embed("event_pic_thumb_1940.png") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_thumb_1940 = std::to_array<std::uint8_t>({
    #embed "event_pic_thumb_1940.png"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_thumb_1940;
#endif


#if __has_embed("event_pic_tiny_thumb_1940.png") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_tiny_thumb_1940 = std::to_array<std::uint8_t>({
    #embed "event_pic_tiny_thumb_1940.png"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_tiny_thumb_1940;
#endif

constexpr release_event_picture event_picture_1940 = { "image/png", std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/1940.png?v=3)XYX"sv, event_pic_orig_1940, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/1940.png?v=3)XYX"sv, event_pic_small_thumb_1940, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/1940.png?v=3)XYX"sv, event_pic_thumb_1940, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/1940.png?v=3)XYX"sv, event_pic_tiny_thumb_1940  };

/* Hatsune Miku Magical Mirai 2015 */
constexpr std::array<additional_name, 4> names_2514 {{
  {"Japanese"sv, R"XYX(初音ミク「マジカルミライ 2015」)XYX"sv},
  {"English"sv, R"XYX(Hatsune Miku Magical Mirai 2015)XYX"sv},
  {"Unspecified"sv, R"XYX(マジカルミライ 2015)XYX"sv},
  {"Unspecified"sv, R"XYX(Magical Mirai 2015)XYX"sv},
}};

/* Hatsune Miku Magical Mirai 2015 */
constexpr std::array<web_link, 2> web_links_2514 {{
  {"Other"sv, "Website (EN)"sv, "https://magicalmirai.com/2015/index_en.php"sv, 943 },
  {"Other"sv, "Website (JP)"sv, "https://magicalmirai.com/2015/"sv, 1896 },
}};

/* Hatsune Miku Magical Mirai 2015 */

#if __has_embed("event_pic_orig_2514.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_orig_2514 = std::to_array<std::uint8_t>({
    #embed "event_pic_orig_2514.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_orig_2514;
#endif


#if __has_embed("event_pic_small_thumb_2514.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_small_thumb_2514 = std::to_array<std::uint8_t>({
    #embed "event_pic_small_thumb_2514.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_small_thumb_2514;
#endif


#if __has_embed("event_pic_thumb_2514.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_thumb_2514 = std::to_array<std::uint8_t>({
    #embed "event_pic_thumb_2514.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_thumb_2514;
#endif


#if __has_embed("event_pic_tiny_thumb_2514.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_tiny_thumb_2514 = std::to_array<std::uint8_t>({
    #embed "event_pic_tiny_thumb_2514.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_tiny_thumb_2514;
#endif

constexpr release_event_picture event_picture_2514 = { "image/jpeg", std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/2514.jpg?v=4)XYX"sv, event_pic_orig_2514, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/2514.jpg?v=4)XYX"sv, event_pic_small_thumb_2514, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/2514.jpg?v=4)XYX"sv, event_pic_thumb_2514, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/2514.jpg?v=4)XYX"sv, event_pic_tiny_thumb_2514  };

/* Miku Expo 2016 Fukuoka */
constexpr std::array<additional_name, 1> names_1399 {{
  {"English"sv, R"XYX(Miku Expo 2016 Fukuoka)XYX"sv},
}};

/* Miku Expo 2016 Fukuoka */
constexpr std::array<web_link, 0> web_links_1399 {{
}};

/* Miku Expo 2016 Fukuoka */

#if __has_embed("event_pic_orig_1399.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_orig_1399 = std::to_array<std::uint8_t>({
    #embed "event_pic_orig_1399.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_orig_1399;
#endif


#if __has_embed("event_pic_small_thumb_1399.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_small_thumb_1399 = std::to_array<std::uint8_t>({
    #embed "event_pic_small_thumb_1399.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_small_thumb_1399;
#endif


#if __has_embed("event_pic_thumb_1399.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_thumb_1399 = std::to_array<std::uint8_t>({
    #embed "event_pic_thumb_1399.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_thumb_1399;
#endif


#if __has_embed("event_pic_tiny_thumb_1399.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_tiny_thumb_1399 = std::to_array<std::uint8_t>({
    #embed "event_pic_tiny_thumb_1399.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_tiny_thumb_1399;
#endif

constexpr release_event_picture event_picture_1399 = { "image/jpeg", std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/1399.jpg?v=8)XYX"sv, event_pic_orig_1399, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/1399.jpg?v=8)XYX"sv, event_pic_small_thumb_1399, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/1399.jpg?v=8)XYX"sv, event_pic_thumb_1399, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/1399.jpg?v=8)XYX"sv, event_pic_tiny_thumb_1399  };

/* Miku Expo 2016 Seattle */
constexpr std::array<additional_name, 1> names_1859 {{
  {"English"sv, R"XYX(Miku Expo 2016 Seattle)XYX"sv},
}};

/* Miku Expo 2016 Seattle */
constexpr std::array<web_link, 2> web_links_1859 {{
  {"Other"sv, "mikuexpo.com"sv, "http://mikuexpo.com/na2016/"sv, 612 },
  {"Other"sv, "mikufan.com Setlist"sv, "http://www.mikufan.com/hatsune-miku-expo-2016-in-north-america-seattle-concert-setlist-spoilers/#sthash.jKNG0ory.dpbs"sv, 613 },
}};

/* Miku Expo 2016 Seattle */

#if __has_embed("event_pic_orig_1859.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_orig_1859 = std::to_array<std::uint8_t>({
    #embed "event_pic_orig_1859.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_orig_1859;
#endif


#if __has_embed("event_pic_small_thumb_1859.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_small_thumb_1859 = std::to_array<std::uint8_t>({
    #embed "event_pic_small_thumb_1859.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_small_thumb_1859;
#endif


#if __has_embed("event_pic_thumb_1859.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_thumb_1859 = std::to_array<std::uint8_t>({
    #embed "event_pic_thumb_1859.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_thumb_1859;
#endif


#if __has_embed("event_pic_tiny_thumb_1859.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_tiny_thumb_1859 = std::to_array<std::uint8_t>({
    #embed "event_pic_tiny_thumb_1859.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_tiny_thumb_1859;
#endif

constexpr release_event_picture event_picture_1859 = { "image/jpeg", std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/1859.jpg?v=5)XYX"sv, event_pic_orig_1859, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/1859.jpg?v=5)XYX"sv, event_pic_small_thumb_1859, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/1859.jpg?v=5)XYX"sv, event_pic_thumb_1859, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/1859.jpg?v=5)XYX"sv, event_pic_tiny_thumb_1859  };

/* Miku Expo 2016 New Taipei City */
constexpr std::array<additional_name, 1> names_1941 {{
  {"English"sv, R"XYX(Miku Expo 2016 New Taipei City)XYX"sv},
}};

/* Miku Expo 2016 New Taipei City */
constexpr std::array<web_link, 4> web_links_1941 {{
  {"Other"sv, "Official website"sv, "https://mikuexpo.com/tw2016/"sv, 966 },
  {"Official"sv, "Facebook"sv, "https://www.facebook.com/mikuexpo2016tw"sv, 967 },
  {"Other"sv, "Mikufan"sv, "https://www.mikufan.com/hatsune-miku-returns-to-taiwan-for-hatsune-miku-expo-2016-in-taiwan-on-stage-june-25th-26th/"sv, 968 },
  {"Reference"sv, "Vocaloid Wiki"sv, "https://vocaloid.fandom.com/wiki/HATSUNE_MIKU_EXPO_2016_in_TAIWAN"sv, 969 },
}};

/* Miku Expo 2016 New Taipei City */

#if __has_embed("event_pic_orig_1941.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_orig_1941 = std::to_array<std::uint8_t>({
    #embed "event_pic_orig_1941.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_orig_1941;
#endif


#if __has_embed("event_pic_small_thumb_1941.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_small_thumb_1941 = std::to_array<std::uint8_t>({
    #embed "event_pic_small_thumb_1941.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_small_thumb_1941;
#endif


#if __has_embed("event_pic_thumb_1941.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_thumb_1941 = std::to_array<std::uint8_t>({
    #embed "event_pic_thumb_1941.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_thumb_1941;
#endif


#if __has_embed("event_pic_tiny_thumb_1941.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_tiny_thumb_1941 = std::to_array<std::uint8_t>({
    #embed "event_pic_tiny_thumb_1941.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_tiny_thumb_1941;
#endif

constexpr release_event_picture event_picture_1941 = { "image/jpeg", std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/1941.jpg?v=4)XYX"sv, event_pic_orig_1941, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/1941.jpg?v=4)XYX"sv, event_pic_small_thumb_1941, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/1941.jpg?v=4)XYX"sv, event_pic_thumb_1941, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/1941.jpg?v=4)XYX"sv, event_pic_tiny_thumb_1941  };

/* Hatsune Miku Magical Mirai 2016 */
constexpr std::array<additional_name, 4> names_1398 {{
  {"Japanese"sv, R"XYX(初音ミク「マジカルミライ 2016」)XYX"sv},
  {"English"sv, R"XYX(Hatsune Miku Magical Mirai 2016)XYX"sv},
  {"Unspecified"sv, R"XYX(マジカルミライ 2016)XYX"sv},
  {"Unspecified"sv, R"XYX(Magical Mirai 2016)XYX"sv},
}};

/* Hatsune Miku Magical Mirai 2016 */
constexpr std::array<web_link, 2> web_links_1398 {{
  {"Other"sv, "Website (JP)"sv, "http://magicalmirai.com/2016/"sv, 192 },
  {"Other"sv, "Website (EN)"sv, "https://magicalmirai.com/2016/index_en.php"sv, 1895 },
}};

/* Hatsune Miku Magical Mirai 2016 */

#if __has_embed("event_pic_orig_1398.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_orig_1398 = std::to_array<std::uint8_t>({
    #embed "event_pic_orig_1398.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_orig_1398;
#endif


#if __has_embed("event_pic_small_thumb_1398.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_small_thumb_1398 = std::to_array<std::uint8_t>({
    #embed "event_pic_small_thumb_1398.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_small_thumb_1398;
#endif


#if __has_embed("event_pic_thumb_1398.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_thumb_1398 = std::to_array<std::uint8_t>({
    #embed "event_pic_thumb_1398.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_thumb_1398;
#endif


#if __has_embed("event_pic_tiny_thumb_1398.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_tiny_thumb_1398 = std::to_array<std::uint8_t>({
    #embed "event_pic_tiny_thumb_1398.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_tiny_thumb_1398;
#endif

constexpr release_event_picture event_picture_1398 = { "image/jpeg", std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/1398.jpg?v=3)XYX"sv, event_pic_orig_1398, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/1398.jpg?v=3)XYX"sv, event_pic_small_thumb_1398, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/1398.jpg?v=3)XYX"sv, event_pic_thumb_1398, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/1398.jpg?v=3)XYX"sv, event_pic_tiny_thumb_1398  };

/* Miku Expo 2016 Shanghai */
constexpr std::array<additional_name, 1> names_1943 {{
  {"English"sv, R"XYX(Miku Expo 2016 Shanghai)XYX"sv},
}};

/* Miku Expo 2016 Shanghai */
constexpr std::array<web_link, 0> web_links_1943 {{
}};

/* Miku Expo 2016 Shanghai */

#if __has_embed("event_pic_orig_1943.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_orig_1943 = std::to_array<std::uint8_t>({
    #embed "event_pic_orig_1943.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_orig_1943;
#endif


#if __has_embed("event_pic_small_thumb_1943.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_small_thumb_1943 = std::to_array<std::uint8_t>({
    #embed "event_pic_small_thumb_1943.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_small_thumb_1943;
#endif


#if __has_embed("event_pic_thumb_1943.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_thumb_1943 = std::to_array<std::uint8_t>({
    #embed "event_pic_thumb_1943.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_thumb_1943;
#endif


#if __has_embed("event_pic_tiny_thumb_1943.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_tiny_thumb_1943 = std::to_array<std::uint8_t>({
    #embed "event_pic_tiny_thumb_1943.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_tiny_thumb_1943;
#endif

constexpr release_event_picture event_picture_1943 = { "image/jpeg", std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEventSeries/mainOrig/82.jpg?v=4)XYX"sv, event_pic_orig_1943, R"XYX(https://static.vocadb.net/img/ReleaseEventSeries/mainSmall/82.jpg?v=4)XYX"sv, event_pic_small_thumb_1943, R"XYX(https://static.vocadb.net/img/ReleaseEventSeries/mainThumb/82.jpg?v=4)XYX"sv, event_pic_thumb_1943, R"XYX(https://static.vocadb.net/img/ReleaseEventSeries/mainTiny/82.jpg?v=4)XYX"sv, event_pic_tiny_thumb_1943  };

/* Hatsune Miku × Kodō Special Live */
constexpr std::array<additional_name, 4> names_2947 {{
  {"Japanese"sv, R"XYX(初音ミク×鼓童スペシャルライブ)XYX"sv},
  {"English"sv, R"XYX(Hatsune Miku × Kodō Special Live)XYX"sv},
  {"Unspecified"sv, R"XYX(初音ミク×鼓童　スペシャルライブ | Ｔｈｉｓ　ｉｓ　ＮＩＰＰＯＮ　プレミアムシアター)XYX"sv},
  {"Unspecified"sv, R"XYX(Hatsune Miku × Kodō Special Live | This is NIPPON Premium Theater)XYX"sv},
}};

/* Hatsune Miku × Kodō Special Live */
constexpr std::array<web_link, 1> web_links_2947 {{
  {"Other"sv, "Website"sv, "https://kodo-miku.com/2017/index.html"sv, 1495 },
}};

/* Hatsune Miku × Kodō Special Live */

#if __has_embed("event_pic_orig_2947.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_orig_2947 = std::to_array<std::uint8_t>({
    #embed "event_pic_orig_2947.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_orig_2947;
#endif


#if __has_embed("event_pic_small_thumb_2947.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_small_thumb_2947 = std::to_array<std::uint8_t>({
    #embed "event_pic_small_thumb_2947.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_small_thumb_2947;
#endif


#if __has_embed("event_pic_thumb_2947.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_thumb_2947 = std::to_array<std::uint8_t>({
    #embed "event_pic_thumb_2947.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_thumb_2947;
#endif


#if __has_embed("event_pic_tiny_thumb_2947.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_tiny_thumb_2947 = std::to_array<std::uint8_t>({
    #embed "event_pic_tiny_thumb_2947.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_tiny_thumb_2947;
#endif

constexpr release_event_picture event_picture_2947 = { "image/jpeg", std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/2947.jpg?v=3)XYX"sv, event_pic_orig_2947, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/2947.jpg?v=3)XYX"sv, event_pic_small_thumb_2947, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/2947.jpg?v=3)XYX"sv, event_pic_thumb_2947, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/2947.jpg?v=3)XYX"sv, event_pic_tiny_thumb_2947  };

/* Hatsune Miku Magical Mirai 2017 */
constexpr std::array<additional_name, 4> names_1397 {{
  {"Japanese"sv, R"XYX(初音ミク「マジカルミライ 2017」)XYX"sv},
  {"English"sv, R"XYX(Hatsune Miku Magical Mirai 2017)XYX"sv},
  {"Unspecified"sv, R"XYX(マジカルミライ 2017)XYX"sv},
  {"Unspecified"sv, R"XYX(Magical Mirai 2017)XYX"sv},
}};

/* Hatsune Miku Magical Mirai 2017 */
constexpr std::array<web_link, 3> web_links_1397 {{
  {"Other"sv, "Website (JP)"sv, "http://magicalmirai.com/2017/"sv, 191 },
  {"Other"sv, "Website (EN)"sv, "http://magicalmirai.com/2017/index_en.html"sv, 193 },
  {"Reference"sv, "Vocaloid Wiki"sv, "http://vocaloid.wikia.com/wiki/Hatsune_Miku_Magical_Mirai_2017"sv, 354 },
}};

/* Hatsune Miku Magical Mirai 2017 */

#if __has_embed("event_pic_orig_1397.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_orig_1397 = std::to_array<std::uint8_t>({
    #embed "event_pic_orig_1397.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_orig_1397;
#endif


#if __has_embed("event_pic_small_thumb_1397.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_small_thumb_1397 = std::to_array<std::uint8_t>({
    #embed "event_pic_small_thumb_1397.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_small_thumb_1397;
#endif


#if __has_embed("event_pic_thumb_1397.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_thumb_1397 = std::to_array<std::uint8_t>({
    #embed "event_pic_thumb_1397.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_thumb_1397;
#endif


#if __has_embed("event_pic_tiny_thumb_1397.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_tiny_thumb_1397 = std::to_array<std::uint8_t>({
    #embed "event_pic_tiny_thumb_1397.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_tiny_thumb_1397;
#endif

constexpr release_event_picture event_picture_1397 = { "image/jpeg", std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/1397.jpg?v=13)XYX"sv, event_pic_orig_1397, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/1397.jpg?v=13)XYX"sv, event_pic_small_thumb_1397, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/1397.jpg?v=13)XYX"sv, event_pic_thumb_1397, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/1397.jpg?v=13)XYX"sv, event_pic_tiny_thumb_1397  };

/* HATSUNE MIKU with YOU 2017 CHINA FESTIVAL */
constexpr std::array<additional_name, 3> names_1619 {{
  {"Unspecified"sv, R"XYX(未来（ミク）には君がいる·初音ミク２０１７上海ライブ)XYX"sv},
  {"Japanese"sv, R"XYX(未来有你·初音未来 2017 上海演唱会)XYX"sv},
  {"English"sv, R"XYX(HATSUNE MIKU with YOU 2017 CHINA FESTIVAL)XYX"sv},
}};

/* HATSUNE MIKU with YOU 2017 CHINA FESTIVAL */
constexpr std::array<web_link, 4> web_links_1619 {{
  {"Other"sv, "Announcement"sv, "https://mp.weixin.qq.com/s/Tuec1cbKO9EzjGxTWht1sg"sv, 409 },
  {"Other"sv, "Website"sv, "https://www.scla.com.cn/events/hatsunemiku2017/"sv, 447 },
  {"Other"sv, "Moegirlpedia"sv, "https://zh.moegirl.org.cn/%E6%9C%AA%E6%9D%A5%E6%9C%89%E4%BD%A0%C2%B7%E5%88%9D%E9%9F%B3%E6%9C%AA%E6%9D%A52017%E6%BC%94%E5%94%B1%E4%BC%9A"sv, 1852 },
  {"Other"sv, "HATSUNE MIKU OFFICIAL BLOG"sv, "https://blog.piapro.net/2017/11/mon171120.html"sv, 1853 },
}};

/* HATSUNE MIKU with YOU 2017 CHINA FESTIVAL */

#if __has_embed("event_pic_orig_1619.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_orig_1619 = std::to_array<std::uint8_t>({
    #embed "event_pic_orig_1619.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_orig_1619;
#endif


#if __has_embed("event_pic_small_thumb_1619.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_small_thumb_1619 = std::to_array<std::uint8_t>({
    #embed "event_pic_small_thumb_1619.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_small_thumb_1619;
#endif


#if __has_embed("event_pic_thumb_1619.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_thumb_1619 = std::to_array<std::uint8_t>({
    #embed "event_pic_thumb_1619.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_thumb_1619;
#endif


#if __has_embed("event_pic_tiny_thumb_1619.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_tiny_thumb_1619 = std::to_array<std::uint8_t>({
    #embed "event_pic_tiny_thumb_1619.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_tiny_thumb_1619;
#endif

constexpr release_event_picture event_picture_1619 = { "image/jpeg", std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/1619.jpg?v=13)XYX"sv, event_pic_orig_1619, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/1619.jpg?v=13)XYX"sv, event_pic_small_thumb_1619, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/1619.jpg?v=13)XYX"sv, event_pic_thumb_1619, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/1619.jpg?v=13)XYX"sv, event_pic_tiny_thumb_1619  };

/* Miku Expo 2017 Kuala Lumpur */
constexpr std::array<additional_name, 1> names_1584 {{
  {"English"sv, R"XYX(Miku Expo 2017 Kuala Lumpur)XYX"sv},
}};

/* Miku Expo 2017 Kuala Lumpur */
constexpr std::array<web_link, 2> web_links_1584 {{
  {"Other"sv, "Website"sv, "http://mikuexpo.com/may2017/"sv, 377 },
  {"Other"sv, "Youtube official highlights"sv, "https://www.youtube.com/watch?v=AJEKjAaIp84"sv, 469 },
}};

/* Miku Expo 2017 Kuala Lumpur */

#if __has_embed("event_pic_orig_1584.png") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_orig_1584 = std::to_array<std::uint8_t>({
    #embed "event_pic_orig_1584.png"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_orig_1584;
#endif


#if __has_embed("event_pic_small_thumb_1584.png") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_small_thumb_1584 = std::to_array<std::uint8_t>({
    #embed "event_pic_small_thumb_1584.png"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_small_thumb_1584;
#endif


#if __has_embed("event_pic_thumb_1584.png") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_thumb_1584 = std::to_array<std::uint8_t>({
    #embed "event_pic_thumb_1584.png"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_thumb_1584;
#endif


#if __has_embed("event_pic_tiny_thumb_1584.png") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_tiny_thumb_1584 = std::to_array<std::uint8_t>({
    #embed "event_pic_tiny_thumb_1584.png"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_tiny_thumb_1584;
#endif

constexpr release_event_picture event_picture_1584 = { "image/png", std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/1584.png?v=6)XYX"sv, event_pic_orig_1584, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/1584.png?v=6)XYX"sv, event_pic_small_thumb_1584, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/1584.png?v=6)XYX"sv, event_pic_thumb_1584, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/1584.png?v=6)XYX"sv, event_pic_tiny_thumb_1584  };

/* SNOW MIKU LIVE! 2018 */
constexpr std::array<additional_name, 1> names_1618 {{
  {"English"sv, R"XYX(SNOW MIKU LIVE! 2018)XYX"sv},
}};

/* SNOW MIKU LIVE! 2018 */
constexpr std::array<web_link, 1> web_links_1618 {{
  {"Other"sv, "Website"sv, "http://snowmiku.com/2018/live_ticket.html"sv, 407 },
}};

/* SNOW MIKU LIVE! 2018 */

#if __has_embed("event_pic_orig_1618.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_orig_1618 = std::to_array<std::uint8_t>({
    #embed "event_pic_orig_1618.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_orig_1618;
#endif


#if __has_embed("event_pic_small_thumb_1618.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_small_thumb_1618 = std::to_array<std::uint8_t>({
    #embed "event_pic_small_thumb_1618.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_small_thumb_1618;
#endif


#if __has_embed("event_pic_thumb_1618.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_thumb_1618 = std::to_array<std::uint8_t>({
    #embed "event_pic_thumb_1618.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_thumb_1618;
#endif


#if __has_embed("event_pic_tiny_thumb_1618.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_tiny_thumb_1618 = std::to_array<std::uint8_t>({
    #embed "event_pic_tiny_thumb_1618.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_tiny_thumb_1618;
#endif

constexpr release_event_picture event_picture_1618 = { "image/jpeg", std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/1618.jpg?v=6)XYX"sv, event_pic_orig_1618, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/1618.jpg?v=6)XYX"sv, event_pic_small_thumb_1618, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/1618.jpg?v=6)XYX"sv, event_pic_thumb_1618, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/1618.jpg?v=6)XYX"sv, event_pic_tiny_thumb_1618  };

/* This is NIPPON Premium Theater Hatsune Miku × Kodō Special Live 2018 */
constexpr std::array<additional_name, 2> names_2948 {{
  {"Japanese"sv, R"XYX(Ｔｈｉｓ　ｉｓ　ＮＩＰＰＯＮ　プレミアムシアター 初音ミク×鼓童　スペシャルライブ　２０１８)XYX"sv},
  {"English"sv, R"XYX(This is NIPPON Premium Theater Hatsune Miku × Kodō Special Live 2018)XYX"sv},
}};

/* This is NIPPON Premium Theater Hatsune Miku × Kodō Special Live 2018 */
constexpr std::array<web_link, 1> web_links_2948 {{
  {"Other"sv, "Website"sv, "https://kodo-miku.com/2018/index.html"sv, 1496 },
}};

/* This is NIPPON Premium Theater Hatsune Miku × Kodō Special Live 2018 */

#if __has_embed("event_pic_orig_2948.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_orig_2948 = std::to_array<std::uint8_t>({
    #embed "event_pic_orig_2948.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_orig_2948;
#endif


#if __has_embed("event_pic_small_thumb_2948.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_small_thumb_2948 = std::to_array<std::uint8_t>({
    #embed "event_pic_small_thumb_2948.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_small_thumb_2948;
#endif


#if __has_embed("event_pic_thumb_2948.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_thumb_2948 = std::to_array<std::uint8_t>({
    #embed "event_pic_thumb_2948.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_thumb_2948;
#endif


#if __has_embed("event_pic_tiny_thumb_2948.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_tiny_thumb_2948 = std::to_array<std::uint8_t>({
    #embed "event_pic_tiny_thumb_2948.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_tiny_thumb_2948;
#endif

constexpr release_event_picture event_picture_2948 = { "image/jpeg", std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/2948.jpg?v=5)XYX"sv, event_pic_orig_2948, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/2948.jpg?v=5)XYX"sv, event_pic_small_thumb_2948, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/2948.jpg?v=5)XYX"sv, event_pic_thumb_2948, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/2948.jpg?v=5)XYX"sv, event_pic_tiny_thumb_2948  };

/* Miku Expo 2018 Los Angeles */
constexpr std::array<additional_name, 1> names_1673 {{
  {"English"sv, R"XYX(Miku Expo 2018 Los Angeles)XYX"sv},
}};

/* Miku Expo 2018 Los Angeles */
constexpr std::array<web_link, 0> web_links_1673 {{
}};

/* Miku Expo 2018 Los Angeles */

#if __has_embed("event_pic_orig_1673.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_orig_1673 = std::to_array<std::uint8_t>({
    #embed "event_pic_orig_1673.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_orig_1673;
#endif


#if __has_embed("event_pic_small_thumb_1673.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_small_thumb_1673 = std::to_array<std::uint8_t>({
    #embed "event_pic_small_thumb_1673.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_small_thumb_1673;
#endif


#if __has_embed("event_pic_thumb_1673.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_thumb_1673 = std::to_array<std::uint8_t>({
    #embed "event_pic_thumb_1673.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_thumb_1673;
#endif


#if __has_embed("event_pic_tiny_thumb_1673.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_tiny_thumb_1673 = std::to_array<std::uint8_t>({
    #embed "event_pic_tiny_thumb_1673.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_tiny_thumb_1673;
#endif

constexpr release_event_picture event_picture_1673 = { "image/jpeg", std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/1673.jpg?v=3)XYX"sv, event_pic_orig_1673, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/1673.jpg?v=3)XYX"sv, event_pic_small_thumb_1673, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/1673.jpg?v=3)XYX"sv, event_pic_thumb_1673, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/1673.jpg?v=3)XYX"sv, event_pic_tiny_thumb_1673  };

/* Hatsune Miku Magical Mirai 2018 in OSAKA */
constexpr std::array<additional_name, 4> names_1561 {{
  {"Japanese"sv, R"XYX(初音ミク「マジカルミライ 2018」in OSAKA)XYX"sv},
  {"English"sv, R"XYX(Hatsune Miku Magical Mirai 2018 in OSAKA)XYX"sv},
  {"Unspecified"sv, R"XYX(マジカルミライ 2018 Osaka)XYX"sv},
  {"Unspecified"sv, R"XYX(Magical Mirai 2018 Osaka)XYX"sv},
}};

/* Hatsune Miku Magical Mirai 2018 in OSAKA */
constexpr std::array<web_link, 4> web_links_1561 {{
  {"Other"sv, "Website (EN)"sv, "http://magicalmirai.com/2018/index_en.html"sv, 526 },
  {"Other"sv, "Website (JP)"sv, "http://magicalmirai.com/2018/"sv, 355 },
  {"Other"sv, "Website - OSAKA (EN)"sv, "https://magicalmirai.com/2018/osaka_top_en.html"sv, 1891 },
  {"Other"sv, "Website - OSAKA (JP)"sv, "https://magicalmirai.com/2018/osaka_top.html"sv, 1892 },
}};

/* Hatsune Miku Magical Mirai 2018 in OSAKA */

#if __has_embed("event_pic_orig_1561.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_orig_1561 = std::to_array<std::uint8_t>({
    #embed "event_pic_orig_1561.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_orig_1561;
#endif


#if __has_embed("event_pic_small_thumb_1561.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_small_thumb_1561 = std::to_array<std::uint8_t>({
    #embed "event_pic_small_thumb_1561.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_small_thumb_1561;
#endif


#if __has_embed("event_pic_thumb_1561.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_thumb_1561 = std::to_array<std::uint8_t>({
    #embed "event_pic_thumb_1561.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_thumb_1561;
#endif


#if __has_embed("event_pic_tiny_thumb_1561.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_tiny_thumb_1561 = std::to_array<std::uint8_t>({
    #embed "event_pic_tiny_thumb_1561.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_tiny_thumb_1561;
#endif

constexpr release_event_picture event_picture_1561 = { "image/jpeg", std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/1561.jpg?v=13)XYX"sv, event_pic_orig_1561, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/1561.jpg?v=13)XYX"sv, event_pic_small_thumb_1561, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/1561.jpg?v=13)XYX"sv, event_pic_thumb_1561, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/1561.jpg?v=13)XYX"sv, event_pic_tiny_thumb_1561  };

/* MIKU WITH YOU 2018 in Beijing */
constexpr std::array<additional_name, 3> names_2085 {{
  {"English"sv, R"XYX(MIKU WITH YOU 2018 in Beijing)XYX"sv},
  {"Japanese"sv, R"XYX(未来有你 2018 in Beijing)XYX"sv},
  {"Unspecified"sv, R"XYX(HATSUNE MIKU WITH YOU 2018 in Beijing)XYX"sv},
}};

/* MIKU WITH YOU 2018 in Beijing */
constexpr std::array<web_link, 3> web_links_2085 {{
  {"Other"sv, "Website"sv, "http://www.scla.com.cn/events/hatsunemiku2018/"sv, 812 },
  {"Other"sv, "Mikufan.com"sv, "https://www.mikufan.com/miku-with-you-2018-china-tour-starts-oct-13th-locations-dates-announced"sv, 814 },
  {"Reference"sv, "Vocaloid Wiki"sv, "http://vocaloid.wikia.com/wiki/MIKU_WITH_YOU_2018"sv, 910 },
}};

/* MIKU WITH YOU 2018 in Beijing */

#if __has_embed("event_pic_orig_2085.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_orig_2085 = std::to_array<std::uint8_t>({
    #embed "event_pic_orig_2085.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_orig_2085;
#endif


#if __has_embed("event_pic_small_thumb_2085.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_small_thumb_2085 = std::to_array<std::uint8_t>({
    #embed "event_pic_small_thumb_2085.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_small_thumb_2085;
#endif


#if __has_embed("event_pic_thumb_2085.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_thumb_2085 = std::to_array<std::uint8_t>({
    #embed "event_pic_thumb_2085.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_thumb_2085;
#endif


#if __has_embed("event_pic_tiny_thumb_2085.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_tiny_thumb_2085 = std::to_array<std::uint8_t>({
    #embed "event_pic_tiny_thumb_2085.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_tiny_thumb_2085;
#endif

constexpr release_event_picture event_picture_2085 = { "image/jpeg", std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/2085.jpg?v=14)XYX"sv, event_pic_orig_2085, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/2085.jpg?v=14)XYX"sv, event_pic_small_thumb_2085, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/2085.jpg?v=14)XYX"sv, event_pic_thumb_2085, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/2085.jpg?v=14)XYX"sv, event_pic_tiny_thumb_2085  };

/* Miku Expo 2018 Paris */
constexpr std::array<additional_name, 1> names_1854 {{
  {"English"sv, R"XYX(Miku Expo 2018 Paris)XYX"sv},
}};

/* Miku Expo 2018 Paris */
constexpr std::array<web_link, 3> web_links_1854 {{
  {"Other"sv, "Website"sv, "http://mikuexpo.com/europe2018/"sv, 607 },
  {"Other"sv, "Japonismes"sv, "https://japonismes.org/"sv, 628 },
  {"Reference"sv, "Vocaloid Wiki"sv, "http://vocaloid.wikia.com/wiki/HATSUNE_MIKU_EXPO_2018_EUROPE"sv, 906 },
}};

/* Miku Expo 2018 Paris */

#if __has_embed("event_pic_orig_1854.png") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_orig_1854 = std::to_array<std::uint8_t>({
    #embed "event_pic_orig_1854.png"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_orig_1854;
#endif


#if __has_embed("event_pic_small_thumb_1854.png") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_small_thumb_1854 = std::to_array<std::uint8_t>({
    #embed "event_pic_small_thumb_1854.png"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_small_thumb_1854;
#endif


#if __has_embed("event_pic_thumb_1854.png") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_thumb_1854 = std::to_array<std::uint8_t>({
    #embed "event_pic_thumb_1854.png"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_thumb_1854;
#endif


#if __has_embed("event_pic_tiny_thumb_1854.png") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_tiny_thumb_1854 = std::to_array<std::uint8_t>({
    #embed "event_pic_tiny_thumb_1854.png"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_tiny_thumb_1854;
#endif

constexpr release_event_picture event_picture_1854 = { "image/png", std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/1854.png?v=7)XYX"sv, event_pic_orig_1854, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/1854.png?v=7)XYX"sv, event_pic_small_thumb_1854, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/1854.png?v=7)XYX"sv, event_pic_thumb_1854, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/1854.png?v=7)XYX"sv, event_pic_tiny_thumb_1854  };

/* SNOW MIKU LIVE! 2019 */
constexpr std::array<additional_name, 1> names_2422 {{
  {"English"sv, R"XYX(SNOW MIKU LIVE! 2019)XYX"sv},
}};

/* SNOW MIKU LIVE! 2019 */
constexpr std::array<web_link, 2> web_links_2422 {{
  {"Other"sv, "Mikufan.com"sv, "https://www.mikufan.com/snow-miku-2019-main-visual-by-kei-snow-miku-live-2019-theme-song-preview-more/#sthash.253HD46r.dpbs"sv, 876 },
  {"Other"sv, "Website"sv, "https://snowmiku.com/2019/live_zepp.html"sv, 877 },
}};

/* SNOW MIKU LIVE! 2019 */

#if __has_embed("event_pic_orig_2422.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_orig_2422 = std::to_array<std::uint8_t>({
    #embed "event_pic_orig_2422.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_orig_2422;
#endif


#if __has_embed("event_pic_small_thumb_2422.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_small_thumb_2422 = std::to_array<std::uint8_t>({
    #embed "event_pic_small_thumb_2422.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_small_thumb_2422;
#endif


#if __has_embed("event_pic_thumb_2422.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_thumb_2422 = std::to_array<std::uint8_t>({
    #embed "event_pic_thumb_2422.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_thumb_2422;
#endif


#if __has_embed("event_pic_tiny_thumb_2422.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_tiny_thumb_2422 = std::to_array<std::uint8_t>({
    #embed "event_pic_tiny_thumb_2422.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_tiny_thumb_2422;
#endif

constexpr release_event_picture event_picture_2422 = { "image/jpeg", std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/2422.jpg?v=14)XYX"sv, event_pic_orig_2422, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/2422.jpg?v=14)XYX"sv, event_pic_small_thumb_2422, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/2422.jpg?v=14)XYX"sv, event_pic_thumb_2422, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/2422.jpg?v=14)XYX"sv, event_pic_tiny_thumb_2422  };

/* Miku Expo 2019 New Taipei City */
constexpr std::array<additional_name, 1> names_2489 {{
  {"English"sv, R"XYX(Miku Expo 2019 New Taipei City)XYX"sv},
}};

/* Miku Expo 2019 New Taipei City */
constexpr std::array<web_link, 1> web_links_2489 {{
  {"Other"sv, "Mikufan.com"sv, "https://www.mikufan.com/hatsune-miku-expo-2019-in-taiwan-finishes-concert-setlist-revealed/"sv, 1140 },
}};

/* Miku Expo 2019 New Taipei City */

#if __has_embed("event_pic_orig_2489.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_orig_2489 = std::to_array<std::uint8_t>({
    #embed "event_pic_orig_2489.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_orig_2489;
#endif


#if __has_embed("event_pic_small_thumb_2489.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_small_thumb_2489 = std::to_array<std::uint8_t>({
    #embed "event_pic_small_thumb_2489.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_small_thumb_2489;
#endif


#if __has_embed("event_pic_thumb_2489.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_thumb_2489 = std::to_array<std::uint8_t>({
    #embed "event_pic_thumb_2489.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_thumb_2489;
#endif


#if __has_embed("event_pic_tiny_thumb_2489.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_tiny_thumb_2489 = std::to_array<std::uint8_t>({
    #embed "event_pic_tiny_thumb_2489.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_tiny_thumb_2489;
#endif

constexpr release_event_picture event_picture_2489 = { "image/jpeg", std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/2489.jpg?v=5)XYX"sv, event_pic_orig_2489, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/2489.jpg?v=5)XYX"sv, event_pic_small_thumb_2489, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/2489.jpg?v=5)XYX"sv, event_pic_thumb_2489, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/2489.jpg?v=5)XYX"sv, event_pic_tiny_thumb_2489  };

/* Hatsune Miku Magical Mirai 2019 in OSAKA */
constexpr std::array<additional_name, 4> names_2515 {{
  {"Japanese"sv, R"XYX(初音ミク「マジカルミライ 2019」in OSAKA)XYX"sv},
  {"English"sv, R"XYX(Hatsune Miku Magical Mirai 2019 in OSAKA)XYX"sv},
  {"Unspecified"sv, R"XYX(マジカルミライ 2019 Osaka)XYX"sv},
  {"Unspecified"sv, R"XYX(Magical Mirai 2019 Osaka)XYX"sv},
}};

/* Hatsune Miku Magical Mirai 2019 in OSAKA */
constexpr std::array<web_link, 4> web_links_2515 {{
  {"Other"sv, "Website (JP)"sv, "https://magicalmirai.com/2019/"sv, 1883 },
  {"Other"sv, "Website (EN)"sv, "https://magicalmirai.com/2019/index_en.html"sv, 1884 },
  {"Other"sv, "Website - OSAKA (JP)"sv, "https://magicalmirai.com/2019/osaka_top.html"sv, 1885 },
  {"Other"sv, "Website - OSAKA (EN)"sv, "https://magicalmirai.com/2019/osaka_top_en.html"sv, 1886 },
}};

/* Hatsune Miku Magical Mirai 2019 in OSAKA */

#if __has_embed("event_pic_orig_2515.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_orig_2515 = std::to_array<std::uint8_t>({
    #embed "event_pic_orig_2515.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_orig_2515;
#endif


#if __has_embed("event_pic_small_thumb_2515.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_small_thumb_2515 = std::to_array<std::uint8_t>({
    #embed "event_pic_small_thumb_2515.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_small_thumb_2515;
#endif


#if __has_embed("event_pic_thumb_2515.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_thumb_2515 = std::to_array<std::uint8_t>({
    #embed "event_pic_thumb_2515.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_thumb_2515;
#endif


#if __has_embed("event_pic_tiny_thumb_2515.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_tiny_thumb_2515 = std::to_array<std::uint8_t>({
    #embed "event_pic_tiny_thumb_2515.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_tiny_thumb_2515;
#endif

constexpr release_event_picture event_picture_2515 = { "image/jpeg", std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/2515.jpg?v=7)XYX"sv, event_pic_orig_2515, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/2515.jpg?v=7)XYX"sv, event_pic_small_thumb_2515, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/2515.jpg?v=7)XYX"sv, event_pic_thumb_2515, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/2515.jpg?v=7)XYX"sv, event_pic_tiny_thumb_2515  };

/* MIKU WITH YOU 2019 in Shanghai */
constexpr std::array<additional_name, 3> names_3752 {{
  {"English"sv, R"XYX(MIKU WITH YOU 2019 in Shanghai)XYX"sv},
  {"Japanese"sv, R"XYX(未来有你 2019 in Shanghai)XYX"sv},
  {"Unspecified"sv, R"XYX(HATSUNE MIKU WITH YOU 2019 in Shanghai)XYX"sv},
}};

/* MIKU WITH YOU 2019 in Shanghai */
constexpr std::array<web_link, 2> web_links_3752 {{
  {"Other"sv, "Website"sv, "https://www.scla.com.cn/events/hatsunemiku2019/"sv, 1844 },
  {"Other"sv, "Mikufan.com"sv, "https://www.mikufan.com/miku-with-you-2019-live-performance-confirmed-for-shanghai-four-main-visuals-revealed/"sv, 1845 },
}};

/* MIKU WITH YOU 2019 in Shanghai */

#if __has_embed("event_pic_orig_3752.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_orig_3752 = std::to_array<std::uint8_t>({
    #embed "event_pic_orig_3752.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_orig_3752;
#endif


#if __has_embed("event_pic_small_thumb_3752.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_small_thumb_3752 = std::to_array<std::uint8_t>({
    #embed "event_pic_small_thumb_3752.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_small_thumb_3752;
#endif


#if __has_embed("event_pic_thumb_3752.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_thumb_3752 = std::to_array<std::uint8_t>({
    #embed "event_pic_thumb_3752.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_thumb_3752;
#endif


#if __has_embed("event_pic_tiny_thumb_3752.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_tiny_thumb_3752 = std::to_array<std::uint8_t>({
    #embed "event_pic_tiny_thumb_3752.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_tiny_thumb_3752;
#endif

constexpr release_event_picture event_picture_3752 = { "image/jpeg", std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/3752.jpg?v=2)XYX"sv, event_pic_orig_3752, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/3752.jpg?v=2)XYX"sv, event_pic_small_thumb_3752, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/3752.jpg?v=2)XYX"sv, event_pic_thumb_3752, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/3752.jpg?v=2)XYX"sv, event_pic_tiny_thumb_3752  };

/* Miku Expo 2020 London */
constexpr std::array<additional_name, 1> names_2786 {{
  {"Japanese"sv, R"XYX(Miku Expo 2020 London)XYX"sv},
}};

/* Miku Expo 2020 London */
constexpr std::array<web_link, 1> web_links_2786 {{
  {"Official"sv, "Facebook"sv, "https://www.facebook.com/events/2412779312331207/"sv, 1257 },
}};

/* Miku Expo 2020 London */

#if __has_embed("event_pic_orig_2786.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_orig_2786 = std::to_array<std::uint8_t>({
    #embed "event_pic_orig_2786.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_orig_2786;
#endif


#if __has_embed("event_pic_small_thumb_2786.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_small_thumb_2786 = std::to_array<std::uint8_t>({
    #embed "event_pic_small_thumb_2786.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_small_thumb_2786;
#endif


#if __has_embed("event_pic_thumb_2786.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_thumb_2786 = std::to_array<std::uint8_t>({
    #embed "event_pic_thumb_2786.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_thumb_2786;
#endif


#if __has_embed("event_pic_tiny_thumb_2786.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_tiny_thumb_2786 = std::to_array<std::uint8_t>({
    #embed "event_pic_tiny_thumb_2786.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_tiny_thumb_2786;
#endif

constexpr release_event_picture event_picture_2786 = { "image/jpeg", std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/2786.jpg?v=7)XYX"sv, event_pic_orig_2786, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/2786.jpg?v=7)XYX"sv, event_pic_small_thumb_2786, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/2786.jpg?v=7)XYX"sv, event_pic_thumb_2786, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/2786.jpg?v=7)XYX"sv, event_pic_tiny_thumb_2786  };

/* Nico Nico Net Chokaigi 2020 Natsu ✕ HATSUNE MIKU LIVE - UNTITLED 0 - */
constexpr std::array<additional_name, 2> names_2939 {{
  {"Japanese"sv, R"XYX(ニコニコネット超会議2020夏✕HATSUNE MIKU LIVE - UNTITLED 0 -)XYX"sv},
  {"Romaji"sv, R"XYX(Nico Nico Net Chokaigi 2020 Natsu ✕ HATSUNE MIKU LIVE - UNTITLED 0 -)XYX"sv},
}};

/* Nico Nico Net Chokaigi 2020 Natsu ✕ HATSUNE MIKU LIVE - UNTITLED 0 - */
constexpr std::array<web_link, 2> web_links_2939 {{
  {"Other"sv, "Piapro Blog Post"sv, "https://blog.piapro.net/2020/07/mo202004061-1.html"sv, 1476 },
  {"Other"sv, "Website"sv, "https://chokaigi.jp/2020summer/plan/mikulive.html"sv, 1477 },
}};

/* Nico Nico Net Chokaigi 2020 Natsu ✕ HATSUNE MIKU LIVE - UNTITLED 0 - */

#if __has_embed("event_pic_orig_2939.png") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_orig_2939 = std::to_array<std::uint8_t>({
    #embed "event_pic_orig_2939.png"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_orig_2939;
#endif


#if __has_embed("event_pic_small_thumb_2939.png") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_small_thumb_2939 = std::to_array<std::uint8_t>({
    #embed "event_pic_small_thumb_2939.png"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_small_thumb_2939;
#endif

constexpr std::array<std::uint8_t, 0> event_pic_thumb_2939;


#if __has_embed("event_pic_tiny_thumb_2939.png") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_tiny_thumb_2939 = std::to_array<std::uint8_t>({
    #embed "event_pic_tiny_thumb_2939.png"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_tiny_thumb_2939;
#endif

constexpr release_event_picture event_picture_2939 = { "image/png", std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/2939.png?v=4)XYX"sv, event_pic_orig_2939, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/2939.png?v=4)XYX"sv, event_pic_small_thumb_2939, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/2939.png?v=4)XYX"sv, event_pic_thumb_2939, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/2939.png?v=4)XYX"sv, event_pic_tiny_thumb_2939  };

/* Hatsune Miku Magical Mirai 2020 in OSAKA */
constexpr std::array<additional_name, 4> names_2758 {{
  {"Unspecified"sv, R"XYX(マジカルミライ 2020 Osaka)XYX"sv},
  {"Unspecified"sv, R"XYX(Magical Mirai 2020 Osaka)XYX"sv},
  {"English"sv, R"XYX(Hatsune Miku Magical Mirai 2020 in OSAKA)XYX"sv},
  {"Japanese"sv, R"XYX(初音ミク「マジカルミライ 2020」in OSAKA)XYX"sv},
}};

/* Hatsune Miku Magical Mirai 2020 in OSAKA */
constexpr std::array<web_link, 8> web_links_2758 {{
  {"Other"sv, "Website (JP)"sv, "https://magicalmirai.com/2020/osaka/"sv, 1382 },
  {"Other"sv, "Website (EN)"sv, "https://magicalmirai.com/2020/osaka/index_en.html"sv, 1383 },
  {"Official"sv, "Twitter (Postponement)"sv, "https://twitter.com/magicalmirai/status/1260761661066973184?s=19"sv, 1426 },
  {"Official"sv, "Twitter (New dates)"sv, "https://twitter.com/magicalmirai/status/1281048322694713344?s=19"sv, 1460 },
  {"Other"sv, "Online Live Information (EN)"sv, "https://magicalmirai.com/2020/osaka/special_en.html#special_online"sv, 1584 },
  {"Other"sv, "PIA LIVE STREAM"sv, "https://w.pia.jp/a/magicalmirai2020-osaka-plseng/"sv, 1585 },
  {"Other"sv, "KKBOX (Streaming)"sv, "https://kklivetw.kktix.cc/events/magicalmirai2020"sv, 1586 },
  {"Other"sv, "Online Live Information (JP)"sv, "https://magicalmirai.com/2020/osaka/special.html#special_online"sv, 1587 },
}};

/* Hatsune Miku Magical Mirai 2020 in OSAKA */

#if __has_embed("event_pic_orig_2758.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_orig_2758 = std::to_array<std::uint8_t>({
    #embed "event_pic_orig_2758.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_orig_2758;
#endif


#if __has_embed("event_pic_small_thumb_2758.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_small_thumb_2758 = std::to_array<std::uint8_t>({
    #embed "event_pic_small_thumb_2758.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_small_thumb_2758;
#endif


#if __has_embed("event_pic_thumb_2758.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_thumb_2758 = std::to_array<std::uint8_t>({
    #embed "event_pic_thumb_2758.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_thumb_2758;
#endif


#if __has_embed("event_pic_tiny_thumb_2758.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_tiny_thumb_2758 = std::to_array<std::uint8_t>({
    #embed "event_pic_tiny_thumb_2758.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_tiny_thumb_2758;
#endif

constexpr release_event_picture event_picture_2758 = { "image/jpeg", std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/2758.jpg?v=17)XYX"sv, event_pic_orig_2758, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/2758.jpg?v=17)XYX"sv, event_pic_small_thumb_2758, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/2758.jpg?v=17)XYX"sv, event_pic_thumb_2758, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/2758.jpg?v=17)XYX"sv, event_pic_tiny_thumb_2758  };

/* MIKU WITH YOU 2020 */
constexpr std::array<additional_name, 3> names_3250 {{
  {"English"sv, R"XYX(MIKU WITH YOU 2020)XYX"sv},
  {"Japanese"sv, R"XYX(未来有你 2020)XYX"sv},
  {"Unspecified"sv, R"XYX(HATSUNE MIKU WITH YOU 2020)XYX"sv},
}};

/* MIKU WITH YOU 2020 */
constexpr std::array<web_link, 2> web_links_3250 {{
  {"Official"sv, "Weibo (Announcement)"sv, "https://weibo.com/5582567326/JqeAidAw5"sv, 1574 },
  {"Other"sv, "HATSUNE MIKU OFFICIAL BLOG"sv, "https://blog.piapro.net/2020/10/zh2010211.html"sv, 1709 },
}};

/* MIKU WITH YOU 2020 */

#if __has_embed("event_pic_orig_3250.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_orig_3250 = std::to_array<std::uint8_t>({
    #embed "event_pic_orig_3250.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_orig_3250;
#endif


#if __has_embed("event_pic_small_thumb_3250.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_small_thumb_3250 = std::to_array<std::uint8_t>({
    #embed "event_pic_small_thumb_3250.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_small_thumb_3250;
#endif


#if __has_embed("event_pic_thumb_3250.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_thumb_3250 = std::to_array<std::uint8_t>({
    #embed "event_pic_thumb_3250.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_thumb_3250;
#endif


#if __has_embed("event_pic_tiny_thumb_3250.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_tiny_thumb_3250 = std::to_array<std::uint8_t>({
    #embed "event_pic_tiny_thumb_3250.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_tiny_thumb_3250;
#endif

constexpr release_event_picture event_picture_3250 = { "image/jpeg", std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/3250.jpg?v=6)XYX"sv, event_pic_orig_3250, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/3250.jpg?v=6)XYX"sv, event_pic_small_thumb_3250, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/3250.jpg?v=6)XYX"sv, event_pic_thumb_3250, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/3250.jpg?v=6)XYX"sv, event_pic_tiny_thumb_3250  };

/* Miku Expo 2021 Online */
constexpr std::array<additional_name, 2> names_3224 {{
  {"English"sv, R"XYX(Miku Expo 2021 Online)XYX"sv},
  {"Unspecified"sv, R"XYX(HATSUNE MIKU EXPO 2021 Online)XYX"sv},
}};

/* Miku Expo 2021 Online */
constexpr std::array<web_link, 10> web_links_3224 {{
  {"Official"sv, "Twitter"sv, "https://twitter.com/mikuexpo/status/1314385636560838656/"sv, 1563 },
  {"Other"sv, "Kickstarter"sv, "https://www.kickstarter.com/projects/cryptonfuturemedia/hatsune-miku-global-concert-hatsune-miku-expo-2021-online"sv, 1588 },
  {"Other"sv, "Website (EN)"sv, "https://mikuexpo.com/online2021/index_en.html"sv, 1704 },
  {"Other"sv, "Website (JP)"sv, "https://mikuexpo.com/online2021/index.html"sv, 1705 },
  {"Other"sv, "Website - Sub-events (EN)"sv, "https://mikuexpo.com/online2021/events_en.html"sv, 1811 },
  {"Other"sv, "Website - Sub-events (JP)"sv, "https://mikuexpo.com/online2021/events.html"sv, 1812 },
  {"Reference"sv, "MIKU EXPO Digital Stars 2021 Online"sv, "https://vocadb.net/E/3706/miku-expo-digital-stars-2021-o"sv, 1813 },
  {"Reference"sv, "HATSUNE MIKU EXPO 2021 Online Song Contest"sv, "https://vocadb.net/E/3252/miku-expo-song-contest-2021"sv, 1814 },
  {"Other"sv, "HATSUNE MIKU OFFICIAL BLOG"sv, "https://blog.piapro.net/2021/04/ta2104061.html"sv, 1843 },
  {"Other"sv, "#MIKU WORLD GALLERY"sv, "https://paint.mikuexpo.com/MikuWorldGallery/"sv, 2050 },
}};

/* Miku Expo 2021 Online */

#if __has_embed("event_pic_orig_3224.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_orig_3224 = std::to_array<std::uint8_t>({
    #embed "event_pic_orig_3224.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_orig_3224;
#endif


#if __has_embed("event_pic_small_thumb_3224.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_small_thumb_3224 = std::to_array<std::uint8_t>({
    #embed "event_pic_small_thumb_3224.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_small_thumb_3224;
#endif


#if __has_embed("event_pic_thumb_3224.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_thumb_3224 = std::to_array<std::uint8_t>({
    #embed "event_pic_thumb_3224.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_thumb_3224;
#endif


#if __has_embed("event_pic_tiny_thumb_3224.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_tiny_thumb_3224 = std::to_array<std::uint8_t>({
    #embed "event_pic_tiny_thumb_3224.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_tiny_thumb_3224;
#endif

constexpr release_event_picture event_picture_3224 = { "image/jpeg", std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/3224.jpg?v=18)XYX"sv, event_pic_orig_3224, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/3224.jpg?v=18)XYX"sv, event_pic_small_thumb_3224, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/3224.jpg?v=18)XYX"sv, event_pic_thumb_3224, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/3224.jpg?v=18)XYX"sv, event_pic_tiny_thumb_3224  };

/* Hatsune Miku "Magical Mirai 2021" in OSAKA */
constexpr std::array<additional_name, 2> names_3305 {{
  {"Japanese"sv, R"XYX(初音ミク「マジカルミライ 2021」in OSAKA)XYX"sv},
  {"English"sv, R"XYX(Hatsune Miku "Magical Mirai 2021" in OSAKA)XYX"sv},
}};

/* Hatsune Miku "Magical Mirai 2021" in OSAKA */
constexpr std::array<web_link, 3> web_links_3305 {{
  {"Other"sv, "Website (JP)"sv, "https://magicalmirai.com/2021/osaka_ticket.html"sv, 2312 },
  {"Other"sv, "Website (EN)"sv, "https://magicalmirai.com/2021/osaka_overview_en.html"sv, 2313 },
  {"Reference"sv, "Creators Market 2021 OSAKA"sv, "https://vocadb.net/E/4030/magical-mirai-creators-market-"sv, 2558 },
}};

/* Hatsune Miku "Magical Mirai 2021" in OSAKA */

#if __has_embed("event_pic_orig_3305.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_orig_3305 = std::to_array<std::uint8_t>({
    #embed "event_pic_orig_3305.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_orig_3305;
#endif


#if __has_embed("event_pic_small_thumb_3305.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_small_thumb_3305 = std::to_array<std::uint8_t>({
    #embed "event_pic_small_thumb_3305.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_small_thumb_3305;
#endif


#if __has_embed("event_pic_thumb_3305.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_thumb_3305 = std::to_array<std::uint8_t>({
    #embed "event_pic_thumb_3305.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_thumb_3305;
#endif


#if __has_embed("event_pic_tiny_thumb_3305.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_tiny_thumb_3305 = std::to_array<std::uint8_t>({
    #embed "event_pic_tiny_thumb_3305.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_tiny_thumb_3305;
#endif

constexpr release_event_picture event_picture_3305 = { "image/jpeg", std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/3305.jpg?v=7)XYX"sv, event_pic_orig_3305, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/3305.jpg?v=7)XYX"sv, event_pic_small_thumb_3305, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/3305.jpg?v=7)XYX"sv, event_pic_thumb_3305, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/3305.jpg?v=7)XYX"sv, event_pic_tiny_thumb_3305  };

/* MIKU WITH YOU 2021 */
constexpr std::array<additional_name, 3> names_4058 {{
  {"English"sv, R"XYX(MIKU WITH YOU 2021)XYX"sv},
  {"Japanese"sv, R"XYX(未来有你 2021)XYX"sv},
  {"Unspecified"sv, R"XYX(HATSUNE MIKU WITH YOU 2021)XYX"sv},
}};

/* MIKU WITH YOU 2021 */
constexpr std::array<web_link, 1> web_links_4058 {{
  {"Official"sv, "Weibo (Announcement)"sv, "https://weibo.com/5582567326/L1a3K5EUz"sv, 2563 },
}};

/* MIKU WITH YOU 2021 */

#if __has_embed("event_pic_orig_4058.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_orig_4058 = std::to_array<std::uint8_t>({
    #embed "event_pic_orig_4058.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_orig_4058;
#endif


#if __has_embed("event_pic_small_thumb_4058.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_small_thumb_4058 = std::to_array<std::uint8_t>({
    #embed "event_pic_small_thumb_4058.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_small_thumb_4058;
#endif


#if __has_embed("event_pic_thumb_4058.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_thumb_4058 = std::to_array<std::uint8_t>({
    #embed "event_pic_thumb_4058.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_thumb_4058;
#endif


#if __has_embed("event_pic_tiny_thumb_4058.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_tiny_thumb_4058 = std::to_array<std::uint8_t>({
    #embed "event_pic_tiny_thumb_4058.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_tiny_thumb_4058;
#endif

constexpr release_event_picture event_picture_4058 = { "image/jpeg", std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/4058.jpg?v=5)XYX"sv, event_pic_orig_4058, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/4058.jpg?v=5)XYX"sv, event_pic_small_thumb_4058, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/4058.jpg?v=5)XYX"sv, event_pic_thumb_4058, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/4058.jpg?v=5)XYX"sv, event_pic_tiny_thumb_4058  };

/* Kagamine Rin・Len Happy 14th Birthday Party "Two You☆★" */
constexpr std::array<additional_name, 2> names_4161 {{
  {"Japanese"sv, R"XYX(鏡音リン・レン Happy 14th Birthday Party「Two You☆★」)XYX"sv},
  {"English"sv, R"XYX(Kagamine Rin・Len Happy 14th Birthday Party "Two You☆★")XYX"sv},
}};

/* Kagamine Rin・Len Happy 14th Birthday Party "Two You☆★" */
constexpr std::array<web_link, 3> web_links_4161 {{
  {"Other"sv, "Website"sv, "https://piapro.net/rinlen14thbd/live/"sv, 2801 },
  {"Official"sv, "Twitter"sv, "https://twitter.com/rinlen_live"sv, 2802 },
  {"Other"sv, "ePlus"sv, "https://ib.eplus.jp/rinlen14thbd"sv, 3290 },
}};

/* Kagamine Rin・Len Happy 14th Birthday Party "Two You☆★" */

#if __has_embed("event_pic_orig_4161.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_orig_4161 = std::to_array<std::uint8_t>({
    #embed "event_pic_orig_4161.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_orig_4161;
#endif


#if __has_embed("event_pic_small_thumb_4161.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_small_thumb_4161 = std::to_array<std::uint8_t>({
    #embed "event_pic_small_thumb_4161.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_small_thumb_4161;
#endif


#if __has_embed("event_pic_thumb_4161.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_thumb_4161 = std::to_array<std::uint8_t>({
    #embed "event_pic_thumb_4161.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_thumb_4161;
#endif


#if __has_embed("event_pic_tiny_thumb_4161.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_tiny_thumb_4161 = std::to_array<std::uint8_t>({
    #embed "event_pic_tiny_thumb_4161.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_tiny_thumb_4161;
#endif

constexpr release_event_picture event_picture_4161 = { "image/jpeg", std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/4161.jpg?v=9)XYX"sv, event_pic_orig_4161, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/4161.jpg?v=9)XYX"sv, event_pic_small_thumb_4161, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/4161.jpg?v=9)XYX"sv, event_pic_thumb_4161, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/4161.jpg?v=9)XYX"sv, event_pic_tiny_thumb_4161  };

/* Hatsune Miku "Magical Mirai" 10th Anniversary in OSAKA */
constexpr std::array<additional_name, 3> names_4233 {{
  {"Japanese"sv, R"XYX(初音ミク「マジカルミライ」10th Anniversary in OSAKA)XYX"sv},
  {"English"sv, R"XYX(Hatsune Miku "Magical Mirai" 10th Anniversary in OSAKA)XYX"sv},
  {"Unspecified"sv, R"XYX(初音ミク「マジカルミライ 2022」in OSAKA)XYX"sv},
}};

/* Hatsune Miku "Magical Mirai" 10th Anniversary in OSAKA */
constexpr std::array<web_link, 4> web_links_4233 {{
  {"Other"sv, "Website (JP)"sv, "https://magicalmirai.com/10th/"sv, 2974 },
  {"Other"sv, "Website (EN)"sv, "https://magicalmirai.com/10th/index_en.html"sv, 2975 },
  {"Other"sv, "Website - OSAKA (EN)"sv, "https://magicalmirai.com/10th/osaka_overview_en.html"sv, 2976 },
  {"Other"sv, "Website - OSAKA (JP)"sv, "https://magicalmirai.com/10th/osaka_ticket.html"sv, 2977 },
}};

/* Hatsune Miku "Magical Mirai" 10th Anniversary in OSAKA */

#if __has_embed("event_pic_orig_4233.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_orig_4233 = std::to_array<std::uint8_t>({
    #embed "event_pic_orig_4233.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_orig_4233;
#endif


#if __has_embed("event_pic_small_thumb_4233.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_small_thumb_4233 = std::to_array<std::uint8_t>({
    #embed "event_pic_small_thumb_4233.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_small_thumb_4233;
#endif


#if __has_embed("event_pic_thumb_4233.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_thumb_4233 = std::to_array<std::uint8_t>({
    #embed "event_pic_thumb_4233.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_thumb_4233;
#endif


#if __has_embed("event_pic_tiny_thumb_4233.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_tiny_thumb_4233 = std::to_array<std::uint8_t>({
    #embed "event_pic_tiny_thumb_4233.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_tiny_thumb_4233;
#endif

constexpr release_event_picture event_picture_4233 = { "image/jpeg", std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/4233.jpg?v=8)XYX"sv, event_pic_orig_4233, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/4233.jpg?v=8)XYX"sv, event_pic_small_thumb_4233, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/4233.jpg?v=8)XYX"sv, event_pic_thumb_4233, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/4233.jpg?v=8)XYX"sv, event_pic_tiny_thumb_4233  };

/* Hatsune Miku "Magical Mirai" 10th Anniversary in SAPPORO */
constexpr std::array<additional_name, 3> names_4235 {{
  {"Japanese"sv, R"XYX(初音ミク「マジカルミライ」10th Anniversary in SAPPORO)XYX"sv},
  {"English"sv, R"XYX(Hatsune Miku "Magical Mirai" 10th Anniversary in SAPPORO)XYX"sv},
  {"Unspecified"sv, R"XYX(初音ミク「マジカルミライ 2022」in SAPPORO)XYX"sv},
}};

/* Hatsune Miku "Magical Mirai" 10th Anniversary in SAPPORO */
constexpr std::array<web_link, 5> web_links_4235 {{
  {"Other"sv, "Website - SAPPORO (JP)"sv, "https://magicalmirai.com/10th/sapporo_ticket.html"sv, 2982 },
  {"Other"sv, "Website - SAPPORO (EN)"sv, "https://magicalmirai.com/10th/sapporo_overview_en.html"sv, 2983 },
  {"Other"sv, "Website (JP)"sv, "https://magicalmirai.com/10th/"sv, 2984 },
  {"Other"sv, "Website (EN)"sv, "https://magicalmirai.com/10th/index_en.html"sv, 2985 },
  {"Reference"sv, "SNOW MIKU 2023"sv, "https://vocadb.net/E/4818/snow-miku-2023"sv, 5505 },
}};

/* Hatsune Miku "Magical Mirai" 10th Anniversary in SAPPORO */

#if __has_embed("event_pic_orig_4235.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_orig_4235 = std::to_array<std::uint8_t>({
    #embed "event_pic_orig_4235.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_orig_4235;
#endif


#if __has_embed("event_pic_small_thumb_4235.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_small_thumb_4235 = std::to_array<std::uint8_t>({
    #embed "event_pic_small_thumb_4235.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_small_thumb_4235;
#endif


#if __has_embed("event_pic_thumb_4235.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_thumb_4235 = std::to_array<std::uint8_t>({
    #embed "event_pic_thumb_4235.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_thumb_4235;
#endif


#if __has_embed("event_pic_tiny_thumb_4235.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_tiny_thumb_4235 = std::to_array<std::uint8_t>({
    #embed "event_pic_tiny_thumb_4235.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_tiny_thumb_4235;
#endif

constexpr release_event_picture event_picture_4235 = { "image/jpeg", std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/4235.jpg?v=9)XYX"sv, event_pic_orig_4235, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/4235.jpg?v=9)XYX"sv, event_pic_small_thumb_4235, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/4235.jpg?v=9)XYX"sv, event_pic_thumb_4235, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/4235.jpg?v=9)XYX"sv, event_pic_tiny_thumb_4235  };

/* HATSUNE MIKU JAPAN TOUR 2023 〜THUNDERBOLT〜 NAGOYA */
constexpr std::array<additional_name, 2> names_4765 {{
  {"Japanese"sv, R"XYX(初音ミク JAPAN TOUR 2023 〜THUNDERBOLT〜 名古屋)XYX"sv},
  {"English"sv, R"XYX(HATSUNE MIKU JAPAN TOUR 2023 〜THUNDERBOLT〜 NAGOYA)XYX"sv},
}};

/* HATSUNE MIKU JAPAN TOUR 2023 〜THUNDERBOLT〜 NAGOYA */
constexpr std::array<web_link, 0> web_links_4765 {{
}};

/* HATSUNE MIKU JAPAN TOUR 2023 〜THUNDERBOLT〜 NAGOYA */

#if __has_embed("event_pic_orig_4765.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_orig_4765 = std::to_array<std::uint8_t>({
    #embed "event_pic_orig_4765.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_orig_4765;
#endif


#if __has_embed("event_pic_small_thumb_4765.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_small_thumb_4765 = std::to_array<std::uint8_t>({
    #embed "event_pic_small_thumb_4765.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_small_thumb_4765;
#endif


#if __has_embed("event_pic_thumb_4765.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_thumb_4765 = std::to_array<std::uint8_t>({
    #embed "event_pic_thumb_4765.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_thumb_4765;
#endif


#if __has_embed("event_pic_tiny_thumb_4765.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_tiny_thumb_4765 = std::to_array<std::uint8_t>({
    #embed "event_pic_tiny_thumb_4765.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_tiny_thumb_4765;
#endif

constexpr release_event_picture event_picture_4765 = { "image/jpeg", std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/4765.jpg?v=7)XYX"sv, event_pic_orig_4765, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/4765.jpg?v=7)XYX"sv, event_pic_small_thumb_4765, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/4765.jpg?v=7)XYX"sv, event_pic_thumb_4765, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/4765.jpg?v=7)XYX"sv, event_pic_tiny_thumb_4765  };

/* Hatsune Miku × Kodō Special Live 2023 ~Yui~ */
constexpr std::array<additional_name, 2> names_5910 {{
  {"Japanese"sv, R"XYX(初音ミク×鼓童スペシャルライブ２０２３ ～結～)XYX"sv},
  {"Romaji"sv, R"XYX(Hatsune Miku × Kodō Special Live 2023 ~Yui~)XYX"sv},
}};

/* Hatsune Miku × Kodō Special Live 2023 ~Yui~ */
constexpr std::array<web_link, 5> web_links_5910 {{
  {"Other"sv, "HATSUNE MIKU OFFICIAL BLOG"sv, "https://blog.piapro.net/2023/02/mon2302151.html"sv, 6813 },
  {"Other"sv, "Ticket PIA"sv, "https://w.pia.jp/t/kodo-miku-t/"sv, 6814 },
  {"Other"sv, "Website"sv, "https://kodo-miku.com/"sv, 6815 },
  {"Other"sv, "PR TIMES"sv, "https://prtimes.jp/main/html/rd/p/000000183.000052709.html"sv, 6816 },
  {"Official"sv, "Twitter (Announcement)"sv, "https://twitter.com/kodo_miku/status/1625676398202617858"sv, 6817 },
}};

/* Hatsune Miku × Kodō Special Live 2023 ~Yui~ */

#if __has_embed("event_pic_orig_5910.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_orig_5910 = std::to_array<std::uint8_t>({
    #embed "event_pic_orig_5910.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_orig_5910;
#endif


#if __has_embed("event_pic_small_thumb_5910.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_small_thumb_5910 = std::to_array<std::uint8_t>({
    #embed "event_pic_small_thumb_5910.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_small_thumb_5910;
#endif


#if __has_embed("event_pic_thumb_5910.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_thumb_5910 = std::to_array<std::uint8_t>({
    #embed "event_pic_thumb_5910.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_thumb_5910;
#endif


#if __has_embed("event_pic_tiny_thumb_5910.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_tiny_thumb_5910 = std::to_array<std::uint8_t>({
    #embed "event_pic_tiny_thumb_5910.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_tiny_thumb_5910;
#endif

constexpr release_event_picture event_picture_5910 = { "image/jpeg", std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/5910.jpg?v=2)XYX"sv, event_pic_orig_5910, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/5910.jpg?v=2)XYX"sv, event_pic_small_thumb_5910, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/5910.jpg?v=2)XYX"sv, event_pic_thumb_5910, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/5910.jpg?v=2)XYX"sv, event_pic_tiny_thumb_5910  };

/* Hatsune Miku "Magical Mirai 2023" in OSAKA */
constexpr std::array<additional_name, 2> names_6045 {{
  {"Japanese"sv, R"XYX(初音ミク「マジカルミライ 2023」in OSAKA)XYX"sv},
  {"English"sv, R"XYX(Hatsune Miku "Magical Mirai 2023" in OSAKA)XYX"sv},
}};

/* Hatsune Miku "Magical Mirai 2023" in OSAKA */
constexpr std::array<web_link, 8> web_links_6045 {{
  {"Other"sv, "Website (JP)"sv, "https://magicalmirai.com/2023/"sv, 7062 },
  {"Other"sv, "Website (EN)"sv, "https://magicalmirai.com/2023/index_en.html"sv, 7063 },
  {"Other"sv, "Website - OSAKA (JP)"sv, "https://magicalmirai.com/2023/osaka_ticket.html"sv, 7066 },
  {"Other"sv, "Website - OSAKA (EN)"sv, "https://magicalmirai.com/2023/osaka_ticket_en.html"sv, 7067 },
  {"Other"sv, "HATSUNE MIKU OFFICIAL BLOG"sv, "https://blog.piapro.net/2023/03/b2303091.html"sv, 7068 },
  {"Official"sv, "Twitter (Announcement) (EN)"sv, "https://twitter.com/cfm_miku_en/status/1633659602930917377"sv, 7069 },
  {"Official"sv, "Twitter (Announcement) (JP)"sv, "https://twitter.com/magicalmirai/status/1633652189238554624"sv, 7070 },
  {"Other"sv, "PR TIMES"sv, "https://prtimes.jp/main/html/rd/p/000000196.000052709.html"sv, 7071 },
}};

/* Hatsune Miku "Magical Mirai 2023" in OSAKA */

#if __has_embed("event_pic_orig_6045.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_orig_6045 = std::to_array<std::uint8_t>({
    #embed "event_pic_orig_6045.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_orig_6045;
#endif


#if __has_embed("event_pic_small_thumb_6045.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_small_thumb_6045 = std::to_array<std::uint8_t>({
    #embed "event_pic_small_thumb_6045.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_small_thumb_6045;
#endif


#if __has_embed("event_pic_thumb_6045.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_thumb_6045 = std::to_array<std::uint8_t>({
    #embed "event_pic_thumb_6045.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_thumb_6045;
#endif


#if __has_embed("event_pic_tiny_thumb_6045.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_tiny_thumb_6045 = std::to_array<std::uint8_t>({
    #embed "event_pic_tiny_thumb_6045.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_tiny_thumb_6045;
#endif

constexpr release_event_picture event_picture_6045 = { "image/jpeg", std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/6045.jpg?v=9)XYX"sv, event_pic_orig_6045, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/6045.jpg?v=9)XYX"sv, event_pic_small_thumb_6045, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/6045.jpg?v=9)XYX"sv, event_pic_thumb_6045, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/6045.jpg?v=9)XYX"sv, event_pic_tiny_thumb_6045  };

/* Miku Expo 2023 VR */
constexpr std::array<additional_name, 2> names_5751 {{
  {"English"sv, R"XYX(Miku Expo 2023 VR)XYX"sv},
  {"Unspecified"sv, R"XYX(HATSUNE MIKU EXPO 2023 VR)XYX"sv},
}};

/* Miku Expo 2023 VR */
constexpr std::array<web_link, 11> web_links_5751 {{
  {"Official"sv, "Twitter (Announcement) (1)"sv, "https://twitter.com/mikuexpo/status/1607197780468195328"sv, 6511 },
  {"Other"sv, "PR TIMES"sv, "https://prtimes.jp/main/html/rd/p/000000163.000052709.html"sv, 6512 },
  {"Other"sv, "Crypton Future Media (Press Release)"sv, "https://www.crypton.co.jp/cfm/news/2022/12/26me23vr"sv, 6513 },
  {"Other"sv, "Kickstarter"sv, "https://www.kickstarter.com/projects/cryptonfuturemedia/hatsune-miku-global-concert-hatsune-miku-expo-2023-vr"sv, 6756 },
  {"Official"sv, "Twitter (Announcement) (2)"sv, "https://twitter.com/mikuexpo/status/1622420905317240833"sv, 6757 },
  {"Other"sv, "HATSUNE MIKU OFFICIAL BLOG (1)"sv, "https://blog.piapro.net/2023/02/o2302061.html"sv, 6758 },
  {"Other"sv, "HATSUNE MIKU OFFICIAL BLOG (2)"sv, "https://blog.piapro.net/2023/03/o2303171.html"sv, 7183 },
  {"Other"sv, "Website (EN)"sv, "https://mikuexpo.com/vr2023/index_en.html"sv, 7325 },
  {"Other"sv, "Website (JP)"sv, "https://mikuexpo.com/vr2023/index.html"sv, 7326 },
  {"Official"sv, "Twitter (Timetable)"sv, "https://twitter.com/mikuexpo/status/1714467552838209763"sv, 8183 },
  {"Official"sv, "Twitter (Content Warning notice)"sv, "https://twitter.com/mikuexpo/status/1723488274654892171"sv, 8289 },
}};

/* Miku Expo 2023 VR */

#if __has_embed("event_pic_orig_5751.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_orig_5751 = std::to_array<std::uint8_t>({
    #embed "event_pic_orig_5751.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_orig_5751;
#endif


#if __has_embed("event_pic_small_thumb_5751.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_small_thumb_5751 = std::to_array<std::uint8_t>({
    #embed "event_pic_small_thumb_5751.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_small_thumb_5751;
#endif


#if __has_embed("event_pic_thumb_5751.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_thumb_5751 = std::to_array<std::uint8_t>({
    #embed "event_pic_thumb_5751.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_thumb_5751;
#endif


#if __has_embed("event_pic_tiny_thumb_5751.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_tiny_thumb_5751 = std::to_array<std::uint8_t>({
    #embed "event_pic_tiny_thumb_5751.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_tiny_thumb_5751;
#endif

constexpr release_event_picture event_picture_5751 = { "image/jpeg", std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/5751.jpg?v=13)XYX"sv, event_pic_orig_5751, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/5751.jpg?v=13)XYX"sv, event_pic_small_thumb_5751, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/5751.jpg?v=13)XYX"sv, event_pic_thumb_5751, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/5751.jpg?v=13)XYX"sv, event_pic_tiny_thumb_5751  };

/* MK15th project MEIKO＆KAITO Online Concert */
constexpr std::array<additional_name, 2> names_6539 {{
  {"English"sv, R"XYX(MK15th project MEIKO＆KAITO Online Concert)XYX"sv},
  {"Japanese"sv, R"XYX(MK15th project MEIKO＆KAITO オンラインコンサート)XYX"sv},
}};

/* MK15th project MEIKO＆KAITO Online Concert */
constexpr std::array<web_link, 1> web_links_6539 {{
  {"Other"sv, "HATSUNE MIKU OFFICIAL BLOG"sv, "https://blog.piapro.net/2023/09/nk2309141.html"sv, 7982 },
}};

/* MK15th project MEIKO＆KAITO Online Concert */

#if __has_embed("event_pic_orig_6539.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_orig_6539 = std::to_array<std::uint8_t>({
    #embed "event_pic_orig_6539.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_orig_6539;
#endif


#if __has_embed("event_pic_small_thumb_6539.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_small_thumb_6539 = std::to_array<std::uint8_t>({
    #embed "event_pic_small_thumb_6539.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_small_thumb_6539;
#endif


#if __has_embed("event_pic_thumb_6539.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_thumb_6539 = std::to_array<std::uint8_t>({
    #embed "event_pic_thumb_6539.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_thumb_6539;
#endif


#if __has_embed("event_pic_tiny_thumb_6539.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_tiny_thumb_6539 = std::to_array<std::uint8_t>({
    #embed "event_pic_tiny_thumb_6539.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_tiny_thumb_6539;
#endif

constexpr release_event_picture event_picture_6539 = { "image/jpeg", std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/6539.jpg?v=6)XYX"sv, event_pic_orig_6539, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/6539.jpg?v=6)XYX"sv, event_pic_small_thumb_6539, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/6539.jpg?v=6)XYX"sv, event_pic_thumb_6539, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/6539.jpg?v=6)XYX"sv, event_pic_tiny_thumb_6539  };

/* MIKU FES'24 (Spring)〜Happy 16th Birthday〜 */
constexpr std::array<additional_name, 3> names_6986 {{
  {"Japanese"sv, R"XYX(MIKU FES'24 (春)〜Happy 16th Birthday〜)XYX"sv},
  {"Romaji"sv, R"XYX(MIKU FES'24 (Haru)〜Happy 16th Birthday〜)XYX"sv},
  {"English"sv, R"XYX(MIKU FES'24 (Spring)〜Happy 16th Birthday〜)XYX"sv},
}};

/* MIKU FES'24 (Spring)〜Happy 16th Birthday〜 */
constexpr std::array<web_link, 2> web_links_6986 {{
  {"Official"sv, "Twitter"sv, "https://twitter.com/cfm_miku/status/1748273235702235618"sv, 8532 },
  {"Other"sv, "Official Page"sv, "https://mikufes24spring.jp/"sv, 8583 },
}};

/* MIKU FES'24 (Spring)〜Happy 16th Birthday〜 */

#if __has_embed("event_pic_orig_6986.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_orig_6986 = std::to_array<std::uint8_t>({
    #embed "event_pic_orig_6986.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_orig_6986;
#endif


#if __has_embed("event_pic_small_thumb_6986.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_small_thumb_6986 = std::to_array<std::uint8_t>({
    #embed "event_pic_small_thumb_6986.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_small_thumb_6986;
#endif


#if __has_embed("event_pic_thumb_6986.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_thumb_6986 = std::to_array<std::uint8_t>({
    #embed "event_pic_thumb_6986.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_thumb_6986;
#endif


#if __has_embed("event_pic_tiny_thumb_6986.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_tiny_thumb_6986 = std::to_array<std::uint8_t>({
    #embed "event_pic_tiny_thumb_6986.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_tiny_thumb_6986;
#endif

constexpr release_event_picture event_picture_6986 = { "image/jpeg", std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/6986.jpg?v=13)XYX"sv, event_pic_orig_6986, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/6986.jpg?v=13)XYX"sv, event_pic_small_thumb_6986, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/6986.jpg?v=13)XYX"sv, event_pic_thumb_6986, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/6986.jpg?v=13)XYX"sv, event_pic_tiny_thumb_6986  };

/* Miku Expo 2024 Vancouver  */
constexpr std::array<additional_name, 1> names_6516 {{
  {"English"sv, R"XYX(Miku Expo 2024 Vancouver )XYX"sv},
}};

/* Miku Expo 2024 Vancouver  */
constexpr std::array<web_link, 1> web_links_6516 {{
  {"Other"sv, "Official Webpage"sv, "https://mikuexpo.com/na2024/"sv, 7951 },
}};

/* Miku Expo 2024 Vancouver  */

#if __has_embed("event_pic_orig_6516.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_orig_6516 = std::to_array<std::uint8_t>({
    #embed "event_pic_orig_6516.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_orig_6516;
#endif


#if __has_embed("event_pic_small_thumb_6516.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_small_thumb_6516 = std::to_array<std::uint8_t>({
    #embed "event_pic_small_thumb_6516.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_small_thumb_6516;
#endif


#if __has_embed("event_pic_thumb_6516.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_thumb_6516 = std::to_array<std::uint8_t>({
    #embed "event_pic_thumb_6516.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_thumb_6516;
#endif


#if __has_embed("event_pic_tiny_thumb_6516.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_tiny_thumb_6516 = std::to_array<std::uint8_t>({
    #embed "event_pic_tiny_thumb_6516.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_tiny_thumb_6516;
#endif

constexpr release_event_picture event_picture_6516 = { "image/jpeg", std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/6516.jpg?v=9)XYX"sv, event_pic_orig_6516, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/6516.jpg?v=9)XYX"sv, event_pic_small_thumb_6516, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/6516.jpg?v=9)XYX"sv, event_pic_thumb_6516, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/6516.jpg?v=9)XYX"sv, event_pic_tiny_thumb_6516  };

/* MIKU WITH YOU 2024 in Shanghai */
constexpr std::array<additional_name, 3> names_7673 {{
  {"English"sv, R"XYX(MIKU WITH YOU 2024 in Shanghai)XYX"sv},
  {"Japanese"sv, R"XYX(未来有你 2024 in Shanghai)XYX"sv},
  {"Unspecified"sv, R"XYX(HATSUNE MIKU WITH YOU 2024 in Shanghai)XYX"sv},
}};

/* MIKU WITH YOU 2024 in Shanghai */
constexpr std::array<web_link, 0> web_links_7673 {{
}};

/* MIKU WITH YOU 2024 in Shanghai */

#if __has_embed("event_pic_orig_7673.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_orig_7673 = std::to_array<std::uint8_t>({
    #embed "event_pic_orig_7673.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_orig_7673;
#endif


#if __has_embed("event_pic_small_thumb_7673.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_small_thumb_7673 = std::to_array<std::uint8_t>({
    #embed "event_pic_small_thumb_7673.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_small_thumb_7673;
#endif


#if __has_embed("event_pic_thumb_7673.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_thumb_7673 = std::to_array<std::uint8_t>({
    #embed "event_pic_thumb_7673.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_thumb_7673;
#endif


#if __has_embed("event_pic_tiny_thumb_7673.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_tiny_thumb_7673 = std::to_array<std::uint8_t>({
    #embed "event_pic_tiny_thumb_7673.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_tiny_thumb_7673;
#endif

constexpr release_event_picture event_picture_7673 = { "image/jpeg", std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/7673.jpg?v=4)XYX"sv, event_pic_orig_7673, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/7673.jpg?v=4)XYX"sv, event_pic_small_thumb_7673, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/7673.jpg?v=4)XYX"sv, event_pic_thumb_7673, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/7673.jpg?v=4)XYX"sv, event_pic_tiny_thumb_7673  };

/* Hatsune Miku "Magical Mirai 2024" in FUKUOKA */
constexpr std::array<additional_name, 2> names_7214 {{
  {"Japanese"sv, R"XYX(初音ミク「マジカルミライ 2024」in FUKUOKA)XYX"sv},
  {"English"sv, R"XYX(Hatsune Miku "Magical Mirai 2024" in FUKUOKA)XYX"sv},
}};

/* Hatsune Miku "Magical Mirai 2024" in FUKUOKA */
constexpr std::array<web_link, 1> web_links_7214 {{
  {"Other"sv, "Website (EN)"sv, "https://magicalmirai.com/2024/fukuoka_ticket_en.html"sv, 8914 },
}};

/* Hatsune Miku "Magical Mirai 2024" in FUKUOKA */

#if __has_embed("event_pic_orig_7214.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_orig_7214 = std::to_array<std::uint8_t>({
    #embed "event_pic_orig_7214.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_orig_7214;
#endif


#if __has_embed("event_pic_small_thumb_7214.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_small_thumb_7214 = std::to_array<std::uint8_t>({
    #embed "event_pic_small_thumb_7214.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_small_thumb_7214;
#endif


#if __has_embed("event_pic_thumb_7214.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_thumb_7214 = std::to_array<std::uint8_t>({
    #embed "event_pic_thumb_7214.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_thumb_7214;
#endif


#if __has_embed("event_pic_tiny_thumb_7214.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_tiny_thumb_7214 = std::to_array<std::uint8_t>({
    #embed "event_pic_tiny_thumb_7214.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_tiny_thumb_7214;
#endif

constexpr release_event_picture event_picture_7214 = { "image/jpeg", std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/7214.jpg?v=9)XYX"sv, event_pic_orig_7214, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/7214.jpg?v=9)XYX"sv, event_pic_small_thumb_7214, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/7214.jpg?v=9)XYX"sv, event_pic_thumb_7214, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/7214.jpg?v=9)XYX"sv, event_pic_tiny_thumb_7214  };

/* Miku Expo 2024 London */
constexpr std::array<additional_name, 1> names_7266 {{
  {"English"sv, R"XYX(Miku Expo 2024 London)XYX"sv},
}};

/* Miku Expo 2024 London */
constexpr std::array<web_link, 1> web_links_7266 {{
  {"Other"sv, "Official Webpage"sv, "https://mikuexpo.com/europe2024/"sv, 8998 },
}};

/* Miku Expo 2024 London */

#if __has_embed("event_pic_orig_7266.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_orig_7266 = std::to_array<std::uint8_t>({
    #embed "event_pic_orig_7266.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_orig_7266;
#endif


#if __has_embed("event_pic_small_thumb_7266.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_small_thumb_7266 = std::to_array<std::uint8_t>({
    #embed "event_pic_small_thumb_7266.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_small_thumb_7266;
#endif


#if __has_embed("event_pic_thumb_7266.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_thumb_7266 = std::to_array<std::uint8_t>({
    #embed "event_pic_thumb_7266.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_thumb_7266;
#endif


#if __has_embed("event_pic_tiny_thumb_7266.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_tiny_thumb_7266 = std::to_array<std::uint8_t>({
    #embed "event_pic_tiny_thumb_7266.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_tiny_thumb_7266;
#endif

constexpr release_event_picture event_picture_7266 = { "image/jpeg", std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/7266.jpg?v=6)XYX"sv, event_pic_orig_7266, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/7266.jpg?v=6)XYX"sv, event_pic_small_thumb_7266, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/7266.jpg?v=6)XYX"sv, event_pic_thumb_7266, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/7266.jpg?v=6)XYX"sv, event_pic_tiny_thumb_7266  };

/* Miku Expo 2024 Auckland */
constexpr std::array<additional_name, 1> names_7765 {{
  {"English"sv, R"XYX(Miku Expo 2024 Auckland)XYX"sv},
}};

/* Miku Expo 2024 Auckland */
constexpr std::array<web_link, 1> web_links_7765 {{
  {"Other"sv, "Official Webpage"sv, "https://mikuexpo.com/nzaus2024/"sv, 9713 },
}};

/* Miku Expo 2024 Auckland */

#if __has_embed("event_pic_orig_7765.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_orig_7765 = std::to_array<std::uint8_t>({
    #embed "event_pic_orig_7765.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_orig_7765;
#endif


#if __has_embed("event_pic_small_thumb_7765.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_small_thumb_7765 = std::to_array<std::uint8_t>({
    #embed "event_pic_small_thumb_7765.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_small_thumb_7765;
#endif


#if __has_embed("event_pic_thumb_7765.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_thumb_7765 = std::to_array<std::uint8_t>({
    #embed "event_pic_thumb_7765.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_thumb_7765;
#endif


#if __has_embed("event_pic_tiny_thumb_7765.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_tiny_thumb_7765 = std::to_array<std::uint8_t>({
    #embed "event_pic_tiny_thumb_7765.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_tiny_thumb_7765;
#endif

constexpr release_event_picture event_picture_7765 = { "image/jpeg", std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/7765.jpg?v=3)XYX"sv, event_pic_orig_7765, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/7765.jpg?v=3)XYX"sv, event_pic_small_thumb_7765, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/7765.jpg?v=3)XYX"sv, event_pic_thumb_7765, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/7765.jpg?v=3)XYX"sv, event_pic_tiny_thumb_7765  };

/* HATSUNE MIKU JAPAN TOUR 2025 〜BLOOMING〜 OSAKA */
constexpr std::array<additional_name, 2> names_8380 {{
  {"Japanese"sv, R"XYX(初音ミク JAPAN TOUR 2025 〜BLOOMING〜 大阪)XYX"sv},
  {"English"sv, R"XYX(HATSUNE MIKU JAPAN TOUR 2025 〜BLOOMING〜 OSAKA)XYX"sv},
}};

/* HATSUNE MIKU JAPAN TOUR 2025 〜BLOOMING〜 OSAKA */
constexpr std::array<web_link, 0> web_links_8380 {{
}};

/* HATSUNE MIKU JAPAN TOUR 2025 〜BLOOMING〜 OSAKA */

#if __has_embed("event_pic_orig_8380.png") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_orig_8380 = std::to_array<std::uint8_t>({
    #embed "event_pic_orig_8380.png"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_orig_8380;
#endif


#if __has_embed("event_pic_small_thumb_8380.png") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_small_thumb_8380 = std::to_array<std::uint8_t>({
    #embed "event_pic_small_thumb_8380.png"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_small_thumb_8380;
#endif


#if __has_embed("event_pic_thumb_8380.png") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_thumb_8380 = std::to_array<std::uint8_t>({
    #embed "event_pic_thumb_8380.png"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_thumb_8380;
#endif


#if __has_embed("event_pic_tiny_thumb_8380.png") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_tiny_thumb_8380 = std::to_array<std::uint8_t>({
    #embed "event_pic_tiny_thumb_8380.png"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_tiny_thumb_8380;
#endif

constexpr release_event_picture event_picture_8380 = { "image/png", std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/8380.png?v=5)XYX"sv, event_pic_orig_8380, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/8380.png?v=5)XYX"sv, event_pic_small_thumb_8380, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/8380.png?v=5)XYX"sv, event_pic_thumb_8380, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/8380.png?v=5)XYX"sv, event_pic_tiny_thumb_8380  };

/* Hatsune Miku "Magical Mirai 2025" in SENDAI */
constexpr std::array<additional_name, 2> names_8768 {{
  {"Japanese"sv, R"XYX(初音ミク「マジカルミライ 2025」in SENDAI)XYX"sv},
  {"English"sv, R"XYX(Hatsune Miku "Magical Mirai 2025" in SENDAI)XYX"sv},
}};

/* Hatsune Miku "Magical Mirai 2025" in SENDAI */
constexpr std::array<web_link, 1> web_links_8768 {{
  {"Other"sv, "Website"sv, "https://magicalmirai.com/2025/"sv, 11366 },
}};

/* Hatsune Miku "Magical Mirai 2025" in SENDAI */

#if __has_embed("event_pic_orig_8768.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_orig_8768 = std::to_array<std::uint8_t>({
    #embed "event_pic_orig_8768.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_orig_8768;
#endif


#if __has_embed("event_pic_small_thumb_8768.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_small_thumb_8768 = std::to_array<std::uint8_t>({
    #embed "event_pic_small_thumb_8768.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_small_thumb_8768;
#endif


#if __has_embed("event_pic_thumb_8768.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_thumb_8768 = std::to_array<std::uint8_t>({
    #embed "event_pic_thumb_8768.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_thumb_8768;
#endif


#if __has_embed("event_pic_tiny_thumb_8768.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_tiny_thumb_8768 = std::to_array<std::uint8_t>({
    #embed "event_pic_tiny_thumb_8768.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_tiny_thumb_8768;
#endif

constexpr release_event_picture event_picture_8768 = { "image/jpeg", std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/8768.jpg?v=9)XYX"sv, event_pic_orig_8768, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/8768.jpg?v=9)XYX"sv, event_pic_small_thumb_8768, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/8768.jpg?v=9)XYX"sv, event_pic_thumb_8768, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/8768.jpg?v=9)XYX"sv, event_pic_tiny_thumb_8768  };

/* Miku Expo 2025 Bangkok */
constexpr std::array<additional_name, 1> names_9341 {{
  {"English"sv, R"XYX(Miku Expo 2025 Bangkok)XYX"sv},
}};

/* Miku Expo 2025 Bangkok */
constexpr std::array<web_link, 1> web_links_9341 {{
  {"Other"sv, "Website"sv, "https://mikuexpo.com/asia2025/"sv, 12284 },
}};

/* Miku Expo 2025 Bangkok */

#if __has_embed("event_pic_orig_9341.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_orig_9341 = std::to_array<std::uint8_t>({
    #embed "event_pic_orig_9341.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_orig_9341;
#endif


#if __has_embed("event_pic_small_thumb_9341.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_small_thumb_9341 = std::to_array<std::uint8_t>({
    #embed "event_pic_small_thumb_9341.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_small_thumb_9341;
#endif

constexpr std::array<std::uint8_t, 0> event_pic_thumb_9341;


#if __has_embed("event_pic_tiny_thumb_9341.jpeg") == __STDC_EMBED_FOUND__
constexpr std::array event_pic_tiny_thumb_9341 = std::to_array<std::uint8_t>({
    #embed "event_pic_tiny_thumb_9341.jpeg"
});
#else
constexpr std::array<std::uint8_t, 0> event_pic_tiny_thumb_9341;
#endif

constexpr release_event_picture event_picture_9341 = { "image/jpeg", std::nullopt, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainOrig/9341.jpg?v=2)XYX"sv, event_pic_orig_9341, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainSmall/9341.jpg?v=2)XYX"sv, event_pic_small_thumb_9341, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainThumb/9341.jpg?v=2)XYX"sv, event_pic_thumb_9341, R"XYX(https://static.vocadb.net/img/ReleaseEvent/mainTiny/9341.jpg?v=2)XYX"sv, event_pic_tiny_thumb_9341  };

export constexpr std::array<release_event, 61> events {{
  {R"XYX(ミクFES'09（夏）, Miku FES'09 (Natsu))XYX"sv, "Concert"sv, 2009y/8/31, R"XYX(Hatsune Miku's 2nd anniversary festival.

**Concert Schedule**:

* **August 31st, 2009 (Mon.)**
OPEN 18:00 / START19:00 (JST))XYX"sv, std::nullopt, 2522, event_picture_2522, R"XYX(Miku FES'09 (Summer))XYX"sv, names_2522, std::nullopt, 0, std::nullopt, 219, R"(ミクFES'09（夏）)", "Approved"sv, R"XYX(miku-fes09-natsu)XYX"sv, R"XYX(新木場 StudioCoast)XYX"sv, web_links_2522 },
  {R"XYX(ミクの日感謝祭39's Giving Day)XYX"sv, "Concert"sv, 2010y/3/9, std::nullopt, std::nullopt, 2520, event_picture_2520, R"XYX(Miku no Hi Kanshasai 39's Giving Day)XYX"sv, names_2520, std::nullopt, 0, std::nullopt, 3952, R"(ミクの日感謝祭 39's Giving Day Project DIVA presents 初音ミク・ソロコンサート～こんばんは、初音ミクです。〜)", "Finished"sv, R"XYX(miku-no-hi-kanshasai-39s-givin)XYX"sv, R"XYX(Zepp Tokyo in Odaiba)XYX"sv, web_links_2520 },
  {R"XYX(初音ミクライブパーティー 2011 Tokyo, ミクパ 2011 Tokyo, MikuPa 2011 Tokyo)XYX"sv, "Concert"sv, 2011y/3/9, R"XYX(18:00 OPEN ／19:00 START／21:30 CLOSE 予定
___
Concert dates:

- March 9, 2011 (Tokyo)
- August 17, 2011 (Sapporo)
- November 11, 2011 (Singapore))XYX"sv, std::nullopt, 2523, event_picture_2523, R"XYX(Hatsune Miku Live Party 2011 Tokyo)XYX"sv, names_2523, 219, 2011, R"XYX(Tokyo)XYX"sv, 3953, R"(Hatsune Miku Live Party 2011 Mikupa♪ Tokyo)", "Finished"sv, R"XYX(hatsune-miku-live-party-2011-t)XYX"sv, R"XYX(Zepp Tokyo)XYX"sv, web_links_2523 },
  {R"XYX(MIKUNOPOLIS in LOS ANGELES “はじめまして、初音ミクです”, MIKUNOPOLIS in LOS ANGELES "Hajimemashite, Hatsune Miku Desu", MIKUNOPOLIS in LOS ANGELES “Happy to meet you! I'm HATSUNE MIKU”)XYX"sv, "Concert"sv, 2011y/7/2, std::nullopt, std::nullopt, 2521, event_picture_2521, R"XYX(MIKUNOPOLIS in LOS ANGELES “Happy to meet you, I'm HATSUNE MIKU”)XYX"sv, names_2521, std::nullopt, 0, std::nullopt, 84, R"(MIKUNOPOLIS in LOS ANGELES “Happy to meet you, I'm HATSUNE MIKU”)", "Finished"sv, R"XYX(mikunopolis-in-los-angeles-haj)XYX"sv, R"XYX(Nokia theater)XYX"sv, web_links_2521 },
  {R"XYX(初音ミクライブパーティー 2011 Sapporo, ミクパ 2011 Sapporo, MikuPa 2011 Sapporo)XYX"sv, "Unspecified"sv, 2011y/8/16, R"XYX(初日公演
8月16日(火)＝17:00 OPEN 18:00 START 20:00 CLOSE予定
二日目公演
8月17日(水)＝15:00 OPEN 16:00 START 18:00 CLOSE予定
___
Concert dates:

- March 9, 2011 (Tokyo)
- August 17, 2011 (Sapporo)
- November 11, 2011 (Singapore))XYX"sv, 2011y/8/17, 2526, event_picture_2526, R"XYX(Hatsune Miku Live Party 2011 Sapporo)XYX"sv, names_2526, 219, 2011, R"XYX(Sapporo)XYX"sv, 12, R"(Hatsune Miku Live Party 2011 Mikupa♪ Sapporo)", "Finished"sv, R"XYX(hatsune-miku-live-party-2011-s)XYX"sv, R"XYX(札幌市教育文化会館 大ホール)XYX"sv, web_links_2526 },
  {R"XYX(初音ミクライブパーティー 2011 Singapore, ミクパ 2011 Singapore, MikuPa 2011 Singapore)XYX"sv, "Unspecified"sv, 2011y/11/11, R"XYX(Fri, Nov 11, OPEN 18:00／START 19:00
___
Concert dates:

- March 9, 2011 (Tokyo)
- August 17, 2011 (Sapporo)
- November 11, 2011 (Singapore))XYX"sv, std::nullopt, 2527, event_picture_2527, R"XYX(Hatsune Miku Live Party 2011 Singapore)XYX"sv, names_2527, 219, 2011, R"XYX(Singapore)XYX"sv, 1, R"(Hatsune Miku Live Party 2011 Mikupa♪ Singapore)", "Finished"sv, R"XYX(hatsune-miku-live-party-2011-s)XYX"sv, R"XYX(Suntec Singapore Exhibition Hall 402)XYX"sv, web_links_2527 },
  {R"XYX(初音ミクライブパーティー 2012 Tokyo, ミクパ 2012 Tokyo, MikuPa 2012 Tokyo)XYX"sv, "Unspecified"sv, 2012y/3/8, R"XYX("Hatsune Miku Live Party 2012 (MikuPa)" was held at Tokyo Dome City Hall on March 8, 2012. It was accompanied by the "Miku no Hi Dai Kanshasai 39's Giving Day" concert on the 9th.
___
Concert dates:

- March 8, 2012 (Tokyo)
- October 2, 2012 (Hong Kong)
- October 6, 2012 (Taiwan))XYX"sv, std::nullopt, 4056, event_picture_4056, R"XYX(Hatsune Miku Live Party 2012 Tokyo)XYX"sv, names_4056, 219, 2012, R"XYX(Tokyo)XYX"sv, 217, R"(Hatsune Miku Live Party 2012 Mikupa♪ Tokyo)", "Finished"sv, R"XYX(hatsune-miku-live-party-2012-t)XYX"sv, std::nullopt, web_links_4056 },
  {R"XYX(ミクの日大感謝祭特番 - 制作日誌39 2012, Miku No Hi Daikanshasai Tokuban - Seisaku Nisshi 39 2012)XYX"sv, "Unspecified"sv, 2012y/3/9, R"XYX("Miku no Hi Dai Kanshasai 39's Giving Day" was held on March 9 and featured both the original -Project DIVA- Arcade graphics. It was accompaned by "Hatsune Miku Live Party 2012 (Mikupa)" the day before. The event took place at Tokyo Dome City Hall.)XYX"sv, std::nullopt, 1413, event_picture_1413, R"XYX(Miku's Big Thanksgiving Day - Special 39's Production 2012)XYX"sv, names_1413, 84, 2012, std::nullopt, 218, R"(Miku's Big Thanksgiving Day - Special 39's Production)", "Finished"sv, R"XYX(miku-no-hi-daikanshasai-tokuba)XYX"sv, R"XYX(Tokyo Dome City Hall)XYX"sv, web_links_1413 },
  {R"XYX(初音ミクライブパーティー 2012 Hong Kong, ミクパ 2012 Hong Kong, MikuPa 2012 Hong Kong)XYX"sv, "Unspecified"sv, 2012y/10/2, R"XYX(昼公演 14:00／15:00
夜公演 19:00／20:00
___
Concert dates:

- March 8, 2012 (Tokyo)
- October 2, 2012 (Hong Kong)
- October 6, 2012 (Taiwan))XYX"sv, std::nullopt, 2524, event_picture_2524, R"XYX(Hatsune Miku Live Party 2012 Hong Kong)XYX"sv, names_2524, 219, 2012, R"XYX(Hong Kong)XYX"sv, 31, R"(Hatsune Miku Live Party 2012 Mikupa♪ Hong Kong and Taiwan)", "Finished"sv, R"XYX(hatsune-miku-live-party-2012-h)XYX"sv, R"XYX(KITEC Star Hall)XYX"sv, web_links_2524 },
  {R"XYX(初音ミクライブパーティー 2013 Sapporo, ミクパ 2013 Sapporo, MikuPa 2013 Sapporo)XYX"sv, "Concert"sv, 2013y/2/9, R"XYX(2月9日（土）昼公演 13:00　夜公演 18:00
2月10日（日）昼公演 12:00　夜公演 17:00
___
Concert dates:

- February 9, 2013 (Sapporo)
- February 10, 2013 (Sapporo)
- March 9, 2013 (Kansai))XYX"sv, 2013y/2/10, 2510, event_picture_2510, R"XYX(Hatsune Miku Live Party 2013 Sapporo)XYX"sv, names_2510, 219, 2013, R"XYX(Sapporo)XYX"sv, 82, R"(Hatsune Miku Live Party 2013 Mikupa♪ Sapporo)", "Finished"sv, R"XYX(hatsune-miku-live-party-2013-s)XYX"sv, R"XYX(札幌市民ホール)XYX"sv, web_links_2510 },
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
- March 9, 2013 (Kansai))XYX"sv, std::nullopt, 2511, event_picture_2511, R"XYX(Hatsune Miku Live Party 2013 Kansai)XYX"sv, names_2511, 219, 2013, R"XYX(Kansai)XYX"sv, 3954, R"(Hatsune Miku Live Party 2013 Mikupa♪ Kansai)", "Finished"sv, R"XYX(hatsune-miku-live-party-2013-k)XYX"sv, R"XYX(和歌山ビッグホエール)XYX"sv, web_links_2511 },
  {R"XYX(初音ミク「マジカルミライ 2013」, マジカルミライ 2013, Magical Mirai 2013)XYX"sv, "Unspecified"sv, 2013y/8/30, R"XYX(Daytime : OPEN 12:30 / Showtime 13:30 / Curtain 15:00
Night : OPEN 17:30 / Showtime 19:30)XYX"sv, std::nullopt, 2519, event_picture_2519, R"XYX(Hatsune Miku Magical Mirai 2013)XYX"sv, names_2519, 81, 2013, std::nullopt, 114, R"(Hatsune Miku Magical Mirai 2013)", "Finished"sv, R"XYX(hatsune-miku-magical-mirai-201)XYX"sv, R"XYX(横浜アリーナ)XYX"sv, web_links_2519 },
  {R"XYX(HATSUNE MIKU EXPO 2014 IN INDONESIA)XYX"sv, "Unspecified"sv, 2014y/5/28, R"XYX(May 28th
The 1st show :Open : 18:30 -Start : 19:30 -
May 29th
The 2nd show :Open : 12:00 -Start : 13:00 -
The 3rd show :Open : 18:30 -Start : 19:30 -)XYX"sv, 2014y/5/29, 1939, event_picture_1939, R"XYX(Miku Expo 2014 Jakarta)XYX"sv, names_1939, 82, 2014, R"XYX(Jakarta)XYX"sv, 213, R"(Miku Expo 2014 Indonesia)", "Finished"sv, R"XYX(miku-expo-2014-jakarta)XYX"sv, std::nullopt, web_links_1939 },
  {R"XYX(初音ミク「マジカルミライ 2014」in OSAKA, マジカルミライ 2014 Osaka, Magical Mirai 2014 Osaka)XYX"sv, "Unspecified"sv, 2014y/8/30, R"XYX(**Live Show**:
INTEX Osaka Hall 5
August 30th(Sat.)

* 1st Show (Evening): OPEN 11:30 / START 12:30
* 2nd Show (Noon): OPEN 16:00 / START 17:00

**Exhibition**:
INTEX Osaka Hall 4
August 30th(Sat.)

Art by [MONQ](https://vocadb.net/Ar/2200))XYX"sv, std::nullopt, 2517, event_picture_2517, R"XYX(Hatsune Miku Magical Mirai 2014 in OSAKA)XYX"sv, names_2517, 81, 2014, R"XYX(Osaka)XYX"sv, 214, R"(Hatsune Miku Magical Mirai 2014)", "Approved"sv, R"XYX(hatsune-miku-magical-mirai-201)XYX"sv, R"XYX(インテックス大阪)XYX"sv, web_links_2517 },
  {R"XYX()XYX"sv, "Unspecified"sv, 2014y/10/11, R"XYX(1st Show Oct. 11, 2014
START : 7:00pm (DOORS OPEN : 6:00pm)

2nd Show Oct. 12, 2014
START : 12:30pm (DOORS OPEN : 11:30am))XYX"sv, 2014y/10/12, 1937, event_picture_1937, R"XYX(Miku Expo 2014 Los Angeles)XYX"sv, names_1937, 82, 2014, R"XYX(Los Angeles)XYX"sv, 221, R"(Miku Expo 2014 USA)", "Draft"sv, R"XYX(miku-expo-2014-los-angeles)XYX"sv, R"XYX(Nokia Theatre)XYX"sv, web_links_1937 },
  {R"XYX()XYX"sv, "Unspecified"sv, 2015y/2/7, R"XYX(**Concert Schedule**:

**February 7th(Sat.)**
Daytime: OPEN: 12:00／START: 13:00
Nighttime: OPEN: 18:00／START: 19:00

**February 8th(Sun.)**
Daytime: OPEN: 12:00／START: 13:00
Nighttime: OPEN: 17:00／START: 18:00

Art by [iXima](https://vocadb.net/Ar/2230))XYX"sv, 2015y/2/8, 3792, event_picture_3792, R"XYX(SNOW MIKU LIVE! 2015 presents MIKU EXPO Live Set)XYX"sv, names_3792, 204, 2015, R"XYX(presents MIKU EXPO Live Set)XYX"sv, 3951, R"(SNOW MIKU LIVE! 2015 presents MIKU EXPO Live Set)", "Finished"sv, R"XYX(snow-miku-live-2015-presents-m)XYX"sv, R"XYX(Zepp Sapporo（北海道）)XYX"sv, web_links_3792 },
  {R"XYX()XYX"sv, "Unspecified"sv, 2015y/6/27, R"XYX(2015-06-27
day show : 9:30 12:00, night show 16:30 18:00
2015-06-28
day show : 9:30 12:00, night show 16:30 18:00)XYX"sv, 2015y/6/28, 1940, event_picture_1940, R"XYX(Miku Expo 2015 Shanghai)XYX"sv, names_1940, 82, 2015, R"XYX(Shanghai)XYX"sv, 2868, R"(Miku Expo 2015 China)", "Draft"sv, R"XYX(miku-expo-2015-shanghai)XYX"sv, R"XYX(E-Sports Arena)XYX"sv, web_links_1940 },
  {R"XYX(初音ミク「マジカルミライ 2015」, マジカルミライ 2015, Magical Mirai 2015)XYX"sv, "Unspecified"sv, 2015y/9/4, R"XYX(**Live Show**:
Nippon Budokan
September 4th(Fri.) - 5th(Sat.)

* 1st and 3rd show (Noon): OPEN 17:30 / START 18:30
* 2nd show (Evening): OPEN 11:00 / START 12:30

**Exhibition**:
Science Museum
September 4th(Fri.) - 6th(Sun.)

Art by [穂嶋](https://vocadb.net/Ar/11782))XYX"sv, 2015y/9/6, 2514, event_picture_2514, R"XYX(Hatsune Miku Magical Mirai 2015)XYX"sv, names_2514, 81, 2015, std::nullopt, 3985, R"(Hatsune Miku Magical Mirai 2015)", "Approved"sv, R"XYX(hatsune-miku-magical-mirai-201)XYX"sv, R"XYX(日本武道館)XYX"sv, web_links_2514 },
  {R"XYX()XYX"sv, "Unspecified"sv, 2016y/3/23, R"XYX(2016.3.23
Night Show
18:00 / 19:00

2016.3.24
Night Show
18:00 / 19:00
)XYX"sv, 2016y/3/24, 1399, event_picture_1399, R"XYX(Miku Expo 2016 Fukuoka)XYX"sv, names_1399, 82, 2016, R"XYX(Fukuoka)XYX"sv, 6570, R"(Miku Expo 2016 Japan)", "Finished"sv, R"XYX(miku-expo-2016-fukuoka)XYX"sv, R"XYX(Zepp Fukuoka)XYX"sv, web_links_1399 },
  {R"XYX()XYX"sv, "Unspecified"sv, 2016y/4/23, std::nullopt, std::nullopt, 1859, event_picture_1859, R"XYX(Miku Expo 2016 Seattle)XYX"sv, names_1859, 82, 2016, R"XYX(Seattle)XYX"sv, 6571, R"(Miku Expo 2016 North America)", "Finished"sv, R"XYX(miku-expo-2016-seattle)XYX"sv, R"XYX(Seattle, Washington: WaMu Theater)XYX"sv, web_links_1859 },
  {R"XYX()XYX"sv, "Unspecified"sv, 2016y/6/25, std::nullopt, 2016y/6/26, 1941, event_picture_1941, R"XYX(Miku Expo 2016 New Taipei City)XYX"sv, names_1941, 82, 2016, R"XYX(New Taipei City)XYX"sv, 6572, R"(Miku Expo 2016 Taiwan)", "Finished"sv, R"XYX(miku-expo-2016-new-taipei-city)XYX"sv, R"XYX(New Taipei City Exhibition Hall)XYX"sv, web_links_1941 },
  {R"XYX(初音ミク「マジカルミライ 2016」, マジカルミライ 2016, Magical Mirai 2016)XYX"sv, "Unspecified"sv, 2016y/9/9, R"XYX(**Live Show**:
Makuhari Messe International Exhibition Hall 9
September 10th(Sat.) - 11th(Sun.)

**Exhibition**:
Makuhari Messe International Exhibition Hall 10 & 11
September 9th(Fri.) - 11th(Sun.)

Art by [LENA[A-7]](https://vocadb.net/Ar/83909))XYX"sv, 2016y/9/11, 1398, event_picture_1398, R"XYX(Hatsune Miku Magical Mirai 2016)XYX"sv, names_1398, 81, 2016, std::nullopt, 6652, R"(Hatsune Miku Magical Mirai 2016)", "Approved"sv, R"XYX(hatsune-miku-magical-mirai-201)XYX"sv, R"XYX(幕張メッセ国際展示場 / Makuhari Messe International Exhibition Hall)XYX"sv, web_links_1398 },
  {R"XYX()XYX"sv, "Unspecified"sv, 2016y/12/3, std::nullopt, 2016y/12/4, 1943, event_picture_1943, R"XYX(Miku Expo 2016 Shanghai)XYX"sv, names_1943, 82, 2016, R"XYX(Shanghai)XYX"sv, 6950, R"(Miku Expo 2016 China)", "Draft"sv, R"XYX(miku-expo-2016-shanghai)XYX"sv, R"XYX(Shanghai Happy Valley)XYX"sv, web_links_1943 },
  {R"XYX(初音ミク×鼓童スペシャルライブ, 初音ミク×鼓童　スペシャルライブ | Ｔｈｉｓ　ｉｓ　ＮＩＰＰＯＮ　プレミアムシアター, Hatsune Miku × Kodō Special Live | This is NIPPON Premium Theater)XYX"sv, "Unspecified"sv, 2017y/3/4, std::nullopt, 2017y/3/5, 2947, event_picture_2947, R"XYX(Hatsune Miku × Kodō Special Live)XYX"sv, names_2947, 255, 0, std::nullopt, 7024, R"(Hatsune Miku × Kodō Special Live)", "Finished"sv, R"XYX(hatsune-miku--kod-special-live)XYX"sv, R"XYX(NHK Hall (Shibuya, Tokyo))XYX"sv, web_links_2947 },
  {R"XYX(初音ミク「マジカルミライ 2017」, マジカルミライ 2017, Magical Mirai 2017)XYX"sv, "Unspecified"sv, 2017y/9/1, R"XYX(**Live Show**:
Makuhari Messe International Exhibition Hall 3
September 1st(Fri.) - 3rd(Sun.)

* September 2nd and 3rd had two shows each, noon and evening.

**Exhibition**:
Makuhari Messe International Exhibition Hall 1, 2
September 1st(Fri.) - 3rd(Sun.)

* Tickets were available by applying to a lottery or purchasing accommodation plan. Accommodation plans were sold first-come, first-served -basis. There were separate lottery and accommodation plans for Japanese attendees and foreigners.

Art by [iXima](https://vocadb.net/Ar/2230))XYX"sv, 2017y/9/3, 1397, event_picture_1397, R"XYX(Hatsune Miku Magical Mirai 2017)XYX"sv, names_1397, 81, 2017, std::nullopt, 6915, R"(Hatsune Miku Magical Mirai 2017)", "Approved"sv, R"XYX(hatsune-miku-magical-mirai-201)XYX"sv, R"XYX(Makuhari Messe)XYX"sv, web_links_1397 },
  {R"XYX(未来有你·初音未来 2017 上海演唱会, 未来（ミク）には君がいる·初音ミク２０１７上海ライブ)XYX"sv, "Concert"sv, 2017y/11/25, std::nullopt, std::nullopt, 1619, event_picture_1619, R"XYX(HATSUNE MIKU with YOU 2017 CHINA FESTIVAL)XYX"sv, names_1619, 173, 2017, R"XYX(in Shanghai)XYX"sv, 7384, R"(HATSUNE MIKU with YOU 2017 CHINA FESTIVAL)", "Finished"sv, R"XYX(hatsune-miku-with-you-2017-chi)XYX"sv, R"XYX(上海新国际博览中心E5馆)XYX"sv, web_links_1619 },
  {R"XYX()XYX"sv, "Unspecified"sv, 2017y/12/16, R"XYX(Door: 6PM Show: 8PM)XYX"sv, std::nullopt, 1584, event_picture_1584, R"XYX(Miku Expo 2017 Kuala Lumpur)XYX"sv, names_1584, 82, 2017, R"XYX(Kuala Lumpur)XYX"sv, 7404, R"(Miku Expo 2017 Malaysia)", "Draft"sv, R"XYX(miku-expo-2017-kuala-lumpur)XYX"sv, R"XYX(Kuala Lumpur Axiata Arena(Bukit Jalil))XYX"sv, web_links_1584 },
  {R"XYX()XYX"sv, "Concert"sv, 2018y/2/9, R"XYX(**Concert Schedule**:

**February 9th(Fri.)**
Daytime: OPEN: 13:00 / START: 14:00
Nighttime: OPEN: 18:00 / START: 19:00

**February 10th(Sat.)**
Daytime: OPEN: 13:00 / START: 14:00
Nighttime: OPEN: 17:00 / START: 18:00

Art by [やすも](https://vocadb.net/Ar/63429))XYX"sv, 2018y/2/10, 1618, event_picture_1618, R"XYX(SNOW MIKU LIVE! 2018)XYX"sv, names_1618, 204, 2018, std::nullopt, 7339, R"(SNOW MIKU LIVE! 2018)", "Finished"sv, R"XYX(snow-miku-live-2018)XYX"sv, R"XYX(Zepp Sapporo（北海道）)XYX"sv, web_links_1618 },
  {R"XYX(Ｔｈｉｓ　ｉｓ　ＮＩＰＰＯＮ　プレミアムシアター 初音ミク×鼓童　スペシャルライブ　２０１８)XYX"sv, "Unspecified"sv, 2018y/6/2, R"XYX(■ Date and time:
・June 2, 2018 (Saturday)
 Open 12:00 / Start 13:00
 Open 18:00 / Start 19:00
・June 3, 2018 (Sunday)
 Open 12:00 / Start 13:00

* All times JST)XYX"sv, 2018y/6/3, 2948, event_picture_2948, R"XYX(This is NIPPON Premium Theater Hatsune Miku × Kodō Special Live 2018)XYX"sv, names_2948, 255, 0, std::nullopt, 8961, R"(Hatsune Miku × Kodō Special Live 2018)", "Finished"sv, R"XYX(this-is-nippon-premium-theater)XYX"sv, R"XYX(NHK Hall (Shibuya, Tokyo))XYX"sv, web_links_2948 },
  {R"XYX()XYX"sv, "Unspecified"sv, 2018y/6/29, std::nullopt, std::nullopt, 1673, event_picture_1673, R"XYX(Miku Expo 2018 Los Angeles)XYX"sv, names_1673, 82, 2018, R"XYX(Los Angeles)XYX"sv, 7758, R"(Miku Expo 2018 North America)", "Finished"sv, R"XYX(miku-expo-2018-los-angeles)XYX"sv, R"XYX(Microsoft Theater)XYX"sv, web_links_1673 },
  {R"XYX(初音ミク「マジカルミライ 2018」in OSAKA, マジカルミライ 2018 Osaka, Magical Mirai 2018 Osaka)XYX"sv, "Unspecified"sv, 2018y/8/25, R"XYX(**Live Show**:
INTEX Osaka A ZONE, Hall 5
August 25th(Sat.) - 26th(Sun.)

**Exhibition**:
INTEX Osaka Hall 4
August 25th(Sat.) - 26th(Sun.)

Art by [Mika Pikazo](https://vocadb.net/Ar/32604))XYX"sv, 2018y/8/26, 1561, event_picture_1561, R"XYX(Hatsune Miku Magical Mirai 2018 in OSAKA)XYX"sv, names_1561, 81, 2018, R"XYX(Osaka)XYX"sv, 7852, R"(Hatsune Miku Magical Mirai 2018)", "Approved"sv, R"XYX(hatsune-miku-magical-mirai-201)XYX"sv, R"XYX(INTEX Osaka, Osaka, Japan)XYX"sv, web_links_1561 },
  {R"XYX(未来有你 2018 in Beijing, HATSUNE MIKU WITH YOU 2018 in Beijing)XYX"sv, "Unspecified"sv, 2018y/10/13, R"XYX(Art by Nekosakana

Main visual (Website) by YYB)XYX"sv, std::nullopt, 2085, event_picture_2085, R"XYX(MIKU WITH YOU 2018 in Beijing)XYX"sv, names_2085, 173, 2018, R"XYX(in Beijing)XYX"sv, 7986, R"(MIKU WITH YOU 2018)", "Finished"sv, R"XYX(miku-with-you-2018-in-beijing)XYX"sv, R"XYX(五棵松M空间 (M Space))XYX"sv, web_links_2085 },
  {R"XYX()XYX"sv, "Unspecified"sv, 2018y/12/1, R"XYX(Samedi 1 décembre 2018 - 20h30
48° 49′ 26″ N, 2° 14′ 00″ E)XYX"sv, std::nullopt, 1854, event_picture_1854, R"XYX(Miku Expo 2018 Paris)XYX"sv, names_1854, 82, 2018, R"XYX(Paris)XYX"sv, 7979, R"(Miku Expo 2018 Paris)", "Finished"sv, R"XYX(miku-expo-2018-paris)XYX"sv, R"XYX(La Seine Musicale, Île Seguin, 92100 Boulogne-Billancourt)XYX"sv, web_links_1854 },
  {R"XYX()XYX"sv, "Unspecified"sv, 2019y/2/9, R"XYX(**Concert Schedule**:

**February 9th(Sat.)**
Daytime: OPEN: 13:00 / START: 14:00
Nighttime: OPEN: 18:00 / START: 19:00

**February 10th(Sun.)**
Daytime: OPEN: 13:00 / START: 14:00
Nighttime: OPEN: 17:00 / START: 18:00

Art by [KEI](https://vocadb.net/Ar/9213))XYX"sv, 2019y/2/10, 2422, event_picture_2422, R"XYX(SNOW MIKU LIVE! 2019)XYX"sv, names_2422, 204, 2019, std::nullopt, 8099, R"(SNOW MIKU LIVE! 2019 )", "Finished"sv, R"XYX(snow-miku-live-2019)XYX"sv, R"XYX(Zepp Sapporo（北海道）)XYX"sv, web_links_2422 },
  {R"XYX()XYX"sv, "Unspecified"sv, 2019y/5/11, std::nullopt, std::nullopt, 2489, event_picture_2489, R"XYX(Miku Expo 2019 New Taipei City)XYX"sv, names_2489, 82, 2019, R"XYX(New Taipei City)XYX"sv, 8103, R"(Miku Expo 2019 New Taipei City)", "Finished"sv, R"XYX(miku-expo-2019-new-taipei-city)XYX"sv, R"XYX(New Taipei City Exhibition Hall)XYX"sv, web_links_2489 },
  {R"XYX(初音ミク「マジカルミライ 2019」in OSAKA, マジカルミライ 2019 Osaka, Magical Mirai 2019 Osaka)XYX"sv, "Unspecified"sv, 2019y/8/9, R"XYX(Magical Mirai 2019's theme is "Future Circus"

**Live Show**:
INTEX Osaka Hall 5A
August 10th(Sat.) - 11th(Sun.)

**Exhibition**:
INTEX Osaka Hall 4,5B
August 9th(Fri.) - 11th(Sun.)

Art by [ni02](https://vocadb.net/Ar/74337))XYX"sv, 2019y/8/11, 2515, event_picture_2515, R"XYX(Hatsune Miku Magical Mirai 2019 in OSAKA)XYX"sv, names_2515, 81, 2019, R"XYX(Osaka)XYX"sv, 8102, R"(Hatsune Miku Magical Mirai 2019 in OSAKA)", "Approved"sv, R"XYX(hatsune-miku-magical-mirai-201)XYX"sv, R"XYX(インテックス大阪)XYX"sv, web_links_2515 },
  {R"XYX(未来有你 2019 in Shanghai, HATSUNE MIKU WITH YOU 2019 in Shanghai)XYX"sv, "Unspecified"sv, 2019y/11/2, std::nullopt, 2019y/11/3, 3752, event_picture_3752, R"XYX(MIKU WITH YOU 2019 in Shanghai)XYX"sv, names_3752, 173, 2019, R"XYX(in Shanghai)XYX"sv, 9359, R"(MIKU WITH YOU 2019)", "Finished"sv, R"XYX(miku-with-you-2019-in-shanghai)XYX"sv, R"XYX(1862 Theater)XYX"sv, web_links_3752 },
  {R"XYX()XYX"sv, "Unspecified"sv, 2020y/1/11, R"XYX(17:00 to 22:00)XYX"sv, std::nullopt, 2786, event_picture_2786, R"XYX(Miku Expo 2020 London)XYX"sv, names_2786, 82, 2020, std::nullopt, 8631, R"(Miku Expo 2020 London/Berlin)", "Draft"sv, R"XYX(miku-expo-2020-london)XYX"sv, R"XYX(O2 Academy Brixton)XYX"sv, web_links_2786 },
  {R"XYX(ニコニコネット超会議2020夏✕HATSUNE MIKU LIVE - UNTITLED 0 -)XYX"sv, "Concert"sv, 2020y/8/9, R"XYX(A live performance at the opening of the Nico Nico Net Chokaigi 2020 Summer event.

Date & Starting time: August 9th, 2020, 7pm JST
Time Shift Deadline: September 8th, 2020, 11:59pm JST
Net Ticket: [Purchase link](https://secure.live.nicovideo.jp/event/lv327105822)
Price: 4,800 Nico Nico Points (4,800 yen including tax)
Purchase Deadline: September 7th, 2020, 11:59pm JST)XYX"sv, std::nullopt, 2939, event_picture_2939, R"XYX(Nico Nico Net Chokaigi 2020 Natsu ✕ HATSUNE MIKU LIVE - UNTITLED 0 -)XYX"sv, names_2939, std::nullopt, 0, std::nullopt, 8940, R"(HATSUNE MIKU LIVE - UNTITLED 0 - )", "Finished"sv, R"XYX(nico-nico-net-chokaigi-2020-na)XYX"sv, std::nullopt, web_links_2939 },
  {R"XYX(初音ミク「マジカルミライ 2020」in OSAKA, マジカルミライ 2020 Osaka, Magical Mirai 2020 Osaka)XYX"sv, "Unspecified"sv, 2020y/11/27, R"XYX(Magical Mirai 2020’s theme is “MATSURI”.

**Live Show**:
INTEX Osaka Hall 5A
November 28th(Sat.) - 29th(Sun.)

**Exhibition**:
INTEX Osaka Hall 3, 4
November 27th(Fri.) - 29th(Sun.)

The concert was also streamed online on November 29th(Sun.).

Art by [藤ちょこ](https://vocadb.net/Ar/9328))XYX"sv, 2020y/11/29, 2758, event_picture_2758, R"XYX(Hatsune Miku Magical Mirai 2020 in OSAKA)XYX"sv, names_2758, 81, 2020, R"XYX(Osaka)XYX"sv, 9131, R"(Hatsune Miku Magical Mirai 2020 in OSAKA)", "Approved"sv, R"XYX(hatsune-miku-magical-mirai-202)XYX"sv, R"XYX(INTEX Osaka Hall 4,5A)XYX"sv, web_links_2758 },
  {R"XYX(未来有你 2020, HATSUNE MIKU WITH YOU 2020)XYX"sv, "Unspecified"sv, 2020y/12/25, std::nullopt, std::nullopt, 3250, event_picture_3250, R"XYX(MIKU WITH YOU 2020)XYX"sv, names_3250, 173, 2020, std::nullopt, 9192, R"(MIKU WITH YOU 2020)", "Finished"sv, R"XYX(miku-with-you-2020)XYX"sv, std::nullopt, web_links_3250 },
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

Art by ryota)XYX"sv, std::nullopt, 3224, event_picture_3224, R"XYX(Miku Expo 2021 Online)XYX"sv, names_3224, 82, 2021, std::nullopt, 9596, R"(HATSUNE MIKU EXPO 2021 Online)", "Approved"sv, R"XYX(miku-expo-2021-online)XYX"sv, R"XYX(YouTube Live / Twitch)XYX"sv, web_links_3224 },
  {R"XYX(初音ミク「マジカルミライ 2021」in OSAKA)XYX"sv, "Unspecified"sv, 2021y/10/22, R"XYX(Magical Mirai 2021’s theme is “Fairy Tale Fantasy”.

**Live Show**:
INTEX Osaka Hall 5A
October 22nd(Fri.) - 24th(Sun.)

**Exhibition**:
INTEX Osaka Hall 4
October 22nd(Fri.) - 24th(Sun.)

Art by [左](https://vocadb.net/Ar/3104))XYX"sv, 2021y/10/24, 3305, event_picture_3305, R"XYX(Hatsune Miku "Magical Mirai 2021" in OSAKA)XYX"sv, names_3305, 81, 2021, std::nullopt, 9909, R"(Hatsune Miku Magical Mirai 2021)", "Approved"sv, R"XYX(hatsune-miku-magical-mirai-202)XYX"sv, std::nullopt, web_links_3305 },
  {R"XYX(未来有你 2021, HATSUNE MIKU WITH YOU 2021)XYX"sv, "Unspecified"sv, 2021y/12/25, R"XYX(Art by Liita)XYX"sv, std::nullopt, 4058, event_picture_4058, R"XYX(MIKU WITH YOU 2021)XYX"sv, names_4058, 173, 2021, std::nullopt, 10011, R"(MIKU WITH YOU 2021)", "Finished"sv, R"XYX(miku-with-you-2021)XYX"sv, std::nullopt, web_links_4058 },
  {R"XYX(鏡音リン・レン Happy 14th Birthday Party「Two You☆★」)XYX"sv, "Concert"sv, 2022y/7/7, R"XYX(Kagamine Rin and Len first solo live concert.

**Concert Schedule**:

* **DAY1 July 7th(Thu.)**
Daytime: RIN PARTY (OPEN 13:00 / START 14:00)
Nighttime: RIN&LEN PARTY (OPEN 18:00 / START 19:00)

* **DAY2 July 8th(Fri.)**
Daytime: LEN PARTY (OPEN 13:00 / START 14:00)
Nighttime: RIN&LEN PARTY (OPEN 18:00 / START 19:00)

* All times JST

Art by [たま](https://vocadb.net/Ar/1724))XYX"sv, 2022y/7/8, 4161, event_picture_4161, R"XYX(Kagamine Rin・Len Happy 14th Birthday Party "Two You☆★")XYX"sv, names_4161, std::nullopt, 0, std::nullopt, 10469, R"(Kagamine Rin・Len Happy 14th Birthday Party "Two You☆★")", "Finished"sv, R"XYX(kagamine-rinlen-happy-14th-bir)XYX"sv, std::nullopt, web_links_4161 },
  {R"XYX(初音ミク「マジカルミライ」10th Anniversary in OSAKA, 初音ミク「マジカルミライ 2022」in OSAKA)XYX"sv, "Unspecified"sv, 2022y/8/12, R"XYX(Magical Mirai 10th anniversary theme is "retro-future".

**Live Show**:
INTEX Osaka Hall 5A
August 12th(Fri.) - 14th(Sun.)

**Exhibition**:
INTEX Osaka Hall 4
August 12th(Fri.) - 14th(Sun.)

Art by [KEI](https://vocadb.net/Ar/9213))XYX"sv, 2022y/8/14, 4233, event_picture_4233, R"XYX(Hatsune Miku "Magical Mirai" 10th Anniversary in OSAKA)XYX"sv, names_4233, 81, 2022, std::nullopt, 10556, R"(Hatsune Miku "Magical Mirai" 10th Anniversary (OSAKA & TOKYO))", "Approved"sv, R"XYX(hatsune-miku-magical-mirai-10t)XYX"sv, std::nullopt, web_links_4233 },
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

Art by [KEI](https://vocadb.net/Ar/9213))XYX"sv, 2023y/2/5, 4235, event_picture_4235, R"XYX(Hatsune Miku "Magical Mirai" 10th Anniversary in SAPPORO)XYX"sv, names_4235, 81, 2023, std::nullopt, 12354, R"(Hatsune Miku "Magical Mirai" 10th Anniversary (SAPPORO))", "Finished"sv, R"XYX(hatsune-miku-magical-mirai-10t)XYX"sv, std::nullopt, web_links_4235 },
  {R"XYX(初音ミク JAPAN TOUR 2023 〜THUNDERBOLT〜 名古屋)XYX"sv, "Unspecified"sv, 2023y/2/23, R"XYX(**Concert Schedule**:

* **February 23rd, 2023 (Thu.)**
1st Show: OPEN 12:00 / START 13:00
2nd Show: OPEN 17:00 / START 18:00

* All times JST)XYX"sv, std::nullopt, 4765, event_picture_4765, R"XYX(HATSUNE MIKU JAPAN TOUR 2023 〜THUNDERBOLT〜 NAGOYA)XYX"sv, names_4765, 408, 1, std::nullopt, 12457, R"(初音ミク JAPAN TOUR 2023 〜THUNDERBOLT〜)", "Finished"sv, R"XYX(hatsune-miku-japan-tour-2023-t)XYX"sv, R"XYX(Zepp Nagoya)XYX"sv, web_links_4765 },
  {R"XYX(初音ミク×鼓童スペシャルライブ２０２３ ～結～)XYX"sv, "Unspecified"sv, 2023y/6/3, R"XYX(Hatsune Miku x Kodo last live performance.

**Concert Schedule**

* **June 3rd, 2023 (Sat.)**
1st Show: OPEN 12:00 / START 13:00
2nd Show: OPEN 18:00 / START 19:00 

* **June 4th, 2023 (Sun.)**
OPEN 12:00 / START 13:00

* All times JST)XYX"sv, 2023y/6/4, 5910, event_picture_5910, R"XYX(Hatsune Miku × Kodō Special Live 2023 ~Yui~)XYX"sv, names_5910, 255, 2023, std::nullopt, 13030, R"(Hatsune Miku × Kodō Special Live 2023 ~Yui~)", "Finished"sv, R"XYX(hatsune-miku--kod-special-live)XYX"sv, std::nullopt, web_links_5910 },
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

Art by [LAM](https://vocadb.net/Ar/59773))XYX"sv, 2023y/8/13, 6045, event_picture_6045, R"XYX(Hatsune Miku "Magical Mirai 2023" in OSAKA)XYX"sv, names_6045, 81, 2023, std::nullopt, 13440, R"(Hatsune Miku "Magical Mirai" 2023)", "Approved"sv, R"XYX(hatsune-miku-magical-mirai-202)XYX"sv, std::nullopt, web_links_6045 },
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

Art by Bukurote)XYX"sv, std::nullopt, 5751, event_picture_5751, R"XYX(Miku Expo 2023 VR)XYX"sv, names_5751, 82, 2023, std::nullopt, 14426, R"(HATSUNE MIKU EXPO 2023 VR Setlist)", "Finished"sv, R"XYX(miku-expo-2023-vr)XYX"sv, std::nullopt, web_links_5751 },
  {R"XYX(MK15th project MEIKO＆KAITO オンラインコンサート)XYX"sv, "Concert"sv, 2024y/2/24, R"XYX(A short online concert celebrating MEIKO and KAITO's 15th anniversary.

**Concert Schedule:** February 24, 2024 (Sat) 19:00 ~ 20:00 JST

**Streaming Platform:** YouTube ([HatsuneMiku](https://www.youtube.com/channel/UCJwGWV914kBlV4dKRn7AEFA)))XYX"sv, std::nullopt, 6539, event_picture_6539, R"XYX(MK15th project MEIKO＆KAITO Online Concert)XYX"sv, names_6539, std::nullopt, 0, std::nullopt, 15303, R"(MK15th project　MEIKO&KAITO オンラインコンサート)", "Finished"sv, R"XYX(mk15th-project-meikokaito-onli)XYX"sv, std::nullopt, web_links_6539 },
  {R"XYX(MIKU FES'24 (春)〜Happy 16th Birthday〜, MIKU FES'24 (Haru)〜Happy 16th Birthday〜)XYX"sv, "Concert"sv, 2024y/3/31, std::nullopt, std::nullopt, 6986, event_picture_6986, R"XYX(MIKU FES'24 (Spring)〜Happy 16th Birthday〜)XYX"sv, names_6986, std::nullopt, 0, std::nullopt, 16628, R"(MIKU FES'24 (春)〜Happy 16th Birthday〜)", "Finished"sv, R"XYX(miku-fes24-haruhappy-16th-birt)XYX"sv, std::nullopt, web_links_6986 },
  {R"XYX()XYX"sv, "Unspecified"sv, 2024y/4/4, R"XYX(HATSUNE MIKU EXPO returns to North America to celebrate its 10th anniversary!)XYX"sv, std::nullopt, 6516, event_picture_6516, R"XYX(Miku Expo 2024 Vancouver )XYX"sv, names_6516, 82, 2024, std::nullopt, 16544, R"(Miku Expo 2024 North America)", "Draft"sv, R"XYX(miku-expo-2024-vancouver)XYX"sv, R"XYX(Thunderbird Arena)XYX"sv, web_links_6516 },
  {R"XYX(未来有你 2024 in Shanghai, HATSUNE MIKU WITH YOU 2024 in Shanghai)XYX"sv, "Unspecified"sv, 2024y/7/13, std::nullopt, 2024y/7/14, 7673, event_picture_7673, R"XYX(MIKU WITH YOU 2024 in Shanghai)XYX"sv, names_7673, 173, 2024, R"XYX(in Shanghai)XYX"sv, 17590, R"(MIKU WITH YOU 2024)", "Draft"sv, R"XYX(miku-with-you-2024-in-shanghai)XYX"sv, R"XYX(前滩31演艺中心·大剧场)XYX"sv, web_links_7673 },
  {R"XYX(初音ミク「マジカルミライ 2024」in FUKUOKA)XYX"sv, "Unspecified"sv, 2024y/8/17, R"XYX(Magical Mirai 2024’s theme is “FAN FUN TRIP”.

**Live Show**:
Fukuoka Sunpalace
August 17th(Sat.) - 18th(Sun.)

**Exhibition**:
FUKUOKA CONVENTION CENTER 2,4,5F
August 17th(Sat.) - 18th(Sun.)

Art by [たま](https://vocadb.net/Ar/1724))XYX"sv, 2024y/8/18, 7214, event_picture_7214, R"XYX(Hatsune Miku "Magical Mirai 2024" in FUKUOKA)XYX"sv, names_7214, 81, 2024, std::nullopt, 17933, R"(Hatsune Miku "Magical Mirai" 2024)", "Finished"sv, R"XYX(hatsune-miku-magical-mirai-202)XYX"sv, R"XYX(Fukuoka Sunpalace, FUKUOKA CONVENTION CENTER 2･4･5F)XYX"sv, web_links_7214 },
  {R"XYX()XYX"sv, "Unspecified"sv, 2024y/10/26, R"XYX(The HATSUNE MIKU EXPO 10th anniversary celebrations continue in Europe!)XYX"sv, std::nullopt, 7266, event_picture_7266, R"XYX(Miku Expo 2024 London)XYX"sv, names_7266, 82, 2024, std::nullopt, 18446, R"(Miku Expo 2024 Europe)", "Finished"sv, R"XYX(miku-expo-2024-london)XYX"sv, R"XYX(OVO Arena Wembley)XYX"sv, web_links_7266 },
  {R"XYX()XYX"sv, "Unspecified"sv, 2024y/11/15, std::nullopt, std::nullopt, 7765, event_picture_7765, R"XYX(Miku Expo 2024 Auckland)XYX"sv, names_7765, 82, 2024, R"XYX(Auckland)XYX"sv, 18583, R"(Miku Expo 2024 New Zealand & Australia)", "Draft"sv, R"XYX(miku-expo-2024-auckland)XYX"sv, R"XYX(Spark Arena)XYX"sv, web_links_7765 },
  {R"XYX(初音ミク JAPAN TOUR 2025 〜BLOOMING〜 大阪)XYX"sv, "Unspecified"sv, 2025y/4/19, std::nullopt, std::nullopt, 8380, event_picture_8380, R"XYX(HATSUNE MIKU JAPAN TOUR 2025 〜BLOOMING〜 OSAKA)XYX"sv, names_8380, 799, 1, std::nullopt, 19957, R"(初音ミク JAPAN TOUR 2025 〜BLOOMING〜)", "Finished"sv, R"XYX(hatsune-miku-japan-tour-2025-b)XYX"sv, std::nullopt, web_links_8380 },
  {R"XYX(初音ミク「マジカルミライ 2025」in SENDAI)XYX"sv, "Unspecified"sv, 2025y/8/1, R"XYX(Magical Mirai 2025’s theme is “Starry River in the Sky”.

**Live Show**:
Sendai Sunplaza
August 1st(Fri.) - 3rd(Sun.)

**Exhibition**:
Near Sendai Station
August 1st(Fri.) - 3rd(Sun.)

Art by [Tiv](https://vocadb.net/Ar/161497))XYX"sv, 2025y/8/3, 8768, event_picture_8768, R"XYX(Hatsune Miku "Magical Mirai 2025" in SENDAI)XYX"sv, names_8768, 81, 2025, std::nullopt, 20912, R"(Hatsune Miku "Magical Mirai" 2025)", "Finished"sv, R"XYX(hatsune-miku-magical-mirai-202)XYX"sv, std::nullopt, web_links_8768 },
  {R"XYX()XYX"sv, "Unspecified"sv, 2025y/11/5, std::nullopt, std::nullopt, 9341, event_picture_9341, R"XYX(Miku Expo 2025 Bangkok)XYX"sv, names_9341, 82, 2025, R"XYX(Bangkok)XYX"sv, std::nullopt, std::nullopt, "Draft"sv, R"XYX(miku-expo-2025-bangkok)XYX"sv, R"XYX(UOB LIVE)XYX"sv, web_links_9341 },
}};


} // namespace vocadb
