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

export module project_sekai:tracks;

import :types;
import std;
import songs;
import songbot.errors;
import util;

namespace {
  constexpr auto no = std::nullopt;
}

export constexpr std::array sekai_tracks = std::to_array<SekaiTrack>({
    /* Pre-Existing Songs */
    { 1, VSG,     "Tell Your World" },
    { 43, VSG,    "Next Nest" },
    { 44, VSG,    "Hand in Hand" },
    { 45, VSG,    "39 Music!" },
    { 46, VSG,    "Greenlights Serenade" },
    { 47, VSG,    "Melt" },
    { 48, VSG,    "World is Mine" },
    { 49, VSG,    "The Disappearance of Hatsune Miku -DEAD END-" },
    { 50, VSG,    "Blessing" },
    { 72, VSG,    "Bless Your Breath" },
    { 83, VSG,    "Gimme×Gimme" },
    { 84, VSG,    "Junky Night Town Orchestra" }, // miss
    { 85, VSG,    "Leia" },
    { 86, VSG,    "on the rocks" },
    { 10001, VSG, "Jangsanbeom" }, // miss
    { 10002, VSG, "Alone" }, // miss
    { 10003, VSG, "Gakgaejeontu" }, // miss
    { 10004, VSG, "Beotkkotbi" }, // miss
    { 10005, VSG, "Byeolbit Serenade" }, // miss
    { 10006, VSG, "Bimil Inhyeonggeuk II" }, // miss
    { 10007, VSG, "Carpe Diem!" }, // miss
    { 10008, VSG, "Dungap" }, // miss
    { 10009, VSG, "Usan" }, // miss
    { 10010, VSG, "Shimiyuku" }, // miss
    { 104, VSG,   "Cendrillon" },
    { 108, VSG,   "Because You're Here" },
    { 109, VSG,   "Resonate" },
    { 110, VSG,   "Thousand Cherry Blossoms" },
    { 11001, VSG, "Pick Me Up" },
    { 11002, VSG, "My Stage With You" },
    { 11003, VSG, "Step Forward" },
    { 11004, VSG, "First Storm" },
    { 11005, VSG, "We Leave The World Together" }, // miss
    { 11006, VSG, "Jìng Zhōng Shàonǚ" }, // miss
    { 11007, VSG, "Dream Color Planet" },
    { 11010, VSG, "Crossing Over the Coastline" },
    { 11012, VSG, "Lái Dōu Lái le" }, // miss
    { 11013, VSG, "HIMAN=HIDAI Syousoukyoku" }, // miss
    { 11014, VSG, "Yuè Xī Jiāng · Chūnléi" }, // miss
    { 11015, VSG, "Mǎi Mǎi Mǎi" }, // miss
    { 11016, VSG, "Mag1c" },
    { 113, VSG,   "Rolling Girl" },
    { 114, VSG,   "Two-Sided Lovers" },
    { 115, VSG,   "Unknown Mother-Goose" },
    { 117, VSG,   "ODDS&ENDS" },
    { 118, VSG,   "*Hello, Planet." },
    { 119, VSG,   "World's End Dancehall" },
    { 124, VSG,   "I'll Miku-Miku You♪ (For Reals)" },
    { 131, VSG,   "The Intense Voice of Hatsune Miku" },
    { 150, VSG,   "TOKIO FUNKA" }, // miss
    { 152, VSG,   "Dareka no Shinzou ni Nareta Nara" }, // miss
    { 153, VSG,   "Miku" },
    { 175, VSG,   "Haikei Doppelganger" }, // miss
    { 177, VSG,   "Butterfly on Your Right Shoulder" },
    { 179, VSG,   "Meltdown" },
    { 186, VSG,   "Hatsune Creation Myth" },
    { 190, VSG,   "Daughter of Evil (The Princess of Lucifer)" },
    { 191, VSG,   "Servant of Evil (His Significance of Existence)" },
    { 202, VSG,   "Q" }, // miss
    { 206, VSG,   "Kimiiro Marine Snow" }, // miss
    { 214, VSG,   "Palette ni wa Kimi ga Ippai" }, // miss
    { 216, VSG,   "Luka Luka★Night Fever" },
    { 219, VSG,   "DUNE" },
    { 220, VSG,   "Donut Hole 2024" }, // miss
    { 220, VSG,   "Donut Hole" }, // miss
    { 221, VSG,   "Matryoshka" },
    { 222, VSG,   "Piano × Forte × Scandal" },
    { 223, VSG,   "Sennen no Dokusouka" }, // miss
    { 228, VSG,   "Goodbye" }, // miss
    { 229, VSG,   "Noushou Sakuretsu Girl" }, // miss
    { 238, VSG,   "Black★Rock Shooter" },
    { 247, VSG,   "Copycat" }, // miss
    { 249, VSG,   "Bokura no 16bit Sensou" }, // miss
    { 250, VSG,   "Kusaregedou to Chocolate" }, // miss
    { 251, VSG,   "Fräulein=Biblioteca" },
    { 256, VSG,   "Double Lariat" },
    { 261, VSG,   "Stardust Utopia" },
    { 263, VSG,   "Highlight" },
    { 265, VSG,   "Change me" },
    { 271, VSG,   "Warm Kaito" },
    { 273, VSG,   "FUTURE EVE" },
    { 275, VSG,   "Paradichlorobenzene" },
    { 278, VSG,   "Bad ∞ End ∞ Night" }, // miss
    { 279, VSG,   "This is, the Happiness and Peace of Mind Committee." },
    { 283, VSG,   "Rainy Snowdrop" },
    { 284, VSG,   "Invisible" },
    { 288, VSG,   "Unhappy Refrain" },
    { 296, VSG,   "Cantarella" },
    { 297, VSG,   "p.h." }, // miss
    { 301, VSG,   "My Love is Hellfire" },
    { 303, VSG,   "Rin-chan Now!" },
    { 305, VSG,   "Strobe Last" }, // miss
    { 309, VSG,   "Afterglow" }, // miss
    { 311, VSG,   "Yoake to Hotaru" }, // miss
    { 312, VSG,   "Heart" },
    { 313, VSG,   "FREELY TOMORROW" },
    { 317, VSG,   "Music Like Magic!" },
    { 318, VSG,   "Sharing The World" },
    { 319, VSG,   "Decade" },
    { 325, VSG,   "Buta ni Natte yeah yeah" }, // miss
    { 326, VSG,   "Tenshi no Tsubasa." }, // miss
    { 327, VSG,   "Snowmix♪" },
    { 328, VSG,   "SEKAI-chan to KAFU-chan no Otsukai Gassoukyoku" }, // miss
    { 330, VSG,   "Interviewer" },
    { 331, VSG,   "39 (Thank You)" },
    { 334, VSG,   "Vampire's ∞ pathoS" }, // miss
    { 335, VSG,   "TRASH and TRASH!" }, // miss
    { 337, VSG,   "METEOR" },
    { 341, VSG,   "Nanchoukei Danshi ga Taosenai" }, // miss
    { 342, VSG,   "Blue Star" },
    { 343, VSG,   "Snowman" },
    { 347, VSG,   "Enbizaka no Shitateya" }, // miss
    { 348, VSG,   "Akutoku no Judgement" }, // miss
    { 349, VSG,   "Akujiki Musume Conchita" }, // miss
    { 350, VSG,   "Nemurase Hime kara no gift" }, // miss
    { 357, VSG,   "Blue Planet" },
    { 362, VSG,   "Wonder Style" }, // miss
    { 363, VSG,   "UNDERWATER" }, // miss
    { 371, VSG,   "Sweety glitch" }, // miss
    { 379, VSG,   "Zunda Party Night" }, // miss
    { 381, VSG,   "New Human Race" },
    { 387, VSG,   "Hello Builder" }, // miss
    { 388, VSG,   "The Intense Voice of Hatsune Miku" },
    { 390, VSG,   "Dear" },
    { 401, VSG,   "Manimani" }, // miss
    { 403, VSG,   "Wintry Winds" },
    { 412, VSG,   "Devil Janai Mon" }, // miss
    { 414, VSG,   "HERO" },
    { 415, VSG,   "Lucky☆Orb" },
    { 419, VSG,   "Unsung Melodies" }, // miss
    { 420, VSG,   "imaginary love story" },
    { 430, VSG,   "\"Nh-Uh-Uh.\"" },
    { 433, VSG,   "Play With Fire" },
    { 435, VSG,   "Relay Outer" }, // miss
    { 439, VSG,   "Issen Kounen" }, // miss
    { 453, VSG,   "Ten Thousand Stars" },
    { 454, VSG,   "Electric Angel" },
    { 459, VSG,   "Can't Make a Song!!" },
    { 461, VSG,   "Odorobo" }, // miss
    { 462, VSG,   "Red Land Marker" },
    { 463, VSG,   "Happy Cheat Day" }, // miss
    { 464, VSG,   "Intergalactic Bound" },
    { 466, VSG,   "Garnet no Namida" }, // miss
    { 467, VSG,   "Love Song" },
    { 470, VSG,   "The First Sound" },
    { 479, VSG,   "MikuFiesta" },
    { 483, VSG,   "A Kotoba" }, // miss
    { 485, VSG,   "Dandan Hayaku Naru" }, // miss
    { 502, VSG,   "Help me, ERINNNNNN!!" }, // miss
    { 515, VSG,   "Igaku" }, // miss
    { 516, VSG,   "Achikochi Date-san" }, // miss
    { 518, VSG,   "Star of Heaven" },
    { 523, VSG,   "Resonance Between You and Me" },
    { 525, VSG,   "Antenna 39" },
    { 528, VSG,   "Thousand Little Voices" },
    { 529, VSG,   "Culture" },
    { 531, VSG,   "Mesmerizer" },
    { 535, VSG,   "Plaything" },
    { 541, VSG,   "Main Character" },
    { 542, VSG,   "Blackjack" },
    { 552, VSG,   "M@GICAL☆CURE! LOVE ♥ SHOT!" },
    { 558, VSG,   "No da" }, // miss
    { 561, VSG,   "Proto Disco" }, // miss
    { 562, VSG,   "Ángel" }, // miss
    { 563, VSG,   "NAKAKAPAGPABAGABAG" }, // miss
    { 566, VSG,   "Panda Hero" }, // miss
    { 567, VSG,   "Close and Open, Demons and The Dead" },
    { 568, VSG,   "Just 1dB Louder" }, // miss
    { 584, VSG,   "IMAWANOKIWA" }, // miss
    { 589, VSG,   "Barerii Ko" }, // miss
    { 590, VSG,   "MANHATTAN" }, // miss
    { 591, VSG,   "Yoshiwara Lament Sairaiban" }, // miss
    { 592, VSG,   "Queen of Hearts" }, // miss
    { 593, VSG,   "Crystal Snow" }, // miss
    { 594, VSG,   "Call!!" },
    { 598, VSG,   "Last of Me" }, // miss
    { 599, VSG,   "Karma" },
    { 604, VSG,   "Packaged" },
    { 609, VSG,   "Sad Machine" }, // miss
    { 611, VSG,   "Love! Snow! Really Magic" },
    { 612, VSG,   "Snow Fairy Story" },
    { 613, VSG,   "Before the Snow Melts" },
    { 614, VSG,   "Star Night Snow" },
    { 615, VSG,   "Round Off the Square Earth" },
    { 616, VSG,   "Love" },
    { 617, VSG,   "Poka Poka Planet" },
    { 618, VSG,   "Fondant Step" }, // miss
    { 619, VSG,   "Connecting" }, // miss
    { 624, VSG,   "Cirno no Perfect Sansuu Gakuen" }, // miss
    { 627, VSG,   "TETORIS" }, // miss
    { 628, VSG,   "Monitoring" },
    { 638, VSG,   "Kaben, Sore ni Matsuwaru Onsei" }, // miss
    { 639, VSG,   "Marionette Dancer" }, // miss
    { 640, VSG,   "MONSTER" }, // miss
    { 648, VSG,   "Life Will Change" }, // miss
    { 651, VSG,   "White Happy" }, // miss
    { 652, VSG,   "Kareshi no Jude" }, // miss
    { 653, VSG,   "Pamela" }, // miss
    { 654, VSG,   "Lustrous" },
    { 657, VSG,   "i DO what i WANT" }, // miss
    { 658, VSG,   "Jougen no Tsuki" }, // miss
    { 663, VSG,   "Venus" }, // miss
    { 666, VSG,   "Young Girl A" },
    { 667, VSG,   "Musekinin Shuugoutai" }, // miss
    { 669, VSG,   "origin" },
    { 685, VSG,   "DENKOH SEKKA" }, // miss
    { 686, VSG,   "TREASURE GARDEN" }, // miss
    { 687, VSG,   "JET BLACK" }, // miss
    { 688, VSG,   "WE ARE PICO PICO HAMMERS!!!!" }, // miss
    { 689, VSG,   "SAI'AI JINSEI RUNNER" }, // miss
    { 692, VSG,   "Vocalo-Colosseum" },
    { 694, VSG,   "Artifact" },
    { 699, VSG,   "Catch the Wave" },
    { 704, VSG,   "Kuronuri Sekai ate Shokan" }, // miss
    { 709, VSG,   "The Disappearance of Hatsune Miku -DEAD END-" },
    { 711, VSG,   "Wanderlast" },
    { 713, VSG,   "Nyanyanyanyanyanyanya!" },
    { 714, VSG,   "Fräulein=Ojousama" }, // miss
    { 717, VSG,   "Ribbon" }, // miss
    { 718, VSG,   "Maku wo Orosou, Parade e" }, // miss
    { 719, VSG,   "SHIAWASE FOR YOU!" }, // miss
    { 721, VSG,   "Aishiteitanoni" }, // miss
    { 722, VSG,   "Daidaidaidaidaikirai" }, // miss
    { 724, VSG,   "HAO" },
    { 725, VSG,   "shrimp miku" }, // miss
    { 726, VSG,   "Alkali Rettousei" }, // miss
    { 727, VSG,   "T-shi no Hanashi wo Shinjiru na" }, // miss
    { 736, VSG,   "LOVELY CAVITY" }, // miss
    { no, VSG,    "Hikari no Atsumekata" }, // miss
    { no, VSG,    "Lapse" }, // miss
    { no, VSG,    "De Los Santos" }, // miss
    { no, VSG,    "Ichiokunen Koi Shiteru" }, // miss
    { no, VSG,    "Ima Sugu Rinne" }, // miss
    /* Cover Songs */
    { 2, LEO,     "ROKI" },
    { 3, LEO,     "Teo" },
    { 6, LEO,     "HIBANA" },
    { 8, LEO,     "Time Machine" },
    { 10, MMJ,    "Happy Synthesizer" },
    { 11, MMJ,    "Viva Happy" },
    { 13, MMJ,    "Nostalogic (MEIKO-SAN mix)" },
    { 15, VBS,    "drop pop candy" },
    { 18, LEO,    "Asu no Yozora Shoukaihan" }, // miss
    { 19, N25,    "Charles" }, // miss
    { 21, WxS,    "Law-evading Rock" },
    { 22, N25,    "Inochi ni Kirawarete Iru" }, // miss
    { 26, VBS,    "BRING IT ON!" },
    { 27, VBS,    "Just Be Friends" },
    { 28, VBS,    "Doctor=Funk Beat" },
    { 36, WxS,    "Miracle Paint" },
    { 38, WxS,    "Tinplate's Dance" },
    { 41, WxS,    "Sweet Magic" },
    { 66, N25,    "Hello/How are you?" },
    { 67, N25,    "Jishou Mushoku" }, // miss
    { 68, WxS,    "Dance Robot Dance" }, // miss
    { 69, VBS,    "Fragile" }, // miss
    { 70, MMJ,    "Melty Land Nightmare" }, // miss
    { 71, MMJ,    "Patchwork Staccato" },
    { 73, MMJ,    "Near" }, // miss
    { 74, N25,    "Solitary Envy" },
    { 75, LEO,    "Tale of the Deep-sea Lily" },
    { 78, WxS,    "Bouken no Sho ga Kiemashita!" }, // miss
    { 81, VBS,    "Yobanashi Deceive" }, // miss
    { 87, MMJ,    "Love Trial" },
    { 88, WxS,    "Chururira Chururira Daddadda!" }, // miss
    { 91, LEO,    "Dramaturgy" },
    { 92, N25,    "Otome Dissection" },
    { 93, LEO,    "Aoku Kakero!" }, // miss
    { 94, N25,    "Totemo Itai Itagaritai" }, // miss
    { 95, VBS,    "Ifuudoudou" }, // miss
    { 96, LEO,    "from Y to Y" },
    { 98, LEO,    "Lost One's Weeping" },
    { 100, VBS,   "ECHO" }, // miss
    { 102, VBS,   "Ghost City Tokyo" },
    { 106, WxS,   "Oki ni Mesu mama" }, // miss
    { 107, MMJ,   "Milk Crown on Sonechka" }, // miss
    { 111, N25,   "Cutlery" }, // miss
    { 120, LEO,   "Ikanaide" }, // miss
    { 121, MMJ,   "Romeo and Cinderella" },
    { 122, WxS,   "Positive☆Dance Time" }, // miss
    { 123, MMJ,   "Dreamin Chuchu" },
    { 125, N25,   "Bocca della Verità" }, // miss
    { 129, N25,   "Bitter Chocolate Decoration" },
    { 133, VBS,   "Akuma no Odorikata" }, // miss
    { 134, WxS,   "Telecaster B Boy" },
    { 135, LEO,   "Roku-chou Nen to Ichiya Monogatari" }, // miss
    { 136, VBS,   "Children Record" }, // miss
    { 138, WxS,   "KING" }, // miss
    { 139, N25,   "Yoru ni Kakeru" }, // miss
    { 143, VBS,   "Traffic Jam" }, // miss
    { 145, N25,   "Venom" }, // miss
    { 146, WxS,   "Remote Controller" },
    { 147, MMJ,   "Karakuri Pierrot" },
    { 148, LEO,   "ray" },
    { 154, MMJ,   "Chikyuu Saigo no Kokuhaku wo" }, // miss
    { 155, LEO,   "Shinpakusuu♯0822" }, // miss
    { 157, MMJ,   "Marshmary" }, // miss
    { 158, WxS,   "Nonsense Bungaku" }, // miss
    { 167, VBS,   "Alter Ego" }, // miss
    { 168, MMJ,   "Darling Dance" },
    { 169, MMJ,   "Shoujorei" }, // miss
    { 170, N25,   "villain" }, // miss
    { 171, LEO,   "Kagerou Daze" },
    { 172, MMJ,   "Happy Halloween" }, // miss
    { 174, WxS,   "1 2 FanClub" },
    { 181, N25,   "Aishite Aishite Aishite" }, // miss
    { 183, WxS,   "fixer" }, // miss
    { 184, LEO,   "Hello,world!" }, // miss
    { 188, MMJ,   "Kokoroyohou" }, // miss
    { 194, N25,   "Delusional Sentimental Compensation Federation" },
    { 195, VBS,   "PaⅢ.SENSATION" }, // miss
    { 198, WxS,   "Goodbye Sengen" }, // miss
    { 199, LEO,   "Ghost Rule" },
    { 200, VBS,   "Garando" }, // miss
    { 201, WxS,   "Kami no Manimani" }, // miss
    { 204, N25,   "Usseewa" }, // miss
    { 205, VBS,   "Odo" },
    { 208, LEO,   "Bokura Mada Underground" }, // miss
    { 210, VBS,   "Ame to Petra" }, // miss
    { 213, MMJ,   "Vampire" },
    { 218, N25,   "Meru" }, // miss
    { 225, WxS,   "Ego Rock" },
    { 226, LEO,   "lost and found" },
    { 240, WxS,   "Odore Orchestra" }, // miss
    { 241, LEO,   "Asagao no Chiru Koro ni" }, // miss
    { 242, MMJ,   "Left-Behind City (Urbandonment)" },
    { 243, LEO,   "Calc." },
    { 245, VBS,   "Aun no Beats" }, // miss
    { 246, WxS,   "Alien Alien" },
    { 253, VBS,   "DAYBREAK FRONTLINE" }, // miss
    { 255, LEO,   "Yomosugara Kimi Omou" }, // miss
    { 258, MMJ,   "Deep-Sea Girl" },
    { 260, WxS,   "Love ka?" }, // miss
    { 262, VBS,   "Teikoku Shoujo" }, // miss
    { 266, VBS,   "YY" },
    { 268, N25,   "Non-breath oblige" }, // miss
    { 269, MMJ,   "Lonely Universe" },
    { 270, N25,   "Blooming in the Mud" },
    { 272, N25,   "Gehenna" },
    { 276, VBS,   "SHANTI" }, // miss
    { 277, N25,   "phony" }, // miss
    { 281, MMJ,   "Kimagure Mercy" },
    { 286, LEO,   "Hello, Worker" },
    { 289, LEO,   "Amanojaku" }, // miss
    { 291, VBS,   "Pheles" },
    { 293, N25,   "Irony" }, // miss
    { 294, N25,   "Even If It's Your Happiness" },
    { 298, WxS,   "Online Game Addicts Sprechchor" },
    { 299, VBS,   "Egoist" }, // miss
    { 306, WxS,   "1925" },
    { 307, WxS,   "Okochama Sensou" }, // miss
    { 320, MMJ,   "Booo!" }, // miss
    { 321, LEO,   "Attract Light" }, // miss
    { 322, VBS,   "Taemanaku Aiiro" }, // miss
    { 323, LEO,   "Kaisei" },
    { 339, LEO,   "glow" },
    { 340, N25,   "Totemo Suteki na Rokugatsu Deshita" }, // miss
    { 344, VBS,   "Brain Revolution Girl" },
    { 346, WxS,   "Aa, Subarashiki Nyansei" }, // miss
    { 352, N25,   "Inochi Bakkari" }, // miss
    { 354, MMJ,   "Setsuna Trip" }, // miss
    { 355, MMJ,   "The Snow White Princess is" },
    { 358, N25,   "kokoronashi" }, // miss
    { 360, WxS,   "Taiyoukei Disco" }, // miss
    { 361, MMJ,   "Kyuukurarin" }, // miss
    { 365, VBS,   "Love is War" },
    { 367, WxS,   "All I Need Are Things I Like" },
    { 369, MMJ,   "Melancholic" },
    { 372, LEO,   "Music of Heaven" },
    { 376, WxS,   "Wagamama Hime" }, // miss
    { 377, MMJ,   "Akuyaku ni Kiss Scene wo" }, // miss
    { 378, N25,   "Slow Downer" }, // miss
    { 385, N25,   "God-ish" },
    { 391, N25,   "Cute na Kanojo" }, // miss
    { 392, VBS,   "Shunran" }, // miss
    { 395, LEO,   "Summertime Record" }, // miss
    { 396, LEO,   "Tokyo Teddy Bear" },
    { 402, N25,   "Envy Baby" }, // miss
    { 407, LEO,   "When First Love Ends" },
    { 410, VBS,   "Marshall Maximizer" }, // miss
    { 413, MMJ,   "Sayonara Princess" }, // miss
    { 417, MMJ,   "Kuu ni Naru" }, // miss
    { 418, VBS,   "Kinmokusei" }, // miss
    { 431, MMJ,   "flos" }, // miss
    { 432, WxS,   "Kyoufuu All Back" }, // miss
    { 434, WxS,   "1000-nen Ikiteru" }, // miss
    { 436, WxS,   "Kosho Yashiki Satsujin Jiken" }, // miss
    { 437, VBS,   "Hm? Ah, Yes." },
    { 438, LEO,   "Hide and Seek" }, // miss
    { 441, VBS,   "Yoidore Shirazu" }, // miss
    { 443, LEO,   "Ringo Uri no Utakata Shoujo" }, // miss
    { 451, N25,   "Netsu Ijou" }, // miss
    { 455, N25,   "Dokuzu" }, // miss
    { 456, LEO,   "Kibou no Tsuki" }, // miss
    { 458, LEO,   "Weigh Anchor" },
    { 469, N25,   "Lag Train" }, // miss
    { 473, N25,   "Mind Brand" }, // miss
    { 475, WxS,   "Chigau!!!" }, // miss
    { 476, N25,   "Shadow Shadow" }, // miss
    { 477, LEO,   "Mozaik Role (Reloaded)" },
    { 480, WxS,   "Ochame Kinou" }, // miss
    { 482, MMJ,   "Dame Ningen da!" }, // miss
    { 484, LEO,   "Henceforth" }, // miss
    { 490, VBS,   "Rumor" }, // miss
    { 491, N25,   "Cat Loving" }, // miss
    { 493, WxS,   "Kyou mo Harebare" }, // miss
    { 494, MMJ,   "Poppin' Candy☆Fever!" }, // miss
    { 495, MMJ,   "SUPERHERO" },
    { 499, WxS,   "Konton Boogie" },
    { 501, N25,   "Bad Apple!! feat.SEKAI" }, // miss
    { 505, VBS,   "Call Boy" }, // miss
    { 506, WxS,   "QUEEN" }, // miss
    { 509, WxS,   "Liar Dancer" }, // miss
    { 510, N25,   "Shippaisaku Shoujo" }, // miss
    { 511, MMJ,   "Kisaragi Attention" }, // miss
    { 513, VBS,   "CH4NGE" }, // miss
    { 520, LEO,   "Toumei Elegy" }, // miss
    { 521, MMJ,   "Override" }, // miss
    { 522, VBS,   "WAVE" }, // miss
    { 530, MMJ,   "Cat Food" },
    { 533, WxS,   "Tensei Ringo" }, // miss
    { 534, LEO,   "World Lampshade [reunion]" }, // miss
    { 536, OTHER, "Fire◎Flower" },
    { 537, VBS,   "Hana ni Kaze" }, // miss
    { 544, MMJ,   "Mousou Aspartame" }, // miss
    { 547, LEO,   "Shuuen Touhikou" }, // miss
    { 551, N25,   "Lost Umbrella" }, // miss
    { 554, MMJ,   "snooze" }, // miss
    { 556, N25,   "The Farthest Ends" },
    { 557, VBS,   "Hana Obore" }, // miss
    { 559, LEO,   "Odoryanse" }, // miss
    { 571, VBS,   "Nisemono Ningen 40-gou" }, // miss
    { 580, VBS,   "Mikazuki Step" }, // miss
    { 581, WxS,   "Chuubyou Gekihatsu Boy" }, // miss
    { 586, VBS,   "Yankee Boy・Yankee Girl" }, // miss
    { 595, LEO,   "Envy Cat Walk" },
    { 601, MMJ,   "Ruma" }, // miss
    { 603, WxS,   "DoReMiFa Rondo" },
    { 606, N25,   "Suicide Parade" }, // miss
    { 607, MMJ,   "Mawaru Sora Usagi" }, // miss
    { 620, VBS,   "Shama" }, // miss
    { 621, MMJ,   "Tokyo Summer Session" }, // miss
    { 623, WxS,   "Touhou☆Wonderland" }, // miss
    { 625, WxS,   "Kono Fuzaketa Subarashiki Sekai wa, Boku no Tame ni Aru" }, // miss
    { 629, MMJ,   "8.32" }, // miss
    { 632, VBS,   "Surges" }, // miss
    { 641, LEO,   "Kimi ga Tobioriru no Naraba" }, // miss
    { 643, VBS,   "About me" }, // miss
    { 644, N25,   "Ikiru" }, // miss
    { 645, LEO,   "Deep Sea City Underground" },
    { 650, N25,   "Ano Natsu ga Houwa Suru." }, // miss
    { 661, WxS,   "Coward Fighters Urotander" },
    { 664, WxS,   "Hito Mania" }, // miss
    { 665, LEO,   "Rocket Cider" }, // miss
    { 670, WxS,   "I~ya I~ya I~ya" }, // miss
    { 672, VBS,   "How-To Sekai Seifuku" }, // miss
    { 680, N25,   "Who?" }, // miss
    { 682, MMJ,   "Anata Shika Mienai no" }, // miss
    { 690, WxS,   "Wakusei Loop" }, // miss
    { 693, MMJ,   "erase or zero" },
    { 698, N25,   "Kusari no Shoujo-Re Alive-" }, // miss
    { 700, MMJ,   "Mahou Shoujo to Chocolate" }, // miss
    { 702, LEO,   "Ramune" }, // miss
    { 703, VBS,   "Violence Trigger" },
    { 710, LEO,   "Hedgehog" },
    { 712, N25,   "Hikaku Shoukougun" }, // miss
    { 715, WxS,   "Mahou Shoujo Koufukuron" }, // miss
    { 723, N25,   "Lavie" },
    { no, N25,    "Propose" }, // miss
    { no, LEO,    "Raspberry＊Monster" },
    { no, VBS,    "Eien Hanahadashii" }, // miss
    /* Commissioned Songs */
    { 51, WxS,    "Sekai wa Mada Hajimatte sura Inai" }, // miss
    { 52, WxS,    "potato ni Natte iku" }, // miss
    { 54, VBS,    "Ready Steady" }, // miss
    { 55, VBS,    "Forward" }, // miss
    { 57, MMJ,    "Idol Shin'eitai" }, // miss
    { 60, N25,    "Kuyamu to Kaite Mirai" }, // miss
    { 61, N25,    "Keitai Renwa" }, // miss
    { 62, N25,    "Jackpot Sad Girl" }, // miss
    { 63, LEO,    "needLe" }, // miss
    { 64, LEO,    "Stella" },
    { 76, OTHER,  "Sekai" },
    { 77, OTHER,  "Wah Wah World" }, // miss
    { 89, MMJ,    "Color of Drops" }, // miss
    { 90, N25,    "Kagirinaku Haiiro e" }, // miss
    { 97, LEO,    "Hare wo Matsu" }, // miss
    { 99, MMJ,    "More! Jump! More!" }, // miss
    { 101, VBS,   "RAD DOGS" }, // miss
    { 103, WxS,   "NIJIIRO STORIES" }, // miss
    { 105, WxS,   "Once Upon a Dream" }, // miss
    { 11008, VSG, "Yīyàng" }, // miss
    { 11017, VSG, "Hype Dive" }, // miss
    { 112, MMJ,   "Tenshi no Clover" }, // miss
    { 116, N25,   "IDSMILE" }, // miss
    { 126, VBS,   "Cinema" }, // miss
    { 127, WxS,   "Tondemo-Wonderz" }, // miss
    { 130, LEO,   "From Tokyo" }, // miss
    { 132, LEO,   "「１」" }, // miss
    { 140, MMJ,   "Ice Drop" }, // miss
    { 141, OTHER, "Gunjou Sanka" }, // miss
    { 142, N25,   "Saisei" }, // miss
    { 144, MMJ,   "Ai no Material" }, // miss
    { 149, N25,   "Kanadetomosusora" }, // miss
    { 156, VBS,   "Beat Eater" }, // miss
    { 159, LEO,   "STAGE OF SEKAI" }, // miss
    { 160, WxS,   "Showtime Ruler" }, // miss
    { 161, VSG,   "magic number" }, // miss
    { 166, WxS,   "Glory Steady Go!" }, // miss
    { 173, LEO,   "Ryuusei no Pulse" }, // miss
    { 176, VSG,   "MACHINEGUN POEM DOLL" }, // miss
    { 178, WxS,   "Niccori^^Chousa-tai no Theme" }, // miss
    { 180, VBS,   "Mirai" }, // miss
    { 182, VBS,   "Flyer!" }, // miss
    { 187, N25,   "Lower" }, // miss
    { 189, N25,   "Nomad" }, // miss
    { 192, VSG,   "Saribitotachi no Waltz" }, // miss
    { 193, MMJ,   "Worldwide Wander" }, // miss
    { 196, LEO,   "Order Made" }, // miss
    { 203, N25,   "Tricologe" }, // miss
    { 207, LEO,   "Peaky Peaky" }, // miss
    { 209, MMJ,   "Metamo Re:born" }, // miss
    { 211, MMJ,   "IF" }, // miss
    { 212, WxS,   "Hoshizora no Melody" }, // miss
    { 217, VBS,   "Machi" }, // miss
    { 224, WxS,   "88☆彡" }, // miss
    { 230, OTHER, "Salamander" },
    { 231, OTHER, "Identity" }, // miss
    { 232, OTHER, "Aoiro Enogu" }, // miss
    { 233, OTHER, "Cosmospice" }, // miss
    { 234, OTHER, "Tokugawa Cup Noodle Kinshirei" }, // miss
    { 235, OTHER, "Journey" }, // miss
    { 236, LEO,   "Voices" }, // miss
    { 237, N25,   "Kimi no Yoru wo Kure" }, // miss
    { 239, VBS,   "Gekkou" }, // miss
    { 244, VBS,   "Awake Now" }, // miss
    { 248, N25,   "bug" }, // miss
    { 252, MMJ,   "DREAM PLACE" }, // miss
    { 257, LEO,   "Teratera" }, // miss
    { 259, LEO,   "the WALL" }, // miss
    { 264, MMJ,   "Parasol Cider" }, // miss
    { 267, VBS,   "Kashika" }, // miss
    { 280, VBS,   "Utsuro wo Aogu" }, // miss
    { 282, WxS,   "Hoshizora Orchestra" }, // miss
    { 285, VSG,   "ÅMARA" }, // miss
    { 287, MMJ,   "Watashi wa, Watashitachi wa" }, // miss
    { 290, WxS,   "Donna Ketsumatsu ga Onozomi dai?" }, // miss
    { 295, MMJ,   "Float Planner" }, // miss
    { 300, N25,   "Samsa" }, // miss
    { 302, LEO,   "Hurray" }, // miss
    { 304, N25,   "I Nandesu" }, // miss
    { 308, MMJ,   "Momoiro no Kagi" }, // miss
    { 310, LEO,   "Flyway" },
    { 316, VBS,   "Hitsuji ga Ippiki" }, // miss
    { 324, WxS,   "Hakoniwa no Coral" }, // miss
    { 333, WxS,   "Mr. Showtime" }, // miss
    { 336, OTHER, "Be The MUSIC!" }, // miss
    { 345, N25,   "Engeki" }, // miss
    { 351, LEO,   "Aioi" }, // miss
    { 353, N25,   "kitty" }, // miss
    { 356, VBS,   "Realize" }, // miss
    { 366, OTHER, "NEO" }, // miss
    { 368, VSG,   "I'm Mine" }, // miss
    { 373, VBS,   "Gekokujou" }, // miss
    { 374, MMJ,   "Teammate" }, // miss
    { 375, LEO,   "Hoshi wo Tsunagu" }, // miss
    { 383, LEO,   "purpose" }, // miss
    { 384, N25,   "Twilight Light" }, // miss
    { 386, WxS,   "Kirapipi★Kirapika" }, // miss
    { 393, VSG,   "Un-Lock" }, // miss
    { 394, VSG,   "Bottle Cake" }, // miss
    { 397, WxS,   "filament fever" }, // miss
    { 398, VBS,   "Beyond the way" }, // miss
    { 400, MMJ,   "Warera Stain Busters!" }, // miss
    { 404, VBS,   "blender" }, // miss
    { 405, MMJ,   "MOTTO!!!" }, // miss
    { 406, VSG,   "ARQETYPE" }, // miss
    { 409, N25,   "25-ji no Jounetsu" }, // miss
    { 411, WxS,   "Sekai wo Terasu Tetrad" }, // miss
    { 416, VSG,   "limbo" }, // miss
    { 421, VBS,   "CRAZY" }, // miss
    { 422, MMJ,   "JUMPIN’ OVER !" }, // miss
    { 423, LEO,   "Regulus" }, // miss
    { 424, LEO,   "Integral" }, // miss
    { 427, VSG,   "Yuukou, 1/f no Yurameki" }, // miss
    { 428, VSG,   "Tokimeki Jet Coaster" }, // miss
    { 429, MMJ,   "Hug" }, // miss
    { 440, VSG,   "Showtime×Audience" }, // miss
    { 442, LEO,   "Suresure" }, // miss
    { 445, VSG,   "Twilight Melody" }, // miss
    { 450, WxS,   "Opera! Space Opera!" }, // miss
    { 452, WxS,   "CYBERPUNK DEAD BOY" }, // miss
    { 457, MMJ,   "Supernova" }, // miss
    { 460, VSG,   "LEADER" }, // miss
    { 465, VSG,   "Jouou" }, // miss
    { 471, VBS,   "ULTRA C" }, // miss
    { 472, WxS,   "Seibai ItaAAAAAsu!" }, // miss
    { 474, MMJ,   "Killer" }, // miss
    { 478, VBS,   "Fuel" }, // miss
    { 489, OTHER, "Neppuu" }, // miss
    { 492, N25,   "Watashi wa Ame" }, // miss
    { 497, VBS,   "Rekka" }, // miss
    { 498, MMJ,   "Hashiru! Tooku! Todoku!" }, // miss
    { 500, N25,   "Yoka ni Mitorete" }, // miss
    { 507, N25,   "Empurple" }, // miss
    { 508, VBS,   "Haven" }, // miss
    { 514, VSG,   "FAKE HEART" }, // miss
    { 519, VSG,   "Natsuyo no Uta" }, // miss
    { 524, LEO,   "Soredemo Bokura wa Utau Koto wo Yamenai" }, // miss
    { 527, VSG,   "Unpoison" }, // miss
    { 538, WxS,   "All-Save Challenge" }, // miss
    { 539, MMJ,   "Eleventh" }, // miss
    { 540, N25,   "Nihil-san" }, // miss
    { 543, VSG,   "Seimeisei Syndrome" }, // miss
    { 546, LEO,   "Sono Oto ga Naru Nara" }, // miss
    { 548, WxS,   "Boku no Kami-sama" }, // miss
    { 549, N25,   "Bake no Hana" }, // miss
    { 555, OTHER, "Fusion" }, // miss
    { 560, WxS,   "EYELID" }, // miss
    { 564, N25,   "Soko ni Aru, Hikari." }, // miss
    { 570, LEO,   "Star" }, // miss
    { 572, N25,   "Kazatte" }, // miss
    { 573, VSG,   "Hajimari no Mirai" }, // miss
    { 574, LEO,   "SToRY" }, // miss
    { 575, MMJ,   "FUN!!" }, // miss
    { 576, VBS,   "Fire Dance" }, // miss
    { 577, WxS,   "Smile*Symphony" }, // miss
    { 578, VSG,   "Hello, SEKAI" }, // miss
    { 579, OTHER, "Worlders" }, // miss
    { 582, MMJ,   "ANTI YOU" }, // miss
    { 583, VBS,   "Accelerate" }, // miss
    { 585, OTHER, "pentatonic" }, // miss
    { 596, N25,   "D/N/A" }, // miss
    { 597, N25,   "Sono E no Namae wa" }, // miss
    { 600, WxS,   "Yuke" }, // miss
    { 602, VSG,   "ELECTRIC WEEKEND ZONE" }, // miss
    { 605, LEO,   "Sympathy" }, // miss
    { 610, MMJ,   "Polar Star" }, // miss
    { 630, N25,   "Koufuku Kei" }, // miss
    { 634, VBS,   "Kousenka" }, // miss
    { 635, MMJ,   "Ari no Mama no Story wo" }, // miss
    { 642, LEO,   "Kono Manma de Ikou" }, // miss
    { 646, LEO,   "Toumei na Palette" }, // miss
    { 649, WxS,   "Sayonara Tengoku Mata Kite Jigoku" }, // miss
    { 659, MMJ,   "Anata no Sora ga Naku no Nara" }, // miss
    { 660, WxS,   "Tobidase! Wonder-Pyoi" }, // miss
    { 662, N25,   "Kokuhaku" }, // miss
    { 668, VSG,   "Nekuratune Circus" }, // miss
    { 671, VSG,   "Kaijuu ni Naritai" }, // miss
    { 673, VSG,   "New Worlds" }, // miss
    { 674, VSG,   "MASTER Kounan'ido Gakkyoku Medley" }, // miss
    { 675, VSG,   "ProSEKA ULTIMATE Gakkyoku Medley" }, // miss
    { 676, VSG,   "Shuunen Kinen Kounan'ido Kakioroshi Gakkyoku Medley" }, // miss
    { 679, VBS,   "CRASH THE PARTY" }, // miss
    { 681, LEO,   "Hoshi ni Ichiban Chikai Basho" }, // miss
    { 683, MMJ,   "Colorful Foundation" }, // miss
    { 684, VBS,   "Fighter" }, // miss
    { 695, LEO,   "Hanamusubi" }, // miss
    { 701, VSG,   "Chu! Future☆Express!" }, // miss
    { 716, VBS,   "Touka Suru Ondo" }, // miss
    { 735, WxS,   "Kugutsu no Utsutsu" }, // miss
    { 740, VBS,   "Uka" }, // miss
    /* Contest Songs */
    { no, VSG,    "Hatsune Kyousoukyoku Dai 01-ban \"Suisei\"" },
    { no, VSG,    "Kowarechatta!!" }, // miss
    { no, VSG,    "Marude Nijuu Furiko no Sekai!" }, // miss
    { 82, VSG,    "alive" }, // miss
    { 11009, VSG, "Dīcǎidù Jìshì" }, // miss
    { 128, VSG,   "Brand New Day" }, // miss
    { 137, VSG,   "Hana wo Utau" }, // miss
    { 151, VSG,   "Utakata Mirai" }, // miss
    { 165, VSG,   "Sou Datta!!" }, // miss
    { 185, VSG,   "Sick of House!" }, // miss
    { 197, VSG,   "Last Score" }, // miss
    { 215, VSG,   "Judas" }, // miss
    { 227, VSG,   "ONESELF" }, // miss
    { 254, VSG,   "Mikansei Sanka" }, // miss
    { 274, VSG,   "Soredemo Ii nda yo" }, // miss
    { 292, VSG,   "Ichi Ni no San de" }, // miss
    { 314, VSG,   "A moment in the sun" },
    { 315, VSG,   "What's up? Pop!" }, // miss
    { 329, VSG,   "YAMINABE!!!!" }, // miss
    { 332, VSG,   "Epilogue ni Kimi wa Inai" }, // miss
    { 338, VSG,   "Where shall we go?" }, // miss
    { 359, VSG,   "Namonaki Kakumei" }, // miss
    { 364, VSG,   "Eternal Aria" }, // miss
    { 370, VSG,   "Jinsei" }, // miss
    { 380, VSG,   "Stardust Medley" }, // miss
    { 382, VSG,   "Shinpaku Pairing" }, // miss
    { 399, VSG,   "Disco No.39" }, // miss
    { 408, VSG,   "CIRCUS PANIC!!!" }, // miss
    { 425, VSG,   "Cool Me Down" }, // miss
    { 426, VSG,   "On&On" }, // miss
    { 444, VSG,   "Syndrome" }, // miss
    { 446, VSG,   "Overcode" }, // miss
    { 468, VSG,   "Juurokusai no Shinzou" }, // miss
    { 481, VSG,   "Meikyoushisui" }, // miss
    { 486, VSG,   "OGYARINIZER" }, // miss
    { 487, VSG,   "Daijobu Desu ka?" }, // miss
    { 488, VSG,   "Memoria" }, // miss
    { 496, VSG,   "Silver Collector" }, // miss
    { 504, VSG,   "I know Ai Nou." }, // miss
    { 512, VSG,   "Gousei Suru Mirai" }, // miss
    { 517, VSG,   "Merry-Go-Round" }, // miss
    { 526, VSG,   "Suisei no Kuni" }, // miss
    { 532, VSG,   "Layer Note" }, // miss
    { 545, VSG,   "Nouten" }, // miss
    { 553, VSG,   "Parry" }, // miss
    { 565, VSG,   "Natsu ni Toumei" }, // miss
    { 569, VSG,   "Secret Seeker" }, // miss
    { 587, VSG,   "Rule Book" }, // miss
    { 588, VSG,   "Planet Hero" }, // miss
    { 608, VSG,   "Hoshizora Melancholia" }, // miss
    { 626, VSG,   "Fish and Tips" }, // miss
    { 633, VSG,   "Niwashi no Ohanashi ni Yoru to" }, // miss
    { 636, VSG,   "Explore" }, // miss
    { 637, VSG,   "Waraetara Ee Yan!" }, // miss
    { 647, VSG,   "SANchi Chokusou" }, // miss
    { 655, VSG,   "lily-lala" }, // miss
    { 656, VSG,   "Blood Doll" }, // miss
    { 677, VSG,   "Abelia" }, // miss
    { 678, VSG,   "Kindokei" }, // miss
    { 691, VSG,   "0.0000034" }, // miss
    { 696, VSG,   "Dream Kiss" }, // miss
    { 697, VSG,   "Internet Junk Junkie" }, // miss
    { 720, VSG,   "ARiA" },
    { 732, VSG,   "Tenran no Ice Heaven" }, // miss
    { 737, VSG,   "Doukaai" }, // miss
    { 738, VSG,   "Strata de Machiawase" }, // miss
  });
