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

/* Kept out of util so the data modules don't depend on dpp or prometheus */
export module reply_handler;

import std;
import dpp;
import songbot.errors;
import prometheus;

export namespace util
{
    template <typename Awaitable, typename Context>
    dpp::task<std::expected<void, std::error_code>>
    reply_handler_new(Awaitable&& awaitable, Context& ctx, prometheus::Counter* success_counter, prometheus::Counter* failure_counter, std::source_location src = std::source_location::current()) {
      if (auto conf = co_await awaitable; conf.is_error())
      {
        if (failure_counter) failure_counter->Increment();
        ctx->log_error("{}:{} reply error: {:d}", src.function_name(), src.line(), conf.get_error());
        co_return std::unexpected(songbot_error::reply_failure);
      }
      if (success_counter) success_counter->Increment();
      co_return {};
    }
}
