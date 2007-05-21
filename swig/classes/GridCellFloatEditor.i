// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxGridCellFloatEditor
GC_MANAGE(wxGridCellFloatEditor);

%{
#include <wx/grid.h>
%}

%import "include/wxGridCellEditor.h"

%include "include/wxGridCellFloatEditor.h"
