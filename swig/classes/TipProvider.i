#   Copyright 2004 by Kevin Smith
#   released under the wxWidgets license
#   as part of the wxRuby project
%include "../common.i"

%module(directors="1") wxTipProvider

%{
#include <wx/tipdlg.h>
%}



%include "include/wxTipProvider.h"

wxTipProvider * wxCreateFileTipProvider(const wxString& filename,  size_t currentTip);
bool wxShowTip(wxWindow *parent,  wxTipProvider *tipProvider,  bool showAtStartup = TRUE);
