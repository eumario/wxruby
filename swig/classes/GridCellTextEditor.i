// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxGridCellTextEditor
GC_MANAGE(wxGridCellTextEditor);

%{
#include <wx/grid.h>
%}

%import "include/wxGridCellEditor.h"

%include "include/wxGridCellTextEditor.h"
