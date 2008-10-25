// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

// Shared features used by the RichText classes

// Used by several classes to load and save rich text content to files
// and streams.
%include "streams.i"

// The wxWidgets RichText API in several places represents and returns
// ranges of text selections with a special class. It doesn't add
// anything much that Ruby's own range class doesn't, so deal with using
// typemaps
%typemap(in) wxRichTextRange& {
  int start = NUM2INT( rb_funcall( $input, rb_intern("begin"), 0));
  int end   = NUM2INT( rb_funcall( $input, rb_intern("end"), 0));
  wxRichTextRange rng = wxRichTextRange(start, end);
  $1 = &rng;
}

%typemap(out) wxRichTextRange& {
  $result = rb_range_new( LONG2NUM( $1->GetStart() ),
                          LONG2NUM( $1->GetEnd() ),
                          0 );     
}

%typemap(typecheck) wxRichTextRange& "$1 = ( CLASS_OF($input) == rb_cRange );"

 // Used as in/out parameters by some other selection-getting methods
%apply int *OUTPUT { long * from , long * to };

