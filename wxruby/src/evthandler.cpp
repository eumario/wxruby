/**********************************************************************

  evthandler.cpp -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#include "wx.h"
#include "wx/tglbtn.h"
#include "wx/notebook.h"
#include "wx/process.h"
#include "wx/splitter.h"
#include "wx/listctrl.h"
#include "wx/fdrepdlg.h"
#include "wx/socket.h"
#ifdef __WXMSW__
#include "wx/msw/taskbar.h"
#endif
#if wxUSE_SASH
#include "wx/generic/laywin.h"
#endif
#include "calendar.h"
#include "evthandler.h"
#include "treectrl.h"
#include "event.h"

IMPLEMENT_ABSTRACT_CLASS(wxRbCallback, wxObject);

wxRbCallback::wxRbCallback(VALUE func) {
    m_func = func;
}

wxRbCallback::wxRbCallback(const wxRbCallback &other) {
    m_func = other.m_func;
}

void wxRbCallback::EventThunker(wxEvent &event) {
    wxRbCallback *cb = (wxRbCallback *)event.m_callbackUserData;
    static VALUE vevent;
    int eventType = event.GetEventType();
    if(eventType==wxEVT_CHAR || eventType==wxEVT_CHAR_HOOK || eventType==wxEVT_KEY_DOWN || eventType==wxEVT_KEY_UP) {
	  vevent = Data_Wrap_Struct(WxKeyEvent::rubyClass, 0, 0, 0);
    } else if(eventType==wxEVT_CLOSE_WINDOW || eventType==wxEVT_END_SESSION || eventType==wxEVT_QUERY_END_SESSION) {
	  vevent = Data_Wrap_Struct(WxCloseEvent::rubyClass, 0, 0, 0);
    } else if(eventType==wxEVT_CALENDAR_DOUBLECLICKED||eventType==wxEVT_CALENDAR_SEL_CHANGED||eventType==wxEVT_CALENDAR_DAY_CHANGED||eventType==wxEVT_CALENDAR_MONTH_CHANGED||eventType==wxEVT_CALENDAR_YEAR_CHANGED||eventType==wxEVT_CALENDAR_WEEKDAY_CLICKED) {
	  vevent = Data_Wrap_Struct(WxCalendarEvent::rubyClass, 0, 0, 0);
    } else if(eventType==wxEVT_COMMAND_BUTTON_CLICKED||
    eventType==wxEVT_COMMAND_CHECKBOX_CLICKED||
    eventType==wxEVT_COMMAND_CHOICE_SELECTED||
    eventType==wxEVT_COMMAND_LISTBOX_SELECTED||
    eventType==wxEVT_COMMAND_LISTBOX_DOUBLECLICKED||
    eventType==wxEVT_COMMAND_TEXT_UPDATED||
    eventType==wxEVT_COMMAND_TEXT_ENTER||
    eventType==wxEVT_COMMAND_MENU_SELECTED||
    eventType==wxEVT_COMMAND_SLIDER_UPDATED||
    eventType==wxEVT_COMMAND_RADIOBOX_SELECTED||
    eventType==wxEVT_COMMAND_RADIOBUTTON_SELECTED||
    eventType==wxEVT_COMMAND_SCROLLBAR_UPDATED||
    eventType==wxEVT_COMMAND_VLBOX_SELECTED||
    eventType==wxEVT_COMMAND_COMBOBOX_SELECTED||

    eventType==wxEVT_COMMAND_TOOL_CLICKED||
    eventType==wxEVT_COMMAND_TOOL_RCLICKED||
    eventType==wxEVT_COMMAND_TOOL_ENTER||

#if defined(__WXGTK__) || defined(__WXMSW__)
    eventType==wxEVT_COMMAND_TOGGLEBUTTON_CLICKED||
#endif
    eventType==wxEVT_COMMAND_CHECKLISTBOX_TOGGLED ) {
	  vevent = Data_Wrap_Struct(WxCommandEvent::rubyClass, 0, 0, 0);
    } else if(
    eventType==wxEVT_COMMAND_LIST_BEGIN_DRAG||
    eventType==wxEVT_COMMAND_LIST_BEGIN_RDRAG||
    eventType==wxEVT_COMMAND_LIST_BEGIN_LABEL_EDIT||
    eventType==wxEVT_COMMAND_LIST_END_LABEL_EDIT||
    eventType==wxEVT_COMMAND_LIST_DELETE_ITEM||
    eventType==wxEVT_COMMAND_LIST_DELETE_ALL_ITEMS||
    eventType==wxEVT_COMMAND_LIST_GET_INFO||
    eventType==wxEVT_COMMAND_LIST_SET_INFO||
    eventType==wxEVT_COMMAND_LIST_ITEM_SELECTED||
    eventType==wxEVT_COMMAND_LIST_ITEM_DESELECTED||
    eventType==wxEVT_COMMAND_LIST_KEY_DOWN||
    eventType==wxEVT_COMMAND_LIST_INSERT_ITEM||
    eventType==wxEVT_COMMAND_LIST_COL_CLICK||
    eventType==wxEVT_COMMAND_LIST_ITEM_RIGHT_CLICK||
    eventType==wxEVT_COMMAND_LIST_ITEM_MIDDLE_CLICK||
    eventType==wxEVT_COMMAND_LIST_ITEM_ACTIVATED||
    eventType==wxEVT_COMMAND_LIST_CACHE_HINT||
    eventType==wxEVT_COMMAND_LIST_COL_RIGHT_CLICK||
    eventType==wxEVT_COMMAND_LIST_COL_BEGIN_DRAG||
    eventType==wxEVT_COMMAND_LIST_COL_DRAGGING||
    eventType==wxEVT_COMMAND_LIST_COL_END_DRAG||
    eventType==wxEVT_COMMAND_LIST_ITEM_FOCUSED) {
	  vevent = Data_Wrap_Struct(WxListEvent::rubyClass, 0, 0, 0);
    } else if(
    eventType==wxEVT_COMMAND_TREE_BEGIN_DRAG||
    eventType==wxEVT_COMMAND_TREE_BEGIN_RDRAG||
    eventType==wxEVT_COMMAND_TREE_BEGIN_LABEL_EDIT||
    eventType==wxEVT_COMMAND_TREE_END_LABEL_EDIT||
    eventType==wxEVT_COMMAND_TREE_DELETE_ITEM||
    eventType==wxEVT_COMMAND_TREE_GET_INFO||
    eventType==wxEVT_COMMAND_TREE_SET_INFO||
    eventType==wxEVT_COMMAND_TREE_ITEM_EXPANDED||
    eventType==wxEVT_COMMAND_TREE_ITEM_EXPANDING||
    eventType==wxEVT_COMMAND_TREE_ITEM_COLLAPSED||
    eventType==wxEVT_COMMAND_TREE_ITEM_COLLAPSING||
    eventType==wxEVT_COMMAND_TREE_SEL_CHANGED||
    eventType==wxEVT_COMMAND_TREE_SEL_CHANGING||
    eventType==wxEVT_COMMAND_TREE_KEY_DOWN||
    eventType==wxEVT_COMMAND_TREE_ITEM_ACTIVATED||
    eventType==wxEVT_COMMAND_TREE_ITEM_RIGHT_CLICK||
    eventType==wxEVT_COMMAND_TREE_ITEM_MIDDLE_CLICK||
    eventType==wxEVT_COMMAND_TREE_END_DRAG) {
        vevent = Data_Wrap_Struct(WxTreeEvent::rubyClass, 0, 0, 0);
    } else if(
    eventType==wxEVT_SOCKET) {
	  vevent = Data_Wrap_Struct(WxSocketEvent::rubyClass, 0, 0, 0);
    } else if(
    eventType==wxEVT_UPDATE_UI) {
	  vevent = Data_Wrap_Struct(WxUpdateUIEvent::rubyClass, 0, 0, 0);
    } else if(
    eventType==wxEVT_SIZE) {
	  vevent = Data_Wrap_Struct(WxSizeEvent::rubyClass, 0, 0, 0);
    } else if(
    eventType==wxEVT_MOVE) {
	  vevent = Data_Wrap_Struct(WxMoveEvent::rubyClass, 0, 0, 0);
    } else if(
    eventType==wxEVT_PAINT||
    eventType==wxEVT_NC_PAINT||
    eventType==wxEVT_PAINT_ICON
    ) {
	  vevent = Data_Wrap_Struct(WxPaintEvent::rubyClass, 0, 0, 0);
    } else if(
    eventType==wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED||
    eventType==wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGING
    ) {
	  vevent = Data_Wrap_Struct(WxNotebookEvent::rubyClass, 0, 0, 0);
    } else if(
    eventType==wxEVT_SCROLL_LINEUP||
    eventType==wxEVT_SCROLL_LINEDOWN||
    eventType==wxEVT_SCROLL_THUMBTRACK||
    eventType==wxEVT_COMMAND_SPINCTRL_UPDATED
    ) {
	  vevent = Data_Wrap_Struct(WxSpinEvent::rubyClass, 0, 0, 0);
    } else if(
    eventType==wxEVT_COMMAND_SPLITTER_SASH_POS_CHANGED||
    eventType==wxEVT_COMMAND_SPLITTER_SASH_POS_CHANGING||
    eventType==wxEVT_COMMAND_SPLITTER_DOUBLECLICKED||
    eventType==wxEVT_COMMAND_SPLITTER_UNSPLIT
    ) {
	  vevent = Data_Wrap_Struct(WxSplitterEvent::rubyClass, 0, 0, 0);
    } else if(
    eventType==wxEVT_COMMAND_FIND||
    eventType==wxEVT_COMMAND_FIND_NEXT||
    eventType==wxEVT_COMMAND_FIND_REPLACE||
    eventType==wxEVT_COMMAND_FIND_REPLACE_ALL||
    eventType==wxEVT_COMMAND_FIND_CLOSE
    ) {
	  vevent = Data_Wrap_Struct(WxFindDialogEvent::rubyClass, 0, 0, 0);
    } else if(
		eventType==wxEVT_LEFT_DOWN||
		eventType==wxEVT_LEFT_UP||
		eventType==wxEVT_MIDDLE_DOWN||
		eventType==wxEVT_MIDDLE_UP||
		eventType==wxEVT_RIGHT_DOWN||
		eventType==wxEVT_RIGHT_UP||
		eventType==wxEVT_MOTION||
		eventType==wxEVT_LEFT_DCLICK||
		eventType==wxEVT_MIDDLE_DCLICK||
		eventType==wxEVT_RIGHT_DCLICK||
		eventType==wxEVT_LEAVE_WINDOW||
		eventType==wxEVT_MOUSEWHEEL||
		eventType==wxEVT_ENTER_WINDOW
	) {
	  vevent = Data_Wrap_Struct(WxMouseEvent::rubyClass, 0, 0, 0);
	} else if(eventType == wxEVT_IDLE) {
		vevent = Data_Wrap_Struct(WxIdleEvent::rubyClass, 0, 0, 0);
    } else {
//printf("Unknown event type %d\n", eventType);
	  vevent = Data_Wrap_Struct(WxEvent::rubyClass, 0, 0, 0);
    }
    DATA_PTR(vevent) = &event;
    rb_funcall(cb->m_func, rb_intern("call"),1,vevent);
}

/////////////////////////////////////////////////////////////////

VALUE WxEvtHandler::eventCallbackArray = Qnil;

void WxEvtHandler::DefineClass()
{
	if(rubyClass)
		return;

	rubyClass = rb_define_class_under(GetWxModule(),"EvtHandler", rb_cObject);
	
	eventCallbackArray = rb_ary_new();
	rb_define_global_const("EVENT_CALLBACK_ARRAY", eventCallbackArray);
	
	rb_define_alloc_func(rubyClass,WxEvtHandler::alloc);
	rb_define_method(rubyClass,"AddPendingEvent",VALUEFUNC(WxEvtHandler::AddPendingEvent),1);
	rb_define_method(rubyClass,"GetClientData",VALUEFUNC(WxEvtHandler::GetClientData),0);
	rb_define_method(rubyClass,"GetEvtHandlerEnabled",VALUEFUNC(WxEvtHandler::GetEvtHandlerEnabled),0);
	rb_define_method(rubyClass,"GetNextHandler",VALUEFUNC(WxEvtHandler::GetNextHandler),0);
	rb_define_method(rubyClass,"GetPreviousHandler",VALUEFUNC(WxEvtHandler::GetPreviousHandler),0);
	rb_define_method(rubyClass,"ProcessEvent",VALUEFUNC(WxEvtHandler::ProcessEvent),1);
	rb_define_method(rubyClass,"SetClientData",VALUEFUNC(WxEvtHandler::SetClientData),1);
	rb_define_method(rubyClass,"SetEvtHandlerEnabled",VALUEFUNC(WxEvtHandler::SetEvtHandlerEnabled),1);
	rb_define_method(rubyClass,"SetNextHandler",VALUEFUNC(WxEvtHandler::SetNextHandler),1);
	rb_define_method(rubyClass,"SetPreviousHandler",VALUEFUNC(WxEvtHandler::SetPreviousHandler),1);

    rb_define_method(rubyClass, "evt_activate",VALUEFUNC(WxEvtHandler::WxRbEVT_ACTIVATE),-1);
    rb_define_method(rubyClass, "evt_activate_app",VALUEFUNC(WxEvtHandler::WxRbEVT_ACTIVATE_APP),-1);
    rb_define_method(rubyClass, "evt_button",VALUEFUNC(WxEvtHandler::WxRbEVT_BUTTON),-1);
    rb_define_method(rubyClass, "evt_calendar",VALUEFUNC(WxEvtHandler::WxRbEVT_CALENDAR),-1);
    rb_define_method(rubyClass, "evt_calendar_day",VALUEFUNC(WxEvtHandler::WxRbEVT_CALENDAR_DAY),-1);
    rb_define_method(rubyClass, "evt_calendar_month",VALUEFUNC(WxEvtHandler::WxRbEVT_CALENDAR_MONTH),-1);
    rb_define_method(rubyClass, "evt_calendar_sel_changed",VALUEFUNC(WxEvtHandler::WxRbEVT_CALENDAR_SEL_CHANGED),-1);
    rb_define_method(rubyClass, "evt_calendar_weekday_clicked",VALUEFUNC(WxEvtHandler::WxRbEVT_CALENDAR_WEEKDAY_CLICKED),-1);
    rb_define_method(rubyClass, "evt_calendar_year",VALUEFUNC(WxEvtHandler::WxRbEVT_CALENDAR_YEAR),-1);
    rb_define_method(rubyClass, "evt_char",VALUEFUNC(WxEvtHandler::WxRbEVT_CHAR),-1);
    rb_define_method(rubyClass, "evt_char_hook",VALUEFUNC(WxEvtHandler::WxRbEVT_CHAR_HOOK),-1);
    rb_define_method(rubyClass, "evt_checkbox",VALUEFUNC(WxEvtHandler::WxRbEVT_CHECKBOX),-1);
    rb_define_method(rubyClass, "evt_checklistbox",VALUEFUNC(WxEvtHandler::WxRbEVT_CHECKLISTBOX),-1);
    rb_define_method(rubyClass, "evt_child_focus",VALUEFUNC(WxEvtHandler::WxRbEVT_CHILD_FOCUS),-1);
    rb_define_method(rubyClass, "evt_choice",VALUEFUNC(WxEvtHandler::WxRbEVT_CHOICE),-1);
    rb_define_method(rubyClass, "evt_close",VALUEFUNC(WxEvtHandler::WxRbEVT_CLOSE),-1);
    rb_define_method(rubyClass, "evt_combobox",VALUEFUNC(WxEvtHandler::WxRbEVT_COMBOBOX),-1);
    rb_define_method(rubyClass, "evt_command",VALUEFUNC(WxEvtHandler::WxRbEVT_COMMAND),-1);
    rb_define_method(rubyClass, "evt_command_enter",VALUEFUNC(WxEvtHandler::WxRbEVT_COMMAND_ENTER),-1);
    rb_define_method(rubyClass, "evt_command_kill_focus",VALUEFUNC(WxEvtHandler::WxRbEVT_COMMAND_KILL_FOCUS),-1);
    rb_define_method(rubyClass, "evt_command_left_click",VALUEFUNC(WxEvtHandler::WxRbEVT_COMMAND_LEFT_CLICK),-1);
    rb_define_method(rubyClass, "evt_command_left_dclick",VALUEFUNC(WxEvtHandler::WxRbEVT_COMMAND_LEFT_DCLICK),-1);
    rb_define_method(rubyClass, "evt_command_range",VALUEFUNC(WxEvtHandler::WxRbEVT_COMMAND_RANGE),4);
    rb_define_method(rubyClass, "evt_command_right_click",VALUEFUNC(WxEvtHandler::WxRbEVT_COMMAND_RIGHT_CLICK),-1);
    rb_define_method(rubyClass, "evt_command_right_dclick",VALUEFUNC(WxEvtHandler::WxRbEVT_COMMAND_RIGHT_DCLICK),-1);
    rb_define_method(rubyClass, "evt_command_scroll",VALUEFUNC(WxEvtHandler::WxRbEVT_COMMAND_SCROLL),-1);
    rb_define_method(rubyClass, "evt_command_scrollwin",VALUEFUNC(WxEvtHandler::WxRbEVT_COMMAND_SCROLLWIN),-1);
    rb_define_method(rubyClass, "evt_command_scrollwin_bottom",VALUEFUNC(WxEvtHandler::WxRbEVT_COMMAND_SCROLLWIN_BOTTOM),-1);
    rb_define_method(rubyClass, "evt_command_scrollwin_linedown",VALUEFUNC(WxEvtHandler::WxRbEVT_COMMAND_SCROLLWIN_LINEDOWN),-1);
    rb_define_method(rubyClass, "evt_command_scrollwin_lineup",VALUEFUNC(WxEvtHandler::WxRbEVT_COMMAND_SCROLLWIN_LINEUP),-1);
    rb_define_method(rubyClass, "evt_command_scrollwin_pagedown",VALUEFUNC(WxEvtHandler::WxRbEVT_COMMAND_SCROLLWIN_PAGEDOWN),-1);
    rb_define_method(rubyClass, "evt_command_scrollwin_pageup",VALUEFUNC(WxEvtHandler::WxRbEVT_COMMAND_SCROLLWIN_PAGEUP),-1);
    rb_define_method(rubyClass, "evt_command_scrollwin_thumbrelease",VALUEFUNC(WxEvtHandler::WxRbEVT_COMMAND_SCROLLWIN_THUMBRELEASE),-1);
    rb_define_method(rubyClass, "evt_command_scrollwin_thumbtrack",VALUEFUNC(WxEvtHandler::WxRbEVT_COMMAND_SCROLLWIN_THUMBTRACK),-1);
    rb_define_method(rubyClass, "evt_command_scrollwin_top",VALUEFUNC(WxEvtHandler::WxRbEVT_COMMAND_SCROLLWIN_TOP),-1);
    rb_define_method(rubyClass, "evt_command_scroll_bottom",VALUEFUNC(WxEvtHandler::WxRbEVT_COMMAND_SCROLL_BOTTOM),-1);
    rb_define_method(rubyClass, "evt_command_scroll_linedown",VALUEFUNC(WxEvtHandler::WxRbEVT_COMMAND_SCROLL_LINEDOWN),-1);
    rb_define_method(rubyClass, "evt_command_scroll_lineup",VALUEFUNC(WxEvtHandler::WxRbEVT_COMMAND_SCROLL_LINEUP),-1);
    rb_define_method(rubyClass, "evt_command_scroll_pagedown",VALUEFUNC(WxEvtHandler::WxRbEVT_COMMAND_SCROLL_PAGEDOWN),-1);
    rb_define_method(rubyClass, "evt_command_scroll_pageup",VALUEFUNC(WxEvtHandler::WxRbEVT_COMMAND_SCROLL_PAGEUP),-1);
    rb_define_method(rubyClass, "evt_command_scroll_thumbrelease",VALUEFUNC(WxEvtHandler::WxRbEVT_COMMAND_SCROLL_THUMBRELEASE),-1);
    rb_define_method(rubyClass, "evt_command_scroll_thumbtrack",VALUEFUNC(WxEvtHandler::WxRbEVT_COMMAND_SCROLL_THUMBTRACK),-1);
    rb_define_method(rubyClass, "evt_command_scroll_top",VALUEFUNC(WxEvtHandler::WxRbEVT_COMMAND_SCROLL_TOP),-1);
    rb_define_method(rubyClass, "evt_command_set_focus",VALUEFUNC(WxEvtHandler::WxRbEVT_COMMAND_SET_FOCUS),-1);
    rb_define_method(rubyClass, "evt_context_menu",VALUEFUNC(WxEvtHandler::WxRbEVT_CONTEXT_MENU),-1);
    rb_define_method(rubyClass, "evt_detailed_help",VALUEFUNC(WxEvtHandler::WxRbEVT_DETAILED_HELP),-1);
    rb_define_method(rubyClass, "evt_detailed_help_range",VALUEFUNC(WxEvtHandler::WxRbEVT_DETAILED_HELP_RANGE),-1);
    rb_define_method(rubyClass, "evt_drop_files",VALUEFUNC(WxEvtHandler::WxRbEVT_DROP_FILES),-1);
    rb_define_method(rubyClass, "evt_end_process",VALUEFUNC(WxEvtHandler::WxRbEVT_END_PROCESS),-1);
    rb_define_method(rubyClass, "evt_end_session",VALUEFUNC(WxEvtHandler::WxRbEVT_END_SESSION),-1);
    rb_define_method(rubyClass, "evt_enter_window",VALUEFUNC(WxEvtHandler::WxRbEVT_ENTER_WINDOW),-1);
    rb_define_method(rubyClass, "evt_erase_background",VALUEFUNC(WxEvtHandler::WxRbEVT_ERASE_BACKGROUND),-1);
    rb_define_method(rubyClass, "evt_help",VALUEFUNC(WxEvtHandler::WxRbEVT_HELP),-1);
    rb_define_method(rubyClass, "evt_help_range",VALUEFUNC(WxEvtHandler::WxRbEVT_HELP_RANGE),-1);
    rb_define_method(rubyClass, "evt_iconize",VALUEFUNC(WxEvtHandler::WxRbEVT_ICONIZE),-1);
    rb_define_method(rubyClass, "evt_idle",VALUEFUNC(WxEvtHandler::WxRbEVT_IDLE),-1);
    rb_define_method(rubyClass, "evt_init_dialog",VALUEFUNC(WxEvtHandler::WxRbEVT_INIT_DIALOG),-1);
    rb_define_method(rubyClass, "evt_joystick_events",VALUEFUNC(WxEvtHandler::WxRbEVT_JOYSTICK_EVENTS),-1);
    rb_define_method(rubyClass, "evt_joy_down",VALUEFUNC(WxEvtHandler::WxRbEVT_JOY_DOWN),-1);
    rb_define_method(rubyClass, "evt_joy_move",VALUEFUNC(WxEvtHandler::WxRbEVT_JOY_MOVE),-1);
    rb_define_method(rubyClass, "evt_joy_up",VALUEFUNC(WxEvtHandler::WxRbEVT_JOY_UP),-1);
    rb_define_method(rubyClass, "evt_joy_zmove",VALUEFUNC(WxEvtHandler::WxRbEVT_JOY_ZMOVE),-1);
    rb_define_method(rubyClass, "evt_key_down",VALUEFUNC(WxEvtHandler::WxRbEVT_KEY_DOWN),-1);
    rb_define_method(rubyClass, "evt_key_up",VALUEFUNC(WxEvtHandler::WxRbEVT_KEY_UP),-1);
    rb_define_method(rubyClass, "evt_kill_focus",VALUEFUNC(WxEvtHandler::WxRbEVT_KILL_FOCUS),-1);
    rb_define_method(rubyClass, "evt_leave_window",VALUEFUNC(WxEvtHandler::WxRbEVT_LEAVE_WINDOW),-1);
    rb_define_method(rubyClass, "evt_left_dclick",VALUEFUNC(WxEvtHandler::WxRbEVT_LEFT_DCLICK),-1);
    rb_define_method(rubyClass, "evt_left_down",VALUEFUNC(WxEvtHandler::WxRbEVT_LEFT_DOWN),-1);
    rb_define_method(rubyClass, "evt_left_up",VALUEFUNC(WxEvtHandler::WxRbEVT_LEFT_UP),-1);
    rb_define_method(rubyClass, "evt_listbox",VALUEFUNC(WxEvtHandler::WxRbEVT_LISTBOX),-1);
    rb_define_method(rubyClass, "evt_listbox_dclick",VALUEFUNC(WxEvtHandler::WxRbEVT_LISTBOX_DCLICK),-1);
    rb_define_method(rubyClass, "evt_maximize",VALUEFUNC(WxEvtHandler::WxRbEVT_MAXIMIZE),-1);
    rb_define_method(rubyClass, "evt_menu",VALUEFUNC(WxEvtHandler::WxRbEVT_MENU),-1);
    rb_define_method(rubyClass, "evt_menu_highlight",VALUEFUNC(WxEvtHandler::WxRbEVT_MENU_HIGHLIGHT),-1);
    rb_define_method(rubyClass, "evt_menu_highlight_all",VALUEFUNC(WxEvtHandler::WxRbEVT_MENU_HIGHLIGHT_ALL),-1);
    rb_define_method(rubyClass, "evt_menu_range",VALUEFUNC(WxEvtHandler::WxRbEVT_MENU_RANGE),-1);
    rb_define_method(rubyClass, "evt_middle_dclick",VALUEFUNC(WxEvtHandler::WxRbEVT_MIDDLE_DCLICK),-1);
    rb_define_method(rubyClass, "evt_middle_down",VALUEFUNC(WxEvtHandler::WxRbEVT_MIDDLE_DOWN),-1);
    rb_define_method(rubyClass, "evt_middle_up",VALUEFUNC(WxEvtHandler::WxRbEVT_MIDDLE_UP),-1);
    rb_define_method(rubyClass, "evt_motion",VALUEFUNC(WxEvtHandler::WxRbEVT_MOTION),-1);
    rb_define_method(rubyClass, "evt_mousewheel",VALUEFUNC(WxEvtHandler::WxRbEVT_MOUSEWHEEL),-1);
    rb_define_method(rubyClass, "evt_mouse_events",VALUEFUNC(WxEvtHandler::WxRbEVT_MOUSE_EVENTS),-1);
    rb_define_method(rubyClass, "evt_move",VALUEFUNC(WxEvtHandler::WxRbEVT_MOVE),-1);
    rb_define_method(rubyClass, "evt_navigation_key",VALUEFUNC(WxEvtHandler::WxRbEVT_NAVIGATION_KEY),-1);
    rb_define_method(rubyClass, "evt_notebook_page_changed",VALUEFUNC(WxEvtHandler::WxRbEVT_NOTEBOOK_PAGE_CHANGED),-1);
    rb_define_method(rubyClass, "evt_notebook_page_changing",VALUEFUNC(WxEvtHandler::WxRbEVT_NOTEBOOK_PAGE_CHANGING),-1);
    rb_define_method(rubyClass, "evt_paint",VALUEFUNC(WxEvtHandler::WxRbEVT_PAINT),-1);
    rb_define_method(rubyClass, "evt_palette_changed",VALUEFUNC(WxEvtHandler::WxRbEVT_PALETTE_CHANGED),-1);
    rb_define_method(rubyClass, "evt_query_end_session",VALUEFUNC(WxEvtHandler::WxRbEVT_QUERY_END_SESSION),-1);
    rb_define_method(rubyClass, "evt_query_new_palette",VALUEFUNC(WxEvtHandler::WxRbEVT_QUERY_NEW_PALETTE),-1);
    rb_define_method(rubyClass, "evt_radiobox",VALUEFUNC(WxEvtHandler::WxRbEVT_RADIOBOX),-1);
    rb_define_method(rubyClass, "evt_radiobutton",VALUEFUNC(WxEvtHandler::WxRbEVT_RADIOBUTTON),-1);
    rb_define_method(rubyClass, "evt_right_dclick",VALUEFUNC(WxEvtHandler::WxRbEVT_RIGHT_DCLICK),-1);
    rb_define_method(rubyClass, "evt_right_down",VALUEFUNC(WxEvtHandler::WxRbEVT_RIGHT_DOWN),-1);
    rb_define_method(rubyClass, "evt_right_up",VALUEFUNC(WxEvtHandler::WxRbEVT_RIGHT_UP),-1);
#if wxUSE_SASH
    rb_define_method(rubyClass, "evt_sash_dragged",VALUEFUNC(WxEvtHandler::WxRbEVT_SASH_DRAGGED),-1);
    rb_define_method(rubyClass, "evt_sash_dragged_range",VALUEFUNC(WxEvtHandler::WxRbEVT_SASH_DRAGGED_RANGE),-1);
    rb_define_method(rubyClass, "evt_query_layout_info",VALUEFUNC(WxEvtHandler::WxRbEVT_QUERY_LAYOUT_INFO),-1);
    rb_define_method(rubyClass, "evt_calculate_layout",VALUEFUNC(WxEvtHandler::WxRbEVT_CALCULATE_LAYOUT),-1);
#endif
    rb_define_method(rubyClass, "evt_scroll",VALUEFUNC(WxEvtHandler::WxRbEVT_SCROLL),-1);
    rb_define_method(rubyClass, "evt_scrollwin",VALUEFUNC(WxEvtHandler::WxRbEVT_SCROLLWIN),-1);
    rb_define_method(rubyClass, "evt_scrollwin_bottom",VALUEFUNC(WxEvtHandler::WxRbEVT_SCROLLWIN_BOTTOM),-1);
    rb_define_method(rubyClass, "evt_scrollwin_linedown",VALUEFUNC(WxEvtHandler::WxRbEVT_SCROLLWIN_LINEDOWN),-1);
    rb_define_method(rubyClass, "evt_scrollwin_lineup",VALUEFUNC(WxEvtHandler::WxRbEVT_SCROLLWIN_LINEUP),-1);
    rb_define_method(rubyClass, "evt_scrollwin_pagedown",VALUEFUNC(WxEvtHandler::WxRbEVT_SCROLLWIN_PAGEDOWN),-1);
    rb_define_method(rubyClass, "evt_scrollwin_pageup",VALUEFUNC(WxEvtHandler::WxRbEVT_SCROLLWIN_PAGEUP),-1);
    rb_define_method(rubyClass, "evt_scrollwin_thumbrelease",VALUEFUNC(WxEvtHandler::WxRbEVT_SCROLLWIN_THUMBRELEASE),-1);
    rb_define_method(rubyClass, "evt_scrollwin_thumbtrack",VALUEFUNC(WxEvtHandler::WxRbEVT_SCROLLWIN_THUMBTRACK),-1);
    rb_define_method(rubyClass, "evt_scrollwin_top",VALUEFUNC(WxEvtHandler::WxRbEVT_SCROLLWIN_TOP),-1);
    rb_define_method(rubyClass, "evt_scroll_bottom",VALUEFUNC(WxEvtHandler::WxRbEVT_SCROLL_BOTTOM),-1);
    rb_define_method(rubyClass, "evt_scroll_linedown",VALUEFUNC(WxEvtHandler::WxRbEVT_SCROLL_LINEDOWN),-1);
    rb_define_method(rubyClass, "evt_scroll_lineup",VALUEFUNC(WxEvtHandler::WxRbEVT_SCROLL_LINEUP),-1);
    rb_define_method(rubyClass, "evt_scroll_pagedown",VALUEFUNC(WxEvtHandler::WxRbEVT_SCROLL_PAGEDOWN),-1);
    rb_define_method(rubyClass, "evt_scroll_pageup",VALUEFUNC(WxEvtHandler::WxRbEVT_SCROLL_PAGEUP),-1);
    rb_define_method(rubyClass, "evt_scroll_thumbrelease",VALUEFUNC(WxEvtHandler::WxRbEVT_SCROLL_THUMBRELEASE),-1);
    rb_define_method(rubyClass, "evt_scroll_thumbtrack",VALUEFUNC(WxEvtHandler::WxRbEVT_SCROLL_THUMBTRACK),-1);
    rb_define_method(rubyClass, "evt_scroll_top",VALUEFUNC(WxEvtHandler::WxRbEVT_SCROLL_TOP),-1);
    rb_define_method(rubyClass, "evt_set_focus",VALUEFUNC(WxEvtHandler::WxRbEVT_SET_FOCUS),-1);
    rb_define_method(rubyClass, "evt_show",VALUEFUNC(WxEvtHandler::WxRbEVT_SHOW),-1);
    rb_define_method(rubyClass, "evt_size",VALUEFUNC(WxEvtHandler::WxRbEVT_SIZE),-1);
    rb_define_method(rubyClass, "evt_slider",VALUEFUNC(WxEvtHandler::WxRbEVT_SLIDER),-1);
    rb_define_method(rubyClass, "evt_spin",VALUEFUNC(WxEvtHandler::WxRbEVT_SPIN),-1);
    rb_define_method(rubyClass, "evt_spinctrl",VALUEFUNC(WxEvtHandler::WxRbEVT_SPINCTRL),-1);
    rb_define_method(rubyClass, "evt_spin_down",VALUEFUNC(WxEvtHandler::WxRbEVT_SPIN_DOWN),-1);
    rb_define_method(rubyClass, "evt_spin_up",VALUEFUNC(WxEvtHandler::WxRbEVT_SPIN_UP),-1);
    rb_define_method(rubyClass, "evt_splitter_doubleclicked",VALUEFUNC(WxEvtHandler::WxRbEVT_SPLITTER_DOUBLECLICKED),-1);
    rb_define_method(rubyClass, "evt_splitter_dclick",VALUEFUNC(WxEvtHandler::WxRbEVT_SPLITTER_DOUBLECLICKED),-1);
    rb_define_method(rubyClass, "evt_splitter_sash_pos_changed",VALUEFUNC(WxEvtHandler::WxRbEVT_SPLITTER_SASH_POS_CHANGED),-1);
    rb_define_method(rubyClass, "evt_splitter_sash_pos_changing",VALUEFUNC(WxEvtHandler::WxRbEVT_SPLITTER_SASH_POS_CHANGING),-1);
    rb_define_method(rubyClass, "evt_splitter_unsplit",VALUEFUNC(WxEvtHandler::WxRbEVT_SPLITTER_UNSPLIT),-1);
    rb_define_method(rubyClass, "evt_sys_colour_changed",VALUEFUNC(WxEvtHandler::WxRbEVT_SYS_COLOUR_CHANGED),-1);
#ifdef __WXMSW__
    rb_define_method(rubyClass, "evt_taskbar_left_dclick",VALUEFUNC(WxEvtHandler::WxRbEVT_TASKBAR_LEFT_DCLICK),-1);
    rb_define_method(rubyClass, "evt_taskbar_left_down",VALUEFUNC(WxEvtHandler::WxRbEVT_TASKBAR_LEFT_DOWN),-1);
    rb_define_method(rubyClass, "evt_taskbar_left_up",VALUEFUNC(WxEvtHandler::WxRbEVT_TASKBAR_LEFT_UP),-1);
    rb_define_method(rubyClass, "evt_taskbar_move",VALUEFUNC(WxEvtHandler::WxRbEVT_TASKBAR_MOVE),-1);
    rb_define_method(rubyClass, "evt_taskbar_right_dclick",VALUEFUNC(WxEvtHandler::WxRbEVT_TASKBAR_RIGHT_DCLICK),-1);
    rb_define_method(rubyClass, "evt_taskbar_right_down",VALUEFUNC(WxEvtHandler::WxRbEVT_TASKBAR_RIGHT_DOWN),-1);
    rb_define_method(rubyClass, "evt_taskbar_right_up",VALUEFUNC(WxEvtHandler::WxRbEVT_TASKBAR_RIGHT_UP),-1);
#endif
    rb_define_method(rubyClass, "evt_text",VALUEFUNC(WxEvtHandler::WxRbEVT_TEXT),-1);
    rb_define_method(rubyClass, "evt_text_enter",VALUEFUNC(WxEvtHandler::WxRbEVT_TEXT_ENTER),-1);
    rb_define_method(rubyClass, "evt_text_maxlen",VALUEFUNC(WxEvtHandler::WxRbEVT_TEXT_MAXLEN),-1);
    rb_define_method(rubyClass, "evt_text_url",VALUEFUNC(WxEvtHandler::WxRbEVT_TEXT_URL),-1);
    rb_define_method(rubyClass, "evt_timer",VALUEFUNC(WxEvtHandler::WxRbEVT_TIMER),-1);
#if defined(__WXGTK__) || defined(__WXMSW__)
    rb_define_method(rubyClass, "evt_togglebutton",VALUEFUNC(WxEvtHandler::WxRbEVT_TOGGLEBUTTON),-1);
#endif
    rb_define_method(rubyClass, "evt_tool",VALUEFUNC(WxEvtHandler::WxRbEVT_TOOL),-1);
    rb_define_method(rubyClass, "evt_tool_enter",VALUEFUNC(WxEvtHandler::WxRbEVT_TOOL_ENTER),-1);
    rb_define_method(rubyClass, "evt_tool_range",VALUEFUNC(WxEvtHandler::WxRbEVT_TOOL_RANGE),-1);
    rb_define_method(rubyClass, "evt_tool_rclicked",VALUEFUNC(WxEvtHandler::WxRbEVT_TOOL_RCLICKED),-1);
    rb_define_method(rubyClass, "evt_tool_rclicked_range",VALUEFUNC(WxEvtHandler::WxRbEVT_TOOL_RCLICKED_RANGE),-1);
    rb_define_method(rubyClass, "evt_update_ui",VALUEFUNC(WxEvtHandler::WxRbEVT_UPDATE_UI),-1);
    rb_define_method(rubyClass, "evt_update_ui_range",VALUEFUNC(WxEvtHandler::WxRbEVT_UPDATE_UI_RANGE),-1);
    rb_define_method(rubyClass, "evt_vlbox",VALUEFUNC(WxEvtHandler::WxRbEVT_VLBOX),-1);
    rb_define_method(rubyClass, "evt_window_create",VALUEFUNC(WxEvtHandler::WxRbEVT_WINDOW_CREATE),-1);
    rb_define_method(rubyClass, "evt_window_destroy",VALUEFUNC(WxEvtHandler::WxRbEVT_WINDOW_DESTROY),-1);

    rb_define_method(rubyClass, "evt_list_begin_drag",VALUEFUNC(WxEvtHandler::WxRbEVT_LIST_BEGIN_DRAG),-1);
    rb_define_method(rubyClass, "evt_list_begin_label_edit",VALUEFUNC(WxEvtHandler::WxRbEVT_LIST_BEGIN_LABEL_EDIT),-1);
    rb_define_method(rubyClass, "evt_list_begin_rdrag",VALUEFUNC(WxEvtHandler::WxRbEVT_LIST_BEGIN_RDRAG),-1);
    rb_define_method(rubyClass, "evt_list_cache_hint",VALUEFUNC(WxEvtHandler::WxRbEVT_LIST_CACHE_HINT),-1);
    rb_define_method(rubyClass, "evt_list_col_begin_drag",VALUEFUNC(WxEvtHandler::WxRbEVT_LIST_COL_BEGIN_DRAG),-1);
    rb_define_method(rubyClass, "evt_list_col_click",VALUEFUNC(WxEvtHandler::WxRbEVT_LIST_COL_CLICK),-1);
    rb_define_method(rubyClass, "evt_list_col_dragging",VALUEFUNC(WxEvtHandler::WxRbEVT_LIST_COL_DRAGGING),-1);
    rb_define_method(rubyClass, "evt_list_col_end_drag",VALUEFUNC(WxEvtHandler::WxRbEVT_LIST_COL_END_DRAG),-1);
    rb_define_method(rubyClass, "evt_list_col_right_click",VALUEFUNC(WxEvtHandler::WxRbEVT_LIST_COL_RIGHT_CLICK),-1);
    rb_define_method(rubyClass, "evt_list_delete_all_items",VALUEFUNC(WxEvtHandler::WxRbEVT_LIST_DELETE_ALL_ITEMS),-1);
    rb_define_method(rubyClass, "evt_list_delete_item",VALUEFUNC(WxEvtHandler::WxRbEVT_LIST_DELETE_ITEM),-1);
    rb_define_method(rubyClass, "evt_list_end_label_edit",VALUEFUNC(WxEvtHandler::WxRbEVT_LIST_END_LABEL_EDIT),-1);
    rb_define_method(rubyClass, "evt_list_get_info",VALUEFUNC(WxEvtHandler::WxRbEVT_LIST_GET_INFO),-1);
    rb_define_method(rubyClass, "evt_list_insert_item",VALUEFUNC(WxEvtHandler::WxRbEVT_LIST_INSERT_ITEM),-1);
    rb_define_method(rubyClass, "evt_list_item_activated",VALUEFUNC(WxEvtHandler::WxRbEVT_LIST_ITEM_ACTIVATED),-1);
    rb_define_method(rubyClass, "evt_list_item_deselected",VALUEFUNC(WxEvtHandler::WxRbEVT_LIST_ITEM_DESELECTED),-1);
    rb_define_method(rubyClass, "evt_list_item_focused",VALUEFUNC(WxEvtHandler::WxRbEVT_LIST_ITEM_FOCUSED),-1);
    rb_define_method(rubyClass, "evt_list_item_middle_click",VALUEFUNC(WxEvtHandler::WxRbEVT_LIST_ITEM_MIDDLE_CLICK),-1);
    rb_define_method(rubyClass, "evt_list_item_right_click",VALUEFUNC(WxEvtHandler::WxRbEVT_LIST_ITEM_RIGHT_CLICK),-1);
    rb_define_method(rubyClass, "evt_list_item_selected",VALUEFUNC(WxEvtHandler::WxRbEVT_LIST_ITEM_SELECTED),-1);
    rb_define_method(rubyClass, "evt_list_key_down",VALUEFUNC(WxEvtHandler::WxRbEVT_LIST_KEY_DOWN),-1);
    rb_define_method(rubyClass, "evt_list_set_info",VALUEFUNC(WxEvtHandler::WxRbEVT_LIST_SET_INFO),-1);
    rb_define_method(rubyClass, "evt_find",VALUEFUNC(WxEvtHandler::WxRbEVT_FIND),-1);
    rb_define_method(rubyClass, "evt_find_next",VALUEFUNC(WxEvtHandler::WxRbEVT_FIND_NEXT),-1);
    rb_define_method(rubyClass, "evt_find_replace",VALUEFUNC(WxEvtHandler::WxRbEVT_FIND_REPLACE),-1);
    rb_define_method(rubyClass, "evt_find_replace_all",VALUEFUNC(WxEvtHandler::WxRbEVT_FIND_REPLACE_ALL),-1);
    rb_define_method(rubyClass, "evt_find_close",VALUEFUNC(WxEvtHandler::WxRbEVT_FIND_CLOSE),-1);
    rb_define_method(rubyClass, "evt_socket",VALUEFUNC(WxEvtHandler::WxRbEVT_SOCKET),-1);
    rb_define_method(rubyClass, "evt_tree_begin_drag",VALUEFUNC(WxEvtHandler::WxRbEVT_TREE_BEGIN_DRAG),-1);
    rb_define_method(rubyClass, "evt_tree_begin_label_edit",VALUEFUNC(WxEvtHandler::WxRbEVT_TREE_BEGIN_LABEL_EDIT),-1);
    rb_define_method(rubyClass, "evt_tree_begin_rdrag",VALUEFUNC(WxEvtHandler::WxRbEVT_TREE_BEGIN_RDRAG),-1);
    rb_define_method(rubyClass, "evt_tree_delete_item",VALUEFUNC(WxEvtHandler::WxRbEVT_TREE_DELETE_ITEM),-1);
    rb_define_method(rubyClass, "evt_tree_end_drag",VALUEFUNC(WxEvtHandler::WxRbEVT_TREE_END_DRAG            ),-1);
    rb_define_method(rubyClass, "evt_tree_end_label_edit",VALUEFUNC(WxEvtHandler::WxRbEVT_TREE_END_LABEL_EDIT),-1);
    rb_define_method(rubyClass, "evt_tree_get_info",VALUEFUNC(WxEvtHandler::WxRbEVT_TREE_GET_INFO),-1);
    rb_define_method(rubyClass, "evt_tree_item_activated",VALUEFUNC(WxEvtHandler::WxRbEVT_TREE_ITEM_ACTIVATED),-1);
    rb_define_method(rubyClass, "evt_tree_item_collapsed",VALUEFUNC(WxEvtHandler::WxRbEVT_TREE_ITEM_COLLAPSED),-1);
    rb_define_method(rubyClass, "evt_tree_item_collapsing",VALUEFUNC(WxEvtHandler::WxRbEVT_TREE_ITEM_COLLAPSING),-1);
    rb_define_method(rubyClass, "evt_tree_item_expanded",VALUEFUNC(WxEvtHandler::WxRbEVT_TREE_ITEM_EXPANDED),-1);
    rb_define_method(rubyClass, "evt_tree_item_expanding",VALUEFUNC(WxEvtHandler::WxRbEVT_TREE_ITEM_EXPANDING),-1);
    rb_define_method(rubyClass, "evt_tree_item_middle_click",VALUEFUNC(WxEvtHandler::WxRbEVT_TREE_ITEM_MIDDLE_CLICK),-1);
    rb_define_method(rubyClass, "evt_tree_item_right_click",VALUEFUNC(WxEvtHandler::WxRbEVT_TREE_ITEM_RIGHT_CLICK),-1);
    rb_define_method(rubyClass, "evt_tree_key_down",VALUEFUNC(WxEvtHandler::WxRbEVT_TREE_KEY_DOWN),-1);
    rb_define_method(rubyClass, "evt_tree_sel_changed",VALUEFUNC(WxEvtHandler::WxRbEVT_TREE_SEL_CHANGED),-1);
    rb_define_method(rubyClass, "evt_tree_sel_changing",VALUEFUNC(WxEvtHandler::WxRbEVT_TREE_SEL_CHANGING),-1);
    rb_define_method(rubyClass, "evt_tree_set_info",VALUEFUNC(WxEvtHandler::WxRbEVT_TREE_SET_INFO),-1);
}

VALUE
WxEvtHandler::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxEvtHandler::init0(wxEvtHandler *handler)
{
    VALUE self = Data_Wrap_Struct(rubyClass, 0, 0, 0);
    DATA_PTR(self) = handler;
    return self;
}

void
WxEvtHandler::Connect(VALUE rubyClass,VALUE rubyId,VALUE rubyLastId,VALUE rubyType,VALUE rubyBlock)
{
    int id = NUM2INT(rubyId);
    int lastId = NUM2INT(rubyLastId);
    wxEventType eventType = rubyType;
	VALUE func = rubyBlock;

	// make sure func won't get garbage collected	
	rb_ary_push(eventCallbackArray, func);
	
    wxObjectEventFunction function = (wxObjectEventFunction )&wxRbCallback::EventThunker;
    wxObject* userData = new wxRbCallback(func);
    wxEvtHandler *ptr;
    Data_Get_Struct(rubyClass, wxEvtHandler, ptr);
    ptr->Connect(id,lastId,eventType,function,userData);
}

void
WxEvtHandler::AddPendingEvent(VALUE self,VALUE vevent)
{
    wxEvent *event;
    Data_Get_Struct(vevent, wxEvent, event);
    wxEvtHandler *ptr;
    Data_Get_Struct(self, wxEvtHandler, ptr);
    ptr->AddPendingEvent(*event);
}

VALUE
WxEvtHandler::GetClientData(VALUE self)
{
    wxEvtHandler *ptr;
    Data_Get_Struct(self, wxEvtHandler, ptr);
    void *data = ptr->GetClientData();
    if(data==NULL)
        return Qnil;
    else
        return rb_hash_aref((VALUE)data, rb_str_new2("data"));
}

VALUE
WxEvtHandler::GetEvtHandlerEnabled(VALUE self)
{
    wxEvtHandler *ptr;
    Data_Get_Struct(self, wxEvtHandler, ptr);
    return (ptr->GetEvtHandlerEnabled() ? Qtrue : Qfalse);
}

VALUE
WxEvtHandler::GetNextHandler(VALUE self)
{
    wxEvtHandler *ptr;
    Data_Get_Struct(self, wxEvtHandler, ptr);
    return WxEvtHandler::init0(ptr->GetNextHandler());
}

VALUE
WxEvtHandler::GetPreviousHandler(VALUE self)
{
    wxEvtHandler *ptr;
    Data_Get_Struct(self, wxEvtHandler, ptr);
    return WxEvtHandler::init0(ptr->GetPreviousHandler());
}

VALUE
WxEvtHandler::ProcessEvent(VALUE self,VALUE vevent)
{
    wxEvent *event;
    Data_Get_Struct(vevent, wxEvent, event);
    wxEvtHandler *ptr;
    Data_Get_Struct(self, wxEvtHandler, ptr);
    return (ptr->ProcessEvent(*event) ? Qtrue : Qfalse);
}

void
WxEvtHandler::SetClientData(VALUE self,VALUE vcdata)
{
    wxEvtHandler *ptr;
    Data_Get_Struct(self, wxEvtHandler, ptr);

    void *data = ptr->GetClientData();
    VALUE vdata;
    if(data==NULL)
        vdata = rb_hash_new();
    else
        vdata = (VALUE)data;
    rb_hash_aset(vdata,rb_str_new2("data"),vcdata);

    ptr->SetClientData((void*)vdata);
}


void
WxEvtHandler::SetEvtHandlerEnabled(VALUE self,VALUE venabled)
{
    bool enabled = (venabled == Qtrue);
    wxEvtHandler *ptr;
    Data_Get_Struct(self, wxEvtHandler, ptr);
    ptr->SetEvtHandlerEnabled(enabled);
}

void
WxEvtHandler::SetNextHandler(VALUE self,VALUE vhandler)
{
    wxEvtHandler* handler;
    Data_Get_Struct(vhandler, wxEvtHandler, handler);
    wxEvtHandler *ptr;
    Data_Get_Struct(self, wxEvtHandler, ptr);
    ptr->SetNextHandler(handler);
}

void
WxEvtHandler::SetPreviousHandler(VALUE self,VALUE vhandler)
{
    wxEvtHandler* handler;
    Data_Get_Struct(vhandler, wxEvtHandler, handler);
    wxEvtHandler *ptr;
    Data_Get_Struct(self, wxEvtHandler, ptr);
    ptr->SetPreviousHandler(handler);
}

///////////////////////////////////////////////////////////////////////////////
// Miscellaneous
void WxEvtHandler::WxRbEVT_SIZE(int argc, VALUE* argv, VALUE self) {
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "0&", &func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_SIZE, func);
}
void WxEvtHandler::WxRbEVT_MOVE(int argc, VALUE* argv, VALUE self) {
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "0&", &func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_MOVE, func);
}
void WxEvtHandler::WxRbEVT_CLOSE(int argc, VALUE* argv, VALUE self) {
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "0&", &func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_CLOSE_WINDOW, func);
}
void WxEvtHandler::WxRbEVT_PAINT(int argc, VALUE* argv, VALUE self) {
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "0&", &func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_PAINT, func);
}
void WxEvtHandler::WxRbEVT_ERASE_BACKGROUND(int argc, VALUE* argv, VALUE self) {
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "0&", &func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_ERASE_BACKGROUND, func);
}
void WxEvtHandler::WxRbEVT_CHAR(int argc, VALUE* argv, VALUE self) {
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "0&", &func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_CHAR, func);
}
void WxEvtHandler::WxRbEVT_CHAR_HOOK(int argc, VALUE* argv, VALUE self) {
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "0&", &func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_CHAR_HOOK, func);
}
void WxEvtHandler::WxRbEVT_KEY_DOWN(int argc, VALUE* argv, VALUE self) {
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "0&", &func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_KEY_DOWN, func);
}
void WxEvtHandler::WxRbEVT_KEY_UP(int argc, VALUE* argv, VALUE self) {
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "0&", &func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_KEY_UP, func);
}
void WxEvtHandler::WxRbEVT_MENU_HIGHLIGHT(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_MENU_HIGHLIGHT, func);
}
void WxEvtHandler::WxRbEVT_MENU_HIGHLIGHT_ALL(int argc, VALUE* argv, VALUE self) {
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "0&", &func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_MENU_HIGHLIGHT, func);
}
void WxEvtHandler::WxRbEVT_SET_FOCUS(int argc, VALUE* argv, VALUE self) {
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "0&", &func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_SET_FOCUS, func);
}
void WxEvtHandler::WxRbEVT_KILL_FOCUS(int argc, VALUE* argv, VALUE self) {
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "0&", &func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_KILL_FOCUS, func);
}
void WxEvtHandler::WxRbEVT_CHILD_FOCUS(int argc, VALUE* argv, VALUE self) {
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "0&", &func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_CHILD_FOCUS, func);
}
void WxEvtHandler::WxRbEVT_ACTIVATE(int argc, VALUE* argv, VALUE self) {
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "0&", &func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_ACTIVATE, func);
}
void WxEvtHandler::WxRbEVT_ACTIVATE_APP(int argc, VALUE* argv, VALUE self) {
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "0&", &func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_ACTIVATE_APP, func);
}
void WxEvtHandler::WxRbEVT_END_SESSION(int argc, VALUE* argv, VALUE self) {
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "0&", &func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_END_SESSION, func);
}
void WxEvtHandler::WxRbEVT_QUERY_END_SESSION(int argc, VALUE* argv, VALUE self) {
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "0&", &func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_QUERY_END_SESSION, func);
}
void WxEvtHandler::WxRbEVT_DROP_FILES(int argc, VALUE* argv, VALUE self) {
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "0&", &func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_DROP_FILES, func);
}
void WxEvtHandler::WxRbEVT_INIT_DIALOG(int argc, VALUE* argv, VALUE self) {
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "0&", &func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_INIT_DIALOG, func);
}
void WxEvtHandler::WxRbEVT_SYS_COLOUR_CHANGED(int argc, VALUE* argv, VALUE self) {
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "0&", &func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_SYS_COLOUR_CHANGED, func);
}
void WxEvtHandler::WxRbEVT_SHOW(int argc, VALUE* argv, VALUE self) {
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "0&", &func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_SHOW, func);
}
void WxEvtHandler::WxRbEVT_MAXIMIZE(int argc, VALUE* argv, VALUE self) {
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "0&", &func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_MAXIMIZE, func);
}
void WxEvtHandler::WxRbEVT_ICONIZE(int argc, VALUE* argv, VALUE self) {
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "0&", &func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_ICONIZE, func);
}
void WxEvtHandler::WxRbEVT_NAVIGATION_KEY(int argc, VALUE* argv, VALUE self) {
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "0&", &func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_NAVIGATION_KEY, func);
}
void WxEvtHandler::WxRbEVT_PALETTE_CHANGED(int argc, VALUE* argv, VALUE self) {
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "0&", &func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_PALETTE_CHANGED, func);
}
void WxEvtHandler::WxRbEVT_QUERY_NEW_PALETTE(int argc, VALUE* argv, VALUE self) {
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "0&", &func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_QUERY_NEW_PALETTE, func);
}
void WxEvtHandler::WxRbEVT_WINDOW_CREATE(int argc, VALUE* argv, VALUE self) {
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "0&", &func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_CREATE, func);
}
void WxEvtHandler::WxRbEVT_WINDOW_DESTROY(int argc, VALUE* argv, VALUE self) {
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "0&", &func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_DESTROY, func);
}
void WxEvtHandler::WxRbEVT_IDLE(int argc, VALUE* argv, VALUE self) {
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "0&", &func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_IDLE, func);
}
void WxEvtHandler::WxRbEVT_UPDATE_UI(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_UPDATE_UI, func);
}
void WxEvtHandler::WxRbEVT_UPDATE_UI_RANGE(int argc, VALUE* argv, VALUE self) {
	VALUE id1 = NUM2INT(-1);
	VALUE id2 = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "2&", &id1, &id2, &func);
    Connect(self, id1, id2, wxEVT_UPDATE_UI, func);
}

// Mouse Events
void WxEvtHandler::WxRbEVT_LEFT_DOWN(int argc, VALUE* argv, VALUE self) {
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "0&", &func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_LEFT_DOWN, func);
}
void WxEvtHandler::WxRbEVT_LEFT_UP(int argc, VALUE* argv, VALUE self) {
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "0&", &func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_LEFT_UP, func);
}
void WxEvtHandler::WxRbEVT_MIDDLE_DOWN(int argc, VALUE* argv, VALUE self) {
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "0&", &func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_MIDDLE_DOWN, func);
}
void WxEvtHandler::WxRbEVT_MIDDLE_UP(int argc, VALUE* argv, VALUE self) {
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "0&", &func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_MIDDLE_UP, func);
}
void WxEvtHandler::WxRbEVT_RIGHT_DOWN(int argc, VALUE* argv, VALUE self) {
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "0&", &func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_RIGHT_DOWN, func);
}
void WxEvtHandler::WxRbEVT_RIGHT_UP(int argc, VALUE* argv, VALUE self) {
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "0&", &func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_RIGHT_UP, func);
}
void WxEvtHandler::WxRbEVT_MOTION(int argc, VALUE* argv, VALUE self) {
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "0&", &func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_MOTION, func);
}
void WxEvtHandler::WxRbEVT_LEFT_DCLICK(int argc, VALUE* argv, VALUE self) {
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "0&", &func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_LEFT_DCLICK, func);
}
void WxEvtHandler::WxRbEVT_MIDDLE_DCLICK(int argc, VALUE* argv, VALUE self) {
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "0&", &func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_MIDDLE_DCLICK, func);
}
void WxEvtHandler::WxRbEVT_RIGHT_DCLICK(int argc, VALUE* argv, VALUE self) {
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "0&", &func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_RIGHT_DCLICK, func);
}
void WxEvtHandler::WxRbEVT_LEAVE_WINDOW(int argc, VALUE* argv, VALUE self) {
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "0&", &func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_LEAVE_WINDOW, func);
}
void WxEvtHandler::WxRbEVT_ENTER_WINDOW(int argc, VALUE* argv, VALUE self) {
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "0&", &func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_ENTER_WINDOW, func);
}
void WxEvtHandler::WxRbEVT_MOUSEWHEEL(int argc, VALUE* argv, VALUE self) {
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "0&", &func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_MOUSEWHEEL, func);
}
// all mouse events
void WxEvtHandler::WxRbEVT_MOUSE_EVENTS(int argc, VALUE* argv, VALUE self) {
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "0&", &func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_LEFT_DOWN,     func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_LEFT_UP,       func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_MIDDLE_DOWN,   func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_MIDDLE_UP,     func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_RIGHT_DOWN,    func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_RIGHT_UP,      func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_MOTION,        func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_LEFT_DCLICK,   func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_MIDDLE_DCLICK, func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_RIGHT_DCLICK,  func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_LEAVE_WINDOW,  func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_ENTER_WINDOW,  func);
}
// EVT_COMMAND
void WxEvtHandler::WxRbEVT_COMMAND(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE cmd = Qnil;
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "2&", &id, &cmd, &func);
    Connect(self, id, INT2NUM(-1), cmd, func);
}
void WxEvtHandler::WxRbEVT_COMMAND_RANGE(int argc, VALUE* argv, VALUE self) {
	VALUE id1 = NUM2INT(-1);
	VALUE id2 = NUM2INT(-1);
	VALUE cmd = Qnil;
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "3&", &id1, &id2, &cmd, &func);
    Connect(self, id1, id2, cmd, func);
}

// Scrolling
void WxEvtHandler::WxRbEVT_SCROLL(int argc, VALUE* argv, VALUE self) {
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "0&", &func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_SCROLL_TOP,       func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_SCROLL_BOTTOM,    func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_SCROLL_LINEUP,    func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_SCROLL_LINEDOWN,  func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_SCROLL_PAGEUP,    func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_SCROLL_PAGEDOWN,  func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_SCROLL_THUMBTRACK,func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_SCROLL_THUMBRELEASE,func);
}
void WxEvtHandler::WxRbEVT_SCROLL_TOP(int argc, VALUE* argv, VALUE self) {
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "0&", &func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_SCROLL_TOP, func);
}
void WxEvtHandler::WxRbEVT_SCROLL_BOTTOM(int argc, VALUE* argv, VALUE self) {
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "0&", &func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_SCROLL_BOTTOM, func);
}
void WxEvtHandler::WxRbEVT_SCROLL_LINEUP(int argc, VALUE* argv, VALUE self) {
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "0&", &func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_SCROLL_LINEUP, func);
}
void WxEvtHandler::WxRbEVT_SCROLL_LINEDOWN(int argc, VALUE* argv, VALUE self) {
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "0&", &func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_SCROLL_LINEDOWN, func);
}
void WxEvtHandler::WxRbEVT_SCROLL_PAGEUP(int argc, VALUE* argv, VALUE self) {
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "0&", &func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_SCROLL_PAGEUP, func);
}
void WxEvtHandler::WxRbEVT_SCROLL_PAGEDOWN(int argc, VALUE* argv, VALUE self) {
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "0&", &func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_SCROLL_PAGEDOWN, func);
}
void WxEvtHandler::WxRbEVT_SCROLL_THUMBTRACK(int argc, VALUE* argv, VALUE self) {
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "0&", &func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_SCROLL_THUMBTRACK, func);
}
void WxEvtHandler::WxRbEVT_SCROLL_THUMBRELEASE(int argc, VALUE* argv, VALUE self) {
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "0&", &func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_SCROLL_THUMBRELEASE, func);
}

// Scrolling, with an id
void WxEvtHandler::WxRbEVT_COMMAND_SCROLL(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_SCROLL_TOP,       func);
    Connect(self, id, INT2NUM(-1), wxEVT_SCROLL_BOTTOM,    func);
    Connect(self, id, INT2NUM(-1), wxEVT_SCROLL_LINEUP,    func);
    Connect(self, id, INT2NUM(-1), wxEVT_SCROLL_LINEDOWN,  func);
    Connect(self, id, INT2NUM(-1), wxEVT_SCROLL_PAGEUP,    func);
    Connect(self, id, INT2NUM(-1), wxEVT_SCROLL_PAGEDOWN,  func);
    Connect(self, id, INT2NUM(-1), wxEVT_SCROLL_THUMBTRACK,func);
    Connect(self, id, INT2NUM(-1), wxEVT_SCROLL_THUMBRELEASE,func);
}
void WxEvtHandler::WxRbEVT_COMMAND_SCROLL_TOP(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_SCROLL_TOP, func);
}
void WxEvtHandler::WxRbEVT_COMMAND_SCROLL_BOTTOM(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_SCROLL_BOTTOM, func);
}
void WxEvtHandler::WxRbEVT_COMMAND_SCROLL_LINEUP(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_SCROLL_LINEUP, func);
}
void WxEvtHandler::WxRbEVT_COMMAND_SCROLL_LINEDOWN(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_SCROLL_LINEDOWN, func);
}
void WxEvtHandler::WxRbEVT_COMMAND_SCROLL_PAGEUP(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_SCROLL_PAGEUP, func);
}
void WxEvtHandler::WxRbEVT_COMMAND_SCROLL_PAGEDOWN(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_SCROLL_PAGEDOWN, func);
}
void WxEvtHandler::WxRbEVT_COMMAND_SCROLL_THUMBTRACK(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_SCROLL_THUMBTRACK, func);
}
void WxEvtHandler::WxRbEVT_COMMAND_SCROLL_THUMBRELEASE(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_SCROLL_THUMBRELEASE, func);
}


void WxEvtHandler::WxRbEVT_SCROLLWIN(int argc, VALUE* argv, VALUE self) {
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "0&", &func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_SCROLLWIN_TOP,         func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_SCROLLWIN_BOTTOM,      func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_SCROLLWIN_LINEUP,      func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_SCROLLWIN_LINEDOWN,    func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_SCROLLWIN_PAGEUP,      func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_SCROLLWIN_PAGEDOWN,    func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_SCROLLWIN_THUMBTRACK,  func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_SCROLLWIN_THUMBRELEASE,func);
}
void WxEvtHandler::WxRbEVT_SCROLLWIN_TOP(int argc, VALUE* argv, VALUE self) {
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "0&", &func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_SCROLLWIN_TOP, func);
}
void WxEvtHandler::WxRbEVT_SCROLLWIN_BOTTOM(int argc, VALUE* argv, VALUE self) {
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "0&", &func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_SCROLLWIN_BOTTOM, func);
}
void WxEvtHandler::WxRbEVT_SCROLLWIN_LINEUP(int argc, VALUE* argv, VALUE self) {
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "0&", &func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_SCROLLWIN_LINEUP, func);
}
void WxEvtHandler::WxRbEVT_SCROLLWIN_LINEDOWN(int argc, VALUE* argv, VALUE self) {
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "0&", &func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_SCROLLWIN_LINEDOWN, func);
}
void WxEvtHandler::WxRbEVT_SCROLLWIN_PAGEUP(int argc, VALUE* argv, VALUE self) {
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "0&", &func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_SCROLLWIN_PAGEUP, func);
}
void WxEvtHandler::WxRbEVT_SCROLLWIN_PAGEDOWN(int argc, VALUE* argv, VALUE self) {
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "0&", &func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_SCROLLWIN_PAGEDOWN, func);
}
void WxEvtHandler::WxRbEVT_SCROLLWIN_THUMBTRACK(int argc, VALUE* argv, VALUE self) {
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "0&", &func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_SCROLLWIN_THUMBTRACK, func);
}
void WxEvtHandler::WxRbEVT_SCROLLWIN_THUMBRELEASE(int argc, VALUE* argv, VALUE self) {
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "0&", &func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_SCROLLWIN_THUMBRELEASE, func);
}

// Scrolling, with an id
void WxEvtHandler::WxRbEVT_COMMAND_SCROLLWIN(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_SCROLLWIN_TOP,         func);
    Connect(self, id, INT2NUM(-1), wxEVT_SCROLLWIN_BOTTOM,      func);
    Connect(self, id, INT2NUM(-1), wxEVT_SCROLLWIN_LINEUP,      func);
    Connect(self, id, INT2NUM(-1), wxEVT_SCROLLWIN_LINEDOWN,    func);
    Connect(self, id, INT2NUM(-1), wxEVT_SCROLLWIN_PAGEUP,      func);
    Connect(self, id, INT2NUM(-1), wxEVT_SCROLLWIN_PAGEDOWN,    func);
    Connect(self, id, INT2NUM(-1), wxEVT_SCROLLWIN_THUMBTRACK,  func);
    Connect(self, id, INT2NUM(-1), wxEVT_SCROLLWIN_THUMBRELEASE,func);
}
void WxEvtHandler::WxRbEVT_COMMAND_SCROLLWIN_TOP(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_SCROLLWIN_TOP, func);
}
void WxEvtHandler::WxRbEVT_COMMAND_SCROLLWIN_BOTTOM(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_SCROLLWIN_BOTTOM, func);
}
void WxEvtHandler::WxRbEVT_COMMAND_SCROLLWIN_LINEUP(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_SCROLLWIN_LINEUP, func);
}
void WxEvtHandler::WxRbEVT_COMMAND_SCROLLWIN_LINEDOWN(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_SCROLLWIN_LINEDOWN, func);
}
void WxEvtHandler::WxRbEVT_COMMAND_SCROLLWIN_PAGEUP(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_SCROLLWIN_PAGEUP, func);
}
void WxEvtHandler::WxRbEVT_COMMAND_SCROLLWIN_PAGEDOWN(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_SCROLLWIN_PAGEDOWN, func);
}
void WxEvtHandler::WxRbEVT_COMMAND_SCROLLWIN_THUMBTRACK(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_SCROLLWIN_THUMBTRACK, func);
}
void WxEvtHandler::WxRbEVT_COMMAND_SCROLLWIN_THUMBRELEASE(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_SCROLLWIN_THUMBRELEASE, func);
}

// Convenience commands
void WxEvtHandler::WxRbEVT_BUTTON(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_COMMAND_BUTTON_CLICKED, func);
}
void WxEvtHandler::WxRbEVT_CHECKBOX(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_COMMAND_CHECKBOX_CLICKED, func);
}
void WxEvtHandler::WxRbEVT_CHOICE(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_COMMAND_CHOICE_SELECTED, func);
}
void WxEvtHandler::WxRbEVT_LISTBOX(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_COMMAND_LISTBOX_SELECTED, func);
}
void WxEvtHandler::WxRbEVT_LISTBOX_DCLICK(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_COMMAND_LISTBOX_DOUBLECLICKED, func);
}
void WxEvtHandler::WxRbEVT_TEXT(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_COMMAND_TEXT_UPDATED, func);
}
void WxEvtHandler::WxRbEVT_TEXT_ENTER(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_COMMAND_TEXT_ENTER, func);
}
void WxEvtHandler::WxRbEVT_TEXT_URL(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_COMMAND_TEXT_URL, func);
}
void WxEvtHandler::WxRbEVT_TEXT_MAXLEN(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_COMMAND_TEXT_MAXLEN, func);
}
void WxEvtHandler::WxRbEVT_MENU(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_COMMAND_MENU_SELECTED, func);
}
void WxEvtHandler::WxRbEVT_MENU_RANGE(int argc, VALUE* argv, VALUE self) {
	VALUE id1 = NUM2INT(-1);
	VALUE id2 = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "2&", &id1, &id2, &func);
    Connect(self, id1, id2, wxEVT_COMMAND_MENU_SELECTED, func);
}
void WxEvtHandler::WxRbEVT_SLIDER(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_COMMAND_SLIDER_UPDATED, func);
}
void WxEvtHandler::WxRbEVT_RADIOBOX(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_COMMAND_RADIOBOX_SELECTED, func);
}
void WxEvtHandler::WxRbEVT_RADIOBUTTON(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_COMMAND_RADIOBUTTON_SELECTED, func);
}
void WxEvtHandler::WxRbEVT_VLBOX(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_COMMAND_VLBOX_SELECTED, func);
}
void WxEvtHandler::WxRbEVT_COMBOBOX(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_COMMAND_COMBOBOX_SELECTED, func);
}
void WxEvtHandler::WxRbEVT_TOOL(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_COMMAND_TOOL_CLICKED, func);
}
void WxEvtHandler::WxRbEVT_TOOL_RANGE(int argc, VALUE* argv, VALUE self) {
	VALUE id1 = NUM2INT(-1);
	VALUE id2 = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "2&", &id1, &id2, &func);
    Connect(self, id1, id2, wxEVT_COMMAND_TOOL_CLICKED, func);
}
void WxEvtHandler::WxRbEVT_TOOL_RCLICKED(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_COMMAND_TOOL_RCLICKED, func);
}
void WxEvtHandler::WxRbEVT_TOOL_RCLICKED_RANGE(int argc, VALUE* argv, VALUE self) {
	VALUE id1 = NUM2INT(-1);
	VALUE id2 = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "2&", &id1, &id2, &func);
    Connect(self, id1, id2, wxEVT_COMMAND_TOOL_RCLICKED, func);
}
void WxEvtHandler::WxRbEVT_TOOL_ENTER(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_COMMAND_TOOL_ENTER, func);
}
void WxEvtHandler::WxRbEVT_CHECKLISTBOX(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_COMMAND_CHECKLISTBOX_TOGGLED, func);
}
void WxEvtHandler::WxRbEVT_SPINCTRL(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_COMMAND_SPINCTRL_UPDATED, func);
}


// Generic command events
void WxEvtHandler::WxRbEVT_COMMAND_LEFT_CLICK(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_COMMAND_LEFT_CLICK, func);
}
void WxEvtHandler::WxRbEVT_COMMAND_LEFT_DCLICK(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_COMMAND_LEFT_DCLICK, func);
}
void WxEvtHandler::WxRbEVT_COMMAND_RIGHT_CLICK(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_COMMAND_RIGHT_CLICK, func);
}
void WxEvtHandler::WxRbEVT_COMMAND_RIGHT_DCLICK(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_COMMAND_RIGHT_DCLICK, func);
}
void WxEvtHandler::WxRbEVT_COMMAND_SET_FOCUS(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_COMMAND_SET_FOCUS, func);
}
void WxEvtHandler::WxRbEVT_COMMAND_KILL_FOCUS(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_COMMAND_KILL_FOCUS, func);
}
void WxEvtHandler::WxRbEVT_COMMAND_ENTER(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_COMMAND_ENTER, func);
}

// wxNotebook events
void WxEvtHandler::WxRbEVT_NOTEBOOK_PAGE_CHANGED(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED, func);
}
void WxEvtHandler::WxRbEVT_NOTEBOOK_PAGE_CHANGING(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGING, func);
}

// wxSpinButton
void WxEvtHandler::WxRbEVT_SPIN_UP(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_SCROLL_LINEUP, func);
}
void WxEvtHandler::WxRbEVT_SPIN_DOWN(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_SCROLL_LINEDOWN, func);
}
void WxEvtHandler::WxRbEVT_SPIN(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_SCROLL_THUMBTRACK,func);
}

#ifdef __WXMSW__
// wxTaskBarIcon
void WxEvtHandler::WxRbEVT_TASKBAR_MOVE(int argc, VALUE* argv, VALUE self) {
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "0&", &func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_TASKBAR_MOVE, func);
}
void WxEvtHandler::WxRbEVT_TASKBAR_LEFT_DOWN(int argc, VALUE* argv, VALUE self) {
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "0&", &func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_TASKBAR_LEFT_DOWN, func);
}
void WxEvtHandler::WxRbEVT_TASKBAR_LEFT_UP(int argc, VALUE* argv, VALUE self) {
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "0&", &func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_TASKBAR_LEFT_UP, func);
}
void WxEvtHandler::WxRbEVT_TASKBAR_RIGHT_DOWN(int argc, VALUE* argv, VALUE self) {
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "0&", &func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_TASKBAR_RIGHT_DOWN, func);
}
void WxEvtHandler::WxRbEVT_TASKBAR_RIGHT_UP(int argc, VALUE* argv, VALUE self) {
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "0&", &func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_TASKBAR_RIGHT_UP, func);
}
void WxEvtHandler::WxRbEVT_TASKBAR_LEFT_DCLICK(int argc, VALUE* argv, VALUE self) {
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "0&", &func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_TASKBAR_LEFT_DCLICK, func);
}
void WxEvtHandler::WxRbEVT_TASKBAR_RIGHT_DCLICK(int argc, VALUE* argv, VALUE self) {
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "0&", &func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_TASKBAR_RIGHT_DCLICK, func);
}
#endif

#if wxUSE_SASH
// wxSashWindow
void WxEvtHandler::WxRbEVT_SASH_DRAGGED(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_SASH_DRAGGED, func);
}
void WxEvtHandler::WxRbEVT_SASH_DRAGGED_RANGE(int argc, VALUE* argv, VALUE self) {
	VALUE id1 = NUM2INT(-1);
	VALUE id2 = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "2&", &id1, &id2, &func);
    Connect(self, id1, id2, wxEVT_SASH_DRAGGED, func);
}
void WxEvtHandler::WxRbEVT_QUERY_LAYOUT_INFO(int argc, VALUE* argv, VALUE self) {
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "0&", &func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_QUERY_LAYOUT_INFO, func);
}
void WxEvtHandler::WxRbEVT_CALCULATE_LAYOUT(int argc, VALUE* argv, VALUE self) {
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "0&", &func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_CALCULATE_LAYOUT, func);
}
#endif

//wxSplitterWindow
void WxEvtHandler::WxRbEVT_SPLITTER_SASH_POS_CHANGING(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_COMMAND_SPLITTER_SASH_POS_CHANGING, func);
}
void WxEvtHandler::WxRbEVT_SPLITTER_SASH_POS_CHANGED(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_COMMAND_SPLITTER_SASH_POS_CHANGED, func);
}
void WxEvtHandler::WxRbEVT_SPLITTER_UNSPLIT(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_COMMAND_SPLITTER_UNSPLIT, func);
}
void WxEvtHandler::WxRbEVT_SPLITTER_DOUBLECLICKED(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_COMMAND_SPLITTER_DOUBLECLICKED, func);
}

// wxTimer
void WxEvtHandler::WxRbEVT_TIMER(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_TIMER, func);
}
// wxProcess
void WxEvtHandler::WxRbEVT_END_PROCESS(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_END_PROCESS, func);
}

// wxJoyStick
void WxEvtHandler::WxRbEVT_JOY_DOWN(int argc, VALUE* argv, VALUE self) {
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "0&", &func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_JOY_BUTTON_DOWN, func);
}
void WxEvtHandler::WxRbEVT_JOY_UP(int argc, VALUE* argv, VALUE self) {
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "0&", &func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_JOY_BUTTON_UP, func);
}
void WxEvtHandler::WxRbEVT_JOY_MOVE(int argc, VALUE* argv, VALUE self) {
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "0&", &func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_JOY_MOVE, func);
}
void WxEvtHandler::WxRbEVT_JOY_ZMOVE(int argc, VALUE* argv, VALUE self) {
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "0&", &func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_JOY_ZMOVE, func);
}
void WxEvtHandler::WxRbEVT_JOYSTICK_EVENTS(int argc, VALUE* argv, VALUE self) {
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "0&", &func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_JOY_BUTTON_DOWN, func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_JOY_BUTTON_UP, func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_JOY_MOVE, func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_JOY_ZMOVE, func);
}

#if defined(__WXGTK__) || defined(__WXMSW__)
void WxEvtHandler::WxRbEVT_TOGGLEBUTTON(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, func);
}
#endif

// Help events
void WxEvtHandler::WxRbEVT_HELP(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_HELP, func);
}
void WxEvtHandler::WxRbEVT_HELP_RANGE(int argc, VALUE* argv, VALUE self) {
	VALUE id1 = NUM2INT(-1);
	VALUE id2 = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "2&", &id1, &id2, &func);
    Connect(self, id1, id2, wxEVT_HELP, func);
}
void WxEvtHandler::WxRbEVT_DETAILED_HELP(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_DETAILED_HELP, func);
}
void WxEvtHandler::WxRbEVT_DETAILED_HELP_RANGE(int argc, VALUE* argv, VALUE self) {
	VALUE id1 = NUM2INT(-1);
	VALUE id2 = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "2&", &id1, &id2, &func);
    Connect(self, id1, id2, wxEVT_DETAILED_HELP, func);
}
void WxEvtHandler::WxRbEVT_CONTEXT_MENU(int argc, VALUE* argv, VALUE self) {
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "0&", &func);
    Connect(self, INT2NUM(-1), INT2NUM(-1), wxEVT_CONTEXT_MENU, func);
}

void WxEvtHandler::WxRbEVT_CALENDAR(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_CALENDAR_DOUBLECLICKED, func);
}
void WxEvtHandler::WxRbEVT_CALENDAR_SEL_CHANGED(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_CALENDAR_SEL_CHANGED, func);
}
void WxEvtHandler::WxRbEVT_CALENDAR_DAY(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_CALENDAR_DAY_CHANGED, func);
}
void WxEvtHandler::WxRbEVT_CALENDAR_MONTH(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_CALENDAR_MONTH_CHANGED, func);
}
void WxEvtHandler::WxRbEVT_CALENDAR_YEAR(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_CALENDAR_YEAR_CHANGED, func);
}
void WxEvtHandler::WxRbEVT_CALENDAR_WEEKDAY_CLICKED(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_CALENDAR_WEEKDAY_CLICKED, func);
}

void WxEvtHandler::WxRbEVT_LIST_BEGIN_DRAG(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_COMMAND_LIST_BEGIN_DRAG, func);
}
void WxEvtHandler::WxRbEVT_LIST_BEGIN_RDRAG(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_COMMAND_LIST_BEGIN_RDRAG, func);
}
void WxEvtHandler::WxRbEVT_LIST_BEGIN_LABEL_EDIT(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_COMMAND_LIST_BEGIN_LABEL_EDIT, func);
}
void WxEvtHandler::WxRbEVT_LIST_END_LABEL_EDIT(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_COMMAND_LIST_END_LABEL_EDIT, func);
}
void WxEvtHandler::WxRbEVT_LIST_DELETE_ITEM(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_COMMAND_LIST_DELETE_ITEM, func);
}
void WxEvtHandler::WxRbEVT_LIST_DELETE_ALL_ITEMS(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_COMMAND_LIST_DELETE_ALL_ITEMS, func);
}
void WxEvtHandler::WxRbEVT_LIST_GET_INFO(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_COMMAND_LIST_GET_INFO, func);
}
void WxEvtHandler::WxRbEVT_LIST_SET_INFO(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_COMMAND_LIST_SET_INFO, func);
}
void WxEvtHandler::WxRbEVT_LIST_KEY_DOWN(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_COMMAND_LIST_KEY_DOWN, func);
}
void WxEvtHandler::WxRbEVT_LIST_INSERT_ITEM(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_COMMAND_LIST_INSERT_ITEM, func);
}
void WxEvtHandler::WxRbEVT_LIST_COL_CLICK(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_COMMAND_LIST_COL_CLICK, func);
}
void WxEvtHandler::WxRbEVT_LIST_COL_RIGHT_CLICK(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_COMMAND_LIST_COL_RIGHT_CLICK, func);
}
void WxEvtHandler::WxRbEVT_LIST_COL_BEGIN_DRAG(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_COMMAND_LIST_COL_BEGIN_DRAG, func);
}
void WxEvtHandler::WxRbEVT_LIST_COL_DRAGGING(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_COMMAND_LIST_COL_DRAGGING, func);
}
void WxEvtHandler::WxRbEVT_LIST_COL_END_DRAG(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_COMMAND_LIST_COL_END_DRAG, func);
}
void WxEvtHandler::WxRbEVT_LIST_ITEM_SELECTED(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_COMMAND_LIST_ITEM_SELECTED, func);
}
void WxEvtHandler::WxRbEVT_LIST_ITEM_DESELECTED(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_COMMAND_LIST_ITEM_DESELECTED, func);
}
void WxEvtHandler::WxRbEVT_LIST_ITEM_RIGHT_CLICK(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_COMMAND_LIST_ITEM_RIGHT_CLICK, func);
}
void WxEvtHandler::WxRbEVT_LIST_ITEM_MIDDLE_CLICK(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_COMMAND_LIST_ITEM_MIDDLE_CLICK, func);
}
void WxEvtHandler::WxRbEVT_LIST_ITEM_ACTIVATED(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_COMMAND_LIST_ITEM_ACTIVATED, func);
}
void WxEvtHandler::WxRbEVT_LIST_ITEM_FOCUSED(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_COMMAND_LIST_ITEM_FOCUSED, func);
}
void WxEvtHandler::WxRbEVT_LIST_CACHE_HINT(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_COMMAND_LIST_CACHE_HINT, func);
}
void WxEvtHandler::WxRbEVT_FIND(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_COMMAND_FIND, func);
}
void WxEvtHandler::WxRbEVT_FIND_NEXT(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_COMMAND_FIND_NEXT, func);
}
void WxEvtHandler::WxRbEVT_FIND_REPLACE(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_COMMAND_FIND_REPLACE, func);
}
void WxEvtHandler::WxRbEVT_FIND_REPLACE_ALL(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_COMMAND_FIND_REPLACE_ALL, func);
}
void WxEvtHandler::WxRbEVT_FIND_CLOSE(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_COMMAND_FIND_CLOSE, func);
}
void WxEvtHandler::WxRbEVT_SOCKET(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_SOCKET, func);
}
void WxEvtHandler::WxRbEVT_TREE_BEGIN_DRAG(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_COMMAND_TREE_BEGIN_DRAG, func);
}
void WxEvtHandler::WxRbEVT_TREE_BEGIN_RDRAG(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_COMMAND_TREE_BEGIN_RDRAG, func);
}
void WxEvtHandler::WxRbEVT_TREE_END_DRAG(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_COMMAND_TREE_END_DRAG, func);
}
void WxEvtHandler::WxRbEVT_TREE_BEGIN_LABEL_EDIT(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_COMMAND_TREE_BEGIN_LABEL_EDIT, func);
}
void WxEvtHandler::WxRbEVT_TREE_END_LABEL_EDIT(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id, INT2NUM(-1), wxEVT_COMMAND_TREE_END_LABEL_EDIT, func);
}
void WxEvtHandler::WxRbEVT_TREE_GET_INFO(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id,INT2NUM(-1),wxEVT_COMMAND_TREE_GET_INFO, func);
}
void WxEvtHandler::WxRbEVT_TREE_SET_INFO(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id,INT2NUM(-1),wxEVT_COMMAND_TREE_SET_INFO, func);
}
void WxEvtHandler::WxRbEVT_TREE_ITEM_EXPANDED(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id,INT2NUM(-1),wxEVT_COMMAND_TREE_ITEM_EXPANDED, func);
}
void WxEvtHandler::WxRbEVT_TREE_ITEM_EXPANDING(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id,INT2NUM(-1),wxEVT_COMMAND_TREE_ITEM_EXPANDING, func);
}
void WxEvtHandler::WxRbEVT_TREE_ITEM_COLLAPSED(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id,INT2NUM(-1),wxEVT_COMMAND_TREE_ITEM_COLLAPSED, func);
}
void WxEvtHandler::WxRbEVT_TREE_ITEM_COLLAPSING(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id,INT2NUM(-1),wxEVT_COMMAND_TREE_ITEM_COLLAPSING, func);
}
void WxEvtHandler::WxRbEVT_TREE_SEL_CHANGED(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id,INT2NUM(-1),wxEVT_COMMAND_TREE_SEL_CHANGED, func);
}
void WxEvtHandler::WxRbEVT_TREE_SEL_CHANGING(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id,INT2NUM(-1),wxEVT_COMMAND_TREE_SEL_CHANGING, func);
}
void WxEvtHandler::WxRbEVT_TREE_KEY_DOWN(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id,INT2NUM(-1),wxEVT_COMMAND_TREE_KEY_DOWN, func);
}
void WxEvtHandler::WxRbEVT_TREE_DELETE_ITEM(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id,INT2NUM(-1),wxEVT_COMMAND_TREE_DELETE_ITEM, func);
}
void WxEvtHandler::WxRbEVT_TREE_ITEM_ACTIVATED(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id,INT2NUM(-1),wxEVT_COMMAND_TREE_ITEM_ACTIVATED, func);
}
void WxEvtHandler::WxRbEVT_TREE_ITEM_RIGHT_CLICK(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id,INT2NUM(-1),wxEVT_COMMAND_TREE_ITEM_RIGHT_CLICK, func);
}
void WxEvtHandler::WxRbEVT_TREE_ITEM_MIDDLE_CLICK(int argc, VALUE* argv, VALUE self) {
	VALUE id = NUM2INT(-1);
	VALUE func = Qnil;
	rb_scan_args(argc, argv, "1&", &id, &func);
    Connect(self, id,INT2NUM(-1),wxEVT_COMMAND_TREE_ITEM_MIDDLE_CLICK, func);
}

VALUE WxEvtHandler::rubyClass;

class ZAutoDefineWxEvtHandler
{
public:
   ZAutoDefineWxEvtHandler()
    {
       WxEvtHandler::DefineClass();
    }
};
static ZAutoDefineWxEvtHandler x;
