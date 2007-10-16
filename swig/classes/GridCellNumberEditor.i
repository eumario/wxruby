// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxGridCellNumberEditor
GC_MANAGE(wxGridCellNumberEditor);

%{
#include <wx/grid.h>
%}

%ignore wxGridCellNumberEditor::GetString() const;
%ignore wxGridCellNumberEditor::HasRange() const;

%import "include/wxGridCellEditor.h"

%include "include/wxGridCellNumberEditor.h"
