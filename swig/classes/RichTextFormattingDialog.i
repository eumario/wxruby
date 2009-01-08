// Copyright 2004-2009, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxRichTextFormattingDialog
GC_MANAGE_AS_DIALOG(wxRichTextFormattingDialog);
SWIG_WXTOPLEVELWINDOW_NO_USELESS_VIRTUALS(wxRichTextFormattingDialog);

%{
#include <wx/richtext/richtextformatdlg.h>
%}
%include "../shared/richtext.i"




#define wxRICHTEXT_FORMAT_STYLE_EDITOR      0x0001
#define wxRICHTEXT_FORMAT_FONT              0x0002
#define wxRICHTEXT_FORMAT_TABS              0x0004
#define wxRICHTEXT_FORMAT_BULLETS           0x0008
#define wxRICHTEXT_FORMAT_INDENTS_SPACING   0x0010
#define wxRICHTEXT_FORMAT_LIST_STYLE        0x0020

#define wxRICHTEXT_FORMAT_HELP_BUTTON       0x0100


enum {
    wxRICHTEXT_BULLETINDEX_NONE = 0,
    wxRICHTEXT_BULLETINDEX_ARABIC,
    wxRICHTEXT_BULLETINDEX_UPPER_CASE,
    wxRICHTEXT_BULLETINDEX_LOWER_CASE,
    wxRICHTEXT_BULLETINDEX_UPPER_CASE_ROMAN,
    wxRICHTEXT_BULLETINDEX_LOWER_CASE_ROMAN,
    wxRICHTEXT_BULLETINDEX_OUTLINE,
    wxRICHTEXT_BULLETINDEX_SYMBOL,
    wxRICHTEXT_BULLETINDEX_BITMAP,
    wxRICHTEXT_BULLETINDEX_STANDARD
};

#define wxRICHTEXT_FORMAT_PARAGRAPH         (wxRICHTEXT_FORMAT_INDENTS_SPACING | wxRICHTEXT_FORMAT_BULLETS | wxRICHTEXT_FORMAT_TABS | wxRICHTEXT_FORMAT_FONT)
#define wxRICHTEXT_FORMAT_CHARACTER         (wxRICHTEXT_FORMAT_FONT)
#define wxRICHTEXT_FORMAT_STYLE             (wxRICHTEXT_FORMAT_PARAGRAPH | wxRICHTEXT_FORMAT_STYLE_EDITOR)

%extend wxRichTextFormattingDialog {
  wxRichTextAttr* __bogus() {
    return new wxRichTextAttr();
  }
}

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxTopLevelWindow.h"
%import "include/wxDialog.h"
%import "include/wxPropertySheetDialog.h"

%include "include/wxRichTextFormattingDialog.h"

