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

import songs;
import concerts;

#include "sd_notify.hpp"
#include "context.hpp"
#include "setlist_command.hpp"
#include "setlistlast_command.hpp"
#include "song_command.hpp"
#include "last_command.hpp"
#include "version.hpp"
#include "formatters.hpp"

namespace
{
    void
    on_healthcheck_timer(dpp::timer timer)
    {
        systemd::notify(0, "WATCHDOG=1");
    }

    struct cerr_logger
    {
        void operator()(const dpp::log_t& log) const
        {
            if (log.severity > dpp::ll_error) {
                std::println(std::cerr, "{}: {}", dpp::utility::loglevel(log.severity), log.message);
            } else if (log.severity > dpp::ll_trace) {
                std::println("{}: {}", dpp::utility::loglevel(log.severity), log.message);
                std::cout.flush();
            }
        }
    };


}

context::context(std::string_view config_filename) :
    metric_registry(std::make_shared<prometheus::Registry>()),
    rng_engine([] {
        std::random_device rd;
        std::seed_seq seq {rd(), rd(), rd(), rd()};
        return std::default_random_engine{seq};
    }())
{
    auto res = get_config(config_filename);

    if (res.has_value()) {
        config = std::move(res.value());
    } else {
        std::rethrow_exception(res.error());
    }

    setup_metrics();

    setup_bot();
}

dpp::task<void> context::on_ready(const dpp::ready_t& event)
{
    if (dpp::run_once<struct register_healthcheck_timer>()) {
        systemd::notify(0, "READY=1");
        systemd::notify(0, "STATUS=Mikumiku Setlists is ready for interaction");
        if (uint64_t usec = 0; systemd::watchdog_enabled(0, &usec) > 0) {
            uint64_t sec = usec / 1000 / 1000 / 2;
            if (sec > 5) {
                log_info("Setting up watchdog timer with interval {}s", sec);
                bot->start_timer(on_healthcheck_timer, sec /* Seconds */);
            } else {
                log_info("Watchdog timer ignored for interval {}s", sec);
            }
        } else {
            log_info("Starting default watchdog timer for 15s");
            bot->start_timer(on_healthcheck_timer, 15 /* Seconds */);
        }

        if (config.public_key) {
            bot->enable_webhook_server(config.public_key.value(), "0.0.0.0", 3939);
        }

        bot->set_presence(dpp::presence(dpp::presence_status::ps_online,
                                        dpp::activity_type::at_listening, get_random_songname(rng_engine)));

        bot->start_timer([this](const dpp::timer& timer) {
            bot->set_presence(dpp::presence(dpp::presence_status::ps_online,
                                            dpp::activity_type::at_listening, get_random_songname(rng_engine)));
        }, 60 * 5 /* Seconds */);
    }

    /* Register Commands */
    if (dpp::run_once<struct register_bot_commands>()) {
        auto cmds = std::views::values(commands) |
            std::views::transform([](auto &p) { return p->get_command(); }) |
            std::ranges::to<std::vector>();
        auto conf = co_await bot->co_global_bulk_command_create(cmds);
        if (conf.is_error()) {
            log_error("Couldn't register commands: {:d}", conf.get_error());
        }
    }

    /* Notify owner of restart */
    if (dpp::run_once<struct notify_owner_on_restart>() && config.owner_id) {
        dpp::snowflake id { *config.owner_id };

        dpp::message msg { std::format("Mikumiku Setlists starting up! *Pi-pi-pi*! Version {} ready to chat!", BUILD_GIT_COMMIT) };
        auto dm_conf = co_await bot->co_direct_message_create(id, msg);
        if (dm_conf.is_error()) {
            log_error("Failed to send dm: {}", dm_conf.get_error());
        }

        auto guilds_conf = co_await bot->co_current_user_get_guilds();
        if (guilds_conf.is_error()) {
            log_error("Failed to get bot guilds: {}", guilds_conf.get_error());
            co_return;
        }

        auto map = guilds_conf.get<dpp::guild_map>();
        using namespace std::literals;
        log_info("I'm in the following guilds {}: {}",
                 map.size(),
                 std::views::values(map) | std::views::transform(&dpp::guild::name) |
                 std::views::join_with(", "sv) | std::ranges::to<std::string>());
    }

    co_return;
}

dpp::task<void> context::on_slashcommand(const dpp::slashcommand_t& event)
{
    auto it = commands.find(event.command.get_command_name());
    if (it == std::ranges::end(commands)) {
        log_debug("Got unexpected slashcommand for command={}",
                  event.command.get_command_name());
        slashcommand_unknown_counter->Increment();
        co_await event.co_reply("I have a bug in my programming, so I'm not sure what to say.");
        co_return;
    }

    auto res = co_await it->second->on_slashcommand(event);
    if (!res) {
        log_error("/{} failed: {}:{}", it->first, res.error().message(), res.error().value());
    }
    co_return;
}


void context::on_autocomplete(const dpp::autocomplete_t& event)
{
    auto it = commands.find(event.name);
    if (it == std::ranges::end(commands)) {
        log_debug("Got unexpected autocomplete for for event.name={}", event.name);
        ac_unknown_counter->Increment();
        event.success();
        return;
    }

    auto resp = it->second->on_autocomplete(event);
    if (resp) {
        bot->interaction_response_create(event.command.id, event.command.token, resp.value());
    } else {
        event.success();
    }
}

void
context::setup_bot()
{
    systemd::notify(0, "STATUS=Starting Mikumiku Setlists discord bot");

    if (config.public_key) {
        bot = std::make_unique<dpp::cluster>(config.api_token, 0, dpp::NO_SHARDS);
    } else {
        bot = std::make_unique<dpp::cluster>(config.api_token);
    }

    bot->on_log(cerr_logger{});

    commands.emplace("setlist", std::make_unique<setlist_command>(*this));
    commands.emplace("last", std::make_unique<last_command>(*this));
    commands.emplace("setlistlast", std::make_unique<setlistlast_command>(*this));

    bot->on_slashcommand(util::bind_front<&context::on_slashcommand>(this));

    bot->on_ready(util::bind_front<&context::on_ready>(this));

    bot->on_autocomplete(util::bind_front<&context::on_autocomplete>(this));
}

void
context::setup_metrics()
{
    /* TODO: Add prometeus bind address & port to config */
    systemd::notify(0, "STATUS=Starting Mikumiku Setlists prometheus endpoint");
    metric_exposer = std::make_unique<prometheus::Exposer>("0.0.0.0:3927");
    metric_exposer->RegisterCollectable(metric_registry);

    /* Compile-time static metrics */
    auto &song_counter = prometheus::BuildCounter()
        .Name("songs_total")
        .Help("Number of known live songs")
        .Register(*metric_registry);
    song_counter.Add({{"known", "compile-time"}}).Increment(songs.size());
    auto &concert_counter = prometheus::BuildCounter()
        .Name("concerts_total")
        .Help("Number of known concerts")
        .Register(*metric_registry);
    concert_counter.Add({{"known", "compile-time"}}).Increment(concerts.size());


    slashcommand_counter = &prometheus::BuildCounter()
        .Name("slashcommands_total")
        .Help("Number of slashcommands")
        .Register(*metric_registry);
    slashcommand_unknown_counter = &slashcommand_counter->Add({{"command", "unknown"}, {"result", "failure"}});

    autocompletion_counter = &prometheus::BuildCounter()
        .Name("autocompletions_total")
        .Help("Number of autocompletions")
        .Register(*metric_registry);
    ac_unknown_counter = &autocompletion_counter->Add({{"event", "unknown"}, {"result", "failure"}});
}
