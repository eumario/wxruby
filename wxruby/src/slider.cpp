/**********************************************************************

  slider.cpp -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#include "wx.h"
#include "slider.h"
#include "window.h"

void WxSlider::DefineClass()
{
	if(rubyClass)
		return;
	WxWindow::DefineClass();
	rubyClass = rb_define_class_under(GetWxModule(),"Slider", WxWindow::rubyClass);
	rb_define_alloc_func(rubyClass,WxSlider::alloc);
	rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new_1), -1);
	rb_define_method(rubyClass, "initialize", VALUEFUNC(WxSlider::init), -1);
	rb_define_method(rubyClass, "clear_sel", VALUEFUNC(WxSlider::ClearSel), 0);
	rb_define_method(rubyClass, "clear_ticks", VALUEFUNC(WxSlider::ClearTicks), 0);
	rb_define_method(rubyClass, "get_line_size", VALUEFUNC(WxSlider::GetLineSize), 0);
	rb_define_method(rubyClass, "get_max", VALUEFUNC(WxSlider::GetMax), 0);
	rb_define_method(rubyClass, "get_min", VALUEFUNC(WxSlider::GetMin), 0);
	rb_define_method(rubyClass, "get_page_size", VALUEFUNC(WxSlider::GetPageSize), 0);
	rb_define_method(rubyClass, "get_sel_end", VALUEFUNC(WxSlider::GetSelEnd), 0);
	rb_define_method(rubyClass, "get_sel_start", VALUEFUNC(WxSlider::GetSelStart), 0);
	rb_define_method(rubyClass, "get_thumb_length", VALUEFUNC(WxSlider::GetThumbLength), 0);
	rb_define_method(rubyClass, "get_tick_freq", VALUEFUNC(WxSlider::GetTickFreq), 0);
	rb_define_method(rubyClass, "get_value", VALUEFUNC(WxSlider::GetValue), 0);
	rb_define_method(rubyClass, "set_range", VALUEFUNC(WxSlider::SetRange), 2);
	rb_define_method(rubyClass, "set_tick_freq", VALUEFUNC(WxSlider::SetTickFreq), 2);
	rb_define_method(rubyClass, "set_line_size", VALUEFUNC(WxSlider::SetLineSize), 1);
	rb_define_method(rubyClass, "set_page_size", VALUEFUNC(WxSlider::SetPageSize), 1);
	rb_define_method(rubyClass, "set_selection", VALUEFUNC(WxSlider::SetSelection), 2);
	rb_define_method(rubyClass, "set_thumb_length", VALUEFUNC(WxSlider::SetThumbLength), 1);
	rb_define_method(rubyClass, "set_tick", VALUEFUNC(WxSlider::SetTick), 1);
	rb_define_method(rubyClass, "set_value", VALUEFUNC(WxSlider::SetValue), 1);
}

VALUE
WxSlider::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxSlider::init(int argc, VALUE *argv, VALUE self)
{
    wxWindow* parent;
    wxWindowID id;
    int value;
    int minValue;
    int maxValue;
    wxPoint pos = wxDefaultPosition;
    wxSize size = wxDefaultSize;
    long style = wxSL_HORIZONTAL;
//    wxValidator validator = wxDefaultValidator;
//    wxString name = "slider";

    if(argc>0 && TYPE(argv[0])==T_DATA) {
	Data_Get_Struct(argv[0], wxWindow, parent);
    }
    if(argc>1 && TYPE(argv[1])==T_FIXNUM)
      id = NUM2INT(argv[1]);
    if(argc>2 && TYPE(argv[2])==T_FIXNUM)
      value = NUM2INT(argv[2]);
    if(argc>3 && TYPE(argv[3])==T_FIXNUM)
      minValue = NUM2INT(argv[3]);
    if(argc>4 && TYPE(argv[4])==T_FIXNUM)
      maxValue = NUM2INT(argv[4]);
    if(argc>5 && TYPE(argv[5])==T_DATA) {
        wxPoint *ptr;
	Data_Get_Struct(argv[5], wxPoint, ptr);
	pos = *ptr;
    }
    if(argc>6 && TYPE(argv[6])==T_DATA) {
        wxSize *ptr;
	Data_Get_Struct(argv[6], wxSize, ptr);
	size = *ptr;
    }
    if(argc>7 && TYPE(argv[7])==T_FIXNUM)
      style = NUM2INT(argv[7]);

    wxSlider *ptr;
    Data_Get_Struct(self, wxSlider, ptr);
    ptr = new wxSlider(parent,id,value,minValue,maxValue,pos,size,style);

    VALUE vdata = rb_hash_new();
    rb_hash_aset(vdata,rb_str_new2("self"),self);
    ptr->SetClientData((void*)vdata);

    DATA_PTR(self) = ptr;

    return self;
}

void
WxSlider::ClearSel(VALUE self)
{
    wxSlider *ptr;
    Data_Get_Struct(self, wxSlider, ptr);
    ptr->ClearSel();
}

void
WxSlider::ClearTicks(VALUE self)
{
    wxSlider *ptr;
    Data_Get_Struct(self, wxSlider, ptr);
    ptr->ClearTicks();
}

VALUE
WxSlider::GetLineSize(VALUE self)
{
    wxSlider *ptr;
    Data_Get_Struct(self, wxSlider, ptr);
    return INT2NUM(ptr->GetLineSize());
}

VALUE
WxSlider::GetMax(VALUE self)
{
    wxSlider *ptr;
    Data_Get_Struct(self, wxSlider, ptr);
    return INT2NUM(ptr->GetMax());
}

VALUE
WxSlider::GetMin(VALUE self)
{
    wxSlider *ptr;
    Data_Get_Struct(self, wxSlider, ptr);
    return INT2NUM(ptr->GetMin());
}

VALUE
WxSlider::GetPageSize(VALUE self)
{
    wxSlider *ptr;
    Data_Get_Struct(self, wxSlider, ptr);
    return INT2NUM(ptr->GetPageSize());
}

VALUE
WxSlider::GetSelEnd(VALUE self)
{
    wxSlider *ptr;
    Data_Get_Struct(self, wxSlider, ptr);
    return INT2NUM(ptr->GetSelEnd());
}

VALUE
WxSlider::GetSelStart(VALUE self)
{
    wxSlider *ptr;
    Data_Get_Struct(self, wxSlider, ptr);
    return INT2NUM(ptr->GetSelStart());
}

VALUE
WxSlider::GetThumbLength(VALUE self)
{
    wxSlider *ptr;
    Data_Get_Struct(self, wxSlider, ptr);
    return INT2NUM(ptr->GetThumbLength());
}

VALUE
WxSlider::GetTickFreq(VALUE self)
{
    wxSlider *ptr;
    Data_Get_Struct(self, wxSlider, ptr);
    return INT2NUM(ptr->GetTickFreq());
}

VALUE
WxSlider::GetValue(VALUE self)
{
    wxSlider *ptr;
    Data_Get_Struct(self, wxSlider, ptr);
    return INT2NUM(ptr->GetValue());
}

void
WxSlider::SetRange(VALUE self,VALUE vminValue, VALUE vmaxValue)
{
    int minValue = NUM2INT(vminValue);
    int maxValue = NUM2INT(vmaxValue);
    wxSlider *ptr;
    Data_Get_Struct(self, wxSlider, ptr);
    ptr->SetRange(minValue,maxValue);
}

void
WxSlider::SetTickFreq(VALUE self,VALUE vn, VALUE vpos)
{
    int n = NUM2INT(vn);
    int pos = NUM2INT(vpos);
    wxSlider *ptr;
    Data_Get_Struct(self, wxSlider, ptr);
    ptr->SetTickFreq(n,pos);
}

void
WxSlider::SetLineSize(VALUE self,VALUE vlineSize)
{
    int lineSize = NUM2INT(vlineSize);
    wxSlider *ptr;
    Data_Get_Struct(self, wxSlider, ptr);
    ptr->SetLineSize(lineSize);
}

void
WxSlider::SetPageSize(VALUE self,VALUE vpageSize)
{
    int pageSize = NUM2INT(vpageSize);
    wxSlider *ptr;
    Data_Get_Struct(self, wxSlider, ptr);
    ptr->SetPageSize(pageSize);
}

void
WxSlider::SetSelection(VALUE self,VALUE vstartPos, VALUE vendPos)
{
    int startPos = NUM2INT(vstartPos);
    int endPos = NUM2INT(vendPos);
    wxSlider *ptr;
    Data_Get_Struct(self, wxSlider, ptr);
    ptr->SetSelection(startPos,endPos);
}

void
WxSlider::SetThumbLength(VALUE self,VALUE vlen)
{
    int len = NUM2INT(vlen);
    wxSlider *ptr;
    Data_Get_Struct(self, wxSlider, ptr);
    ptr->SetThumbLength(len);
}

void
WxSlider::SetTick(VALUE self,VALUE vtickPos)
{
    int tickPos = NUM2INT(vtickPos);
    wxSlider *ptr;
    Data_Get_Struct(self, wxSlider, ptr);
    ptr->SetTick(tickPos);
}

void
WxSlider::SetValue(VALUE self,VALUE vvalue)
{
    int value = NUM2INT(vvalue);
    wxSlider *ptr;
    Data_Get_Struct(self, wxSlider, ptr);
    ptr->SetValue(value);
}

VALUE WxSlider::rubyClass;

class ZAutoDefine
{
public:
   ZAutoDefine()
    {
       WxSlider::DefineClass();
    }
};
static ZAutoDefine x;
