Songbot
=======

A Discord bot for querying a database of Hatsune Miku songs that have appeared
in live concerts (Miku Expo, Magical Mirai, Snow Miku Live, etc.).

The database is implemented as compile-time `constexpr std::array` structures in
C++26 modules — no runtime database, just static data baked in at compile time.
Song data is sourced from [VocaDB](https://vocadb.net/) via a scraper tool that
generates `.cppm` files checked into the repo.


Commands
--------

| Command | Description |
|---|---|
| `/last <song>` | Most recent concert where a song was played, with full history and frequency rank |
| `/setlist <event>` | Complete setlist for a concert event, with VocaDB links per song |
| `/setlistlast <event>` | Setlist annotated with each song's prior performance date or "LIVE DEBUT" |
| `/freq` | Top 25 most frequently performed songs across all concerts (paginated) |
| `/freqtour <series>` | Most frequently performed songs for a specific tour series (paginated) |
| `/nextlive [tour]` | Next upcoming concert with venue, date, and countdown |
| `/lvchart [only_new]` | Localvoid's weekly Vocaloid chart with view count changes (paginated) |

Setlists within 36 hours of a concert are marked as spoilers. The `/last`
command suppresses the most recent concert within the same window.


Building
--------

Requires Meson ≥ 1.4.0, GCC with C++26 support, and the following libraries:
`dpp`, `magic_enum`, `uni-algo`, `boost::ut`, `libsystemd`, `openssl`, `zlib`,
`prometheus-cpp`.

```sh
meson setup build
meson compile -C build
meson test -C build
```

To regenerate the song/concert database from VocaDB:

```sh
meson setup build -Dbuild_anidb_sourcegen=true
meson compile -C build
./build/vocadb_sourcegen   # writes src/vocadb/gen/*.cppm
```

The build system uses custom Meson targets to compile C++26 modules and may
require some environment-specific tuning.


Configuration
-------------

The bot reads `config.ini` from the working directory at startup.

```ini
[discord]
; Path to a file containing the Discord bot token (preferred over api_token)
api_token_file = /run/secrets/api_token

; Or inline (less preferred)
; api_token = <token>

; Path to a file containing the Discord application public key (for webhook verification)
public_key_file = /run/secrets/public_key

; Or inline
; public_key = <hex key>

; Discord user ID of the bot owner (receives startup/shutdown DMs)
owner_id = 123456789012345678
```

### Credential files

If `api_token` / `api_token_file` are absent from the ini, the bot falls back
to reading credentials from files named `api_token`, `public_key`, and
`owner_id` in the first of these directories that exists:

| Environment variable / path | Description |
|---|---|
| `$CREDENTIALS_DIRECTORY` | systemd `LoadCredential=` directory |
| `/run/secrets` | container secrets mount |
| `/var/run/secrets` | alternate container secrets mount |


Runtime
-------

The bot exposes a [Prometheus](https://prometheus.io/) metrics endpoint on port
**3927** and an optional webhook server on port **3939**. It integrates with
systemd (`sd_notify`) for readiness signalling.


License
-------

GNU General Public License v3.0 or later — see [COPYING](COPYING).
