// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxSlider
GC_MANAGE_AS_WINDOW(wxSlider);
SWIG_WXWINDOW_NO_USELESS_VIRTUALS(wxSlider);
%{
#include <wx/wx.h>
#include <wx/slider.h>
%}

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxControl.h"

%include "include/wxSlider.h"
