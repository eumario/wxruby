// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module wxRichTextHeaderFooterData;
GC_MANAGE_AS_OBJECT(wxRichTextHeaderFooterData);

%{
#include <wx/richtext/richtextprint.h>
%}

%include "../shared/richtext.i"

%import "include/wxObject.h"
%include "include/wxRichTextHeaderFooterData.h"
