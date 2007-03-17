#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxFindReplaceDialog

%{
#include <wx/fdrepdlg.h>
%}
%ignore wxFindReplaceDialog::wxFindReplaceDialog();

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxDialog.h"

%include "include/wxFindReplaceDialog.h"
