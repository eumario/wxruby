// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxFlexGridSizer
GC_MANAGE_AS_SIZER(wxFlexGridSizer);

enum wxFlexSizerGrowMode
{
    // don't resize the cells in non-flexible direction at all
    wxFLEX_GROWMODE_NONE,
    // uniformly resize only the specified ones (default)
    wxFLEX_GROWMODE_SPECIFIED,
    // uniformly resize all cells
    wxFLEX_GROWMODE_ALL
};



// shared functions
%include "../shared/sizers.i"

%import "include/wxObject.h"
%import "include/wxSizer.h"
%import "include/wxGridSizer.h"

%include "include/wxFlexGridSizer.h"
