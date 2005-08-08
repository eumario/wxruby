#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxCalendarDateAttr
%feature("nodirector") wxCalendarDateAttr;

%{
//NO_DIRECTOR

#include <wx/calctrl.h>
%}

%ignore wxCalendarDateAttr::wxCalendarDateAttr();
%ignore wxCalendarDateAttr::wxCalendarDateAttr(const wxColour& colText, const wxColour& colBack = wxNullColour, const wxColour& colBorder = wxNullColour, const wxFont& font = wxNullFont, wxCalendarDateBorder border = wxCAL_BORDER_NONE);

%include "include/wxCalendarDateAttr.h"
