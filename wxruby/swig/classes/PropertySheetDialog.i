// Copyright 2004-2009, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxPropertySheetDialog
GC_MANAGE_AS_DIALOG(wxPropertySheetDialog);
SWIG_WXTOPLEVELWINDOW_NO_USELESS_VIRTUALS(wxPropertySheetDialog);

%{
#include <wx/propdlg.h>
%}

#define wxPROPSHEET_DEFAULT         0x0001
#define wxPROPSHEET_NOTEBOOK        0x0002
#define wxPROPSHEET_TOOLBOOK        0x0004
#define wxPROPSHEET_CHOICEBOOK      0x0008
#define wxPROPSHEET_LISTBOOK        0x0010
#define wxPROPSHEET_BUTTONTOOLBOOK  0x0020
#define wxPROPSHEET_TREEBOOK        0x0040
#define wxPROPSHEET_SHRINKTOFIT     0x0100

// Needs special handling to ensure the return value is cast to the
// correct book class, not the generic abstract parent class
// wxBookCtrlBase
%ignore wxPropertySheetDialog::GetBookCtrl;

%extend wxPropertySheetDialog {
  VALUE get_book_ctrl() {
    wxBookCtrlBase* book = $self->GetBookCtrl();
    return wxRuby_WrapWxObjectInRuby( (wxObject*)book) ;
  }
}

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxTopLevelWindow.h"
%import "include/wxDialog.h"

%include "include/wxPropertySheetDialog.h"
