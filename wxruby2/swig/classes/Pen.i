#   Copyright 2004 by Kevin Smith
#   released under the wxWidgets license
#   as part of the wxRuby project
%include "../common.i"

%module(directors="1") wxPen

%ignore wxPen::SetStipple;

# under GTK, these don't exist
#ifndef SWIGMAC
 #ifndef SWIGWIN
  %ignore GetStipple;
  %ignore wxPen::wxPen(const wxBitmap&, int&);
 #endif
#endif

# For reasons I don't understand, the
# constructor ignore above is not solving 
# the compile error. So ignore the whole 
# class for now
%runtime %{
//@@if defined(__WXMSWIN__) || defined(__WXMAC__)
%}


%include "include/wxPen.h"
 