// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxHtmlHelpController
GC_MANAGE_AS_OBJECT(wxHtmlHelpController);

%{
#include <wx/html/helpctrl.h>
%}

%ignore wxHtmlHelpController::CreateHelpFrame;

%import "include/wxObject.h"

%include "include/wxHtmlHelpController.h"
