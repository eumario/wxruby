// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxStaticBoxSizer
GC_MANAGE_AS_SIZER(wxStaticBoxSizer);

// shared functions
%include "../shared/sizers.i"

// Must ensure that the C++ detach method is called, else the associated
// StaticBox will be double-freed
%feature(nodirector) wxStaticBoxSizer::Detach;
%feature(nodirector) wxStaticBoxSizer::Remove;
%feature(nodirector) wxStaticBoxSizer::Clear;


%import "include/wxObject.h"
%import "include/wxSizer.h"
%import "include/wxBoxSizer.h"

%include "include/wxStaticBoxSizer.h"
