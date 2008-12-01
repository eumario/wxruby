// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxAnimationCtrl
GC_MANAGE_AS_WINDOW(wxAnimationCtrl);
SWIG_WXWINDOW_NO_USELESS_VIRTUALS(wxAnimationCtrl);

%{
#include <wx/animate.h>
%}

// AC_DEFAULT_STYLE = (wxNO_BORDER)
#define wxAC_DEFAULT_STYLE (0x00200000)
#define wxAC_NO_AUTORESIZE (0x0010)

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxControl.h"

%include "include/wxAnimationCtrl.h"

