// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxPrintPreview
GC_MANAGE_AS_OBJECT(wxPrintPreview);

%{
#include <wx/print.h>
%}

%import "include/wxObject.h"

%include "include/wxPrintPreview.h"
