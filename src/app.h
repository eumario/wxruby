/**********************************************************************

  app.h -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/

#ifndef WXRUBY_APP_H
#define WXRUBY_APP_H

class wxAppWithCallbacks;
	
class WxApp {
public:
	static VALUE rubyClass;

    static void DefineClass();
    static wxAppWithCallbacks* GetPtr(VALUE self);
    static VALUE alloc(VALUE self);
    static void free(wxAppWithCallbacks *ptr);
    static VALUE init(VALUE self);
    static VALUE MainLoop(VALUE self);
    static VALUE ExitMainLoop(VALUE self);
    static void SetTopWindow(VALUE self,VALUE vwin);
    static VALUE GetAppName(VALUE self);
    static void SetAppName(VALUE self,VALUE vname);
    static VALUE GetClassName(VALUE self);
    static void SetClassName(VALUE self,VALUE vname);
    static VALUE GetVendorName(VALUE self);
    static void SetVendorName(VALUE self,VALUE vname);
    static void Yield(VALUE self);
};

#endif
