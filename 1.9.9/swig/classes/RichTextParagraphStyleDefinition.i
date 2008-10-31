// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module wxRichTextParagraphStyleDefinition;
GC_MANAGE_AS_OBJECT(wxRichTextParagraphStyleDefinition);

%{
#include <wx/richtext/richtextstyles.h>
%}

%include "../shared/richtext.i"

%import "include/wxObject.h"
%import "include/wxRichTextStyleDefinition.h"
%include "include/wxRichTextParagraphStyleDefinition.h"
