import songs;
import concerts;

#include "sd_notify.hpp"
#include "context.hpp"
#include "setlist_command.hpp"
#include "song_command.hpp"
#include "last_command.hpp"

namespace
{
    void
    on_healthcheck_timer(dpp::timer timer)
    {
        systemd::notify(0, "WATCHDOG=1");
    }
}

context::context(std::string_view config_filename) :
    metric_registry(std::make_shared<prometheus::Registry>())
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

void context::on_ready(const dpp::ready_t& event)
{
    /* if (dpp::run_once<struct clear_bot_commands>()) {
       bot->global_bulk_command_delete();
       } */

    if (dpp::run_once<struct register_healthcheck_timer>()) {
        systemd::notify(0, "READY=1");
        systemd::notify(0, "STATUS=Mikumiku Setlists is ready for interaction");
        if (uint64_t usec = 0; systemd::watchdog_enabled(0, &usec) > 0) {
            uint64_t sec = usec / 1000 / 1000 / 2;
            if (sec > 5) {
                bot->log(dpp::ll_info, std::format("Setting up watchdog timer with interval {}s", sec));
                bot->start_timer(on_healthcheck_timer, sec /* Seconds */);
            } else {
                bot->log(dpp::ll_info, std::format("Watchdog timer ignored for interval {}s", sec));
            }
        } else {
            bot->log(dpp::ll_info, std::format("Starting default watchdog timer for 15s"));
            bot->start_timer(on_healthcheck_timer, 15 /* Seconds */);
        }
    }

    /* Register Commands */
    if (dpp::run_once<struct register_bot_commands>()) {
        auto cmds = std::views::values(commands) |
            std::views::transform([](auto &p) { return p->get_command(); }) |
            std::ranges::to<std::vector>();
        bot->global_bulk_command_create(cmds);
    }
}

void context::on_slashcommand(const dpp::slashcommand_t& event)
{
    auto it = commands.find(event.command.get_command_name());
    if (it == std::ranges::end(commands)) {
        bot->log(dpp::ll_debug, std::format("Got unexpected slashcommand for command={}",
                                            event.command.get_command_name()));
        event.reply("I have a bug in my programming, so I'm not sure what to say.");
        slashcommand_unknown_counter->Increment();
        return;
    }

    it->second->on_slashcommand(event);
}


void context::on_autocomplete(const dpp::autocomplete_t& event)
{
    auto it = commands.find(event.name);
    if (it == std::ranges::end(commands)) {
        bot->log(dpp::ll_debug, std::format("Got unexpected autocomplete for for event.name={}", event.name));
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

namespace {
    struct cerr_logger
    {
        void operator()(const dpp::log_t& log) const
        {
            if (log.severity > dpp::ll_error) {
                std::println(std::cerr, "[{}] {}: {}", dpp::utility::current_date_time(), dpp::utility::loglevel(log.severity), log.message);
            } else if (log.severity > dpp::ll_trace) {
                std::println("[{}] {}: {}", dpp::utility::current_date_time(), dpp::utility::loglevel(log.severity), log.message);
            }
        }
    };
}

void
context::setup_bot()
{
    systemd::notify(0, "STATUS=Starting Mikumiku Setlists discord bot");
    bot = std::make_unique<dpp::cluster>(config.api_token);

    bot->on_log(cerr_logger{});

    commands.emplace("setlist", std::make_unique<setlist_command>(*this));
//    commands.emplace("song", std::make_unique<song_command>(*this));
    commands.emplace("last", std::make_unique<last_command>(*this));

    bot->on_slashcommand([this](const dpp::slashcommand_t& event) {
        return on_slashcommand(event);
    });

    bot->on_ready([this](const dpp::ready_t& event) {
        return on_ready(event);
    });

    bot->on_autocomplete([this](const dpp::autocomplete_t & event) {
        return on_autocomplete(event);
    });
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
