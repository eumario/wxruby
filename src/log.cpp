/**********************************************************************

  log.cpp -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#include "wx.h"
#include "log.h"

void WxLog::DefineClass()
{
	if(rubyClass)
		return;
	rubyClass = rb_define_class_under(GetWxModule(),"Log", rb_cObject);
	rb_define_alloc_func(rubyClass,WxLog::alloc);
	rb_define_method(rubyClass, "flush", VALUEFUNC(WxLog::Flush), 0);
	rb_define_singleton_method(rubyClass, "get_active_target", VALUEFUNC(WxLog::GetActiveTarget), 0);
	rb_define_singleton_method(rubyClass, "set_active_target", VALUEFUNC(WxLog::SetActiveTarget), 1);
	rb_define_singleton_method(rubyClass, "dont_create_on_demand", VALUEFUNC(WxLog::DontCreateOnDemand), 0);
	rb_define_singleton_method(rubyClass, "flush_active", VALUEFUNC(WxLog::FlushActive), 0);
	rb_define_singleton_method(rubyClass, "resume", VALUEFUNC(WxLog::Resume), 0);
	rb_define_singleton_method(rubyClass, "suspend", VALUEFUNC(WxLog::Suspend), 0);
}

VALUE
WxLog::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}


VALUE
WxLog::init0(wxLog *log)
{
    static VALUE self = Data_Wrap_Struct(rubyClass, 0, 0, 0);
    DATA_PTR(self) = log;
    return self;
}

VALUE
WxLog::GetActiveTarget(VALUE self)
{
    return WxLog::init0(wxLog::GetActiveTarget());
}

VALUE
WxLog::SetActiveTarget(VALUE self,VALUE vlogtarget)
{
    wxLog *logtarget = NULL;
    if(vlogtarget != Qnil)
        Data_Get_Struct(vlogtarget, wxLog, logtarget);
    return WxLog::init0(wxLog::SetActiveTarget(logtarget));
}

void
WxLog::Flush(VALUE self)
{
    wxLog *ptr;
    Data_Get_Struct(self, wxLog, ptr);
    ptr->Flush();
}

void
WxLog::DontCreateOnDemand(VALUE self)
{
    wxLog::DontCreateOnDemand();
}

void
WxLog::FlushActive(VALUE self)
{
    wxLog::FlushActive();
}

void
WxLog::Suspend(VALUE self)
{
    wxLog::Suspend();
}

void
WxLog::Resume(VALUE self)
{
    wxLog::Resume();
}

VALUE WxLog::rubyClass;

class ZAutoDefine
{
public:
   ZAutoDefine()
    {
       WxLog::DefineClass();
    }
};
static ZAutoDefine x;

//--------------------------------------------------------------------
void WxLogTextCtrl::DefineClass()
{
	if(rubyClass)
		return;
	WxLog::DefineClass();
	rubyClass = rb_define_class_under(GetWxModule(),"LogTextCtrl", WxLog::rubyClass);
	rb_define_alloc_func(rubyClass,WxLogTextCtrl::alloc);
	rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new1), 1);
	rb_define_method(rubyClass, "initialize", VALUEFUNC(WxLogTextCtrl::init), 1);
}
	
VALUE
WxLogTextCtrl::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxLogTextCtrl::init(VALUE self,VALUE vtextctrl)
{
    wxTextCtrl *textctrl;
	Data_Get_Struct(vtextctrl, wxTextCtrl, textctrl);

    wxLogTextCtrl *ptr;
    Data_Get_Struct(self, wxLogTextCtrl, ptr);
    ptr = new wxLogTextCtrl(textctrl);
    DATA_PTR(self) = ptr;

    return self;
}

VALUE WxLogTextCtrl::rubyClass;

class ZAutoDefineWxLogTextCtrl
{
public:
   ZAutoDefineWxLogTextCtrl()
    {
       WxLogTextCtrl::DefineClass();
    }
};
static ZAutoDefineWxLogTextCtrl x2;
