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

// Use the non-const one, identical signature
%ignore wxRichTextCtrl::GetBuffer() const;

// FIXME
// SWIG's normal wrapping of these causes a compile error 
%ignore wxRichTextCtrl::IsSelectionAligned;
%ignore wxRichTextCtrl::IsSelectionBold;
%ignore wxRichTextCtrl::IsSelectionItalics;
%ignore wxRichTextCtrl::IsSelectionUnderlined;

// Deal with some output values from TextCtrl methods - PositionToXY
%apply long * OUTPUT { long * }
%apply long * OUTPUT { wxTextCoord *col, wxTextCoord *row }

%import "include/wxObject.h"
%import "include/wxWindow.h"
%import "include/wxControl.h"
%import "include/wxTextCtrl.h"

%include "include/wxRichTextCtrl.h"
