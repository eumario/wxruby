// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxWizardPage
GC_MANAGE_AS_WINDOW(wxWizardPage);

%{
#include <wx/wizard.h>
%}

// no ctor b/c of abstract methods
%ignore wxWizardPage::wxWizardPage(wxWizard*  parent , const wxBitmap&  bitmap = wxNullBitmap, const wxChar  *resource = NULL);



%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxPanel.h"

%include "include/wxWizardPage.h"

