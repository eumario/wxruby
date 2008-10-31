// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxMenuBar;
// Memory management is handled via the containing Frame
GC_NEVER(wxMenuBar);
SWIG_WXWINDOW_NO_USELESS_VIRTUALS(wxMenuBar);

%ignore wxMenuBar(int  n , wxMenu*  menus[] , const wxString  titles[] ) ;

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"

%include "include/wxMenuBar.h"
