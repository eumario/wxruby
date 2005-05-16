#   Copyright 2004 by Kevin Smith
#   released under the wxWidgets license
#   as part of the wxRuby project
%include "../common.i"

%module wxGridCellNumberEditor

%{
#include <wx/grid.h>
%}

%ignore wxGridCellNumberEditor::GetString() const;
%ignore wxGridCellNumberEditor::HasRange() const;

%include "include/wxGridCellNumberEditor.h"

