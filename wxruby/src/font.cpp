/**********************************************************************

  font.cpp -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#include "wx.h"
#include "font.h"

void WxFont::DefineClass()
{
	if(rubyClass)
		return;
	rubyClass = rb_define_class_under(GetWxModule(),"Font", rb_cObject);
	rb_define_alloc_func(rubyClass,WxFont::alloc);
	rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new_1), -1);
	rb_define_method(rubyClass, "initialize", VALUEFUNC(WxFont::init), -1);
}

VALUE
WxFont::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxFont::init(int argc, VALUE *argv, VALUE self)
{
    wxFont *ptr;
    if(argc==0) {
      Data_Get_Struct(self, wxFont, ptr);
      ptr = new wxFont();
    } else {
      int pointSize = NUM2INT(argv[0]);
      int family = NUM2INT(argv[1]);
      int style = NUM2INT(argv[2]);
      int weight = NUM2INT(argv[3]);
      bool underline = FALSE;
      wxString faceName = "";
      wxFontEncoding encoding = wxFONTENCODING_DEFAULT;
      if(argc>4 && argv[4]==Qtrue) underline = TRUE;
      if(argc>5 && TYPE(argv[5])==T_STRING) {
        faceName = StringValuePtr(argv[5]);
      }
      if(argc>6 && TYPE(argv[6])==T_FIXNUM) {
        encoding = (wxFontEncoding)NUM2INT(argv[6]);
      }
      ptr = new wxFont(pointSize,family,style,weight,underline,faceName,encoding);
    }
    DATA_PTR(self) = ptr;
    return self;
}

VALUE
WxFont::init0(const wxFont &font)
{
    wxFont *ptr;
    VALUE self = Data_Wrap_Struct(rubyClass, 0, 0, 0);
    ptr = new wxFont();
    *ptr = font;
    DATA_PTR(self) = ptr;
    return self;
}

VALUE WxFont::rubyClass;

class ZAutoDefine
{
public:
   ZAutoDefine()
    {
       WxFont::DefineClass();
    }
};
static ZAutoDefine x;
