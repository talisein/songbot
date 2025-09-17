#include <signal.h>
#include <sys/signalfd.h>
#include <cerrno>

import std;

#include "context.hpp"
#include "sd_notify.hpp"

int
main()
{
    context ctx("config.ini");

    /* Setup SIGTERM signalfd */
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
            signalfd_siginfo fdsi {};
            auto res = read(fd, &fdsi, sizeof(fdsi));
            if (res == sizeof(fdsi) && fdsi.ssi_signo == SIGTERM) {
                bot->log(dpp::ll_info, std::format("Received SIGTERM, exiting."));
                systemd::notify(0, "STOPPING=1");
                bot->shutdown();
            } else if (res == sizeof(fdsi)) {
                bot->log(dpp::ll_info, std::format("Received {}?", strsignal(fdsi.ssi_signo)));
            }

        } };
        ctx.bot->socketengine->register_socket(ev);
    }

    ctx.bot->start(dpp::st_wait);
    ctx.bot->log(dpp::ll_info, std::format("Stopped."));

    return 0;
}
