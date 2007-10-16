// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxPrinter
GC_MANAGE_AS_OBJECT(wxPrinter);

%{
#include <wx/print.h>
%}

%import "include/wxObject.h"

%include "include/wxPrinter.h"
