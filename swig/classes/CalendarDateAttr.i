#   Copyright 2004 by Kevin Smith
#   released under the wxWidgets license
#   as part of the wxRuby project
%include "../common.i"

%module(directors="1") wxCalendarDateAttr

%{
#include <wx/calctrl.h>
%}

%ignore wxCalendarDateAttr::wxCalendarDateAttr();
%ignore wxCalendarDateAttr::wxCalendarDateAttr(const wxColour& colText, const wxColour& colBack = wxNullColour, const wxColour& colBorder = wxNullColour, const wxFont& font = wxNullFont, wxCalendarDateBorder border = wxCAL_BORDER_NONE);

%include "include/wxCalendarDateAttr.h"
