#include <signal.h>
#include <sys/signalfd.h>
#include <cerrno>

import std;

#include "context.hpp"
#include "sd_notify.hpp"

int
main()
{
    std::println(std::cerr, "Environment report:");
    for (char** env = ::environ; *env != nullptr; ++env) {
        std::println(std::cerr, "{}", *env);
    }
    std::println(std::cerr, "Environment report finished. Now trying cout");
    std::println(std::cout, "Do you see cout?");


    context ctx("config.ini");

    sigset_t mask;
    sigemptyset(&mask);
    sigaddset(&mask, SIGTERM);
    // Block the signal in the current thread's signal mask
    pthread_sigmask(SIG_BLOCK, &mask, nullptr);
    int sfd = signalfd(-1, &mask, 0);
    if (sfd == -1) {
        ctx.bot->log(dpp::ll_error, std::format("Unable to create signalfd, errno={}", std::error_code{errno, std::generic_category()}.message()));

    } else {
        dpp::socket_events ev { sfd, dpp::socket_event_flags::WANT_READ, [bot = ctx.bot.get()](dpp::socket fd, const struct dpp::socket_events&) -> void
        {
            bot->log(dpp::ll_info, std::format("Received SIGTERM, exiting."));
            systemd::notify(0, "STOPPING=1");
            bot->shutdown();
        } };
        ctx.bot->socketengine->register_socket(ev);
    }

    ctx.bot->start(dpp::st_wait);

    return 0;
}
