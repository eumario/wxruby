#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxPasswordEntryDialog

%{
#include <wx/textdlg.h>
%}

%import "include/wxObject.h"
%import "include/wxWindow.h"
%import "include/wxEvtHandler.h"
%import "include/wxDialog.h"
%import "include/wxTextEntryDialog.h"

%include "include/wxPasswordEntryDialog.h"
