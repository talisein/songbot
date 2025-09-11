#pragma once

import dpp;
import concerts;
import songs;

/*
class template_command
{
public:
    static dpp::slashcommand get_command(const auto& id)
    {
      auto cmd = dpp::slashcommand("cmd", "Description", id);
      return cmd;
    }

    static void on_slashcommand(const dpp::slashcommand_t& event)
    {
    }
};
*/

class setlist_command
{
public:
    static dpp::slashcommand get_command(const auto& id)
    {
        auto setlist_cmd = dpp::slashcommand("setlist", "Full Concert Setlist", id);
        auto event_opt = dpp::command_option(dpp::command_option_type::co_string, "event", "Name of event, e.g. ME2014LANY", true);
        event_opt.set_auto_complete(true);

        setlist_cmd.add_option(std::move(event_opt));
        return setlist_cmd;
    }

    static void on_slashcommand(const dpp::slashcommand_t& event)
    {
        try {
            auto param = std::get<std::string>(event.get_parameter("event"));
            auto concert = lookup_concert(param);
            if (!concert) {
                event.reply(std::format("I don't know about '{}'", param));
            } else {
                auto setlist = get_setlist(concert->short_name);
                std::ostringstream reply;
                reply << "Setlist for " << concert->name << ":\n";
                for (auto track : setlist) {
                    reply << std::format("`{:2}` {}\n", track.pos, *lookup_song(track.song));
                }
                event.reply(reply.str());
            }
        } catch (std::runtime_error& e) {
            event.reply(std::format("Oops, I messed up: {}", e.what()));
        } catch (std::exception& e) {
            event.reply(std::format("Oops, I really messed up: {}", e.what()));
        }
    }

    static std::optional<dpp::interaction_response> on_autocomplete(const dpp::autocomplete_t& event)
    {
        for (auto & opt : event.options) {
            if (opt.focused) {
                std::string uservalue = std::get<std::string>(opt.value);
                auto matches = match_concerts(uservalue);
                if (matches.empty()) return std::nullopt;
                auto resp = dpp::interaction_response(dpp::ir_autocomplete_reply);
                for (const auto& concert : matches) {
                    resp.add_autocomplete_choice(dpp::command_option_choice(std::string(concert.short_name), std::string(concert.short_name)));
                }
                return resp;
            }
        }
        return std::nullopt;
    }
};

class template_command
{
public:
    static dpp::slashcommand get_command(const auto& id)
    {
      auto cmd = dpp::slashcommand("cmd", "Description", id);
      return cmd;
    }

    static void on_slashcommand(const dpp::slashcommand_t& event)
    {
    }
};
