#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxDC

// avoid directors for pure virtuals
// for some reason, ignoring just this one avoids errors for the rest!?
%feature("nodirector") wxDC::GetCharHeight;

// Not sure why these are ignored
%ignore wxDC::CacheEnabled;
%ignore wxDC::ClearCache;
%ignore wxDC::EnableCache;
%ignore wxDC::StartPage;

// wxList version is now 'type-safe' so we won't be using that version instead
%ignore DrawLines(const wxList * points, wxCoord xoffset = 0, wxCoord yoffset = 0);
%ignore DrawPolygon(const wxList * points , wxCoord xoffset = 0, wxCoord yoffset = 0, int  fill_style = wxODDEVEN_RULE) ;


%import "include/wxObject.h"

%include "include/wxDC.h"