// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxChoicebook
GC_MANAGE_AS_WINDOW(wxChoicebook);
%feature("nodirector") wxChoicebook::OnSelChange;

%{
#include <wx/wx.h>
#include <wx/choicebk.h>
%}



#define wxChoicebookPage wxWindow

%ignore wxChoicebook::OnSelChange;

// TODO: Are these correct? Docs don't show Choicebook
%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxControl.h"

%include "include/wxChoicebook.h"
