/**********************************************************************

  mask.cpp -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#include "wx.h"
#include "mask.h"

void WxMask::DefineClass()
{
	if(rubyClass)
		return;
	rubyClass = rb_define_class_under(GetWxModule(),"Mask", rb_cObject);
	rb_define_alloc_func(rubyClass,WxMask::alloc);
	rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new_1), -1);
	rb_define_method(rubyClass, "initialize", VALUEFUNC(WxMask::init), -1);
}

VALUE
WxMask::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxMask::init(int argc, VALUE *argv, VALUE self)
{
    wxBitmap *bitmap;
    wxColour *colour;
    int index;

    wxMask *ptr;
    Data_Get_Struct(self, wxMask, ptr);
    if(argc==0) {
        ptr = new wxMask();
    }
    else {
        Data_Get_Struct(argv[0], wxBitmap, bitmap);
        if(TYPE(argv[1])==T_FIXNUM) {
            index = NUM2INT(argv[1]);
            ptr = new wxMask(*bitmap,index);
        } else {
            Data_Get_Struct(argv[1], wxColour, colour);
            ptr = new wxMask(*bitmap,*colour);
        }

    }
    DATA_PTR(self) = ptr;
    return self;
}

VALUE
WxMask::init0(wxMask *mask)
{
    static VALUE self = Data_Wrap_Struct(rubyClass, 0, 0, 0);
    DATA_PTR(self) = mask;
    return self;
}

VALUE WxMask::rubyClass;

class ZAutoDefine
{
public:
   ZAutoDefine()
    {
       WxMask::DefineClass();
    }
};
static ZAutoDefine x;
