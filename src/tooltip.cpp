/**********************************************************************

  tooltip.cpp -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#include "wx.h"
#include "tooltip.h"
#include "window.h"

void WxToolTip::DefineClass()
{
	if(rubyClass)
		return;
	rubyClass = rb_define_class_under(GetWxModule(),"ToolTip", rb_cObject);
	rb_define_alloc_func(rubyClass,WxToolTip::alloc);
	rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new1), 1);
	rb_define_method(rubyClass, "initialize", VALUEFUNC(WxToolTip::init), 1);
	rb_define_singleton_method(rubyClass, "enable", VALUEFUNC(WxToolTip::Enable), 1);
	rb_define_singleton_method(rubyClass, "set_delay", VALUEFUNC(WxToolTip::SetDelay), 1);
	rb_define_method(rubyClass, "set_tip", VALUEFUNC(WxToolTip::SetTip), 1);
	rb_define_method(rubyClass, "get_tip", VALUEFUNC(WxToolTip::GetTip), 0);
	rb_define_method(rubyClass, "get_window", VALUEFUNC(WxToolTip::GetWindow), 0);
}

VALUE
WxToolTip::alloc(VALUE self)
{
   return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxToolTip::init(VALUE self,VALUE vtip)
{
    wxString tip = StringValuePtr(vtip);
    wxToolTip *ptr;
    Data_Get_Struct(self, wxToolTip, ptr);
    ptr = new wxToolTip(tip);
    DATA_PTR(self) = ptr;

    return self;
}

void
WxToolTip::Enable(VALUE self,VALUE vflag)
{
    bool flag = (vflag == Qtrue);
    wxToolTip::Enable(flag);
}

void
WxToolTip::SetDelay(VALUE self,VALUE vmsecs)
{
    long msecs = NUM2INT(vmsecs);
    wxToolTip::SetDelay(msecs);
}

void
WxToolTip::SetTip(VALUE self,VALUE vtip)
{
    wxString tip = StringValuePtr(vtip);
    wxToolTip *ptr;
    Data_Get_Struct(self, wxToolTip, ptr);
    ptr->SetTip(tip);
}

VALUE
WxToolTip::GetTip(VALUE self)
{
    wxToolTip *ptr;
    Data_Get_Struct(self, wxToolTip, ptr);
    return rb_str_new2(ptr->GetTip());
}

VALUE
WxToolTip::GetWindow(VALUE self)
{
    wxToolTip *ptr;
    Data_Get_Struct(self, wxToolTip, ptr);
    return WxWindow::init0(ptr->GetWindow());
}

VALUE
WxToolTip::init0(wxToolTip *tooltip)
{
    VALUE self = Data_Wrap_Struct(rubyClass, 0, 0, 0);
    DATA_PTR(self) = tooltip;
    return self;
}

VALUE WxToolTip::rubyClass;

class ZAutoDefine
{
public:
   ZAutoDefine()
    {
       WxToolTip::DefineClass();
    }
};
static ZAutoDefine x;
