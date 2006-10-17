#   Copyright 2004-2006 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxPageSetupDialog
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
