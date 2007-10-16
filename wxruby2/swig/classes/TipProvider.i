// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxTipProvider
GC_MANAGE(wxTipProvider);

%feature("nodirector") wxTipProvider::GetTip;

%{
#include <wx/tipdlg.h>
%}



%include "include/wxTipProvider.h"

wxTipProvider * wxCreateFileTipProvider(const wxString& filename,  size_t currentTip);
bool wxShowTip(wxWindow *parent,  wxTipProvider *tipProvider,  bool showAtStartup = TRUE);
