// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%{
#include <wx/wx.h>
#include <wx/numdlg.h>
%}

%module(directors="1") wxNumberEntryDialog
GC_MANAGE_AS_DIALOG(wxNumberEntryDialog);

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxDialog.h"

%include "include/wxNumberEntryDialog.h"
