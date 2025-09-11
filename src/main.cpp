#include "sd_notify.hpp"
#include "token.hpp"
#include "commands.hpp"

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
    systemd::notify(0, "STATUS=Starting Mikumiku Setlists");
    dpp::cluster bot(API_TOKEN);

    bot.on_log(dpp::utility::cout_logger());

    bot.on_slashcommand([&bot](const dpp::slashcommand_t& event) {
        if (event.command.get_command_name() == "setlist") {
            setlist_command::on_slashcommand(event);
        } else {
            bot.log(dpp::ll_debug, std::format("Got unexpected slashcommand for command={}",
                                               event.command.get_command_name()));
            event.success();
        }
    });

    bot.on_ready([&bot](const dpp::ready_t& event) {
//        if (dpp::run_once<struct clear_bot_commands>()) {
//            bot.global_bulk_command_delete();
//        }

        if (dpp::run_once<struct register_healthcheck_timer>()) {
            systemd::notify(0, "READY=1");
            if (uint64_t usec = 0; systemd::watchdog_enabled(0, &usec) > 0) {
                bot.start_timer(on_healthcheck_timer, (usec / 1000) / 2 /* Seconds */);
            }
        }

        /* Register Commands */
        if (dpp::run_once<struct register_bot_commands>()) {
            bot.global_command_create(setlist_command::get_command(bot.me.id));
        }
    });

    bot.on_autocomplete([&bot](const dpp::autocomplete_t & event) {
        if (event.name == "setlist") {
            auto resp = setlist_command::on_autocomplete(event);
            if (resp) {
                bot.log(dpp::ll_debug, std::format("Autocomplete got something for {}", event.name));
                bot.interaction_response_create(event.command.id, event.command.token, *resp);
            } else {
                bot.log(dpp::ll_debug, std::format("Autocomplete has no match in field {}", event.name));
                event.success();
            }
        } else {
            bot.log(dpp::ll_debug, std::format("Got unexpected autocomplete for for event.name={}", event.name));
            event.success();
        }
    });

    bot.start(dpp::st_wait);
    return 0;
}
