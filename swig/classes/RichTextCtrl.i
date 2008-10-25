// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxRichTextCtrl;
GC_MANAGE_AS_WINDOW(wxRichTextCtrl);
SWIG_WXWINDOW_NO_USELESS_VIRTUALS(wxRichTextCtrl);

%{
#include <wx/richtext/richtextctrl.h>
%}

%include "../shared/richtext.i"

%ignore wxRichTextCtrl::GetBuffer() const;

%import "include/wxObject.h"
%import "include/wxWindow.h"
%import "include/wxControl.h"
%include "include/wxRichTextCtrl.h"
