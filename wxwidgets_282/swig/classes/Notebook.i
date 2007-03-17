#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxNotebook
%feature("nodirector") wxNotebook::OnSelChange;

%{
#include <wx/wx.h>
#include <wx/notebook.h>
%}


GC_NEVER(wxNotebook)

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
