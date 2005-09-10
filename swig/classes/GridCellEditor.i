#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxGridCellEditor

%{
#include <wx/grid.h>
%}

%ignore wxGridCellEditor::wxGridCellEditor();
%ignore wxGridCellEditor::~wxGridCellEditor();

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"


%include "include/wxGridCellEditor.h"
