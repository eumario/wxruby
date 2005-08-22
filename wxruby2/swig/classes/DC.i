#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxDC
%feature("nodirector") wxDC; // abstract base class with pure virtual methods

%{
//NO_DIRECTOR
%}

%ignore wxDC::CacheEnabled;
%ignore wxDC::ClearCache;
%ignore wxDC::EnableCache;

%ignore wxDC::StartPage;

%typemap(in,numinputs=0) (wxCoord * w , wxCoord * h , wxCoord * descent, wxCoord * externalLeading) (wxCoord a, wxCoord b, wxCoord c, wxCoord d) {
	$1=&a;
	$2=&b;
	$3=&c;
	$4=&d;
}

%typemap(argout) (wxCoord * w , wxCoord * h , wxCoord * descent, wxCoord * externalLeading) {
	$result = rb_ary_new();
	rb_ary_push($result, INT2NUM(*$1));
	rb_ary_push($result, INT2NUM(*$2));
	rb_ary_push($result, INT2NUM(*$3));
	rb_ary_push($result, INT2NUM(*$4));
}

%import "include/wxObject.h"

%include "include/wxDC.h"

%extend wxDC {

    VALUE free() 
    {
        delete self;
        return Qnil;
    }
}
