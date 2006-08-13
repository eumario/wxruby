#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxSashLayoutWindow

%{
#include <wx/laywin.h>
#include <wx/sashwin.h>

%}

enum wxLayoutOrientation;
enum wxLayoutAlignment;


%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxSashWindow.h"


%include "include/wxSashLayoutWindow.h"
