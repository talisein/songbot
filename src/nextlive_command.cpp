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
import vocadb.events;

#include "nextlive_command.hpp"
#include "context.hpp"
#include "formatters.hpp"

namespace {
    std::string
    discord_timestamp(const std::chrono::sys_seconds sys_time)
    {
      return std::format("<t:{}:F>", sys_time.time_since_epoch().count());
    }

    std::string
    discord_timestamp_relative(const std::chrono::sys_seconds sys_time)
    {
      return std::format("<t:{}:R>", sys_time.time_since_epoch().count());
    }
}

nextlive_command::nextlive_command(context &ctx) noexcept :
    iface_command(ctx, "nextlive", "Get the date and location for the next live")
{
    /* Metric: freq command */
    nextlive_success_counter = &ctx.slashcommand_counter->Add({{"command", "nextlive"}, {"result", "success"}});
    nextlive_failure_counter = &ctx.slashcommand_counter->Add({{"command", "nextlive"}, {"result", "failure"}});
}

dpp::slashcommand
nextlive_command::get_command()
{
    auto nextlive_cmd = iface_command::get_command();

    auto series_opt = dpp::command_option(dpp::command_option_type::co_string, "tour", "Name of tour, e.g. ME2026NA", false);
    for (const auto& c : std::views::all(concerts) | std::views::filter([now = std::chrono::system_clock::now()](const auto &c) {
      using namespace std::literals;
      return now < static_cast<std::chrono::sys_days>(c.last_date.value_or(c.date));
    }))
    {
      series_opt.add_choice(dpp::command_option_choice(std::string(magic_enum::enum_name(c.short_name)), std::string(magic_enum::enum_name(c.short_name))));
    }

    nextlive_cmd.add_option(std::move(series_opt));

    return nextlive_cmd;
}

dpp::task<std::expected<void, std::error_code>>
nextlive_command::on_slashcommand(const dpp::slashcommand_t event)
{
  using namespace std::literals;
  const auto v = event.get_parameter("tour");
  std::optional<ConcertTour> requested_tour = std::holds_alternative<std::string>(v) ? magic_enum::enum_cast<ConcertTour>(std::get<std::string>(v)) : std::nullopt;

  const auto now = std::chrono::system_clock::now();
  const auto in_future = [now](const live_event& e) { return now < e.start_time.get_sys_time(); };
  const auto match_tour = [requested_tour](const live_event& e) { if (!requested_tour) return true; return *requested_tour == e.tour; };
  auto rng = std::views::all(get_live_events()) | std::views::filter(in_future) | std::views::filter(match_tour) | std::views::take(1);
  if (std::ranges::empty(rng)) {
    auto msg = dpp::message("I'm not yet aware of the next event.").set_flags(dpp::message_flags::m_ephemeral);
    co_return co_await util::reply_handler_new(event.co_reply(msg), ctx, nextlive_success_counter, nextlive_failure_counter);
  }

  const auto e = *std::ranges::begin(rng);
  const auto c = lookup_concert(e.tour);
  auto msg = dpp::message().set_flags(dpp::message_flags::m_using_components_v2).suppress_embeds(true);
  std::ostringstream ss;
  std::println(ss, "The next {}{}live is [{}](https://vocadb.net/E/{}) at [{}]({})",
               requested_tour?magic_enum::enum_name(*requested_tour):""sv,
               requested_tour?" "sv:""sv,
               c->name, e.vocadb_id, e.location_name, e.location_link);
  std::println(ss, "{} {}", discord_timestamp(e.start_time.get_sys_time()), discord_timestamp_relative(e.start_time.get_sys_time()));
  auto remaining = e.start_time.get_sys_time() - now;
  if (remaining > 24h) {
    const auto days = std::chrono::floor<std::chrono::days>(remaining);
    remaining -= days;
    const auto hours = std::chrono::floor<std::chrono::hours>(remaining);
    std::print(ss, "{} day", days.count());
    if (days >= 48h) ss << 's';
    if (hours > 0h) {
      std::print(ss, " and {} hour", hours.count());
      if (hours > 1h) ss << 's';
    }
    std::print(ss, " remaining!");
  }

  auto section = dpp::component().set_type(dpp::cot_section);
  auto text = dpp::component().set_type(dpp::cot_text_display).set_content(ss.str());

  if (auto it = std::ranges::find_if(vocadb::events, [id = c->vocadb_event_id](const auto &event) { return event.id == id; });
      it != std::ranges::end(vocadb::events) &&
      it->main_picture.original &&
      it->main_picture.original->size() > 0)
  {
    std::string_view data{reinterpret_cast<const char *>(it->main_picture.original->data()), it->main_picture.original->size_bytes()};
    std::string filename = std::format("{}.{}", it->id, it->main_picture.original_file_ext.size() > 0 ? it->main_picture.original_file_ext : "jpg"sv);
    auto mime = it->main_picture.original_mime_type;
    if (mime.size() == 0 && it->main_picture.mime) {
      mime = it->main_picture.mime.value();
    }
    msg.add_file(filename, data, mime);
    section.set_accessory(dpp::component().set_type(dpp::cot_thumbnail).set_thumbnail(std::format("attachment://{}", filename)));
    section.add_component_v2(text);
    msg.add_component_v2(section);
  } else {
    msg.add_component_v2(text);
  }

  co_return co_await util::reply_handler_new(event.co_reply(msg), ctx, nextlive_success_counter, nextlive_failure_counter);
}

std::expected<dpp::interaction_response, std::error_code>
nextlive_command::on_autocomplete(const dpp::autocomplete_t& event)
{
  return std::unexpected(std::make_error_code(std::errc::invalid_argument));
}
