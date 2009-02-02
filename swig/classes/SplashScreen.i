// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxSplashScreen
GC_MANAGE_AS_FRAME(wxSplashScreen);
SWIG_WXTOPLEVELWINDOW_NO_USELESS_VIRTUALS(wxSplashScreen);

%{
#include <wx/splash.h>
%}

// SplashScreen constants
#define wxSPLASH_CENTRE_ON_PARENT   0x01
#define wxSPLASH_CENTRE_ON_SCREEN   0x02
#define wxSPLASH_NO_CENTRE          0x00
#define wxSPLASH_TIMEOUT            0x04
#define wxSPLASH_NO_TIMEOUT         0x00


%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxFrame.h"


%include "include/wxSplashScreen.h"
