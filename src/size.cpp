/**********************************************************************

  size.cpp -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#include "wx.h"
#include "size.h"

void WxSize::DefineClass()
{
	if(rubyClass)
		return;
	rubyClass = rb_define_class_under(GetWxModule(),"Size", rb_cObject);
	rb_define_alloc_func(rubyClass,WxSize::alloc);
	rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new2), 2);
	rb_define_method(rubyClass, "initialize", VALUEFUNC(WxSize::init), 2);
	rb_define_method(rubyClass, "set", VALUEFUNC(WxSize::Set), 2);
	rb_define_method(rubyClass, "set_height", VALUEFUNC(WxSize::SetHeight), 1);
	rb_define_method(rubyClass, "set_width", VALUEFUNC(WxSize::SetWidth), 1);
	rb_define_method(rubyClass, "get_height", VALUEFUNC(WxSize::GetHeight), 0);
	rb_define_method(rubyClass, "get_width", VALUEFUNC(WxSize::GetWidth), 0);
	rb_define_method(rubyClass, "x", VALUEFUNC(WxSize::x), 0);
	rb_define_method(rubyClass, "y", VALUEFUNC(WxSize::y), 0);
}

VALUE
WxSize::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxSize::init(VALUE self,VALUE vwidth,VALUE vheight)
{
    int width = NUM2INT(vwidth);
    int height = NUM2INT(vheight);
    wxSize *ptr;
    Data_Get_Struct(self, wxSize, ptr);
    ptr = new wxSize(width,height);
    DATA_PTR(self) = ptr;

    return self;
}

void
WxSize::Set(VALUE self,VALUE vwidth,VALUE vheight)
{
    int width = NUM2INT(vwidth);
    int height = NUM2INT(vheight);
    wxSize *ptr;
    Data_Get_Struct(self, wxSize, ptr);
    ptr->Set(width,height);
}

void
WxSize::SetHeight(VALUE self,VALUE vheight)
{
    int height = NUM2INT(vheight);
    wxSize *ptr;
    Data_Get_Struct(self, wxSize, ptr);
    ptr->SetHeight(height);
}

void
WxSize::SetWidth(VALUE self,VALUE vwidth)
{
    int width = NUM2INT(vwidth);
    wxSize *ptr;
    Data_Get_Struct(self, wxSize, ptr);
    ptr->SetWidth(width);
}

VALUE
WxSize::GetWidth(VALUE self)
{
    wxSize *ptr;
    Data_Get_Struct(self, wxSize, ptr);
    return INT2NUM(ptr->GetWidth());
}

VALUE
WxSize::GetHeight(VALUE self)
{
    wxSize *ptr;
    Data_Get_Struct(self, wxSize, ptr);
    return INT2NUM(ptr->GetHeight());
}

VALUE
WxSize::init0(const wxSize &size)
{
    static VALUE self = Data_Wrap_Struct(rubyClass, 0, 0, 0);
    DATA_PTR(self) = new wxSize(size);
    return self;
}

VALUE
WxSize::x(VALUE self)
{
    wxSize *ptr;
    Data_Get_Struct(self, wxSize, ptr);
    return INT2NUM(ptr->x);
}

VALUE
WxSize::y(VALUE self)
{
    wxSize *ptr;
    Data_Get_Struct(self, wxSize, ptr);
    return INT2NUM(ptr->y);
}

VALUE WxSize::rubyClass;

class ZAutoDefineWxSize
{
public:
   ZAutoDefineWxSize()
    {
       WxSize::DefineClass();
    }
};
static ZAutoDefineWxSize x;
