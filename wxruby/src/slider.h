/**********************************************************************

  slider.h -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#ifndef WXRUBY_SLIDER_H
#define WXRUBY_SLIDER_H

class WxSlider {
public:
    static VALUE alloc(VALUE self);
    static VALUE init(int argc, VALUE *argv, VALUE self);
    static void ClearSel(VALUE self);
    static void ClearTicks(VALUE self);
    static VALUE GetLineSize(VALUE self);
    static VALUE GetMax(VALUE self);
    static VALUE GetMin(VALUE self);
    static VALUE GetPageSize(VALUE self);
    static VALUE GetSelEnd(VALUE self);
    static VALUE GetSelStart(VALUE self);
    static VALUE GetThumbLength(VALUE self);
    static VALUE GetTickFreq(VALUE self);
    static VALUE GetValue(VALUE self);
    static void SetLineSize(VALUE self,VALUE vlineSize);
    static void SetPageSize(VALUE self,VALUE vpageSize);
    static void SetRange(VALUE self,VALUE vminValue, VALUE vmaxValue);
    static void SetSelection(VALUE self,VALUE vstartPos, VALUE vendPos);
    static void SetThumbLength(VALUE self,VALUE vlen);
    static void SetTick(VALUE self,VALUE vtickPos);
    static void SetTickFreq(VALUE self,VALUE vn, VALUE vpos);
    static void SetValue(VALUE self,VALUE vvalue);

    static void DefineClass();
	static VALUE rubyClass;
};

#endif
