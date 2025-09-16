#pragma once

import dpp;
import concerts;
import songs;
import std;
import magic_enum;

#include "errors.hpp"

constexpr size_t AUTOCOMPLETE_MAX_CHOICES = 25UZ;

class context;

class iface_command
{
public:
    iface_command(context& ctx, std::string_view cmd_name, std::string_view cmd_description) noexcept;

    virtual dpp::slashcommand get_command();

    virtual ~iface_command() = default;

    virtual std::expected<void, std::error_code> on_slashcommand(const dpp::slashcommand_t& event) = 0;

    virtual std::expected<dpp::interaction_response, std::error_code> on_autocomplete(const dpp::autocomplete_t& event) = 0;

protected:
    context * const ctx;
    const std::string_view cmd_name;
    const std::string_view cmd_description;


};
