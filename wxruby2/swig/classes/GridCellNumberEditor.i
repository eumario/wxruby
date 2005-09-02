#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxGridCellNumberEditor

%{
#include <wx/grid.h>
%}

%ignore wxGridCellNumberEditor::GetString() const;
%ignore wxGridCellNumberEditor::HasRange() const;

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxGridCellEditor.h"

%include "include/wxGridCellNumberEditor.h"
