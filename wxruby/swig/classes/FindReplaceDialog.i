// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxFindReplaceDialog
GC_MANAGE_AS_DIALOG(wxFindReplaceDialog);
SWIG_WXTOPLEVELWINDOW_NO_USELESS_VIRTUALS(wxFindReplaceDialog);

%{
#include <wx/fdrepdlg.h>
%}

%ignore wxFindReplaceDialog::wxFindReplaceDialog();

%apply SWIGTYPE *DISOWN { wxFindReplaceData* data };

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxDialog.h"

%include "include/wxFindReplaceDialog.h"
