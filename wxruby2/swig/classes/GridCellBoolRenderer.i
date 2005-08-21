#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxGridCellBoolRenderer

%{
#include <wx/grid.h>
%}

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxGridCellRenderer.h"

%include "include/wxGridCellBoolRenderer.h"
