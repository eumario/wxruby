#   Copyright 2004 by Kevin Smith
#   released under the wxWidgets license
#   as part of the wxRuby project
%include "../common.i"

%module(directors="1") wxColourDialog

%{
#include <wx/colordlg.h>
%}

%include "include/wxColourDialog.h"
