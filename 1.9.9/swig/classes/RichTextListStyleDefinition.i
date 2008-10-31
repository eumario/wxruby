// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module wxRichTextListStyleDefinition;
GC_MANAGE_AS_OBJECT(wxRichTextListStyleDefinition);

%{
#include <wx/richtext/richtextstyles.h>
%}

// FIXME - SWIG's generated code gives a compile error for these.
%ignore wxRichTextListStyleDefinition::GetCombinedStyle;
%ignore wxRichTextListStyleDefinition::GetCombinedStyleForLevel;

%include "../shared/richtext.i"

%import "include/wxObject.h"
%import "include/wxRichTextStyleDefinition.h"
%import "include/wxRichTextParagraphStyleDefinition.h"
%include "include/wxRichTextListStyleDefinition.h"
