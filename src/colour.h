/**********************************************************************

  colour.h -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/

#ifndef WXRUBY_COLOUR_H
#define WXRUBY_COLOUR_H

class WxColour {
public:
    static VALUE alloc(VALUE self);
    static VALUE init(int argc, VALUE *argv, VALUE self);
    static VALUE init0(const wxColour &colour);
    static VALUE Blue(VALUE self);
    static VALUE Green(VALUE self);
    static VALUE Red(VALUE self);
    static VALUE Ok(VALUE self);

    static void DefineClass();
	static VALUE rubyClass;
};

#endif
