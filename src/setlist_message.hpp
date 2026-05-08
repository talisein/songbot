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
import concerts;

class context;

std::vector<std::string> get_header_lines(const Concert& concert);
bool can_post_setlist_publicly(const dpp::slashcommand_t& event, const context& ctx);
bool is_concert_spoiler(const Concert& concert);

/* Builder for a setlist Discord reply. Inherits dpp::component (the body
 * cot_container) and tracks character count so build_messages() can split
 * across multiple follow-up messages when needed. */
class setlist_message : public dpp::component {
public:
    explicit setlist_message(const Concert& concert, bool suppress_spoiler = false);
    void set_header(const std::vector<std::string>& header_lines, const Concert& concert);
    void set_body(std::string_view body_text);
    size_t char_count() const { return header_char_count + body_char_count; }
    [[nodiscard]] dpp::message to_message(bool use_ephemeral,
                                          std::optional<std::string> reveal_button_id,
                                          std::optional<std::string> no_spoiler_button_id = std::nullopt) const;
    [[nodiscard]] static std::vector<dpp::message> build_messages(
        const Concert& concert,
        const std::vector<std::string>& header_lines,
        const std::vector<std::string>& body_lines,
        bool use_ephemeral,
        std::optional<std::string> reveal_button_id,
        std::optional<std::string> no_spoiler_button_id = std::nullopt,
        bool suppress_spoiler = false);

private:
    size_t header_char_count = 0;
    size_t body_char_count = 0;
    bool is_spoiler;
    std::optional<dpp::component> header_section;

    struct Thumbnail {
        std::string filename;
        std::string_view raw_data;
        std::string mime;
    };
    std::optional<Thumbnail> thumbnail;
};

template<typename Event>
dpp::task<std::expected<void, std::error_code>>
reply_and_followup(const Event& event, std::ranges::forward_range auto&& rng, context* ctx)
    requires std::same_as<std::ranges::range_value_t<decltype(rng)>, dpp::message>
{
    if (auto e = co_await util::reply_handler_new(event.co_reply(*std::ranges::begin(rng)), ctx, nullptr, nullptr);
        !e.has_value())
    {
        co_return e;
    }
    for (const auto& msg : rng | std::views::drop(1)) {
        auto e = co_await util::reply_handler_new(event.co_follow_up(msg), ctx, nullptr, nullptr);
        if (!e.has_value()) {
            co_return e;
        }
    }
    co_return {};
}
