/**********************************************************************

  point.h -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#ifndef WXRUBY_POINT_H
#define WXRUBY_POINT_H

class WxPoint {
public:
    static VALUE alloc(VALUE self);
    static VALUE init(VALUE self,VALUE vx,VALUE vy);
    static VALUE init0(const wxPoint &point);
    static VALUE x(VALUE self);
    static VALUE y(VALUE self);

    static void DefineClass();
	static VALUE rubyClass;
};

#endif
