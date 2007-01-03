#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxMouseEvent

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
