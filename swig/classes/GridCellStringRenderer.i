// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxGridCellStringRenderer
GC_MANAGE(wxGridCellStringRenderer);

%{
#include <wx/grid.h>
%}

%import "include/wxGridCellRenderer.h"

%include "include/wxGridCellStringRenderer.h"
