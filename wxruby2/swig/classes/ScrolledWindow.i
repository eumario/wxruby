#   Copyright 2004 by Kevin Smith
#   released under the wxWidgets license
#   as part of the wxRuby project
%include "../common.i"

%{
#include <wx/scrolwin.h>
%}

%module(directors="1") wxScrolledWindow
%ignore wxScrolledWindow::wxScrolledWindow();

%include "include/wxScrolledWindow.h"
