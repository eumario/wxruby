#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%{
#include <wx/scrolwin.h>
%}

%module(directors="1") wxScrolledWindow
%ignore wxScrolledWindow::wxScrolledWindow();

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxPanel.h"

%include "include/wxScrolledWindow.h"
