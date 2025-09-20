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

import std;

#include "context.hpp"

template <typename StoredArguments>
class state_storage
{
public:
    using keyspace_t = std::uint64_t;
    using key_t = std::string;
    using key_view_t = std::string_view;

    state_storage(context& ctx) : rng(ctx.rng_engine)
    {
        ctx.bot->start_timer([this](const auto& timer) { clean(); }, 5 * 60 /* Seconds */);
    }

    key_t insert(StoredArguments&& args) {
        auto k = dist(rng.get());
        key_t key = std::to_string(k);

        store.emplace(std::piecewise_construct,
                      std::forward_as_tuple(key),
                      std::forward_as_tuple(std::forward<StoredArguments>(args), std::chrono::steady_clock::now()));

        return key;
    }

    std::optional<StoredArguments> get(const key_t& key) const {
        auto it = store.find(key);
        if (it != std::cend(store)) {
            return std::make_optional<StoredArguments>(it->second.stored_args);
        } else {
            return std::nullopt;
        }
    };

private:
    void clean() {
        const auto now = std::chrono::steady_clock::now();
        const auto five_minutes_ago = now - std::chrono::minutes(5);
        std::erase_if(store, [&](const auto& pair) {
            return pair.second.timestamp < five_minutes_ago;
        });
    }

    struct args {
        StoredArguments stored_args;
        std::chrono::steady_clock::time_point timestamp;
    };
    std::map<key_t, args> store;

    std::reference_wrapper<decltype(std::declval<context>().rng_engine)> rng;
    std::uniform_int_distribution<keyspace_t> dist;
};
