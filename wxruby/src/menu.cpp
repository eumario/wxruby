/**********************************************************************

  menu.cpp -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#include "wx.h"
#include "menu.h"

void WxMenu::DefineClass()
{
	if(rubyClass)
		return;
	rubyClass = rb_define_class_under(GetWxModule(),"Menu", rb_cObject);
	rb_define_alloc_func(rubyClass,WxMenu::alloc);
	rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new_1), -1);
	rb_define_method(rubyClass, "initialize", VALUEFUNC(WxMenu::init), -1);
	rb_define_method(rubyClass, "append", VALUEFUNC(WxMenu::Append), -1);
	rb_define_method(rubyClass, "append_item", VALUEFUNC(WxMenu::AppendItem), -1);
	rb_define_method(rubyClass, "append_check_item", VALUEFUNC(WxMenu::AppendCheckItem), -1);
	rb_define_method(rubyClass, "append_radio_item", VALUEFUNC(WxMenu::AppendRadioItem), -1);
	rb_define_method(rubyClass, "append_separator", VALUEFUNC(WxMenu::AppendSeparator), 0);
	rb_define_method(rubyClass, "check", VALUEFUNC(WxMenu::Check), 2);
	rb_define_method(rubyClass, "enable", VALUEFUNC(WxMenu::Enable), 2);
}

VALUE
WxMenu::alloc(VALUE self)
{
   return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxMenu::init(int argc, VALUE *argv, VALUE self)
{
    wxMenu *ptr;
    Data_Get_Struct(self, wxMenu, ptr);
    if(argc==0) {
        ptr = new wxMenu();
    } else if(TYPE(argv[0])==T_STRING) {
        wxString title = StringValuePtr(argv[0]);
        long style = 0;
        if(argc>1) style = NUM2INT(argv[1]);
        ptr = new wxMenu(title,style);
    } else {
        long style = NUM2INT(argv[1]);
        ptr = new wxMenu(style);
    }

    DATA_PTR(self) = ptr;

    return self;
}


VALUE WxMenu::Append(int argc, VALUE *argv, VALUE self)
{
    int id = NUM2INT(argv[0]);
    wxString item = StringValuePtr(argv[1]);
    wxString helpString = "";
    if(argc>2)
      helpString = StringValuePtr(argv[2]);
    wxItemKind kind = wxITEM_NORMAL;
    if(argc>3) kind = (wxItemKind)NUM2INT(argv[3]);

    wxMenu *ptr = 0;
    Data_Get_Struct(self, wxMenu, ptr);
    ptr->Append(id,item,helpString,kind);
	return Qnil;
}

VALUE WxMenu::AppendItem(int argc, VALUE *argv, VALUE self)
{
	VALUE rubyItem = Qnil;
//	int got=rb_scan_args(argc, argv, "10", &rubyItem);
    wxMenuItem* item = 0;
    Data_Get_Struct(rubyItem, wxMenuItem, item);

    wxMenu *ptr;
    Data_Get_Struct(self, wxMenu, ptr);
    ptr->Append(item);
	return Qnil;
}

VALUE WxMenu::AppendCheckItem(int argc, VALUE *argv, VALUE self)
{
    int id = NUM2INT(argv[0]);
    wxString item = StringValuePtr(argv[1]);
    wxString helpString = "";
    if(argc>2)
      helpString = StringValuePtr(argv[2]);
    wxMenu *ptr;
    Data_Get_Struct(self, wxMenu, ptr);
    ptr->AppendCheckItem(id,item,helpString);
	return Qnil;
}

VALUE WxMenu::AppendRadioItem(int argc, VALUE *argv, VALUE self)
{
    int id = NUM2INT(argv[0]);
    wxString item = StringValuePtr(argv[1]);
    wxString helpString = "";
    if(argc>2)
      helpString = StringValuePtr(argv[2]);
    wxMenu *ptr;
    Data_Get_Struct(self, wxMenu, ptr);
    ptr->AppendRadioItem(id,item,helpString);
	return Qnil;
}

VALUE WxMenu::AppendSeparator(VALUE self)
{
    wxMenu *ptr;
    Data_Get_Struct(self, wxMenu, ptr);
    ptr->AppendSeparator();
	return Qnil;
}

VALUE WxMenu::Check(VALUE self,VALUE vid,VALUE vcheck)
{
    int id = NUM2INT(vid);
    bool check = (vcheck == Qtrue);
    wxMenu *ptr;
    Data_Get_Struct(self, wxMenu, ptr);
    ptr->Check(id,check);
	return Qnil;
}

VALUE WxMenu::Enable(VALUE self,VALUE vid,VALUE venable)
{
    int id = NUM2INT(vid);
    bool enable = (venable == Qtrue);
    wxMenu *ptr;
    Data_Get_Struct(self, wxMenu, ptr);
    ptr->Enable(id,enable);
	return Qnil;
}

VALUE WxMenu::rubyClass;

class ZAutoDefine
{
public:
   ZAutoDefine()
    {
       WxMenu::DefineClass();
    }
};
static ZAutoDefine x;
