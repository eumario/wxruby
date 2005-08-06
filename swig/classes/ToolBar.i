#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxToolBar;

%{
#include <wx/toolbar.h>

// for some reason, the api returns a wxToolBarTool, 
// even though that's not a documented class.
// fake it by saying it's just a control
typedef wxControl wxToolBarTool ;
%}

#// for some reason, the api returns a wxToolBarTool, 
#// even though that's not a documented class.
#// fake it by saying it's just a control
typedef wxControl wxToolBarTool;

%ignore wxToolBar::AddTool(int toolId, const wxString& label, const wxBitmap& bitmap1, const wxBitmap& bitmap2 = wxNullBitmap, wxItemKind kind = wxITEM_NORMAL, const wxString& shortHelpString = "", const wxString& longHelpString = "", wxObject* clientData = NULL);

// VERY weird swig bug here...
// If we have the comment, the %if, %ignore and %endif,
// no code is generated. 
// Removing any single element doesn't help, but removing 
// all of it makes the problem go away!
// under GTK, this doesn't exist
//%if !defined(SWIGMAC) && !defined(SWIGWIN)
  %ignore SetMargins(const wxSize&);
//%endif

GC_NEVER(wxToolBar);

%include "include/wxToolBar.h"
