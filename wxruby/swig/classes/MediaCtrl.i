//  Copyright 2004-2007 by wxRuby development team
//  released under the under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxMediaCtrl
GC_MANAGE_AS_WINDOW(wxMediaCtrl);
SWIG_WXWINDOW_NO_USELESS_VIRTUALS(wxMediaCtrl);

%{
#include <wx/mediactrl.h>
%}

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxControl.h"
%include "include/wxMediaCtrl.h"
