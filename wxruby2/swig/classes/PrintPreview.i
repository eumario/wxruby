#   Copyright 2004-2006 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxPrintPreview

%{
#include <wx/print.h>
%}

%import "include/wxObject.h"

%include "include/wxPrintPreview.h"
