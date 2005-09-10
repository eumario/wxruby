#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxTipProvider

%feature("nodirector") wxTipProvider::GetTip;

%{
#include <wx/tipdlg.h>
%}



%include "include/wxTipProvider.h"

wxTipProvider * wxCreateFileTipProvider(const wxString& filename,  size_t currentTip);
bool wxShowTip(wxWindow *parent,  wxTipProvider *tipProvider,  bool showAtStartup = TRUE);
