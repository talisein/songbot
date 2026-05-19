#include "vocadb_song_model.hpp"
#include "song_item.hpp"
#include <peel/GLib/GLib.h>
#include <peel/Soup/Message.h>
#include <nlohmann/json.hpp>
#include <format>
#include <print>
#include <chrono>

using namespace peel;

static constexpr unsigned chunk_size = 205;
static constexpr auto fetch_cooldown = std::chrono::seconds(5);

namespace {
struct ChunkCtx { VocadbSongModel *self; unsigned start; };
}

void
VocadbSongModel::init_type(Type tp)
{
    PEEL_IMPLEMENT_INTERFACE(tp, Gio::ListModel);
}

void
VocadbSongModel::init_interface(Gio::ListModel::Iface *iface)
{
    iface->override_vfunc_get_item<VocadbSongModel>();
    iface->override_vfunc_get_item_type<VocadbSongModel>();
    iface->override_vfunc_get_n_items<VocadbSongModel>();
}

Type
VocadbSongModel::vfunc_get_item_type()
{
    return Type::of<SongItem>();
}

unsigned
VocadbSongModel::vfunc_get_n_items()
{
    return total_count;
}

RefPtr<GObject::Object>
VocadbSongModel::vfunc_get_item(unsigned position)
{
    if (position >= total_count) return nullptr;
    if (!items[position]) fetch_chunk((position / chunk_size) * chunk_size);
    return items[position];
}

void
VocadbSongModel::fetch_chunk(unsigned start)
{
    unsigned chunk_idx = start / chunk_size;
    if (chunks_in_flight.count(chunk_idx)) return;
    chunks_in_flight.insert(chunk_idx);

    /* Pre-fill with placeholders so vfunc_get_item never returns null for valid positions */
    unsigned end = std::min(start + chunk_size, total_count);
    for (unsigned i = start; i < end; ++i)
        if (!items[i]) items[i] = SongItem::create_placeholder();

    pending_chunks.push(start);
    if (!cooldown_source)
        schedule_next_chunk();
}

void
VocadbSongModel::schedule_next_chunk()
{
    if (pending_chunks.empty()) return;

    using namespace std::chrono;
    auto now = steady_clock::now();

    if (last_send_time == steady_clock::time_point{} || now >= last_send_time + fetch_cooldown) {
        unsigned start = pending_chunks.front();
        pending_chunks.pop();
        send_chunk_request(start);
        if (!pending_chunks.empty()) {
            cooldown_source = GLib::timeout_add_full(G_PRIORITY_DEFAULT,
                (unsigned)duration_cast<milliseconds>(fetch_cooldown).count(),
                [this]() -> bool {
                    cooldown_source = 0;
                    schedule_next_chunk();
                    return false;
                });
        }
    } else {
        auto delay = (last_send_time + fetch_cooldown) - now;
        cooldown_source = GLib::timeout_add_full(G_PRIORITY_DEFAULT,
            (unsigned)duration_cast<milliseconds>(delay).count(),
            [this]() -> bool {
                cooldown_source = 0;
                schedule_next_chunk();
                return false;
            });
    }
}

void
VocadbSongModel::send_chunk_request(unsigned start)
{
    last_send_time = std::chrono::steady_clock::now();

    auto escaped = GLib::Uri::escape_string(query.c_str(), nullptr, true);
    auto url = std::format(
        "https://vocadb.net/api/songs?query={}&start={}&maxResults={}&getTotalCount=true"
        "&fields=Artists,Names,MainPicture&nameMatchMode=Partial&sort=RatingScore&lang=English",
        escaped.c_str(), start, chunk_size);

    std::println("vocadb query: start={} query={}", start, query);
    auto msg = Soup::Message::create(SOUP_METHOD_GET, url.c_str());
    unsigned seq = search_seq;
    soup_session->send_and_read_async(
        msg, G_PRIORITY_DEFAULT, cancellable,
        [this, start, seq](GObject::Object *src, Gio::AsyncResult *res) {
            on_chunk_response(start, seq, src, res);
        });
}

void
VocadbSongModel::on_chunk_response(unsigned start, unsigned seq, GObject::Object *src, Gio::AsyncResult *res)
{
    std::println("vocadb response: start={} seq={} current={}", start, seq, search_seq);
    UniquePtr<GLib::Error> error;
    auto bytes = static_cast<Soup::Session*>(src)->send_and_read_finish(res, &error);
    if (error) {
        if (error->matches(G_IO_ERROR, G_IO_ERROR_CANCELLED)) return;
        std::println("VocadbSongModel error: {}", error->message);
        chunks_in_flight.erase(start / chunk_size);
        return;
    }
    if (seq != search_seq) {
        std::println("VocadbSongModel discarding stale response: start={} seq={}", start, seq);
        return;
    }

    auto data = bytes->get_data();
    std::string_view response{reinterpret_cast<const char*>(data.data()), data.size()};

    try {
        auto json = nlohmann::json::parse(response);
        if (!json.contains("items")) {
            std::println("VocadbSongModel unexpected response: {}", response);
            chunks_in_flight.erase(start / chunk_size);
            return;
        }
        const auto &json_items = json["items"];
        unsigned n = json_items.size();

        if (start == 0) {
            unsigned new_total = json.value("totalCount", 0u);
            total_count = new_total;
            items.resize(total_count);
            for (unsigned i = 0; i < n && i < total_count; ++i)
                items[i] = SongItem::create(json_items[i]);
            /* fetch_chunk(0) was called when total_count==0 so it skipped the pre-fill;
               fill the rest of this chunk now so vfunc_get_item never returns null
               while chunk 0 is still in chunks_in_flight during items_changed */
            unsigned chunk0_end = std::min(chunk_size, total_count);
            for (unsigned i = n; i < chunk0_end; ++i)
                items[i] = SongItem::create_placeholder();
            items_changed(0, 0, total_count);
            chunks_in_flight.erase(0u);
        } else {
            for (unsigned i = 0; i < n && start + i < total_count; ++i)
                items[start + i] = SongItem::create(json_items[i]);
            items_changed(start, n, n);
            chunks_in_flight.erase(start / chunk_size);
        }
    } catch (const std::exception &e) {
        std::println("VocadbSongModel parse error: {} — body: {}", e.what(), response);
        chunks_in_flight.erase(start / chunk_size);
    }
}

RefPtr<VocadbSongModel>
VocadbSongModel::create(Soup::Session *session)
{
    auto m = Object::create<VocadbSongModel>();
    m->soup_session = session;
    return m;
}

void
VocadbSongModel::search(const char *text)
{
    ++search_seq;
    if (cancellable) cancellable->cancel();
    if (cooldown_source) { GLib::Source::remove(cooldown_source); cooldown_source = 0; }
    pending_chunks = {};
    unsigned old_total = total_count;
    query = text;
    total_count = 0;
    items.clear();
    chunks_in_flight.clear();
    last_send_time = {};
    if (old_total > 0) items_changed(0, old_total, 0);
    cancellable = Gio::Cancellable::create();
    fetch_chunk(0);
}

void
VocadbSongModel::cancel()
{
    if (cancellable) cancellable->cancel();
    if (cooldown_source) { GLib::Source::remove(cooldown_source); cooldown_source = 0; }
    pending_chunks = {};
}

SongItem *
VocadbSongModel::get_song_item(unsigned pos) const
{
    if (pos < items.size()) return items[pos];
    return nullptr;
}

void VocadbSongModel::Class::init() {}
PEEL_CLASS_IMPL(VocadbSongModel, "SongSearcherVocadbSongModel", GObject::Object)
