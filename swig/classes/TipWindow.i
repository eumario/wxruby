// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxTipWindow
GC_MANAGE_AS_WINDOW(wxTipWindow);
SWIG_WXWINDOW_NO_USELESS_VIRTUALS(wxTipWindow);


%{
#include  <wx/tipwin.h>
%}

// Not useful in wxRuby
%ignore wxTipWindow::SetTipWindowPtr;

// Ignore this argument in the constructor
%typemap(in,numinputs=0) (wxTipWindow **windowPtr) "$1 = NULL;"

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"

%include "include/wxTipWindow.h"
