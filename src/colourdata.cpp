/**********************************************************************

  colourdata.cpp -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#include "wx.h"
#include "colour.h"
#include "colourdata.h"

void WxColourData::DefineClass()
{
	if(rubyClass)
		return;
	rubyClass = rb_define_class_under(GetWxModule(),"ColourData", rb_cObject);
	rb_define_alloc_func(rubyClass,WxColourData::alloc);
	rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new0), 0);
	rb_define_method(rubyClass, "initialize", VALUEFUNC(WxColourData::init), 0);
	rb_define_method(rubyClass, "get_choose_full", VALUEFUNC(WxColourData::GetChooseFull), 1);
	rb_define_method(rubyClass, "get_colour", VALUEFUNC(WxColourData::GetColour), 0);
	rb_define_method(rubyClass, "get_custom_colour", VALUEFUNC(WxColourData::GetCustomColour), 0);
	rb_define_method(rubyClass, "set_choose_full", VALUEFUNC(WxColourData::SetChooseFull), 1);
	rb_define_method(rubyClass, "set_colour", VALUEFUNC(WxColourData::SetColour), 1);
	rb_define_method(rubyClass, "set_custom_colour", VALUEFUNC(WxColourData::SetCustomColour), 2);
}

VALUE
WxColourData::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxColourData::init(VALUE self)
{
    wxColourData *ptr;
    Data_Get_Struct(self, wxColourData, ptr);
    ptr = new wxColourData();
    DATA_PTR(self) = ptr;

    return self;
}

void
WxColourData::SetColour(VALUE self,VALUE vcolour)
{
    wxColour *colour;
    Data_Get_Struct(vcolour, wxColour, colour);
    wxColourData *ptr;
    Data_Get_Struct(self, wxColourData, ptr);
    ptr->SetColour(*colour);
}

void
WxColourData::SetCustomColour(VALUE self,VALUE vi,VALUE vcolour)
{
    int i = NUM2INT(vi);
    wxColour *colour;
    Data_Get_Struct(vcolour, wxColour, colour);
    wxColourData *ptr;
    Data_Get_Struct(self, wxColourData, ptr);
    ptr->SetCustomColour(i,*colour);
}

void
WxColourData::SetChooseFull(VALUE self,VALUE vflag)
{
    bool flag = (vflag==Qtrue);
    wxColourData *ptr;
    Data_Get_Struct(self, wxColourData, ptr);
    ptr->SetChooseFull(flag);
}

VALUE
WxColourData::GetColour(VALUE self)
{
    wxColourData *ptr;
    Data_Get_Struct(self, wxColourData, ptr);
    return WxColour::init0(ptr->GetColour());
}

VALUE
WxColourData::init0(const wxColourData &colourData)
{
    wxColourData *ptr;
    VALUE self = Data_Wrap_Struct(rubyClass, 0, 0, 0);
    ptr = new wxColourData();
    *ptr = colourData;
    DATA_PTR(self) = ptr;
    return self;
}

VALUE
WxColourData::GetChooseFull(VALUE self)
{
    wxColourData *ptr;
    Data_Get_Struct(self, wxColourData, ptr);
    return (ptr->GetChooseFull() ? Qtrue : Qfalse);
}

VALUE
WxColourData::GetCustomColour(VALUE self,VALUE vi)
{
    int i = NUM2INT(vi);
    wxColourData *ptr;
    Data_Get_Struct(self, wxColourData, ptr);
    return WxColour::init0(ptr->GetCustomColour(i));
}

VALUE WxColourData::rubyClass;

class ZAutoDefineWxColourData
{
public:
   ZAutoDefineWxColourData()
    {
       WxColourData::DefineClass();
    }
};
static ZAutoDefineWxColourData x;
