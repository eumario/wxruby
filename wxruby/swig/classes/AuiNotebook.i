// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxAuiNotebook
GC_MANAGE_AS_WINDOW(wxAuiNotebook);
SWIG_WXWINDOW_NO_USELESS_VIRTUALS(wxAuiNotebook);

%{
// Workaround for wx's auibar.h incompatibility 2.8.10 with OS X compiler
// Should be fixed by future wxWidgets 
#ifdef __WXMAC__
#define id toolid
#endif

#include <wx/aui/aui.h>
%}

enum wxAuiNotebookOption
{
    wxAUI_NB_TOP                 = 1 << 0,
    wxAUI_NB_LEFT                = 1 << 1,  // not implemented yet
    wxAUI_NB_RIGHT               = 1 << 2,  // not implemented yet
    wxAUI_NB_BOTTOM              = 1 << 3,  // not implemented yet
    wxAUI_NB_TAB_SPLIT           = 1 << 4,
    wxAUI_NB_TAB_MOVE            = 1 << 5,
    wxAUI_NB_TAB_EXTERNAL_MOVE   = 1 << 6,
    wxAUI_NB_TAB_FIXED_WIDTH     = 1 << 7,
    wxAUI_NB_SCROLL_BUTTONS      = 1 << 8,
    wxAUI_NB_WINDOWLIST_BUTTON   = 1 << 9,
    wxAUI_NB_CLOSE_BUTTON        = 1 << 10,
    wxAUI_NB_CLOSE_ON_ACTIVE_TAB = 1 << 11,
    wxAUI_NB_CLOSE_ON_ALL_TABS   = 1 << 12,
    
    
    wxAUI_NB_DEFAULT_STYLE = wxAUI_NB_TOP |
                             wxAUI_NB_TAB_SPLIT |
                             wxAUI_NB_TAB_MOVE |
                             wxAUI_NB_SCROLL_BUTTONS |
                             wxAUI_NB_CLOSE_ON_ACTIVE_TAB
};

%import "include/wxControl.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxObject.h"

// wxWidgets provides a whole class for writing custom styles for the
// tabs in AuiNotebooks. Rather than add the whole API, provide access
// to allow switching between the two styles that come with wxWidgets.
%extend wxAuiNotebook {
  void use_glossy_art()
    { $self->SetArtProvider(new wxAuiDefaultTabArt); }

  void use_simple_art()
    { $self->SetArtProvider(new wxAuiSimpleTabArt); }
}

%include "include/wxAuiNotebook.h"
