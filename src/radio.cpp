/**********************************************************************

  radio.cpp -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#include "wx.h"
#include "radio.h"
#include "window.h"

void WxRadioBox::DefineClass()
{
	if(rubyClass)
		return;
	WxWindow::DefineClass();
	rubyClass = rb_define_class_under(GetWxModule(),"RadioBox", WxWindow::rubyClass);
	rb_define_alloc_func(rubyClass,WxRadioBox::alloc);
	rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new_1), -1);
	rb_define_method(rubyClass, "initialize", VALUEFUNC(WxRadioBox::init), -1);
	rb_define_method(rubyClass, "set_selection", VALUEFUNC(WxRadioBox::SetSelection), 1);
	rb_define_method(rubyClass, "get_string", VALUEFUNC(WxRadioBox::GetString), 1);
	rb_define_method(rubyClass, "get_string_selection", VALUEFUNC(WxRadioBox::GetStringSelection), 0);
	rb_define_method(rubyClass, "set_string_selection", VALUEFUNC(WxRadioBox::SetStringSelection), 1);
}

VALUE
WxRadioBox::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxRadioBox::init(int argc, VALUE *argv, VALUE self)
{
    wxWindow* parent;
    wxWindowID id;
    wxString label;
    wxPoint pos = wxDefaultPosition;
    wxSize size = wxDefaultSize;
    int n = 0;
    wxString *choices = NULL;
    int majorDimension = 0;
    long style = wxRA_SPECIFY_COLS;
//    wxValidator val wxDefaultValidator;
//    wxString name = "radioBox";

    if(argc>0 && TYPE(argv[0])==T_DATA) {
	Data_Get_Struct(argv[0], wxWindow, parent);
    }
    if(argc>1 && TYPE(argv[1])==T_FIXNUM)
      id = NUM2INT(argv[1]);
    if(argc>2 && TYPE(argv[2])==T_STRING)
      label = wxString(StringValuePtr(argv[2]));
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
    if(argc>5 && TYPE(argv[5])==T_ARRAY) {
      n = RARRAY(argv[5])->len;
      choices = new wxString[n];
      for (int i = 0; i < RARRAY(argv[5])->len; i++) {
        choices[i] = wxString(StringValuePtr(RARRAY(argv[5])->ptr[i]));
      }
    }
    if(argc>6 && TYPE(argv[6])==T_FIXNUM)
      majorDimension = NUM2INT(argv[6]);
    if(argc>7 && TYPE(argv[7])==T_FIXNUM)
      style = NUM2INT(argv[7]);

    wxRadioBox *ptr;
    Data_Get_Struct(self, wxRadioBox, ptr);
    ptr = new wxRadioBox(parent,id,label,pos,size,n,choices,majorDimension,style);

    VALUE vdata = rb_hash_new();
    rb_hash_aset(vdata,rb_str_new2("self"),self);
    ptr->SetClientData((void*)vdata);

    DATA_PTR(self) = ptr;

    return self;
}

void
WxRadioBox::SetSelection(VALUE self,VALUE vn)
{
    int n = NUM2INT(vn);
    wxRadioBox *ptr;
    Data_Get_Struct(self, wxRadioBox, ptr);
    ptr->SetSelection(n);
}

VALUE
WxRadioBox::GetString(VALUE self,VALUE vn)
{
    int n = NUM2INT(vn);
    wxRadioBox *ptr;
    Data_Get_Struct(self, wxRadioBox, ptr);
    return rb_str_new2(ptr->GetString(n));
}

VALUE
WxRadioBox::GetStringSelection(VALUE self)
{
    wxRadioBox *ptr;
    Data_Get_Struct(self, wxRadioBox, ptr);
    return rb_str_new2(ptr->GetStringSelection());
}

void
WxRadioBox::SetStringSelection(VALUE self,VALUE vstring)
{
    wxString string = StringValuePtr(vstring);
    wxRadioBox *ptr;
    Data_Get_Struct(self, wxRadioBox, ptr);
    ptr->SetStringSelection(string);
}

VALUE WxRadioBox::rubyClass;

class ZAutoDefine
{
public:
   ZAutoDefine()
    {
       WxRadioBox::DefineClass();
    }
};
static ZAutoDefine x;

//-------------------------------------------------------------------------------------
void WxRadioButton::DefineClass()
{
	if(rubyClass)
		return;
	WxWindow::DefineClass();
	rubyClass = rb_define_class_under(GetWxModule(),"RadioButton", WxWindow::rubyClass);
	rb_define_alloc_func(rubyClass,WxRadioButton::alloc);
	rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new_1), -1);
	rb_define_method(rubyClass, "initialize", VALUEFUNC(WxRadioButton::init), -1);
	rb_define_method(rubyClass, "get_value", VALUEFUNC(WxRadioButton::GetValue), 0);
	rb_define_method(rubyClass, "set_value", VALUEFUNC(WxRadioButton::SetValue), 1);
}


VALUE
WxRadioButton::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxRadioButton::init(int argc, VALUE *argv, VALUE self)
{
    wxWindow* parent;
    wxWindowID id;
    wxString label;
    wxPoint pos = wxDefaultPosition;
    wxSize size = wxDefaultSize;
    long style = 0;
//    wxValidator val wxDefaultValidator;
//    wxString name = "radioButton";

    if(argc>0 && TYPE(argv[0])==T_DATA) {
	Data_Get_Struct(argv[0], wxWindow, parent);
    }
    if(argc>1 && TYPE(argv[1])==T_FIXNUM)
      id = NUM2INT(argv[1]);
    if(argc>2 && TYPE(argv[2])==T_STRING)
      label = wxString(StringValuePtr(argv[2]));
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

    wxRadioButton *ptr;
    Data_Get_Struct(self, wxRadioButton, ptr);
    ptr = new wxRadioButton(parent,id,label,pos,size,style);

    VALUE vdata = rb_hash_new();
    rb_hash_aset(vdata,rb_str_new2("self"),self);
    ptr->SetClientData((void*)vdata);

    DATA_PTR(self) = ptr;

    return self;
}

VALUE
WxRadioButton::GetValue(VALUE self)
{
    wxRadioButton *ptr;
    Data_Get_Struct(self, wxRadioButton, ptr);
    return (ptr->GetValue() ? Qtrue : Qfalse);
}

void
WxRadioButton::SetValue(VALUE self,VALUE vvalue)
{
    bool value = (vvalue == Qtrue);
    wxRadioButton *ptr;
    Data_Get_Struct(self, wxRadioButton, ptr);
    ptr->SetValue(value);
}

VALUE WxRadioButton::rubyClass;

class ZAutoDefineWxRadioButton
{
public:
   ZAutoDefineWxRadioButton()
    {
       WxRadioButton::DefineClass();
    }
};
static ZAutoDefineWxRadioButton x2;
