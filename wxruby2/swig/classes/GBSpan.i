// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxGBSpan
GC_MANAGE(wxGBSpan);

%{
#include <wx/gbsizer.h>
%}

%constant const wxGBSpan DEFAULT_SPAN = wxDefaultSpan;

%include "include/wxGBSpan.h"
