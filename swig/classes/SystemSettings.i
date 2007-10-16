// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module wxSystemSettings
GC_MANAGE_AS_OBJECT(wxSystemSettings);

%typemap(in) wxSystemColour "$1 = (wxSystemColour)NUM2INT($input);"
%typemap(out) wxSystemColour " $result = INT2NUM((int)$1);"
%typemap(in) wxSystemFont "$1 = (wxSystemFont)NUM2INT($input);"
%typemap(out) wxSystemFont "$result = INT2NUM((int)$1);"
%typemap(in) wxSystemMetric "$1 = (wxSystemMetric)NUM2INT($input);"
%typemap(out) wxSystemMetric "$result = INT2NUM((int)$1);"

%import "include/wxObject.h"

%include "include/wxSystemSettings.h"
