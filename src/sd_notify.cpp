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
}

namespace systemd {
    int notify(int unset_environment, const char* state)
    {
        return sd_notify(unset_environment, state);
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
