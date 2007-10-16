// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"


%module(directors="1") wxKeyEvent
GC_MANAGE_AS_EVENT(wxKeyEvent);

%import "include/wxObject.h"
%import "include/wxEvent.h"

%include "include/wxKeyEvent.h"

%extend wxKeyEvent {

    VALUE key_code()
    {
        return INT2NUM(self->GetKeyCode());
    }
}
