/**********************************************************************

  brush.cpp -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#include "wx.h"
#include "brush.h"
#include "bitmap.h"
#include "colour.h"

void WxBrush::DefineClass()
{
	if(rubyClass)
		return;
	rubyClass = rb_define_class_under(GetWxModule(),"Brush", rb_cObject);
	rb_define_alloc_func(rubyClass,WxBrush::alloc);
	rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new_1), -1);
	rb_define_method(rubyClass, "initialize", VALUEFUNC(WxBrush::init), -1);
	rb_define_method(rubyClass, "get_colour", VALUEFUNC(WxBrush::GetColour), 0);
#ifdef __WXMSW__
	rb_define_method(rubyClass, "get_stipple", VALUEFUNC(WxBrush::GetStipple), 0);
#endif
	rb_define_method(rubyClass, "get_style", VALUEFUNC(WxBrush::GetStyle), 0);
	rb_define_method(rubyClass, "ok", VALUEFUNC(WxBrush::Ok), 0);
	rb_define_method(rubyClass, "set_colour", VALUEFUNC(WxBrush::SetColour), -1);
#ifdef __WXMSW__
	rb_define_method(rubyClass, "set_stipple", VALUEFUNC(WxBrush::SetStipple), 1);
#endif
	rb_define_method(rubyClass, "set_style", VALUEFUNC(WxBrush::SetStyle), 1);
}

VALUE
WxBrush::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxBrush::init(int argc, VALUE *argv, VALUE self)
{
    wxBrush *ptr;
    Data_Get_Struct(self, wxBrush, ptr);
    if(argc==0) {
        ptr = new wxBrush();
    } else if(argc==1) {
        wxBitmap *stippleBitmap;
        Data_Get_Struct(argv[0], wxBitmap, stippleBitmap);
        ptr = new wxBrush(*stippleBitmap);
    } else if(argc==2) {
        int style = NUM2INT(argv[1]);
        if(TYPE(argv[0])==T_STRING) {
            wxString colourName = StringValuePtr(argv[0]);
            ptr = new wxBrush(colourName,style);
        }
        else {
            wxColour *colour;
            Data_Get_Struct(argv[0], wxColour, colour);
            ptr = new wxBrush(*colour,style);
        }
    }
    DATA_PTR(self) = ptr;
    return self;
}

VALUE
WxBrush::init0(const wxBrush &brush)
{
    VALUE self = Data_Wrap_Struct(rubyClass, 0, 0, 0);
    DATA_PTR(self) = (void*)&brush;
    return self;
}

VALUE
WxBrush::GetColour(VALUE self)
{
    wxBrush *ptr;
    Data_Get_Struct(self, wxBrush, ptr);
    return WxColour::init0(ptr->GetColour());
}

VALUE
WxBrush::GetStipple(VALUE self)
{
    wxBrush *ptr;
    Data_Get_Struct(self, wxBrush, ptr);
    return WxBitmap::init0(*ptr->GetStipple());
}

VALUE
WxBrush::GetStyle(VALUE self)
{
    wxBrush *ptr;
    Data_Get_Struct(self, wxBrush, ptr);
    return INT2NUM(ptr->GetStyle());
}

VALUE
WxBrush::Ok(VALUE self)
{
    wxBrush *ptr;
    Data_Get_Struct(self, wxBrush, ptr);
    return (ptr->Ok() ? Qtrue : Qfalse);
}

void
WxBrush::SetColour(int argc, VALUE *argv, VALUE self)
{
    wxBrush *ptr;
    Data_Get_Struct(self, wxBrush, ptr);
    if(argc==1) {
        if(TYPE(argv[0])==T_STRING) {
            wxString colourName = StringValuePtr(argv[0]);
            ptr->SetColour(colourName);
        }
        else {
            wxColour *colour;
            Data_Get_Struct(argv[0], wxColour, colour);
            ptr->SetColour(*colour);
        }
    } else if(argc==3) {
        unsigned char red = NUM2INT(argv[0]);
        unsigned char green = NUM2INT(argv[1]);
        unsigned char blue = NUM2INT(argv[2]);
        ptr->SetColour(red,green,blue);
    }
}

void
WxBrush::SetStipple(VALUE self,VALUE vbitmap)
{
    wxBitmap *bitmap;
    Data_Get_Struct(vbitmap, wxBitmap, bitmap);
    wxBrush *ptr;
    Data_Get_Struct(self, wxBrush, ptr);
    ptr->SetStipple(*bitmap);
}

void
WxBrush::SetStyle(VALUE self,VALUE vstyle)
{
    int style = NUM2INT(vstyle);
    wxBrush *ptr;
    Data_Get_Struct(self, wxBrush, ptr);
    ptr->SetStyle(style);
}

VALUE WxBrush::rubyClass;

class ZAutoDefineWxBrush
{
public:
   ZAutoDefineWxBrush()
    {
       WxBrush::DefineClass();
    }
};
static ZAutoDefineWxBrush x;
