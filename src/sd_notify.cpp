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

#include <systemd/sd-daemon.h>
#include <systemd/sd-journal.h>

#include "sd_notify.hpp"

namespace {
    constexpr std::string_view emerg{SD_EMERG};
    constexpr std::string_view alert{SD_ALERT};
    constexpr std::string_view crit{SD_CRIT};
    constexpr std::string_view err{SD_ERR};
    constexpr std::string_view warning{SD_WARNING};
    constexpr std::string_view notice{SD_NOTICE};
    constexpr std::string_view info{SD_INFO};
    constexpr std::string_view debug{SD_DEBUG};

    std::once_flag notify_socket_flag;
}

namespace systemd {
    int notify(int unset_environment, const char* state)
    {
        auto res = sd_notify(unset_environment, state);
        if (0 == res) {
            std::call_once(notify_socket_flag, [] static {
                std::println(std::cerr, "NOTICE: NOTIFY_SOCKET is not set, can't notify");
            });
        } else if (0 > res) {
            std::println(std::cerr, "ERROR: sd_notify(), errno={}", res);
        }
        return res;
    }

    int watchdog_enabled(int unset_environment, long unsigned *usec)
    {
        uint64_t sd_usec = 0;
        auto res = sd_watchdog_enabled(unset_environment, &sd_usec);
        *usec = sd_usec;
        return res;
    }

    void sd_logger(const dpp::log_t& log)
    {
        switch (log.severity) {
            case dpp::ll_trace:
                //sd_journal_print(LOG_DEBUG, "%s", log.message.c_str());
	            break;
            case dpp::ll_debug:
                sd_journal_print(LOG_DEBUG, "%s", log.message.c_str());
                break;
            case dpp::ll_info:
                sd_journal_print(LOG_INFO, "%s", log.message.c_str());
	            break;
            case dpp::ll_warning:
                sd_journal_print(LOG_WARNING, "%s", log.message.c_str());
	            break;
            case dpp::ll_error:
                sd_journal_print(LOG_ERR, "%s", log.message.c_str());
	            break;
            case dpp::ll_critical:
            default:
                sd_journal_print(LOG_CRIT, "%s", log.message.c_str());
	            break;
        }
    }

}
