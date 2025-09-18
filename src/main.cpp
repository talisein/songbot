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

#include <signal.h>
#include <sys/signalfd.h>
#include <cerrno>

import std;

#include "context.hpp"
#include "sd_notify.hpp"
#include "version.hpp"

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

    ctx.log(dpp::ll_info, "songbot version {} starting now", BUILD_GIT_COMMIT);
    ctx.bot->start(dpp::st_wait);
    ctx.log(dpp::ll_info, "Stopped.");

    return 0;
}
