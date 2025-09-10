module;

export module concerts;

import std;
import uni_algo;
import magic_enum;
import songs;
using namespace std::literals;

template<auto Proj>
constexpr auto make_needle_filter(std::string_view needle)
{
    return std::views::filter([needle](const auto& obj) constexpr -> bool {
        const auto &val = std::invoke(Proj, obj);
        return needle == val;
    });
}

export enum ConcertSeries
{
    MIKU_EXPO,
    MAGICAL_MIRAI,
    SNOW_MIKU,
    MIKUPA,
    MIKU_WITH_YOU,
};

export struct Concert
{
    ConcertSeries series;
    std::string_view name;
    std::string_view short_name;
    std::chrono::year year;
};

export constexpr std::array concerts = std::to_array<Concert>({
        { MIKU_EXPO, "HATSUNE MIKU EXPO 2014 in Indonesia", "ME2014IN", 2014y },
    });

export [[nodiscard]] constexpr
const Concert& lookup_concert(std::string_view short_name)
{
    auto it = std::ranges::find(concerts, short_name, &Concert::short_name);
    if (it == std::ranges::end(concerts)) throw std::exception();
    return *it;
}

export consteval
const Concert& operator ""_live(const char* short_name, std::size_t len)
{
    return lookup_concert({short_name, len});
}

export struct SetlistTrack
{
    std::string_view concert;
    int pos;
    std::string_view song;
    std::optional<std::string_view> variant; // E.g. setlist A, setlist B.
    std::optional<std::string_view> note; // E.g. Osaka Day 2
};

export constexpr std::array setlists = std::to_array<SetlistTrack>({
        { "ME2014IN", 1,  "Senbonzakura" },
        { "ME2014IN", 2,  "Look This Way, Baby" },
        { "ME2014IN", 3,  "Marginal" },
        { "ME2014IN", 4,  "Love Ward" },
        { "ME2014IN", 5,  "Colorful × Melody" },
        { "ME2014IN", 6,  "Fire◎Flower" },
        { "ME2014IN", 7,  "Butterfly on Your Right Shoulder" },
        { "ME2014IN", 8,  "Melancholic" },
        { "ME2014IN", 9,  "Heart" },
        { "ME2014IN", 10, "Left-Behind City (Urbandonment)" },
        { "ME2014IN", 11, "Close and Open, Demons and The Dead" },
        { "ME2014IN", 12, "Romeo and Cinderella" },
        { "ME2014IN", 13, "Piano × Forte × Scandal" },
        { "ME2014IN", 14, "Pane dhiria" },
        { "ME2014IN", 15, "Thousand Year Solo" },
        { "ME2014IN", 16, "Vegetable Juice" },
        { "ME2014IN", 17, "The Snow White Princess is" },
        { "ME2014IN", 18, "Venus at The Fingertips" },
        { "ME2014IN", 19, "Double Lariat" },
        { "ME2014IN", 20, "Luka Luka★Night Fever" },
        { "ME2014IN", 21, "Secret Police" },
        { "ME2014IN", 22, "Yellow" },
        { "ME2014IN", 23, "The Intense Voice of Hatsune Miku" },
        { "ME2014IN", 24, "Melt" },
        { "ME2014IN", 25, "Tell Your World" },
        { "ME2014IN", 26, "I'll Miku-Miku You♪ (For Reals)" },
        { "ME2014IN", 27, "letter song" },

    });

/* Every concert series needs to exist */
constexpr auto concert_series_exists = [](const SetlistTrack& track) constexpr -> bool { return std::ranges::contains(concerts, track.concert, &Concert::short_name); };
static_assert(std::ranges::all_of(setlists, concert_series_exists),
              std::ranges::find_if_not(setlists, concert_series_exists)->concert);

/* Every song needs to exist */
constexpr auto song_exists = [](const SetlistTrack& track) constexpr -> bool { return lookup_song(track.song).has_value(); };
static_assert(std::ranges::all_of(setlists, song_exists),
              std::ranges::find_if_not(setlists, song_exists)->song);

/* Every setlist position in a series must exist.
   e.g. Song 1, Song 2, Song 3. Not only Song 1 & Song 3. */
constexpr auto setlist_positions_skipped = [](const Concert& concert) constexpr -> bool {
    auto tracks = setlists | make_needle_filter<&SetlistTrack::concert>(concert.short_name) | std::ranges::to<std::vector>();
    std::ranges::stable_sort(tracks, {}, &SetlistTrack::pos);
    auto rng = std::views::slide(tracks, 2);
    for (auto pair : rng) {
        auto it = std::ranges::begin(pair);
        auto first = it->pos;
        auto second = (++it)->pos;
        if ((second - first) > 1)
            return true;
    }
    return false;
};
static_assert(std::ranges::none_of(concerts, setlist_positions_skipped),
              std::ranges::find_if(concerts, setlist_positions_skipped)->short_name);

export [[nodiscard]]
auto get_setlist(std::string_view short_name)
{
    return setlists | make_needle_filter<&SetlistTrack::concert>(short_name) | std::ranges::to<std::vector>();
}
