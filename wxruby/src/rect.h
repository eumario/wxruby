/**********************************************************************

  rect.h -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#ifndef WXRUBY_RECT_H
#define WXRUBY_RECT_H

class WxRect {
public:
    static VALUE alloc(VALUE self);
    static VALUE init(VALUE self,VALUE vx,VALUE vy,VALUE vwidth,VALUE vheight);
    static VALUE init0(const wxRect &point);
    static VALUE x(VALUE self);
    static VALUE y(VALUE self);
    static VALUE width(VALUE self);
    static VALUE height(VALUE self);

    static void DefineClass();
	static VALUE rubyClass;
};

#endif
