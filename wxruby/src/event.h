/**********************************************************************

  event.h -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/

#ifndef WXRUBY_EVENT_H
#define WXRUBY_EVENT_H

class WxEvent {
public:
    static VALUE alloc(VALUE self);
    static void Skip(int argc, VALUE *argv, VALUE self);
    static VALUE GetId(VALUE self);
    static VALUE GetEventObject(VALUE self);
    static VALUE GetEventType(VALUE self);

    static void DefineClass();
	
	static VALUE rubyClass;
};

class WxMouseEvent {
public:
    static VALUE alloc(VALUE self);
    static VALUE init0(wxMouseEvent event);

	static VALUE GetX(VALUE self);
	static VALUE GetY(VALUE self);
	static VALUE LeftIsDown(VALUE self);
	static VALUE LeftDown(VALUE self);
	static VALUE ShiftDown(VALUE self);
	static VALUE MetaDown(VALUE self);
	static VALUE ControlDown(VALUE self);
	static VALUE AltDown(VALUE self);

	static VALUE GetWheelRotation(VALUE self);
	static VALUE GetWheelDelta(VALUE self);
	
    static void DefineClass();
	static VALUE rubyClass;
};

class WxKeyEvent {
public:
    static VALUE alloc(VALUE self);
    static VALUE init0(wxKeyEvent event);
    static VALUE GetKeyCode(VALUE self);
    static VALUE AltDown(VALUE self);
    static VALUE ControlDown(VALUE self);
    static VALUE HasModifiers(VALUE self);
    static VALUE MetaDown(VALUE self);
    static VALUE ShiftDown(VALUE self);

    static void DefineClass();
	static VALUE rubyClass;
};



class WxCloseEvent {
public:
    static VALUE alloc(VALUE self);
    static VALUE CanVeto(VALUE self);
    static void Veto(int argc, VALUE *argv, VALUE self);

    static void DefineClass();
	static VALUE rubyClass;
};


class WxCommandEvent {
public:
    static VALUE alloc(VALUE self);
    static VALUE GetSelection(VALUE self);
    static VALUE GetString(VALUE self);
    static VALUE IsChecked(VALUE self);
    static VALUE IsSelection(VALUE self);
    //static VALUE GetClientData(VALUE self);
    static VALUE GetExtraLong(VALUE self);
    static VALUE GetInt(VALUE self);

    static void DefineClass();
	static VALUE rubyClass;
};

class WxSizeEvent {
public:
    static VALUE alloc(VALUE self);
    static VALUE GetSize(VALUE self);

    static void DefineClass();
	static VALUE rubyClass;
};

class WxMoveEvent {
public:
    static VALUE alloc(VALUE self);
    static VALUE GetPosition(VALUE self);

    static void DefineClass();
	static VALUE rubyClass;
};

class WxNotifyEvent {
public:
    static VALUE alloc(VALUE self);
    static void Allow(VALUE self);
    static VALUE IsAllowed(VALUE self);
    static void Veto(VALUE self);

    static void DefineClass();
	static VALUE rubyClass;
};

class WxNotebookEvent {
public:
    static VALUE alloc(VALUE self);
    static VALUE GetSelection(VALUE self);
    static void SetSelection(VALUE self,VALUE nSel);
    static VALUE GetOldSelection(VALUE self);
    static void SetOldSelection(VALUE self,VALUE nOldSel);

    static void DefineClass();
	static VALUE rubyClass;
};

class WxSpinEvent {
public:
    static VALUE alloc(VALUE self);
    static VALUE GetPosition(VALUE self);
    static void SetPosition(VALUE self,VALUE vpos);

    static void DefineClass();
	static VALUE rubyClass;
};

class WxPaintEvent {
public:
    static VALUE alloc(VALUE self);

    static void DefineClass();
	static VALUE rubyClass;
};

class WxCalendarEvent {
public:
    static VALUE alloc(VALUE self);
    static VALUE GetDate(VALUE self);

    static void DefineClass();
	static VALUE rubyClass;
};

class WxListEvent {
public:
    static VALUE alloc(VALUE self);
    static VALUE GetData(VALUE self);
    static VALUE GetColumn(VALUE self);
    static VALUE GetIndex(VALUE self);
    static VALUE GetKeyCode(VALUE self);
    static VALUE GetMask(VALUE self);
//    static VALUE Cancelled(VALUE self);
    static VALUE GetImage(VALUE self);
    static VALUE GetItem(VALUE self);
    static VALUE GetLabel(VALUE self);
    static VALUE GetPoint(VALUE self);
    static VALUE GetText(VALUE self);
    static VALUE GetCacheFrom(VALUE self);
    static VALUE GetCacheTo(VALUE self);

    static void DefineClass();
	static VALUE rubyClass;
};

class WxUpdateUIEvent {
public:
    static VALUE alloc(VALUE self);
    static void Enable(VALUE self,VALUE venable);

    static void DefineClass();
	static VALUE rubyClass;
};

class WxFindDialogEvent {
public:
    static VALUE alloc(VALUE self);
    static VALUE GetDialog(VALUE self);
    static VALUE GetFindString(VALUE self);
    static VALUE GetFlags(VALUE self);
    static VALUE GetReplaceString(VALUE self);
    static void SetFindString(VALUE self,VALUE vstr);
    static void SetFlags(VALUE self,VALUE flags);
    static void SetReplaceString(VALUE self,VALUE vstr);

    static void DefineClass();
	static VALUE rubyClass;
};

class WxSocketEvent {
public:
    static VALUE alloc(VALUE self);
    //static VALUE GetClientData(VALUE self);
    static VALUE GetSocket(VALUE self);
    static VALUE GetSocketEvent(VALUE self);

    static void DefineClass();
	static VALUE rubyClass;
};

class WxSplitterEvent {
public:
    static VALUE alloc(VALUE self);
    static VALUE GetSashPosition(VALUE self);
    static VALUE GetWindowBeingRemoved(VALUE self);
    static VALUE GetX(VALUE self);
    static VALUE GetY(VALUE self);
    static void SetSashPosition(VALUE self,VALUE vpos);

    static void DefineClass();
	static VALUE rubyClass;
};

class WxTreeEvent {
public:
    static VALUE alloc(VALUE self);
    static VALUE GetItem(VALUE self);
    static VALUE GetKeyCode(VALUE self);
    static VALUE GetKeyEvent(VALUE self);
    static VALUE GetLabel(VALUE self);
    static VALUE GetOldItem(VALUE self);
    static VALUE GetPoint(VALUE self);
    static VALUE IsEditCancelled(VALUE self);

    static void DefineClass();
	static VALUE rubyClass;
};

class WxIdleEvent {
public:
    static VALUE alloc(VALUE self);
	static VALUE RequestMore(VALUE self);
	static VALUE MoreRequested(VALUE self);

    static void DefineClass();
	static VALUE rubyClass;
};

#endif
