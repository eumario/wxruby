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
extern swig_class cWxEvent;
extern swig_class cWxCalendarEvent;
extern swig_class cWxCloseEvent;
extern swig_class cWxCommandEvent;
extern swig_class cWxIdleEvent;
extern swig_class cWxPaintEvent;
extern swig_class cWxUpdateUIEvent;

static int calendarEvents[] = 
{
    wxEVT_CALENDAR_SEL_CHANGED,
    wxEVT_CALENDAR_DAY_CHANGED,
    wxEVT_CALENDAR_MONTH_CHANGED,
    wxEVT_CALENDAR_YEAR_CHANGED,
    wxEVT_CALENDAR_DOUBLECLICKED,
    wxEVT_CALENDAR_WEEKDAY_CLICKED,
    -1
};

static int closeEvents[] =
{
    wxEVT_CLOSE_WINDOW,
    -1
};

static int commandEvents[] = 
{
    wxEVT_COMMAND_BUTTON_CLICKED,
    wxEVT_COMMAND_CHECKBOX_CLICKED,
    wxEVT_COMMAND_CHOICE_SELECTED,
    wxEVT_COMMAND_LISTBOX_SELECTED,
    wxEVT_COMMAND_LISTBOX_DOUBLECLICKED,
    wxEVT_COMMAND_CHECKLISTBOX_TOGGLED,
    wxEVT_COMMAND_TEXT_UPDATED,
    wxEVT_COMMAND_TEXT_ENTER,
    wxEVT_COMMAND_TEXT_URL,
    wxEVT_COMMAND_TEXT_MAXLEN,
    wxEVT_COMMAND_MENU_SELECTED,
    wxEVT_COMMAND_SLIDER_UPDATED,
    wxEVT_COMMAND_RADIOBOX_SELECTED,
    wxEVT_COMMAND_RADIOBUTTON_SELECTED,
    wxEVT_COMMAND_SCROLLBAR_UPDATED,
    wxEVT_COMMAND_VLBOX_SELECTED,
    wxEVT_COMMAND_COMBOBOX_SELECTED,
    wxEVT_COMMAND_TOOL_RCLICKED,
    wxEVT_COMMAND_TOOL_ENTER,
    wxEVT_COMMAND_SPINCTRL_UPDATED,
    -1
};

static int idleEvents[] =
{
    wxEVT_IDLE,
    -1
};

static int paintEvents[] = 
{
    wxEVT_PAINT,
    -1
};

static int updateUIEvents[] =
{
    wxEVT_UPDATE_UI,
    -1
};


//IMPLEMENT_ABSTRACT_CLASS(wxRbCallback, wxObject);

class wxRbCallback : public wxObject 
{
//    DECLARE_ABSTRACT_CLASS(wxRbCallback);
public:
    wxRbCallback(VALUE func) { m_func = func; }
    wxRbCallback(const wxRbCallback &other) { m_func = other.m_func; }
 
    void EventThunker(wxEvent &event)
    {
        VALUE cEvent = Qnil;
        
        int type = event.GetEventType();
        if(IsEventInMap(type, calendarEvents))
            cEvent = cWxCalendarEvent.klass;
        else if(IsEventInMap(type, closeEvents))
            cEvent = cWxCloseEvent.klass;
        else if(IsEventInMap(type, commandEvents))
            cEvent = cWxCommandEvent.klass;
        else if(IsEventInMap(type, idleEvents))
            cEvent = cWxIdleEvent.klass;
        else if(IsEventInMap(type, paintEvents))
            cEvent = cWxPaintEvent.klass;
        else if(IsEventInMap(type, updateUIEvents))
            cEvent = cWxUpdateUIEvent.klass;
        else
            cEvent = cWxEvent.klass;
            
        static VALUE vevent;
        vevent = Data_Wrap_Struct(cEvent, 0, 0, 0);
        DATA_PTR(vevent) = &event;
        
        wxRbCallback *cb = (wxRbCallback *)event.m_callbackUserData;
        rb_funcall(cb->m_func, rb_intern("call"),1,vevent);
    }
    
    bool IsEventInMap(int type, int map[])
    {
        for(int i=0; map[i] >= 0; ++i)
            if(type == map[i])
                return true;
        return false;
    }
    
                                                                                
    VALUE       m_func;
};


static void internal_connect(VALUE self, int firstId, int lastId, 
                wxEventType eventType)
{
    
    wxEvtHandler *cppSelf = (wxEvtHandler *) 0 ;
    SWIG_ConvertPtr(self, (void **) &cppSelf, SWIGTYPE_p_wxEvtHandler, 1);

    VALUE func = rb_funcall(rb_cProc, rb_intern("new"), 0);
    rb_global_variable(&callbacks);
    if(callbacks == Qnil)
        callbacks = rb_ary_new();
    rb_ary_push(callbacks, func);

    wxObject* userData = new wxRbCallback(func);
    wxObjectEventFunction function = 
        (wxObjectEventFunction )&wxRbCallback::EventThunker;
    (cppSelf)->Connect(firstId, lastId, eventType, function, userData);
}

static VALUE internal_evt_with_id(int argc, VALUE *argv, VALUE self, 
        wxEventType eventType) 
{
    if (argc != 1)
        rb_raise(rb_eArgError, "wrong # of arguments(%d for 1)",argc);
        
    int id = NUM2INT(argv[0]);
    //printf("evt_with_id(%d) %s\n", id, rb_block_given_p() ? "with block" : "");

    internal_connect(self, id, id, eventType);
    return Qnil;
}

static VALUE internal_evt_no_parameters(int argc, VALUE *argv, VALUE self, 
        wxEventType eventType) 
{
    if (argc != 0)
        rb_raise(rb_eArgError, "wrong # of arguments(%d for 0)",argc);
        
    //printf("evt_no_parameters() %s\n", rb_block_given_p() ? "with block" : "");
    internal_connect(self, -1, -1, eventType);
    return Qnil;
}

static VALUE connect(int argc, VALUE *argv, VALUE self) 
{
    if (argc != 3)
        rb_raise(rb_eArgError, "wrong # of arguments(%d for 3)", argc);

    int id = NUM2INT(argv[0]);
    int lastId = NUM2INT(argv[1]);
    int type = NUM2INT(argv[2]);
    
    internal_connect(self, id, lastId, type);
    return Qnil;
}

static VALUE evt_menu(int argc, VALUE *argv, VALUE self) 
{
    return internal_evt_with_id(argc, argv, self, wxEVT_COMMAND_MENU_SELECTED);
}

static VALUE evt_choice(int argc, VALUE *argv, VALUE self) 
{
    return internal_evt_with_id(argc, argv, self, wxEVT_COMMAND_CHOICE_SELECTED);
}

static VALUE evt_calendar(int argc, VALUE *argv, VALUE self) 
{
    return internal_evt_with_id(argc, argv, self, wxEVT_CALENDAR_DOUBLECLICKED);
}

static VALUE evt_calendar_sel_changed(int argc, VALUE *argv, VALUE self) 
{
    return internal_evt_with_id(argc, argv, self, wxEVT_CALENDAR_SEL_CHANGED);
}

static VALUE evt_calendar_day(int argc, VALUE *argv, VALUE self) 
{
    return internal_evt_with_id(argc, argv, self, wxEVT_CALENDAR_DAY_CHANGED);
}

static VALUE evt_calendar_month(int argc, VALUE *argv, VALUE self) 
{
    return internal_evt_with_id(argc, argv, self, wxEVT_CALENDAR_MONTH_CHANGED);
}

static VALUE evt_calendar_year(int argc, VALUE *argv, VALUE self) 
{
    return internal_evt_with_id(argc, argv, self, wxEVT_CALENDAR_YEAR_CHANGED);
}

static VALUE evt_calendar_weekday_clicked(int argc, VALUE *argv, VALUE self) 
{
    return internal_evt_with_id(argc, argv, self, wxEVT_CALENDAR_WEEKDAY_CLICKED);
}

static VALUE evt_update_ui(int argc, VALUE *argv, VALUE self) 
{
    return internal_evt_with_id(argc, argv, self, wxEVT_UPDATE_UI);
}

static VALUE evt_paint(int argc, VALUE *argv, VALUE self) 
{
    return internal_evt_no_parameters(argc, argv, self, wxEVT_PAINT);
}

static VALUE evt_close(int argc, VALUE *argv, VALUE self) 
{
    return internal_evt_no_parameters(argc, argv, self, wxEVT_CLOSE_WINDOW);
}

static VALUE evt_idle(int argc, VALUE *argv, VALUE self) 
{
    return internal_evt_no_parameters(argc, argv, self, wxEVT_IDLE);
}

static VALUE evt_show(int argc, VALUE *argv, VALUE self) 
{
    return internal_evt_no_parameters(argc, argv, self, wxEVT_SHOW);
}

static VALUE evt_window_create(int argc, VALUE *argv, VALUE self) 
{
    return internal_evt_no_parameters(argc, argv, self, wxEVT_CREATE);
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
    rb_define_method(cWxEvtHandler.klass, "evt_idle", VALUEFUNC(evt_idle), -1);
    rb_define_method(cWxEvtHandler.klass, "evt_show", VALUEFUNC(evt_show), -1);
    rb_define_method(cWxEvtHandler.klass, "evt_update_ui", VALUEFUNC(evt_update_ui), -1);
    rb_define_method(cWxEvtHandler.klass, "evt_window_create", VALUEFUNC(evt_window_create), -1);

    rb_define_method(cWxEvtHandler.klass, "evt_paint", VALUEFUNC(evt_paint), -1);
    rb_define_method(cWxEvtHandler.klass, "evt_close", VALUEFUNC(evt_close), -1);

%}
