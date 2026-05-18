#pragma once
#include <peel/Gtk/Box.h>
#include <peel/Gtk/Label.h>
#include <peel/GObject/Binding.h>
#include <peel/class.h>
#include <peel/RefPtr.h>
#include <peel/FloatPtr.h>

class SongItem;

class SecondarySongDataCell final : public peel::Gtk::Box
{
    PEEL_SIMPLE_CLASS(SecondarySongDataCell, peel::Gtk::Box);

    struct Members {
        peel::Gtk::Label *type_label;
        peel::Gtk::Label *date_label;
        peel::Gtk::Label *duration_label;
    } m;

    peel::RefPtr<peel::GObject::Binding> type_bind;
    peel::RefPtr<peel::GObject::Binding> date_bind;
    peel::RefPtr<peel::GObject::Binding> dur_bind;

    void init(Class *);
    void vfunc_dispose();

public:
    static peel::FloatPtr<SecondarySongDataCell> create();
    void bind(SongItem *song);
    void unbind();
};
