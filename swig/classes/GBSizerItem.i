// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module wxGBSizerItem
GC_MANAGE_AS_OBJECT(wxGBSizerItem);

%{
#include <wx/gbsizer.h>
%}

%import "include/wxObject.h"
%import "include/wxSizerItem.h"

// Use only variants that return the object
%ignore GetPos(int& row, int& col) const;
%ignore GetSpan(int& rowspan, int& colspan) const;

// For GetEndPos
%apply int *OUTPUT { int &row, int &col };

%include "include/wxGBSizerItem.h"
