// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxProgressDialog
GC_MANAGE_AS_DIALOG(wxProgressDialog);
SWIG_WXTOPLEVELWINDOW_NO_USELESS_VIRTUALS(wxProgressDialog);

%{
#include <wx/progdlg.h>
%}

// These two have problematic arguments; they accept a bool pointer
// which will be set to true if "skip" was pressed since the last
// update. Dealt with below.
%ignore wxProgressDialog::Pulse;
%ignore wxProgressDialog::Update;

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"
%import "include/wxWindow.h"
%import "include/wxDialog.h"

// In wxRuby there are two versions of each of these methods, the
// standard one which returns just true/false depending on whether it
// has been aborted, and a special one which returns a pair of values,
// true/false for "aborted" and then true/false for "skipped"
%extend wxProgressDialog {
  VALUE pulse(VALUE rb_msg = Qnil)
  {
    wxString new_msg;
    if ( rb_msg == Qnil )
      new_msg = wxEmptyString;
    else
      new_msg = wxString( StringValuePtr(rb_msg), wxConvUTF8 );

    if ( $self->Pulse(new_msg) )
      return Qtrue;
    else
      return Qfalse;
  }

  VALUE pulse_and_check(VALUE rb_msg = Qnil)
  {
    VALUE ret = rb_ary_new();

    wxString new_msg;
    if ( rb_msg == Qnil )
      new_msg = wxEmptyString;
    else
      new_msg = wxString( StringValuePtr(rb_msg), wxConvUTF8 );
    
    bool skip = false;
    if ( $self->Pulse(new_msg, &skip) )
      rb_ary_push(ret, Qtrue);
    else 
      rb_ary_push(ret, Qfalse);
    
    rb_ary_push(ret, ( skip ? Qtrue : Qfalse) );

    return ret;
  }

  VALUE update(int value, VALUE rb_msg = Qnil)
  {
    wxString new_msg;
    if ( rb_msg == Qnil )
      new_msg = wxEmptyString;
    else
      new_msg = wxString( StringValuePtr(rb_msg), wxConvUTF8 );

    if ( $self->Update(value, new_msg) )
      return Qtrue;
    else
      return Qfalse;
  }

  VALUE update_and_check(int value, VALUE rb_msg = Qnil)
  {
    VALUE ret = rb_ary_new();

    wxString new_msg;
    if ( rb_msg == Qnil )
      new_msg = wxEmptyString;
    else
      new_msg = wxString( StringValuePtr(rb_msg), wxConvUTF8 );

    bool skip = false;
    if ( $self->Update(value, new_msg, &skip) )
      rb_ary_push(ret, Qtrue);
    else 
      rb_ary_push(ret, Qfalse);

    rb_ary_push(ret, ( skip ? Qtrue : Qfalse) );

    return ret;
  }
}

%include "include/wxProgressDialog.h"
