// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxFlexGridSizer
GC_MANAGE_AS_SIZER(wxFlexGridSizer);

%ignore wxFlexGridSizer::GetFlexibleDirection;
%ignore wxFlexGridSizer::GetNonFlexibleDirection;
%ignore wxFlexGridSizer::SetFlexibleDirection;
%ignore wxFlexGridSizer::SetNonFlexibleDirection;
%ignore wxFlexGridSizer::GetNonFlexibleGrowMode;
%ignore wxFlexGridSizer::SetNonFlexibleGrowMode;

// shared functions
%include "../shared/sizers.i"

%import "include/wxObject.h"
%import "include/wxSizer.h"
%import "include/wxGridSizer.h"

%include "include/wxFlexGridSizer.h"
