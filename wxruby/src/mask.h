/**********************************************************************

  mask.h -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#ifndef WXRUBY_MASK_H
#define WXRUBY_MASK_H

class WxMask {
public:
    static VALUE alloc(VALUE self);
    static VALUE init(int argc, VALUE *argv, VALUE self);
    static VALUE init0(wxMask *mask);

    static void DefineClass();
	static VALUE rubyClass;
};


#endif
