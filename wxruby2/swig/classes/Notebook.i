#   Copyright 2004 by Kevin Smith
#   released under the wxWidgets license
#   as part of the wxRuby project
%include "../common.i"

%{
#include <wx/wx.h>
#include <wx/notebook.h>
%}

%module(directors="1") wxNotebook

GC_NEVER(wxNotebook)

#define wxNotebookPage wxPanel

%ignore wxNotebook::wxNotebook();

%include "include/wxNotebook.h"
