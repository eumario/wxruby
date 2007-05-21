// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxGBPosition
GC_MANAGE(wxGBPosition);

%{
#include <wx/gbsizer.h>
%}

%include "include/wxGBPosition.h"
