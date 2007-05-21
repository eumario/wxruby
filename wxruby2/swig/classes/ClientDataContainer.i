// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxClientDataContainer
GC_MANAGE(wxClientDataContainer);

%{
#include <wx/clntdata.h>
%}


%include "include/wxClientDataContainer.h"
