#   Copyright 2004 by Kevin Smith
#   released under the wxWidgets license
#   as part of the wxRuby project
%include "../common.i"

%module(directors="1") wxSpinCtrl

%{
#include <wx/spinctrl.h>
%}

# under GTK, this doesn't exist
#ifndef SWIGMAC
 #ifndef SWIGWIN
  %ignore SetSelection;
 #endif
#endif


%include "include/wxSpinCtrl.h"

 