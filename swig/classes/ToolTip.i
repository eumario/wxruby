#   Copyright 2004 by Kevin Smith
#   released under the wxWidgets license
#   as part of the wxRuby project
%include "../common.i"

%module(directors="1") wxToolTip

%{
#include <wx/tooltip.h>
%}

%ignore wxToolTip::SetWindow(wxWindow *win);

%include "include/wxToolTip.h"
