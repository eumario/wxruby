// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxCalendarCtrl
GC_MANAGE_AS_WINDOW(wxCalendarCtrl);

%include "../shared/datetime.i"

%{
#include <wx/calctrl.h>
%}



%typemap(in) wxCalendarDateBorder {
	$1 = (wxCalendarDateBorder)NUM2INT($input);
}

%typemap(out) wxCalendarDateBorder {
    $result = INT2NUM((int)$1);
}

%ignore wxCalendarCtrl::wxCalendarCtrl();

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxControl.h"

%include "include/wxCalendarCtrl.h"
