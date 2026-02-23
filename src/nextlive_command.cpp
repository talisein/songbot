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
  std::chrono::time_zone const * JST;
  std::chrono::time_zone const * VANCOUVER_TZ;
  std::chrono::time_zone const * PST;
  std::chrono::time_zone const * PHOENIX_TZ;
  std::chrono::time_zone const * MST;
  std::chrono::time_zone const * DENVER_TZ;
  std::chrono::time_zone const * CST;
  std::chrono::time_zone const * EST;
  std::chrono::time_zone const * DETROIT_TZ;
  std::chrono::time_zone const * TORONTO_TZ;
  std::chrono::time_zone const * MEXICO_CITY_TZ;
  std::chrono::time_zone const * AUCKLAND_TZ;
  std::chrono::time_zone const * BRISBANE_TZ;
  std::chrono::time_zone const * SYDNEY_TZ;
  std::chrono::time_zone const * MELBOURNE_TZ;
  std::chrono::time_zone const * PERTH_TZ;
  std::chrono::time_zone const * BANGKOK_TZ;
  std::chrono::time_zone const * HONGKONG_TZ;
  std::chrono::time_zone const * JAKARTA_TZ;
  std::chrono::time_zone const * MANILA_TZ;
  std::chrono::time_zone const * SINGAPORE_TZ;
  std::chrono::time_zone const * KUALALUMPUR_TZ;
  std::chrono::time_zone const * TAIPEI_TZ;
  std::chrono::time_zone const * SEOUL_TZ;
  std::chrono::time_zone const * CHICAGO_TZ;
  std::chrono::time_zone const * LONDON_TZ;
  std::chrono::time_zone const * BRUSSELS_TZ;
  std::chrono::time_zone const * AMSTERDAM_TZ;
  std::chrono::time_zone const * BERLIN_TZ;
  std::chrono::time_zone const * DUSSELDORF_TZ;
  std::chrono::time_zone const * PARIS_TZ;
  std::chrono::time_zone const * MADRID_TZ;

  std::once_flag init_tz_flag;
  void init_timezones()
  {
    try {
      JST            = std::chrono::locate_zone("Asia/Tokyo");
      VANCOUVER_TZ   = std::chrono::locate_zone("America/Vancouver");
      PST            = std::chrono::locate_zone("America/Los_Angeles");
      PHOENIX_TZ     = std::chrono::locate_zone("America/Phoenix");
      MST            = std::chrono::locate_zone("America/Denver");
      DENVER_TZ      = std::chrono::locate_zone("America/Denver");
      CST            = std::chrono::locate_zone("America/Chicago");
      EST            = std::chrono::locate_zone("America/New_York");
      DETROIT_TZ     = std::chrono::locate_zone("America/Detroit");
      TORONTO_TZ     = std::chrono::locate_zone("America/Toronto");
      MEXICO_CITY_TZ = std::chrono::locate_zone("America/Mexico_City");
      AUCKLAND_TZ    = std::chrono::locate_zone("Pacific/Auckland");
      BRISBANE_TZ    = std::chrono::locate_zone("Australia/Brisbane");
      SYDNEY_TZ      = std::chrono::locate_zone("Australia/Sydney");
      MELBOURNE_TZ   = std::chrono::locate_zone("Australia/Melbourne");
      PERTH_TZ       = std::chrono::locate_zone("Australia/Perth");
      BANGKOK_TZ     = std::chrono::locate_zone("Asia/Bangkok");
      HONGKONG_TZ    = std::chrono::locate_zone("Asia/Hong_Kong");
      JAKARTA_TZ     = std::chrono::locate_zone("Asia/Jakarta");
      MANILA_TZ      = std::chrono::locate_zone("Asia/Manila");
      SINGAPORE_TZ   = std::chrono::locate_zone("Asia/Singapore");
      KUALALUMPUR_TZ = std::chrono::locate_zone("Asia/Kuala_Lumpur");
      TAIPEI_TZ      = std::chrono::locate_zone("Asia/Taipei");
      SEOUL_TZ       = std::chrono::locate_zone("Asia/Seoul");
      CHICAGO_TZ     = std::chrono::locate_zone("America/Chicago");
      LONDON_TZ      = std::chrono::locate_zone("Europe/London");
      BRUSSELS_TZ    = std::chrono::locate_zone("Europe/Brussels");
      AMSTERDAM_TZ   = std::chrono::locate_zone("Europe/Amsterdam");
      BERLIN_TZ      = std::chrono::locate_zone("Europe/Berlin");
      DUSSELDORF_TZ  = std::chrono::locate_zone("Europe/Berlin");
      PARIS_TZ       = std::chrono::locate_zone("Europe/Paris");
      MADRID_TZ      = std::chrono::locate_zone("Europe/Madrid");
    } catch (std::runtime_error &e) {
      std::println(std::cerr, "Failed to load required timezones. This is likely due to an incompatibility between the latest tzdb 20204b and GCC 14s stdlib, see bug 116657.\nSpecific error: {}\nTerminating", e.what());
      exit(1);
    }
  }

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
  std::call_once(init_tz_flag, init_timezones);
  using namespace std::literals;
  using std::chrono::local_days;
    events = {
      { VOLTAGE,  9613,  { JST,            local_days{2026y/3/20}  + 12h }, "LaLa arena TOKYO-BAY", "https://maps.app.goo.gl/xFEqpXcYepPaVM237" },
      { VOLTAGE,  9613,  { JST,            local_days{2026y/3/20}  + 18h }, "LaLa arena TOKYO-BAY", "https://maps.app.goo.gl/xFEqpXcYepPaVM237" },
      { VOLTAGE,  9613,  { JST,            local_days{2026y/3/21}  + 12h }, "LaLa arena TOKYO-BAY", "https://maps.app.goo.gl/xFEqpXcYepPaVM237" },
      { VOLTAGE,  9613,  { JST,            local_days{2026y/3/21}  + 18h }, "LaLa arena TOKYO-BAY", "https://maps.app.goo.gl/xFEqpXcYepPaVM237" },
      { VOLTAGE,  9613,  { JST,            local_days{2026y/3/22}  + 12h }, "LaLa arena TOKYO-BAY", "https://maps.app.goo.gl/xFEqpXcYepPaVM237" },
      { VOLTAGE,  9613,  { JST,            local_days{2026y/3/22}  + 18h }, "LaLa arena TOKYO-BAY", "https://maps.app.goo.gl/xFEqpXcYepPaVM237" },
      { ME2026NA, 9811,  { CHICAGO_TZ,     local_days{2026y/4/12}  + 20h }, "The Auditorium", "https://maps.app.goo.gl/P28CZKX5aN67CzDd6" },
      { ME2026NA, 9811,  { CHICAGO_TZ,     local_days{2026y/4/13}  + 20h }, "The Auditorium", "https://maps.app.goo.gl/P28CZKX5aN67CzDd6" },
      { ME2026NA, 9812,  { DENVER_TZ,      local_days{2026y/4/15}  + 20h }, "Mission Ballroom", "https://maps.app.goo.gl/B4yZexmBzc517P3F7" },
      { ME2026NA, 9813,  { VANCOUVER_TZ,   local_days{2026y/4/18}  + 20h }, "Doug Mitchell Thunderbird Sports Centre", "https://maps.app.goo.gl/qKD91YFLbUkc9V559" },
      { ME2026NA, 9814,  { PST,            local_days{2026y/4/20}  + 20h }, "WAMU Theater", "https://maps.app.goo.gl/bym2QCvo9JBZgukw6" },
      { ME2026NA, 9815,  { PST,            local_days{2026y/4/22}  + 20h }, "San Jose Civic", "https://maps.app.goo.gl/qPuR3TnKVfSKQbYt5" },
      { ME2026NA, 9815,  { PST,            local_days{2026y/4/23}  + 20h }, "San Jose Civic", "https://maps.app.goo.gl/qPuR3TnKVfSKQbYt5" },
      { ME2026NA, 9816,  { PST,            local_days{2026y/4/25}  + 20h }, "Peacock Theater", "https://maps.app.goo.gl/cNvgYsUXZKyD1psAA" },
      { ME2026NA, 9816,  { PST,            local_days{2026y/4/26}  + 20h }, "Peacock Theater", "https://maps.app.goo.gl/cNvgYsUXZKyD1psAA" },
      { ME2026NA, 9817,  { PHOENIX_TZ,     local_days{2026y/4/28}  + 20h }, "Desert Diamond Arena", "https://maps.app.goo.gl/4x3GqU7c84hNeb3G8" },
      { ME2026NA, 9818,  { CST,            local_days{2026y/4/30}  + 20h }, "Texas Trust CU Theatre", "https://maps.app.goo.gl/pDy6ARcbAMbh9VoN6" },
      { ME2026NA, 9819,  { CST,            local_days{2026y/5/1}   + 20h }, "H-E-B Center at Cedar Park", "https://maps.app.goo.gl/F2TqY3cRPpXs6vgL8" },
      { ME2026NA, 9820,  { EST,            local_days{2026y/5/3}   + 20h }, "Gas South Arena", "https://maps.app.goo.gl/mpStYrFULStsCLZz8" },
      { ME2026NA, 9821,  { EST,            local_days{2026y/5/5}   + 20h }, "The Anthem", "https://maps.app.goo.gl/5GHNFc4djSfgey3J9" },
      { ME2026NA, 9822,  { EST,            local_days{2026y/5/7}   + 20h }, "Prudencial Center", "https://maps.app.goo.gl/krmFYX3bx3ETjWoF6" },
      { ME2026NA, 9823,  { EST,            local_days{2026y/5/10}  + 20h }, "Wang Theatre at the Boch Center", "https://maps.app.goo.gl/dcsQsVz9ovb59vFUA" },
      { ME2026NA, 9823,  { EST,            local_days{2026y/5/11}  + 20h }, "Wang Theatre at the Boch Center", "https://maps.app.goo.gl/dcsQsVz9ovb59vFUA" },
      { ME2026NA, 9824,  { TORONTO_TZ,     local_days{2026y/5/13}  + 20h }, "TD Coliseum", "https://maps.app.goo.gl/erep1AemU7w9LrqY9" },
      { ME2026NA, 9825,  { MEXICO_CITY_TZ, local_days{2026y/5/19}  + 20h }, "Pepsi Center WTC", "https://maps.app.goo.gl/HTv12b5NkAHucHz47" },
      { ME2026EU, 12222, { LONDON_TZ,      local_days{2026y/11/12} + 20h }, "The O2", "https://maps.app.goo.gl/wc6fh8pVJogAUaWcA" },
      { ME2026EU, 12223, { BRUSSELS_TZ,    local_days{2026y/11/14} + 20h }, "ING Arena", "https://maps.app.goo.gl/qXoKyoWRaDYGWhJ4A" },
      { ME2026EU, 12224, { AMSTERDAM_TZ,   local_days{2026y/11/15} + 20h }, "AFAS Live", "https://maps.app.goo.gl/qNVDzeBM5vsT2rvj7" },
      { ME2026EU, 12225, { BERLIN_TZ,      local_days{2026y/11/17} + 20h }, "Velodrom", "https://maps.app.goo.gl/JxVfuKYQ11xtSfec7" },
      { ME2026EU, 12226, { DUSSELDORF_TZ,  local_days{2026y/11/20} + 20h }, "PSD Bank Dome", "https://maps.app.goo.gl/goJ2uA8sYsw8HPas9" },
      { ME2026EU, 12227, { PARIS_TZ,       local_days{2026y/11/22} + 20h }, "Accor Arena", "https://maps.app.goo.gl/WnapRimvbmGaGFc57" },
      { ME2026EU, 12228, { MADRID_TZ,      local_days{2026y/11/25} + 20h }, "Palacio Vistalegre", "https://maps.app.goo.gl/jBdeiWfbBmNx78R37" },
    };

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
  auto rng = std::views::all(events) | std::views::filter(in_future) | std::views::filter(match_tour) | std::views::take(1);
  if (std::ranges::empty(rng)) {
    auto msg = dpp::message("I'm not yet aware of the next event.").set_flags(dpp::message_flags::m_ephemeral);
    if (auto conf = co_await event.co_reply(msg); conf.is_error()) {
      nextlive_failure_counter->Increment();
      co_return util::reply_handler(conf, ctx);
    } else {
      nextlive_success_counter->Increment();
      co_return {};
    }
  }

  const auto e = *std::ranges::begin(rng);
  const auto c = lookup_concert(e.tour);
  auto msg = dpp::message().set_flags(dpp::message_flags::m_using_components_v2).suppress_embeds(true);
  std::ostringstream ss;
  std::println(ss, "The next live is [{}](https://vocadb.net/E/{}) at [{}]({})", c->name, e.vocadb_id, e.location_name, e.location_link);
  std::println(ss, "{} {}", discord_timestamp(e.start_time.get_sys_time()), discord_timestamp_relative(e.start_time.get_sys_time()));

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

  if (auto conf = co_await event.co_reply(msg); conf.is_error()) {
    nextlive_failure_counter->Increment();
    co_return util::reply_handler(conf, ctx);
  } else {
    nextlive_success_counter->Increment();
    co_return {};
  }
}

std::expected<dpp::interaction_response, std::error_code>
nextlive_command::on_autocomplete(const dpp::autocomplete_t& event)
{
  return std::unexpected(std::make_error_code(std::errc::invalid_argument));
}
