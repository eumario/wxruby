/**********************************************************************

  point.cpp -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#include "wx.h"
#include "point.h"

void WxPoint::DefineClass()
{
	if(rubyClass)
		return;
	rubyClass = rb_define_class_under(GetWxModule(),"Point", rb_cObject);
	rb_define_alloc_func(rubyClass,WxPoint::alloc);
	rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new2), 2);
	rb_define_method(rubyClass, "initialize", VALUEFUNC(WxPoint::init), 2);
	rb_define_method(rubyClass, "x", VALUEFUNC(WxPoint::x), 0);
	rb_define_method(rubyClass, "y", VALUEFUNC(WxPoint::y), 0);
}

VALUE
WxPoint::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxPoint::init(VALUE self,VALUE vx,VALUE vy)
{
    int x = NUM2INT(vx);
    int y = NUM2INT(vy);
    wxPoint *ptr;
    Data_Get_Struct(self, wxPoint, ptr);
    ptr = new wxPoint(x,y);
    DATA_PTR(self) = ptr;

    return self;
}

VALUE
WxPoint::x(VALUE self)
{
    wxPoint *ptr;
    Data_Get_Struct(self, wxPoint, ptr);
    return INT2NUM(ptr->x);
}

VALUE
WxPoint::y(VALUE self)
{
    wxPoint *ptr;
    Data_Get_Struct(self, wxPoint, ptr);
    return INT2NUM(ptr->y);
}

VALUE
WxPoint::init0(const wxPoint &point)
{
    VALUE self = Data_Wrap_Struct(rubyClass, 0, 0, 0);
    DATA_PTR(self) = new wxPoint(point);
    return self;
}

VALUE WxPoint::rubyClass;

class ZAutoDefine
{
public:
   ZAutoDefine()
    {
       WxPoint::DefineClass();
    }
};
static ZAutoDefine x;
