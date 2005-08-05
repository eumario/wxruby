#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxPen

%feature("nodirector") wxPen;

%ignore wxPen::SetStipple;
%ignore GetStipple;
%ignore wxPen::wxPen(const wxBitmap&, int);

# For reasons I dont understand, the
# constructor ignore above is not solving 
# the compile error. So ignore the whole 
# class for now
/*
%runtime %{
//@@if defined(__WXMSW__) || defined(__WXMAC__)
%}
*/

%include "include/wxPen.h"
