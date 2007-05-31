#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license
%include "common.i"

%module(directors="1") wxEvents;

%{
//NO_CLASS - This tells fixmodule not to expect a class

#include <wx/calctrl.h>
#include <wx/choicebk.h>
#include <wx/fdrepdlg.h>
#include <wx/notebook.h>
#include <wx/listbook.h>
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
#include <wx/aui/aui.h>

#ifdef WXSCINTILLA
#    include <wx/wxscintilla.h>
#endif
%}


%constant const int wxEVT_NULL;// 0)
%constant const int wxEVT_COMMAND_BUTTON_CLICKED;// 1)
%constant const int wxEVT_COMMAND_CHECKBOX_CLICKED;// 2)
%constant const int wxEVT_COMMAND_CHOICE_SELECTED;// 3)
%constant const int wxEVT_COMMAND_LISTBOX_SELECTED;// 4)
%constant const int wxEVT_COMMAND_LISTBOX_DOUBLECLICKED;// 5)
%constant const int wxEVT_COMMAND_CHECKLISTBOX_TOGGLED;// 6)
%constant const int wxEVT_COMMAND_TEXT_UPDATED;// 7)
%constant const int wxEVT_COMMAND_TEXT_ENTER;// 8)
%constant const int wxEVT_COMMAND_TEXT_URL;// 13)
%constant const int wxEVT_COMMAND_TEXT_MAXLEN;// 14)
%constant const int wxEVT_COMMAND_MENU_SELECTED;// 9)
%constant const int wxEVT_COMMAND_SLIDER_UPDATED;// 10)
%constant const int wxEVT_COMMAND_RADIOBOX_SELECTED;// 11)
%constant const int wxEVT_COMMAND_RADIOBUTTON_SELECTED;// 12)
%constant const int wxEVT_COMMAND_SCROLLBAR_UPDATED;// 13)
%constant const int wxEVT_COMMAND_VLBOX_SELECTED;// 14)
%constant const int wxEVT_COMMAND_COMBOBOX_SELECTED;// 15)
%constant const int wxEVT_COMMAND_TOOL_RCLICKED;// 16)
%constant const int wxEVT_COMMAND_TOOL_ENTER;// 17)
%constant const int wxEVT_COMMAND_SPINCTRL_UPDATED;// 18)
%constant const int wxEVT_SOCKET;// 50)
%constant const int wxEVT_TIMER ;// 80)
%constant const int wxEVT_LEFT_DOWN;// 100)
%constant const int wxEVT_LEFT_UP;// 101)
%constant const int wxEVT_MIDDLE_DOWN;// 102)
%constant const int wxEVT_MIDDLE_UP;// 103)
%constant const int wxEVT_RIGHT_DOWN;// 104)
%constant const int wxEVT_RIGHT_UP;// 105)
%constant const int wxEVT_MOTION;// 106)
%constant const int wxEVT_ENTER_WINDOW;// 107)
%constant const int wxEVT_LEAVE_WINDOW;// 108)
%constant const int wxEVT_LEFT_DCLICK;// 109)
%constant const int wxEVT_MIDDLE_DCLICK;// 110)
%constant const int wxEVT_RIGHT_DCLICK;// 111)
%constant const int wxEVT_SET_FOCUS;// 112)
%constant const int wxEVT_KILL_FOCUS;// 113)
%constant const int wxEVT_CHILD_FOCUS;// 114)
%constant const int wxEVT_MOUSEWHEEL;// 115)
%constant const int wxEVT_NC_LEFT_DOWN;// 200)
%constant const int wxEVT_NC_LEFT_UP;// 201)
%constant const int wxEVT_NC_MIDDLE_DOWN;// 202)
%constant const int wxEVT_NC_MIDDLE_UP;// 203)
%constant const int wxEVT_NC_RIGHT_DOWN;// 204)
%constant const int wxEVT_NC_RIGHT_UP;// 205)
%constant const int wxEVT_NC_MOTION;// 206)
%constant const int wxEVT_NC_ENTER_WINDOW;// 207)
%constant const int wxEVT_NC_LEAVE_WINDOW;// 208)
%constant const int wxEVT_NC_LEFT_DCLICK;// 209)
%constant const int wxEVT_NC_MIDDLE_DCLICK;// 210)
%constant const int wxEVT_NC_RIGHT_DCLICK;// 211)
%constant const int wxEVT_CHAR;// 212)
%constant const int wxEVT_CHAR_HOOK;// 213)
%constant const int wxEVT_NAVIGATION_KEY;// 214)
%constant const int wxEVT_KEY_DOWN;// 215)
%constant const int wxEVT_KEY_UP;// 216)
%constant const int wxEVT_SET_CURSOR;// 230)
%constant const int wxEVT_SCROLL_TOP;// 300)
%constant const int wxEVT_SCROLL_BOTTOM;// 301)
%constant const int wxEVT_SCROLL_LINEUP;// 302)
%constant const int wxEVT_SCROLL_LINEDOWN;// 303)
%constant const int wxEVT_SCROLL_PAGEUP;// 304)
%constant const int wxEVT_SCROLL_PAGEDOWN;// 305)
%constant const int wxEVT_SCROLL_THUMBTRACK;// 306)
%constant const int wxEVT_SCROLL_THUMBRELEASE;// 307)
%constant const int wxEVT_SCROLL_ENDSCROLL;// 308)
%constant const int wxEVT_SCROLLWIN_TOP;// 320)
%constant const int wxEVT_SCROLLWIN_BOTTOM;// 321)
%constant const int wxEVT_SCROLLWIN_LINEUP;// 322)
%constant const int wxEVT_SCROLLWIN_LINEDOWN;// 323)
%constant const int wxEVT_SCROLLWIN_PAGEUP;// 324)
%constant const int wxEVT_SCROLLWIN_PAGEDOWN;// 325)
%constant const int wxEVT_SCROLLWIN_THUMBTRACK;// 326)
%constant const int wxEVT_SCROLLWIN_THUMBRELEASE;// 327)
%constant const int wxEVT_SIZE;// 400)
%constant const int wxEVT_MOVE;// 401)
%constant const int wxEVT_CLOSE_WINDOW;// 402)
%constant const int wxEVT_END_SESSION;// 403)
%constant const int wxEVT_QUERY_END_SESSION;// 404)
%constant const int wxEVT_ACTIVATE_APP;// 405)
#ifdef wxHAS_POWER_EVENTS  // currently Win32 only
%constant const int wxEVT_POWER_SUSPENDING;// 406)
%constant const int wxEVT_POWER_SUSPENDED;// 407)
#endif
%constant const int wxEVT_ACTIVATE;// 409)
%constant const int wxEVT_CREATE;// 410)
%constant const int wxEVT_DESTROY;// 411)
%constant const int wxEVT_SHOW;// 412)
%constant const int wxEVT_ICONIZE;// 413)
%constant const int wxEVT_MAXIMIZE;// 414)
%constant const int wxEVT_MOUSE_CAPTURE_CHANGED;// 415)
%constant const int wxEVT_PAINT;// 416)
%constant const int wxEVT_ERASE_BACKGROUND;// 417)
%constant const int wxEVT_NC_PAINT;// 418)
%constant const int wxEVT_PAINT_ICON;// 419)
%constant const int wxEVT_MENU_OPEN;// 420)
%constant const int wxEVT_MENU_CLOSE;// 421)
%constant const int wxEVT_MENU_HIGHLIGHT;// 422)
// %constant const int wxEVT_POPUP_MENU_INIT;// 423) -- free slot
%constant const int wxEVT_CONTEXT_MENU;// 424)
%constant const int wxEVT_SYS_COLOUR_CHANGED;// 425)
%constant const int wxEVT_DISPLAY_CHANGED;// 426)
%constant const int wxEVT_SETTING_CHANGED;// 427)
%constant const int wxEVT_QUERY_NEW_PALETTE;// 428)
%constant const int wxEVT_PALETTE_CHANGED;// 429)
%constant const int wxEVT_JOY_BUTTON_DOWN;// 430)
%constant const int wxEVT_JOY_BUTTON_UP;// 431)
%constant const int wxEVT_JOY_MOVE;// 432)
%constant const int wxEVT_JOY_ZMOVE;// 433)
%constant const int wxEVT_DROP_FILES;// 434)
%constant const int wxEVT_DRAW_ITEM;// 435)
%constant const int wxEVT_MEASURE_ITEM;// 436)
%constant const int wxEVT_COMPARE_ITEM;// 437)
%constant const int wxEVT_INIT_DIALOG;// 438)
%constant const int wxEVT_IDLE;// 439)
%constant const int wxEVT_UPDATE_UI;// 440)
%constant const int wxEVT_COMMAND_LEFT_CLICK;// 500)
%constant const int wxEVT_COMMAND_LEFT_DCLICK;// 501)
%constant const int wxEVT_COMMAND_RIGHT_CLICK;// 502)
%constant const int wxEVT_COMMAND_RIGHT_DCLICK;// 503)
%constant const int wxEVT_COMMAND_SET_FOCUS;// 504)
%constant const int wxEVT_COMMAND_KILL_FOCUS;// 505)
%constant const int wxEVT_COMMAND_ENTER;// 506)
%constant const int wxEVT_COMMAND_FIND;// 510)
%constant const int wxEVT_COMMAND_FIND_NEXT;// 511)
%constant const int wxEVT_COMMAND_FIND_REPLACE;// 512)
%constant const int wxEVT_COMMAND_FIND_REPLACE_ALL;// 513)
%constant const int wxEVT_COMMAND_FIND_CLOSE;// 514)            


%constant const int wxEVT_SCROLL_TOP; //300)
%constant const int wxEVT_SCROLL_BOTTOM; //301)
%constant const int wxEVT_SCROLL_LINEUP; //302)
%constant const int wxEVT_SCROLL_LINEDOWN; //303)
%constant const int wxEVT_SCROLL_PAGEUP; //304)
%constant const int wxEVT_SCROLL_PAGEDOWN; //305)
%constant const int wxEVT_SCROLL_THUMBTRACK; //306)
%constant const int wxEVT_SCROLL_THUMBRELEASE; //307)
%constant const int wxEVT_SCROLL_CHANGED; //308)

%constant const int wxEVT_SCROLLWIN_TOP; //320)
%constant const int wxEVT_SCROLLWIN_BOTTOM; //321)
%constant const int wxEVT_SCROLLWIN_LINEUP; //322)
%constant const int wxEVT_SCROLLWIN_LINEDOWN; //323)
%constant const int wxEVT_SCROLLWIN_PAGEUP; //324)
%constant const int wxEVT_SCROLLWIN_PAGEDOWN; //325)
%constant const int wxEVT_SCROLLWIN_THUMBTRACK; //326)
%constant const int wxEVT_SCROLLWIN_THUMBRELEASE; //327)
        
%constant const int wxEVT_HELP;// 1050)
%constant const int wxEVT_DETAILED_HELP;// 1051)

%constant const int wxEVT_COMMAND_TREE_BEGIN_DRAG;
%constant const int wxEVT_COMMAND_TREE_BEGIN_RDRAG;
%constant const int wxEVT_COMMAND_TREE_END_DRAG;
%constant const int wxEVT_COMMAND_TREE_BEGIN_LABEL_EDIT;
%constant const int wxEVT_COMMAND_TREE_END_LABEL_EDIT;
%constant const int wxEVT_COMMAND_TREE_GET_INFO;
%constant const int wxEVT_COMMAND_TREE_SET_INFO;
%constant const int wxEVT_COMMAND_TREE_ITEM_EXPANDED;
%constant const int wxEVT_COMMAND_TREE_ITEM_EXPANDING;
%constant const int wxEVT_COMMAND_TREE_ITEM_COLLAPSED;
%constant const int wxEVT_COMMAND_TREE_ITEM_COLLAPSING;
%constant const int wxEVT_COMMAND_TREE_SEL_CHANGED;
%constant const int wxEVT_COMMAND_TREE_SEL_CHANGING;
%constant const int wxEVT_COMMAND_TREE_KEY_DOWN;
%constant const int wxEVT_COMMAND_TREE_DELETE_ITEM;
%constant const int wxEVT_COMMAND_TREE_ITEM_ACTIVATED;

%constant const int wxEVT_COMMAND_TREE_ITEM_MENU;
%constant const int wxEVT_COMMAND_TREE_ITEM_RIGHT_CLICK;
%constant const int wxEVT_COMMAND_TREE_ITEM_MIDDLE_CLICK;
%constant const int wxEVT_COMMAND_TREE_STATE_IMAGE_CLICK;
%constant const int wxEVT_COMMAND_TREE_ITEM_GETTOOLTIP;

%constant const int wxEVT_GRID_CELL_LEFT_CLICK; //1580)
%constant const int wxEVT_GRID_CELL_RIGHT_CLICK; //1581)
%constant const int wxEVT_GRID_CELL_LEFT_DCLICK; //1582)
%constant const int wxEVT_GRID_CELL_RIGHT_DCLICK; //1583)
%constant const int wxEVT_GRID_LABEL_LEFT_CLICK; //1584)
%constant const int wxEVT_GRID_LABEL_RIGHT_CLICK; //1585)
%constant const int wxEVT_GRID_LABEL_LEFT_DCLICK; //1586)
%constant const int wxEVT_GRID_LABEL_RIGHT_DCLICK; //1587)
%constant const int wxEVT_GRID_ROW_SIZE; //1588)
%constant const int wxEVT_GRID_COL_SIZE; //1589)
%constant const int wxEVT_GRID_RANGE_SELECT; //1590)
%constant const int wxEVT_GRID_CELL_CHANGE; //1591)
%constant const int wxEVT_GRID_SELECT_CELL; //1592)
%constant const int wxEVT_GRID_EDITOR_SHOWN; //1593)
%constant const int wxEVT_GRID_EDITOR_HIDDEN; //1594)
%constant const int wxEVT_GRID_EDITOR_CREATED; //1595)
%constant const int wxEVT_GRID_CELL_BEGIN_DRAG; //1596)

%constant const int wxEVT_CALENDAR_SEL_CHANGED;//, 950)
%constant const int wxEVT_CALENDAR_DAY_CHANGED;//, 951)
%constant const int wxEVT_CALENDAR_MONTH_CHANGED;//, 952)
%constant const int wxEVT_CALENDAR_YEAR_CHANGED;//, 953)
%constant const int wxEVT_CALENDAR_DOUBLECLICKED;//, 954)
%constant const int wxEVT_CALENDAR_WEEKDAY_CLICKED;//, 955)

%constant const int wxEVT_COMMAND_CHOICEBOOK_PAGE_CHANGING;
%constant const int wxEVT_COMMAND_CHOICEBOOK_PAGE_CHANGED;
%constant const int wxEVT_COMMAND_LISTBOOK_PAGE_CHANGING;
%constant const int wxEVT_COMMAND_LISTBOOK_PAGE_CHANGED;
%constant const int wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGING;
%constant const int wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED;

%constant const int wxEVT_WIZARD_PAGE_CHANGED; //900)
%constant const int wxEVT_WIZARD_PAGE_CHANGING; //901)
%constant const int wxEVT_WIZARD_CANCEL; //902)
%constant const int wxEVT_WIZARD_HELP; //903)
%constant const int wxEVT_WIZARD_FINISHED; //903)

%constant const int wxEVT_SASH_DRAGGED;

%constant const int wxEVT_AUI_PANE_BUTTON;
%constant const int wxEVT_AUI_PANE_CLOSE;
%constant const int wxEVT_AUI_PANE_MAXIMIZE;
%constant const int wxEVT_AUI_PANE_RESTORE;
%constant const int wxEVT_AUI_RENDER;
%constant const int wxEVT_AUI_FIND_MANAGER;

%constant const int wxEVT_COMMAND_AUINOTEBOOK_PAGE_CLOSE;
%constant const int wxEVT_COMMAND_AUINOTEBOOK_PAGE_CHANGED;
%constant const int wxEVT_COMMAND_AUINOTEBOOK_PAGE_CHANGING;
%constant const int wxEVT_COMMAND_AUINOTEBOOK_BUTTON;
%constant const int wxEVT_COMMAND_AUINOTEBOOK_BEGIN_DRAG;
%constant const int wxEVT_COMMAND_AUINOTEBOOK_END_DRAG;
%constant const int wxEVT_COMMAND_AUINOTEBOOK_DRAG_MOTION;
%constant const int wxEVT_COMMAND_AUINOTEBOOK_ALLOW_DND;

#############################################################################
#### NOTE: Before adding anything below this line, consider whether it really
#### belongs in swig/classes/include/events.rb instead!!!
#############################################################################



%{
extern swig_class cWxEvtHandler;

void internal_connect(VALUE self, int firstId, int lastId, 
                wxEventType eventType);


static VALUE internal_evt_with_id(int argc, VALUE *argv, VALUE self, 
        wxEventType eventType) 
{
	puts("Called internal_evt_with_id in Events");        
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
	puts("Called in Events");        
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
