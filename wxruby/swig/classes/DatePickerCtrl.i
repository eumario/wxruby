// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxDatePickerCtrl
GC_MANAGE_AS_WINDOW(wxDatePickerCtrl);
SWIG_WXWINDOW_NO_USELESS_VIRTUALS(wxDatePickerCtrl);

%include "../shared/datetime.i"

%{
#include <wx/datectrl.h>
%}

enum
{
    wxDP_DEFAULT = 0,
    wxDP_SPIN = 1,
    wxDP_DROPDOWN = 2,
    wxDP_SHOWCENTURY = 4,
    wxDP_ALLOWNONE = 8
};

// Dealt with below
%ignore wxDatePickerCtrl::GetRange;

%extend wxDatePickerCtrl {
   VALUE get_range() {
     wxDateTime dt1, dt2;
     $self->GetRange(&dt1, &dt2);
 
     VALUE items = rb_ary_new();
     rb_ary_push(items, wxRuby_wxDateTimeToRuby(dt1));
     rb_ary_push(items, wxRuby_wxDateTimeToRuby(dt2));
   
     return items;
   }
}
%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxControl.h"

%include "include/wxDatePickerCtrl.h"
