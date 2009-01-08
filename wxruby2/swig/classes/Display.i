// Copyright 2004-2009, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module wxDisplay
GC_MANAGE(wxDisplay);

%{
#include <wx/display.h>
%}

// Not supported for now
%ignore wxDisplay::ChangeMode;
%ignore wxDisplay::GetCurrentMode;
%ignore wxDisplay::GetModes;

%extend wxDisplay {
  // This is in the documentation, but missing from wx/display.h
  VALUE get_depth() { return INT2NUM( wxDisplayDepth() ); }
}
%include "include/wxDisplay.h"
