/**********************************************************************

  staticbitmap.h -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/

#ifndef WXRUBY_STATICBITMAP_H
#define WXRUBY_STATICBITMAP_H


class WxStaticBitmap {
public:
    static VALUE alloc(VALUE self);
    static VALUE init(int argc, VALUE *argv, VALUE self);
    static void SetBitmap(VALUE self,VALUE vlabel);

    static void DefineClass();
	static VALUE rubyClass;
};

#endif
