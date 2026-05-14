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
#include "paged_widget.hpp"


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
    auto only_new_opt = dpp::command_option(dpp::command_option_type::co_boolean, "only_new", "Only show songs released last week", false);

    lvchart_cmd.add_option(std::move(only_new_opt));
    return lvchart_cmd;
}


dpp::task<std::expected<void, std::error_code>>
lvchart_command::on_slashcommand(const dpp::slashcommand_t event)
{
    using namespace std::literals;
    const auto only_new_param = event.get_parameter("only_new");
    const bool only_new = std::holds_alternative<bool>(only_new_param) && std::get<bool>(only_new_param);

    std::ostringstream ss;
    std::string user_locale_str = event.command.locale;
    std::replace(user_locale_str.begin(), user_locale_str.end(), '-', '_');
    std::locale l;
    try {
      std::locale user_loc(user_locale_str + ".UTF-8");
      ss.imbue(user_loc);
      l = user_loc;
    } catch (const std::exception& e) {
      ctx->log_info("Couldn't set user locale {}: {}", user_locale_str, e.what());
      l = std::locale("");
      ss.imbue(l);
    }

    using json = nlohmann::json;
    const auto chart = json::parse(localvoid::charts.back());
    const auto songs = chart["songs"];
    const auto is_not_out = [](const auto& song) -> bool { return !song["isOut"].template get<bool>(); };
    const auto passes_new_filter = [only_new](const auto& song) -> bool { return (!only_new) || song["isNew"].template get<bool>(); };
    const size_t total_in_songs = std::ranges::distance(std::views::filter(songs, is_not_out));
    const ssize_t max_view_width = std::format(l, "{:+Ld}", std::views::filter(songs, is_not_out).begin()->at("viewIncrease").template get<ssize_t>()).size();

    const auto ymd_result = util::parse_lvchart_sheetname(chart["sheetName"].template get<std::string>());
    if (!ymd_result)
        co_return std::unexpected(ymd_result.error());
    const auto& ymd = *ymd_result;
    const auto ymw = std::chrono::year_month_weekday{ymd.year(), ymd.month(), std::chrono::Thursday[static_cast<unsigned>(ymd.day())]};

    constexpr size_t step = 25;
    auto make_page = [&](size_t start_idx) -> std::string {
        ss.str(""); ss.clear();
        std::println(ss, "## [Localvoid](https://lvchart.com)'s Vocaloid Song Chart for {:%B} {:%Y} (Week {})", ymw, ymw, ymw.index());
        for (const auto& song : std::views::filter(songs, is_not_out)
                              | std::views::filter(passes_new_filter)
                              | std::views::drop(start_idx)
                              | std::views::take(step))
        {
            auto rank           = song["rank"].template get<int>();
            auto views          = song["viewIncrease"].template get<std::int64_t>();
            auto title          = song["title"].template get<std::string>();
            auto video_url      = song["videoUrl"].template get<std::string>();
            auto english_title  = song["englishTitle"].template get<std::string>();
            auto english_artist = song["englishArtist"].template get<std::string>();
            auto artist         = song["artist"].template get<std::string>();
            auto is_new         = song["isNew"].template get<bool>();
            std::print(ss, "- {}. `{:+{}Ld}` [", rank, views, max_view_width);
            if (!english_title.empty()) std::print(ss, "{}", english_title);
            else                        std::print(ss, "{}", title);
            std::print(ss, "]({}) by ", video_url);
            if (!english_artist.empty()) std::print(ss, "{}", english_artist);
            else                         std::print(ss, "{}", artist);
            if (is_new) std::print(ss, " **(NEW!)**");
            ss << '\n';
        }
        return ss.str();
    };
    co_return co_await run_paged_widget(event, ctx, total_in_songs, step, make_page,
                                        lvchart_success_counter, lvchart_failure_counter);
}

std::expected<dpp::interaction_response, std::error_code>
lvchart_command::on_autocomplete(const dpp::autocomplete_t& event)
{
  return std::unexpected(std::make_error_code(std::errc::invalid_argument));
}
