#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxLayoutAlgorithm

%{
#include <wx/laywin.h>
%}

%import "include/wxObject.h"

%include "include/wxLayoutAlgorithm.h"
