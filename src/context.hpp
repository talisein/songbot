#pragma once

import std;
import prometheus;
import dpp;

#include "config_file.hpp"
#include "setlist_command.hpp"

class context
{
public:
    context(std::string_view config_filename);

    bot_config config;
    std::unique_ptr<prometheus::Exposer> metric_exposer;
    std::shared_ptr<prometheus::Registry> metric_registry;

    std::unique_ptr<dpp::cluster> bot;

    std::map<std::string_view, std::unique_ptr<iface_command>> commands;

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
