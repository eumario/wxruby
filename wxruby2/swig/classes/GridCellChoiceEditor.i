#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module wxGridCellChoiceEditor

%{
#include <wx/grid.h>
%}

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxGridCellEditor.h"

%include "include/wxGridCellChoiceEditor.h"
