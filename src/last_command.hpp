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

import prometheus;
import std;

#include "commands.hpp"

class last_command : public iface_command
{
public:
    last_command(context &ctx) noexcept;

    dpp::slashcommand get_command() override;

    std::expected<void, std::error_code> on_slashcommand(const dpp::slashcommand_t& event) override;

    std::expected<dpp::interaction_response, std::error_code> on_autocomplete(const dpp::autocomplete_t& event) override;

private:
    std::expected<dpp::interaction_response, std::error_code> on_autocomplete_impl(const dpp::autocomplete_t& event);

    prometheus::Counter* last_success_counter;
    prometheus::Counter* last_failure_counter;

    prometheus::Counter* ac_last_success_counter;
    prometheus::Counter* ac_last_no_match_counter;
    prometheus::Counter* ac_last_failure_counter;
};
