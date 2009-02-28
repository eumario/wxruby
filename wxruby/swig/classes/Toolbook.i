// Copyright 2004-2009, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxToolbook
GC_MANAGE_AS_WINDOW(wxToolbook);
SWIG_WXWINDOW_NO_USELESS_VIRTUALS(wxToolbook);

%{
#include <wx/toolbook.h>
%}

%include "../shared/bookctrls.i"
BOOKCTRL_FEATURES(wxToolbook);

#define wxToolbookPage wxWindow

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxControl.h"
%import "include/wxBookCtrlBase.h"

%include "include/wxToolbook.h"
