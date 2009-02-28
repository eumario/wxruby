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

// We only support the version which returns its value as a
// RichTextAttr. Note that these methods are further manipulated in ruby
// so that they accept a single argument and return the RichTextAttr
// object.
%ignore wxRichTextCtrl::GetStyle(long position, wxTextAttr& style);
%ignore wxRichTextCtrl::GetStyle(long position, wxTextAttrEx& style);
%ignore wxRichTextCtrl::GetStyleForRange(const wxRichTextRange& range, 
                                         wxTextAttr& style);
%ignore wxRichTextCtrl::GetStyleForRange(const wxRichTextRange& range, 
                                         wxTextAttrEx& style);
%ignore wxRichTextCtrl::GetUncombinedStyle(long position, wxTextAttr& style);
%ignore wxRichTextCtrl::GetUncombinedStyle(long position, wxTextAttrEx& style);

// This is unsupported - class is not ported
%ignore wxRichTextCtrl::WriteImage(const wxRichTextImageBlock& imageBlock);

// Ignore the versions that use TextAttrEx as not used in wxRuby
%ignore  wxRichTextCtrl::HasCharacterAttributes(const wxRichTextRange& range,
                                                const wxTextAttrEx& style);
%ignore  wxRichTextCtrl::HasParagraphAttributes(const wxRichTextRange& range,
                                                const wxTextAttrEx& style);

%ignore wxRichTextCtrl::SetBasicStyle(const wxTextAttrEx& style);
%ignore wxRichTextCtrl::SetStyle(long start, long end, const wxTextAttrEx& style);
%ignore wxRichTextCtrl::SetStyle(long start, long end, const wxTextAttr& style);
%ignore wxRichTextCtrl::SetStyleEx(long start, long end,
                                   const wxTextAttrEx& style,
                                   int flags = wxRICHTEXT_SETSTYLE_WITH_UNDO);


%feature("nodirector") wxRichTextCtrl::Scroll;
%feature("nodirector") wxRichTextCtrl::GetViewStart;
%feature("nodirector") wxRichTextCtrl::GetScrollPixelsPerUnit;

// Deal with some output values from TextCtrl methods - PositionToXY
%apply long * OUTPUT { long * }
%apply long * OUTPUT { wxTextCoord *col, wxTextCoord *row }

// GetViewStart
%apply int * OUTPUT { int * }

%apply SWIGTYPE *DISOWN { wxRichTextStyleSheet* styleSheet };


%import "include/wxObject.h"
%import "include/wxWindow.h"
%import "include/wxControl.h"
%import "include/wxTextCtrl.h"

%include "include/wxRichTextCtrl.h"
