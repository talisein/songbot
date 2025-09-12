#include <systemd/sd-daemon.h>

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
}
