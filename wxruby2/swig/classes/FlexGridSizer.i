#   Copyright 2004 by Kevin Smith
#   released under the wxWidgets license
#   as part of the wxRuby project
%include "../common.i"

%module(directors="1") wxFlexGridSizer

#ifdef __WXMAC__
%ignore wxFlexGridSizer::GetFlexibleDirection;
%ignore wxFlexGridSizer::GetNonFlexibleDirection;
%ignore wxFlexGridSizer::SetFlexibleDirection;
%ignore wxFlexGridSizer::SetNonFlexibleDirection;
%ignore wxFlexGridSizer::GetNonFlexibleGrowMode;
%ignore wxFlexGridSizer::SetNonFlexibleGrowMode;
#endif
 

%include "include/wxFlexGridSizer.h"



