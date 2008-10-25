// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module wxRichTextHTMLHandler;
GC_MANAGE_AS_OBJECT(wxRichTextHTMLHandler);

%{
#include <wx/richtext/richtexthtml.h>
%}

%include "../shared/richtext.i"

%import "include/wxObject.h"
%import "include/wxRichTextFileHandler.h"
%include "include/wxRichTextHTMLHandler.h"
