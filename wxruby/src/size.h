/**********************************************************************

  size.h -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#ifndef WXRUBY_SIZE_H
#define WXRUBY_SIZE_H

class WxSize {
public:
    static VALUE alloc(VALUE self);
    static VALUE init(VALUE self,VALUE vx,VALUE vy);
    static VALUE init0(const wxSize &size);
    static void Set(VALUE self,VALUE vwidth,VALUE vheight);
    static void SetHeight(VALUE self,VALUE vheight);
    static void SetWidth(VALUE self,VALUE vwidth);
    static VALUE GetWidth(VALUE self);
    static VALUE GetHeight(VALUE self);
    static VALUE x(VALUE self);
    static VALUE y(VALUE self);

    static void DefineClass();
	static VALUE rubyClass;
};

#endif
