/**********************************************************************

  messagedialog.cpp -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#include "wx.h"
#include "messagedialog.h"
#include "dialog.h"

void WxMessageDialog::DefineClass()
{
	if(rubyClass)
		return;
	WxDialog::DefineClass();
	rubyClass = rb_define_class_under(GetWxModule(),"MessageDialog", WxDialog::rubyClass);
	rb_define_alloc_func(rubyClass,WxMessageDialog::alloc);
	rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new_1), -1);
	rb_define_method(rubyClass, "initialize", VALUEFUNC(WxMessageDialog::init), -1);
	rb_define_method(rubyClass, "show_modal", VALUEFUNC(WxMessageDialog::ShowModal), 0);
}

VALUE
WxMessageDialog::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxMessageDialog::init(int argc, VALUE *argv, VALUE self)
{
    wxWindow* parent = NULL;
    wxString message;
    wxString caption = "Message box";
    long style = wxOK | wxCANCEL | wxCENTRE;
    wxPoint pos = wxDefaultPosition;

    if(argc>0 && TYPE(argv[0])==T_DATA) {
      Data_Get_Struct(argv[0], wxWindow, parent);
    }
    if(argc>1 && TYPE(argv[1])==T_STRING)
      message = wxString(StringValuePtr(argv[1]));
    if(argc>2 && TYPE(argv[2])==T_STRING)
      caption = wxString(StringValuePtr(argv[2]));
    if(argc>3 && TYPE(argv[3])==T_FIXNUM)
      style = NUM2INT(argv[3]);
    if(argc>4 && TYPE(argv[4])==T_DATA) {
        wxPoint *ptr;
	Data_Get_Struct(argv[4], wxPoint, ptr);
	pos = *ptr;
    }

    wxMessageDialog *ptr;
    Data_Get_Struct(self, wxMessageDialog, ptr);
    ptr = new wxMessageDialog(parent,message,caption,style,pos);
    DATA_PTR(self) = ptr;

    return self;
}

VALUE
WxMessageDialog::ShowModal(VALUE self)
{
    wxMessageDialog *ptr;
    Data_Get_Struct(self, wxMessageDialog, ptr);
    return INT2NUM(ptr->ShowModal());
}

VALUE WxMessageDialog::rubyClass;

class ZAutoDefineWxMessageDialog
{
public:
   ZAutoDefineWxMessageDialog()
    {
       WxMessageDialog::DefineClass();
    }
};
static ZAutoDefineWxMessageDialog x;
