#   Copyright 2004 by Kevin Smith
#   released under the wxWidgets license
#   as part of the wxRuby project
%include "../common.i"

%module(directors="1") wxGauge
%{
#include <wx/gauge.h>
%}

%ignore wxGauge::wxGauge();

%include "include/wxGauge.h"

