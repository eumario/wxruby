/**********************************************************************

  panel.cpp -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#include "wx.h"
#include "panel.h"
#include "button.h"
#include "window.h"

void WxPanel::DefineClass()
{
	if(rubyClass)
		return;
	WxWindow::DefineClass();
	rubyClass = rb_define_class_under(GetWxModule(),"Panel", WxWindow::rubyClass);
	rb_define_alloc_func(rubyClass,WxPanel::alloc);
	rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new_1), -1);
	rb_define_method(rubyClass, "initialize", VALUEFUNC(WxPanel::init), -1);
	rb_define_method(rubyClass, "get_default_item", VALUEFUNC(WxPanel::GetDefaultItem), 0);
	rb_define_method(rubyClass, "init_dialog", VALUEFUNC(WxPanel::InitDialog), 0);
	rb_define_method(rubyClass, "set_default_item", VALUEFUNC(WxPanel::SetDefaultItem), 1);
}

VALUE
WxPanel::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxPanel::init(int argc, VALUE *argv, VALUE self)
{
    wxWindow* parent;
    wxWindowID id = -1;
    wxPoint pos = wxDefaultPosition;
    wxSize size = wxDefaultSize;
    long style = wxTAB_TRAVERSAL;
    wxString name = "panel";

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

    wxPanel *ptr;
    Data_Get_Struct(self, wxPanel, ptr);
    ptr = new wxPanel(parent,id,pos,size,style,name);

    VALUE vdata = rb_hash_new();
    rb_hash_aset(vdata,rb_str_new2("self"),self);
    ptr->SetClientData((void*)vdata);

    DATA_PTR(self) = ptr;

    return self;
}


VALUE
WxPanel::GetDefaultItem(VALUE self)
{
    wxPanel *ptr;
    Data_Get_Struct(self, wxPanel, ptr);
    return WxButton::init0((wxButton*)ptr->GetDefaultItem());
}

void
WxPanel::InitDialog(VALUE self)
{
    wxPanel *ptr;
    Data_Get_Struct(self, wxPanel, ptr);
    ptr->InitDialog();
}

void
WxPanel::SetDefaultItem(VALUE self,VALUE vbtn)
{
    wxButton *btn;
    Data_Get_Struct(vbtn, wxButton, btn);
    wxPanel *ptr;
    Data_Get_Struct(self, wxPanel, ptr);
    ptr->SetDefaultItem(btn);
}

VALUE WxPanel::rubyClass;

class ZAutoDefine
{
public:
   ZAutoDefine()
    {
       WxPanel::DefineClass();
    }
};
static ZAutoDefine x;
