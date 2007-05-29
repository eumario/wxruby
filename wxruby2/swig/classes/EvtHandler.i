// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%{
#include <wx/calctrl.h>
#include <wx/choicebk.h>
#include <wx/fdrepdlg.h>
#include <wx/listbook.h>
#include <wx/notebook.h>
#include <wx/grid.h>
#include <wx/spinbutt.h>
#include <wx/treectrl.h>
#include <wx/splitter.h>
#include <wx/listctrl.h>
#include <wx/sashwin.h>
#include <wx/wizard.h>
#include <wx/aui/aui.h>
#ifdef WXSCINTILLA
#    include <wx/wxscintilla.h>
#endif
%}

%module(directors="1") wxEvtHandler
GC_MANAGE_AS_OBJECT(wxEvtHandler);

%ignore wxEvtHandler::Connect;
%ignore wxEvtHandler::Disconnect;

%import "include/wxObject.h"

%include "include/wxEvtHandler.h"


%{
static VALUE callbacks = Qnil;
extern swig_class cWxEvent;
extern swig_class cWxCalendarEvent;
extern swig_class cWxCloseEvent;
extern swig_class cWxCommandEvent;
extern swig_class cWxTextUrlEvent;
extern swig_class cWxIdleEvent;
extern swig_class cWxPaintEvent;
extern swig_class cWxUpdateUIEvent;
extern swig_class cWxSizeEvent;
extern swig_class cWxTimerEvent;
extern swig_class cWxKeyEvent; 
extern swig_class cWxFindDialogEvent;
extern swig_class cWxMouseEvent;
extern swig_class cWxFocusEvent;
extern swig_class cWxSpinEvent;
extern swig_class cWxChoicebookEvent;
extern swig_class cWxNotebookEvent;
extern swig_class cWxListbookEvent;
extern swig_class cWxGridEvent;
extern swig_class cWxGridRangeSelectEvent;
extern swig_class cWxGridSizeEvent;
extern swig_class cWxGridEditorCreatedEvent;
extern swig_class cWxTreeEvent;
extern swig_class cWxSplitterEvent;
extern swig_class cWxScrollEvent;
extern swig_class cWxScrollWinEvent;
extern swig_class cWxMoveEvent;
extern swig_class cWxListEvent;
extern swig_class cWxWizardEvent;
extern swig_class cWxSashEvent;
extern swig_class cWxActivateEvent;
extern swig_class cWxWindowCreateEvent;
extern swig_class cWxWindowDestroyEvent;
extern swig_class cWxMenuEvent;
extern swig_class cWxContextMenuEvent;
extern swig_class cWxAuiManagerEvent;
extern swig_class cWxAuiNotebookEvent;
#ifdef WXSCINTILLA
extern swig_class cWxScintillaEvent;
#endif

static const wxEventType *calendarEvents[] =
{
    &wxEVT_CALENDAR_SEL_CHANGED,
    &wxEVT_CALENDAR_DAY_CHANGED,
    &wxEVT_CALENDAR_MONTH_CHANGED,
    &wxEVT_CALENDAR_YEAR_CHANGED,
    &wxEVT_CALENDAR_DOUBLECLICKED,
    &wxEVT_CALENDAR_WEEKDAY_CLICKED,
    (const wxEventType *)0
};

static const wxEventType *closeEvents[] =
{
    &wxEVT_CLOSE_WINDOW,
    (const wxEventType *)0
};

static const wxEventType *commandEvents[] = 
{
    &wxEVT_COMMAND_BUTTON_CLICKED,
    &wxEVT_COMMAND_CHECKBOX_CLICKED,
    &wxEVT_COMMAND_CHOICE_SELECTED,
    &wxEVT_COMMAND_LISTBOX_SELECTED,
    &wxEVT_COMMAND_LISTBOX_DOUBLECLICKED,
    &wxEVT_COMMAND_CHECKLISTBOX_TOGGLED,
    &wxEVT_COMMAND_TEXT_UPDATED,
    &wxEVT_COMMAND_TEXT_ENTER,
    &wxEVT_COMMAND_TEXT_MAXLEN,
    &wxEVT_COMMAND_MENU_SELECTED,
    &wxEVT_COMMAND_SLIDER_UPDATED,
    &wxEVT_COMMAND_RADIOBOX_SELECTED,
    &wxEVT_COMMAND_RADIOBUTTON_SELECTED,
    &wxEVT_COMMAND_SCROLLBAR_UPDATED,
    &wxEVT_COMMAND_VLBOX_SELECTED,
    &wxEVT_COMMAND_COMBOBOX_SELECTED,
    &wxEVT_COMMAND_TOOL_RCLICKED,
    &wxEVT_COMMAND_TOOL_ENTER,
    &wxEVT_COMMAND_SPINCTRL_UPDATED,
    &wxEVT_COMMAND_COMBOBOX_SELECTED,
    (const wxEventType *)0
};

static const wxEventType *textUrlEvents[] =
{
    &wxEVT_COMMAND_TEXT_URL,
    (const wxEventType *)0
};

static const wxEventType *idleEvents[] =
{
    &wxEVT_IDLE,
    (const wxEventType *)0
};

static const wxEventType *paintEvents[] = 
{
    &wxEVT_PAINT,
    (const wxEventType *)0
};

static const wxEventType *updateUIEvents[] =
{  
    &wxEVT_UPDATE_UI,
    (const wxEventType *)0
};

static const wxEventType *sizeEvents[] = 
{
    &wxEVT_SIZE,
    (const wxEventType *)0
};

static const wxEventType *timerEvents[] = 
{
    &wxEVT_TIMER,
    (const wxEventType *)0
};

static const wxEventType *keyEvents [] = 
{
    &wxEVT_CHAR,
    &wxEVT_CHAR_HOOK,
    &wxEVT_KEY_DOWN,
    &wxEVT_KEY_UP,
    (const wxEventType *)0
};

static const wxEventType *findEvents [] = 
{
    &wxEVT_COMMAND_FIND,
    &wxEVT_COMMAND_FIND_NEXT,
    &wxEVT_COMMAND_FIND_REPLACE,
    &wxEVT_COMMAND_FIND_REPLACE_ALL,
    &wxEVT_COMMAND_FIND_CLOSE,
    (const wxEventType *)0
};

static const wxEventType *focusEvents [] =
{
    &wxEVT_SET_FOCUS,
    &wxEVT_KILL_FOCUS,
    (const wxEventType *)0
};    

static const wxEventType *mouseEvents[] = 
{
    &wxEVT_LEFT_DOWN,
    &wxEVT_LEFT_UP,
    &wxEVT_LEFT_DCLICK,
    &wxEVT_MIDDLE_DOWN,
    &wxEVT_MIDDLE_UP,
    &wxEVT_MIDDLE_DCLICK,
    &wxEVT_RIGHT_DOWN,
    &wxEVT_RIGHT_UP,
    &wxEVT_RIGHT_DCLICK,
    &wxEVT_MOTION,
    &wxEVT_ENTER_WINDOW,
    &wxEVT_LEAVE_WINDOW,
    &wxEVT_MOUSEWHEEL,
    (const wxEventType *)0
};

static const wxEventType *spinEvents[] = 
{
    &wxEVT_SCROLL_THUMBTRACK,
    &wxEVT_SCROLL_LINEUP,
    &wxEVT_SCROLL_LINEDOWN,
    (const wxEventType *)0
};

static const wxEventType *choicebookEvents[] = 
{
     &wxEVT_COMMAND_CHOICEBOOK_PAGE_CHANGED,
     &wxEVT_COMMAND_CHOICEBOOK_PAGE_CHANGING,
     (const wxEventType *)0
};

static const wxEventType *notebookEvents[] = 
{
     &wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGED,
     &wxEVT_COMMAND_NOTEBOOK_PAGE_CHANGING,
     (const wxEventType *)0
};

static const wxEventType *listbookEvents[] = 
{
     &wxEVT_COMMAND_LISTBOOK_PAGE_CHANGED,
     &wxEVT_COMMAND_LISTBOOK_PAGE_CHANGING,
     (const wxEventType *)0
};

static const wxEventType *gridEvents[] = 
{
     &wxEVT_GRID_CELL_LEFT_CLICK,
     &wxEVT_GRID_CELL_RIGHT_CLICK,
     &wxEVT_GRID_CELL_LEFT_DCLICK,
     &wxEVT_GRID_CELL_RIGHT_DCLICK,
     &wxEVT_GRID_LABEL_LEFT_CLICK,
     &wxEVT_GRID_LABEL_RIGHT_CLICK,
     &wxEVT_GRID_LABEL_LEFT_DCLICK,
     &wxEVT_GRID_LABEL_RIGHT_DCLICK,
     &wxEVT_GRID_CELL_CHANGE,
     &wxEVT_GRID_SELECT_CELL,
     &wxEVT_GRID_EDITOR_HIDDEN,
     &wxEVT_GRID_EDITOR_SHOWN,
     (const wxEventType *)0
};

static const wxEventType *gridRangeEvents[] =
{
		&wxEVT_GRID_RANGE_SELECT,
		(const wxEventType *)0
};

static const wxEventType *gridSizeEvents[] =
{
     &wxEVT_GRID_COL_SIZE,
     &wxEVT_GRID_ROW_SIZE,
     (const wxEventType *)0
};

static const wxEventType *gridEditorEvent[] =
{
     &wxEVT_GRID_EDITOR_CREATED,
     (const wxEventType *)0
};

static const wxEventType *wizardEvents[] =
{
    &wxEVT_WIZARD_PAGE_CHANGED,
    &wxEVT_WIZARD_PAGE_CHANGING,
    &wxEVT_WIZARD_CANCEL,
    &wxEVT_WIZARD_HELP,
    &wxEVT_WIZARD_FINISHED,
    (const wxEventType *)0
};

static const wxEventType *sashEvents[] =
{
    &wxEVT_SASH_DRAGGED,
    (const wxEventType *)0
};

static const wxEventType *scrollEvents[] =
{
  &wxEVT_SCROLL_TOP,
  &wxEVT_SCROLL_BOTTOM,
  &wxEVT_SCROLL_LINEUP,
  &wxEVT_SCROLL_LINEDOWN,
  &wxEVT_SCROLL_PAGEUP,
  &wxEVT_SCROLL_PAGEDOWN,
  &wxEVT_SCROLL_THUMBTRACK,
  &wxEVT_SCROLL_THUMBRELEASE,
  &wxEVT_SCROLL_CHANGED,
  (const wxEventType *)0
};


static const wxEventType *scrollWinEvents[] =
{
  &wxEVT_SCROLLWIN_TOP,
  &wxEVT_SCROLLWIN_BOTTOM,
  &wxEVT_SCROLLWIN_LINEUP,
  &wxEVT_SCROLLWIN_LINEDOWN,
  &wxEVT_SCROLLWIN_PAGEUP,
  &wxEVT_SCROLLWIN_PAGEDOWN,
  &wxEVT_SCROLLWIN_THUMBTRACK,
  &wxEVT_SCROLLWIN_THUMBRELEASE,
  (const wxEventType *)0
};

static const wxEventType *activateEvents[] =
{
  &wxEVT_ACTIVATE,
  &wxEVT_ACTIVATE_APP,
  (const wxEventType *)0
};

static const wxEventType *createEvents[] =
{
  &wxEVT_CREATE,
  (const wxEventType *)0
};

static const wxEventType *destroyEvents[] =
{
  &wxEVT_DESTROY,
  (const wxEventType *)0
};

static const wxEventType *menuEvents[] =
{
  &wxEVT_MENU_OPEN,
  &wxEVT_MENU_CLOSE,
  &wxEVT_MENU_HIGHLIGHT,
  (const wxEventType *)0
};

static const wxEventType *contextMenuEvents[] =
{
  &wxEVT_CONTEXT_MENU,
  (const wxEventType *)0
};

static const wxEventType *auiManagerEvents[] =
{
  &wxEVT_AUI_PANE_BUTTON,
  &wxEVT_AUI_PANE_CLOSE,
  &wxEVT_AUI_PANE_MAXIMIZE,
  &wxEVT_AUI_PANE_RESTORE,
  &wxEVT_AUI_RENDER,
  &wxEVT_AUI_FIND_MANAGER,
  (const wxEventType *)0
};

static const wxEventType *auiNotebookEvents[] =
{
  &wxEVT_COMMAND_AUINOTEBOOK_PAGE_CLOSE,
  &wxEVT_COMMAND_AUINOTEBOOK_PAGE_CHANGED,
  &wxEVT_COMMAND_AUINOTEBOOK_PAGE_CHANGING,
  &wxEVT_COMMAND_AUINOTEBOOK_BUTTON,
  &wxEVT_COMMAND_AUINOTEBOOK_BEGIN_DRAG,
  &wxEVT_COMMAND_AUINOTEBOOK_END_DRAG,
  &wxEVT_COMMAND_AUINOTEBOOK_DRAG_MOTION,
  &wxEVT_COMMAND_AUINOTEBOOK_ALLOW_DND,
  (const wxEventType *)0
};

#ifdef WXSCINTILLA
static const wxEventType *scintillaEvents[] =
{
     &wxEVT_SCI_CHANGE,
     &wxEVT_SCI_STYLENEEDED,
     &wxEVT_SCI_CHARADDED,
     &wxEVT_SCI_SAVEPOINTREACHED,
     &wxEVT_SCI_SAVEPOINTLEFT,
     &wxEVT_SCI_ROMODIFYATTEMPT,
     &wxEVT_SCI_KEY,
     &wxEVT_SCI_DOUBLECLICK,
     &wxEVT_SCI_UPDATEUI,
     &wxEVT_SCI_MODIFIED,
     &wxEVT_SCI_MACRORECORD,
     &wxEVT_SCI_MARGINCLICK,
     &wxEVT_SCI_NEEDSHOWN,
     &wxEVT_SCI_PAINTED,
     &wxEVT_SCI_USERLISTSELECTION,
     &wxEVT_SCI_URIDROPPED,
     &wxEVT_SCI_DWELLSTART,
     &wxEVT_SCI_DWELLEND,
     &wxEVT_SCI_START_DRAG,
     &wxEVT_SCI_DRAG_OVER,
     &wxEVT_SCI_DO_DROP,
     &wxEVT_SCI_ZOOM,
     &wxEVT_SCI_HOTSPOT_CLICK,
     &wxEVT_SCI_HOTSPOT_DCLICK,
     &wxEVT_SCI_CALLTIP_CLICK,
     (const wxEventType *)0
};
#endif

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
        if(event.IsKindOf(CLASSINFO(wxCalendarEvent)))
            cEvent = cWxCalendarEvent.klass;
        else if (event.IsKindOf(CLASSINFO(wxChoicebookEvent)))
            cEvent = cWxChoicebookEvent.klass;			
        else if (event.IsKindOf(CLASSINFO(wxListbookEvent)))
            cEvent = cWxListbookEvent.klass;  
        else if (event.IsKindOf(CLASSINFO(wxNotebookEvent)))
            cEvent = cWxNotebookEvent.klass;
       else if(event.IsKindOf(CLASSINFO(wxUpdateUIEvent)))
            cEvent = cWxUpdateUIEvent.klass;
        else if(event.IsKindOf(CLASSINFO(wxSizeEvent)))
            cEvent = cWxSizeEvent.klass;
        else if(event.IsKindOf(CLASSINFO(wxKeyEvent)))
            cEvent = cWxKeyEvent.klass;
        else if(event.IsKindOf(CLASSINFO(wxFindDialogEvent)))
            cEvent = cWxFindDialogEvent.klass;            
        else if(event.IsKindOf(CLASSINFO(wxFocusEvent)))
            cEvent = cWxFocusEvent.klass;
        else if(event.IsKindOf(CLASSINFO(wxMouseEvent)))
            cEvent = cWxMouseEvent.klass;            
        else if(event.IsKindOf(CLASSINFO(wxSpinEvent)))
            cEvent = cWxSpinEvent.klass;
        else if(event.IsKindOf(CLASSINFO(wxCloseEvent)))
            cEvent = cWxCloseEvent.klass;
        else if(event.IsKindOf(CLASSINFO(wxIdleEvent)))
            cEvent = cWxIdleEvent.klass;
        else if(event.IsKindOf(CLASSINFO(wxPaintEvent)))
            cEvent = cWxPaintEvent.klass;
        else if(event.IsKindOf(CLASSINFO(wxTimerEvent)))
            cEvent = cWxTimerEvent.klass;
		else if (event.IsKindOf(CLASSINFO(wxTreeEvent)))
			cEvent = cWxTreeEvent.klass;
		else if (event.IsKindOf(CLASSINFO(wxGridEvent)))
			cEvent = cWxGridEvent.klass;
		else if (event.IsKindOf(CLASSINFO(wxGridRangeSelectEvent)))
			cEvent = cWxGridRangeSelectEvent.klass;
		else if (event.IsKindOf(CLASSINFO(wxGridSizeEvent)))
			cEvent = cWxGridSizeEvent.klass;
		else if (event.IsKindOf(CLASSINFO(wxGridEditorCreatedEvent)))
			cEvent = cWxGridEditorCreatedEvent.klass;			
		else if (event.IsKindOf(CLASSINFO(wxSplitterEvent)))
			cEvent = cWxSplitterEvent.klass;
		else if (event.IsKindOf(CLASSINFO(wxMoveEvent)))
			cEvent = cWxMoveEvent.klass;
        else if(event.IsKindOf(CLASSINFO(wxListEvent)))
            cEvent = cWxListEvent.klass;
        else if(event.IsKindOf(CLASSINFO(wxScrollEvent)))
            cEvent = cWxScrollEvent.klass;
        else if(event.IsKindOf(CLASSINFO(wxScrollWinEvent)))
            cEvent = cWxScrollWinEvent.klass;
        else if(event.IsKindOf(CLASSINFO(wxWizardEvent)))
            cEvent = cWxWizardEvent.klass;
        else if(event.IsKindOf(CLASSINFO(wxActivateEvent)))
            cEvent = cWxActivateEvent.klass;
        else if(event.IsKindOf(CLASSINFO(wxWindowCreateEvent)))
            cEvent = cWxWindowCreateEvent.klass;
        else if(event.IsKindOf(CLASSINFO(wxWindowDestroyEvent)))
            cEvent = cWxWindowDestroyEvent.klass;
        else if(event.IsKindOf(CLASSINFO(wxMenuEvent)))
            cEvent = cWxMenuEvent.klass;
        else if(event.IsKindOf(CLASSINFO(wxContextMenuEvent)))
            cEvent = cWxContextMenuEvent.klass;
        else if(event.IsKindOf(CLASSINFO(wxSashEvent)))
            cEvent = cWxSashEvent.klass;
        else if(event.IsKindOf(CLASSINFO(wxTextUrlEvent)))
            cEvent = cWxTextUrlEvent.klass;
        else if(event.IsKindOf(CLASSINFO(wxAuiManagerEvent)))
            cEvent = cWxAuiManagerEvent.klass;
        else if(event.IsKindOf(CLASSINFO(wxAuiNotebookEvent)))
            cEvent = cWxAuiNotebookEvent.klass;

#ifdef WXSCINTILLA
        else if (event.IsKindOf(CLASSINFO(wxScintillaEvent)))
            cEvent = cWxScintillaEvent.klass;
#endif
        else if(event.IsKindOf(CLASSINFO(wxCommandEvent)))
            cEvent = cWxCommandEvent.klass;
 
        else
        {
            cEvent = cWxEvent.klass;
        }
            
        static VALUE vevent;
        vevent = Data_Wrap_Struct(cEvent, 0, 0, 0);
        DATA_PTR(vevent) = &event;
        
        wxRbCallback *cb = (wxRbCallback *)event.m_callbackUserData;
        rb_funcall(cb->m_func, rb_intern("call"),1,vevent);
    }
    
    bool IsEventInMap(int type, const wxEventType *map[])
    {
        for(int i=0; map[i] != NULL; ++i)
            if(type == *map[i])
                return true;
        return false;
    }
    
                                                                                
    VALUE       m_func;
};


void internal_connect(VALUE self, int firstId, int lastId, 
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

%}

%init %{
extern void Init_wxRubyEventTypes();

Init_wxRubyEventTypes();
%}


// The EvtHandler instance event methods (evt_xxx) are not defined
// here. Instead, they are defined by Events.cpp, generated from
// swig/Event.i and modified by swig/fixevents.rb
