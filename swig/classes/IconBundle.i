// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxIconBundle
GC_MANAGE(wxIconBundle);

%feature("nodirector") wxIconBundle;
%feature("nodirector") ~wxIconBundle;


%include "include/wxIconBundle.h"
