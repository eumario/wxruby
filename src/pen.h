/**********************************************************************

  pen.h -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/

#ifndef WXRUBY_PEN_H
#define WXRUBY_PEN_H

class WxPen {
public:
    static VALUE alloc(VALUE self);
    static VALUE init(int argc, VALUE *argv, VALUE self);
    static VALUE init0(wxPen *pen);
    static VALUE GetCap(VALUE self);
    static VALUE GetColour(VALUE self);
    static VALUE GetDashes(VALUE self);
    static VALUE GetJoin(VALUE self);
#ifdef __WXMSW__
    static VALUE GetStipple(VALUE self);
#endif
    static VALUE GetStyle(VALUE self);
    static VALUE GetWidth(VALUE self);
    static VALUE Ok(VALUE self);
    static void SetCap(VALUE self,VALUE vcapStyle);
    static void SetColour(int argc, VALUE *argv, VALUE self);
    static void SetDashes(VALUE self,VALUE vdashes);
    static void SetJoin(VALUE self,VALUE vjoin_style);
#ifdef __WXMSW__
    static void SetStipple(VALUE self,VALUE vstipple);
#endif
    static void SetStyle(VALUE self,VALUE vstyle);
    static void SetWidth(VALUE self,VALUE vwidth);

    static void DefineClass();
	static VALUE rubyClass;
};

#endif
