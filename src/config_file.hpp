import std;

struct bot_config
{
    std::string api_token;
    std::optional<std::string> public_key;
};

std::expected<bot_config, std::exception_ptr> get_config(std::string_view filename = "config.ini");
