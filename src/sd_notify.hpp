#pragma once

import dpp;

namespace systemd {
    int notify(int unset_environment, const char* state);
    int watchdog_enabled(int unset_environment, long unsigned *usec);

    void sd_logger(const dpp::log_t& log);
}
