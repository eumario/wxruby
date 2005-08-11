#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxSpinCtrl

%{
#include <wx/spinctrl.h>
%}

%include "include/wxSpinCtrl.h"
