// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxIconBundle
GC_MANAGE(wxIconBundle);

%feature("nodirector") wxIconBundle;
%feature("nodirector") ~wxIconBundle;


%include "include/wxIconBundle.h"
