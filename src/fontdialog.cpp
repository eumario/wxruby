/**********************************************************************

  fontdialog.cpp -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#include "wx.h"

// this is a bad hack, but on Mac OS X we need to use
// the generic font dialog
#if !(defined(__WXGTK__) || defined(__WXMSW__))
#define __WXUNIVERSAL__
#endif
#include "wx/fontdlg.h"
#if !(defined(__WXGTK__) || defined(__WXMSW__))
#undef __WXUNIVERSAL__
#endif
// end bad hack

#include "fontdata.h"
#include "fontdialog.h"
#include "dialog.h"


void WxFontDialog::DefineClass()
{
	if(rubyClass)
		return;
	WxDialog::DefineClass();
	rubyClass = rb_define_class_under(GetWxModule(),"FontDialog", WxDialog::rubyClass);
	rb_define_alloc_func(rubyClass,WxFontDialog::alloc);
	rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new_1), -1);
	rb_define_method(rubyClass, "initialize", VALUEFUNC(WxFontDialog::init), -1);
	rb_define_method(rubyClass, "show_modal", VALUEFUNC(WxFontDialog::ShowModal), 0);
	rb_define_method(rubyClass, "get_font_data", VALUEFUNC(WxFontDialog::GetFontData), 0);
}

VALUE
WxFontDialog::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}


VALUE
WxFontDialog::init(int argc, VALUE *argv, VALUE self)
{
    wxWindow *parent = 0;
    wxFontData *data = 0;
    if(argc>0 && TYPE(argv[0])==T_DATA) {
      Data_Get_Struct(argv[0], wxWindow, parent);
    }
    if(argc>1 && TYPE(argv[1])==T_DATA) {
      Data_Get_Struct(argv[1], wxFontData, data);
    }
    wxFontDialog *ptr;
    Data_Get_Struct(self, wxFontDialog, ptr);
    if(argc==1)
// YUCK! The Generic FontDialog doesn't have a constructor that 
// only takes one parameter
#if !(defined(__WXGTK__) || defined(__WXMSW__))
      ptr = new wxFontDialog(parent);
#else
	  rb_raise(rb_intern("RuntimeError"), 
			"On this platform, FontDialog.new requires two parameters");
#endif
    else if(argc==2)
      ptr = new wxFontDialog(parent,*data);
    else
      ptr = new wxFontDialog();
    DATA_PTR(self) = ptr;

    return self;
}

VALUE
WxFontDialog::ShowModal(VALUE self)
{
    wxFontDialog *ptr;
    Data_Get_Struct(self, wxFontDialog, ptr);
    return INT2NUM(ptr->ShowModal());
}


VALUE
WxFontDialog::GetFontData(VALUE self)
{
    wxFontDialog *ptr;
    Data_Get_Struct(self, wxFontDialog, ptr);
    return WxFontData::init0(ptr->GetFontData());
}

VALUE WxFontDialog::rubyClass;

class ZAutoDefine
{
public:
   ZAutoDefine()
    {
       WxFontDialog::DefineClass();
    }
};
static ZAutoDefine x;
