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
#include <execinfo.h>

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


    void init_handlers()
    {
        int pipefd[2];

        if (auto res = pipe(pipefd); res == -1) {
            std::println(std::cerr, "Error: Couldn't open pipe");
            return;
        }

        void *preload_buffer[2];
        int frames = backtrace(preload_buffer, 2);

        // Use the /dev/null descriptor to silently discard the output
        if (frames > 0) {
            backtrace_symbols_fd(preload_buffer, frames, pipefd[1]);
        }

        close(pipefd[0]);
        close(pipefd[1]);
    }

    extern "C" void sigsegv_handler(int sig)
    {
        const char msg[] = "\n--- Segmentation Fault (SIGSEGV) Detected ---\n";
        // Using write() which is async-signal-safe
        write(STDERR_FILENO, msg, sizeof(msg) - 1);

        const int max_frames = 100;
        void *callstack[max_frames];
        int frames = 0;

        // backtrace() is not strictly in the POSIX list, but is widely used
        // and safer than std::stacktrace::current() which involves allocation.
        frames = backtrace(callstack, max_frames);

        const char trace_msg[] = "--- Stack Trace (Raw Output) ---\n";
        write(STDERR_FILENO, trace_msg, sizeof(trace_msg) - 1);

        // backtrace_symbols_fd() is also often considered safer for a raw dump
        // as it writes directly to the file descriptor.
        backtrace_symbols_fd(callstack, frames, STDERR_FILENO);

        const char end_msg[] = "--------------------------------------------\n";
        write(STDERR_FILENO, end_msg, sizeof(end_msg) - 1);

        std::abort();
    }

    void terminate_handler() noexcept
    {
        auto eptr = std::current_exception();
        if (eptr) {
            try {
                std::rethrow_exception(eptr);
            } catch (const std::exception& e) {
                std::println(std::cerr, "Uncaught exception: {}", e.what());
            } catch (...) {
                std::println(std::cerr, "Uncaught exception, but its not std::exception");
            }
        } else {
            std::println("std::terminate called (no exception)");
        }

        std::println(std::cerr, "Stack trace:\n{}", std::stacktrace::current());
        std::abort();
    }
}

int
main()
{
    sigset_t mask;
    sigemptyset(&mask);
    sigaddset(&mask, SIGTERM);
    std::signal(SIGSEGV, sigsegv_handler);
    std::set_terminate(terminate_handler);
    init_handlers();

    if (int res = pthread_sigmask(SIG_BLOCK, &mask, nullptr); 0 != res) {
        std::println(std::cerr, "ERROR: Unable to mask SIGTERM. errno={}", errno_to_ec(res).message());
    } else {
        std::println(std::cout, "DEBUG: Masked SIGTERM");
    }

    context ctx("config.ini");

    int sfd = signalfd(-1, &mask, 0);
    if (sfd == -1) {
        ctx.log_error("Unable to create signalfd, errno={}", errno_to_ec(errno).message());
    } else {
        dpp::socket_events ev { sfd, dpp::socket_event_flags::WANT_READ, [&ctx](dpp::socket fd, const struct dpp::socket_events&) -> void
        {
            signalfd_siginfo fdsi {};
            auto res = read(fd, &fdsi, sizeof(fdsi));
            if (res == sizeof(fdsi) && fdsi.ssi_signo == SIGTERM) {
                ctx.log_info("Received SIGTERM, exiting.");
                systemd::notify(0, "STOPPING=1");
                ctx.bot->shutdown();
            } else if (res == sizeof(fdsi)) {
                ctx.log_warning("Received {}?", strsignal(fdsi.ssi_signo));
            }
        } };
        ctx.bot->socketengine->register_socket(ev);
    }

    ctx.log_info("songbot version {} starting now", BUILD_GIT_COMMIT);
    ctx.bot->start(dpp::st_wait);
    ctx.log_info("Stopped.");

    return 0;
}
