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

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxControl.h"

%include "include/wxDatePickerCtrl.h"
