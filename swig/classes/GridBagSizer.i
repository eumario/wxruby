#   Copyright 2004-2007 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxGridBagSizer

%{
#include <wx/gbsizer.h>
%}

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
