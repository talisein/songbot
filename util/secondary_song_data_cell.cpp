#include "secondary_song_data_cell.hpp"
#include "song_item.hpp"
#include <peel/GObject/GObject.h>
#include <peel/Gtk/Gtk.h>
#include <peel/widget-template.h>

using namespace peel;

void
SecondarySongDataCell::Class::init()
{
    override_vfunc_dispose<SecondarySongDataCell>();
    set_template_from_resource("/bot/hatsune/SongSearcher/secondary_song_data_cell.ui");
    PEEL_WIDGET_TEMPLATE_BIND_CHILD(SecondarySongDataCell, m.type_label,     "type-label");
    PEEL_WIDGET_TEMPLATE_BIND_CHILD(SecondarySongDataCell, m.date_label,     "date-label");
    PEEL_WIDGET_TEMPLATE_BIND_CHILD(SecondarySongDataCell, m.duration_label, "duration-label");
}

void
SecondarySongDataCell::init(Class *)
{
    new (&m) Members;
    init_template();
}

void
SecondarySongDataCell::vfunc_dispose()
{
    dispose_template(Type::of<SecondarySongDataCell>());
    parent_vfunc_dispose<SecondarySongDataCell>();
}

FloatPtr<SecondarySongDataCell>
SecondarySongDataCell::create()
{
    return Object::create<SecondarySongDataCell>();
}

void
SecondarySongDataCell::bind(SongItem *song)
{
    type_bind = Object::bind_property(
        song, SongItem::prop_song_type(),
        m.type_label, Gtk::Label::prop_label(),
        GObject::BindingFlags::SYNC_CREATE);
    date_bind = Object::bind_property(
        song, SongItem::prop_publish_date(),
        m.date_label, Gtk::Label::prop_label(),
        GObject::BindingFlags::SYNC_CREATE);
    dur_bind = Object::bind_property(
        song, SongItem::prop_duration(),
        m.duration_label, Gtk::Label::prop_label(),
        GObject::BindingFlags::SYNC_CREATE);
}

void
SecondarySongDataCell::unbind()
{
    if (type_bind) { type_bind->unbind(); type_bind = {}; }
    if (date_bind) { date_bind->unbind(); date_bind = {}; }
    if (dur_bind)  { dur_bind->unbind();  dur_bind = {}; }
}

PEEL_CLASS_IMPL(SecondarySongDataCell, "SongSearcherSecondarySongDataCell", Gtk::Box)
