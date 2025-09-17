import util;
import concerts;
import songs;

#include "setlist_command.hpp"
#include "context.hpp"

namespace {
    static
    std::generator<std::string> get_setlist_lines(std::string_view concert_name)
    {
        auto concert = lookup_concert(concert_name);
        if (!concert) {
            co_yield std::format("I don't know about '{}'", concert_name);
            co_return;
        }

        auto setlist = get_setlist(concert->short_name);
        co_yield std::format("Setlist for {}:\n", concert->name);
        for (auto &track : setlist) {
            auto song = lookup_song(track.song, track.producer);
            if (!song) {
                co_yield std::format("`{:2}` 🫠 '{}' I guess? This is a bug...\n", track.pos, track.song);
                continue;
            }
            co_yield std::format("`{:2}` {}\n", track.pos, util::escape_markdown(std::format("{}", *song)));
        }
    }

}

setlist_command::setlist_command(context &ctx) noexcept :
    iface_command(ctx, "setlist", "Full Concert Setlist")
{
    /* Metric: setlist */
    setlist_success_counter = &ctx.slashcommand_counter->Add({{"command", "setlist"}, {"result", "success"}});
    setlist_failure_counter = &ctx.slashcommand_counter->Add({{"command", "setlist"}, {"result", "failure"}});

    /* Metric: Autocompletions */
    ac_setlist_success_counter = &ctx.autocompletion_counter->Add({{"event", "setlist"}, {"result", "success"}});
    ac_setlist_no_match_counter = &ctx.autocompletion_counter->Add({{"event", "setlist"}, {"result", "no-match"}});
    ac_setlist_failure_counter = &ctx.autocompletion_counter->Add({{"event", "setlist"}, {"result", "failure"}});
}

dpp::slashcommand
setlist_command::get_command()
{
    auto setlist_cmd = iface_command::get_command();
    auto event_opt = dpp::command_option(dpp::command_option_type::co_string, "event", "Name of event, e.g. ME2014LANY", true);
    event_opt.set_auto_complete(true);

    setlist_cmd.add_option(std::move(event_opt));
    return setlist_cmd;
}

namespace {
    constexpr size_t DISCORD_REPLY_LIMIT = 2000UZ;

    void my_follow_up(const dpp::slashcommand_t event,
                      const dpp::message& msg,
                      dpp::command_completion_event_t cb = dpp::utility::log_error())
    {
        event.owner->interaction_followup_create(event.command.token, msg, std::move(cb));
    }

    /* DPP makes confirmation_callback_t const, so we need to create a new closure for each successive followup. */
    struct recursive_follow_upper
    {
        dpp::slashcommand_t event;
        context * const ctx;
        std::vector<dpp::message> msgs;
        int sequence;

        recursive_follow_upper(const dpp::slashcommand_t& event, context * const ctx, auto &&rng, int sequence = 2) noexcept :
            event(event),
            ctx(ctx),
            msgs(std::views::drop(rng, 1) | std::ranges::to<std::vector>()),
            sequence(sequence)
        { }


        auto operator()(const dpp::confirmation_callback_t& confirmation) const
        {
            if (confirmation.is_error()) {
                return dpp::utility::log_error()(confirmation);
            }

            if (msgs.size() == 1) {
                return my_follow_up(event, msgs.front());
            } else {
                return my_follow_up(event, msgs.front(), recursive_follow_upper(event, ctx, msgs, sequence + 1));
            }
        }

    };
}

std::expected<void, std::error_code>
setlist_command::on_slashcommand(const dpp::slashcommand_t& event)
{
    try {
        /* Some setlists are more than 2000 characters. So we need to split up
         * our reply into a reply and some number of follow ups. */

        auto lines = get_setlist_lines(std::get<std::string>(event.get_parameter("event")));
        std::ostringstream reply;
        std::vector<dpp::message> messages;

        for (const auto& line : lines) {
            if ((reply.view().size() + line.size()) >= DISCORD_REPLY_LIMIT) {
                messages.emplace_back(reply.view()).set_flags(dpp::message_flags::m_ephemeral);
                reply.str(line);
            } else {
                reply << line;
            }
        }

        if (reply.view().size() > 0) {
            messages.emplace_back(reply.view()).set_flags(dpp::message_flags::m_ephemeral);
        }

        /* Ok, we have a list of messages to send. */
        if (messages.size() == 1) {
            event.reply(messages.front());
        } else {
            event.reply(messages.front(), recursive_follow_upper(event, ctx, messages));
        }

    } catch(std::system_error &e) {
        event.reply("I have a bug in my programming, so I can't give you that setlist. I'm sorry!");
        ctx->bot->log(dpp::ll_error, std::format("/setlist: System Error {}", e.what()));
        setlist_failure_counter->Increment();
        return std::unexpected(e.code());
    } catch (...) {
        event.reply("I have a bug in my programming, so I can't give you that setlist. I'm sorry!");
        ctx->bot->log(dpp::ll_error, "/setlist: Unhandled exception");
        setlist_failure_counter->Increment();
        return std::unexpected(songbot_error::explosion);
    }

    setlist_success_counter->Increment();
    return {};
}

std::expected<dpp::interaction_response, std::error_code>
setlist_command::on_autocomplete_impl(const dpp::autocomplete_t& event)
{
    for (auto & opt : event.options | std::views::filter(&dpp::command_option::focused)) {
        try {
            std::string uservalue = std::get<std::string>(opt.value);

            auto matches = match_concerts(uservalue);
            if (matches.empty()) {
                return std::unexpected(songbot_error::autocomplete_no_match);
            }

            auto resp = dpp::interaction_response(dpp::ir_autocomplete_reply);
            for (const auto& concert : matches | std::views::take(AUTOCOMPLETE_MAX_CHOICES) ) {
                resp.add_autocomplete_choice(dpp::command_option_choice(std::string(concert.short_name), std::string(concert.short_name)));
            }

            return resp;
        } catch (std::bad_variant_access &e) {
            ctx->bot->log(dpp::ll_error, std::format("/setlist: autocomplete error: {}", e.what()));
            return std::unexpected(std::make_error_code(std::errc::invalid_argument));
        }
    }

    return std::unexpected(songbot_error::autocomplete_no_focused_option);
}

std::expected<dpp::interaction_response, std::error_code>
setlist_command::on_autocomplete(const dpp::autocomplete_t& event)
{
    auto res = on_autocomplete_impl(event);
    if (res) {
        ac_setlist_success_counter->Increment();
    } else {
        bool is_no_match = res.error().category() == get_songbot_error_category() &&
            res.error().value() == std::to_underlying(songbot_error::autocomplete_no_match);
        if (is_no_match) {
            ac_setlist_no_match_counter->Increment();
        } else {
            ac_setlist_failure_counter->Increment();
        }
    }

    return res;
}
