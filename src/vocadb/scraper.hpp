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

import std;
import cpr;
import nlohmann.json;

namespace cpr
{
    class CprErrorCategory : public std::error_category {
    public:
        // A unique name for the category
        const char* name() const noexcept override {
            return "cpr";
        }

        // Get a human-readable message for a specific error code value
        std::string message(int ev) const override {
            const auto ec = static_cast<ErrorCode>(ev);
            return std::to_string(ec);
        }
    };

    const std::error_category& cpr_error_category() noexcept;
    std::error_code make_error_code(ErrorCode e) noexcept;

}

namespace std {
template <>
struct is_error_code_enum<cpr::ErrorCode> : std::true_type {};
}

class scraper
{
public:
    scraper(std::filesystem::path res_directory) noexcept;

    std::expected<void, std::error_code> scrape_events(const std::filesystem::path& generated_src); // gen/release_events.cppm
    std::expected<void, std::error_code> scrape_songs(const std::filesystem::path& generated_src); // gen/songs.cppm

private:
    cpr::Session session;
    std::filesystem::path res_dir;
    std::default_random_engine rng_eng;
    std::gamma_distribution<double> dist;

    std::expected<void, std::error_code> write_song_anonymous(const nlohmann::json& event,  std::ostream& stream);
    std::expected<void, std::error_code> write_event_anonymous(const nlohmann::json& event,  std::ostream& stream);
    std::expected<cpr::Response, std::error_code> get(const cpr::Url& url, const cpr::Parameters& params = {});
    std::expected<cpr::Response, std::error_code> download(const cpr::Url& url, std::ofstream& os, const cpr::Parameters& params = {});
    std::expected<void, std::error_code> write_pictures(std::ostream& os,
                                                        const nlohmann::json& pic,
                                                        const std::string_view id_namespace,
                                                        std::uint64_t id);

    struct fetched_pic
    {
    public:
        fetched_pic(const std::filesystem::path& res_dir, std::string_view filename);
        std::string embed_filename;
        std::string mime_type;
        std::string file_ext;
    };

    std::expected<std::vector<std::optional<fetched_pic>>,
                  std::error_code>
    fetch_picture_embeds(const nlohmann::json& pictures,
                         const std::string_view id_namespace,
                         std::uint64_t id);

    std::chrono::milliseconds get_request_delay();
};
