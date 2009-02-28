// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module wxAboutDialogInfo
GC_MANAGE(wxAboutDialogInfo);

%{
#include <wx/aboutdlg.h>
%}


%include "include/wxAboutDialogInfo.h"
