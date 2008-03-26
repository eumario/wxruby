// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxGridRangeSelectEvent
GC_MANAGE_AS_EVENT(wxGridRangeSelectEvent);

%{
#include <wx/grid.h>
%}

// Typemaps for GridCoords
%include "../shared/grid_coords.i"

%import "include/wxObject.h"
%import "include/wxEvent.h"
%import "include/wxCommandEvent.h"
%import "include/wxNotifyEvent.h"

%include "include/wxGridRangeSelectEvent.h"
