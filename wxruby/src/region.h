/**********************************************************************

  region.h -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#ifndef WXRUBY_REGION_H
#define WXRUBY_REGION_H

class WxRegion {
public:
    static VALUE alloc(VALUE self);
    static VALUE init(int argc, VALUE *argv, VALUE self);
    static void Clear(VALUE self);
    static VALUE Contains(int argc, VALUE *argv, VALUE self);
    static VALUE GetBox(VALUE self);
    static VALUE Intersect(int argc, VALUE *argv, VALUE self);
    static VALUE IsEmpty(VALUE self);
#if defined(__WXGTK__) || defined(__WXMSW__)
    static VALUE Offset(VALUE self,VALUE vx,VALUE vy);
#endif
    static VALUE Subtract(VALUE self,VALUE argv);
    static VALUE Union(int argc, VALUE *argv, VALUE self);
    static VALUE Xor(int argc, VALUE *argv, VALUE self);
    static VALUE init0(const wxRegion &region);

    static void DefineClass();
	static VALUE rubyClass;
};


#endif
