// Copyright 2004-2009, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxSingleChoiceDialog
GC_MANAGE_AS_DIALOG(wxSingleChoiceDialog);
SWIG_WXTOPLEVELWINDOW_NO_USELESS_VIRTUALS(wxSingleChoiceDialog);

// Wx's SingleChoiceDialog offers the possibility of attaching client
// data to each choice. However this would need memory management, and a
// pure ruby implementation is trivial and likely to be more convenient
// on a per-case basis.
%typemap("in", numinputs=0) char** clientData "$1 = (char **)NULL;"
%ignore wxSingleChoiceDialog::GetSelectionClientData();

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxDialog.h"

%include "include/wxSingleChoiceDialog.h"
