// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxSizer
GC_MANAGE_AS_SIZER(wxSizer);

%feature("nodirector") wxSizer::CalcMin;
%ignore wxSizer::IsShown;

// shared functions
%include "../shared/sizers.i"

%import "include/wxObject.h"

%include "include/wxSizer.h"
