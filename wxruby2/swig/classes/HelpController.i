// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxHelpController
GC_MANAGE_AS_OBJECT(wxHelpController);

%{
#include <wx/help.h>
%}

%rename(Init) wxHelpController::Initialize;

%import "include/wxObject.h"

%include "include/wxHelpController.h"
