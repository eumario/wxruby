// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxRichTextEvent
GC_MANAGE_AS_EVENT(wxRichTextEvent);

%{
#include <wx/richtext/richtextctrl.h>
%}

// Needed to convert RichTextRange to ruby range class
%include "../shared/richtext.i"

%import "include/wxObject.h"
%import "include/wxEvent.h"
%import "include/wxCommandEvent.h"
%import "include/wxNotifyEvent.h"
%include "include/wxRichTextEvent.h"
