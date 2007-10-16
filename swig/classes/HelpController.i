// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxHelpController
GC_MANAGE_AS_OBJECT(wxHelpController);

%{
#include <wx/help.h>
%}

%rename(Init) wxHelpController::Initialize;

%import "include/wxObject.h"

%include "include/wxHelpController.h"
