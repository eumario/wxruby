/**********************************************************************

  gauge.h -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#ifndef WXRUBY_GAUGE_H
#define WXRUBY_GAUGE_H

class WxGauge {
public:
    static VALUE alloc(VALUE self);
    static VALUE init(int argc, VALUE *argv, VALUE self);
    static VALUE GetBezelFace(VALUE self);
    static VALUE GetRange(VALUE self);
    static VALUE GetShadowWidth(VALUE self);
    static VALUE GetValue(VALUE self);
    static void SetBezelFace(VALUE self,VALUE vwidth);
    static void SetRange(VALUE self,VALUE vrange);
    static void SetShadowWidth(VALUE self,VALUE vwidth);
    static void SetValue(VALUE self,VALUE vpos);

    static void DefineClass();
	static VALUE rubyClass;
};

#endif
