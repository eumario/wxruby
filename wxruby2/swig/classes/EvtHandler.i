#   Copyright 2004 by Kevin Smith
#   released under the wxWidgets license
#   as part of the wxRuby project
%include "../common.i"

%{
#include <wx/calctrl.h>
%}

%module(directors="1") wxEvtHandler

%ignore wxEvtHandler::Connect;
%ignore wxEvtHandler::Disconnect;

%include "include/wxEvtHandler.h"

%{
    static VALUE callbacks = Qnil;
%}

%{
static void internal_connect(VALUE self, int firstId, int lastId, 
                wxEventType eventType, wxObjectEventFunction function)
{
    
    wxEvtHandler *cppSelf = (wxEvtHandler *) 0 ;
    SWIG_ConvertPtr(self, (void **) &cppSelf, SWIGTYPE_p_wxEvtHandler, 1);

    VALUE func = rb_funcall(rb_cProc, rb_intern("new"), 0);
    rb_global_variable(&callbacks);
    if(callbacks == Qnil)
        callbacks = rb_ary_new();
    rb_ary_push(callbacks, func);

    wxObject* userData = new wxRbCallback(func);
    (cppSelf)->Connect(firstId, lastId, eventType, function, userData);
}

static VALUE internal_evt_with_id(int argc, VALUE *argv, VALUE self, 
        wxObjectEventFunction function, wxEventType eventType) 
{
    if (argc != 1)
        rb_raise(rb_eArgError, "wrong # of arguments(%d for 1)",argc);
        
    int id = NUM2INT(argv[0]);
    //printf("evt_with_id(%d) %s\n", id, rb_block_given_p() ? "with block" : "");

    internal_connect(self, id, id, eventType, function);
    return Qnil;
}

static VALUE internal_evt_no_parameters(int argc, VALUE *argv, VALUE self, 
        wxObjectEventFunction function, wxEventType eventType) 
{
    if (argc != 0)
        rb_raise(rb_eArgError, "wrong # of arguments(%d for 0)",argc);
        
    //printf("evt_no_parameters() %s\n", rb_block_given_p() ? "with block" : "");
    internal_connect(self, -1, -1, eventType, function);
    return Qnil;
}

static VALUE connect(int argc, VALUE *argv, VALUE self) 
{
    if (argc != 3)
        rb_raise(rb_eArgError, "wrong # of arguments(%d for 3)", argc);

    int id = NUM2INT(argv[0]);
    int lastId = NUM2INT(argv[1]);
    int type = NUM2INT(argv[2]);
    
    wxObjectEventFunction function = 
        (wxObjectEventFunction )&wxRbCallback::GenericEventThunker;

    internal_connect(self, id, lastId, type, function);
    return Qnil;
}

static VALUE evt_menu(int argc, VALUE *argv, VALUE self) 
{
    wxObjectEventFunction function = 
        (wxObjectEventFunction )&wxRbCallback::CommandEventThunker;
    return internal_evt_with_id(argc, argv, self, function, wxEVT_COMMAND_MENU_SELECTED);
}

static VALUE evt_choice(int argc, VALUE *argv, VALUE self) 
{
    wxObjectEventFunction function = 
        (wxObjectEventFunction )&wxRbCallback::CommandEventThunker;
    return internal_evt_with_id(argc, argv, self, function, wxEVT_COMMAND_CHOICE_SELECTED);
}

static VALUE evt_calendar(int argc, VALUE *argv, VALUE self) 
{
    wxObjectEventFunction function = 
        (wxObjectEventFunction )&wxRbCallback::CalendarEventThunker;
    return internal_evt_with_id(argc, argv, self, function, wxEVT_CALENDAR_DOUBLECLICKED);
}

static VALUE evt_calendar_sel_changed(int argc, VALUE *argv, VALUE self) 
{
    wxObjectEventFunction function = 
        (wxObjectEventFunction )&wxRbCallback::CalendarEventThunker;
    return internal_evt_with_id(argc, argv, self, function, wxEVT_CALENDAR_SEL_CHANGED);
}

static VALUE evt_calendar_day(int argc, VALUE *argv, VALUE self) 
{
    wxObjectEventFunction function = 
        (wxObjectEventFunction )&wxRbCallback::CalendarEventThunker;
    return internal_evt_with_id(argc, argv, self, function, wxEVT_CALENDAR_DAY_CHANGED);
}

static VALUE evt_calendar_month(int argc, VALUE *argv, VALUE self) 
{
    wxObjectEventFunction function = 
        (wxObjectEventFunction )&wxRbCallback::CalendarEventThunker;
    return internal_evt_with_id(argc, argv, self, function, wxEVT_CALENDAR_MONTH_CHANGED);
}

static VALUE evt_calendar_year(int argc, VALUE *argv, VALUE self) 
{
    wxObjectEventFunction function = 
        (wxObjectEventFunction )&wxRbCallback::CalendarEventThunker;
    return internal_evt_with_id(argc, argv, self, function, wxEVT_CALENDAR_YEAR_CHANGED);
}

static VALUE evt_calendar_weekday_clicked(int argc, VALUE *argv, VALUE self) 
{
    wxObjectEventFunction function = 
        (wxObjectEventFunction )&wxRbCallback::CalendarEventThunker;
    return internal_evt_with_id(argc, argv, self, function, wxEVT_CALENDAR_WEEKDAY_CLICKED);
}

static VALUE evt_update_ui(int argc, VALUE *argv, VALUE self) 
{
    wxObjectEventFunction function = 
        (wxObjectEventFunction )&wxRbCallback::UpdateUIEventThunker;
    return internal_evt_with_id(argc, argv, self, function, wxEVT_UPDATE_UI);
}

static VALUE evt_paint(int argc, VALUE *argv, VALUE self) 
{
    wxObjectEventFunction function = 
        (wxObjectEventFunction )&wxRbCallback::PaintEventThunker;
    return internal_evt_no_parameters(argc, argv, self, function, wxEVT_PAINT);
}

static VALUE evt_close(int argc, VALUE *argv, VALUE self) 
{
    wxObjectEventFunction function = 
        (wxObjectEventFunction )&wxRbCallback::CloseEventThunker;
    return internal_evt_no_parameters(argc, argv, self, function, wxEVT_CLOSE_WINDOW);
}

%}

%init %{
    rb_define_method(cWxEvtHandler.klass, "connect", VALUEFUNC(connect), -1);
    rb_define_method(cWxEvtHandler.klass, "evt_menu", VALUEFUNC(evt_menu), -1);
    rb_define_method(cWxEvtHandler.klass, "evt_choice", VALUEFUNC(evt_choice), -1);
    rb_define_method(cWxEvtHandler.klass, "evt_calendar", VALUEFUNC(evt_calendar), -1);
    rb_define_method(cWxEvtHandler.klass, "evt_calendar_sel_changed", VALUEFUNC(evt_calendar_sel_changed), -1);
    rb_define_method(cWxEvtHandler.klass, "evt_calendar_day", VALUEFUNC(evt_calendar_day), -1);
    rb_define_method(cWxEvtHandler.klass, "evt_calendar_month", VALUEFUNC(evt_calendar_month), -1);
    rb_define_method(cWxEvtHandler.klass, "evt_calendar_year", VALUEFUNC(evt_calendar_year), -1);
    rb_define_method(cWxEvtHandler.klass, "evt_calendar_weekday_clicked", VALUEFUNC(evt_calendar_weekday_clicked), -1);
    rb_define_method(cWxEvtHandler.klass, "evt_update_ui", VALUEFUNC(evt_update_ui), -1);

    rb_define_method(cWxEvtHandler.klass, "evt_paint", VALUEFUNC(evt_paint), -1);
    rb_define_method(cWxEvtHandler.klass, "evt_close", VALUEFUNC(evt_close), -1);

%}
