/**********************************************************************

  icon.cpp -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#include "wx.h"
#include "icon.h"
#include "bitmap.h"

#ifdef __WXMSW__
#include "wx/msw/private.h"
#endif

void WxIcon::DefineClass()
{
	if(rubyClass)
		return;
	WxBitmap::DefineClass();
	rubyClass = rb_define_class_under(GetWxModule(),"Icon", WxBitmap::rubyClass);
	rb_define_alloc_func(rubyClass,WxIcon::alloc);
	rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new_1), -1);
	rb_define_method(rubyClass, "initialize", VALUEFUNC(WxIcon::init), -1);
	rb_define_method(rubyClass, "ok", VALUEFUNC(WxIcon::Ok), 0);
	rb_define_method(rubyClass, "copy_from_bitmap", VALUEFUNC(WxIcon::CopyFromBitmap), 1);
	rb_define_method(rubyClass, "get_depth", VALUEFUNC(WxIcon::GetDepth), 0);
	rb_define_method(rubyClass, "get_height", VALUEFUNC(WxIcon::GetHeight), 0);
	rb_define_method(rubyClass, "get_width", VALUEFUNC(WxIcon::GetWidth), 0);
	rb_define_method(rubyClass, "load_file", VALUEFUNC(WxIcon::LoadFile), 2);
	rb_define_method(rubyClass, "set_depth", VALUEFUNC(WxIcon::SetDepth), 1);
	rb_define_method(rubyClass, "set_height", VALUEFUNC(WxIcon::SetHeight), 1);
//    rb_define_method(rubyClass, "set_ok", VALUEFUNC(WxIcon::SetOk), 1);
	rb_define_method(rubyClass, "set_width", VALUEFUNC(WxIcon::SetWidth), 1);
}

VALUE
WxIcon::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxIcon::init(int argc, VALUE *argv, VALUE self)
{
    wxString name;
    long type = 0;
    int desiredWidth = -1;
    int desiredHeight = -1;

    wxIcon *ptr;
    Data_Get_Struct(self, wxIcon, ptr);
    if(argc==0) {
        ptr = new wxIcon();
    }
    else if(argc>0 && TYPE(argv[0])==T_STRING) {
    	name = StringValuePtr(argv[0]);
        if(argc>1 && TYPE(argv[1])==T_FIXNUM)
          type = (wxBitmapType)NUM2INT(argv[1]);
        else if(strstr(StringValuePtr(argv[0]),".xpm"))
          type = wxBITMAP_TYPE_XPM;
        else if(strstr(StringValuePtr(argv[0]),".ico"))
          type = wxBITMAP_TYPE_ICO;
    	if(argc>2 && TYPE(argv[2])==T_FIXNUM)
    	  desiredWidth = NUM2INT(argv[2]);
    	if(argc>3 && TYPE(argv[3])==T_FIXNUM)
    	  desiredHeight = NUM2INT(argv[3]);
        if(type == wxBITMAP_TYPE_XPM) {
          ptr = new wxIcon();
          ptr->CopyFromBitmap(wxBitmap(name,(wxBitmapType)type));
        } else
          ptr = new wxIcon(name,type,desiredWidth,desiredHeight);
    } else if(argc==1 && TYPE(argv[0])==T_DATA) {
        wxIcon *tptr;
        Data_Get_Struct(argv[0], wxIcon, tptr);
      	ptr = new wxIcon(*tptr);
    }
    DATA_PTR(self) = ptr;
    return self;
}


VALUE
WxIcon::Ok(VALUE self)
{
    wxIcon *ptr;
    Data_Get_Struct(self, wxIcon, ptr);
    return (ptr->Ok() ? Qtrue : Qfalse);
}

void
WxIcon::CopyFromBitmap(VALUE self,VALUE vbmp)
{
    wxBitmap *bmp;
    Data_Get_Struct(vbmp, wxBitmap, bmp);
    wxIcon *ptr;
    Data_Get_Struct(self, wxIcon, ptr);
    ptr->CopyFromBitmap(*bmp);
}

VALUE
WxIcon::GetDepth(VALUE self)
{
    wxIcon *ptr;
    Data_Get_Struct(self, wxIcon, ptr);
    return INT2NUM(ptr->GetDepth());
}

VALUE
WxIcon::GetHeight(VALUE self)
{
    wxIcon *ptr;
    Data_Get_Struct(self, wxIcon, ptr);
    return INT2NUM(ptr->GetHeight());
}

VALUE
WxIcon::GetWidth(VALUE self)
{
    wxIcon *ptr;
    Data_Get_Struct(self, wxIcon, ptr);
    return INT2NUM(ptr->GetWidth());
}

VALUE
WxIcon::LoadFile(VALUE self,VALUE vname,VALUE vtype)
{
    wxString name;
    long type;
    wxIcon *ptr;
    Data_Get_Struct(self, wxIcon, ptr);
  	name = StringValuePtr(vname);
    type = NUM2INT(vtype);
    return (ptr->LoadFile(name,type) ? Qtrue : Qfalse);
}

void
WxIcon::SetDepth(VALUE self,VALUE vdepth)
{
    int depth = NUM2INT(vdepth);
    wxIcon *ptr;
    Data_Get_Struct(self, wxIcon, ptr);
    ptr->SetDepth(depth);
}

void
WxIcon::SetHeight(VALUE self,VALUE vheight)
{
    int height = NUM2INT(vheight);
    wxIcon *ptr;
    Data_Get_Struct(self, wxIcon, ptr);
    ptr->SetHeight(height);
}

/*
void
WxIcon::SetOk(VALUE self,VALUE visOk)
{
    int isOk = NUM2INT(visOk);
    wxIcon *ptr;
    Data_Get_Struct(self, wxIcon, ptr);
    ptr->SetOk(isOk);
}
*/

void
WxIcon::SetWidth(VALUE self,VALUE vwidth)
{
    int width = NUM2INT(vwidth);
    wxIcon *ptr;
    Data_Get_Struct(self, wxIcon, ptr);
    ptr->SetWidth(width);
}


VALUE
WxIcon::init0(const wxIcon &icon)
{
    static VALUE self = Data_Wrap_Struct(rubyClass, 0, 0, 0);
    DATA_PTR(self) = new wxIcon(icon);
    return self;
}

VALUE WxIcon::rubyClass;

class ZAutoDefine
{
public:
   ZAutoDefine()
    {
       WxIcon::DefineClass();
    }
};
static ZAutoDefine x;
