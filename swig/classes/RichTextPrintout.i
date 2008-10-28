// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxRichTextPrintout;
GC_MANAGE_AS_OBJECT(wxRichTextPrintout);

%{
#include <wx/richtext/richtextprint.h>
%}

%include "../shared/richtext.i"

%apply int *OUTPUT { int *minPage, int *maxPage, 
                     int *selPageFrom, int *selPageTo };


%import "include/wxObject.h"
%import "include/wxPrintout.h"

%include "include/wxRichTextPrintout.h"
