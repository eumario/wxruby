// Copyright 2004-2009, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxChoicebook
GC_MANAGE_AS_WINDOW(wxChoicebook);
SWIG_WXWINDOW_NO_USELESS_VIRTUALS(wxChoicebook);

%{
#include <wx/choicebk.h>
%}

%include "../shared/bookctrls.i"
BOOKCTRL_FEATURES(wxChoicebook);

#define wxChoicebookPage wxWindow

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxControl.h"
%import "include/wxBookCtrlBase.h"

%include "include/wxChoicebook.h"
