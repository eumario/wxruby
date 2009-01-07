// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxListbook
GC_MANAGE_AS_WINDOW(wxListbook);
SWIG_WXWINDOW_NO_USELESS_VIRTUALS(wxListbook);

%{
#include <wx/listbook.h>
%}

%include "../shared/bookctrls.i"
BOOKCTRL_FEATURES(wxListbook);

#define wxListbookPage wxWindow

// wxListbook flags
#define wxLB_DEFAULT          wxBK_DEFAULT
#define wxLB_TOP              wxBK_TOP
#define wxLB_BOTTOM           wxBK_BOTTOM
#define wxLB_LEFT             wxBK_LEFT
#define wxLB_RIGHT            wxBK_RIGHT
#define wxLB_ALIGN_MASK       wxBK_ALIGN_MASK

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxControl.h"
%import "include/wxBookCtrlBase.h"

%include "include/wxListbook.h"
