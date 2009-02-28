// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxCalendarCtrl
GC_MANAGE_AS_WINDOW(wxCalendarCtrl);
SWIG_WXWINDOW_NO_USELESS_VIRTUALS(wxCalendarCtrl);

%include "../shared/datetime.i"

%{
#include <wx/calctrl.h>
%}

// These are managed by the CalendarCtrl once set via set_attr
%apply SWIGTYPE *DISOWN { wxCalendarDateAttr* attr };

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxControl.h"

%include "include/wxCalendarCtrl.h"
