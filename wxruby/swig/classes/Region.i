// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module wxRegion
GC_MANAGE(wxRegion);

// Figure out how to make SWIG like this
%ignore GetBox(long&  x , long&  y , long&  width , long&  height) const;


%constant const int wxIN_REGION   = wxInRegion;
%constant const int wxPART_REGION = wxPartRegion;

// tweak return value so that it is nil if not in region, so that a
// simple boolean test can be used in Ruby
%typemap(out) wxRegionContain {
  if ( $1 == wxOutRegion )
    $result = Qfalse;
  else
    $result = INT2NUM($1);
}

%include "include/wxRegion.h"

