#   Copyright 2004-2007 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxSizer

%ignore wxSizer::IsShown;

%feature("nodirector") wxSizer::CalcMin;

// Any nested sizers passed to Add() in are owned by C++, not GC'd by Ruby
%apply SWIGTYPE *DISOWN { wxSizer* sizer };

%import "include/wxObject.h"

%include "include/wxSizer.h"
