// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxGBSpan
GC_MANAGE(wxGBSpan);

%{
#include <wx/gbsizer.h>
%}

%constant const wxGBSpan DEFAULT_SPAN = wxDefaultSpan;

%include "include/wxGBSpan.h"
