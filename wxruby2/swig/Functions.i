#   Copyright 2004 by Kevin Smith
#   released under the wxWidgets license
#   as part of the wxRuby project

%module(directors="1") wxFunctions

%include "common.i"

%{
#include <wx/image.h>

void log_message(VALUE self, VALUE text)
{
    wxLogMessage("%s", STR2CSTR(text));
}

void log_status(int argc, VALUE *argv, VALUE self)
{
    if(TYPE(argv[0])==T_DATA) {
        wxFrame *ptr;
        Data_Get_Struct(argv[0], wxFrame, ptr);
        VALUE str = rb_f_sprintf(argc-1, &argv[1]);
        wxLogStatus(ptr,StringValuePtr(str));
    }
    else {
        VALUE str = rb_f_sprintf(argc, argv);
        wxLogStatus(StringValuePtr(str));
    }

}


%}

void wxInitAllImageHandlers();

%init %{
    extern VALUE mWx;
    rb_define_method(mWx, "log_message", VALUEFUNC(log_message), 1);
    rb_define_method(mWx, "log_status", VALUEFUNC(log_status), -1);

%}
