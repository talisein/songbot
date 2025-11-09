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

#include "iface_command.hpp"
#include "context.hpp"

iface_command::iface_command(context& ctx, std::string_view cmd_name, std::string_view cmd_description) noexcept :
    ctx(&ctx),
    cmd_name(cmd_name),
    cmd_description(cmd_description)
{
}

dpp::slashcommand
iface_command::get_command()
{
    auto cmd = dpp::slashcommand(std::string(cmd_name), std::string(cmd_description), ctx->bot->me.id);
    std::vector<dpp::interaction_context_type> contexts {
        dpp::interaction_context_type::itc_guild,
        dpp::interaction_context_type::itc_bot_dm,
        dpp::interaction_context_type::itc_private_channel
    };
    cmd.set_interaction_contexts(contexts);
    return cmd;
}
