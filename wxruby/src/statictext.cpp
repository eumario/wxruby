/**********************************************************************

  statictext.cpp -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#include "wx.h"
#include "statictext.h"
#include "control.h"

void WxStaticText::DefineClass()
{
	if(rubyClass)
		return;
	WxControl::DefineClass();
	rubyClass = rb_define_class_under(GetWxModule(),"StaticText", WxControl::rubyClass);
	rb_define_alloc_func(rubyClass,WxStaticText::alloc);
	rb_define_singleton_method(rubyClass, "new", VALUEFUNC(wrapNew), -1);
	rb_define_method(rubyClass, "initialize", VALUEFUNC(WxStaticText::init), -1);
	rb_define_method(rubyClass, "set_label", VALUEFUNC(WxStaticText::SetLabel), 1);
	rb_define_method(rubyClass, "set_font", VALUEFUNC(WxStaticText::SetFont), 1);
}

VALUE
WxStaticText::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE WxStaticText::wrapNew(int argc, VALUE *argv, VALUE self)
{
    VALUE res = rb_funcall2(self, rb_intern("allocate"), 0, 0);
    rb_obj_call_init(res, argc, argv);
    return res;
}

VALUE
WxStaticText::init(int argc, VALUE *argv, VALUE self)
{
    wxWindow *parent = 0;
    wxWindowID id = -1;
    wxString label;
    wxPoint pos = wxDefaultPosition;
    wxSize size = wxDefaultSize;
    long style = 0;
    wxString name = wxStaticTextNameStr;

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
    if(argc>6 && TYPE(argv[6])==T_STRING)
      name = wxString(StringValuePtr(argv[6]));

    wxStaticText *ptr;
    Data_Get_Struct(self, wxStaticText, ptr);
    ptr = new wxStaticText(parent,id,label,pos,size,style,name);

    VALUE vdata = rb_hash_new();
    rb_hash_aset(vdata,rb_str_new2("self"),self);
    ptr->SetClientData((void*)vdata);

    DATA_PTR(self) = ptr;

    return self;
}

void
WxStaticText::SetLabel(VALUE self,VALUE vlabel)
{
    wxString label = wxString(StringValuePtr(vlabel));
    wxStaticText *ptr;
    Data_Get_Struct(self, wxStaticText, ptr);
    ptr->SetLabel(label);
}

void
WxStaticText::SetFont(VALUE self,VALUE vfont)
{
    wxFont *font;
    Data_Get_Struct(vfont, wxFont, font);
    wxStaticText *ptr;
    Data_Get_Struct(self, wxStaticText, ptr);
    ptr->SetFont(*font);
}

VALUE WxStaticText::rubyClass;

class ZAutoDefineWxStaticText
{
public:
   ZAutoDefineWxStaticText()
    {
       WxStaticText::DefineClass();
    }
};
static ZAutoDefineWxStaticText x1;

//------------------------------------------------------------------------
void WxStaticBox::DefineClass()
{
	if(rubyClass)
		return;
	WxControl::DefineClass();
	rubyClass = rb_define_class_under(GetWxModule(),"StaticBox", WxControl::rubyClass);
	rb_define_alloc_func(rubyClass,WxStaticBox::alloc);
	rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new_1), -1);
	rb_define_method(rubyClass, "initialize", VALUEFUNC(WxStaticBox::init), -1);
}

VALUE
WxStaticBox::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxStaticBox::init(int argc, VALUE *argv, VALUE self)
{
    wxWindow *parent = 0;
    wxWindowID id = -1;
    wxString label;
    wxPoint pos = wxDefaultPosition;
    wxSize size = wxDefaultSize;
    long style = 0;
    wxString name = "staticBox";

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
    if(argc>6 && TYPE(argv[6])==T_STRING)
      name = wxString(StringValuePtr(argv[6]));

    wxStaticBox *ptr;
    Data_Get_Struct(self, wxStaticBox, ptr);
    ptr = new wxStaticBox(parent,id,label,pos,size,style,name);

    VALUE vdata = rb_hash_new();
    rb_hash_aset(vdata,rb_str_new2("self"),self);
    ptr->SetClientData((void*)vdata);

    DATA_PTR(self) = ptr;

    return self;
}

VALUE WxStaticBox::rubyClass;

class ZAutoDefineWxStaticBox
{
public:
   ZAutoDefineWxStaticBox()
    {
       WxStaticBox::DefineClass();
    }
};
static ZAutoDefineWxStaticBox x2;

//--------------------------------------------------------------------------------
void WxStaticLine::DefineClass()
{
	if(rubyClass)
		return;
	WxControl::DefineClass();
	rubyClass = rb_define_class_under(GetWxModule(),"StaticLine", WxControl::rubyClass);
	rb_define_alloc_func(rubyClass,WxStaticLine::alloc);
	rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new_1), -1);
	rb_define_method(rubyClass, "initialize", VALUEFUNC(WxStaticLine::init), -1);
}

VALUE
WxStaticLine::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxStaticLine::init(int argc, VALUE *argv, VALUE self)
{
    wxWindow *parent = 0;
    wxWindowID id = -1;
    wxPoint pos = wxDefaultPosition;
    wxSize size = wxDefaultSize;
    long style = wxLI_HORIZONTAL;
    wxString name = "staticLine";

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
    if(argc>5 && TYPE(argv[5])==T_STRING)
      name = wxString(StringValuePtr(argv[5]));

    wxStaticLine *ptr;
    Data_Get_Struct(self, wxStaticLine, ptr);
    ptr = new wxStaticLine(parent,id,pos,size,style,name);

    VALUE vdata = rb_hash_new();
    rb_hash_aset(vdata,rb_str_new2("self"),self);
    ptr->SetClientData((void*)vdata);

    DATA_PTR(self) = ptr;

    return self;
}

VALUE WxStaticLine::rubyClass;

class ZAutoDefineWxStaticLine
{
public:
   ZAutoDefineWxStaticLine()
    {
       WxStaticLine::DefineClass();
    }
};
static ZAutoDefineWxStaticLine x3;
