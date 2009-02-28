// Copyright 2004-2009, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxMDIParentFrame;
GC_MANAGE_AS_FRAME(wxMDIParentFrame);
SWIG_WXTOPLEVELWINDOW_NO_USELESS_VIRTUALS(wxMDIParentFrame);

%apply SWIGTYPE *DISOWN { wxMenuBar * }

%{
#include <wx/mdi.h>
%}


// Doesn't work on wxMac
%ignore wxMDIParentFrame::GetWindowMenu;
%ignore wxMDIParentFrame::SetWindowMenu;

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxTopLevelWindow.h"
%import "include/wxFrame.h"

%include "include/wxMDIParentFrame.h"
