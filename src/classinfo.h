/**********************************************************************

  classinfo.h -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/
#ifndef WXRUBY_CLASSINFO_H
#define WXRUBY_CLASSINFO_H

class WxClassInfo {
public:
	static VALUE rubyClass;

    static VALUE alloc(VALUE self);
    static VALUE init0(wxClassInfo *classinfo);
    static VALUE GetClassName(VALUE self);

    static void DefineClass();
};




#endif
