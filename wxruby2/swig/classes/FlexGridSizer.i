#   Copyright 2004 by Kevin Smith
#   released under the wxWidgets license
#   as part of the wxRuby project
%include "../common.i"

%module(directors="1") wxFlexGridSizer

%ignore wxFlexGridSizer::GetFlexibleDirection;
%ignore wxFlexGridSizer::GetNonFlexibleDirection;
%ignore wxFlexGridSizer::SetFlexibleDirection;
%ignore wxFlexGridSizer::SetNonFlexibleDirection;
%ignore wxFlexGridSizer::GetNonFlexibleGrowMode;
%ignore wxFlexGridSizer::SetNonFlexibleGrowMode;
 

%include "include/wxFlexGridSizer.h"



