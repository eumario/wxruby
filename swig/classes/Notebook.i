// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxNotebook
GC_MANAGE_AS_WINDOW(wxNotebook);
%feature("nodirector") wxNotebook::OnSelChange;

%{
#include <wx/wx.h>
#include <wx/notebook.h>
%}



#define wxNotebookPage wxWindow

// Protect panels etc added as Notebook pages from being GC'd by Ruby;
// avoids double-free segfaults on exit on GTK
%apply SWIGTYPE *DISOWN { wxNotebookPage* page };


%ignore wxNotebook::wxNotebook();
%ignore wxNotebook::OnSelChange;

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxControl.h"

%include "include/wxNotebook.h"
