#pragma once
#include <peel/Gtk/Box.h>
#include <peel/Gtk/Label.h>
#include <peel/GObject/Binding.h>
#include <peel/class.h>
#include <peel/RefPtr.h>
#include <peel/FloatPtr.h>

class SongItem;

class PrimarySongDataCell final : public peel::Gtk::Box
{
    PEEL_SIMPLE_CLASS(PrimarySongDataCell, peel::Gtk::Box);

    struct Members {
        peel::Gtk::Label *name_label;
        peel::Gtk::Label *artist_label;
        peel::Gtk::Label *vocalist_label;
    } m;

    peel::RefPtr<peel::GObject::Binding> name_bind;
    peel::RefPtr<peel::GObject::Binding> artist_bind;
    peel::RefPtr<peel::GObject::Binding> vocalist_bind;

    void init(Class *);
    void vfunc_dispose();

public:
    static peel::FloatPtr<PrimarySongDataCell> create();
    void bind(SongItem *song);
    void unbind();
};
