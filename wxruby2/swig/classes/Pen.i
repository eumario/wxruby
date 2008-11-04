// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxPen
GC_MANAGE_AS_OBJECT(wxPen);

// special free func is needed to clean up Dashes array if it has been
// set; wxWidgets does not do this automatically so will leak if not
// dealt with.
%{
  void GC_free_wxPen(wxPen *pen) {
    SWIG_RubyRemoveTracking(pen);
    wxDash *dashes;
    int dash_count = pen->GetDashes(&dashes);
    if ( dash_count )
      delete dashes;
    delete pen;
  }
%}

%feature("freefunc") wxPen "GC_free_wxPen";

// dealt with below - these require special handling becaause of the use
// of wxDash array, which cannot be freed until the pen is disposed of
// or until a new dash pattern is specified.
%ignore wxPen::GetDashes;
%ignore wxPen::SetDashes;

%extend wxPen {
  // Returns a ruby array with the dash lengths
  VALUE get_dashes() {
    VALUE rb_dashes = rb_ary_new();
    wxDash* dashes;
    int dash_count = $self->GetDashes(&dashes);
    for ( int i = 0; i < dash_count; i++ )
      {
        rb_ary_push(rb_dashes, INT2NUM( dashes[i] ) );
      }
    return rb_dashes;
  }

  // Sets the dashes to have the lengths defined in the ruby array of ints
  void set_dashes(VALUE rb_dashes) {
    // Check right parameter type
    if ( TYPE(rb_dashes) != T_ARRAY )
      rb_raise(rb_eTypeError, 
               "Wrong argument type for set_dashes, should be Array");

    // Get old value in case it needs to be deallocated to avoid leaking
    wxDash* old_dashes;
    int old_dashes_count = $self->GetDashes(&old_dashes);

    // Create a C++ wxDash array to hold the new dashes, and populate
    int new_dash_count = RARRAY_LEN(rb_dashes);
    wxDash* new_dashes = new wxDash[ new_dash_count ];
    for ( int i = 0; i < new_dash_count; i++ )
      {
        new_dashes[i] = NUM2INT(rb_ary_entry(rb_dashes, i));
      }
    $self->SetDashes(new_dash_count, new_dashes);

    // Clean up the old if it existed
    if ( old_dashes_count )
      delete old_dashes;
  }
};

%import "include/wxObject.h"
%import "include/wxGDIObject.h"

%include "include/wxPen.h"
