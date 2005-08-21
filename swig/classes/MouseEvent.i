#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxMouseEvent

%ignore wxMouseEvent::wxMouseEvent;

%import "include/wxObject.h"
%import "include/wxEvent.h"

%include "include/wxMouseEvent.h"
