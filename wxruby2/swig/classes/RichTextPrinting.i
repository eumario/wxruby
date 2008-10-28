// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module wxRichTextPrinting;
GC_MANAGE_AS_OBJECT(wxRichTextPrinting);

%{
#include <wx/richtext/richtextprint.h>
%}

%include "../shared/richtext.i"


// Header/footer page identifiers
enum wxRichTextOddEvenPage {
    wxRICHTEXT_PAGE_ODD,
    wxRICHTEXT_PAGE_EVEN,
    wxRICHTEXT_PAGE_ALL
};

// Header/footer text locations
enum wxRichTextPageLocation {
    wxRICHTEXT_PAGE_LEFT,
    wxRICHTEXT_PAGE_CENTRE,
    wxRICHTEXT_PAGE_RIGHT
};

%import "include/wxObject.h"

%include "include/wxRichTextPrinting.h"
