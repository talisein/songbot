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

}

/*

template<auto Builder, std::size_t MaxSize>
constexpr auto to_view() {
  // constexpr tuple of oversized things
  // we don't want this static yet
  constexpr auto data = [&]{
    const auto input = Builder();

    // we have no idea how big this will ultimately need to be
    // so we're taking the passed-in MaxSize per unit, and squaring it
    std::array<char, MaxSize * MaxSize> allchars{};

    std::array<std::size_t, MaxSize> string_lengths{};

    // save all of the string lengths and the set of packed characters
    auto current = allchars.begin();
    for (std::size_t index = 0; const auto &str : input) {
      current = std::ranges::copy(str, current).out;
      string_lengths[index++] = str.size();
    }
    const auto total_chars = std::distance(allchars.begin(), current);

    return std::tuple{input.size(), total_chars, allchars, string_lengths};
  }();

  constexpr auto total_chars = std::get<1>(data);

  // this is the only static thing, as it is the packed
  // set of characters that make up all of the strings, truncated
  // to exactly the right size
  static constexpr auto right_sized_chars = [&]{
    // this is the right-sized array, based on the previously
    // computed total string length
    std::array<char, total_chars> result;
    auto &allchars = std::get<2>(data);
    std::ranges::copy(allchars | std::views::take(total_chars), result.begin());
    return result;
  }();


  // now build and return an array of string_views into
  // that array of chars, based on the string sizes
  // that were saved in the very first IILE
  constexpr auto num_strings = std::get<0>(data);
  std::array<std::string_view, num_strings> views;
  std::size_t start = 0;
  auto &string_lengths = std::get<3>(data);
  for (std::size_t index = 0; index < num_strings; ++index) {
    const auto size = string_lengths[index];
    views[index] = std::string_view(right_sized_chars.begin() + start,
                                    right_sized_chars.begin() + start + size);
    start += size;
  }

  // for mega bonus points, we could probably de-duplicate strings and build
  // a new string table that reuses existing strings for the
  // string_views...

  return views;
}
*/
