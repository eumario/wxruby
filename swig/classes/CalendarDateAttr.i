// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module wxCalendarDateAttr
GC_MANAGE(wxCalendarDateAttr);

%{
#include <wx/calctrl.h>
%}

%include "include/wxCalendarDateAttr.h"
