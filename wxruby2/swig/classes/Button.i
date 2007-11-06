// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxButton
GC_MANAGE_AS_WINDOW(wxButton);
SWIG_WXWINDOW_NO_USELESS_VIRTUALS(wxButton);

%include "../shared/no_window_virtuals.i"
SWIG_WXWINDOW_NO_USELESS_VIRTUALS(wxButton);


%ignore wxButton::wxButton();

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxControl.h"

%include "include/wxButton.h"
