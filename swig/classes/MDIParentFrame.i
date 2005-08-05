#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxMDIParentFrame;

%{
#include <wx/mdi.h>
%}
%ignore wxMDIParentFrame::wxMDIParentFrame();

//
// Doesn't work on wxMac
//
%ignore wxMDIParentFrame::GetWindowMenu;
%ignore wxMDIParentFrame::SetWindowMenu;


%include "include/wxMDIParentFrame.h"
