/**********************************************************************

  radio.h -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#ifndef WXRUBY_RADIO_H
#define WXRUBY_RADIO_H

class WxRadioBox {
public:
    static VALUE alloc(VALUE self);
    static VALUE init(int argc, VALUE *argv, VALUE self);
    static void SetSelection(VALUE self,VALUE vn);
    static VALUE GetString(VALUE self,VALUE vn);
    static VALUE GetStringSelection(VALUE self);
    static void SetStringSelection(VALUE self,VALUE vstring);

    static void DefineClass();
	static VALUE rubyClass;
};

class WxRadioButton {
public:
    static VALUE alloc(VALUE self);
    static VALUE init(int argc, VALUE *argv, VALUE self);
    static VALUE GetValue(VALUE self);
    static void SetValue(VALUE self,VALUE vvalue);

    static void DefineClass();
	static VALUE rubyClass;
};

#endif
