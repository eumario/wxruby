// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxGridSizer
GC_MANAGE_AS_SIZER(wxGridSizer);

// shared functions 
%include "../shared/sizers.i"

%import "include/wxObject.h"
%import "include/wxSizer.h"

%include "include/wxGridSizer.h"
