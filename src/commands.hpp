#pragma once

import dpp;
import concerts;
import songs;
import std;
import magic_enum;

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

std::generator<char> escape_markdown_gen(std::string_view input) {
    for (char c : input) {
        switch (c) {
            case '*':
            case '`':
            case '_':
            case '~':
            case '#':
            case '-':
            case '[':
            case ']':
            case '(':
            case ')':
            case '|':
            case '>':
            case '\\':
//            case '+':
//            case '.':
//            case '!':*/
                co_yield '\\'; // Yield the escape character
                break;
            default:
                break;
        }
        co_yield c; // Yield the original character
    }
}

std::string escape_markdown(std::string_view input) {
    return escape_markdown_gen(input) | std::ranges::to<std::string>();
}

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

    static std::expected<void, std::exception_ptr> on_slashcommand(const dpp::slashcommand_t& event)
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
                    auto song = lookup_song(track.song, track.producer);
                    if (!song) {
                        reply << "I messed up! I can't produce this song. I'm sorry. This is a bug.\n";
                    } else {
                        reply << std::format("`{:2}` {}\n", track.pos, *song);
                    }
                }

                // Check for size
                if (reply.view().size() > 1900) {
                    reply.str(std::string());
                    reply << "Setlist for " << concert->short_name << ":\n";
                    for (auto track : setlist) {
                        auto song = lookup_song(track.song, track.producer);
                        if (!song) {
                            reply << "I messed up! I can't produce this song. I'm sorry. This is a bug.\n";
                        } else {
                            reply << std::format("`{:2}` {} feat. {} by {}\n", track.pos, song->name, magic_enum::enum_flags_name(song->singer), escape_markdown(song->producer));
                        }
                    }
                }
                event.reply(reply.str());
            }
        } catch (...) {
            return std::unexpected(std::current_exception());
        }
        return {};
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
