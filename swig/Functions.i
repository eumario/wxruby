#   Copyright 2004 by Kevin Smith
#   released under the wxWidgets license
#   as part of the wxRuby project

%module(directors="1") wxFunctions

%include "common.i"

%{
void log_message(VALUE self, VALUE text)
{
    wxLogMessage("%s", STR2CSTR(text));
}

void log_status(VALUE self, const char* text)
{
    wxLogStatus("%s", STR2CSTR(text));
}

%}

%init %{
    extern VALUE mWx;
    rb_define_method(mWx, "log_message", VALUEFUNC(log_message), 1);
    rb_define_method(mWx, "log_status", VALUEFUNC(log_status), 1);

%}
