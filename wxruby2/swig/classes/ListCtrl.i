#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%{
#include <wx/wx.h>
#include <wx/listctrl.h>
%}

%module(directors="1") wxListCtrl

%ignore wxListCtrl::wxListCtrl();
//
// Doesn't work on wxMac
//
%ignore wxListCtrl::GetEditControl;

# deprecated:
%ignore wxListCtrl::GetItemSpacing(bool isSmall) const;



%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxControl.h"

%include "include/wxListCtrl.h"

// TODO: Make this its own class!
//
// There is no record of this class in the XML file
//
