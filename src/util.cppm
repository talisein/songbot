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

#include <cassert>

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

    /* hanickadot's constexpr materialization
     * https://www.reddit.com/r/cpp/comments/1ideht3/comment/m9yz1x8/?utm_source=share&utm_medium=web3x&utm_name=web3xcss&utm_term=1&utm_content=share_button
     * https://compiler-explorer.com/z/55MxnGcPa
     */
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


/*************************** HERE BE DRAGONS ***********************************/
/* This function generates a static constexpr array<char> that holds the
 * casefolded version of all the Song names. Then then string_views are assigned
 * in the returned vector pointing into that array.
 *
 * https://compiler-explorer.com/z/E7n1T357T
 * https://youtu.be/_AefJX66io8
 *
 * Except we don't need to do this for only Songs, so its templated on fields...
 */
    template <std::invocable auto SourceBuilder,
              std::size_t NumOptionalSource,
              std::size_t NumSource,
              auto... SourceMembers>
    consteval auto generate_casefolded_fields() {
        constexpr auto source_members_tuple = std::tuple{SourceMembers...};

        const std::vector elems = std::invoke(SourceBuilder);
        std::array<char, 4096 * 4096> allchars; // Start with a sufficiently large array
        std::array<std::size_t, 4096> string_lengths;
        auto current = allchars.begin();
        std::size_t index = 0;

        for (const auto& elem : elems) {
            // Process optional source members
            [&]<std::size_t... Is>(std::index_sequence<Is...>) {
                ((
                    [&] {
                        if (const auto& str_opt = std::invoke(std::get<Is>(source_members_tuple), elem); str_opt) {
                            const auto casefolded = util::to_nfkc_casefold(*str_opt);
                            current = std::ranges::copy(casefolded, current).out;
                            string_lengths[index++] = casefolded.size();
                        } else {
                            string_lengths[index++] = 0UZ;
                        }
                    }()
                    ), ...);
            }(std::make_index_sequence<NumOptionalSource>{});

            // Process non-optional source members
            [&]<std::size_t... Js>(std::index_sequence<Js...>) {
                ((
                    [&] {
                        const auto casefolded = util::to_nfkc_casefold(std::invoke(std::get<Js + NumOptionalSource>(source_members_tuple), elem));
                        current = std::ranges::copy(casefolded, current).out;
                        string_lengths[index++] = casefolded.size();
                    }()
                    ), ...);
            }(std::make_index_sequence<NumSource - NumOptionalSource>{});
        }
        const auto total_chars = std::distance(allchars.begin(), current);

        // Return a tuple containing the over-sized array and the lengths.
        return std::tuple{allchars, string_lengths, total_chars, index};
    }

    template <typename Dest,
              std::invocable auto IncompleteDestBuilder,
              std::size_t NumOptionalDest,
              std::size_t NumDest,
              auto... Members>
    constexpr std::vector<Dest> merge_casefolded_fields_from_tuple(const auto& casefolded_tuple)
    {
        constexpr auto all_members_tuple = std::tuple{Members...};
        constexpr auto dest_members_tuple = [&]<std::size_t... Is>(std::index_sequence<Is...>) {
            return std::tuple{std::get<Is>(all_members_tuple)...};
        }(std::make_index_sequence<NumDest>{});

        const auto& right_sized_chars = std::get<0>(casefolded_tuple);
        const auto& string_lengths = std::get<1>(casefolded_tuple);

        std::vector<Dest> res = IncompleteDestBuilder();
        std::size_t start = 0;
        std::size_t index = 0;

        for (auto& dest_elem : res) {
            // Process optional destination members
            [&]<std::size_t... Is>(std::index_sequence<Is...>) {
                ((
                    [&] {
                        if (const auto size = string_lengths[index++]; size > 0) {
                            std::invoke(std::get<Is>(dest_members_tuple), dest_elem) = std::string_view{right_sized_chars.begin() + start, size};
                            start += size;
                        } else {
                            std::invoke(std::get<Is>(dest_members_tuple), dest_elem) = std::nullopt;
                        }
                    }()
                    ), ...);
            }(std::make_index_sequence<NumOptionalDest>{});

            // Process non-optional destination members
            [&]<std::size_t... Js>(std::index_sequence<Js...>) {
                ((
                    [&] {
                        const auto size = string_lengths[index++];
                        std::invoke(std::get<Js + NumOptionalDest>(dest_members_tuple), dest_elem) = std::string_view{right_sized_chars.begin() + start, size};
                        start += size;
                    }()
                    ), ...);
            }(std::make_index_sequence<NumDest - NumOptionalDest>{});
        }

        return res;
    }


}
