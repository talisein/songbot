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

#pragma once

import std;
import dpp;

constexpr size_t AUTOCOMPLETE_MAX_CHOICES = 25UZ;

class context;

class iface_command
{
public:
    iface_command(context& ctx, std::string_view cmd_name, std::string_view cmd_description) noexcept;

    virtual dpp::slashcommand get_command();

    virtual ~iface_command() = default;

    virtual dpp::task<std::expected<void, std::error_code>> on_slashcommand(const dpp::slashcommand_t event) = 0;

    virtual std::expected<dpp::interaction_response, std::error_code> on_autocomplete(const dpp::autocomplete_t& event) = 0;

protected:
    context * const ctx;
    const std::string_view cmd_name;
    const std::string_view cmd_description;


};
