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

import util;
import concerts;
import songs;
import songbot.errors;
import vocadb.api;
import vocadb.songs;

#include "freq_command.hpp"
#include "context.hpp"
#include "formatters.hpp"

freq_command::freq_command(context &ctx) noexcept :
    iface_command(ctx, "freq", "List the most frequent live songs")
{
    /* Metric: freq command */
    freq_success_counter = &ctx.slashcommand_counter->Add({{"command", "freq"}, {"result", "success"}});
    freq_failure_counter = &ctx.slashcommand_counter->Add({{"command", "freq"}, {"result", "failure"}});
}

dpp::slashcommand
freq_command::get_command()
{
    auto freq_cmd = iface_command::get_command();

    return freq_cmd;
}


dpp::task<std::expected<void, std::error_code>>
freq_command::on_slashcommand(const dpp::slashcommand_t event)
{
    using namespace std::literals;
    auto start_idx = 0UZ;
    constexpr auto step = 25UZ;
    const auto next_key = ctx->keygen();
    const auto prev_key = ctx->keygen();

    auto make_msg = [&] {
      auto msg = dpp::message().set_flags(dpp::message_flags::m_using_components_v2 | dpp::message_flags::m_ephemeral).suppress_embeds(true);
      auto action_row = dpp::component().set_type(dpp::cot_action_row);
      if (start_idx > 0) {
        auto prev_button = dpp::component().set_type(dpp::cot_button)
          .set_style(dpp::cos_primary)
          .set_label(std::format("Prev {}", step))
          .set_id(prev_key);
        action_row.add_component_v2(prev_button);
      }
      if ((start_idx + step) < song_frequencies.size()) {
        auto next_button = dpp::component().set_type(dpp::cot_button)
          .set_style(dpp::cos_primary)
          .set_label(std::format("Next {}", step))
          .set_id(next_key);
        action_row.add_component_v2(next_button);
      }

      auto text = dpp::component().set_type(dpp::cot_text_display);
      std::ostringstream ss;
      for (auto const [idx, song_freq] : std::views::enumerate(song_frequencies) | std::views::drop(start_idx) | std::views::take(step)) {
        auto song = lookup_song(song_freq.song_name);
        if (song) {
          std::println(ss, "{}. `{:2d}x` {}", idx + 1, song_freq.count, *song);
        } else {
          std::println(ss, "{}. `{:2d}x` {}", idx + 1, song_freq.count, song_freq.song_name); // FIXME: METEOR & Meteor
        }
      }
      text.set_content(ss.str());
      msg.add_component_v2(text);
      msg.add_component_v2(action_row);

      return msg;
    };

    if (auto conf = co_await event.co_reply(make_msg()); conf.is_error()) {
      freq_failure_counter->Increment();
      co_return util::reply_handler(conf, ctx);
    }

    do {
      auto when_any_result = co_await dpp::when_any{
        event.owner->co_sleep(5 * 60), // 5 minutes
        event.owner->on_button_click.when([next_key, prev_key](const auto& click) {
          return click.custom_id == next_key || click.custom_id == prev_key;})};
      if (when_any_result.index() == 0) {
        // 5 min Timeout
        break;
      } else {
        const auto &click_event = when_any_result.get<1>();
        if (click_event.custom_id == next_key) {
          start_idx += step;
          start_idx = std::clamp(start_idx, 0UZ, song_frequencies.size());
        } else if (click_event.custom_id == prev_key) {
          start_idx -= step;
          start_idx = std::clamp(start_idx, 0UZ, song_frequencies.size());
        }

        if (auto conf = co_await click_event.co_reply(dpp::ir_deferred_update_message, dpp::message{}); conf.is_error()) {
          freq_failure_counter->Increment();
          co_return util::reply_handler(conf, ctx);
        }
        if (auto conf = co_await event.co_edit_original_response(make_msg()); conf.is_error()) {
          freq_failure_counter->Increment();
          co_return util::reply_handler(conf, ctx);
        }
      }
    } while (true);

    freq_success_counter->Increment();
    co_return {};
}

std::expected<dpp::interaction_response, std::error_code>
freq_command::on_autocomplete(const dpp::autocomplete_t& event)
{
  return std::unexpected(std::make_error_code(std::errc::invalid_argument));
}
