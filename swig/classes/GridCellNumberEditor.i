#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module wxGridCellNumberEditor

%{
#include <wx/grid.h>
%}

%ignore wxGridCellNumberEditor::GetString() const;
%ignore wxGridCellNumberEditor::HasRange() const;

%include "include/wxGridCellNumberEditor.h"
