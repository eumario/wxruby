/**********************************************************************

  palette.cpp -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#include "wx.h"
#include "palette.h"
#include "bitmap.h"
#include "colour.h"

void WxPalette::DefineClass()
{
	if(rubyClass)
		return;
	rubyClass = rb_define_class_under(GetWxModule(),"Palette", rb_cObject);
	rb_define_alloc_func(rubyClass,WxPalette::alloc);
	rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new3), 3);
	rb_define_method(rubyClass, "initialize", VALUEFUNC(WxPalette::init), 3);
	rb_define_method(rubyClass, "get_pixel", VALUEFUNC(WxPalette::GetPixel), 3);
	rb_define_method(rubyClass, "get_rgb", VALUEFUNC(WxPalette::GetRGB), 1);
	rb_define_method(rubyClass, "ok", VALUEFUNC(WxPalette::Ok), 0);
}

VALUE
WxPalette::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxPalette::init(VALUE self,VALUE vred,VALUE vgreen,VALUE vblue)
{
    wxPalette *ptr;
    Data_Get_Struct(self, wxPalette, ptr);

    int n = RARRAY(vred)->len;
    unsigned char* red = new unsigned char[n];
    unsigned char* green = new unsigned char[n];
    unsigned char* blue = new unsigned char[n];
    for (int i = 0; i < n; i++) {
        red[i] = NUM2INT(RARRAY(vred)->ptr[i]);
        green[i] = NUM2INT(RARRAY(vgreen)->ptr[i]);
        blue[i] = NUM2INT(RARRAY(vblue)->ptr[i]);
    }
    ptr = new wxPalette(n,red,green,blue);
    delete red;
    delete green;
    delete blue;
    DATA_PTR(self) = ptr;
    return self;
}

VALUE
WxPalette::init0(wxPalette *palette)
{
    VALUE self = Data_Wrap_Struct(rubyClass, 0, 0, 0);
    DATA_PTR(self) = (void*)palette;
    return self;
}

VALUE
WxPalette::GetPixel(VALUE self,VALUE vred,VALUE vgreen,VALUE vblue)
{
    unsigned char red = NUM2INT(vred);
    unsigned char green = NUM2INT(vgreen);
    unsigned char blue = NUM2INT(vblue);
    wxPalette *ptr;
    Data_Get_Struct(self, wxPalette, ptr);
    return INT2NUM(ptr->GetPixel(red,green,blue));
}

VALUE
WxPalette::GetRGB(VALUE self,VALUE vpixel)
{
    int pixel = NUM2INT(vpixel);
    unsigned char red;
    unsigned char green;
    unsigned char blue;
    wxPalette *ptr;
    Data_Get_Struct(self, wxPalette, ptr);
    if(ptr->GetRGB(pixel,&red,&green,&blue))
        return rb_ary_new3(3,INT2NUM(red),INT2NUM(green),INT2NUM(blue));
    else
        return Qnil;
}

VALUE
WxPalette::Ok(VALUE self)
{
    wxPalette *ptr;
    Data_Get_Struct(self, wxPalette, ptr);
    return (ptr->Ok() ? Qtrue : Qfalse);
}

VALUE WxPalette::rubyClass;

class ZAutoDefineWxPalette
{
public:
   ZAutoDefineWxPalette()
    {
       WxPalette::DefineClass();
    }
};
static ZAutoDefineWxPalette x;
