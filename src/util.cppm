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

module;

export module util;

import std;
import uni_algo;
import magic_enum;

using namespace std::literals;

namespace {
    std::generator<char> escape_markdown_gen(std::string_view input) {
        for (char c : input) {
            switch (c) {
                case '*':
                case '`':
                case '_':
                case '~':
                case '#':
                case '-':
                case '[':
                case ']':
                case '(':
                case ')':
                case '|':
                case '>':
                case '\\':
//            case '+':
//            case '.':
//            case '!':*/
                    co_yield '\\'; // Yield the escape character
                    break;
                default:
                    break;
            }
            co_yield c; // Yield the original character
        }
    }

}

export namespace util
{
    std::string escape_markdown(std::string_view input) {
        return escape_markdown_gen(input) | std::ranges::to<std::string>();
    }

    constexpr auto
    to_nfkc_casefold(std::string_view s) noexcept
    {
        return una::cases::to_casefold_utf8(una::norm::to_nfkc_utf8(s));
    }

    template<auto Proj>
    constexpr auto make_casefold_proj()
    {
        return [](const auto& obj) constexpr {
            const auto &val = std::invoke(Proj, obj);
            if constexpr (std::is_same_v<std::remove_cvref_t<decltype(obj)>, std::optional<std::string_view>>) {
                return val.transform(&util::to_nfkc_casefold);
            } else {
                return util::to_nfkc_casefold(val);
            }
        };
    }

    template<auto Proj, typename T>
    constexpr auto make_needle_filter(T&& needle)
    {
        return std::views::filter([needle = std::forward<T>(needle)](const auto& obj) constexpr -> bool {
            const auto &val = std::invoke(Proj, obj);
            if constexpr (std::is_same_v<std::remove_cvref_t<decltype(val)>, std::optional<std::string_view>>) {
                if (val.has_value()) {
                    return needle == *val;
                }
                return false;
            } else {
                return needle == val;
            }
        });
    }


    template <std::size_t Extent, typename Range>
    consteval auto to_array(const Range & range) {
        using value_type = std::ranges::range_value_t<Range>;
        static_assert(std::default_initializable<value_type>);
        assert(range.size() == Extent);

        // I can't use std::copy / std::ranges::copy as the result can have const (like pair from map)
        return [&]<std::size_t... Idx>(std::index_sequence<Idx...>) {
            auto it = range.begin();
            return std::array<value_type, Extent>{((void)Idx, *it++)...};
        }(std::make_index_sequence<Extent>());
    }

    template <auto callback>
    requires (std::invocable<decltype(callback)>) consteval auto materialize() {
        constexpr std::size_t extent = callback().size();
        return to_array<extent>(callback());
    }



}
