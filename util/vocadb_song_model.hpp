#pragma once
#include <peel/GObject/Object.h>
#include <peel/Gio/ListModel.h>
#include <peel/Gio/Cancellable.h>
#include <peel/Gio/AsyncResult.h>
#include <peel/Soup/Session.h>
#include <peel/class.h>
#include <peel/RefPtr.h>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <chrono>

class SongItem;

class VocadbSongModel final : public peel::Gio::ListModel
{
    PEEL_SIMPLE_CLASS(VocadbSongModel, peel::GObject::Object);
    friend class peel::Gio::ListModel;

    static void init_type(peel::Type tp);
    static void init_interface(peel::Gio::ListModel::Iface *iface);

    peel::Soup::Session                   *soup_session = nullptr;
    std::string                            query;
    unsigned                               total_count = 0;
    std::vector<peel::RefPtr<SongItem>>    items;
    std::set<unsigned>                     chunks_in_flight;
    peel::RefPtr<peel::Gio::Cancellable>   cancellable;

    peel::Type                             vfunc_get_item_type();
    unsigned                               vfunc_get_n_items();
    peel::RefPtr<peel::GObject::Object>    vfunc_get_item(unsigned position);

    std::chrono::steady_clock::time_point  last_send_time{};
    std::queue<unsigned>                   pending_chunks;
    guint                                  cooldown_source = 0;
    unsigned                               search_seq = 0;

    void fetch_chunk(unsigned start);
    void schedule_next_chunk();
    void send_chunk_request(unsigned start);
    void on_chunk_response(unsigned start, unsigned seq, peel::GObject::Object *, peel::Gio::AsyncResult *);

    void init(Class *) {}

public:
    static peel::RefPtr<VocadbSongModel> create(peel::Soup::Session *session);
    void search(const char *text);
    void cancel();
    SongItem *get_song_item(unsigned pos) const;
};
