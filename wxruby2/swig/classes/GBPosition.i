// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxGBPosition
GC_MANAGE(wxGBPosition);

%{
#include <wx/gbsizer.h>
%}

%include "include/wxGBPosition.h"
