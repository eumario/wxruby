#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxSizer
%feature("nodirector") wxSizer; // abstract base class

%{
//NO_DIRECTOR
%}

%ignore wxSizer::IsShown;


%import "include/wxObject.h"

%include "include/wxSizer.h"
