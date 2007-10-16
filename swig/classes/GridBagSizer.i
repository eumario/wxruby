// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxGridBagSizer
GC_MANAGE_AS_SIZER(wxGridBagSizer);

%{
#include <wx/gbsizer.h>
%}

// shared functions
%include "../shared/sizers.i"

// ignore these for now - are they useful?
// require GBSizerItem to be wrapped
%ignore wxGridBagSizer::FindItemWithData;
%ignore wxGridBagSizer::FindItemAtPoint;
%ignore wxGridBagSizer::FindItemAtPosition;

%import "include/wxObject.h"
%import "include/wxSizer.h"
%import "include/wxGridSizer.h"
%import "include/wxFlexGridSizer.h"

%include "include/wxGridBagSizer.h"
