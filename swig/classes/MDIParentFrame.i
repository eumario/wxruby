#   Copyright 2004 by Kevin Smith
#   released under the wxWidgets license
#   as part of the wxRuby project
%include "../common.i"

%module(directors="1") wxMDIParentFrame;

%{
#include <wx/mdi.h>
%}
%ignore wxMDIParentFrame::wxMDIParentFrame();

%include "include/wxMDIParentFrame.h"

