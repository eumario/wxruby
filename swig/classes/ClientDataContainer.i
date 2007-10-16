// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxClientDataContainer
GC_MANAGE(wxClientDataContainer);

%{
#include <wx/clntdata.h>
%}


%include "include/wxClientDataContainer.h"
