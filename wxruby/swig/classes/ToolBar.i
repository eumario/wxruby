// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxToolBar;
GC_MANAGE_AS_WINDOW(wxToolBar);
SWIG_WXWINDOW_NO_USELESS_VIRTUALS(wxToolBar);

%{
#include <wx/toolbar.h>
%}


// wxToolBar style flags
enum
{
    wxTB_HORIZONTAL  = wxHORIZONTAL,    // == 0x0004
    wxTB_TOP         = wxTB_HORIZONTAL,
    wxTB_VERTICAL    = wxVERTICAL,      // == 0x0008
    wxTB_LEFT        = wxTB_VERTICAL,
    wxTB_3DBUTTONS   = 0x0010,
    wxTB_FLAT        = 0x0020,
    wxTB_DOCKABLE    = 0x0040,
    wxTB_NOICONS     = 0x0080,
    wxTB_TEXT        = 0x0100,
    wxTB_NODIVIDER   = 0x0200,
    wxTB_NOALIGN     = 0x0400,
    wxTB_HORZ_LAYOUT = 0x0800,
    wxTB_HORZ_TEXT   = wxTB_HORZ_LAYOUT | wxTB_TEXT,
    wxTB_NO_TOOLTIPS = 0x1000,
    wxTB_BOTTOM       = 0x2000,
    wxTB_RIGHT        = 0x4000
};

// Ensure that the C++ wxToolBar(Base) implementation of UpdateWindowUI
// is called internally, so that UpdateUIEvents are also sent to each
// button within the toolbar. This means update_window_ui can't be
// overridden for this class in Ruby, but unlikely a real problem.
%feature("nodirector") wxToolBar::UpdateWindowUI;

// These don't work as you would think...
%ignore wxToolBar::AddTool(wxToolBarToolBase* tool);
%ignore wxToolBar::InsertTool(size_t pos, wxToolBarToolBase* tool);

// This is missing on GTK
%ignore wxToolBar::SetMargins(const wxSize& size);

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxControl.h"

%include "include/wxToolBar.h"
