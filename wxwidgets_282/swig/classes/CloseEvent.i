#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxCloseEvent

%ignore wxCloseEvent::GetForce;
%ignore wxCloseEvent::GetSessionEnding;
%ignore wxCloseEvent::SetForce;

%import "include/wxObject.h"
%import "include/wxEvent.h"

%include "include/wxCloseEvent.h"
