#   Copyright 2004 by Kevin Smith
#   released under the wxWidgets license
#   as part of the wxRuby project
%include "../common.i"

%module(directors="1") wxSizer

%ignore wxSizer::Detach;
%ignore wxSizer::Show;

%include "include/wxSizer.h"
