/**********************************************************************

  url.h -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#ifndef WXRUBY_URL_H
#define WXRUBY_URL_H

#include "wx/url.h"

class WxURL {
public:
    static VALUE alloc(VALUE self);
    static VALUE init(VALUE self,VALUE vurl);
    static VALUE ConvertToValidURI(VALUE self,VALUE vuri);
    static VALUE GetError(VALUE self);
    static VALUE GetInputStream(VALUE self);
    static VALUE GetPath(VALUE self);
    static VALUE GetProtocol(VALUE self);
    static VALUE GetProtocolName(VALUE self);
    static void SetDefaultProxy(VALUE self,VALUE vurl_proxy);
    static void SetProxy(VALUE self,VALUE vurl_proxy);

    static void DefineClass();
	static VALUE rubyClass;
};


#endif
