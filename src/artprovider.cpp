/**********************************************************************

  artprovider.cpp -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#include "wx.h"
#include "bitmap.h"
#include "icon.h"
#include "size.h"
#include "artprovider.h"

wxBitmap wxRbArtProvider::CreateBitmap(const wxArtID& id,
                          const wxArtClient& client,
                          const wxSize& size)
{
    wxBitmap *ptr;
    VALUE v = WxBitmap::init0(wxNullBitmap);
    v = rb_funcall(self,rb_intern("CreateBitmap"),3,rb_str_new2(id),rb_str_new2(client),WxSize::init0(size));
    Data_Get_Struct(v, wxBitmap, ptr);
    return *ptr;
}

void WxArtProvider::DefineClass()
{
	if(rubyClass)
		return;
	
	rubyClass = rb_define_class_under(GetWxModule(),"ArtProvider", rb_cObject);
	rb_define_alloc_func(rubyClass,WxArtProvider::alloc);
	rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new0), 0);
	rb_define_method(rubyClass, "initialize", VALUEFUNC(WxArtProvider::init), 0);
	rb_define_method(rubyClass, "create_bitmap", VALUEFUNC(WxArtProvider::CreateBitmap), 3);
	rb_define_singleton_method(rubyClass, "get_bitmap", VALUEFUNC(WxArtProvider::GetBitmap), -1);
	rb_define_singleton_method(rubyClass, "get_icon", VALUEFUNC(WxArtProvider::GetIcon), -1);
	rb_define_singleton_method(rubyClass, "pop_provider", VALUEFUNC(WxArtProvider::PopProvider), 0);
	rb_define_singleton_method(rubyClass, "push_provider", VALUEFUNC(WxArtProvider::PushProvider), 1);
	rb_define_singleton_method(rubyClass, "remove_provider", VALUEFUNC(WxArtProvider::RemoveProvider), 1);
}

VALUE
WxArtProvider::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxArtProvider::init(VALUE self)
{
    wxRbArtProvider *ptr;
    Data_Get_Struct(self, wxRbArtProvider, ptr);
    ptr = new wxRbArtProvider(self);
    DATA_PTR(self) = ptr;
    return self;
}

VALUE
WxArtProvider::CreateBitmap(VALUE self,VALUE vid,VALUE vclient,VALUE vsize)
{
    wxArtID id = StringValuePtr(vid);
    wxArtClient client = StringValuePtr(vclient);
    wxSize *size;
    Data_Get_Struct(vsize, wxSize, size);
    wxRbArtProvider *ptr;
    Data_Get_Struct(self, wxRbArtProvider, ptr);
//    return WxBitmap.init0(ptr->CreateBitmap(id,client,*size));
    return Qnil;
}

VALUE
WxArtProvider::GetBitmap(int argc, VALUE *argv, VALUE self)
{
    wxArtID id;
    if(TYPE(argv[0])==T_STRING)
      id = StringValuePtr(argv[0]);
    else {
      VALUE value = NUM2INT(argv[0]);
      id = StringValuePtr(value);
    }
    wxArtClient client = wxART_OTHER;
    if(argc>1 && TYPE(argv[1])==T_STRING)
      client = StringValuePtr(argv[1]);
    wxSize size = wxDefaultSize;
    if(argc>2 && TYPE(argv[2])==T_DATA) {
      wxSize *ptr;
      Data_Get_Struct(argv[2], wxSize, ptr);
      size = *ptr;
    }
    return WxBitmap::init0(wxArtProvider::GetBitmap(id,client,size));
}

VALUE
WxArtProvider::GetIcon(int argc, VALUE *argv, VALUE self)
{
    wxArtID id;
    if(TYPE(argv[0])==T_STRING)
      id = StringValuePtr(argv[0]);
    else {
      VALUE value = NUM2INT(argv[0]);
      id = StringValuePtr(value);
    }
    wxArtClient client = wxART_OTHER;
    if(argc>1 && TYPE(argv[1])==T_STRING)
      client = StringValuePtr(argv[1]);
    wxSize size = wxDefaultSize;
    if(argc>2 && TYPE(argv[2])==T_DATA) {
      wxSize *ptr;
      Data_Get_Struct(argv[2], wxSize, ptr);
      size = *ptr;
    }
    return WxIcon::init0(wxArtProvider::GetIcon(id,client,size));
}

VALUE
WxArtProvider::PopProvider(VALUE self)
{
    return (wxArtProvider::PopProvider() ? Qtrue : Qfalse);
}

void
WxArtProvider::PushProvider(VALUE self,VALUE vprovider)
{
    wxRbArtProvider* provider;
    Data_Get_Struct(vprovider, wxRbArtProvider, provider);
    wxArtProvider::PushProvider(provider);
}

VALUE
WxArtProvider::RemoveProvider(VALUE self,VALUE vprovider)
{
    wxRbArtProvider* provider;
    Data_Get_Struct(vprovider, wxRbArtProvider, provider);
    return (wxArtProvider::RemoveProvider(provider) ? Qtrue : Qfalse);
}

VALUE WxArtProvider::rubyClass;

class ZAutoDefine
{
public:
   ZAutoDefine()
    {
       WxArtProvider::DefineClass();
    }
};
static ZAutoDefine x;
