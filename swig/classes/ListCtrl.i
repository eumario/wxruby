#   Copyright 2004 by Kevin Smith
#   released under the wxWidgets license
#   as part of the wxRuby project
%include "../common.i"

%{
#include <wx/wx.h>
#include <wx/listctrl.h>
%}

%module(directors="1") wxListCtrl

#ifdef __WXMAC__
%ignore wxListCtrl::GetEditControl;
#endif

%include "include/wxListCtrl.h"
