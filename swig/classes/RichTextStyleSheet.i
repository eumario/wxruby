// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module wxRichTextStyleSheet;
GC_MANAGE_AS_OBJECT(wxRichTextStyleSheet);

%{
#include <wx/richtext/richtextstyles.h>
%}

%include "../shared/richtext.i"

%import "include/wxObject.h"
%include "include/wxRichTextStyleSheet.h"
