#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxFlexGridSizer

%ignore wxFlexGridSizer::GetFlexibleDirection;
%ignore wxFlexGridSizer::GetNonFlexibleDirection;
%ignore wxFlexGridSizer::SetFlexibleDirection;
%ignore wxFlexGridSizer::SetNonFlexibleDirection;
%ignore wxFlexGridSizer::GetNonFlexibleGrowMode;
%ignore wxFlexGridSizer::SetNonFlexibleGrowMode;
 

%include "include/wxFlexGridSizer.h"
