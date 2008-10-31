// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxMDIParentFrame;
GC_MANAGE_AS_FRAME(wxMDIParentFrame);
SWIG_WXWINDOW_NO_USELESS_VIRTUALS(wxMDIParentFrame);

%apply SWIGTYPE *DISOWN { wxMenuBar * }

%{
#include <wx/mdi.h>
%}
%ignore wxMDIParentFrame::wxMDIParentFrame();

//
// Doesn't work on wxMac
//
%ignore wxMDIParentFrame::GetWindowMenu;
%ignore wxMDIParentFrame::SetWindowMenu;

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxFrame.h"

%include "include/wxMDIParentFrame.h"
