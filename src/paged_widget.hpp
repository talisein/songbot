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
#pragma once

import std;
import dpp;
import util;
import prometheus;

#include "context.hpp"

template<std::invocable<size_t> MakePageFn>
    requires std::convertible_to<std::invoke_result_t<MakePageFn, size_t>, std::string>
dpp::task<std::expected<void, std::error_code>>
run_paged_widget(
    const dpp::slashcommand_t& event,
    context* ctx,
    size_t total_count,
    size_t step,
    MakePageFn&& make_page,
    prometheus::Counter* success_counter,
    prometheus::Counter* failure_counter)
{
    const auto next_key = ctx->keygen();
    const auto prev_key = ctx->keygen();
    size_t start_idx = 0;

    auto make_msg = [&](bool include_buttons) {
        auto msg = dpp::message()
            .set_flags(dpp::message_flags::m_using_components_v2 | dpp::message_flags::m_ephemeral)
            .suppress_embeds(true);
        auto action_row = dpp::component().set_type(dpp::cot_action_row);
        if (start_idx > 0)
            action_row.add_component_v2(dpp::component().set_type(dpp::cot_button)
                .set_style(dpp::cos_primary)
                .set_label(std::format("Prev {}", step))
                .set_id(prev_key));
        if ((start_idx + step) < total_count)
            action_row.add_component_v2(dpp::component().set_type(dpp::cot_button)
                .set_style(dpp::cos_primary)
                .set_label(std::format("Next {}", step))
                .set_id(next_key));
        msg.add_component_v2(dpp::component().set_type(dpp::cot_text_display)
            .set_content(std::string(make_page(start_idx))));
        if (include_buttons)
            msg.add_component_v2(action_row);
        return msg;
    };

    if (auto e = co_await util::reply_handler_new(event.co_reply(make_msg(true)), ctx, nullptr, failure_counter); !e)
        co_return e;

    do {
        auto result = co_await dpp::when_any{
            event.owner->co_sleep(5 * 60),
            event.owner->on_button_click.when([next_key, prev_key](const auto& click) {
                return click.custom_id == next_key || click.custom_id == prev_key;
            })};
        if (result.index() == 0) {
            co_return co_await util::reply_handler_new(
                event.co_edit_original_response(make_msg(false)), ctx, success_counter, failure_counter);
        } else {
            const auto& click = result.template get<1>();
            if (click.custom_id == next_key)
                start_idx = std::clamp(std::saturating_add(start_idx, step), 0UZ, std::saturating_sub(total_count, 1UZ));
            else
                start_idx = std::saturating_sub(start_idx, step);
            if (auto e = co_await util::reply_handler_new(
                    click.co_reply(dpp::ir_deferred_update_message, dpp::message{}), ctx, nullptr, failure_counter); !e)
                co_return e;
            if (auto e = co_await util::reply_handler_new(
                    event.co_edit_original_response(make_msg(true)), ctx, nullptr, failure_counter); !e)
                co_return e;
        }
    } while (true);
}
