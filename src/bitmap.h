/**********************************************************************

  bitmap.h -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/

#ifndef WXRUBY_BITMAP_H
#define WXRUBY_BITMAP_H

class WxBitmap {
public:
    static VALUE alloc(VALUE self);
    static VALUE init(int argc, VALUE *argv, VALUE self);
    static VALUE init0(const wxBitmap &bitmap);
    static VALUE GetWidth(VALUE self);
    static VALUE GetHeight(VALUE self);
    static VALUE Ok(VALUE self);
    static VALUE GetMask(VALUE self);
    static void SetMask(VALUE self,VALUE vmask);
    static VALUE ConvertToImage(VALUE self);

    static void DefineClass();
	static VALUE rubyClass;
};

#endif
