// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxNotebook
GC_MANAGE_AS_WINDOW(wxNotebook);
SWIG_WXWINDOW_NO_USELESS_VIRTUALS(wxNotebook);

%{
#include <wx/notebook.h>
%}

// use common book wxBK_* flags for describing alignment
#define wxNB_DEFAULT          0x0000
#define wxNB_TOP              0x0010
#define wxNB_BOTTOM           0x0020
#define wxNB_LEFT             0x0040
#define wxNB_RIGHT            0x0080

#define wxNB_FIXEDWIDTH       0x0100
#define wxNB_MULTILINE        0x0200
#define wxNB_NOPAGETHEME      0x0400
#define wxNB_FLAT             0x0800

#define wxNotebookPage wxWindow

// Protect panels etc added as Notebook pages from being GC'd by Ruby;
// avoids double-free segfaults on exit on GTK
%apply SWIGTYPE *DISOWN { wxNotebookPage* page };

// Avoid premature deletion of ImageList providing icons for notebook
// tabs; wxRuby takes ownership when the ImageList is assigned,
// wxWidgets will delete the ImageList with the Notebook.
%apply SWIGTYPE *DISOWN { wxImageList* };
// This version in Wx doesn't automatically delete
%ignore wxNotebook::SetImageList;
// Use the version that deletes the ImageList when the Notebook is destroyed
%rename(SetImageList) wxNotebook::AssignImageList;

// Users should handle page changes with events, not virtual methods
%ignore wxNotebook::OnSelChange;
%feature("nodirector") wxNotebook::OnSelChange;

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxControl.h"

%include "include/wxNotebook.h"
