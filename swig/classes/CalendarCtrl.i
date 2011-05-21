// Copyright 2004-2011, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxCalendarCtrl
GC_MANAGE_AS_WINDOW(wxCalendarCtrl);
SWIG_WXWINDOW_NO_USELESS_VIRTUALS(wxCalendarCtrl);

%include "../shared/datetime.i"

%{
#include <wx/calctrl.h>
%}

// Custom implementation for Ruby
%ignore wxCalendarCtrl::HitTest;

// These are managed by the CalendarCtrl once set via set_attr
%apply SWIGTYPE *DISOWN { wxCalendarDateAttr* attr };

%extend wxCalendarCtrl {
  VALUE hit_test(wxPoint& pos)
  {
    wxDateTime hit_date;
    wxDateTime::WeekDay hit_wkday;
    wxCalendarHitTestResult hit = $self->HitTest(pos, &hit_date, &hit_wkday);
    if ( hit == wxCAL_HITTEST_HEADER ) {
      return(INT2NUM(hit_wkday));
    }
    else if ( hit == wxCAL_HITTEST_DAY ) {
      return(wxRuby_wxDateTimeToRuby(hit_date));
    }
    // Assume that hit == wxCAL_HITTEST_NOWHERE
    return Qnil;
  }
};



%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxControl.h"

%include "include/wxCalendarCtrl.h"
