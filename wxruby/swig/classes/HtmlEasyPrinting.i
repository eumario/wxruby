// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxHtmlEasyPrinting
GC_MANAGE_AS_OBJECT(wxHtmlEasyPrinting);

%{
#include <wx/html/htmprint.h>
%}

// Control which pages headers and footers are used on
enum {
  wxPAGE_ODD,
  wxPAGE_EVEN,
  wxPAGE_ALL
};


%import "include/wxObject.h"

%include "include/wxHtmlEasyPrinting.h"
