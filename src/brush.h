/**********************************************************************

  brush.h -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/

#ifndef WXRUBY_BRUSH_H
#define WXRUBY_BRUSH_H

class WxBrush {
public:
    static VALUE alloc(VALUE self);
    static VALUE init(int argc, VALUE *argv, VALUE self);
    static VALUE init0(const wxBrush &brush);
    static VALUE GetColour(VALUE self);
    static VALUE GetStipple(VALUE self);
    static VALUE GetStyle(VALUE self);
    static VALUE Ok(VALUE self);
    static void SetColour(int argc, VALUE *argv, VALUE self);
    static void SetStipple(VALUE self,VALUE vbitmap);
    static void SetStyle(VALUE self,VALUE vstyle);

    static void DefineClass();
	static VALUE rubyClass;
};

#endif
