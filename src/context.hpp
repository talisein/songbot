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
import prometheus;
import dpp;

#include "config_file.hpp"
#include "iface_command.hpp"

class context
{
public:
    context(std::string_view config_filename);

    bot_config config;
    std::unique_ptr<prometheus::Exposer> metric_exposer;
    std::shared_ptr<prometheus::Registry> metric_registry;

    std::unique_ptr<dpp::cluster> bot;

    std::map<std::string_view, std::unique_ptr<iface_command>> commands;

    std::default_random_engine rng_engine;

    template<typename... Args>
    void log(dpp::loglevel, std::format_string<Args...> fmt, Args&&... args);

private:
    void setup_metrics();
    void setup_bot();

    void on_ready(const dpp::ready_t& event);
    void on_slashcommand(const dpp::slashcommand_t& event);
    void on_autocomplete(const dpp::autocomplete_t& event);

public:
    prometheus::Family<prometheus::Counter>* slashcommand_counter;
    prometheus::Counter* slashcommand_unknown_counter;
    prometheus::Family<prometheus::Counter>* autocompletion_counter;
    prometheus::Counter* ac_unknown_counter;
};

template<typename... Args>
void
context::log(dpp::loglevel severity, std::format_string<Args...> fmt, Args&&... args)
{
    bot->log(severity, std::format(fmt, std::forward<Args>(args)...));
}
