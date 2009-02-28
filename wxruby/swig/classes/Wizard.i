// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxWizard
GC_MANAGE_AS_DIALOG(wxWizard);
SWIG_WXTOPLEVELWINDOW_NO_USELESS_VIRTUALS(wxWizard);

%{
#include <wx/wizard.h>
%}

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxPanel.h"
%import "include/wxDialog.h"

%include "include/wxWizard.h"
