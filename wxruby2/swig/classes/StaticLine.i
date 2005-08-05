#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxStaticLine

%{
#include <wx/statline.h>
%}

%include "include/wxStaticLine.h"
