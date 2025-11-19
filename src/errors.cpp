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
        case songbot_error::reply_failure:
            return "Received error when trying to reply";
        case songbot_error::explosion:
            return "💥💥💥";
        case songbot_error::http_error_400:
            return "HTTP Error > 400";
        case songbot_error::http_error_404:
            return "HTTP Error 404 Not Found";
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
