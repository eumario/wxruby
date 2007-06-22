// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxToolBar;
GC_MANAGE_AS_WINDOW(wxToolBar);

%{
#include <wx/toolbar.h>
%}


// 
%typemap(out) wxToolBarToolBase* {
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
