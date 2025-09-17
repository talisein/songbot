#include <signal.h>
#include <sys/signalfd.h>
#include <cerrno>

import std;

#include "context.hpp"
#include "sd_notify.hpp"

namespace
{
    [[nodiscard]] std::error_code
    errno_to_ec(int err) noexcept {
        return {err, std::generic_category()};
    }
}

int
main()
{
    sigset_t mask;
    sigemptyset(&mask);
    sigaddset(&mask, SIGTERM);
    if (int res = pthread_sigmask(SIG_BLOCK, &mask, nullptr); 0 != res) {
        std::println(std::cerr, "ERROR: Unable to mask SIGTERM. errno={}", errno_to_ec(res).message());
    } else {
        std::println(std::cout, "DEBUG: Masked SIGTERM");
    }

    context ctx("config.ini");

    int sfd = signalfd(-1, &mask, 0);
    if (sfd == -1) {
        ctx.log(dpp::ll_error, "Unable to create signalfd, errno={}", errno_to_ec(errno).message());
    } else {
        dpp::socket_events ev { sfd, dpp::socket_event_flags::WANT_READ, [&ctx](dpp::socket fd, const struct dpp::socket_events&) -> void
        {
            signalfd_siginfo fdsi {};
            auto res = read(fd, &fdsi, sizeof(fdsi));
            if (res == sizeof(fdsi) && fdsi.ssi_signo == SIGTERM) {
                ctx.log(dpp::ll_info, "Received SIGTERM, exiting.");
                systemd::notify(0, "STOPPING=1");
                ctx.bot->shutdown();
            } else if (res == sizeof(fdsi)) {
                ctx.log(dpp::ll_warning, "Received {}?", strsignal(fdsi.ssi_signo));
            }
        } };
        ctx.bot->socketengine->register_socket(ev);
    }

    ctx.bot->start(dpp::st_wait);
    ctx.log(dpp::ll_info, "Stopped.");

    return 0;
}
