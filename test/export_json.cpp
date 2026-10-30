import std;
import boost.ut;
import dpp;
import songs;
import concerts;
import project_diva;
import project_sekai;

#include "export_json.hpp"

int main()
{
    using namespace boost::ut;
    using namespace std::literals;
    using json = nlohmann::json;

    const auto files = export_json::export_all();
    std::map<std::string, json> parsed;
    for (const auto& f : files)
        parsed[f.name] = json::parse(f.contents);

    "Every file parses and carries the schema version"_test = [&] {
        expect(eq(5UZ, files.size()));
        for (const auto& [name, j] : parsed) {
            expect(eq(export_json::schema_version, j.at("schema_version").get<int>())) << name;
            expect(j.at("data").is_array()) << name;
        }
    };

    "Output is deterministic"_test = [&] {
        const auto again = export_json::export_all();
        for (auto [a, b] : std::views::zip(files, again))
            expect(a.contents == b.contents) << a.name;
    };

    "Record counts match the source arrays"_test = [&] {
        expect(eq(songs.size(), parsed["songs.json"]["data"].size()));
        expect(eq(concerts.size(), parsed["concerts.json"]["data"].size()));
        expect(eq(get_live_events().size(), parsed["events.json"]["data"].size()));
        expect(eq(diva_tracks.size(), parsed["diva.json"]["data"].size()));
        expect(eq(sekai_tracks.size(), parsed["sekai.json"]["data"].size()));

        std::size_t tracks = 0;
        for (const auto& c : parsed["concerts.json"]["data"])
            tracks += c.at("setlist").size();
        expect(eq(setlists.size(), tracks));
    };

    "Setlist positions are contiguous"_test = [&] {
        for (const auto& c : parsed["concerts.json"]["data"]) {
            std::vector<int> positions;
            for (const auto& t : c.at("setlist"))
                positions.push_back(t.at("pos").get<int>());
            std::ranges::sort(positions);
            auto [first, last] = std::ranges::unique(positions);
            positions.erase(first, last);
            for (auto [i, pos] : std::views::enumerate(positions))
                expect(eq(static_cast<int>(i) + 1, pos)) << c.at("tour").get<std::string>();
        }
    };

    "Every event time zone resolves"_test = [&] {
        for (const auto& e : parsed["events.json"]["data"]) {
            const auto tz = e.at("tz").get<std::string>();
            expect(nothrow([&] { (void)std::chrono::locate_zone(tz); })) << tz;
        }
    };

    "Event times"_test = [&] {
        const auto& events = parsed["events.json"]["data"];
        auto london = std::ranges::find_if(events, [](const json& e) { return e.at("vocadb_event_id") == 12222; });
        expect(fatal(london != events.end()));
        expect(eq("ME2026EU"s, london->at("tour").get<std::string>()));
        expect(eq("2026-11-12T20:00:00"s, london->at("start_local").get<std::string>()));
        expect(eq("2026-11-12T20:00:00Z"s, london->at("start_utc").get<std::string>()));
        expect(eq(1794513600LL, london->at("start_unix").get<long long>()));
        expect(eq("Europe/London"s, london->at("tz").get<std::string>()));
        expect(eq(120, london->at("duration_minutes").get<int>()));
        expect(eq("London"s, london->at("city").get<std::string>()));
    };

    "Event time zones keep their linked names"_test = [&] {
        /* Europe/Amsterdam is a tzdb link to Europe/Brussels */
        const auto& events = parsed["events.json"]["data"];
        auto amsterdam = std::ranges::find_if(events, [](const json& e) { return e.at("vocadb_event_id") == 12224; });
        expect(fatal(amsterdam != events.end()));
        expect(eq("Europe/Amsterdam"s, amsterdam->at("tz").get<std::string>()));
        expect(eq("Amsterdam"s, amsterdam->at("city").get<std::string>()));
    };

    "Setlist tracks resolve to VocaDB ids"_test = [&] {
        const auto& c = parsed["concerts.json"]["data"];
        auto me14in = std::ranges::find_if(c, [](const json& j) { return j.at("tour") == "ME2014IN"; });
        expect(fatal(me14in != c.end()));
        const auto& first = me14in->at("setlist").at(0);
        expect(eq(1, first.at("pos").get<int>()));
        expect(first.contains("song_vocadb_id"));
    };

    "Singers are an array of names"_test = [&] {
        const auto& s = parsed["songs.json"]["data"];
        auto senbon = std::ranges::find_if(s, [](const json& j) { return j.value("romaji_name", "") == "Senbonzakura"; });
        expect(fatal(senbon != s.end()));
        expect(eq(json::array({"Miku"}), senbon->at("singers")));
    };
}
