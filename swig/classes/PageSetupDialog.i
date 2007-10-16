// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxPageSetupDialog
GC_MANAGE_AS_DIALOG(wxPageSetupDialog);
%feature("nodirector") wxPageSetupDialog;

%{
#include <wx/printdlg.h>
%}

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
#%import "include/wxTopLevelWindow.h"
%import "include/wxDialog.h"

%include "include/wxPageSetupDialog.h"
