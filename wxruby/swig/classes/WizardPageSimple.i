// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxWizardPageSimple
GC_MANAGE_AS_WINDOW(wxWizardPageSimple);
SWIG_WXWINDOW_NO_USELESS_VIRTUALS(wxWizardPageSimple);

%{
#include <wx/wizard.h>
%}

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxPanel.h"
%import "include/wxWizardPage.h"

%include "include/wxWizardPageSimple.h"
