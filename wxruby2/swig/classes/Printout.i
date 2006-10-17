#   Copyright 2004-2006 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxPrintout

%{
#include <wx/print.h>
%}

%apply int * OUTPUT {int *}

%import "include/wxObject.h"

%include "include/wxPrintout.h"
