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
import util;
import dpp;

#include "iface_command.hpp"
#include "state_storage.hpp"

class setlistlast_command : public iface_command
{
public:
    setlistlast_command(context &ctx) noexcept;

    dpp::slashcommand get_command() override;

    dpp::task<std::expected<void, std::error_code>> on_slashcommand(const dpp::slashcommand_t& event) override;

    std::expected<dpp::interaction_response, std::error_code> on_autocomplete(const dpp::autocomplete_t& event) override;

    void on_button_click(const dpp::button_click_t& event);

private:
    std::expected<dpp::interaction_response, std::error_code> on_autocomplete_impl(const dpp::autocomplete_t& event);

    using key_t = std::string;
public:
    struct event_state {
        std::string concert;
        dpp::slashcommand_t event;
        key_t reveal_key;
        key_t lang_key;
    };
private:
    state_storage<event_state> cmd_state_store;
    state_storage<decltype(cmd_state_store)::key_t> btn_reveal_state_store; // map to cmd_state_store
    state_storage<decltype(cmd_state_store)::key_t> btn_lang_state_store; // map to cmd_state_store

    void on_reveal_button_click(const dpp::button_click_t& event, const event_state& state);

    prometheus::Counter* setlistlast_success_counter;
    prometheus::Counter* setlistlast_failure_counter;
    prometheus::Counter* setlistlast_reveal_success_counter;
    prometheus::Counter* setlistlast_reveal_failure_counter;

    prometheus::Counter* ac_setlistlast_success_counter;
    prometheus::Counter* ac_setlistlast_no_match_counter;
    prometheus::Counter* ac_setlistlast_failure_counter;
};
