// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxGridCellCoords
GC_MANAGE(wxGridCellCoords);

%{
#include <wx/grid.h>
%}

%include "include/wxGridCellCoords.h"

