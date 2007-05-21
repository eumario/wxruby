// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxCalendarDateAttr
GC_MANAGE(wxCalendarDateAttr);
%feature("nodirector") wxCalendarDateAttr;

%{
//NO_DIRECTOR

#include <wx/calctrl.h>
%}

%ignore wxCalendarDateAttr::wxCalendarDateAttr();
%ignore wxCalendarDateAttr::wxCalendarDateAttr(const wxColour& colText, const wxColour& colBack = wxNullColour, const wxColour& colBorder = wxNullColour, const wxFont& font = wxNullFont, wxCalendarDateBorder border = wxCAL_BORDER_NONE);

%include "include/wxCalendarDateAttr.h"
