/**********************************************************************

  classinfo.cpp -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/

#include "wx.h"
#include "classinfo.h"

void WxClassInfo::DefineClass()
{
    if(rubyClass)
        return;

    rubyClass = rb_define_class_under(GetWxModule(),"ClassInfo", rb_cObject);
    rb_define_alloc_func(rubyClass,WxClassInfo::alloc);
    rb_define_method(rubyClass, "get_class_name", VALUEFUNC(WxClassInfo::GetClassName), 0);
}

VALUE
WxClassInfo::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}


VALUE
WxClassInfo::init0(wxClassInfo *classinfo)
{
    if(classinfo==NULL) return Qnil;
    VALUE self = Data_Wrap_Struct(rubyClass, 0, 0, 0);
    DATA_PTR(self) = classinfo;
    return self;
}

VALUE
WxClassInfo::GetClassName(VALUE self)
{
    wxClassInfo *ptr;
    Data_Get_Struct(self, wxClassInfo, ptr);
    return rb_str_new2(ptr->GetClassName());
}

VALUE WxClassInfo::rubyClass;

class ZAutoDefineWxClassInfo
{
public:
	ZAutoDefineWxClassInfo()
	{
		WxClassInfo::DefineClass();
	}
};
static ZAutoDefineWxClassInfo x;
