/**********************************************************************

  statusbar.cpp -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#include "wx.h"
#include "statusbar.h"
#include "rect.h"
#include "window.h"

void WxStatusBar::DefineClass()
{
	if(rubyClass)
		return;
	WxWindow::DefineClass();
	rubyClass = rb_define_class_under(GetWxModule(),"StatusBar", WxWindow::rubyClass);
	rb_define_alloc_func(rubyClass,WxStatusBar::alloc);
	rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new_1), -1);
	rb_define_method(rubyClass, "initialize", VALUEFUNC(WxStatusBar::init), -1);
	rb_define_method(rubyClass, "get_field_rect", VALUEFUNC(WxStatusBar::GetFieldRect), 1);
	rb_define_method(rubyClass, "get_fields_count", VALUEFUNC(WxStatusBar::GetFieldsCount), -1);
	rb_define_method(rubyClass, "get_status_text", VALUEFUNC(WxStatusBar::GetStatusText), -1);
	rb_define_method(rubyClass, "pop_status_text", VALUEFUNC(WxStatusBar::PopStatusText), -1);
	rb_define_method(rubyClass, "push_status_text", VALUEFUNC(WxStatusBar::PushStatusText), -1);
	rb_define_method(rubyClass, "set_fields_count", VALUEFUNC(WxStatusBar::SetFieldsCount), -1);
	rb_define_method(rubyClass, "set_min_height", VALUEFUNC(WxStatusBar::SetMinHeight), 1);
	rb_define_method(rubyClass, "set_status_text", VALUEFUNC(WxStatusBar::SetStatusText), -1);
	rb_define_method(rubyClass, "set_status_widths", VALUEFUNC(WxStatusBar::SetStatusWidths), 1);
}

VALUE
WxStatusBar::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxStatusBar::init(int argc, VALUE *argv, VALUE self)
{
    wxWindow* parent;
    wxWindowID id;
    long style = wxST_SIZEGRIP;
    wxString name = "statusBar";

    if(NIL_P(argv[0])) parent = NULL;
    else {
        Data_Get_Struct(argv[0], wxWindow, parent);
    }
    id = NUM2INT(argv[1]);
    if(argc>2) style = NUM2INT(argv[2]);
    if(argc>3) name = StringValuePtr(argv[3]);
    wxStatusBar *ptr;
    Data_Get_Struct(self, wxStatusBar, ptr);
    ptr = new wxStatusBar(parent,id,style,name);

    VALUE vdata = rb_hash_new();
    rb_hash_aset(vdata,rb_str_new2("self"),self);
    ptr->SetClientData((void*)vdata);

    DATA_PTR(self) = ptr;
    return self;
}

VALUE
WxStatusBar::GetFieldRect(VALUE self,VALUE vi)
{
    int i = NUM2INT(vi);
    wxRect rect;
    wxStatusBar *ptr;
    Data_Get_Struct(self, wxStatusBar, ptr);
    bool r = ptr->GetFieldRect(i,rect);
    if(r) return WxRect::init0(rect);
    else return Qnil;
}

VALUE
WxStatusBar::GetFieldsCount(VALUE self)
{
    wxStatusBar *ptr;
    Data_Get_Struct(self, wxStatusBar, ptr);
    return INT2NUM(ptr->GetFieldsCount());
}

VALUE
WxStatusBar::GetStatusText(int argc, VALUE *argv, VALUE self)
{
    int ir = 0;
    if(argc>0) ir = NUM2INT(argv[0]);
    wxStatusBar *ptr;
    Data_Get_Struct(self, wxStatusBar, ptr);
    return rb_str_new2(ptr->GetStatusText(ir));
}

void
WxStatusBar::PopStatusText(int argc, VALUE *argv, VALUE self)
{
    int field = 0;
    if(argc>0) field = NUM2INT(argv[0]);
    wxStatusBar *ptr;
    Data_Get_Struct(self, wxStatusBar, ptr);
    ptr->PopStatusText(field);
}

void
WxStatusBar::PushStatusText(int argc, VALUE *argv, VALUE self)
{
    wxString string = StringValuePtr(argv[0]);
    int field = 0;
    if(argc>1) field = NUM2INT(argv[1]);
    wxStatusBar *ptr;
    Data_Get_Struct(self, wxStatusBar, ptr);
    ptr->PushStatusText(string,field);
}

void
WxStatusBar::SetFieldsCount(int argc, VALUE *argv, VALUE self)
{
    int number = 1;
    if(argc>0) number = NUM2INT(argv[0]);
    int* widths = NULL;
    wxStatusBar *ptr;
    Data_Get_Struct(self, wxStatusBar, ptr);
    ptr->SetFieldsCount(number,widths);
}

void
WxStatusBar::SetMinHeight(VALUE self,VALUE vheight)
{
    int height = NUM2INT(vheight);
    wxStatusBar *ptr;
    Data_Get_Struct(self, wxStatusBar, ptr);
    ptr->SetMinHeight(height);
}

void
WxStatusBar::SetStatusText(int argc, VALUE *argv, VALUE self)
{
    wxString text = StringValuePtr(argv[0]);
    int i = 0;
    if(argc>1) i = NUM2INT(argv[1]);
    wxStatusBar *ptr;
    Data_Get_Struct(self, wxStatusBar, ptr);
    ptr->SetStatusText(text,i);
}

void
WxStatusBar::SetStatusWidths(VALUE self,VALUE vwidths)
{
    int n = RARRAY(vwidths)->len;
    int *widths = new int[n];
    for(int i=0;i<n;i++) {
        widths[i] = NUM2INT(RARRAY(vwidths)->ptr[i]);
    }
    wxStatusBar *ptr;
    Data_Get_Struct(self, wxStatusBar, ptr);
    ptr->SetStatusWidths(n,widths);
}

VALUE
WxStatusBar::init0(wxStatusBar *statusbar)
{
    static VALUE self = Data_Wrap_Struct(rubyClass, 0, 0, 0);
    DATA_PTR(self) = (void*)statusbar;
    return self;

}

VALUE WxStatusBar::rubyClass;

class ZAutoDefine
{
public:
   ZAutoDefine()
    {
       WxStatusBar::DefineClass();
    }
};
static ZAutoDefine x;
