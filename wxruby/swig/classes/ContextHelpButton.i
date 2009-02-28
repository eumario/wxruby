// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxContextHelpButton
GC_MANAGE_AS_WINDOW(wxContextHelpButton);
SWIG_WXWINDOW_NO_USELESS_VIRTUALS(wxContextHelpButton);

%header %{
#include <wx/cshelp.h>
%}

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxControl.h"
%import "include/wxButton.h"
%import "include/wxBitmapButton.h"

%include "include/wxContextHelpButton.h"
