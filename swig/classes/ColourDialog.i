#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxColourDialog

%{
#include <wx/colordlg.h>
%}

%include "include/wxColourDialog.h"
