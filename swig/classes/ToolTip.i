// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxToolTip
GC_MANAGE_AS_OBJECT(wxToolTip);

%{
#include <wx/tooltip.h>
%}

%ignore wxToolTip::SetWindow(wxWindow *win);

%import "include/wxObject.h"

%include "include/wxToolTip.h"
