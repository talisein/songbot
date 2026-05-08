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

import util;
import songs;
import songbot.errors;
import vocadb.api;
import vocadb.songs;

#include "producer_command.hpp"
#include "context.hpp"
#include "formatters.hpp"

namespace
{
  using namespace std::literals;
  constexpr std::string_view ID_PREFIX {"id:"sv};

  // Returns deduplicated producer artists from vocadb data whose name or aliases
  // contain needle (case-insensitive). Empty needle matches all producers.
  std::vector<vocadb::artist_t> match_vocadb_artists(std::string_view needle)
  {
    auto cf_needle = util::to_nfkc_casefold(needle);
    std::map<std::uint64_t, vocadb::artist_t> artist_map;

    for (const auto& vsong : vocadb::songs) {
      for (const auto& sa : vsong.artists) {
        if (!sa.artist.has_value()) continue;
        if (!sa.categories.contains("Producer"sv)) continue;
        const auto& a = *sa.artist;
        if (artist_map.contains(a.id)) continue;

        bool matches = cf_needle.empty();
        if (!matches && a.name.has_value()) {
          auto cf = util::to_nfkc_casefold(*a.name);
          matches = std::ranges::contains_subrange(cf, cf_needle);
        }
        if (!matches && a.additional_names.has_value()) {
          auto cf = util::to_nfkc_casefold(*a.additional_names);
          matches = std::ranges::contains_subrange(cf, cf_needle);
        }

        if (matches) {
          artist_map.emplace(a.id, a);
        }
      }
    }

    auto result = artist_map | std::views::values | std::ranges::to<std::vector>();
    std::ranges::sort(result, {}, [](const vocadb::artist_t& a) {
      return a.name.value_or(""sv);
    });
    return result;
  }

  // Returns all vocadb song IDs that list the given artist in their artist credits.
  std::vector<std::uint64_t> vocadb_song_ids_for_artist(const vocadb::artist_t& artist)
  {
    std::vector<std::uint64_t> ids;
    for (const auto& vsong : vocadb::songs) {
      for (const auto& sa : vsong.artists) {
        if (sa.artist.has_value() && sa.artist->id == artist.id) {
          ids.push_back(vsong.id);
          break;
        }
      }
    }
    return ids;
  }

  std::string_view artist_role_in_song(std::uint64_t vocadb_song_id, std::uint64_t artist_id)
  {
    auto it = std::ranges::find(vocadb::songs, vocadb_song_id, &vocadb::song::id);
    if (it == std::ranges::end(vocadb::songs)) return {};
    auto sa = std::ranges::find_if(it->artists, [artist_id](const vocadb::song_artists& sa) {
      return sa.artist.has_value() && sa.artist->id == artist_id;
    });
    if (sa == std::ranges::end(it->artists)) return {};
    return sa->roles;
  }

  std::optional<vocadb::artist_t> find_vocadb_artist(std::uint64_t id)
  {
    for (const auto& vsong : vocadb::songs) {
      for (const auto& sa : vsong.artists) {
        if (sa.artist.has_value() && sa.artist->id == id) {
          return sa.artist;
        }
      }
    }
    return std::nullopt;
  }
}

producer_command::producer_command(context &ctx) noexcept :
    iface_command(ctx, "producer", "Show songs for a VocaDB producer")
{
    producer_success_counter = &ctx.slashcommand_counter->Add({{"command", "producer"}, {"result", "success"}});
    producer_failure_counter = &ctx.slashcommand_counter->Add({{"command", "producer"}, {"result", "failure"}});

    ac_producer_success_counter = &ctx.autocompletion_counter->Add({{"event", "producer"}, {"result", "success"}});
    ac_producer_no_match_counter = &ctx.autocompletion_counter->Add({{"event", "producer"}, {"result", "no-match"}});
    ac_producer_failure_counter = &ctx.autocompletion_counter->Add({{"event", "producer"}, {"result", "failure"}});

    prometheus::Histogram::BucketBoundaries buckets {0.0001, 0.00025, 0.0005, 0.001, 0.0025, 0.005, 0.01, 0.025, 0.05, 0.1, 0.25, 0.5, 1.0};
    prometheus::Labels labels {{"command", "producer"}};
    autocomplete_latency = &ctx.autocomplete_latency->Add(labels, buckets);
}

dpp::slashcommand
producer_command::get_command()
{
    auto cmd = iface_command::get_command();
    auto opt = dpp::command_option(dpp::command_option_type::co_string, "producer", "Name of producer, e.g. DECO*27", true);
    opt.set_auto_complete(true);
    cmd.add_option(std::move(opt));
    return cmd;
}

dpp::task<std::expected<void, std::error_code>>
producer_command::on_slashcommand(const dpp::slashcommand_t event)
{
    auto param = std::get<std::string>(event.get_parameter("producer"));
    std::optional<vocadb::artist_t> artist;
    std::string error_message;

    if (param.starts_with(ID_PREFIX)) {
        std::string_view sv = param;
        sv.remove_prefix(ID_PREFIX.size());
        std::uint64_t id;
        if (auto [ptr, ec] = std::from_chars(sv.data(), sv.data() + sv.size(), id); ec != std::errc{}) {
            error_message = "I'm sorry, I couldn't parse that producer ID.";
        } else {
            artist = find_vocadb_artist(id);
            if (!artist.has_value()) {
                error_message = "I'm sorry, I couldn't find that producer.";
            }
        }
    } else {
        auto matches = match_vocadb_artists(param);
        if (matches.empty()) {
            error_message = "I'm sorry, I don't know a producer by that name.";
        } else if (matches.size() == 1) {
            artist = matches.front();
        } else {
            std::ostringstream ss;
            std::print(ss, "{} producers match '{}', including {}", matches.size(), param,
                       matches.front().name.value_or("(unknown)"));
            for (const auto& a : matches | std::views::drop(1) | std::views::take(4)) {
                std::print(ss, ", {}", a.name.value_or("(unknown)"));
            }
            ss << "...";
            error_message = ss.str();
        }
    }

    if (!error_message.empty()) {
        auto msg = dpp::message(error_message).set_flags(dpp::message_flags::m_ephemeral);
        auto e = co_await util::reply_handler_new(event.co_reply(msg), ctx, producer_success_counter, producer_failure_counter);
        co_return std::unexpected(e.error_or(songbot_error::no_match));
    }

    auto vocadb_ids = vocadb_song_ids_for_artist(*artist);
    auto song_list = songs
        | std::views::filter([&](const Song& s) {
            return s.vocadb_id.has_value() && std::ranges::contains(vocadb_ids, *s.vocadb_id);
          })
        | std::ranges::to<std::vector>();
    std::ranges::sort(song_list, {}, &Song::name);

    std::ostringstream ss;
    std::print(ss, "**{}**", artist->name.value_or("(unknown)"));
    std::print(ss, " | [VocaDB](https://vocadb.net/Ar/{})\n", artist->id);
    if (artist->additional_names.has_value() && !artist->additional_names->empty()) {
        std::print(ss, "-# {}\n", *artist->additional_names);
    }

    if (song_list.empty()) {
        ss << "\nNo songs in the concert database.";
    } else {
        constexpr auto MAX_SONGS = 30Z;
        std::print(ss, "{} Live Songs:\n", song_list.size());
        for (const auto& song : song_list | std::views::take(MAX_SONGS)) {
            auto role = artist_role_in_song(*song.vocadb_id, artist->id);
            if (role.empty() || role == "Default"sv) {
                std::print(ss, "- {}\n", song);
            } else {
                std::print(ss, "- {} *({})*\n", song, role);
            }
        }
        if (std::cmp_greater(song_list.size(), MAX_SONGS)) {
            std::print(ss, "-# ...and {} more", song_list.size() - MAX_SONGS);
        }
    }

    auto msg = dpp::message().set_flags(dpp::message_flags::m_using_components_v2).suppress_embeds(true);
    auto text = dpp::component().set_type(dpp::cot_text_display).set_content(ss.str());
    msg.add_component_v2(text);

    co_return co_await util::reply_handler_new(event.co_reply(msg), ctx, producer_success_counter, producer_failure_counter);
}

std::expected<dpp::interaction_response, std::error_code>
producer_command::on_autocomplete_impl(const dpp::autocomplete_t& event)
{
    for (auto& opt : event.options | std::views::filter(&dpp::command_option::focused)) {
        try {
            std::string uservalue = std::get<std::string>(opt.value);
            auto matches = match_vocadb_artists(uservalue);
            if (matches.empty()) {
                return std::unexpected(songbot_error::autocomplete_no_match);
            }

            auto resp = dpp::interaction_response(dpp::ir_autocomplete_reply);
            for (const auto& a : matches | std::views::take(AUTOCOMPLETE_MAX_CHOICES)) {
                auto name = std::string(a.name.value_or("(unknown)"));
                auto value = std::format("{}{}", ID_PREFIX, a.id);
                resp.add_autocomplete_choice(dpp::command_option_choice(name, value));
            }
            return resp;
        } catch (std::bad_variant_access& e) {
            ctx->bot->log(dpp::ll_error, std::format("/producer: autocomplete error: {}", e.what()));
            return std::unexpected(std::make_error_code(std::errc::invalid_argument));
        }
    }
    return std::unexpected(songbot_error::autocomplete_no_focused_option);
}

std::expected<dpp::interaction_response, std::error_code>
producer_command::on_autocomplete(const dpp::autocomplete_t& event)
{
    const auto start = std::chrono::high_resolution_clock::now();
    auto res = on_autocomplete_impl(event);
    const auto end = std::chrono::high_resolution_clock::now();
    autocomplete_latency->Observe(std::chrono::duration_cast<std::chrono::duration<double>>(end - start).count());
    if (res) {
        ac_producer_success_counter->Increment();
    } else {
        bool is_no_match = res.error().category() == get_songbot_error_category() &&
            res.error().value() == std::to_underlying(songbot_error::autocomplete_no_match);
        if (is_no_match) {
            ac_producer_no_match_counter->Increment();
        } else {
            ac_producer_failure_counter->Increment();
        }
    }
    return res;
}
