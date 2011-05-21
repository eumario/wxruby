// Copyright 2004-2009, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxEvent
GC_MANAGE_AS_EVENT(wxEvent);

// To allow instance variables to be attached to custom subclasses of
// Wx::Event written in Ruby in a GC-safe, thread-safe way, wrap a
// custom C++ subclass of wxEvent as Ruby's Wx::Event.
// 
// Note that this subclass only applies to Event objects created on the
// Ruby side - for the large majority of normal event handling, objects
// are created C++ side then given a shallow, transient wrapper for
// their use in Ruby - see wxRuby_WrapWxEventInRuby in swig/wx.i.
%rename(wxEvent) wxRubyEvent;

%header %{
#include <wx/event.h>
%}

// Custom subclass implementation. Provide a constructor, destructor and
// clone functions to allow proper linking to a Ruby object.
%{
class wxRubyEvent : public wxEvent
{
  public:
  wxRubyEvent(wxEventType commandType = wxEVT_NULL, 
              int id = 0,
              int prop_level = wxEVENT_PROPAGATE_NONE) : 
    wxEvent(id, commandType) {  m_propagationLevel = prop_level; }

  // When the C++ side event is destroyed, unlink from the Ruby object
  // and remove that object from the tracking hash so it can be
  // collected by GC.
  virtual ~wxRubyEvent() {
    wxRuby_RemoveTracking( (void*)this );
  }

  // Will be called when add_pending_event is used to queue an event
  // (often when using Threads), because a clone is queued. So copy the
  // Wx C++ event, create a shallow (dup) of the Ruby event object, and
  // add to the tracking hash so that it is GC-protected
  virtual wxEvent* Clone() const {
    wxRubyEvent* wx_ev = new wxRubyEvent( GetEventType(),
                                          GetId(),
                                          m_propagationLevel );

    VALUE r_obj = SWIG_RubyInstanceFor((void *)this);
    VALUE r_obj_dup = rb_obj_clone(r_obj);

    DATA_PTR(r_obj_dup) = wx_ev;
    wxRuby_AddTracking( (void*)wx_ev, r_obj_dup );
    return wx_ev;
  }
};
%}

%extend wxRubyEvent {
  // This class method provides a guaranteed-unique event id that can be
  // used for custom event types.
  static VALUE new_event_type()
  {
	int event_type_id = (int)wxNewEventType();
	return INT2NUM(event_type_id );
  }
}

%import "include/wxObject.h"

// Definition of the class to be parsed by SWIG
class wxRubyEvent : public wxEvent
{
public:
  wxRubyEvent(wxEventType commandType = wxEVT_NULL, 
              int id = 0,
              int propagation_level = wxEVENT_PROPAGATE_NONE);
  virtual wxEvent* Clone() const;
  virtual ~wxRubyEvent();
  wxObject* GetEventObject() ;
  WXTYPE GetEventType() ;
  int GetId() ;
  bool GetSkipped() ;
  long GetTimestamp() ;
  void SetEventObject(wxObject*  object ) ;
  void SetEventType(WXTYPE  typ ) ;
  void SetId(int  id ) ;
  void SetTimestamp(long  timeStamp ) ;
  void Skip(bool skip = true) ;

  bool IsCommandEvent() const ;
  bool ShouldPropagate() const ;
  int StopPropagation() ;
  void ResumePropagation(int propagationLevel) ;
};



// The rest of the file just provides the large number of standard
// EVT_xxx constants for identifying event types in core Wx.


// These includes are all required so that the wx EVT_XXX constants 
// are all loaded
%{

#include <wx/calctrl.h>
#include <wx/datectrl.h>
#include <wx/choicebk.h>
#include <wx/collpane.h>
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
// Workaround for wx's auibar.h incompatibility 2.8.10 with OS X compiler
// Should be fixed by future wxWidgets 
#ifdef __WXMAC__
#define id toolid
#endif
#include <wx/aui/aui.h>

#include <wx/treebook.h>
#include <wx/toolbook.h>
#include <wx/hyperlink.h>
#include <wx/srchctrl.h>
#include <wx/mediactrl.h>
#include <wx/html/htmlwin.h>
#include <wx/richtext/richtextctrl.h>

#ifdef WXSCINTILLA
#    include <wx/wxscintilla.h>
#endif

%}

enum Propagation_state
{
    // don't propagate it at all
    wxEVENT_PROPAGATE_NONE = 0,

    // propagate it until it is processed
    wxEVENT_PROPAGATE_MAX = INT_MAX
};

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
%constant const int wxEVT_COMMAND_TOOL_CLICKED; // = wxEVT_COMMAND_MENU_SELECTED
%constant const int wxEVT_COMMAND_SLIDER_UPDATED;// 10)
%constant const int wxEVT_COMMAND_RADIOBOX_SELECTED;// 11)
%constant const int wxEVT_COMMAND_RADIOBUTTON_SELECTED;// 12)
%constant const int wxEVT_COMMAND_SCROLLBAR_UPDATED;// 13)
%constant const int wxEVT_COMMAND_VLBOX_SELECTED;// 14)
%constant const int wxEVT_COMMAND_COMBOBOX_SELECTED;// 15)
%constant const int wxEVT_COMMAND_TOOL_RCLICKED;// 16)
%constant const int wxEVT_COMMAND_TOOL_ENTER;// 17)
%constant const int wxEVT_COMMAND_SPINCTRL_UPDATED;// 18)
%constant const int wxEVT_COMMAND_TOGGLEBUTTON_CLICKED; // 19
%constant const int wxEVT_COMMAND_COLLPANE_CHANGED; // 1102

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
%constant const int wxEVT_SIZING; // Not exposed?
%constant const int wxEVT_MOVE;// 401)
%constant const int wxEVT_MOVING; // Not exposed?

%constant const int wxEVT_CLOSE_WINDOW;// 402)
%constant const int wxEVT_END_SESSION;// 403)
%constant const int wxEVT_QUERY_END_SESSION;// 404)
%constant const int wxEVT_ACTIVATE_APP;// 405)

%constant const int wxEVT_HIBERNATE; // 443
#ifdef wxHAS_POWER_EVENTS  // currently Win32 only
%constant const int wxEVT_POWER_SUSPENDING;// 406)
%constant const int wxEVT_POWER_SUSPENDED;// 407)
#endif

#if wxUSE_DIALUP_MANAGER // currently Win32 only
%constant const int wxEVT_DIALUP_CONNECTED; // 450
%constant const int wxEVT_DIALUP_DISCONNECTED; // 451
#endif 

#if wxUSE_TAB_DIALOG
%constant const int wxEVT_COMMAND_TAB_SEL_CHANGED; // 800
%constant const int wxEVT_COMMAND_TAB_SEL_CHANGED; // 801
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
%constant const int wxEVT_END_PROCESS; // 440

// Clipboard events
%constant const int wxEVT_COMMAND_TEXT_COPY; // 444
%constant const int wxEVT_COMMAND_TEXT_CUT; // 445 
%constant const int wxEVT_COMMAND_TEXT_PASTE; // 446

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

%constant const int wxEVT_TASKBAR_MOVE; //1550)
%constant const int wxEVT_TASKBAR_LEFT_DOWN; //1551)
%constant const int wxEVT_TASKBAR_LEFT_UP; //1552)
%constant const int wxEVT_TASKBAR_RIGHT_DOWN; //1553)
%constant const int wxEVT_TASKBAR_RIGHT_UP; //1554)
%constant const int wxEVT_TASKBAR_LEFT_DCLICK; //1555)
%constant const int wxEVT_TASKBAR_RIGHT_DCLICK; //1556)
        
%constant const int wxEVT_HELP;// 1050)
%constant const int wxEVT_DETAILED_HELP;// 1051)

%constant const int wxEVT_COMMAND_LIST_BEGIN_DRAG;
%constant const int wxEVT_COMMAND_LIST_BEGIN_RDRAG;
%constant const int wxEVT_COMMAND_LIST_BEGIN_LABEL_EDIT;
%constant const int wxEVT_COMMAND_LIST_END_LABEL_EDIT;
%constant const int wxEVT_COMMAND_LIST_DELETE_ITEM;
%constant const int wxEVT_COMMAND_LIST_DELETE_ALL_ITEMS;
%constant const int wxEVT_COMMAND_LIST_KEY_DOWN;
%constant const int wxEVT_COMMAND_LIST_INSERT_ITEM;
%constant const int wxEVT_COMMAND_LIST_COL_CLICK;
%constant const int wxEVT_COMMAND_LIST_COL_RIGHT_CLICK;
%constant const int wxEVT_COMMAND_LIST_COL_BEGIN_DRAG;
%constant const int wxEVT_COMMAND_LIST_COL_DRAGGING;
%constant const int wxEVT_COMMAND_LIST_COL_END_DRAG;
%constant const int wxEVT_COMMAND_LIST_ITEM_SELECTED;
%constant const int wxEVT_COMMAND_LIST_ITEM_DESELECTED;
%constant const int wxEVT_COMMAND_LIST_ITEM_RIGHT_CLICK;
%constant const int wxEVT_COMMAND_LIST_ITEM_MIDDLE_CLICK;
%constant const int wxEVT_COMMAND_LIST_ITEM_ACTIVATED;
%constant const int wxEVT_COMMAND_LIST_ITEM_FOCUSED;
%constant const int wxEVT_COMMAND_LIST_CACHE_HINT;

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
%constant const int wxEVT_DATE_CHANGED;

%constant const int wxEVT_COMMAND_BOOKCTRL_PAGE_CHANGING;
%constant const int wxEVT_COMMAND_BOOKCTRL_PAGE_CHANGED;
%constant const int wxEVT_COMMAND_CHOICEBOOK_PAGE_CHANGING;
%constant const int wxEVT_COMMAND_CHOICEBOOK_PAGE_CHANGED;
%constant const int wxEVT_COMMAND_LISTBOOK_PAGE_CHANGING;
%constant const int wxEVT_COMMAND_LISTBOOK_PAGE_CHANGED;
%constant const int wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGING;
%constant const int wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED;
%constant const int wxEVT_COMMAND_TOOLBOOK_PAGE_CHANGING;
%constant const int wxEVT_COMMAND_TOOLBOOK_PAGE_CHANGED;
%constant const int wxEVT_COMMAND_TREEBOOK_PAGE_CHANGING;
%constant const int wxEVT_COMMAND_TREEBOOK_PAGE_CHANGED;
%constant const int wxEVT_COMMAND_TREEBOOK_NODE_COLLAPSED;
%constant const int wxEVT_COMMAND_TREEBOOK_NODE_EXPANDED;

%constant const int wxEVT_COMMAND_HYPERLINK; // 3700 

%constant const int wxEVT_WIZARD_PAGE_CHANGED; //900)
%constant const int wxEVT_WIZARD_PAGE_CHANGING; //901)
%constant const int wxEVT_WIZARD_CANCEL; //902)
%constant const int wxEVT_WIZARD_HELP; //903)
%constant const int wxEVT_WIZARD_FINISHED; //903)

%constant const int wxEVT_SASH_DRAGGED;
%constant const int wxEVT_COMMAND_SPLITTER_SASH_POS_CHANGED; // 850
%constant const int wxEVT_COMMAND_SPLITTER_SASH_POS_CHANGING; // 851
%constant const int wxEVT_COMMAND_SPLITTER_DOUBLECLICKED; // 852
%constant const int wxEVT_COMMAND_SPLITTER_UNSPLIT; // 853

%constant const int wxEVT_QUERY_LAYOUT_INFO; // 1500
%constant const int wxEVT_CALCULATE_LAYOUT; // 1501

%constant const int wxEVT_AUI_PANE_BUTTON;
%constant const int wxEVT_AUI_PANE_CLOSE;
%constant const int wxEVT_AUI_PANE_MAXIMIZE;
%constant const int wxEVT_AUI_PANE_RESTORE;
%constant const int wxEVT_AUI_RENDER;
%constant const int wxEVT_AUI_FIND_MANAGER;

%constant const int wxEVT_COMMAND_HTML_CELL_CLICKED;
%constant const int wxEVT_COMMAND_HTML_CELL_HOVER;
%constant const int wxEVT_COMMAND_HTML_LINK_CLICKED;

%constant const int wxEVT_COMMAND_AUINOTEBOOK_PAGE_CLOSE;
%constant const int wxEVT_COMMAND_AUINOTEBOOK_PAGE_CLOSED;
%constant const int wxEVT_COMMAND_AUINOTEBOOK_PAGE_CHANGED;
%constant const int wxEVT_COMMAND_AUINOTEBOOK_PAGE_CHANGING;
%constant const int wxEVT_COMMAND_AUINOTEBOOK_BUTTON;
%constant const int wxEVT_COMMAND_AUINOTEBOOK_BEGIN_DRAG;
%constant const int wxEVT_COMMAND_AUINOTEBOOK_END_DRAG;
%constant const int wxEVT_COMMAND_AUINOTEBOOK_DRAG_MOTION;
%constant const int wxEVT_COMMAND_AUINOTEBOOK_ALLOW_DND;
%constant const int wxEVT_COMMAND_AUINOTEBOOK_DRAG_DONE;
%constant const int wxEVT_COMMAND_AUINOTEBOOK_BG_DCLICK;
%constant const int wxEVT_COMMAND_AUINOTEBOOK_TAB_MIDDLE_DOWN;
%constant const int wxEVT_COMMAND_AUINOTEBOOK_TAB_MIDDLE_UP;
%constant const int wxEVT_COMMAND_AUINOTEBOOK_TAB_RIGHT_DOWN;
%constant const int wxEVT_COMMAND_AUINOTEBOOK_TAB_RIGHT_UP;

%constant const int wxEVT_COMMAND_SEARCHCTRL_SEARCH_BTN;
%constant const int wxEVT_COMMAND_SEARCHCTRL_CANCEL_BTN;

%constant const int wxEVT_COMMAND_RICHTEXT_LEFT_CLICK;
%constant const int wxEVT_COMMAND_RICHTEXT_RIGHT_CLICK;
%constant const int wxEVT_COMMAND_RICHTEXT_MIDDLE_CLICK;
%constant const int wxEVT_COMMAND_RICHTEXT_LEFT_DCLICK;
%constant const int wxEVT_COMMAND_RICHTEXT_RETURN;
%constant const int wxEVT_COMMAND_RICHTEXT_CHARACTER;
%constant const int wxEVT_COMMAND_RICHTEXT_DELETE;

%constant const int wxEVT_COMMAND_RICHTEXT_STYLESHEET_CHANGING;
%constant const int wxEVT_COMMAND_RICHTEXT_STYLESHEET_CHANGED;
%constant const int wxEVT_COMMAND_RICHTEXT_STYLESHEET_REPLACING;
%constant const int wxEVT_COMMAND_RICHTEXT_STYLESHEET_REPLACED;

%constant const int wxEVT_COMMAND_RICHTEXT_CONTENT_INSERTED;
%constant const int wxEVT_COMMAND_RICHTEXT_CONTENT_DELETED;
%constant const int wxEVT_COMMAND_RICHTEXT_STYLE_CHANGED;
%constant const int wxEVT_COMMAND_RICHTEXT_SELECTION_CHANGED;
