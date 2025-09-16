#pragma once

import prometheus;
import std;

#include "commands.hpp"

class song_command : public iface_command
{
public:
    song_command(context &ctx) noexcept;

    dpp::slashcommand get_command() override;

    std::expected<void, std::error_code> on_slashcommand(const dpp::slashcommand_t& event) override;

    std::expected<dpp::interaction_response, std::error_code> on_autocomplete(const dpp::autocomplete_t& event) override;

private:
    std::expected<dpp::interaction_response, std::error_code> on_autocomplete_impl(const dpp::autocomplete_t& event);

    prometheus::Counter* song_success_counter;
    prometheus::Counter* song_failure_counter;

    prometheus::Counter* ac_song_success_counter;
    prometheus::Counter* ac_song_no_match_counter;
    prometheus::Counter* ac_song_failure_counter;
};
