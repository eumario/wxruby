/**********************************************************************

  layout.h -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#ifndef WXRUBY_LAYOUT_H
#define WXRUBY_LAYOUT_H

class WxIndividualLayoutConstraint {
public:
    static VALUE alloc(VALUE self);
    static VALUE init(VALUE self);
    static VALUE init0(wxIndividualLayoutConstraint &individualLayoutConstraint);
    static void SameAs(int argc, VALUE *argv, VALUE self);
    static void LeftOf(int argc, VALUE *argv, VALUE self);
    static void RightOf(int argc, VALUE *argv, VALUE self);
    static void Above(int argc, VALUE *argv, VALUE self);
    static void Below(int argc, VALUE *argv, VALUE self);
    static void PercentOf(VALUE self,VALUE votherW,VALUE vwh,VALUE vper);
    static void AsIs(VALUE self);
    static void Absolute(VALUE self,VALUE vvalue);

    static void DefineClass();
	static VALUE rubyClass;
};


class WxLayoutConstraints {
public:
    static VALUE alloc(VALUE self);
    static VALUE init(VALUE self);
    static VALUE init0(wxLayoutConstraints *layoutConstraint);
    static VALUE left(VALUE self);
    static VALUE top(VALUE self);
    static VALUE right(VALUE self);
    static VALUE bottom(VALUE self);
    static VALUE width(VALUE self);
    static VALUE height(VALUE self);
    static VALUE centreX(VALUE self);
    static VALUE centreY(VALUE self);

    static void DefineClass();
	static VALUE rubyClass;
};


#endif
