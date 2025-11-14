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

namespace std {

template<>
struct formatter<dpp::error_detail>
{
public:
    using context_type = std::format_context;

    template <class ParseContext>
    constexpr auto parse(ParseContext& ctx) -> ParseContext::iterator
    {
        auto it = ctx.begin();
        if (it != ctx.end() && *it != '}') {
            throw std::format_error("Invalid format args for dpp::error_detail.");
        }

        return it;
    }

    template <class FmtContext>
    constexpr auto format(const dpp::error_detail& ed, FmtContext& ctx) const -> FmtContext::iterator
    {
        return std::format_to(ctx.out(), ctx.locale(), "dpp::error_detail{{ code={}, field={}, object={}, reason={} }}",
                              ed.code, ed.field, ed.object, ed.reason);
    }

};


template<>
struct formatter<dpp::error_info>
{
private:
    bool dev_output = false;
public:
    using context_type = std::format_context;

    template <class ParseContext>
    constexpr auto parse(ParseContext& ctx) -> ParseContext::iterator {
        auto it = ctx.begin();
        if (it != ctx.end() && *it == 'd') {
            dev_output = true;
            ++it;
        }

        if (it != ctx.end() && *it != '}') {
            throw std::format_error("Invalid format args for dpp::error_info.");
        }

        return it;
    }

    template <class FmtContext>
    constexpr auto format(const dpp::error_info& ei, FmtContext& ctx) const -> FmtContext::iterator {
        if (dev_output) {
            return std::format_to(ctx.out(), ctx.locale(), "dpp::error_info{{ code={}, errors={}, human_readable={}, message={} }}",
                                  ei.code, std::views::all(ei.errors), ei.human_readable, ei.message);
        } else {
            return std::ranges::copy(ei.human_readable, ctx.out()).out;
        }
    }

};

} // namespace std
