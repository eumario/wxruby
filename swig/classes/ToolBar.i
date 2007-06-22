// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxToolBar;
GC_MANAGE_AS_WINDOW(wxToolBar);

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

// Numerous adding methods in wxToolBar return an undocumented C++
// wxToolBarToolBase class. Rather than port this class, these methods
// return the integer position of the new tool in wxRuby. Hence, all
// access to ToolBar changing methods is via Wx::ToolBar.
%typemap(out) wxToolBarToolBase* {
  // arg1 here is the typecase C++ self; $1 is the new ToolBarToolBase
  int pos_of_tool = arg1->GetToolPos($1->GetId());
  $result = INT2NUM(pos_of_tool);
}


// Versions of methods that accept a ToolBarTool argument are not
// supported in wxRuby, because that class is not ported.
%ignore wxToolBar::AddTool(wxToolBarToolBase *tool);
%ignore wxToolBar::FindToolForPosition(const float  x , const float  y ) const;
%ignore wxToolBar::InsertTool(size_t pos, wxToolBarToolBase *tool);

// VERY weird swig bug here...
// If we have the comment, the %if, %ignore and %endif,
// no code is generated. 
// Removing any single element doesn't help, but removing 
// all of it makes the problem go away!
// under GTK, this doesn't exist
//%if !defined(SWIGMAC) && !defined(SWIGWIN)
  %ignore SetMargins(const wxSize&);
//%endif


%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxControl.h"

%include "include/wxToolBar.h"
