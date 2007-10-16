// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxScreenDC
GC_MANAGE_AS_OBJECT(wxScreenDC);

// wxList version is now 'type-safe' so we won't be using that version instead
%ignore DrawLines(const wxList * points, wxCoord xoffset = 0, wxCoord yoffset = 0);
%ignore DrawPolygon(const wxList * points , wxCoord xoffset = 0, wxCoord yoffset = 0, int  fill_style = wxODDEVEN_RULE) ;

%import "include/wxObject.h"
%import "include/wxDC.h"

%include "include/wxScreenDC.h"

