#   Copyright 2004-2006 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxRegion

# FIXME:  Figure out how to make SWIG like this
%ignore GetBox(long&  x , long&  y , long&  width , long&  height) const;

%include "include/wxRegion.h"

