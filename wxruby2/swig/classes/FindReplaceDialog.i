#   Copyright 2004 by Kevin Smith
#   released under the wxWidgets license
#   as part of the wxRuby project
%include "../common.i"

%module(directors="1") wxFindReplaceDialog

%{
#include <wx/fdrepdlg.h>
%}
%ignore wxFindReplaceDialog::wxFindReplaceDialog();
%include "include/wxFindReplaceDialog.h"

