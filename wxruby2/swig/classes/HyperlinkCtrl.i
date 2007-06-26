// Copyright 2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxHyperlinkCtrl
GC_MANAGE_AS_WINDOW(wxHyperlinkCtrl);

%{
#include <wx/hyperlink.h>
%}

#define wxHL_CONTEXTMENU        0x0001
#define wxHL_ALIGN_LEFT         0x0002
#define wxHL_ALIGN_RIGHT        0x0004
#define wxHL_ALIGN_CENTRE       0x0008
#define wxHL_DEFAULT_STYLE      (wxHL_CONTEXTMENU|wxNO_BORDER|wxHL_ALIGN_CENTRE)

%ignore wxHyperlinkCtrl::wxHyperlinkCtrl();

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxControl.h"

%include "include/wxHyperlinkCtrl.h"
