// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxSashLayoutWindow
GC_MANAGE_AS_WINDOW(wxSashLayoutWindow);

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
