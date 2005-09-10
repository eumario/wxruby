#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxSizer

%ignore wxSizer::IsShown;

%feature("nodirector") wxSizer::CalcMin;

%import "include/wxObject.h"

%include "include/wxSizer.h"
