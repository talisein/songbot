#include "commands.hpp"
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
    return cmd;
}
