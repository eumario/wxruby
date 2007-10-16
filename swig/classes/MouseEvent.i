// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxMouseEvent
GC_MANAGE_AS_EVENT(wxMouseEvent);

// the symbolic names for the mouse buttons
enum
{
    wxMOUSE_BTN_ANY     = -1,
    wxMOUSE_BTN_NONE    = 0,
    wxMOUSE_BTN_LEFT    = 1,
    wxMOUSE_BTN_MIDDLE  = 2,
    wxMOUSE_BTN_RIGHT   = 3
};

%ignore wxMouseEvent::wxMouseEvent;

%import "include/wxObject.h"
%import "include/wxEvent.h"

%include "include/wxMouseEvent.h"
