/**********************************************************************

  menubar.cpp -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#include "wx.h"
#include "menubar.h"

void WxMenuBar::DefineClass()
{
	if(rubyClass)
		return;
	rubyClass = rb_define_class_under(GetWxModule(),"MenuBar", rb_cObject);
	rb_define_alloc_func(rubyClass,WxMenuBar::alloc);
	rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new_1), -1);
	rb_define_method(rubyClass, "initialize", VALUEFUNC(WxMenuBar::init), -1);
	rb_define_method(rubyClass, "append", VALUEFUNC(WxMenuBar::Append), -1);
	rb_define_method(rubyClass, "check", VALUEFUNC(WxMenuBar::Check), 2);
	rb_define_method(rubyClass, "is_checked", VALUEFUNC(WxMenuBar::IsChecked), 1);
}

VALUE
WxMenuBar::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxMenuBar::init(int argc, VALUE *argv, VALUE self)
{
    long style = 0;
    if(argc>0) style = NUM2INT(argv[0]);
    wxMenuBar *ptr;
    Data_Get_Struct(self, wxMenuBar, ptr);
    ptr = new wxMenuBar(style);
    DATA_PTR(self) = ptr;

    return self;
}

void WxMenuBar::Append(int argc, VALUE *argv, VALUE self)
{
    wxMenu *menu;
    Data_Get_Struct(argv[0],wxMenu,menu);
    wxString title = StringValuePtr(argv[1]);
    wxMenuBar *ptr;
    Data_Get_Struct(self, wxMenuBar, ptr);
    ptr->Append(menu,title);
}

void
WxMenuBar::Check(VALUE self,VALUE vid,VALUE vcheck)
{
    int id = NUM2INT(vid);
    bool check = (vcheck==Qtrue);
    wxMenuBar *ptr;
    Data_Get_Struct(self, wxMenuBar, ptr);
    ptr->Check(id,check);
}

VALUE
WxMenuBar::init0(wxMenuBar *menubar)
{
    VALUE self = Data_Wrap_Struct(rubyClass, 0, 0, 0);
    DATA_PTR(self) = menubar;
    return self;
}

VALUE
WxMenuBar::IsChecked(VALUE self,VALUE vid)
{
    int id = NUM2INT(vid);
    wxMenuBar *ptr;
    Data_Get_Struct(self, wxMenuBar, ptr);
    return (ptr->IsChecked(id) ? Qtrue : Qfalse);
}

VALUE WxMenuBar::rubyClass;

class ZAutoDefineWxMenuBar
{
public:
   ZAutoDefineWxMenuBar()
    {
       WxMenuBar::DefineClass();
    }
};
static ZAutoDefineWxMenuBar x;
