/**********************************************************************

  list.cpp -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#include "wx.h"
#include "list.h"
#include "bitmap.h"
#include "icon.h"

#ifdef __WXMSW__
#include "wx/msw/private.h"
#endif

void WxList::DefineClass()
{
	if(rubyClass)
		return;
	rubyClass = rb_define_class_under(GetWxModule(),"List", rb_cObject);
	rb_define_alloc_func(rubyClass, alloc);
	rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new_1), -1);
	rb_define_method(rubyClass, "initialize", VALUEFUNC(init), -1);
}


VALUE
WxList::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}


VALUE
WxList::init(int argc, VALUE *argv, VALUE self)
{
    wxList *ptr;
    Data_Get_Struct(self, wxList, ptr);
    if(argc==0) {
        ptr = new wxList();
    }
    else {
    	unsigned int key_type = NUM2INT(argv[0]);
    	ptr = new wxList(key_type);
    }
    DATA_PTR(self) = ptr;

    return self;
}

VALUE
WxList::init0(wxList *list)
{
    static VALUE self = Data_Wrap_Struct(rubyClass, 0, 0, 0);
    DATA_PTR(self) = (void*)list;
    return self;
}

VALUE WxList::rubyClass;

class ZAutoDefineWxList
{
public:
   ZAutoDefineWxList()
    {
       WxList::DefineClass();
    }
};
static ZAutoDefineWxList x;

//-------------------------------------------------------------------------------------------------
void WxImageList::DefineClass()
{
	if(rubyClass)
		return;
	rubyClass = rb_define_class_under(GetWxModule(),"ImageList", rb_cObject);
	rb_define_alloc_func(rubyClass,WxImageList::alloc);
	rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new_1), -1);
	rb_define_method(rubyClass, "initialize", VALUEFUNC(WxImageList::init), -1);
	rb_define_method(rubyClass, "add", VALUEFUNC(WxImageList::Add), -1);
	rb_define_method(rubyClass, "add_with_colour_mask", VALUEFUNC(WxImageList::AddWithColourMask), 2);
	rb_define_method(rubyClass, "draw", VALUEFUNC(WxImageList::Draw), -1);
	rb_define_method(rubyClass, "get_image_count", VALUEFUNC(WxImageList::GetImageCount), 0);
	rb_define_method(rubyClass, "get_size", VALUEFUNC(WxImageList::GetSize), 1);
	rb_define_method(rubyClass, "remove", VALUEFUNC(WxImageList::Remove), 1);
	rb_define_method(rubyClass, "remove_all", VALUEFUNC(WxImageList::RemoveAll), 0);
	rb_define_method(rubyClass, "replace", VALUEFUNC(WxImageList::Replace), -1);
#ifdef __WXMSW__
	rb_define_method(rubyClass, "replace_icon", VALUEFUNC(WxImageList::ReplaceIcon), 2);
#endif

	rb_define_method(rubyClass, "add_icon", VALUEFUNC(WxImageList::Add), -1);
}


VALUE
WxImageList::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxImageList::init(int argc, VALUE *argv, VALUE self)
{
    int width;
    int height;
    bool mask = TRUE;
    int initialCount = 1;

    wxImageList *ptr;
    Data_Get_Struct(self, wxImageList, ptr);
    if(argc==0) {
        ptr = new wxImageList();
    }
    else {
    	width = NUM2INT(argv[0]);
        height = NUM2INT(argv[1]);
    	if(argc>2 && argv[2]==Qfalse)
    	  mask = FALSE;
    	if(argc>3 && TYPE(argv[3])==T_FIXNUM)
    	  initialCount = NUM2INT(argv[3]);
    	ptr = new wxImageList(width,height,mask,initialCount);
    }

    DATA_PTR(self) = ptr;
    return self;
}

VALUE
WxImageList::Add(int argc, VALUE *argv, VALUE self)
{
    wxImageList *ptr;
    Data_Get_Struct(self, wxImageList, ptr);
    if(strstr(rb_class2name(CLASS_OF(argv[0])),"Icon"))
    {
        wxIcon *icon;
        Data_Get_Struct(argv[0], wxIcon, icon);
        return INT2NUM(ptr->Add(*icon));
    } else {
        wxBitmap *bitmap;
        Data_Get_Struct(argv[0], wxBitmap, bitmap);
        wxBitmap mask = wxNullBitmap;
        return INT2NUM(ptr->Add(*bitmap,mask));
    }
}

VALUE
WxImageList::AddWithColourMask(VALUE self,VALUE vbitmap,VALUE vmaskColour)
{
    wxBitmap *bitmap;
    Data_Get_Struct(vbitmap, wxBitmap, bitmap);
    wxColour *maskColour;
    Data_Get_Struct(vmaskColour, wxColour, maskColour);
    wxImageList *ptr;
    Data_Get_Struct(self, wxImageList, ptr);
    return INT2NUM(ptr->Add(*bitmap,*maskColour));
}


VALUE
WxImageList::Draw(int argc, VALUE *argv, VALUE self)
{
    int index = NUM2INT(argv[0]);
    wxDC *dc;
    Data_Get_Struct(argv[1], wxDC, dc);
    int x = NUM2INT(argv[2]);
    int y = NUM2INT(argv[3]);
    int flags = wxIMAGELIST_DRAW_NORMAL;
    if(argc>4) flags = NUM2INT(argv[4]);
    bool solidBackground = FALSE;
    if(argc>5 && argv[5]==Qtrue) solidBackground = TRUE;

    wxImageList *ptr;
    Data_Get_Struct(self, wxImageList, ptr);
    return (ptr->Draw(index,*dc,x,y,flags,solidBackground) ? Qtrue : Qfalse);
}

VALUE
WxImageList::GetImageCount(VALUE self)
{
    wxImageList *ptr;
    Data_Get_Struct(self, wxImageList, ptr);
    return INT2NUM(ptr->GetImageCount());
}

VALUE
WxImageList::GetSize(VALUE self,VALUE vindex)
{
    int index = NUM2INT(vindex);
    int width;
    int height;
    wxImageList *ptr;
    Data_Get_Struct(self, wxImageList, ptr);
    bool result = ptr->GetSize(index,width,height);
    return rb_ary_new3(3,(result ? Qtrue : Qfalse),INT2NUM(width),INT2NUM(height));
}

VALUE
WxImageList::Remove(VALUE self,VALUE vindex)
{
    int index = NUM2INT(vindex);
    wxImageList *ptr;
    Data_Get_Struct(self, wxImageList, ptr);
    return (ptr->Remove(index) ? Qtrue : Qfalse);
}

VALUE
WxImageList::RemoveAll(VALUE self)
{
    wxImageList *ptr;
    Data_Get_Struct(self, wxImageList, ptr);
    return (ptr->RemoveAll() ? Qtrue : Qfalse);
}

VALUE
WxImageList::Replace(int argc, VALUE *argv, VALUE self)
{
    int index = NUM2INT(argv[0]);
    wxBitmap *bitmap;
    Data_Get_Struct(argv[1], wxBitmap, bitmap);
    wxBitmap *mask = &wxNullBitmap;
    if(argc>2) {
      Data_Get_Struct(argv[2], wxBitmap, mask);
    }
    wxImageList *ptr;
    Data_Get_Struct(self, wxImageList, ptr);
#ifdef __WXMSW__
    return (ptr->Replace(index,*bitmap,*mask) ? Qtrue : Qfalse);
#else
    return (ptr->Replace(index,*bitmap) ? Qtrue : Qfalse);
#endif
}

#ifdef __WXMSW__
VALUE
WxImageList::ReplaceIcon(VALUE self,VALUE vindex,VALUE vicon)
{
    int index = NUM2INT(vindex);
    wxIcon *icon;
    Data_Get_Struct(vicon, wxIcon, icon);
    wxImageList *ptr;
    Data_Get_Struct(self, wxImageList, ptr);
    return (ptr->Replace(index,*icon) ? Qtrue : Qfalse);
}
#endif

VALUE
WxImageList::init0(wxImageList *imageList)
{
    if(imageList==NULL) return Qnil;
    static VALUE self = Data_Wrap_Struct(rubyClass, 0, 0, 0);
    DATA_PTR(self) = (void*)imageList;
    return self;
}

VALUE WxImageList::rubyClass;

class ZAutoDefineWxImageList
{
public:
   ZAutoDefineWxImageList()
    {
       WxImageList::DefineClass();
    }
};
static ZAutoDefineWxImageList x2;
