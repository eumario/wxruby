/**********************************************************************

  colour.cpp -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#include "wx.h"
#include "colour.h"

void WxColour::DefineClass()
{
	if(rubyClass)
		return;
	rubyClass = rb_define_class_under(GetWxModule(),"Colour", rb_cObject);
	rb_define_alloc_func(rubyClass,WxColour::alloc);
	rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new_1), -1);
	rb_define_method(rubyClass, "initialize", VALUEFUNC(WxColour::init), -1);
	rb_define_method(rubyClass, "blue", VALUEFUNC(WxColour::Blue), 0);
	rb_define_method(rubyClass, "green", VALUEFUNC(WxColour::Green), 0);
	rb_define_method(rubyClass, "red", VALUEFUNC(WxColour::Red), 0);
	rb_define_method(rubyClass, "ok", VALUEFUNC(WxColour::Ok), 0);
}

VALUE
WxColour::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxColour::init(int argc, VALUE *argv, VALUE self)
{
    wxColour *ptr;
    Data_Get_Struct(self, wxColour, ptr);
    if(argc==0) {
        ptr = new wxColour();
    } else if(argc==3) {
        unsigned char red = NUM2INT(argv[0]);
        unsigned char green = NUM2INT(argv[1]);
        unsigned char blue = NUM2INT(argv[2]);
        ptr = new wxColour(red,green,blue);
    } else {
        wxString colourNname = StringValuePtr(argv[0]);
        ptr = new wxColour(colourNname);
    }
    DATA_PTR(self) = ptr;

    return self;
}

VALUE
WxColour::Blue(VALUE self)
{
    wxColour *ptr;
    Data_Get_Struct(self, wxColour, ptr);
    return INT2NUM(ptr->Blue());
}

VALUE
WxColour::Green(VALUE self)
{
    wxColour *ptr;
    Data_Get_Struct(self, wxColour, ptr);
    return INT2NUM(ptr->Green());
}

VALUE
WxColour::Red(VALUE self)
{
    wxColour *ptr;
    Data_Get_Struct(self, wxColour, ptr);
    return INT2NUM(ptr->Red());
}

VALUE
WxColour::Ok(VALUE self)
{
    wxColour *ptr;
    Data_Get_Struct(self, wxColour, ptr);
    return (ptr->Ok() ? Qtrue : Qfalse);
}

VALUE
WxColour::init0(const wxColour &colour)
{
    VALUE self = Data_Wrap_Struct(rubyClass, 0, 0, 0);
    DATA_PTR(self) = new wxColour(colour);
    return self;
}

VALUE WxColour::rubyClass;

class ZAutoDefineWxColour
{
public:
   ZAutoDefineWxColour()
    {
       WxColour::DefineClass();
    }
};
static ZAutoDefineWxColour x;
