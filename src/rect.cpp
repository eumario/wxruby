/**********************************************************************

  rect.cpp -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#include "wx.h"
#include "rect.h"

void WxRect::DefineClass()
{
	if(rubyClass)
		return;
	rubyClass = rb_define_class_under(GetWxModule(),"Rect", rb_cObject);
	rb_define_alloc_func(rubyClass,WxRect::alloc);
	rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new4), 4);
	rb_define_method(rubyClass, "initialize", VALUEFUNC(WxRect::init), 4);
	rb_define_method(rubyClass, "x", VALUEFUNC(WxRect::x), 0);
	rb_define_method(rubyClass, "y", VALUEFUNC(WxRect::y), 0);
	rb_define_method(rubyClass, "width", VALUEFUNC(WxRect::width), 0);
	rb_define_method(rubyClass, "height", VALUEFUNC(WxRect::height), 0);
}

VALUE
WxRect::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxRect::init(VALUE self,VALUE vx,VALUE vy,VALUE vwidth,VALUE vheight)
{
    int x = NUM2INT(vx);
    int y = NUM2INT(vy);
    int width = NUM2INT(vwidth);
    int height = NUM2INT(vheight);
    wxRect *ptr;
    Data_Get_Struct(self, wxRect, ptr);
    ptr = new wxRect(x,y,width,height);
    DATA_PTR(self) = ptr;

    return self;
}

VALUE
WxRect::x(VALUE self)
{
    wxRect *ptr;
    Data_Get_Struct(self, wxRect, ptr);
    return INT2NUM(ptr->x);
}

VALUE
WxRect::y(VALUE self)
{
    wxRect *ptr;
    Data_Get_Struct(self, wxRect, ptr);
    return INT2NUM(ptr->y);
}

VALUE
WxRect::width(VALUE self)
{
    wxRect *ptr;
    Data_Get_Struct(self, wxRect, ptr);
    return INT2NUM(ptr->width);
}

VALUE
WxRect::height(VALUE self)
{
    wxRect *ptr;
    Data_Get_Struct(self, wxRect, ptr);
    return INT2NUM(ptr->height);
}

VALUE
WxRect::init0(const wxRect &rect)
{
    VALUE self = Data_Wrap_Struct(rubyClass, 0, 0, 0);
    DATA_PTR(self) = new wxRect(rect);
    return self;
}

VALUE WxRect::rubyClass;

class ZAutoDefineWxRect
{
public:
   ZAutoDefineWxRect()
    {
       WxRect::DefineClass();
    }
};
static ZAutoDefineWxRect x;
