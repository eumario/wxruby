// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxFindReplaceData
GC_MANAGE_AS_OBJECT(wxFindReplaceData);

%{
#include <wx/fdrepdlg.h>
%}

%import "include/wxObject.h"

%include "include/wxFindReplaceData.h"
