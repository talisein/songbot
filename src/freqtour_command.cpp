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
import magic_enum;

#include "freqtour_command.hpp"
#include "context.hpp"
#include "formatters.hpp"

freqtour_command::freqtour_command(context &ctx) noexcept :
    iface_command(ctx, "freqtour", "List the most frequent live songs for a concert series")
{
    /* Metric: freq command */
    freqtour_success_counter = &ctx.slashcommand_counter->Add({{"command", "freqtour"}, {"result", "success"}});
    freqtour_failure_counter = &ctx.slashcommand_counter->Add({{"command", "freqtour"}, {"result", "failure"}});
}

dpp::slashcommand
freqtour_command::get_command()
{
    auto freqtour_cmd = iface_command::get_command();

    auto series_opt = dpp::command_option(dpp::command_option_type::co_string, "series", "Name of tour series, e.g. MIKU_EXPO", true);
    constexpr std::array supported { MIKU_EXPO, MAGICAL_MIRAI, MIKUPA, MIKU_WITH_YOU, SNOW_MIKU };
    for (const auto& s : supported) {
      series_opt.add_choice(dpp::command_option_choice(std::string(magic_enum::enum_name(s)), std::string(magic_enum::enum_name(s))));
    }

    freqtour_cmd.add_option(std::move(series_opt));

    return freqtour_cmd;
}


dpp::task<std::expected<void, std::error_code>>
freqtour_command::on_slashcommand(const dpp::slashcommand_t event)
{
    using namespace std::literals;
    auto start_idx = 0UZ;
    constexpr auto step = 25UZ;
    const auto next_key = ctx->keygen();
    const auto prev_key = ctx->keygen();

    constexpr auto freqs_for_series = [](ConcertSeries series) constexpr -> std::span<const song_frequency, std::dynamic_extent> {
      switch (series) {
        case MIKU_EXPO: return song_frequencies_expo;
        case MAGICAL_MIRAI: return song_frequencies_mirai;
        case MIKU_WITH_YOU: return song_frequencies_mwy;
        case MIKUPA: return song_frequencies_mikupa;
        case SNOW_MIKU: return song_frequencies_snowmiku;
        default:
        throw songbot_error::no_match;
      }
    };


    ConcertSeries series;
    std::span<const song_frequency, std::dynamic_extent> queried_frequencies;
    try {
      const auto series_str = std::get<std::string>(event.get_parameter("series"));
      auto series_opt = magic_enum::enum_cast<ConcertSeries>(series_str, magic_enum::case_insensitive);

      if (!series_opt.has_value()) {
        dpp::message m{std::format("I'm sorry, I don't know about a concert series named '{}'", series_str)};
        m.set_flags(dpp::message_flags::m_ephemeral);
        auto res = co_await event.co_reply(m);
        freqtour_failure_counter->Increment();
        co_return std::unexpected(util::reply_handler(res, ctx).error_or(songbot_error::no_match));
      } else {
        queried_frequencies = freqs_for_series(*series_opt);
        series = *series_opt;
      }
    } catch(std::exception &e) {
      dpp::message m{std::format("I'm sorry, I couldn't understand what concert series you asked about.")};
      m.set_flags(dpp::message_flags::m_ephemeral);
      event.reply(m);
      freqtour_failure_counter->Increment();
      co_return std::unexpected(songbot_error::no_match);
    } catch(songbot_error &e) {
      dpp::message m{std::format("I'm sorry, I don't have frequency data for that series.")};
      m.set_flags(dpp::message_flags::m_ephemeral);
      event.reply(m);
      freqtour_failure_counter->Increment();
      co_return std::unexpected(songbot_error::no_match);
    }

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
      if ((start_idx + step) < queried_frequencies.size()) {
        auto next_button = dpp::component().set_type(dpp::cot_button)
          .set_style(dpp::cos_primary)
          .set_label(std::format("Next {}", step))
          .set_id(next_key);
        action_row.add_component_v2(next_button);
      }

      auto text = dpp::component().set_type(dpp::cot_text_display);
      std::ostringstream ss;
      std::println(ss, "# Song Frequency for Tour Series {}", magic_enum::enum_name(series));
      for (auto const [idx, song_freq] : std::views::enumerate(queried_frequencies) | std::views::drop(start_idx) | std::views::take(step)) {
        auto song = lookup_song(song_freq.song_name, song_freq.producer);
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
      freqtour_failure_counter->Increment();
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
          start_idx = std::add_sat(start_idx, step);
          start_idx = std::clamp(start_idx, 0UZ, std::sub_sat(queried_frequencies.size(), 1UZ));
        } else if (click_event.custom_id == prev_key) {
          start_idx = std::sub_sat(start_idx, step);
        }

        if (auto conf = co_await click_event.co_reply(dpp::ir_deferred_update_message, dpp::message{}); conf.is_error()) {
          freqtour_failure_counter->Increment();
          co_return util::reply_handler(conf, ctx);
        }
        if (auto conf = co_await event.co_edit_original_response(make_msg()); conf.is_error()) {
          freqtour_failure_counter->Increment();
          co_return util::reply_handler(conf, ctx);
        }
      }
    } while (true);

    freqtour_success_counter->Increment();
    co_return {};
}

std::expected<dpp::interaction_response, std::error_code>
freqtour_command::on_autocomplete(const dpp::autocomplete_t& event)
{
  return std::unexpected(std::make_error_code(std::errc::invalid_argument));
/*  constexpr std::array supported { MIKU_EXPO, MAGICAL_MIRAI, MIKUPA, MIKU_WITH_YOU, SNOW_MIKU };
  auto resp = dpp::interaction_response(dpp::ir_autocomplete_reply);
   for (const auto& s : supported) {
     resp.add_autocomplete_choice(dpp::command_option_choice(std::string(magic_enum::enum_name(s)), std::string(magic_enum::enum_name(s))));
  }

  return resp;*/
}
