// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxGridCellBoolEditor
GC_MANAGE(wxGridCellBoolEditor);

%{
#include <wx/grid.h>
%}

%import "include/wxGridCellEditor.h"

%include "include/wxGridCellBoolEditor.h"
