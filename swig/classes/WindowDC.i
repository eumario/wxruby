#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxWindowDC

%ignore GetTextExtent;

// only support the variants that return an object
%ignore GetSize(int*  width , int*  height ) const;

// redundant with good typemaps
%ignore DrawLines(int  n , wxPoint  points[] , wxCoord xoffset = 0, wxCoord yoffset = 0);
%ignore DrawPolygon(int  n , wxPoint  points[] , wxCoord xoffset = 0, wxCoord yoffset = 0, int  fill_style = wxODDEVEN_RULE) ;

%import "include/wxObject.h"
%import "include/wxDC.h"

%include "include/wxWindowDC.h"
