/**********************************************************************

  gauge.cpp -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#include "wx.h"
#include "gauge.h"
#include "window.h"

void WxGauge::DefineClass()
{
	if(rubyClass)
		return;
	WxWindow::DefineClass();
	rubyClass = rb_define_class_under(GetWxModule(),"Gauge", WxWindow::rubyClass);
	rb_define_alloc_func(rubyClass,WxGauge::alloc);
	rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new_1), -1);
	rb_define_method(rubyClass, "initialize", VALUEFUNC(WxGauge::init), -1);
	rb_define_method(rubyClass, "set_bezel_face", VALUEFUNC(WxGauge::SetBezelFace), 1);
	rb_define_method(rubyClass, "set_range", VALUEFUNC(WxGauge::SetRange), 1);
	rb_define_method(rubyClass, "set_shadow_width", VALUEFUNC(WxGauge::SetShadowWidth), 1);
	rb_define_method(rubyClass, "set_value", VALUEFUNC(WxGauge::SetValue), 1);
	rb_define_method(rubyClass, "get_bezel_face", VALUEFUNC(WxGauge::GetBezelFace), 0);
	rb_define_method(rubyClass, "get_range", VALUEFUNC(WxGauge::GetRange), 0);
	rb_define_method(rubyClass, "get_shadow_width", VALUEFUNC(WxGauge::GetShadowWidth), 0);
	rb_define_method(rubyClass, "get_value", VALUEFUNC(WxGauge::GetValue), 0);
}

VALUE
WxGauge::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxGauge::init(int argc, VALUE *argv, VALUE self)
{
    wxWindow* parent = 0;
    wxWindowID id = -1;
    int range = 0;
    wxPoint pos = wxDefaultPosition;
    wxSize size = wxDefaultSize;
    long style = wxGA_HORIZONTAL;
//    wxValidator validator = wxDefaultValidator;
//    wxString name = "gauge";

    if(argc>0 && TYPE(argv[0])==T_DATA) {
	Data_Get_Struct(argv[0], wxWindow, parent);
    }
    if(argc>1 && TYPE(argv[1])==T_FIXNUM)
      id = NUM2INT(argv[1]);
    if(argc>2 && TYPE(argv[2])==T_FIXNUM)
      range = NUM2INT(argv[2]);
    if(argc>3 && TYPE(argv[3])==T_DATA) {
        wxPoint *ptr;
	Data_Get_Struct(argv[3], wxPoint, ptr);
	pos = *ptr;
    }
    if(argc>4 && TYPE(argv[4])==T_DATA) {
        wxSize *ptr;
	Data_Get_Struct(argv[4], wxSize, ptr);
	size = *ptr;
    }
    if(argc>5 && TYPE(argv[5])==T_FIXNUM)
      style = NUM2INT(argv[5]);

    wxGauge *ptr;
    Data_Get_Struct(self, wxGauge, ptr);
    ptr = new wxGauge(parent,id,range,pos,size,style);

    VALUE vdata = rb_hash_new();
    rb_hash_aset(vdata,rb_str_new2("self"),self);
    ptr->SetClientData((void*)vdata);

    DATA_PTR(self) = ptr;

    return self;
}

VALUE
WxGauge::GetBezelFace(VALUE self)
{
    wxGauge *ptr;
    Data_Get_Struct(self, wxGauge, ptr);
    return INT2NUM(ptr->GetBezelFace());
}

VALUE
WxGauge::GetRange(VALUE self)
{
    wxGauge *ptr;
    Data_Get_Struct(self, wxGauge, ptr);
    return INT2NUM(ptr->GetRange());
}

VALUE
WxGauge::GetShadowWidth(VALUE self)
{
    wxGauge *ptr;
    Data_Get_Struct(self, wxGauge, ptr);
    return INT2NUM(ptr->GetShadowWidth());
}

VALUE
WxGauge::GetValue(VALUE self)
{
    wxGauge *ptr;
    Data_Get_Struct(self, wxGauge, ptr);
    return INT2NUM(ptr->GetValue());
}

void
WxGauge::SetBezelFace(VALUE self,VALUE vwidth)
{
    int width = NUM2INT(vwidth);
    wxGauge *ptr;
    Data_Get_Struct(self, wxGauge, ptr);
    ptr->SetBezelFace(width);
}

void
WxGauge::SetRange(VALUE self,VALUE vrange)
{
    int range = NUM2INT(vrange);
    wxGauge *ptr;
    Data_Get_Struct(self, wxGauge, ptr);
    ptr->SetRange(range);
}

void
WxGauge::SetShadowWidth(VALUE self,VALUE vwidth)
{
    int width = NUM2INT(vwidth);
    wxGauge *ptr;
    Data_Get_Struct(self, wxGauge, ptr);
    ptr->SetShadowWidth(width);
}

void
WxGauge::SetValue(VALUE self,VALUE vpos)
{
    int pos = NUM2INT(vpos);
    wxGauge *ptr;
    Data_Get_Struct(self, wxGauge, ptr);
    ptr->SetValue(pos);
}

VALUE WxGauge::rubyClass;

class ZAutoDefineWxGague
{
public:
   ZAutoDefineWxGague()
    {
       WxGauge::DefineClass();
    }
};
static ZAutoDefineWxGague x;
