// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxPrintout
GC_MANAGE_AS_OBJECT(wxPrintout);

%{
#include <wx/print.h>
%}

%apply int * OUTPUT {int *}

%import "include/wxObject.h"

%include "include/wxPrintout.h"
