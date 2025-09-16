#pragma once

import std;

enum class songbot_error : int
{
    invalid_config_file,
    missing_api_token,
    autocomplete_no_match,
    autocomplete_no_focused_option,
    explosion
};

class songbot_error_category : public std::error_category {
public:
    const char* name() const noexcept override;
    std::string message(int ev) const override;
};

const std::error_category& get_songbot_error_category() noexcept;

namespace std {
    template <>
    struct is_error_code_enum<songbot_error> : public true_type {};
}

std::error_code make_error_code(songbot_error e) noexcept;
