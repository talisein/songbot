#include "primary_song_data_cell.hpp"
#include "song_item.hpp"
#include <peel/GLib/GLib.h>
#include <peel/GObject/GObject.h>
#include <peel/Gtk/Gtk.h>
#include <peel/widget-template.h>
#include <format>

using namespace peel;

void
PrimarySongDataCell::Class::init()
{
    override_vfunc_dispose<PrimarySongDataCell>();
    set_template_from_resource("/bot/hatsune/SongSearcher/primary_song_data_cell.ui");
    PEEL_WIDGET_TEMPLATE_BIND_CHILD(PrimarySongDataCell, m.name_label,     "name-label");
    PEEL_WIDGET_TEMPLATE_BIND_CHILD(PrimarySongDataCell, m.artist_label,   "artist-label");
    PEEL_WIDGET_TEMPLATE_BIND_CHILD(PrimarySongDataCell, m.vocalist_label, "vocalist-label");
}

void
PrimarySongDataCell::init(Class *)
{
    new (&m) Members;
    init_template();
}

void
PrimarySongDataCell::vfunc_dispose()
{
    dispose_template(Type::of<PrimarySongDataCell>());
    parent_vfunc_dispose<PrimarySongDataCell>();
}

FloatPtr<PrimarySongDataCell>
PrimarySongDataCell::create()
{
    return Object::create<PrimarySongDataCell>();
}

void
PrimarySongDataCell::bind(SongItem *song)
{
    int sid = song->get_id();
    name_bind = Object::bind_property(
        song, SongItem::prop_name(),
        m.name_label, Gtk::Label::prop_label(),
        GObject::BindingFlags::SYNC_CREATE,
        [sid](const char *name) -> peel::String {
            auto escaped = GLib::markup_escape_text(name, -1);
            auto link = std::format("<a href=\"https://vocadb.net/S/{}\">{}</a>", sid, escaped.c_str());
            return peel::String(link.c_str());
        });
    artist_bind = Object::bind_property(
        song, SongItem::prop_artist(),
        m.artist_label, Gtk::Label::prop_label(),
        GObject::BindingFlags::SYNC_CREATE);
    vocalist_bind = Object::bind_property(
        song, SongItem::prop_vocalists(),
        m.vocalist_label, Gtk::Label::prop_label(),
        GObject::BindingFlags::SYNC_CREATE);
}

void
PrimarySongDataCell::unbind()
{
    if (name_bind)     { name_bind->unbind();     name_bind = {}; }
    if (artist_bind)   { artist_bind->unbind();   artist_bind = {}; }
    if (vocalist_bind) { vocalist_bind->unbind(); vocalist_bind = {}; }
}

PEEL_CLASS_IMPL(PrimarySongDataCell, "SongSearcherPrimarySongDataCell", Gtk::Box)
