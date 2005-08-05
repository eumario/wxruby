#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license
%include "common.i"

%{
#include <wx/calctrl.h>
#include <wx/fdrepdlg.h>
#include <wx/notebook.h>
#include <wx/listctrl.h>
#include <wx/treectrl.h>
#include <wx/dialup.h>
#include <wx/sashwin.h>
#include <wx/taskbar.h>
#include <wx/tabctrl.h>
#include <wx/wizard.h>
#include <wx/splitter.h>
#include <wx/grid.h>
#include <wx/laywin.h>
#include <wx/process.h>
#include <wx/tglbtn.h>
%}

%module(directors="1") wxEventHandlers;



%{
extern swig_class cWxEvtHandler;

void internal_connect(VALUE self, int firstId, int lastId, 
                wxEventType eventType);


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

static VALUE internal_evt_with_id_range(int argc, VALUE *argv, VALUE self, 
        wxEventType eventType)
{
    if (argc != 2)
        rb_raise(rb_eArgError, "wrong # of arguments(%d for 1)",argc);
        
    int idStart = NUM2INT(argv[0]);
    int idEnd = NUM2INT(argv[1]);
    //printf("evt_with_id(%d) %s\n", id, rb_block_given_p() ? "with block" : "");

    internal_connect(self, idStart, idEnd, eventType);
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

static VALUE connect_fnc(int argc, VALUE *argv, VALUE self) 
{
    if (argc != 3)
        rb_raise(rb_eArgError, "wrong # of arguments(%d for 3)", argc);

    int id = NUM2INT(argv[0]);
    int lastId = NUM2INT(argv[1]);
    int type = NUM2INT(argv[2]);
    
    internal_connect(self, id, lastId, type);
    return Qnil;
}

%}

#if 0 
%{

static VALUE evt_menu(int argc, VALUE *argv, VALUE self) 
{
    return internal_evt_with_id(argc, argv, self, wxEVT_COMMAND_MENU_SELECTED);
}

static VALUE evt_menu_range(int argc, VALUE *argv, VALUE self) 
{
    return internal_evt_with_id_range(argc, argv, self, wxEVT_COMMAND_MENU_SELECTED);
}

static VALUE evt_combobox(int argc, VALUE *argv, VALUE self) 
{
    return internal_evt_with_id(argc, argv, self, wxEVT_COMMAND_COMBOBOX_SELECTED);
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

static VALUE evt_set_focus(int argc, VALUE *argv, VALUE self) 
{
    return internal_evt_no_parameters(argc, argv, self, wxEVT_SET_FOCUS);
}

static VALUE evt_kill_focus(int argc, VALUE *argv, VALUE self) 
{
    return internal_evt_no_parameters(argc, argv, self, wxEVT_KILL_FOCUS);
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

static VALUE evt_size(int argc, VALUE *argv, VALUE self) 
{
    return internal_evt_no_parameters(argc, argv, self, wxEVT_SIZE);
}

static VALUE evt_key_down(int argc, VALUE *argv, VALUE self) 
{
    return internal_evt_no_parameters(argc, argv, self, wxEVT_KEY_DOWN);
}

static VALUE evt_key_up(int argc, VALUE *argv, VALUE self) 
{
    return internal_evt_no_parameters(argc, argv, self, wxEVT_KEY_UP);
}

static VALUE evt_char(int argc, VALUE *argv, VALUE self) 
{
    return internal_evt_no_parameters(argc, argv, self, wxEVT_CHAR);
}

static VALUE evt_find(int argc, VALUE *argv, VALUE self) 
{
    return internal_evt_with_id(argc, argv, self, wxEVT_COMMAND_FIND);
}

static VALUE evt_find_next(int argc, VALUE *argv, VALUE self) 
{
    return internal_evt_with_id(argc, argv, self, wxEVT_COMMAND_FIND_NEXT);
}

static VALUE evt_find_replace(int argc, VALUE *argv, VALUE self) 
{
    return internal_evt_with_id(argc, argv, self, wxEVT_COMMAND_FIND_REPLACE);
}

static VALUE evt_find_replace_all(int argc, VALUE *argv, VALUE self) 
{
    return internal_evt_with_id(argc, argv, self, wxEVT_COMMAND_FIND_REPLACE_ALL);
}

static VALUE evt_find_close(int argc, VALUE *argv, VALUE self) 
{
    return internal_evt_with_id(argc, argv, self, wxEVT_COMMAND_FIND_CLOSE);
}

static VALUE evt_button(int argc, VALUE *argv, VALUE self) 
{
    return internal_evt_with_id(argc, argv, self, wxEVT_COMMAND_BUTTON_CLICKED);
}

static VALUE evt_tool_rclicked(int argc, VALUE *argv, VALUE self) 
{
    return internal_evt_with_id(argc, argv, self, wxEVT_COMMAND_TOOL_RCLICKED);
}

static VALUE evt_tool_enter(int argc, VALUE *argv, VALUE self) 
{
    return internal_evt_with_id(argc, argv, self, wxEVT_COMMAND_TOOL_ENTER);
}

static VALUE evt_left_down(int argc, VALUE *argv, VALUE self) 
{
    return internal_evt_no_parameters(argc, argv, self, wxEVT_LEFT_DOWN);
}

static VALUE evt_left_up(int argc, VALUE *argv, VALUE self) 
{
    return internal_evt_no_parameters(argc, argv, self, wxEVT_LEFT_UP);
}

static VALUE evt_left_dclick(int argc, VALUE *argv, VALUE self) 
{
    return internal_evt_no_parameters(argc, argv, self, wxEVT_LEFT_DCLICK);
}

static VALUE evt_right_down(int argc, VALUE *argv, VALUE self) 
{
    return internal_evt_no_parameters(argc, argv, self, wxEVT_RIGHT_DOWN);
}

static VALUE evt_right_up(int argc, VALUE *argv, VALUE self) 
{
    return internal_evt_no_parameters(argc, argv, self, wxEVT_RIGHT_UP);
}

static VALUE evt_right_dclick(int argc, VALUE *argv, VALUE self) 
{
    return internal_evt_no_parameters(argc, argv, self, wxEVT_RIGHT_DCLICK);
}

static VALUE evt_middle_down(int argc, VALUE *argv, VALUE self) 
{
    return internal_evt_no_parameters(argc, argv, self, wxEVT_MIDDLE_DOWN);
}

static VALUE evt_middle_up(int argc, VALUE *argv, VALUE self) 
{
    return internal_evt_no_parameters(argc, argv, self, wxEVT_MIDDLE_UP);
}

static VALUE evt_middle_dclick(int argc, VALUE *argv, VALUE self) 
{
    return internal_evt_no_parameters(argc, argv, self, wxEVT_MIDDLE_DCLICK);
}

static VALUE evt_motion(int argc, VALUE *argv, VALUE self) 
{
    return internal_evt_no_parameters(argc, argv, self, wxEVT_MOTION);
}

static VALUE evt_enter_window(int argc, VALUE *argv, VALUE self) 
{
    return internal_evt_no_parameters(argc, argv, self, wxEVT_ENTER_WINDOW);
}

static VALUE evt_leave_window(int argc, VALUE *argv, VALUE self) 
{
    return internal_evt_no_parameters(argc, argv, self, wxEVT_LEAVE_WINDOW);
}

static VALUE evt_mousewheel(int argc, VALUE *argv, VALUE self) 
{
    return internal_evt_no_parameters(argc, argv, self, wxEVT_MOUSEWHEEL);
}

static VALUE evt_spin(int argc, VALUE *argv, VALUE self) 
{
    return internal_evt_with_id(argc, argv, self, wxEVT_SCROLL_THUMBTRACK);
}

static VALUE evt_spin_up(int argc, VALUE *argv, VALUE self) 
{
    return internal_evt_with_id(argc, argv, self, wxEVT_SCROLL_LINEUP);
}

static VALUE evt_spin_down(int argc, VALUE *argv, VALUE self) 
{
    return internal_evt_with_id(argc, argv, self, wxEVT_SCROLL_LINEDOWN);
}

static VALUE evt_notebook_page_changing(int argc, VALUE *argv, VALUE self) 
{
    return internal_evt_with_id(argc, argv, self, wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGING);
}

static VALUE evt_notebook_page_changed(int argc, VALUE *argv, VALUE self) 
{
    return internal_evt_with_id(argc, argv, self, wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED);
}

static VALUE evt_listbox(int argc, VALUE *argv, VALUE self) 
{
    return internal_evt_with_id(argc, argv, self, wxEVT_COMMAND_LISTBOX_SELECTED);
}

static VALUE evt_listbox_dclick(int argc, VALUE *argv, VALUE self) 
{
    return internal_evt_with_id(argc, argv, self, wxEVT_COMMAND_LISTBOX_DOUBLECLICKED);
}

static VALUE evt_checkbox(int argc, VALUE *argv, VALUE self) 
{
    return internal_evt_with_id(argc, argv, self, wxEVT_COMMAND_CHECKBOX_CLICKED);
}

static VALUE evt_text(int argc, VALUE *argv, VALUE self) 
{
    return internal_evt_with_id(argc, argv, self, wxEVT_COMMAND_TEXT_UPDATED);
}

static VALUE evt_text_enter(int argc, VALUE *argv, VALUE self) 
{
    return internal_evt_with_id(argc, argv, self, wxEVT_COMMAND_TEXT_ENTER);
}

static VALUE evt_text_maxlen(int argc, VALUE *argv, VALUE self) 
{
    return internal_evt_with_id(argc, argv, self, wxEVT_COMMAND_TEXT_MAXLEN);
}

#ifdef __WXMSW__
static VALUE evt_text_url(int argc, VALUE *argv, VALUE self) 
{
    return internal_evt_with_id(argc, argv, self, wxEVT_COMMAND_TEXT_URL);
}
#endif

static VALUE evt_radiobox(int argc, VALUE *argv, VALUE self) 
{
    return internal_evt_with_id(argc, argv, self, wxEVT_COMMAND_RADIOBOX_SELECTED);
}

static VALUE evt_radiobutton(int argc, VALUE *argv, VALUE self) 
{
    return internal_evt_with_id(argc, argv, self, wxEVT_COMMAND_RADIOBUTTON_SELECTED);
}



%}




%init %{
    rb_define_method(cWxEvtHandler.klass, "connect", VALUEFUNC(connect_fnc), -1);
    rb_define_method(cWxEvtHandler.klass, "evt_menu", VALUEFUNC(evt_menu), -1);
    rb_define_method(cWxEvtHandler.klass, "evt_tool", VALUEFUNC(evt_menu), -1);
    rb_define_method(cWxEvtHandler.klass, "evt_menu_range", VALUEFUNC(evt_menu_range), -1);
    rb_define_method(cWxEvtHandler.klass, "evt_tool_range", VALUEFUNC(evt_menu_range), -1);
    rb_define_method(cWxEvtHandler.klass, "evt_choice", VALUEFUNC(evt_choice), -1);
    rb_define_method(cWxEvtHandler.klass, "evt_combobox", VALUEFUNC(evt_combobox), -1);

    rb_define_method(cWxEvtHandler.klass, "evt_calendar", VALUEFUNC(evt_calendar), -1);
    rb_define_method(cWxEvtHandler.klass, "evt_calendar_sel_changed", VALUEFUNC(evt_calendar_sel_changed), -1);
    rb_define_method(cWxEvtHandler.klass, "evt_calendar_day", VALUEFUNC(evt_calendar_day), -1);
    rb_define_method(cWxEvtHandler.klass, "evt_calendar_month", VALUEFUNC(evt_calendar_month), -1);
    rb_define_method(cWxEvtHandler.klass, "evt_calendar_year", VALUEFUNC(evt_calendar_year), -1);
    rb_define_method(cWxEvtHandler.klass, "evt_calendar_weekday_clicked", VALUEFUNC(evt_calendar_weekday_clicked), -1);
    rb_define_method(cWxEvtHandler.klass, "evt_idle", VALUEFUNC(evt_idle), -1);
    rb_define_method(cWxEvtHandler.klass, "evt_size", VALUEFUNC(evt_size), -1);
    rb_define_method(cWxEvtHandler.klass, "evt_show", VALUEFUNC(evt_show), -1);
    rb_define_method(cWxEvtHandler.klass, "evt_update_ui", VALUEFUNC(evt_update_ui), -1);
    rb_define_method(cWxEvtHandler.klass, "evt_window_create", VALUEFUNC(evt_window_create), -1);

    rb_define_method(cWxEvtHandler.klass, "evt_paint", VALUEFUNC(evt_paint), -1);
    rb_define_method(cWxEvtHandler.klass, "evt_close", VALUEFUNC(evt_close), -1);
    rb_define_method(cWxEvtHandler.klass, "evt_key_down", VALUEFUNC(evt_key_down), -1);
    rb_define_method(cWxEvtHandler.klass, "evt_key_up", VALUEFUNC(evt_key_up), -1);
    rb_define_method(cWxEvtHandler.klass, "evt_char", VALUEFUNC(evt_char), -1);
    rb_define_method(cWxEvtHandler.klass, "evt_find", VALUEFUNC(evt_find), -1);
    rb_define_method(cWxEvtHandler.klass, "evt_find_next", VALUEFUNC(evt_find_next), -1);
    rb_define_method(cWxEvtHandler.klass, "evt_find_replace", VALUEFUNC(evt_find_replace), -1);        
    rb_define_method(cWxEvtHandler.klass, "evt_find_replace_all", VALUEFUNC(evt_find_replace_all), -1);        
    rb_define_method(cWxEvtHandler.klass, "evt_find_close", VALUEFUNC(evt_find_close), -1);        
    rb_define_method(cWxEvtHandler.klass, "evt_button", VALUEFUNC(evt_button), -1);        
    rb_define_method(cWxEvtHandler.klass, "evt_tool_rclicked", VALUEFUNC(evt_tool_rclicked), -1);        
    rb_define_method(cWxEvtHandler.klass, "evt_tool_enter", VALUEFUNC(evt_tool_enter), -1);        
    rb_define_method(cWxEvtHandler.klass, "evt_left_down", VALUEFUNC(evt_left_down), -1);        
    rb_define_method(cWxEvtHandler.klass, "evt_left_up", VALUEFUNC(evt_left_up), -1);        
    rb_define_method(cWxEvtHandler.klass, "evt_left_dclick", VALUEFUNC(evt_left_dclick), -1);        
    rb_define_method(cWxEvtHandler.klass, "evt_right_down", VALUEFUNC(evt_right_down), -1);        
    rb_define_method(cWxEvtHandler.klass, "evt_right_up", VALUEFUNC(evt_right_up), -1);        
    rb_define_method(cWxEvtHandler.klass, "evt_right_dclick", VALUEFUNC(evt_right_dclick), -1);        
    rb_define_method(cWxEvtHandler.klass, "evt_middle_down", VALUEFUNC(evt_middle_down), -1);        
    rb_define_method(cWxEvtHandler.klass, "evt_middle_up", VALUEFUNC(evt_middle_up), -1);        
    rb_define_method(cWxEvtHandler.klass, "evt_middle_dclick", VALUEFUNC(evt_middle_dclick), -1);        
    rb_define_method(cWxEvtHandler.klass, "evt_enter_window", VALUEFUNC(evt_enter_window), -1);        
    rb_define_method(cWxEvtHandler.klass, "evt_leave_window", VALUEFUNC(evt_leave_window), -1);        
    rb_define_method(cWxEvtHandler.klass, "evt_mousewheel", VALUEFUNC(evt_mousewheel), -1);        
    rb_define_method(cWxEvtHandler.klass, "evt_set_focus", VALUEFUNC(evt_set_focus), -1);        
    rb_define_method(cWxEvtHandler.klass, "evt_kill_focus", VALUEFUNC(evt_kill_focus), -1);
    rb_define_method(cWxEvtHandler.klass, "evt_spin", VALUEFUNC(evt_spin), -1);        
    rb_define_method(cWxEvtHandler.klass, "evt_spin_up", VALUEFUNC(evt_spin_up), -1);
    rb_define_method(cWxEvtHandler.klass, "evt_spin_down", VALUEFUNC(evt_spin_down), -1);        
    rb_define_method(cWxEvtHandler.klass, "evt_notebook_page_changing", VALUEFUNC(evt_notebook_page_changing), -1);        
    rb_define_method(cWxEvtHandler.klass, "evt_notebook_page_changed", VALUEFUNC(evt_notebook_page_changed), -1);        
    rb_define_method(cWxEvtHandler.klass, "evt_listbox", VALUEFUNC(evt_listbox), -1);        
    rb_define_method(cWxEvtHandler.klass, "evt_listbox_dclick", VALUEFUNC(evt_listbox_dclick), -1);        
    rb_define_method(cWxEvtHandler.klass, "evt_checkbox", VALUEFUNC(evt_checkbox), -1);        
    rb_define_method(cWxEvtHandler.klass, "evt_text", VALUEFUNC(evt_text), -1);        
    rb_define_method(cWxEvtHandler.klass, "evt_text_enter", VALUEFUNC(evt_text_enter), -1);        
    rb_define_method(cWxEvtHandler.klass, "evt_text_maxlen", VALUEFUNC(evt_text_maxlen), -1);        
#ifdef __WXMSW__
    rb_define_method(cWxEvtHandler.klass, "evt_text_url", VALUEFUNC(evt_text_url), -1);        
#endif
    rb_define_method(cWxEvtHandler.klass, "evt_radiobox", VALUEFUNC(evt_radiobox), -1);        
    rb_define_method(cWxEvtHandler.klass, "evt_radiobutton", VALUEFUNC(evt_radiobutton), -1);        







%}


#endif
