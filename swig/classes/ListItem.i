// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%{
#include <wx/wx.h>
#include <wx/listctrl.h>
%}

%module(directors="1") wxListItem
GC_MANAGE_AS_OBJECT(wxListItem);

%import "include/wxObject.h"

%include "include/wxListItem.h"
