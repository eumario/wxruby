/**********************************************************************

  menu.h -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#ifndef WXRUBY_MENU_H
#define WXRUBY_MENU_H

class WxMenu {
public:
    static VALUE alloc(VALUE self);
    static VALUE init(int argc, VALUE *argv, VALUE self);
    static VALUE Append(int argc, VALUE *argv, VALUE self);
    static VALUE AppendItem(int argc, VALUE *argv, VALUE self);
    static VALUE AppendCheckItem(int argc, VALUE *argv, VALUE self);
    static VALUE AppendRadioItem(int argc, VALUE *argv, VALUE self);
    static VALUE AppendSeparator(VALUE self);
    static VALUE Check(VALUE self,VALUE vid,VALUE vcheck);
    static VALUE Enable(VALUE self,VALUE vid,VALUE venable);

    static void DefineClass();
	static VALUE rubyClass;
};

#endif
