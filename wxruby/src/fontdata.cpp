/**********************************************************************

  fontdata.cpp -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#include "wx.h"
#include "font.h"
#include "colour.h"
#include "fontdata.h"

void WxFontData::DefineClass()
{
	if(rubyClass)
		return;
	rubyClass = rb_define_class_under(GetWxModule(),"FontData", rb_cObject);
	rb_define_alloc_func(rubyClass,WxFontData::alloc);
	rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new0), 0);
	rb_define_method(rubyClass, "initialize", VALUEFUNC(WxFontData::init), 0);
	rb_define_method(rubyClass, "set_initial_font", VALUEFUNC(WxFontData::SetInitialFont), 1);
	rb_define_method(rubyClass, "set_colour", VALUEFUNC(WxFontData::SetColour), 1);
	rb_define_method(rubyClass, "set_show_help", VALUEFUNC(WxFontData::SetShowHelp), 1);
	rb_define_method(rubyClass, "get_chosen_font", VALUEFUNC(WxFontData::GetChosenFont), 0);
	rb_define_method(rubyClass, "get_colour", VALUEFUNC(WxFontData::GetColour), 0);
}

VALUE
WxFontData::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxFontData::init(VALUE self)
{
    wxFontData *ptr;
    Data_Get_Struct(self, wxFontData, ptr);
    ptr = new wxFontData();
    DATA_PTR(self) = ptr;

    return self;
}

void
WxFontData::SetInitialFont(VALUE self,VALUE vfont)
{
    wxFont *font;
    Data_Get_Struct(vfont, wxFont, font);
    wxFontData *ptr;
    Data_Get_Struct(self, wxFontData, ptr);
    ptr->SetInitialFont(*font);
}

void
WxFontData::SetColour(VALUE self,VALUE vcolour)
{
    wxColour *colour;
    Data_Get_Struct(vcolour, wxColour, colour);
    wxFontData *ptr;
    Data_Get_Struct(self, wxFontData, ptr);
    ptr->SetColour(*colour);
}

void
WxFontData::SetShowHelp(VALUE self,VALUE vshowHelp)
{
    bool showHelp = (vshowHelp==Qtrue);
    wxFontData *ptr;
    Data_Get_Struct(self, wxFontData, ptr);
    ptr->SetShowHelp(showHelp);
}

VALUE
WxFontData::GetChosenFont(VALUE self)
{
    wxFontData *ptr;
    Data_Get_Struct(self, wxFontData, ptr);
    return WxFont::init0(ptr->GetChosenFont());
}

VALUE
WxFontData::GetColour(VALUE self)
{
    wxFontData *ptr;
    Data_Get_Struct(self, wxFontData, ptr);
    return WxColour::init0(ptr->GetColour());
}

VALUE
WxFontData::init0(const wxFontData &fontData)
{
    wxFontData *ptr;
    VALUE self = Data_Wrap_Struct(rubyClass, 0, 0, 0);
    ptr = new wxFontData();
    *ptr = fontData;
    DATA_PTR(self) = ptr;
    return self;
}

VALUE WxFontData::rubyClass;

class ZAutoDefineWxFontData
{
public:
   ZAutoDefineWxFontData()
    {
       WxFontData::DefineClass();
    }
};
static ZAutoDefineWxFontData x;
