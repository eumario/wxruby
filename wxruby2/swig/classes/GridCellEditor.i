#   Copyright 2004 by Kevin Smith
#   released under the wxWidgets license
#   as part of the wxRuby project
%include "../common.i"

%module wxGridCellEditor

%{
#include <wx/grid.h>
%}

%ignore wxGridCellEditor::wxGridCellEditor();

%include "include/wxGridCellEditor.h"

