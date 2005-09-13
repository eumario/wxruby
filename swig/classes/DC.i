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

%import "include/wxObject.h"

%include "include/wxDC.h"

%extend wxDC {

    VALUE free() 
    {
        delete self;
        return Qnil;
    }
}
