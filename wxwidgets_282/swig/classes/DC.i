#   Copyright 2004-2007 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxDC

// raises 'void value is not ignored as it should be' compile error
%ignore wxDC::StartPage;

// wxList version is now 'type-safe' so we won't be using that version instead
%ignore DrawLines(const wxList * points, wxCoord xoffset = 0, wxCoord yoffset = 0);
%ignore DrawPolygon(const wxList * points , wxCoord xoffset = 0, wxCoord yoffset = 0, int  fill_style = wxODDEVEN_RULE) ;


%rename(GetDimensions) wxDC::GetSize(wxCoord * width , wxCoord * height);
%rename(GetDimensionsMM) wxDC::GetSizeMM(wxCoord *width , wxCoord *height) const;
%rename(GetTextSize) wxDC::GetTextExtent(const wxString& string) const;
%rename(GetMultiLineTextSize) wxDC::GetMultiLineTextExtent(const wxString& string) const;


%import "include/wxObject.h"

%include "include/wxDC.h"
