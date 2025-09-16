#include "errors.hpp"

const char*
songbot_error_category::name() const noexcept
{
    return "songbot_errors";
}

std::string
songbot_error_category::message(int ev) const
{
    switch (static_cast<songbot_error>(ev)) {
        case songbot_error::invalid_config_file:
            return "Configuration file is invalid";
        case songbot_error::missing_api_token:
            return "No Discord bot API token was provided in the configuration";
        case songbot_error::autocomplete_no_match:
            return "No match for autocompletion";
        case songbot_error::autocomplete_no_focused_option:
            return "Autocompletion requested but no passed option was focused";
        case songbot_error::explosion:
            return "💥💥💥";
    }

    return std::format("Unknown songbot error code {}", ev);
}

const std::error_category& get_songbot_error_category() noexcept {
    static const songbot_error_category instance;
    return instance;
}

std::error_code make_error_code(songbot_error e) noexcept {
    return { std::to_underlying(e), get_songbot_error_category() };
}
