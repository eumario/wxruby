/**********************************************************************

  spin.cpp -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#include "wx.h"
#include "spin.h"
#include "window.h"

void WxSpinCtrl::DefineClass()
{
	if(rubyClass)
		return;
	WxWindow::DefineClass();
	rubyClass = rb_define_class_under(GetWxModule(),"SpinCtrl", WxWindow::rubyClass);
	rb_define_alloc_func(rubyClass,WxSpinCtrl::alloc);
	rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new_1), -1);
	rb_define_method(rubyClass, "initialize", VALUEFUNC(WxSpinCtrl::init), -1);
	rb_define_method(rubyClass, "set_value",    VALUEFUNC(WxSpinCtrl::SetValue), 1);
	rb_define_method(rubyClass, "get_value",    VALUEFUNC(WxSpinCtrl::GetValue), 0);
	rb_define_method(rubyClass, "set_range",    VALUEFUNC(WxSpinCtrl::SetRange), 2);
#ifdef __WXMSW__
	rb_define_method(rubyClass, "set_selection",VALUEFUNC(WxSpinCtrl::SetSelection), 2);
#endif
	rb_define_method(rubyClass, "get_min",      VALUEFUNC(WxSpinCtrl::GetMin), 0);
	rb_define_method(rubyClass, "get_max",      VALUEFUNC(WxSpinCtrl::GetMax), 0);
}

VALUE
WxSpinCtrl::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxSpinCtrl::init(int argc, VALUE *argv, VALUE self)
{
    wxWindow* parent = 0;
    wxWindowID id = -1;
    wxString value = "";
    wxPoint pos = wxDefaultPosition;
    wxSize size = wxDefaultSize;
    long style = wxSP_ARROW_KEYS;
    int min = 0;
    int max = 100;
    int initial = 0;
    wxString name = "wxSpinCtrl";

    if(argc>0 && TYPE(argv[0])==T_DATA) {
	Data_Get_Struct(argv[0], wxWindow, parent);
    }
    if(argc>1 && TYPE(argv[1])==T_FIXNUM)
      id = NUM2INT(argv[1]);
    if(argc>2 && TYPE(argv[2])==T_STRING)
      value = wxString(StringValuePtr(argv[2]));
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
    if(argc>6 && TYPE(argv[6])==T_FIXNUM)
      min = NUM2INT(argv[6]);
    if(argc>7 && TYPE(argv[7])==T_FIXNUM)
      max = NUM2INT(argv[7]);
    if(argc>8 && TYPE(argv[8])==T_FIXNUM)
      initial = NUM2INT(argv[8]);
    if(argc>9 && TYPE(argv[9])==T_STRING)
      name = wxString(StringValuePtr(argv[9]));

    wxSpinCtrl *ptr;
    Data_Get_Struct(self, wxSpinCtrl, ptr);
    ptr = new wxSpinCtrl(parent,id,value,pos,size,style,min,max,initial,name);

    VALUE vdata = rb_hash_new();
    rb_hash_aset(vdata,rb_str_new2("self"),self);
    ptr->SetClientData((void*)vdata);

    DATA_PTR(self) = ptr;

    return self;
}

void
WxSpinCtrl::SetValue(VALUE self,VALUE vvalue)
{
    int value = NUM2INT(vvalue);
    wxSpinCtrl *ptr;
    Data_Get_Struct(self, wxSpinCtrl, ptr);
    ptr->SetValue(value);
}

void
WxSpinCtrl::SetRange(VALUE self,VALUE vminVal,VALUE vmaxVal)
{
    int minVal = NUM2INT(vminVal);
    int maxVal = NUM2INT(vmaxVal);
    wxSpinCtrl *ptr;
    Data_Get_Struct(self, wxSpinCtrl, ptr);
    ptr->SetRange(minVal,maxVal);
}

#ifdef __WXMSW__
void
WxSpinCtrl::SetSelection(VALUE self,VALUE vfrom,VALUE vto)
{
    long from = NUM2INT(vfrom);
    long to = NUM2INT(vto);
    wxSpinCtrl *ptr;
    Data_Get_Struct(self, wxSpinCtrl, ptr);
    ptr->SetSelection(from,to);
}
#endif

VALUE
WxSpinCtrl::GetValue(VALUE self)
{
    wxSpinCtrl *ptr;
    Data_Get_Struct(self, wxSpinCtrl, ptr);
    return INT2NUM(ptr->GetValue());
}

VALUE
WxSpinCtrl::GetMin(VALUE self)
{
    wxSpinCtrl *ptr;
    Data_Get_Struct(self, wxSpinCtrl, ptr);
    return INT2NUM(ptr->GetMin());
}

VALUE
WxSpinCtrl::GetMax(VALUE self)
{
    wxSpinCtrl *ptr;
    Data_Get_Struct(self, wxSpinCtrl, ptr);
    return INT2NUM(ptr->GetMax());
}

VALUE WxSpinCtrl::rubyClass;

class ZAutoDefineWxSpinCtrl
{
public:
   ZAutoDefineWxSpinCtrl()
    {
       WxSpinCtrl::DefineClass();
    }
};
static ZAutoDefineWxSpinCtrl x;

//---------------------------------------------------------------------------------------
void WxSpinButton::DefineClass()
{
	if(rubyClass)
		return;
	WxWindow::DefineClass();
	rubyClass = rb_define_class_under(GetWxModule(),"SpinButton", WxWindow::rubyClass);
	rb_define_alloc_func(rubyClass,WxSpinButton::alloc);
	rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new_1), -1);
	rb_define_method(rubyClass, "initialize", VALUEFUNC(WxSpinButton::init), -1);
	rb_define_method(rubyClass, "get_max", VALUEFUNC(WxSpinButton::GetMax), 0);
	rb_define_method(rubyClass, "get_min", VALUEFUNC(WxSpinButton::GetMin), 0);
	rb_define_method(rubyClass, "get_value", VALUEFUNC(WxSpinButton::GetValue), 0);
	rb_define_method(rubyClass, "set_range", VALUEFUNC(WxSpinButton::SetRange), 2);
	rb_define_method(rubyClass, "set_value", VALUEFUNC(WxSpinButton::SetValue), 1);
}

VALUE
WxSpinButton::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxSpinButton::init(int argc, VALUE *argv, VALUE self)
{
    wxWindow* parent = NULL;
    wxWindowID id = -1;
    wxPoint pos = wxDefaultPosition;
    wxSize size = wxDefaultSize;
    long style = wxSP_HORIZONTAL;
//    wxValidator validator = wxDefaultValidator;
//    wxString name = "spinButton";

    if(argc>0 && TYPE(argv[0])==T_DATA) {
	    Data_Get_Struct(argv[0], wxWindow, parent);
    }
    if(argc>1 && TYPE(argv[1])==T_FIXNUM)
      id = NUM2INT(argv[1]);
    if(argc>2 && TYPE(argv[2])==T_DATA) {
        wxPoint *ptr;
	    Data_Get_Struct(argv[2], wxPoint, ptr);
	    pos = *ptr;
    }
    if(argc>3 && TYPE(argv[3])==T_DATA) {
        wxSize *ptr;
	    Data_Get_Struct(argv[3], wxSize, ptr);
	    size = *ptr;
    }
    if(argc>4 && TYPE(argv[4])==T_FIXNUM)
      style = NUM2INT(argv[4]);

    wxSpinButton *ptr;
    Data_Get_Struct(self, wxSpinButton, ptr);
    ptr = new wxSpinButton(parent,id,pos,size,style);

    VALUE vdata = rb_hash_new();
    rb_hash_aset(vdata,rb_str_new2("self"),self);
    ptr->SetClientData((void*)vdata);

    DATA_PTR(self) = ptr;

    return self;
}

VALUE
WxSpinButton::GetMax(VALUE self)
{
    wxSpinButton *ptr;
    Data_Get_Struct(self, wxSpinButton, ptr);
    return INT2NUM(ptr->GetMax());
}

VALUE
WxSpinButton::GetMin(VALUE self)
{
    wxSpinButton *ptr;
    Data_Get_Struct(self, wxSpinButton, ptr);
    return INT2NUM(ptr->GetMin());
}

VALUE
WxSpinButton::GetValue(VALUE self)
{
    wxSpinButton *ptr;
    Data_Get_Struct(self, wxSpinButton, ptr);
    return INT2NUM(ptr->GetValue());
}

void
WxSpinButton::SetRange(VALUE self,VALUE vmin,VALUE vmax)
{
    int min = NUM2INT(vmin);
    int max = NUM2INT(vmax);
    wxSpinButton *ptr;
    Data_Get_Struct(self, wxSpinButton, ptr);
    ptr->SetRange(min,max);
}

void
WxSpinButton::SetValue(VALUE self,VALUE vvalue)
{
    int value = NUM2INT(vvalue);
    wxSpinButton *ptr;
    Data_Get_Struct(self, wxSpinButton, ptr);
    ptr->SetValue(value);
}

VALUE WxSpinButton::rubyClass;

class ZAutoDefineWxSpinButton
{
public:
   ZAutoDefineWxSpinButton()
    {
       WxSpinButton::DefineClass();
    }
};
static ZAutoDefineWxSpinButton x2;
