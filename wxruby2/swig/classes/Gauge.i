#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxGauge
%{
#include <wx/gauge.h>
%}

%ignore wxGauge::wxGauge();

%include "include/wxGauge.h"
