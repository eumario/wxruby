#   Copyright 2004-2007 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxGBSpan

%{
#include <wx/gbsizer.h>
%}

%constant const wxGBSpan DEFAULT_SPAN = wxDefaultSpan;

%include "include/wxGBSpan.h"
