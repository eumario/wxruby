#   Copyright 2004 by Kevin Smith
#   released under the wxWidgets license
#   as part of the wxRuby project

%module(directors="1") wx

%include "common.i"

%{
IMPLEMENT_ABSTRACT_CLASS(wxRbCallback, wxObject);
%} 

%init %{
    extern void InitializeOtherModules();
    InitializeOtherModules();
%}

#define VERSION_STRING "wxRuby-SWIG 0.0.3"

int wxMessageBox(const wxString& message, const wxString& caption = "Message", int style = wxOK, wxWindow *parent = NULL, int x = -1, int y = -1);

%init %{
    rb_define_const(mWx,"XXX", INT2NUM(777));
printf("Defined XXX = %d\n", NUM2INT(rb_iv_get(mWx, "XXX")));
%}
