// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module wxRichTextCharacterStyleDefinition;
GC_MANAGE_AS_OBJECT(wxRichTextCharacterStyleDefinition);

%{
#include <wx/richtext/richtextstyles.h>
%}

%include "../shared/richtext.i"

%import "include/wxObject.h"
%import "include/wxRichTextStyleDefinition.h"
%include "include/wxRichTextCharacterStyleDefinition.h"
