/**********************************************************************

  palette.h -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/

#ifndef WXRUBY_PALETTE_H
#define WXRUBY_PALETTE_H

class WxPalette {
public:
    static VALUE alloc(VALUE self);
    static VALUE init(VALUE self,VALUE vred,VALUE vgreen,VALUE vblue);
    static VALUE init0(wxPalette *palette);
    static VALUE GetPixel(VALUE self,VALUE vred,VALUE vgreen,VALUE vblue);
    static VALUE GetRGB(VALUE self,VALUE vpixel);
    static VALUE Ok(VALUE self);

    static void DefineClass();
	static VALUE rubyClass;
};

#endif
