#   Copyright 2004-2006 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxHtmlHelpController

%{
#include <wx/html/helpctrl.h>
%}

%ignore wxHtmlHelpController::CreateHelpFrame;

%import "include/wxObject.h"

%include "include/wxHtmlHelpController.h"
