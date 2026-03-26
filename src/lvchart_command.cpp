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
import localvoid;

#include "lvchart_command.hpp"
#include "context.hpp"
#include "formatters.hpp"

namespace
{
  auto sheetname_to_ymw(const auto& json)
  {
    // "sheetName": "2024_7_4"
    std::stringstream ss { json["sheetName"].template get<std::string>() };
    std::chrono::year_month_day ymd; // its not actually a day but a week number.
    std::chrono::from_stream(ss, "%Y_%m_%d", ymd);
    unsigned w = static_cast<unsigned>(ymd.day());

    std::chrono::year_month_weekday res { ymd.year(), ymd.month(), std::chrono::Thursday[w] };

    return res;
  };

}

lvchart_command::lvchart_command(context &ctx) noexcept :
    iface_command(ctx, "lvchart", "Localvoid's Weekly Vocaloid Song Chart")
{
    /* Metric: lvchart command */
    lvchart_success_counter = &ctx.slashcommand_counter->Add({{"command", "lvchart"}, {"result", "success"}});
    lvchart_failure_counter = &ctx.slashcommand_counter->Add({{"command", "lvchart"}, {"result", "failure"}});
}

dpp::slashcommand
lvchart_command::get_command()
{
    auto lvchart_cmd = iface_command::get_command();

    return lvchart_cmd;
}


dpp::task<std::expected<void, std::error_code>>
lvchart_command::on_slashcommand(const dpp::slashcommand_t event)
{
    using namespace std::literals;
    auto start_idx = 0UZ;
    constexpr auto step = 25UZ;
    const auto next_key = ctx->keygen();
    const auto prev_key = ctx->keygen();

    std::ostringstream ss;
    std::string user_locale_str = event.command.locale;
    std::replace(user_locale_str.begin(), user_locale_str.end(), '-', '_');
    try {
      std::locale user_loc(user_locale_str + ".UTF-8");
      ss.imbue(user_loc);
    } catch (const std::exception& e) {
      ctx->log_info("Couldn't set user locale {}: {}", user_locale_str, e.what());
      ss.imbue(std::locale(""));
    }

    using json = nlohmann::json;
    const auto chart = json::parse(localvoid::charts.back());
    const auto songs = chart["songs"];
    const auto is_not_out = [](const auto& song) -> bool { return !song["isOut"].template get<bool>(); };
    const size_t total_in_songs = std::ranges::distance(std::views::filter(songs, is_not_out));
    const ssize_t max_view_width = std::format("{:+Ld}", std::views::filter(songs, is_not_out).begin()->at("viewIncrease").template get<ssize_t>()).size();

    auto make_msg = [&] (bool include_buttons){
      auto msg = dpp::message().set_flags(dpp::message_flags::m_using_components_v2 | dpp::message_flags::m_ephemeral).suppress_embeds(true);
      auto action_row = dpp::component().set_type(dpp::cot_action_row);
      if (start_idx > 0) {
        auto prev_button = dpp::component().set_type(dpp::cot_button)
          .set_style(dpp::cos_primary)
          .set_label(std::format("Prev {}", step))
          .set_id(prev_key);
        action_row.add_component_v2(prev_button);
      }
      if ((start_idx + step) < total_in_songs) {
        auto next_button = dpp::component().set_type(dpp::cot_button)
          .set_style(dpp::cos_primary)
          .set_label(std::format("Next {}", step))
          .set_id(next_key);
        action_row.add_component_v2(next_button);
      }

      auto text = dpp::component().set_type(dpp::cot_text_display);
      ss.str("");
      ss.clear();
      const auto ymd = sheetname_to_ymw(chart);
      std::println(ss, "## [Localvoid](https://lvchart.com)'s Vocaloid Song Chart for {:%B} {:%Y} (Week {})", ymd, ymd, ymd.index());
      for (const auto& song : std::views::filter(songs, is_not_out) | std::views::drop(start_idx) | std::views::take(step)) {
        auto rank           = song["rank"].template get<int>();
        auto views          = song["viewIncrease"].template get<std::int64_t>();
        auto title          = song["title"].template get<std::string>();
        auto video_url      = song["videoUrl"].template get<std::string>();
        auto english_title  = song["englishTitle"].template get<std::string>();
        auto english_artist = song["englishArtist"].template get<std::string>();
        auto artist         = song["artist"].template get<std::string>();
        std::print(ss, "{}. `{:+{}Ld}` [", rank, views, max_view_width);
        if (!english_title.empty()) {
          std::print(ss, "{}", english_title);
        } else {
          std::print(ss, "{}", title);
        }
        std::print(ss, "]({}) by ", video_url);
        if (!english_artist.empty()) {
          std::print(ss, "{}", english_artist);
        } else {
          std::print(ss, "{}", artist);
        }
        ss << '\n';
      }
      text.set_content(ss.str());
      msg.add_component_v2(text);
      if (include_buttons) {
        msg.add_component_v2(action_row);
      }

      return msg;
    };

    if (auto expected = co_await util::reply_handler_new(event.co_reply(make_msg(true)), ctx, nullptr, lvchart_failure_counter); !expected) {
      co_return expected;
    }

    do {
      auto when_any_result = co_await dpp::when_any{
        event.owner->co_sleep(5 * 60), // 5 minutes
        event.owner->on_button_click.when([next_key, prev_key](const auto& click) {
          return click.custom_id == next_key || click.custom_id == prev_key;})};
      if (when_any_result.index() == 0) {
        // 5 min Timeout
        co_return co_await util::reply_handler_new(event.co_edit_original_response(make_msg(false)), ctx, lvchart_success_counter, lvchart_failure_counter);
      } else {
        const auto &click_event = when_any_result.get<1>();
        if (click_event.custom_id == next_key) {
          start_idx = std::add_sat(start_idx, step);
          start_idx = std::clamp(start_idx, 0UZ, std::sub_sat(total_in_songs, 1UZ));
        } else if (click_event.custom_id == prev_key) {
          start_idx = std::sub_sat(start_idx, step);
        }


        if (auto expected = co_await util::reply_handler_new(click_event.co_reply(dpp::ir_deferred_update_message, dpp::message{}), ctx, nullptr, lvchart_failure_counter); !expected) {
          co_return expected;
        }
        if (auto expected = co_await util::reply_handler_new(event.co_edit_original_response(make_msg(true)), ctx, nullptr, lvchart_failure_counter); !expected) {
          co_return expected;
        }
      }
    } while (true);

    co_return {};
}

std::expected<dpp::interaction_response, std::error_code>
lvchart_command::on_autocomplete(const dpp::autocomplete_t& event)
{
  return std::unexpected(std::make_error_code(std::errc::invalid_argument));
}
