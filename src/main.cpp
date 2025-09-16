import std;

#include "context.hpp"

int
main()
{
    context ctx("config.ini");

    ctx.bot->start(dpp::st_wait);

    return 0;
}
