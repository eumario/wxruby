// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxWindowDC
GC_MANAGE_AS_OBJECT(wxWindowDC);

// only support the variants that return an object
%ignore GetSize(int*  width , int*  height ) const;

// wxList version is now 'type-safe' so we won't be using that version instead
%ignore DrawLines(const wxList * points, wxCoord xoffset = 0, wxCoord yoffset = 0);
%ignore DrawPolygon(const wxList * points , wxCoord xoffset = 0, wxCoord yoffset = 0, int  fill_style = wxODDEVEN_RULE) ;

%import "include/wxObject.h"
%import "include/wxDC.h"

%include "include/wxWindowDC.h"
