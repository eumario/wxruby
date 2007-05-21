// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxGridCellNumberRenderer
GC_MANAGE(wxGridCellNumberRenderer);

%{
#include <wx/grid.h>
%}

%import "include/wxGridCellRenderer.h"

%include "include/wxGridCellNumberRenderer.h"
