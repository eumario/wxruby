// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxRegion
GC_MANAGE(wxRegion);

# FIXME:  Figure out how to make SWIG like this
%ignore GetBox(long&  x , long&  y , long&  width , long&  height) const;

%include "include/wxRegion.h"

