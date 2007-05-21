// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxGridCellChoiceEditor
GC_MANAGE(wxGridCellChoiceEditor);

%{
#include <wx/grid.h>
%}

%import "include/wxGridCellEditor.h"

%include "include/wxGridCellChoiceEditor.h"
