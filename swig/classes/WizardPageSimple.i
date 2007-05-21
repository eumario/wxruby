// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxWizardPageSimple
GC_MANAGE_AS_WINDOW(wxWizardPageSimple);

%{
#include <wx/wizard.h>
%}

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxPanel.h"
%import "include/wxWizardPage.h"

%include "include/wxWizardPageSimple.h"
