// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxGridCellCoords
GC_MANAGE(wxGridCellCoords);

%{
#include <wx/grid.h>
%}

%include "include/wxGridCellCoords.h"

