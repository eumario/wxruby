#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%{
#include <wx/scrolwin.h>
%}

%module(directors="1") wxScrolledWindow
%ignore wxScrolledWindow::wxScrolledWindow();

%include "include/wxScrolledWindow.h"
