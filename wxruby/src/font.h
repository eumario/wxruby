/**********************************************************************

  font.h -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#ifndef WXRUBY_FONT_H
#define WXRUBY_FONT_H

class WxFont {
public:
    static VALUE alloc(VALUE self);
    static VALUE init(int argc, VALUE *argv, VALUE self);
    static VALUE init0(const wxFont &font);

    static void DefineClass();
	static VALUE rubyClass;
};

#endif
