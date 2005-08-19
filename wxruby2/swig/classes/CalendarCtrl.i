#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxCalendarCtrl

%{
#include <wx/calctrl.h>
%}

%ignore wxCalendarCtrl::wxCalendarCtrl();

%include "include/wxCalendarCtrl.h"
