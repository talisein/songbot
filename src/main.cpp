#include "config_file.hpp"
#include "sd_notify.hpp"
#include "commands.hpp"


import prometheus;
import dpp;
import std;

void
on_healthcheck_timer(dpp::timer timer)
{
    systemd::notify(0, "WATCHDOG=1");
}

int
main()
{
    /* Read config file */
    auto config = get_config("config.ini");
    if (!config) {
        std::rethrow_exception(config.error());
        return 1;
    }

    /* Create metrics */
    systemd::notify(0, "STATUS=Starting Mikumiku Setlists prometheus endpoint");
    prometheus::Exposer exposer{"127.0.0.1:3927"};
    auto registry = std::make_shared<prometheus::Registry>();
    /* Metric: compile-time known data */
    auto& song_counter = prometheus::BuildCounter()
        .Name("songs_total")
        .Help("Number of known live songs")
        .Register(*registry);
    song_counter.Add({{"known", "compile-time"}}).Increment(songs.size());
    auto& concert_counter = prometheus::BuildCounter()
        .Name("concerts_total")
        .Help("Number of known concerts")
        .Register(*registry);
    concert_counter.Add({{"known", "compile-time"}}).Increment(concerts.size());

    /* Metric: setlist */
    auto& setlist_counter = prometheus::BuildCounter()
        .Name("slashcommand_setlist_total")
        .Help("Number of /setlist requests")
        .Register(*registry);
    auto &setlist_success_counter = setlist_counter.Add({{"result", "success"}});
    auto &setlist_failure_counter = setlist_counter.Add({{"result", "failure"}});
    exposer.RegisterCollectable(registry);

    /* Metric: Autocompletions */
    auto& autocompletion_counter = prometheus::BuildCounter()
        .Name("autocompletions_total")
        .Help("Number of autocompletions")
        .Register(*registry);
    auto& ac_setlist_success_counter = autocompletion_counter.Add({{"event", "setlist"}, {"result", "success"}});
    auto& ac_setlist_failure_counter = autocompletion_counter.Add({{"event", "setlist"}, {"result", "failure"}});
    auto& ac_unknown_counter = autocompletion_counter.Add({{"event", "unknown"}, {"result", "failure"}});

    /* Create Discord Bot */
    systemd::notify(0, "STATUS=Starting Mikumiku Setlists discord bot");
    dpp::cluster bot(config->api_token);

    bot.on_log(dpp::utility::cout_logger());

    bot.on_slashcommand([&bot, &setlist_success_counter, &setlist_failure_counter](const dpp::slashcommand_t& event) {
        if (event.command.get_command_name() == "setlist") {
            auto res = setlist_command::on_slashcommand(event);
            if (res.has_value()) {
                setlist_success_counter.Increment();
            } else {
                try {
                    std::rethrow_exception(res.error());
                } catch (std::exception &e) {
                    bot.log(dpp::ll_error, std::format("Setlist produced exception: {}", e.what()));
                    setlist_failure_counter.Increment();
                    event.reply("I have a bug in my programming, so I can't give you that setlist. I'm sorry!");
                }
            }
        } else {
            bot.log(dpp::ll_debug, std::format("Got unexpected slashcommand for command={}",
                                               event.command.get_command_name()));
            event.reply("I have a bug in my programming, so I'm not sure what to say.");
        }
    });

    bot.on_ready([&bot](const dpp::ready_t& event) {
        /* if (dpp::run_once<struct clear_bot_commands>()) {
            bot.global_bulk_command_delete();
        } */

        if (dpp::run_once<struct register_healthcheck_timer>()) {
            systemd::notify(0, "READY=1");
            systemd::notify(0, "STATUS=Mikumiku Setlists is ready for interaction");
            if (uint64_t usec = 0; systemd::watchdog_enabled(0, &usec) > 0) {
                uint64_t sec = usec / 1000 / 2;
                if (sec > 5) {
                    bot.log(dpp::ll_info, std::format("Setting up watchdog timer with interval {}", sec));
                    bot.start_timer(on_healthcheck_timer, sec /* Seconds */);
                } else {
                    bot.log(dpp::ll_error, std::format("Watchdog timer ignored for interval {}", sec));
                }
            }
        }

        /* Register Commands */
        if (dpp::run_once<struct register_bot_commands>()) {
            bot.global_command_create(setlist_command::get_command(bot.me.id));
        }
    });

    bot.on_autocomplete([&bot, &ac_setlist_success_counter, &ac_setlist_failure_counter, &ac_unknown_counter](const dpp::autocomplete_t & event) {
        if (event.name == "setlist") {
            auto resp = setlist_command::on_autocomplete(event);
            if (resp) {
                bot.interaction_response_create(event.command.id, event.command.token, *resp);
                ac_setlist_success_counter.Increment();
            } else {
                ac_setlist_failure_counter.Increment();
                event.success();
            }
        } else {
            bot.log(dpp::ll_debug, std::format("Got unexpected autocomplete for for event.name={}", event.name));
            ac_unknown_counter.Increment();
            event.success();
        }
    });

    bot.start(dpp::st_wait);
    return 0;
}
