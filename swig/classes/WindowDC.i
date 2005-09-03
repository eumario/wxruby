#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

%include "../common.i"

%module(directors="1") wxWindowDC

%typemap(in,numinputs=0) (wxCoord * w , wxCoord * h , wxCoord * descent, wxCoord * externalLeading, wxFont *font) (wxCoord a, wxCoord b, wxCoord c, wxCoord d, wxFont f) {
	$1=&a;
	$2=&b;
	$3=&c;
	$4=&d;
	$5=&f;
}

%typemap(argout) (wxCoord * w , wxCoord * h , wxCoord * descent, wxCoord * externalLeading, wxFont *font) {
	$result = rb_ary_new();
	rb_ary_push($result, INT2NUM(*$1));
	rb_ary_push($result, INT2NUM(*$2));
	rb_ary_push($result, INT2NUM(*$3));
	rb_ary_push($result, INT2NUM(*$4));
	rb_ary_push($result, SWIG_NewPointerObj((void *) $5, SWIGTYPE_p_wxFont,0));
}

%typemap(in,numinputs=0) (wxCoord * width , wxCoord * height , wxCoord * heightLine, wxFont *font) (wxCoord a, wxCoord b, wxCoord c, wxFont f) {
	$1=&a;
	$2=&b;
	$3=&c;
	$4=&f;
}

%typemap(argout) (wxCoord * width , wxCoord * height , wxCoord * heightLine, wxFont *font) {
	$result = rb_ary_new();
	rb_ary_push($result, INT2NUM(*$1));
	rb_ary_push($result, INT2NUM(*$2));
	rb_ary_push($result, INT2NUM(*$3));
	rb_ary_push($result, SWIG_NewPointerObj((void *) $4, SWIGTYPE_p_wxFont,0));
}

%import "include/wxObject.h"
%import "include/wxDC.h"

%include "include/wxWindowDC.h"
