#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxToolTip

%{
#include <wx/tooltip.h>
%}

%ignore wxToolTip::SetWindow(wxWindow *win);

%include "include/wxToolTip.h"
