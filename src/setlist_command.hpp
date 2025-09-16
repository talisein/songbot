#pragma once

import prometheus;
import std;

#include "commands.hpp"

class setlist_command : public iface_command
{
public:
    setlist_command(context &ctx) noexcept;

    dpp::slashcommand get_command() override;

    std::expected<void, std::error_code> on_slashcommand(const dpp::slashcommand_t& event) override;

    std::expected<dpp::interaction_response, std::error_code> on_autocomplete(const dpp::autocomplete_t& event) override;

private:
    std::expected<dpp::interaction_response, std::error_code> on_autocomplete_impl(const dpp::autocomplete_t& event);

    prometheus::Counter* setlist_success_counter;
    prometheus::Counter* setlist_failure_counter;

    prometheus::Counter* ac_setlist_success_counter;
    prometheus::Counter* ac_setlist_no_match_counter;
    prometheus::Counter* ac_setlist_failure_counter;
};
