// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxFlexGridSizer
GC_MANAGE_AS_OBJECT(wxFlexGridSizer);

%ignore wxFlexGridSizer::GetFlexibleDirection;
%ignore wxFlexGridSizer::GetNonFlexibleDirection;
%ignore wxFlexGridSizer::SetFlexibleDirection;
%ignore wxFlexGridSizer::SetNonFlexibleDirection;
%ignore wxFlexGridSizer::GetNonFlexibleGrowMode;
%ignore wxFlexGridSizer::SetNonFlexibleGrowMode;

// shared functions for GC marking 
%include "../shared/sizers.i"
%markfunc wxBoxSizer "mark_wxSizer";

 

%import "include/wxObject.h"
%import "include/wxSizer.h"
%import "include/wxGridSizer.h"

%include "include/wxFlexGridSizer.h"
