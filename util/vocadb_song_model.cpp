#include "vocadb_song_model.hpp"
#include "song_item.hpp"
#include <peel/GLib/GLib.h>
#include <peel/Soup/Message.h>
#include <nlohmann/json.hpp>
#include <format>
#include <print>

using namespace peel;

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
    if (!items[position]) fetch_chunk((position / 20) * 20);
    return items[position];
}

void
VocadbSongModel::fetch_chunk(unsigned start)
{
    unsigned chunk_idx = start / 20;
    if (chunks_in_flight.count(chunk_idx)) return;
    chunks_in_flight.insert(chunk_idx);

    /* Pre-fill with placeholders so vfunc_get_item never returns null for valid positions */
    unsigned end = std::min(start + 20u, total_count);
    for (unsigned i = start; i < end; ++i)
        if (!items[i]) items[i] = SongItem::create_placeholder();

    auto escaped = GLib::Uri::escape_string(query.c_str(), nullptr, true);
    auto url = std::format(
        "https://vocadb.net/api/songs?query={}&start={}&maxResults=20&getTotalCount=true"
        "&fields=Artists,Names,MainPicture&nameMatchMode=Partial&sort=RatingScore&lang=English",
        escaped.c_str(), start);

    std::println("vocadb query: start={} query={}", start, query);
    auto msg = Soup::Message::create(SOUP_METHOD_GET, url.c_str());
    soup_session->send_and_read_async(
        msg, G_PRIORITY_DEFAULT, cancellable,
        [this, start](GObject::Object *src, Gio::AsyncResult *res) {
            on_chunk_response(start, src, res);
        });
}

void
VocadbSongModel::on_chunk_response(unsigned start, GObject::Object *src, Gio::AsyncResult *res)
{
    UniquePtr<GLib::Error> error;
    auto bytes = static_cast<Soup::Session*>(src)->send_and_read_finish(res, &error);
    if (error) {
        if (error->matches(G_IO_ERROR, G_IO_ERROR_CANCELLED)) return;
        std::println("VocadbSongModel error: {}", error->message);
        chunks_in_flight.erase(start / 20);
        return;
    }

    auto data = bytes->get_data();
    std::string_view response{reinterpret_cast<const char*>(data.data()), data.size()};

    try {
        auto json = nlohmann::json::parse(response);
        const auto &json_items = json["items"];
        unsigned n = json_items.size();

        if (start == 0) {
            unsigned new_total = json.value("totalCount", 0u);
            total_count = new_total;
            items.resize(total_count);
            for (unsigned i = 0; i < n && i < total_count; ++i)
                items[i] = SongItem::create(json_items[i]);
            chunks_in_flight.erase(0u);
            items_changed(0, 0, total_count);
        } else {
            for (unsigned i = 0; i < n && start + i < total_count; ++i)
                items[start + i] = SongItem::create(json_items[i]);
            chunks_in_flight.erase(start / 20);
            items_changed(start, n, n);
        }
    } catch (const std::exception &e) {
        std::println("VocadbSongModel parse error: {}", e.what());
        chunks_in_flight.erase(start / 20);
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
    if (cancellable) cancellable->cancel();
    unsigned old_total = total_count;
    query = text;
    total_count = 0;
    items.clear();
    chunks_in_flight.clear();
    if (old_total > 0) items_changed(0, old_total, 0);
    cancellable = Gio::Cancellable::create();
    fetch_chunk(0);
}

void
VocadbSongModel::cancel()
{
    if (cancellable) cancellable->cancel();
}

SongItem *
VocadbSongModel::get_song_item(unsigned pos) const
{
    if (pos < items.size()) return items[pos];
    return nullptr;
}

void VocadbSongModel::Class::init() {}
PEEL_CLASS_IMPL(VocadbSongModel, "SongSearcherVocadbSongModel", GObject::Object)
