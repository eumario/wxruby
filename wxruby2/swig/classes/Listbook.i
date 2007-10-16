// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxListbook
GC_MANAGE_AS_WINDOW(wxListbook);
%feature("nodirector") wxListbook::OnSelChange;

%{
#include <wx/wx.h>
#include <wx/listbook.h>
%}



#define wxListbookPage wxWindow

%ignore wxListbook::OnSelChange;

// TODO: Are these correct? Docs don't show Listbook
%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxControl.h"

%include "include/wxListbook.h"
