// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxClipboard
GC_NEVER(wxClipboard);

%{
#include <wx/clipbrd.h>
%}

%include "../shared/data_object.i"

%include "include/wxClipboard.h"

