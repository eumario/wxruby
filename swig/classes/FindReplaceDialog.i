// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxFindReplaceDialog
GC_MANAGE_AS_DIALOG(wxFindReplaceDialog);

%{
#include <wx/fdrepdlg.h>
%}
%ignore wxFindReplaceDialog::wxFindReplaceDialog();

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxDialog.h"

%include "include/wxFindReplaceDialog.h"
