// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module wxToolTip
GC_MANAGE_AS_OBJECT(wxToolTip);

%{
#include <wx/tooltip.h>
%}

%ignore wxToolTip::SetWindow(wxWindow *win);

%import "include/wxObject.h"

%include "include/wxToolTip.h"
