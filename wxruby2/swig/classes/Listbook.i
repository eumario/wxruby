#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxListbook
%feature("nodirector") wxListbook::OnSelChange;

%{
#include <wx/wx.h>
#include <wx/listbook.h>
%}


GC_NEVER(wxListbook)

#define wxListbookPage wxWindow

%ignore wxListbook::OnSelChange;

// TODO: Are these correct? Docs don't show Listbook
%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxControl.h"

%include "include/wxListbook.h"
