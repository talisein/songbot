# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

Songbot is a Discord bot for querying a database of Hatsune Miku songs that appeared in live concerts (Miku Expo, Magical Mirai, Snow Miku, etc.). The song and concert databases are implemented as compile-time `constexpr std::array` structures in C++26 modules — data is static and baked in at compile time rather than loaded from a runtime database.

## Build Commands

```bash
meson setup build                          # Configure build directory
meson compile -C build                     # Compile the project
meson test -C build                        # Run all tests
meson test -C build --test-args="-v"       # Run tests verbosely
```

To build the VocaDB scraper/data generator (only needed when regenerating song/concert data):
```bash
meson setup build -Dbuild_anidb_sourcegen=true
meson compile -C build
```

## Architecture

### Module System

The project uses C++26 modules extensively. There are three categories:

1. **Domain modules** (`src/*.cppm`) — `songs`, `concerts`, `util`, `errors` — define the core data types and logic.
2. **Wrapper modules** (`src/prometheus.cppm`, `src/dpp.cppm`, `src/magic_enum.cppm`, `src/uni_algo.cppm`) — wrap third-party library headers into modules for clean importing.
3. **Generated data modules** (`src/vocadb/gen/*.cppm`) — `vocadb_songs`, `release_events`, `localvoid_charts` — contain the actual constexpr arrays of song and concert data. These are checked into the repo and should not be hand-edited; regenerate via the scraper.

The build system configures a `module.mapper` to resolve module names to file paths for GCC.

### Command Handling

Each Discord slash command is a class implementing the interface in `src/iface_command.hpp`. Commands implement `on_slashcommand()` (a `dpp::task<void>` coroutine) and optionally `on_autocomplete()`. Commands are registered and dispatched through `src/context.hpp/cpp`.

New commands follow the pattern: create `src/{name}_command.hpp` and `src/{name}_command.cpp`, then register in `context.cpp` and add to `meson.build`.

### Data Pipeline

The scraper tool (`src/vocadb/`) queries the VocaDB API and generates `.cppm` files for the `gen/` directory. Run it with `build_anidb_sourcegen=true`, execute the resulting binary, then commit the updated generated files. The generated data is committed to avoid scraping on every build.

### Dependencies

- **D++ (dpp)** — Discord bot framework; async ops use `dpp::task<void>` coroutines
- **magic_enum** — Enum reflection for virtual singer enums
- **uni-algo** — Unicode normalization for song name matching
- **prometheus-cpp** — Metrics/monitoring
- **libsystemd** — `sd_notify` readiness notification
- **boost::ut** — Unit test framework (compiled as a module in `test/ut.cppm`)

## Testing

Tests live in `test/` and use Boost.UT. Tests exercise the constexpr data structures (songs, concerts) and can validate compile-time correctness. Add new test files to `test/meson.build`.

## C++ Style Notes

- C++26 standard; use modules (`import`) rather than headers where possible
- Async command handlers must be `dpp::task<void>` coroutines
- Song/concert data additions go in `src/vocadb/gen/` (via scraper) or by hand-editing the constexpr arrays if small
