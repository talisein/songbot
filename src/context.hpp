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

    template<auto severity, typename... Args>
    void log(Args&&... args);

    template<typename... Args>
    void log_error(std::format_string<Args...> fmt, Args&&... args);

    template<typename... Args>
    void log_info(std::format_string<Args...> fmt, Args&&... args);

    template<typename... Args>
    void log_debug(std::format_string<Args...> fmt, Args&&... args);

    template<typename... Args>
    void log_warning(std::format_string<Args...> fmt, Args&&... args);

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

template<auto severity, typename... Args>
void
context::log(Args&&... args)
{
    bot->log(severity, std::format(std::forward<Args>(args)...));
}

template<typename... Args>
void
context::log_error(std::format_string<Args...> fmt, Args&&... args)
{
    log<dpp::ll_error>(std::move(fmt), std::forward<Args>(args)...);
}

template<typename... Args>
void
context::log_info(std::format_string<Args...> fmt, Args&&... args)
{
    log<dpp::ll_info>(std::move(fmt), std::forward<Args>(args)...);
}

template<typename... Args>
void
context::log_debug(std::format_string<Args...> fmt, Args&&... args)
{
    log<dpp::ll_debug>(std::move(fmt), std::forward<Args>(args)...);
}

template<typename... Args>
void
context::log_warning(std::format_string<Args...> fmt, Args&&... args)
{
    log<dpp::ll_warning>(std::move(fmt), std::forward<Args>(args)...);
}
