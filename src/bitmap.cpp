/**********************************************************************

  bitmap.cpp -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#include "wx.h"
#include "bitmap.h"
#include "mask.h"
#include "image.h"

void WxBitmap::DefineClass()
{
	if(rubyClass)
		return;
	rubyClass = rb_define_class_under(GetWxModule(),"Bitmap", rb_cObject);
	rb_define_alloc_func(rubyClass,WxBitmap::alloc);
	rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new_1), -1);
	rb_define_method(rubyClass, "initialize", VALUEFUNC(WxBitmap::init), -1);
	rb_define_method(rubyClass, "get_width", VALUEFUNC(WxBitmap::GetWidth), 0);
	rb_define_method(rubyClass, "get_height", VALUEFUNC(WxBitmap::GetHeight), 0);
	rb_define_method(rubyClass, "ok", VALUEFUNC(WxBitmap::Ok), 0);
	rb_define_method(rubyClass, "set_mask", VALUEFUNC(WxBitmap::SetMask), 1);
	rb_define_method(rubyClass, "get_mask", VALUEFUNC(WxBitmap::GetMask), 0);
	rb_define_method(rubyClass, "convert_to_image", VALUEFUNC(WxBitmap::ConvertToImage), 0);
}

VALUE
WxBitmap::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxBitmap::init(int argc, VALUE *argv, VALUE self)
{
    wxBitmap *ptr;
    Data_Get_Struct(self, wxBitmap, ptr);
    if(TYPE(argv[0])==T_FIXNUM) {
        int width = NUM2INT(argv[0]);
        int height = NUM2INT(argv[1]);
        int depth = -1;
        if(argc>2) depth = NUM2INT(argv[2]);
        ptr = new wxBitmap(width,height,depth);
    } else if(TYPE(argv[0])==T_DATA && strstr(rb_class2name(CLASS_OF(argv[0])),"Image")) {
        wxImage *image;
        int depth = -1;
        Data_Get_Struct(argv[0], wxImage, image);
        if(argc>1) depth = NUM2INT(argv[1]);
        ptr = new wxBitmap(*image,depth);
    } else if(TYPE(argv[0])==T_DATA) {
        wxBitmap *bmp;
        Data_Get_Struct(argv[0], wxBitmap, bmp);
        ptr = new wxBitmap(*bmp);
    } else {
        wxString name = StringValuePtr(argv[0]);
        // Note: We really shouldn't have ANY default here, 
        // but this was the quickest way to safely get rid 
        // of the compile warning
        wxBitmapType type = wxBITMAP_TYPE_XPM;
        if(argc>1 && TYPE(argv[1])==T_FIXNUM)
          type = (wxBitmapType)NUM2INT(argv[1]);
        else if(strstr(StringValuePtr(argv[0]),".xpm"))
          type = wxBITMAP_TYPE_XPM;
        else if(strstr(StringValuePtr(argv[0]),".ico"))
          type = wxBITMAP_TYPE_ICO;
        ptr = new wxBitmap(name,type);
    }
    DATA_PTR(self) = ptr;

    return self;
}

VALUE
WxBitmap::init0(const wxBitmap &bitmap)
{
    VALUE self = Data_Wrap_Struct(rubyClass, 0, 0, 0);
    if(bitmap==wxNullBitmap)
      DATA_PTR(self) = &wxNullBitmap;
    else
      DATA_PTR(self) = new wxBitmap(bitmap);
    return self;
}

VALUE
WxBitmap::GetWidth(VALUE self)
{
    wxBitmap *ptr;
    Data_Get_Struct(self, wxBitmap, ptr);
    return INT2NUM(ptr->GetWidth());
}

VALUE
WxBitmap::GetHeight(VALUE self)
{
    wxBitmap *ptr;
    Data_Get_Struct(self, wxBitmap, ptr);
    return INT2NUM(ptr->GetHeight());
}

VALUE
WxBitmap::Ok(VALUE self)
{
    wxBitmap *ptr;
    Data_Get_Struct(self, wxBitmap, ptr);
    return (ptr->Ok() ? Qtrue : Qfalse);
}

void
WxBitmap::SetMask(VALUE self,VALUE vmask)
{
    wxMask* mask;
    Data_Get_Struct(vmask, wxMask, mask);
    wxBitmap *ptr;
    Data_Get_Struct(self, wxBitmap, ptr);
    ptr->SetMask(mask);
}

VALUE
WxBitmap::GetMask(VALUE self)
{
    wxBitmap *ptr;
    Data_Get_Struct(self, wxBitmap, ptr);
    return WxMask::init0(ptr->GetMask());
}

VALUE
WxBitmap::ConvertToImage(VALUE self)
{
    wxBitmap *ptr;
    Data_Get_Struct(self, wxBitmap, ptr);
    wxImage *image = new wxImage(ptr->ConvertToImage());
    return WxImage::init0(*image);
}

VALUE WxBitmap::rubyClass;

class ZAutoDefineWxBitmap
{
public:
   ZAutoDefineWxBitmap()
    {
       WxBitmap::DefineClass();
    }
};
static ZAutoDefineWxBitmap x1;
