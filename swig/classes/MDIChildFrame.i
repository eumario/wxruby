#   Copyright 2004 by Kevin Smith
#   released under the wxWidgets license
#   as part of the wxRuby project
%include "../common.i"

%module(directors="1") wxMDIChildFrame;

%{
#include <wx/mdi.h>
%}

%ignore wxMDIChildFrame::wxMDIChildFrame();

//
// Doesn't work on wxMac. We need a better workaround.
//
%ignore wxMdiChildFrame::GetWindowMenu;
%ignore wxMdiChildFrame::SetWindowMenu;

%include "include/wxMDIChildFrame.h"

