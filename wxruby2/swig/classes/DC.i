#   Copyright 2004 by Kevin Smith
#   released under the wxWidgets license
#   as part of the wxRuby project
%include "../common.i"

%module(directors="1") wxDC

%ignore wxDC::CacheEnabled;
%ignore wxDC::ClearCache;
%ignore wxDC::EnableCache;

%ignore wxDC::StartPage;

%include "include/wxDC.h"
