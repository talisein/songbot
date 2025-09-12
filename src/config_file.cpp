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
std::expected<IniData, std::exception_ptr>
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

std::expected<config, std::exception_ptr>
get_config(std::string_view filename)
{
    config res;
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
            path /= "api_token";
            if (!std::filesystem::exists(path)) break;
            std::ifstream api_token_file(path);
            if (!api_token_file.is_open()) break;
            std::println("INFO: Reading Discord API Token from {}", path.native());
            std::getline(api_token_file, res.api_token);
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
