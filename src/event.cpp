/**********************************************************************

  event.cpp -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#include "wx.h"
#include "wx/listctrl.h"
#include "wx/spinbutt.h"
#include "wx/fdrepdlg.h"
#include "wx/splitter.h"
#include "event.h"
#include "date.h"
#include "size.h"
#include "point.h"
#include "calendar.h"
#include "notebook.h"
#include "listctrl.h"
#include "socket.h"
#include "treectrl.h"

void WxEvent::DefineClass()
{
	if(rubyClass)
		return;
	rubyClass = rb_define_class_under(GetWxModule(),"Event", rb_cObject);
	rb_define_alloc_func(rubyClass,WxEvent::alloc);
	rb_define_method(rubyClass, "skip", VALUEFUNC(WxEvent::Skip), -1);
	rb_define_method(rubyClass, "get_id", VALUEFUNC(WxEvent::GetId), 0);
	rb_define_method(rubyClass, "get_event_object", VALUEFUNC(WxEvent::GetEventObject), 0);
	rb_define_method(rubyClass, "get_event_type", VALUEFUNC(WxEvent::GetEventType), 0);
}

VALUE
WxEvent::alloc(VALUE self)
{
   return Data_Wrap_Struct(self, 0, 0, 0);
}

void
WxEvent::Skip(int argc, VALUE *argv, VALUE self)
{
    bool skip = TRUE;
    if(argc>0 && argv[0]==Qfalse) skip = FALSE;
    wxEvent *ptr;
    Data_Get_Struct(self, wxEvent, ptr);
    ptr->Skip(skip);
}

VALUE
WxEvent::GetId(VALUE self)
{
    wxEvent *ptr;
    Data_Get_Struct(self, wxEvent, ptr);
    return INT2NUM(ptr->GetId());
}

VALUE
WxEvent::GetEventObject(VALUE self)
{
    wxEvent *ptr;
    Data_Get_Struct(self, wxEvent, ptr);
    wxEvtHandler *object = (wxEvtHandler *)ptr->GetEventObject();
    if(object) {
        void *data = object->GetClientData();
        if(data==NULL)
            return Qnil;
        else
            return rb_hash_aref((VALUE)data, rb_str_new2("self"));
    } else
        return Qnil;
}

VALUE
WxEvent::GetEventType(VALUE self)
{
    wxEvent *ptr;
    Data_Get_Struct(self, wxEvent, ptr);
    return INT2NUM(ptr->GetEventType());
}

VALUE WxEvent::rubyClass;


class ZAutoDefine
{
public:
   ZAutoDefine()
    {
       WxEvent::DefineClass();
    }
};
static ZAutoDefine x1;

//--------------------------------------------------------------------------------

void WxMouseEvent::DefineClass()
{
	if(rubyClass)
		return;
	WxEvent::DefineClass();
	rubyClass = rb_define_class_under(GetWxModule(),"MouseEvent", WxEvent::rubyClass);
	rb_define_alloc_func(rubyClass,alloc);
	rb_define_method(rubyClass, "get_x", VALUEFUNC(WxMouseEvent::GetX), 0);
	rb_define_method(rubyClass, "get_y", VALUEFUNC(WxMouseEvent::GetY), 0);
	rb_define_method(rubyClass, "left_is_down", VALUEFUNC(WxMouseEvent::LeftIsDown), 0);
	rb_define_method(rubyClass, "get_wheel_delta", VALUEFUNC(WxMouseEvent::GetWheelDelta), 0);
	rb_define_method(rubyClass, "get_wheel_rotation", VALUEFUNC(WxMouseEvent::GetWheelRotation), 0);
}

VALUE WxMouseEvent::alloc(VALUE self)
{
	return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE WxMouseEvent::init0(wxMouseEvent event)
{
    static VALUE self = Data_Wrap_Struct(rubyClass, 0, 0, 0);
    DATA_PTR(self) = new wxMouseEvent(event);
    return self;
}

VALUE WxMouseEvent::GetX(VALUE self)
{
    wxMouseEvent *ptr;
    Data_Get_Struct(self, wxMouseEvent, ptr);
    return INT2NUM(ptr->GetX());
}

VALUE WxMouseEvent::GetY(VALUE self)
{
    wxMouseEvent *ptr;
    Data_Get_Struct(self, wxMouseEvent, ptr);
    return INT2NUM(ptr->GetY());
}

VALUE WxMouseEvent::LeftIsDown(VALUE self)
{
    wxMouseEvent *ptr;
    Data_Get_Struct(self, wxMouseEvent, ptr);
	if(ptr->LeftIsDown())
		return Qtrue;
	else
	    return Qfalse;
}

VALUE WxMouseEvent::GetWheelRotation(VALUE self)
{
    wxMouseEvent *ptr;
    Data_Get_Struct(self, wxMouseEvent, ptr);
    return INT2NUM(ptr->GetWheelRotation());
}

VALUE WxMouseEvent::GetWheelDelta(VALUE self)
{
    wxMouseEvent *ptr;
    Data_Get_Struct(self, wxMouseEvent, ptr);
    return INT2NUM(ptr->GetWheelDelta());
}

VALUE WxMouseEvent::rubyClass;

class ZAutoDefineWxMouseEvent
{
public:
   ZAutoDefineWxMouseEvent()
    {
       WxMouseEvent::DefineClass();
    }
};
static ZAutoDefineWxMouseEvent x1WxMouseEvent;


//--------------------------------------------------------------------------------
void WxKeyEvent::DefineClass()
{
	if(rubyClass)
		return;
	WxEvent::DefineClass();
	rubyClass = rb_define_class_under(GetWxModule(),"KeyEvent", WxEvent::rubyClass);
	rb_define_alloc_func(rubyClass,WxKeyEvent::alloc);
	rb_define_method(rubyClass, "get_key_code", VALUEFUNC(WxKeyEvent::GetKeyCode), 0);
	rb_define_method(rubyClass, "key_code", VALUEFUNC(WxKeyEvent::GetKeyCode), 0);
	rb_define_method(rubyClass, "alt_down", VALUEFUNC(WxKeyEvent::AltDown), 0);
	rb_define_method(rubyClass, "control_down", VALUEFUNC(WxKeyEvent::ControlDown), 0);
	rb_define_method(rubyClass, "has_modifiers", VALUEFUNC(WxKeyEvent::HasModifiers), 0);
	rb_define_method(rubyClass, "meta_down", VALUEFUNC(WxKeyEvent::MetaDown), 0);
	rb_define_method(rubyClass, "shift_down", VALUEFUNC(WxKeyEvent::ShiftDown), 0);
}

VALUE
WxKeyEvent::alloc(VALUE self)
{
   return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxKeyEvent::init0(wxKeyEvent event)
{
    static VALUE self = Data_Wrap_Struct(rubyClass, 0, 0, 0);
    DATA_PTR(self) = new wxKeyEvent(event);
    return self;
}

VALUE
WxKeyEvent::GetKeyCode(VALUE self)
{
    wxKeyEvent *ptr;
    Data_Get_Struct(self, wxKeyEvent, ptr);
    return INT2NUM(ptr->GetKeyCode());
}

VALUE
WxKeyEvent::ControlDown(VALUE self)
{
    wxKeyEvent *ptr;
    Data_Get_Struct(self, wxKeyEvent, ptr);
    return (ptr->ControlDown() ? Qtrue : Qfalse);
}

VALUE
WxKeyEvent::MetaDown(VALUE self)
{
    wxKeyEvent *ptr;
    Data_Get_Struct(self, wxKeyEvent, ptr);
    return (ptr->MetaDown() ? Qtrue : Qfalse);
}

VALUE
WxKeyEvent::AltDown(VALUE self)
{
    wxKeyEvent *ptr;
    Data_Get_Struct(self, wxKeyEvent, ptr);
    return (ptr->AltDown() ? Qtrue : Qfalse);
}

VALUE
WxKeyEvent::ShiftDown(VALUE self)
{
    wxKeyEvent *ptr;
    Data_Get_Struct(self, wxKeyEvent, ptr);
    return (ptr->ShiftDown() ? Qtrue : Qfalse);
}

VALUE
WxKeyEvent::HasModifiers(VALUE self)
{
    wxKeyEvent *ptr;
    Data_Get_Struct(self, wxKeyEvent, ptr);
    return (ptr->HasModifiers() ? Qtrue : Qfalse);
}

VALUE WxKeyEvent::rubyClass;


class ZAutoDefineWxKeyEvent
{
public:
   ZAutoDefineWxKeyEvent()
    {
       WxKeyEvent::DefineClass();
    }
};
static ZAutoDefineWxKeyEvent x2;

//--------------------------------------------------------------------------------
void WxCloseEvent::DefineClass()
{
	if(rubyClass)
		return;
	WxEvent::DefineClass();
	rubyClass = rb_define_class_under(GetWxModule(),"CloseEvent", WxEvent::rubyClass);
	rb_define_alloc_func(rubyClass,WxCloseEvent::alloc);
	rb_define_method(rubyClass, "can_veto", VALUEFUNC(WxCloseEvent::CanVeto), 0);
	rb_define_method(rubyClass, "veto", VALUEFUNC(WxCloseEvent::Veto), -1);
}

VALUE
WxCloseEvent::alloc(VALUE self)
{
   return Data_Wrap_Struct(self, 0, 0, 0);
}


VALUE
WxCloseEvent::CanVeto(VALUE self)
{
    wxCloseEvent *ptr;
    Data_Get_Struct(self, wxCloseEvent, ptr);
    return (ptr->CanVeto() ? Qtrue : Qfalse);
}

void
WxCloseEvent::Veto(int argc, VALUE *argv, VALUE self)
{
    bool veto = TRUE;
    if(argc>0 && argv[0]!=Qtrue) veto = FALSE;
    wxCloseEvent *ptr;
    Data_Get_Struct(self, wxCloseEvent, ptr);
    ptr->Veto(veto);

}

VALUE WxCloseEvent::rubyClass;


class ZAutoDefineWxCloseEvent
{
public:
   ZAutoDefineWxCloseEvent()
    {
       WxCloseEvent::DefineClass();
    }
};
static ZAutoDefineWxCloseEvent x3;


//--------------------------------------------------------------------------------
void WxCommandEvent::DefineClass()
{
	if(rubyClass)
		return;
	WxEvent::DefineClass();
	rubyClass = rb_define_class_under(GetWxModule(),"CommandEvent", WxEvent::rubyClass);
	rb_define_alloc_func(rubyClass,WxCommandEvent::alloc);
	rb_define_method(rubyClass, "get_selection", VALUEFUNC(WxCommandEvent::GetSelection), 0);
	rb_define_method(rubyClass, "get_string", VALUEFUNC(WxCommandEvent::GetString), 0);
	rb_define_method(rubyClass, "is_checked", VALUEFUNC(WxCommandEvent::IsChecked), 0);
	rb_define_method(rubyClass, "is_selection", VALUEFUNC(WxCommandEvent::IsSelection), 0);
	rb_define_method(rubyClass, "get_client_data", VALUEFUNC(WxCommandEvent::GetClientData), 0);
	rb_define_method(rubyClass, "get_extra_long", VALUEFUNC(WxCommandEvent::GetExtraLong), 0);
	rb_define_method(rubyClass, "get_int", VALUEFUNC(WxCommandEvent::GetInt), 0);
}

VALUE
WxCommandEvent::alloc(VALUE self)
{
   return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxCommandEvent::GetSelection(VALUE self)
{
    wxCommandEvent *ptr;
    Data_Get_Struct(self, wxCommandEvent, ptr);
    return INT2NUM(ptr->GetSelection());
}

VALUE
WxCommandEvent::GetString(VALUE self)
{
    wxCommandEvent *ptr;
    Data_Get_Struct(self, wxCommandEvent, ptr);
    return rb_str_new2(ptr->GetString());
}

VALUE
WxCommandEvent::IsChecked(VALUE self)
{
    wxCommandEvent *ptr;
    Data_Get_Struct(self, wxCommandEvent, ptr);
    return (ptr->IsChecked() ? Qtrue : Qfalse);
}

VALUE
WxCommandEvent::IsSelection(VALUE self)
{
    wxCommandEvent *ptr;
    Data_Get_Struct(self, wxCommandEvent, ptr);
    return (ptr->IsSelection() ? Qtrue : Qfalse);
}

VALUE
WxCommandEvent::GetClientData(VALUE self)
{
    wxCommandEvent *ptr;
    Data_Get_Struct(self, wxCommandEvent, ptr);
    void *data = ptr->GetClientData();
    if(data==NULL)
        return Qnil;
    else
        return rb_hash_aref((VALUE)data, rb_str_new2("data"));
}

VALUE
WxCommandEvent::GetExtraLong(VALUE self)
{
    wxCommandEvent *ptr;
    Data_Get_Struct(self, wxCommandEvent, ptr);
    return INT2NUM(ptr->GetExtraLong());
}

VALUE
WxCommandEvent::GetInt(VALUE self)
{
    wxCommandEvent *ptr;
    Data_Get_Struct(self, wxCommandEvent, ptr);
    return INT2NUM(ptr->GetInt());
}

VALUE WxCommandEvent::rubyClass;



class ZAutoDefineWxCommandEvent
{
public:
   ZAutoDefineWxCommandEvent()
    {
       WxCommandEvent::DefineClass();
    }
};
static ZAutoDefineWxCommandEvent x4;


//--------------------------------------------------------------------------------
void WxCalendarEvent::DefineClass()
{
	if(rubyClass)
		return;
	WxEvent::DefineClass();
	rubyClass = rb_define_class_under(GetWxModule(),"CalendarEvent", WxEvent::rubyClass);
	rb_define_alloc_func(rubyClass,WxCalendarEvent::alloc);
	rb_define_method(rubyClass, "get_date", VALUEFUNC(WxCalendarEvent::GetDate), 0);
}

VALUE
WxCalendarEvent::alloc(VALUE self)
{
   return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxCalendarEvent::GetDate(VALUE self)
{
    wxCalendarEvent *ptr;
    Data_Get_Struct(self, wxCalendarEvent, ptr);
    return WxDateTime::init0(ptr->GetDate());
}

VALUE WxCalendarEvent::rubyClass;

class ZAutoDefineWxCalendarEvent
{
public:
   ZAutoDefineWxCalendarEvent()
    {
       WxCalendarEvent::DefineClass();
    }
};
static ZAutoDefineWxCalendarEvent x5;


//--------------------------------------------------------------------------------
void WxListEvent::DefineClass()
{
	if(rubyClass)
		return;
	WxNotifyEvent::DefineClass();
	rubyClass = rb_define_class_under(GetWxModule(),"ListEvent", WxNotifyEvent::rubyClass);
	rb_define_alloc_func(rubyClass,WxListEvent::alloc);
	rb_define_method(rubyClass, "get_data", VALUEFUNC(WxListEvent::GetData), 0);
	rb_define_method(rubyClass, "get_cache_from", VALUEFUNC(WxListEvent::GetCacheFrom), 0);
	rb_define_method(rubyClass, "get_column", VALUEFUNC(WxListEvent::GetColumn), 0);
	rb_define_method(rubyClass, "get_index", VALUEFUNC(WxListEvent::GetIndex), 0);
	rb_define_method(rubyClass, "get_key_code", VALUEFUNC(WxListEvent::GetKeyCode), 0);
	rb_define_method(rubyClass, "get_mask", VALUEFUNC(WxListEvent::GetMask), 0);
//    rb_define_method(rubyClass, "cancelled", VALUEFUNC(WxListEvent::Cancelled), 0);
	rb_define_method(rubyClass, "get_image", VALUEFUNC(WxListEvent::GetImage), 0);
	rb_define_method(rubyClass, "get_item", VALUEFUNC(WxListEvent::GetItem), 0);
	rb_define_method(rubyClass, "get_label", VALUEFUNC(WxListEvent::GetLabel), 0);
	rb_define_method(rubyClass, "get_point", VALUEFUNC(WxListEvent::GetPoint), 0);
	rb_define_method(rubyClass, "get_text", VALUEFUNC(WxListEvent::GetText), 0);
	rb_define_method(rubyClass, "get_cache_to", VALUEFUNC(WxListEvent::GetCacheTo), 0);
}

VALUE
WxListEvent::alloc(VALUE self)
{
   return Data_Wrap_Struct(self, 0, 0, 0);
}


VALUE
WxListEvent::GetData(VALUE self)
{
    wxListEvent *ptr;
    Data_Get_Struct(self, wxListEvent, ptr);
    VALUE v = ptr->GetData();
    if (v == Qfalse || v== Qnil) v = INT2NUM(0);
    return (v);
}

VALUE
WxListEvent::GetIndex(VALUE self)
{
    wxListEvent *ptr;
    Data_Get_Struct(self, wxListEvent, ptr);
    return INT2NUM(ptr->GetIndex());
}

VALUE
WxListEvent::GetKeyCode(VALUE self)
{
    wxListEvent *ptr;
    Data_Get_Struct(self, wxListEvent, ptr);
    return INT2NUM(ptr->GetKeyCode());
}

VALUE
WxListEvent::GetCacheFrom(VALUE self)
{
    wxListEvent *ptr;
    Data_Get_Struct(self, wxListEvent, ptr);
    return INT2NUM(ptr->GetCacheFrom());
}

VALUE
WxListEvent::GetColumn(VALUE self)
{
    wxListEvent *ptr;
    Data_Get_Struct(self, wxListEvent, ptr);
    return INT2NUM(ptr->GetColumn());
}

VALUE
WxListEvent::GetMask(VALUE self)
{
    wxListEvent *ptr;
    Data_Get_Struct(self, wxListEvent, ptr);
    return INT2NUM(ptr->GetMask());
}

//VALUE
//WxListEvent::Cancelled(VALUE self)
//{
//    wxListEvent *ptr;
//    Data_Get_Struct(self, wxListEvent, ptr);
//    return (ptr->Cancelled() ? Qtrue : Qfalse);
//}

VALUE
WxListEvent::GetPoint(VALUE self)
{
    wxListEvent *ptr;
    Data_Get_Struct(self, wxListEvent, ptr);
    return WxPoint::init0(ptr->GetPoint());
}

VALUE
WxListEvent::GetLabel(VALUE self)
{
    wxListEvent *ptr;
    Data_Get_Struct(self, wxListEvent, ptr);
    return rb_str_new2(ptr->GetLabel());
}

VALUE
WxListEvent::GetText(VALUE self)
{
    wxListEvent *ptr;
    Data_Get_Struct(self, wxListEvent, ptr);
    return rb_str_new2(ptr->GetText());
}

VALUE
WxListEvent::GetImage(VALUE self)
{
    wxListEvent *ptr;
    Data_Get_Struct(self, wxListEvent, ptr);
    return INT2NUM(ptr->GetImage());
}

VALUE
WxListEvent::GetItem(VALUE self)
{
    wxListEvent *ptr;
    Data_Get_Struct(self, wxListEvent, ptr);
    return WxListItem::init0((wxListItem *)&ptr->GetItem());
}


VALUE
WxListEvent::GetCacheTo(VALUE self)
{
    wxListEvent *ptr;
    Data_Get_Struct(self, wxListEvent, ptr);
    return INT2NUM(ptr->GetCacheTo());
}

VALUE WxListEvent::rubyClass;

class ZAutoDefineWxListEvent
{
public:
   ZAutoDefineWxListEvent()
    {
       WxListEvent::DefineClass();
    }
};
static ZAutoDefineWxListEvent x6;


//--------------------------------------------------------------------------------
void WxUpdateUIEvent::DefineClass()
{
	if(rubyClass)
		return;
	WxCommandEvent::DefineClass();
	rubyClass = rb_define_class_under(GetWxModule(),"UpdateUIEvent", WxCommandEvent::rubyClass);
	rb_define_alloc_func(rubyClass,WxUpdateUIEvent::alloc);
	rb_define_method(rubyClass, "enable", VALUEFUNC(WxUpdateUIEvent::Enable), 1);
}

VALUE
WxUpdateUIEvent::alloc(VALUE self)
{
   return Data_Wrap_Struct(self, 0, 0, 0);
}


void
WxUpdateUIEvent::Enable(VALUE self,VALUE venable)
{
    bool enable = (venable == Qtrue);
    wxUpdateUIEvent *ptr;
    Data_Get_Struct(self, wxUpdateUIEvent, ptr);
    ptr->Enable(enable);
}

VALUE WxUpdateUIEvent::rubyClass;

class ZAutoDefineWxUpdateUIEvent
{
public:
   ZAutoDefineWxUpdateUIEvent()
    {
       WxUpdateUIEvent::DefineClass();
    }
};
static ZAutoDefineWxUpdateUIEvent x7;


//---------------------------------------------------------------------------------
void WxSizeEvent::DefineClass()
{
	if(rubyClass)
		return;
	WxEvent::DefineClass();
	rubyClass = rb_define_class_under(GetWxModule(),"SizeEvent", WxEvent::rubyClass);
	rb_define_alloc_func(rubyClass,WxSizeEvent::alloc);
	rb_define_method(rubyClass, "get_size", VALUEFUNC(WxSizeEvent::GetSize), 0);
}

VALUE
WxSizeEvent::alloc(VALUE self)
{
   return Data_Wrap_Struct(self, 0, 0, 0);
}


VALUE
WxSizeEvent::GetSize(VALUE self)
{
    wxSizeEvent *ptr;
    Data_Get_Struct(self, wxSizeEvent, ptr);
    return WxSize::init0(ptr->GetSize());
}

VALUE WxSizeEvent::rubyClass;

class ZAutoDefineWxSizeEvent
{
public:
   ZAutoDefineWxSizeEvent()
    {
       WxSizeEvent::DefineClass();
    }
};
static ZAutoDefineWxSizeEvent x8;


//---------------------------------------------------------------------------------
void WxMoveEvent::DefineClass()
{
	if(rubyClass)
		return;
	WxEvent::DefineClass();
	rubyClass = rb_define_class_under(GetWxModule(),"MoveEvent", WxEvent::rubyClass);
	rb_define_alloc_func(rubyClass,WxMoveEvent::alloc);
	rb_define_method(rubyClass, "get_position", VALUEFUNC(WxMoveEvent::GetPosition), 0);
}

VALUE
WxMoveEvent::alloc(VALUE self)
{
   return Data_Wrap_Struct(self, 0, 0, 0);
}


VALUE
WxMoveEvent::GetPosition(VALUE self)
{
    wxMoveEvent *ptr;
    Data_Get_Struct(self, wxMoveEvent, ptr);
    return WxPoint::init0(ptr->GetPosition());
}

VALUE WxMoveEvent::rubyClass;

class ZAutoDefineWxMoveEvent
{
public:
   ZAutoDefineWxMoveEvent()
    {
       WxMoveEvent::DefineClass();
    }
};
static ZAutoDefineWxMoveEvent x9;


//---------------------------------------------------------------------------------
void WxSpinEvent::DefineClass()
{
	if(rubyClass)
		return;
	WxNotifyEvent::DefineClass();
	rubyClass = rb_define_class_under(GetWxModule(),"SpinEvent", WxNotifyEvent::rubyClass);
	rb_define_alloc_func(rubyClass,WxSpinEvent::alloc);
	rb_define_method(rubyClass, "get_position", VALUEFUNC(WxSpinEvent::GetPosition), 0);
	rb_define_method(rubyClass, "set_position", VALUEFUNC(WxSpinEvent::SetPosition), 1);
}

VALUE
WxSpinEvent::alloc(VALUE self)
{
   return Data_Wrap_Struct(self, 0, 0, 0);
}


VALUE
WxSpinEvent::GetPosition(VALUE self)
{
    wxSpinEvent *ptr;
    Data_Get_Struct(self, wxSpinEvent, ptr);
    return INT2NUM(ptr->GetPosition());
}

void
WxSpinEvent::SetPosition(VALUE self,VALUE vpos)
{
    int pos = NUM2INT(vpos);
    wxSpinEvent *ptr;
    Data_Get_Struct(self, wxSpinEvent, ptr);
    ptr->SetPosition(pos);
}

VALUE WxSpinEvent::rubyClass;

class ZAutoDefineWxSpinEvent
{
public:
   ZAutoDefineWxSpinEvent()
    {
       WxSpinEvent::DefineClass();
    }
};
static ZAutoDefineWxSpinEvent x10;


//---------------------------------------------------------------------------------
void WxNotifyEvent::DefineClass()
{
	if(rubyClass)
		return;
	WxCommandEvent::DefineClass();
	rubyClass = rb_define_class_under(GetWxModule(),"NotifyEvent", WxCommandEvent::rubyClass);
	rb_define_alloc_func(rubyClass,WxNotifyEvent::alloc);
	rb_define_method(rubyClass, "allow", VALUEFUNC(WxNotifyEvent::Allow), 0);
	rb_define_method(rubyClass, "is_allowed", VALUEFUNC(WxNotifyEvent::IsAllowed), 0);
	rb_define_method(rubyClass, "veto", VALUEFUNC(WxNotifyEvent::Veto), 0);
}

VALUE
WxNotifyEvent::alloc(VALUE self)
{
   return Data_Wrap_Struct(self, 0, 0, 0);
}

void
WxNotifyEvent::Allow(VALUE self)
{
    wxNotifyEvent *ptr;
    Data_Get_Struct(self, wxNotifyEvent, ptr);
    ptr->Allow();
}

VALUE
WxNotifyEvent::IsAllowed(VALUE self)
{
    wxNotifyEvent *ptr;
    Data_Get_Struct(self, wxNotifyEvent, ptr);
    return (ptr->IsAllowed() ? Qtrue : Qfalse);
}

void
WxNotifyEvent::Veto(VALUE self)
{
    wxNotifyEvent *ptr;
    Data_Get_Struct(self, wxNotifyEvent, ptr);
    ptr->Veto();
}

VALUE WxNotifyEvent::rubyClass;

class ZAutoDefineWxNotifyEvent
{
public:
   ZAutoDefineWxNotifyEvent()
    {
       WxNotifyEvent::DefineClass();
    }
};
static ZAutoDefineWxNotifyEvent x11;


//---------------------------------------------------------------------------------
void WxNotebookEvent::DefineClass()
{
	if(rubyClass)
		return;
	WxNotifyEvent::DefineClass();
	rubyClass = rb_define_class_under(GetWxModule(),"NotebookEvent", WxNotifyEvent::rubyClass);
	rb_define_alloc_func(rubyClass,WxNotebookEvent::alloc);
	rb_define_method(rubyClass, "get_selection", VALUEFUNC(WxNotebookEvent::GetSelection), 0);
	rb_define_method(rubyClass, "set_selection", VALUEFUNC(WxNotebookEvent::SetSelection), 1);
	rb_define_method(rubyClass, "get_old_selection", VALUEFUNC(WxNotebookEvent::GetOldSelection), 0);
	rb_define_method(rubyClass, "set_old_selection", VALUEFUNC(WxNotebookEvent::SetOldSelection), 1);
}

VALUE
WxNotebookEvent::alloc(VALUE self)
{
   return Data_Wrap_Struct(self, 0, 0, 0);
}


VALUE
WxNotebookEvent::GetSelection(VALUE self)
{
    wxNotebookEvent *ptr;
    Data_Get_Struct(self, wxNotebookEvent, ptr);
    return INT2NUM(ptr->GetSelection());
}

void
WxNotebookEvent::SetSelection(VALUE self,VALUE vnSel)
{
    int nSel = NUM2INT(vnSel);
    wxNotebookEvent *ptr;
    Data_Get_Struct(self, wxNotebookEvent, ptr);
    ptr->SetSelection(nSel);
}

VALUE
WxNotebookEvent::GetOldSelection(VALUE self)
{
    wxNotebookEvent *ptr;
    Data_Get_Struct(self, wxNotebookEvent, ptr);
    return INT2NUM(ptr->GetOldSelection());
}

void
WxNotebookEvent::SetOldSelection(VALUE self,VALUE vnOldSel)
{
    int nOldSel = NUM2INT(vnOldSel);
    wxNotebookEvent *ptr;
    Data_Get_Struct(self, wxNotebookEvent, ptr);
    ptr->SetOldSelection(nOldSel);
}

VALUE WxNotebookEvent::rubyClass;

class ZAutoDefineWxNotebookEvent
{
public:
   ZAutoDefineWxNotebookEvent()
    {
       WxNotebookEvent::DefineClass();
    }
};
static ZAutoDefineWxNotebookEvent x12;



//---------------------------------------------------------------------------------
void WxPaintEvent::DefineClass()
{
	if(rubyClass)
		return;
	WxEvent::DefineClass();
	rubyClass = rb_define_class_under(GetWxModule(),"PaintEvent", WxEvent::rubyClass);
	rb_define_alloc_func(rubyClass,WxPaintEvent::alloc);
}

VALUE
WxPaintEvent::alloc(VALUE self)
{
   return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE WxPaintEvent::rubyClass;

class ZAutoDefineWxPaintEvent
{
public:
   ZAutoDefineWxPaintEvent()
    {
       WxPaintEvent::DefineClass();
    }
};
static ZAutoDefineWxPaintEvent x13;


//---------------------------------------------------------------------------------
void WxFindDialogEvent::DefineClass()
{
	if(rubyClass)
		return;
	WxCommandEvent::DefineClass();
	rubyClass = rb_define_class_under(GetWxModule(),"FindDialogEvent", WxCommandEvent::rubyClass);
	rb_define_alloc_func(rubyClass,WxFindDialogEvent::alloc);
	rb_define_method(rubyClass, "get_dialog", VALUEFUNC(WxEvent::GetEventObject), 0);
	rb_define_method(rubyClass, "get_find_string", VALUEFUNC(WxFindDialogEvent::GetFindString), 0);
	rb_define_method(rubyClass, "get_flags", VALUEFUNC(WxFindDialogEvent::GetFlags), 0);
	rb_define_method(rubyClass, "get_replace_string", VALUEFUNC(WxFindDialogEvent::GetReplaceString), 0);
	rb_define_method(rubyClass, "set_find_string", VALUEFUNC(WxFindDialogEvent::SetFindString), 1);
	rb_define_method(rubyClass, "set_flags", VALUEFUNC(WxFindDialogEvent::SetFlags), 1);
	rb_define_method(rubyClass, "set_replace_string", VALUEFUNC(WxFindDialogEvent::SetReplaceString), 1);
}

VALUE
WxFindDialogEvent::alloc(VALUE self)
{
   return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxFindDialogEvent::GetFlags(VALUE self)
{
    wxFindDialogEvent *ptr;
    Data_Get_Struct(self, wxFindDialogEvent, ptr);
    return INT2NUM(ptr->GetFlags());
}

VALUE
WxFindDialogEvent::GetFindString(VALUE self)
{
    wxFindDialogEvent *ptr;
    Data_Get_Struct(self, wxFindDialogEvent, ptr);
    return rb_str_new2(ptr->GetFindString());
}

VALUE
WxFindDialogEvent::GetReplaceString(VALUE self)
{
    wxFindDialogEvent *ptr;
    Data_Get_Struct(self, wxFindDialogEvent, ptr);
    return rb_str_new2(ptr->GetReplaceString());
}

VALUE
WxFindDialogEvent::GetDialog(VALUE self)
{
    wxFindDialogEvent *ptr;
    Data_Get_Struct(self, wxFindDialogEvent, ptr);
    return (long)(ptr->GetEventObject());
}

void
WxFindDialogEvent::SetFlags(VALUE self,VALUE vflags)
{
    int flags = NUM2INT(vflags);
    wxFindDialogEvent *ptr;
    Data_Get_Struct(self, wxFindDialogEvent, ptr);
    ptr->SetFlags(flags);
}

void
WxFindDialogEvent::SetFindString(VALUE self,VALUE vstr)
{
    wxString str = StringValuePtr(vstr);
    wxFindDialogEvent *ptr;
    Data_Get_Struct(self, wxFindDialogEvent, ptr);
    ptr->SetFindString(str);
}

void
WxFindDialogEvent::SetReplaceString(VALUE self,VALUE vstr)
{
    wxString str = StringValuePtr(vstr);
    wxFindDialogEvent *ptr;
    Data_Get_Struct(self, wxFindDialogEvent, ptr);
    ptr->SetReplaceString(str);
}

VALUE WxFindDialogEvent::rubyClass;

class ZAutoDefineWxFindDialogEvent
{
public:
   ZAutoDefineWxFindDialogEvent()
    {
       WxFindDialogEvent::DefineClass();
    }
};
static ZAutoDefineWxFindDialogEvent x14;


//---------------------------------------------------------------------------------
void WxSocketEvent::DefineClass()
{
	if(rubyClass)
		return;
	WxEvent::DefineClass();
	rubyClass = rb_define_class_under(GetWxModule(),"SocketEvent", WxEvent::rubyClass);
	rb_define_alloc_func(rubyClass,WxSocketEvent::alloc);
	rb_define_method(rubyClass, "get_client_data", VALUEFUNC(WxSocketEvent::GetClientData), 0);
	rb_define_method(rubyClass, "get_socket", VALUEFUNC(WxSocketEvent::GetSocket), 0);
	rb_define_method(rubyClass, "get_socket_event", VALUEFUNC(WxSocketEvent::GetSocketEvent), 0);
}

VALUE
WxSocketEvent::alloc(VALUE self)
{
   return Data_Wrap_Struct(self, 0, 0, 0);
}


VALUE
WxSocketEvent::GetClientData(VALUE self)
{
    wxSocketEvent *ptr;
    Data_Get_Struct(self, wxSocketEvent, ptr);
    return (VALUE)(ptr->GetClientData());
}


VALUE
WxSocketEvent::GetSocket(VALUE self)
{
    wxSocketEvent *ptr;
    Data_Get_Struct(self, wxSocketEvent, ptr);
    return WxSocketBase::init0(ptr->GetSocket());
}

VALUE
WxSocketEvent::GetSocketEvent(VALUE self)
{
    wxSocketEvent *ptr;
    Data_Get_Struct(self, wxSocketEvent, ptr);
    return INT2NUM(ptr->GetSocketEvent());
}

VALUE WxSocketEvent::rubyClass;

class ZAutoDefineWxSocketEvent
{
public:
   ZAutoDefineWxSocketEvent()
    {
       WxSocketEvent::DefineClass();
    }
};
static ZAutoDefineWxSocketEvent x15;


//---------------------------------------------------------------------------------
void WxSplitterEvent::DefineClass()
{
	if(rubyClass)
		return;
	WxNotifyEvent::DefineClass();
	rubyClass = rb_define_class_under(GetWxModule(),"SplitterEvent", WxNotifyEvent::rubyClass);
	rb_define_alloc_func(rubyClass,WxSplitterEvent::alloc);
	rb_define_method(rubyClass, "get_sash_position", VALUEFUNC(WxSplitterEvent::GetSashPosition), 0);
	rb_define_method(rubyClass, "get_window_being_removed", VALUEFUNC(WxSplitterEvent::GetWindowBeingRemoved), 0);
	rb_define_method(rubyClass, "get_x", VALUEFUNC(WxSplitterEvent::GetX), 0);
	rb_define_method(rubyClass, "get_y", VALUEFUNC(WxSplitterEvent::GetY), 0);
	rb_define_method(rubyClass, "set_sash_position", VALUEFUNC(WxSplitterEvent::SetSashPosition), 1);
}


VALUE
WxSplitterEvent::alloc(VALUE self)
{
   return Data_Wrap_Struct(self, 0, 0, 0);
}

void
WxSplitterEvent::SetSashPosition(VALUE self,VALUE vpos)
{
    int pos = NUM2INT(vpos);
    wxSplitterEvent *ptr;
    Data_Get_Struct(self, wxSplitterEvent, ptr);
    ptr->SetSashPosition(pos);
}

VALUE
WxSplitterEvent::GetSashPosition(VALUE self)
{
    wxSplitterEvent *ptr;
    Data_Get_Struct(self, wxSplitterEvent, ptr);
    return INT2NUM(ptr->GetSashPosition());
}

VALUE
WxSplitterEvent::GetX(VALUE self)
{
    wxSplitterEvent *ptr;
    Data_Get_Struct(self, wxSplitterEvent, ptr);
    return INT2NUM(ptr->GetX());
}

VALUE
WxSplitterEvent::GetY(VALUE self)
{
    wxSplitterEvent *ptr;
    Data_Get_Struct(self, wxSplitterEvent, ptr);
    return INT2NUM(ptr->GetY());
}

VALUE
WxSplitterEvent::GetWindowBeingRemoved(VALUE self)
{
    wxSplitterEvent *ptr;
    Data_Get_Struct(self, wxSplitterEvent, ptr);
    return WxWindow::init0(ptr->GetWindowBeingRemoved());
}

VALUE WxSplitterEvent::rubyClass;

class ZAutoDefineWxSplitterEvent
{
public:
   ZAutoDefineWxSplitterEvent()
    {
       WxSplitterEvent::DefineClass();
    }
};
static ZAutoDefineWxSplitterEvent x16;


//--------------------------------------------------------------------------------
void WxTreeEvent::DefineClass()
{
	if(rubyClass)
		return;
	WxNotifyEvent::DefineClass();
	rubyClass = rb_define_class_under(GetWxModule(),"TreeEvent", WxNotifyEvent::rubyClass);
	rb_define_alloc_func(rubyClass,WxTreeEvent::alloc);
	rb_define_method(rubyClass, "get_key_code", VALUEFUNC(WxTreeEvent::GetKeyCode), 0);
	rb_define_method(rubyClass, "get_key_event", VALUEFUNC(WxTreeEvent::GetKeyEvent), 0);
	rb_define_method(rubyClass, "get_item", VALUEFUNC(WxTreeEvent::GetItem), 0);
	rb_define_method(rubyClass, "get_label", VALUEFUNC(WxTreeEvent::GetLabel), 0);
	rb_define_method(rubyClass, "get_old_item", VALUEFUNC(WxTreeEvent::GetOldItem), 0);
	rb_define_method(rubyClass, "get_point", VALUEFUNC(WxTreeEvent::GetPoint), 0);
	rb_define_method(rubyClass, "is_edit_cancelled", VALUEFUNC(WxTreeEvent::IsEditCancelled), 0);
}

VALUE
WxTreeEvent::alloc(VALUE self)
{
   return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxTreeEvent::GetKeyCode(VALUE self)
{
    wxTreeEvent *ptr;
    Data_Get_Struct(self, wxTreeEvent, ptr);
    return INT2NUM(ptr->GetKeyCode());
}

VALUE
WxTreeEvent::GetKeyEvent(VALUE self)
{
    wxTreeEvent *ptr;
    Data_Get_Struct(self, wxTreeEvent, ptr);
    return WxKeyEvent::init0(ptr->GetKeyEvent());
}

VALUE
WxTreeEvent::GetItem(VALUE self)
{
    wxTreeEvent *ptr;
    Data_Get_Struct(self, wxTreeEvent, ptr);
    return INT2NUM(ptr->GetItem());
}

VALUE
WxTreeEvent::GetLabel(VALUE self)
{
    wxTreeEvent *ptr;
    Data_Get_Struct(self, wxTreeEvent, ptr);
    return rb_str_new2(ptr->GetLabel());
}

VALUE
WxTreeEvent::GetOldItem(VALUE self)
{
    wxTreeEvent *ptr;
    Data_Get_Struct(self, wxTreeEvent, ptr);
    return INT2NUM(ptr->GetOldItem());
}

VALUE
WxTreeEvent::GetPoint(VALUE self)
{
    wxTreeEvent *ptr;
    Data_Get_Struct(self, wxTreeEvent, ptr);
    return WxPoint::init0(ptr->GetPoint());
}

VALUE
WxTreeEvent::IsEditCancelled(VALUE self)
{
    wxTreeEvent *ptr;
    Data_Get_Struct(self, wxTreeEvent, ptr);
    return (ptr->IsEditCancelled() ? Qtrue : Qfalse);
}

VALUE WxTreeEvent::rubyClass;

class ZAutoDefineWxTreeEvent
{
public:
   ZAutoDefineWxTreeEvent()
    {
       WxTreeEvent::DefineClass();
    }
};
static ZAutoDefineWxTreeEvent x17;

//--------------------------------------------------------------------------------

void WxIdleEvent::DefineClass()
{
	if(rubyClass)
		return;
	WxEvent::DefineClass();
	rubyClass = rb_define_class_under(GetWxModule(),"IdleEvent", WxEvent::rubyClass);
	rb_define_alloc_func(rubyClass,alloc);
	rb_define_method(rubyClass, "more_requested", VALUEFUNC(MoreRequested), 0);
	rb_define_method(rubyClass, "request_more", VALUEFUNC(RequestMore), 0);
}

VALUE
WxIdleEvent::alloc(VALUE self)
{
   return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxIdleEvent::MoreRequested(VALUE self)
{
    wxIdleEvent *ptr;
    Data_Get_Struct(self, wxIdleEvent, ptr);
    return INT2NUM(ptr->MoreRequested()) ? Qtrue : Qfalse;
}

VALUE
WxIdleEvent::RequestMore(VALUE self)
{
    wxIdleEvent *ptr;
    Data_Get_Struct(self, wxIdleEvent, ptr);
    ptr->RequestMore(TRUE);
	return Qnil;
}

VALUE WxIdleEvent::rubyClass;

class ZAutoDefineWxIdleEvent
{
public:
   ZAutoDefineWxIdleEvent()
    {
       WxIdleEvent::DefineClass();
    }
};
static ZAutoDefineWxIdleEvent x17WxIdleEvent;
