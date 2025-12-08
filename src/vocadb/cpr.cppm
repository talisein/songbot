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

export module cpr;
export import <cpr/cpr.h>;
import std;

export namespace cpr {
  constexpr auto FLAG_URLDECODE = CURLU_URLDECODE;
  constexpr auto FLAG_DEFAULT_SCHEME = CURLU_DEFAULT_SCHEME;
  constexpr auto FLAG_PUNYCODE = CURLU_PUNYCODE;

  class curlu_error_category : public std::error_category {
  public:
      const char* name() const noexcept override
      {
          return "curlu_errors";
      }

      std::string message(int ev) const override
      {
          const auto code = static_cast<CURLUcode>(ev);
          return std::format("CURLUcode {}: {}", static_cast<std::underlying_type_t<CURLUcode>>(code), curl_url_strerror(code));
      }
  };

  class curl_error_category : public std::error_category {
  public:
      const char* name() const noexcept override
      {
          return "curl_errors";
      }

      std::string message(int ev) const override
      {
          const auto code = static_cast<CURLcode>(ev);
          return std::format("CURLcode {}: {}", static_cast<std::underlying_type_t<CURLcode>>(code), curl_easy_strerror(code));
      }
  };

  const std::error_category& get_curlu_error_category() noexcept
  {
      static const curlu_error_category instance;
      return instance;
  }

  const std::error_category& get_curl_error_category() noexcept
  {
      static const curl_error_category instance;
      return instance;
  }

}

export namespace std {
  template <>
  struct is_error_code_enum<CURLUcode> : public true_type {};
  template <>
  struct is_error_code_enum<CURLcode> : public true_type {};

  std::error_code make_error_code(CURLUcode e) noexcept
  {
      return { static_cast<int>(std::to_underlying(e)), cpr::get_curlu_error_category() };
  }
  std::error_code make_error_code(CURLcode e) noexcept
  {
      return { static_cast<int>(std::to_underlying(e)), cpr::get_curl_error_category() };
  }
}

export namespace cpr {
  std::expected<void, std::error_code> set_ifmodsince(cpr::Session& session,
                                                      const std::chrono::time_point<std::chrono::system_clock>& tp)
  {
    auto holder = session.GetCurlHolder();
    long tv { std::chrono::system_clock::to_time_t(tp) };
    auto rc = curl_easy_setopt(holder->handle, CURLOPT_TIMEVALUE, tv);
    if (CURLE_OK != rc) return std::unexpected(std::make_error_code(rc));
    rc = curl_easy_setopt(holder->handle, CURLOPT_TIMECONDITION, (long)CURL_TIMECOND_IFMODSINCE);
    if (CURLE_OK != rc) return std::unexpected(std::make_error_code(rc));
    return {};
  }
}
