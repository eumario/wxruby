/**********************************************************************

  evthandler.h -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#ifndef WXRUBY_EVTHANDLER_H
#define WXRUBY_EVTHANDLER_H

class wxRbCallback : public wxObject {
    DECLARE_ABSTRACT_CLASS(wxRbCallback);
public:
    wxRbCallback(VALUE func);
    wxRbCallback(const wxRbCallback &other);

    void EventThunker(wxEvent &event);

    VALUE	m_func;
};

class WxEvtHandler {
public:
	static VALUE eventCallbackArray;

    static VALUE alloc(VALUE self);
    static VALUE init0(wxEvtHandler *handler);
    static void Connect(VALUE argv0,VALUE argv1,VALUE argv2,VALUE argv3,VALUE argv4);
    static void AddPendingEvent(VALUE self,VALUE vevent);
    //static VALUE GetClientData(VALUE self);
    static VALUE GetEvtHandlerEnabled(VALUE self);
    static VALUE GetNextHandler(VALUE self);
    static VALUE GetPreviousHandler(VALUE self);
    static VALUE ProcessEvent(VALUE self,VALUE vevent);
    //static void SetClientData(VALUE self,VALUE vdata);
    static void SetEvtHandlerEnabled(VALUE self,VALUE venabled);
    static void SetNextHandler(VALUE self,VALUE vhandler);
    static void SetPreviousHandler(VALUE self,VALUE vhandler);

    static void WxRbEVT_ACTIVATE(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_ACTIVATE_APP(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_BUTTON(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_CALENDAR(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_CALENDAR_DAY(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_CALENDAR_MONTH(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_CALENDAR_SEL_CHANGED(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_CALENDAR_WEEKDAY_CLICKED(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_CALENDAR_YEAR(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_CHAR(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_CHAR_HOOK(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_CHECKBOX(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_CHECKLISTBOX(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_CHILD_FOCUS(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_CHOICE(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_CLOSE(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_COMBOBOX(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_COMMAND(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_COMMAND_ENTER(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_COMMAND_KILL_FOCUS(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_COMMAND_LEFT_CLICK(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_COMMAND_LEFT_DCLICK(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_COMMAND_RANGE(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_COMMAND_RIGHT_CLICK(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_COMMAND_RIGHT_DCLICK(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_COMMAND_SCROLL(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_COMMAND_SCROLLWIN(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_COMMAND_SCROLLWIN_BOTTOM(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_COMMAND_SCROLLWIN_LINEDOWN(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_COMMAND_SCROLLWIN_LINEUP(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_COMMAND_SCROLLWIN_PAGEDOWN(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_COMMAND_SCROLLWIN_PAGEUP(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_COMMAND_SCROLLWIN_THUMBRELEASE(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_COMMAND_SCROLLWIN_THUMBTRACK(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_COMMAND_SCROLLWIN_TOP(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_COMMAND_SCROLL_BOTTOM(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_COMMAND_SCROLL_LINEDOWN(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_COMMAND_SCROLL_LINEUP(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_COMMAND_SCROLL_PAGEDOWN(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_COMMAND_SCROLL_PAGEUP(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_COMMAND_SCROLL_THUMBRELEASE(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_COMMAND_SCROLL_THUMBTRACK(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_COMMAND_SCROLL_TOP(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_COMMAND_SET_FOCUS(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_CONTEXT_MENU(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_DETAILED_HELP(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_DETAILED_HELP_RANGE(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_DROP_FILES(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_END_PROCESS(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_END_SESSION(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_ENTER_WINDOW(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_ERASE_BACKGROUND(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_HELP(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_HELP_RANGE(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_ICONIZE(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_IDLE(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_INIT_DIALOG(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_JOYSTICK_EVENTS(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_JOY_DOWN(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_JOY_MOVE(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_JOY_UP(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_JOY_ZMOVE(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_KEY_DOWN(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_KEY_UP(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_KILL_FOCUS(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_LEAVE_WINDOW(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_LEFT_DCLICK(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_LEFT_DOWN(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_LEFT_UP(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_LISTBOX(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_LISTBOX_DCLICK(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_MAXIMIZE(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_MENU(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_MENU_HIGHLIGHT(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_MENU_HIGHLIGHT_ALL(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_MENU_RANGE(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_MIDDLE_DCLICK(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_MIDDLE_DOWN(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_MIDDLE_UP(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_MOTION(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_MOUSEWHEEL(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_MOUSE_EVENTS(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_MOVE(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_NAVIGATION_KEY(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_NOTEBOOK_PAGE_CHANGED(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_NOTEBOOK_PAGE_CHANGING(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_PAINT(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_PALETTE_CHANGED(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_QUERY_END_SESSION(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_QUERY_NEW_PALETTE(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_RADIOBOX(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_RADIOBUTTON(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_RIGHT_DCLICK(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_RIGHT_DOWN(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_RIGHT_UP(int argc, VALUE* argv, VALUE self);
#if wxUSE_SASH
    static void WxRbEVT_SASH_DRAGGED(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_SASH_DRAGGED_RANGE(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_QUERY_LAYOUT_INFO(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_CALCULATE_LAYOUT(int argc, VALUE* argv, VALUE self);
#endif
    static void WxRbEVT_SCROLL(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_SCROLLWIN(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_SCROLLWIN_BOTTOM(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_SCROLLWIN_LINEDOWN(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_SCROLLWIN_LINEUP(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_SCROLLWIN_PAGEDOWN(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_SCROLLWIN_PAGEUP(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_SCROLLWIN_THUMBRELEASE(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_SCROLLWIN_THUMBTRACK(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_SCROLLWIN_TOP(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_SCROLL_BOTTOM(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_SCROLL_LINEDOWN(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_SCROLL_LINEUP(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_SCROLL_PAGEDOWN(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_SCROLL_PAGEUP(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_SCROLL_THUMBRELEASE(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_SCROLL_THUMBTRACK(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_SCROLL_TOP(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_SET_FOCUS(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_SHOW(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_SIZE(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_SLIDER(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_SPIN(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_SPINCTRL(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_SPIN_DOWN(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_SPIN_UP(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_SPLITTER_DOUBLECLICKED(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_SPLITTER_SASH_POS_CHANGED(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_SPLITTER_SASH_POS_CHANGING(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_SPLITTER_UNSPLIT(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_SYS_COLOUR_CHANGED(int argc, VALUE* argv, VALUE self);
#ifdef __WXMSW__
    static void WxRbEVT_TASKBAR_LEFT_DCLICK(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_TASKBAR_LEFT_DOWN(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_TASKBAR_LEFT_UP(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_TASKBAR_MOVE(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_TASKBAR_RIGHT_DCLICK(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_TASKBAR_RIGHT_DOWN(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_TASKBAR_RIGHT_UP(int argc, VALUE* argv, VALUE self);
#endif
    static void WxRbEVT_TEXT(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_TEXT_ENTER(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_TEXT_MAXLEN(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_TEXT_URL(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_TIMER(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_TOGGLEBUTTON(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_TOOL(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_TOOL_ENTER(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_TOOL_RANGE(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_TOOL_RCLICKED(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_TOOL_RCLICKED_RANGE(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_UPDATE_UI(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_UPDATE_UI_RANGE(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_VLBOX(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_WINDOW_CREATE(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_WINDOW_DESTROY(int argc, VALUE* argv, VALUE self);

    static void WxRbEVT_LIST_BEGIN_DRAG(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_LIST_BEGIN_LABEL_EDIT(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_LIST_BEGIN_RDRAG(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_LIST_CACHE_HINT(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_LIST_COL_BEGIN_DRAG(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_LIST_COL_CLICK(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_LIST_COL_DRAGGING(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_LIST_COL_END_DRAG(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_LIST_COL_RIGHT_CLICK(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_LIST_DELETE_ALL_ITEMS(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_LIST_DELETE_ITEM(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_LIST_END_LABEL_EDIT(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_LIST_GET_INFO(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_LIST_INSERT_ITEM(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_LIST_ITEM_ACTIVATED(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_LIST_ITEM_DESELECTED(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_LIST_ITEM_FOCUSED(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_LIST_ITEM_MIDDLE_CLICK(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_LIST_ITEM_RIGHT_CLICK(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_LIST_ITEM_SELECTED(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_LIST_KEY_DOWN(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_LIST_SET_INFO(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_FIND(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_FIND_NEXT(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_FIND_REPLACE(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_FIND_REPLACE_ALL(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_FIND_CLOSE(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_SOCKET(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_TREE_BEGIN_DRAG(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_TREE_BEGIN_LABEL_EDIT(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_TREE_BEGIN_RDRAG(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_TREE_DELETE_ITEM(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_TREE_END_DRAG(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_TREE_END_LABEL_EDIT(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_TREE_GET_INFO(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_TREE_ITEM_ACTIVATED(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_TREE_ITEM_COLLAPSED(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_TREE_ITEM_COLLAPSING(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_TREE_ITEM_EXPANDED(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_TREE_ITEM_EXPANDING(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_TREE_ITEM_MIDDLE_CLICK(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_TREE_ITEM_RIGHT_CLICK(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_TREE_KEY_DOWN(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_TREE_SEL_CHANGED(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_TREE_SEL_CHANGING(int argc, VALUE* argv, VALUE self);
    static void WxRbEVT_TREE_SET_INFO(int argc, VALUE* argv, VALUE self);
    
    static void WxRbEVT_GRID_CELL_LEFT_CLICK( int argc, VALUE* argv, VALUE self );
	static void WxRbEVT_GRID_CELL_LEFT_DCLICK( int argc, VALUE* argv, VALUE self );
	static void WxRbEVT_GRID_CELL_RIGHT_CLICK( int argc, VALUE* argv, VALUE self );
	static void WxRbEVT_GRID_CELL_RIGHT_DCLICK( int argc, VALUE* argv, VALUE self );
	static void WxRbEVT_GRID_LABEL_LEFT_CLICK( int argc, VALUE* argv, VALUE self );
	static void WxRbEVT_GRID_LABEL_LEFT_DCLICK( int argc, VALUE* argv, VALUE self );
	static void WxRbEVT_GRID_LABEL_RIGHT_CLICK( int argc, VALUE* argv, VALUE self );
	static void WxRbEVT_GRID_LABEL_RIGHT_DCLICK( int argc, VALUE* argv, VALUE self );
	static void WxRbEVT_GRID_CELL_CHANGE( int argc, VALUE* argv, VALUE self );
	static void WxRbEVT_GRID_SELECT_CELL( int argc, VALUE* argv, VALUE self );
	static void WxRbEVT_GRID_EDITOR_HIDDEN( int argc, VALUE* argv, VALUE self );
	static void WxRbEVT_GRID_EDITOR_SHOWN( int argc, VALUE* argv, VALUE self );
	static void WxRbEVT_GRID_ROW_SIZE( int argc, VALUE* argv, VALUE self );
	static void WxRbEVT_GRID_COL_SIZE( int argc, VALUE* argv, VALUE self );
	static void WxRbEVT_GRID_RANGE_SELECT( int argc, VALUE* argv, VALUE self );
	static void WxRbEVT_GRID_EDITOR_CREATED( int argc, VALUE* argv, VALUE self );


    
   
    static void DefineClass();
	static VALUE rubyClass;
};

#endif
