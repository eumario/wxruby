/**********************************************************************

  url.cpp -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#include "wx.h"
#include "socket.h"
#include "stream.h"
#include "url.h"

void WxURL::DefineClass()
{
	if(rubyClass)
		return;
	rubyClass = rb_define_class_under(GetWxModule(),"URL", rb_cObject);
	rb_define_alloc_func(rubyClass,WxURL::alloc);
	rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new1), 1);
	rb_define_method(rubyClass, "initialize", VALUEFUNC(WxURL::init), 1);
	rb_define_singleton_method(rubyClass, "convert_to_valid_uri", VALUEFUNC(WxURL::ConvertToValidURI), 1);
	rb_define_method(rubyClass, "get_error", VALUEFUNC(WxURL::GetError), 0);
	rb_define_method(rubyClass, "get_input_stream", VALUEFUNC(WxURL::GetInputStream), 0);
	rb_define_method(rubyClass, "get_path", VALUEFUNC(WxURL::GetPath), 0);
	rb_define_method(rubyClass, "get_protocol", VALUEFUNC(WxURL::GetProtocol), 0);
	rb_define_method(rubyClass, "get_protocol_name", VALUEFUNC(WxURL::GetProtocolName), 0);
	rb_define_singleton_method(rubyClass, "set_default_proxy", VALUEFUNC(WxURL::SetDefaultProxy), 1);
	rb_define_method(rubyClass, "set_proxy", VALUEFUNC(WxURL::SetProxy), 1);
}


VALUE
WxURL::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxURL::init(VALUE self,VALUE vurl)
{
    wxString url = StringValuePtr(vurl);
    wxURL *ptr;
    Data_Get_Struct(self, wxURL, ptr);
    ptr = new wxURL(url);
    DATA_PTR(self) = ptr;

    return self;
}

VALUE
WxURL::GetProtocolName(VALUE self)
{
    wxURL *ptr;
    Data_Get_Struct(self, wxURL, ptr);
    return rb_str_new2(ptr->GetProtocolName());
}

VALUE
WxURL::GetProtocol(VALUE self)
{
    wxURL *ptr;
    Data_Get_Struct(self, wxURL, ptr);
    return WxProtocol::init0(&ptr->GetProtocol());
}

VALUE
WxURL::GetPath(VALUE self)
{
    wxURL *ptr;
    Data_Get_Struct(self, wxURL, ptr);
    return rb_str_new2(ptr->GetPath());
}

VALUE
WxURL::GetError(VALUE self)
{
    wxURL *ptr;
    Data_Get_Struct(self, wxURL, ptr);
    return INT2NUM(ptr->GetError());
}

VALUE
WxURL::GetInputStream(VALUE self)
{
    wxURL *ptr;
    Data_Get_Struct(self, wxURL, ptr);
    return WxInputStream::init0(ptr->GetInputStream());
}

void
WxURL::SetDefaultProxy(VALUE self,VALUE vurl_proxy)
{
    wxString url_proxy = StringValuePtr(vurl_proxy);
    wxURL::SetDefaultProxy(url_proxy);
}

void
WxURL::SetProxy(VALUE self,VALUE vurl_proxy)
{
    wxString url_proxy = StringValuePtr(vurl_proxy);
    wxURL *ptr;
    Data_Get_Struct(self, wxURL, ptr);
    ptr->SetProxy(url_proxy);
}

VALUE
WxURL::ConvertToValidURI(VALUE self,VALUE vuri)
{
    wxString uri = StringValuePtr(vuri);
    return rb_str_new2(wxURL::ConvertToValidURI(uri));
}

VALUE WxURL::rubyClass;

class ZAutoDefineWxURL
{
public:
   ZAutoDefineWxURL()
    {
       WxURL::DefineClass();
    }
};
static ZAutoDefineWxURL x;
