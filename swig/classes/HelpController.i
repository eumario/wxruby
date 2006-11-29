#   Copyright 2004-2006 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxHelpController

%{
#include <wx/help.h>
%}

%rename(Init) wxHelpController::Initialize;

%import "include/wxObject.h"

%include "include/wxHelpController.h"
