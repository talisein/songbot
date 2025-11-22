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

#include "config_file.hpp"

static
std::string
trim(const std::string& str)
{
    const auto first = str.find_first_not_of(" \t\n\r");
    if (std::string::npos == first) {
        return str;
    }
    const auto last = str.find_last_not_of(" \t\n\r");
    return str.substr(first, (last - first + 1));
}


using IniData = std::map<std::string, std::map<std::string, std::string>>;
static std::expected<IniData, std::exception_ptr>
get_config_ini(std::string_view filename)
{
    using namespace std::literals;
    using IniData = std::map<std::string, std::map<std::string, std::string>>;
    IniData data;
    std::ifstream file(std::filesystem::path{filename});
    if (!file.is_open()) {
        return std::unexpected(std::make_exception_ptr(std::runtime_error(std::format("config file '{}' couldn't be opened", filename))));
    }

    std::string currentSection;
    std::string line;
    while (std::getline(file, line)) {
        line = trim(line);

        if (line.empty() || line.starts_with(';') || line.starts_with('#')) {
            continue; // Skip empty lines and comments
        }

        if (line.starts_with('[') && line.ends_with(']')) {
            // Found a new section
            currentSection = trim(line.substr(1, line.size() - 2));
            continue;
        }

        // Must be a key-value pair
        const auto separatorPos = line.find('=');
        if (separatorPos != std::string::npos) {
            std::string key = trim(line.substr(0, separatorPos));
            std::string value = trim(line.substr(separatorPos + 1));
            if (!currentSection.empty()) {
                data[currentSection][key] = value;
            }
        }
    }

    return data;
}

std::expected<bot_config, std::exception_ptr>
get_config(std::string_view filename)
{
    bot_config res;
    auto ini = get_config_ini(filename);

    /* Transform from ini map to config struct */
    if (ini) {
        auto &data = ini.value();
        if (data.contains("discord") && data["discord"].contains("api_token_file"))
        {
            auto path = std::filesystem::path(data["discord"]["api_token_file"]);
            if (!std::filesystem::exists(path)) {
                std::println(std::cerr, "Error: Given api_token_file '{}' doesn't exist", path.string());
                return std::unexpected(std::make_exception_ptr(std::runtime_error("Couldn't open api_token_file")));
            }
            std::ifstream token_file(path);
            if (!token_file.is_open()) {
                std::println(std::cerr, "Error: Couldn't open api_token_file '{}'", path.string());
                return std::unexpected(std::make_exception_ptr(std::runtime_error("Couldn't open api_token_file")));
            }
            std::getline(token_file, res.api_token);
        } else if (data.contains("discord") && data["discord"].contains("api_token")) {
            res.api_token = data["discord"]["api_token"];
        }

        if (data.contains("discord") && data["discord"].contains("public_key_file"))
        {
            auto path = std::filesystem::path(data["discord"]["public_key_file"]);
            if (!std::filesystem::exists(path)) {
                std::println(std::cerr, "Error: Given public_key_file '{}' doesn't exist", path.string());
                return std::unexpected(std::make_exception_ptr(std::runtime_error("Couldn't open public_key_file")));
            }
            std::ifstream token_file(path);
            if (!token_file.is_open()) {
                std::println(std::cerr, "Error: Couldn't open public_key_file '{}'", path.string());
                return std::unexpected(std::make_exception_ptr(std::runtime_error("Couldn't open public_key_file")));
            }
            std::string public_key;
            std::getline(token_file, public_key);
            res.public_key = public_key;
        } else if (data.contains("discord") && data["discord"].contains("public_key")) {
            res.public_key = data["discord"]["public_key"];
        }
        if (data.contains("discord") && data["discord"].contains("owner_id")) {
            auto owner_str = data["discord"]["owner_id"];
            std::uint64_t owner_id;
            auto [_, ec] = std::from_chars(std::to_address(owner_str.begin()), std::to_address(owner_str.end()), owner_id);
            if (ec == std::errc()) {
                res.owner_id = owner_id;
            }
        }

    }

    /* Default to $CREDENTIALS_DIRECTORY/api_token if no api_token */
    if (res.api_token.size() == 0) {
        do {
            std::filesystem::path path;
            const char* creds_dir_cstr = std::getenv("CREDENTIALS_DIRECTORY");
            if (creds_dir_cstr) {
                path = creds_dir_cstr;
            } else if (std::filesystem::exists("/run/secrets")) {
                path = "/run/secrets";
            } else if (std::filesystem::exists("/var/run/secrets")) {
                path = "/var/run/secrets";
            }

            auto token_path = path / "api_token";
            if (!std::filesystem::exists(token_path)) break;
            std::ifstream api_token_file(token_path);
            if (!api_token_file.is_open()) break;
            std::println("INFO: Reading Discord API Token from {}", token_path.native());
            std::getline(api_token_file, res.api_token);

            auto public_key_path = path / "public_key";
            if (!std::filesystem::exists(public_key_path)) break;
            std::ifstream public_key_file(public_key_path);
            if (!public_key_file.is_open()) break;
            std::println("INFO: Reading Discord Public Key from {}", public_key_path.native());
            std::string public_key;
            std::getline(public_key_file, public_key);
            res.public_key = public_key;
        } while (0);
    }

    /* Default to $CREDENTIALS_DIRECTORY/owner_id if no owner_id */
    if (!res.owner_id) {
        do {
            std::filesystem::path path;
            const char* creds_dir_cstr = std::getenv("CREDENTIALS_DIRECTORY");
            if (creds_dir_cstr) {
                path = creds_dir_cstr;
            } else if (std::filesystem::exists("/run/secrets")) {
                path = "/run/secrets";
            } else if (std::filesystem::exists("/var/run/secrets")) {
                path = "/var/run/secrets";
            }

            auto owner_id_path = path / "owner_id";
            if (!std::filesystem::exists(owner_id_path)) break;
            std::ifstream owner_id_file(owner_id_path);
            if (!owner_id_file.is_open()) break;
            std::println("INFO: Reading owner_id from {}", owner_id_path.native());
            std::string owner_str;
            std::getline(owner_id_file, owner_str);
            std::uint64_t owner_id;
            auto [_, ec] = std::from_chars(std::to_address(owner_str.begin()), std::to_address(owner_str.end()), owner_id);
            if (ec == std::errc()) {
                res.owner_id = owner_id;
            }

        } while (0);
    }

    if (res.api_token.size() == 0 && !ini) {
        return std::unexpected(ini.error());
    }

    if (res.api_token.size() < 10) {
        return std::unexpected(std::make_exception_ptr(std::runtime_error("Invalid api token")));
    }

    if (res.api_token.size() > 0) {
        return res;
    } else {
        return std::unexpected(std::make_exception_ptr(std::runtime_error("No api_token in config file")));
    }
}
