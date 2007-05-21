// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxSplashScreen
GC_MANAGE_AS_FRAME(wxSplashScreen);

%{
#include <wx/splash.h>
%}

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxFrame.h"


%include "include/wxSplashScreen.h"
