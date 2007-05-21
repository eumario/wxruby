// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxGridCellFloatRenderer
GC_MANAGE(wxGridCellFloatRenderer);

%{
#include <wx/grid.h>
%}

%import "include/wxGridCellRenderer.h"

%include "include/wxGridCellFloatRenderer.h"
