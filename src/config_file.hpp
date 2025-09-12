import std;

struct config
{
    std::string api_token;
};

std::expected<config, std::exception_ptr> get_config(std::string_view filename = "config.ini");
