// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxGridCellBoolRenderer
GC_MANAGE(wxGridCellBoolRenderer);

%{
#include <wx/grid.h>
%}

%import "include/wxGridCellRenderer.h"

%include "include/wxGridCellBoolRenderer.h"
