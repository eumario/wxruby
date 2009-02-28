// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxRichTextStyleListBox
GC_MANAGE_AS_WINDOW(wxRichTextStyleListBox);
SWIG_WXWINDOW_NO_USELESS_VIRTUALS(wxRichTextStyleListBox);

%{
#include <wx/richtext/richtextstyles.h>
%}

%apply SWIGTYPE *DISOWN { wxRichTextStyleSheet* styleSheet };

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxPanel.h"
%import "include/wxVScrolledWindow.h"
%import "include/wxVListBox.h"

// This should strictly be imported, but including it seems to confuse
// SWIG (1.3.33) and cause it to use a strange parent for the call to
// rb_define_class_under in the generated C++ code. It shouldn't make a
// functional difference.
// 
// %import "include/wxHtmlListBox.h"

%include "include/wxRichTextStyleListBox.h"
