#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxMemoryDC

%import "include/wxObject.h"
// TODO: Figure out why the following line causes swig 
// to remove the allocator for this class
//%import "include/wxDC.h"

%include "include/wxMemoryDC.h"
