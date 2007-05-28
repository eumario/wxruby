// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxGridSizer
GC_MANAGE_AS_OBJECT(wxGridSizer);

// shared functions for GC marking 
%include "../shared/sizers.i"
%markfunc wxBoxSizer "mark_wxSizer";


%import "include/wxObject.h"
%import "include/wxSizer.h"

%include "include/wxGridSizer.h"
