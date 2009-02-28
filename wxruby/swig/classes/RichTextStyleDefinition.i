// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module wxRichTextStyleDefinition;
GC_MANAGE_AS_OBJECT(wxRichTextStyleDefinition);

%{
#include <wx/richtext/richtextstyles.h>
%}

// This class is virtual, so no constructor
%ignore wxRichTextStyleDefinition::wxRichTextStyleDefinition;

%include "../shared/richtext.i"

%import "include/wxObject.h"
%include "include/wxRichTextStyleDefinition.h"
