/**********************************************************************

  cursor.h -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#ifndef WXRUBY_CURSOR_H
#define WXRUBY_CURSOR_H

class WxCursor {
public:
    static VALUE alloc(VALUE self);
    static VALUE init(int argc, VALUE *argv, VALUE self);
    static VALUE Ok(VALUE self);
    static VALUE init0(wxCursor *cursor);

    static void DefineClass();
	static VALUE rubyClass;
};

class WxBusyCursor {
public:
    static VALUE alloc(VALUE self);
    static VALUE init(int argc, VALUE *argv, VALUE self);
    static void free(VALUE self);
    static VALUE Busy(int argc, VALUE *argv, VALUE self);
    static void DefineClass();
	static VALUE rubyClass;
};

#endif
