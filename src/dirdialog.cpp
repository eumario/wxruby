/**********************************************************************

  dirdialog.cpp -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#include "wx.h"
#include "dirdialog.h"
#include "dialog.h"

void WxDirDialog::DefineClass()
{
	if(rubyClass)
		return;
	WxDialog::DefineClass();
	rubyClass = rb_define_class_under(GetWxModule(),"DirDialog", WxDialog::rubyClass);
	rb_define_alloc_func(rubyClass,WxDirDialog::alloc);
	rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new_1), -1);
	rb_define_method(rubyClass, "initialize", VALUEFUNC(WxDirDialog::init), -1);
	rb_define_method(rubyClass, "show_modal", VALUEFUNC(WxDirDialog::ShowModal), 0);
	rb_define_method(rubyClass, "get_path", VALUEFUNC(WxDirDialog::GetPath), 0);
}

VALUE
WxDirDialog::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxDirDialog::init(int argc, VALUE *argv, VALUE self)
{
    wxWindow* parent = 0;
    wxString message = "Choose a directory";
    wxString defaultPath = "";
    long style = 0;
    wxPoint pos = wxDefaultPosition;
    wxSize size = wxDefaultSize;
    wxString name = "wxDirCtrl";

    if(argc>0 && TYPE(argv[0])==T_DATA) {
      Data_Get_Struct(argv[0], wxWindow, parent);
    }
    if(argc>1 && TYPE(argv[1])==T_STRING)
      message = wxString(StringValuePtr(argv[1]));
    if(argc>2 && TYPE(argv[2])==T_STRING)
      defaultPath = wxString(StringValuePtr(argv[2]));
    if(argc>3 && TYPE(argv[3])==T_FIXNUM)
      style = NUM2INT(argv[3]);
    if(argc>4 && TYPE(argv[4])==T_DATA) {
        wxPoint *ptr;
	Data_Get_Struct(argv[4], wxPoint, ptr);
	pos = *ptr;
    }
    if(argc>5 && TYPE(argv[5])==T_DATA) {
        wxSize *ptr;
	Data_Get_Struct(argv[5], wxSize, ptr);
	size = *ptr;
    }
    if(argc>6 && TYPE(argv[6])==T_STRING)
      name = wxString(StringValuePtr(argv[6]));

    wxDirDialog *ptr;
    Data_Get_Struct(self, wxDirDialog, ptr);
    ptr = new wxDirDialog(parent,message,defaultPath,style,pos,size,name);
    DATA_PTR(self) = ptr;

    return self;
}

VALUE
WxDirDialog::ShowModal(VALUE self)
{
    wxDirDialog *ptr;
    Data_Get_Struct(self, wxDirDialog, ptr);
    return INT2NUM(ptr->ShowModal());
}

VALUE
WxDirDialog::GetPath(VALUE self)
{
    wxDirDialog *ptr;
    Data_Get_Struct(self, wxDirDialog, ptr);
    return rb_str_new2((const char*)ptr->GetPath());
}

VALUE WxDirDialog::rubyClass;

class ZAutoDefine
{
public:
   ZAutoDefine()
    {
       WxDirDialog::DefineClass();
    }
};
static ZAutoDefine x;
