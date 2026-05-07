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
import vocadb.events;
import uni_algo;

#include "setlist_message.hpp"
#include "context.hpp"

namespace {
    constexpr size_t DISCORD_REPLY_LIMIT = 4000UZ;
}

std::vector<std::string>
get_header_lines(const Concert& concert)
{
    std::vector<std::string> headers;
    headers.push_back(std::format("## {}", concert.name));
    if (concert.last_date) {
        if (concert.date.year() != concert.last_date->year()) {
            headers.push_back(std::format("{:%A, %e %B %Y} – {:%A, %e %B %Y}", concert.date, *concert.last_date));
        } else if (concert.date.month() != concert.last_date->month()) {
            headers.push_back(std::format("{:%A, %b %e} – {:%A, %b %e %Y}", concert.date, *concert.last_date));
        } else {
            headers.push_back(std::format("{:%B %e (%a)}–{:%e (%a) %Y}", concert.date, *concert.last_date));
        }
    } else {
        headers.push_back(std::format("{:%A, %e %B %Y}", concert.date));
    }
    if (auto it = std::ranges::find(vocadb::events, concert.vocadb_event_id, &decltype(vocadb::events)::value_type::id);
        it != std::ranges::end(vocadb::events))
    {
        using namespace std::literals;
        std::vector<std::string> links;
        const auto is_official_weblink = [](const auto &link) static -> bool {
            return link.description.has_value() && link.url.has_value() && (
                0 == una::caseless::compare_utf8("Website (EN)"sv, *link.description) ||
                0 == una::caseless::compare_utf8("Website"sv, *link.description) ||
                0 == una::caseless::compare_utf8("Official website"sv, *link.description) ||
                0 == una::caseless::compare_utf8("mikuexpo.com"sv, *link.description) ||
                0 == una::caseless::compare_utf8("Official Page"sv, *link.description) ||
                0 == una::caseless::compare_utf8("Official Webpage"sv, *link.description));
        };
        for (const auto &link : std::views::filter(it->web_links, is_official_weblink) | std::views::take(1))
        {
            links.push_back(std::format("[Offical Website]({})", *link.url));
        }
        links.push_back(std::format("[VocaDB](https://vocadb.net/E/{}/{})", it->id, it->url_slug));
        const auto is_vocawiki_weblink = [](const auto &link) static -> bool {
            return link.url.has_value() && (
                una::caseless::find_utf8(*link.url, "vocaloid.wikia.com"sv) ||
                una::caseless::find_utf8(*link.url, "vocaloid.fandom.com"sv));
        };
        for (const auto &link : std::views::filter(it->web_links, is_vocawiki_weblink) | std::views::take(1))
        {
            links.push_back(std::format("[VocaWiki]({})", *link.url));
        }
        headers.push_back(std::format("-# {}", std::views::join_with(links, " — "sv) | std::ranges::to<std::string>()));
    }
    return headers;
}

setlist_message::setlist_message(const Concert& concert)
{
    using namespace std::literals;
    is_spoiler = (std::chrono::system_clock::now() -
                  static_cast<std::chrono::sys_days>(concert.last_date.value_or(concert.date))) < 36h;
    this->set_type(dpp::cot_container);
    this->set_accent(dpp::utility::rgb(134, 206, 203));
    if (is_spoiler) {
        this->set_spoiler(true);
    }
}

void
setlist_message::set_header(const std::vector<std::string>& header_lines, const Concert& concert)
{
    auto section = dpp::component().set_type(dpp::cot_section);
    for (const auto& line : header_lines) {
        section.add_component_v2(dpp::component().set_type(dpp::cot_text_display).set_content(line));
        header_char_count += line.size();
    }

    if (concert.vocadb_event_id) {
        auto it = std::ranges::find_if(vocadb::events, [id = concert.vocadb_event_id](const auto& event) {
            return event.id == id;
        });
        if (it != std::ranges::end(vocadb::events) &&
            it->main_picture.original &&
            it->main_picture.original->size() > 0)
        {
            using namespace std::literals;
            Thumbnail thumb;
            thumb.raw_data = std::string_view{
                reinterpret_cast<const char*>(it->main_picture.original->data()),
                it->main_picture.original->size_bytes()};
            thumb.filename = std::format("{}.{}", it->id,
                it->main_picture.original_file_ext.size() > 0
                    ? it->main_picture.original_file_ext : "jpg"sv);
            thumb.mime = it->main_picture.original_mime_type;
            if (thumb.mime.size() == 0 && it->main_picture.mime) {
                thumb.mime = it->main_picture.mime.value();
            }
            section.set_accessory(
                dpp::component().set_type(dpp::cot_thumbnail)
                    .set_thumbnail(std::format("attachment://{}", thumb.filename)));
            thumbnail = std::move(thumb);
        }
    }

    header_section = std::move(section);
}

void
setlist_message::set_body(std::string_view body_text)
{
    this->add_component_v2(
        dpp::component().set_type(dpp::cot_text_display).set_content(std::string(body_text)));
    body_char_count += body_text.size();
}

dpp::message
setlist_message::to_message(bool use_ephemeral, std::optional<std::string> reveal_button_id) const
{
    const auto flags = dpp::message_flags::m_using_components_v2 |
                       (use_ephemeral ? dpp::message_flags::m_ephemeral : 0);
    auto real_msg = dpp::message().set_flags(flags);

    if (thumbnail) {
        real_msg.add_file(thumbnail->filename, thumbnail->raw_data, thumbnail->mime);
    }

    if (reveal_button_id.has_value()) {
        auto action_row = dpp::component().set_type(dpp::cot_action_row);
        auto button     = dpp::component().set_type(dpp::cot_button)
                          .set_style(dpp::cos_primary)
                          .set_label("Post Publicly")
                          .set_id(reveal_button_id.value());
        action_row.add_component_v2(button);
        real_msg.add_component_v2(action_row);
    }

    if (header_section) {
        real_msg.add_component_v2(*header_section);
    }

    if (is_spoiler) {
        real_msg.add_component_v2(
            dpp::component().set_type(dpp::cot_text_display).set_content("Setlist Spoilers Below:"));
    }

    real_msg.add_component_v2(*this);
    return real_msg;
}

std::vector<dpp::message>
setlist_message::build_messages(
    const Concert& concert,
    const std::vector<std::string>& header_lines,
    const std::vector<std::string>& body_lines,
    bool use_ephemeral,
    std::optional<std::string> reveal_button_id)
{
    const size_t header_size = std::ranges::fold_left(
        std::views::transform(header_lines, &std::string::size),
        0UZ, std::plus<size_t>());

    std::vector<std::string> chunks;
    std::ostringstream current;
    size_t current_header_size = header_size;

    for (const auto& line : body_lines) {
        if ((current.view().size() + line.size() + current_header_size) >= DISCORD_REPLY_LIMIT) {
            if (!current.view().empty()) {
                chunks.emplace_back(current.view());
                current.str({});
            }
            current_header_size = 0;
        }
        current << line;
    }
    if (!current.view().empty()) {
        chunks.emplace_back(current.view());
    }

    std::vector<dpp::message> result;
    result.reserve(chunks.size());
    for (size_t i = 0; i < chunks.size(); ++i) {
        setlist_message msg(concert);
        if (i == 0) {
            msg.set_header(header_lines, concert);
        }
        msg.set_body(chunks[i]);
        result.push_back(msg.to_message(use_ephemeral, i == 0 ? reveal_button_id : std::nullopt));
    }
    return result;
}
