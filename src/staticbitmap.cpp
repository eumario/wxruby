/**********************************************************************

  staticbitmap.cpp -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#include "wx.h"
#include "staticbitmap.h"
#include "window.h"

void WxStaticBitmap::DefineClass()
{
    if(rubyClass)
        return;
    WxWindow::DefineClass();
    rubyClass = rb_define_class_under(GetWxModule(),"StaticBitmap", WxWindow::rubyClass);
    rb_define_alloc_func(rubyClass,WxStaticBitmap::alloc);
    rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new_1), -1);
    rb_define_method(rubyClass, "initialize", VALUEFUNC(WxStaticBitmap::init), -1);
    rb_define_method(rubyClass, "set_bitmap", VALUEFUNC(WxStaticBitmap::SetBitmap), 1);
}

VALUE
WxStaticBitmap::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxStaticBitmap::init(int argc, VALUE *argv, VALUE self)
{
    wxWindow* parent = NULL;
    wxWindowID id = -1;
    wxBitmap label;
    wxPoint pos = wxDefaultPosition;
    wxSize size = wxDefaultSize;
    long style = 0;
    wxString name = "staticBitmap";

    if(argc>0 && TYPE(argv[0])==T_DATA) {
	    Data_Get_Struct(argv[0], wxWindow, parent);
    }
    if(argc>1 && TYPE(argv[1])==T_FIXNUM)
        id = NUM2INT(argv[1]);
    if(argc>2 && TYPE(argv[2])==T_DATA) {
        wxBitmap *ptr;
	    Data_Get_Struct(argv[2], wxBitmap, ptr);
	    label = *ptr;
    }
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

    wxStaticBitmap *ptr;
    Data_Get_Struct(self, wxStaticBitmap, ptr);
    ptr = new wxStaticBitmap(parent,id,label,pos,size,style,name);

    VALUE vdata = rb_hash_new();
    rb_hash_aset(vdata,rb_str_new2("self"),self);
    ptr->SetClientData((void*)vdata);

    DATA_PTR(self) = ptr;

    return self;
}

void
WxStaticBitmap::SetBitmap(VALUE self,VALUE vlabel)
{
    wxBitmap *label;
    Data_Get_Struct(vlabel, wxBitmap, label);
    wxStaticBitmap *ptr;
    Data_Get_Struct(self, wxStaticBitmap, ptr);
    ptr->SetBitmap(*label);
}

VALUE WxStaticBitmap::rubyClass;

class ZAutoDefineWxStaticBitmap
{
public:
   ZAutoDefineWxStaticBitmap()
    {
       WxStaticBitmap::DefineClass();
    }
};
static ZAutoDefineWxStaticBitmap x2;
