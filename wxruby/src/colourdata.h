/**********************************************************************

  colourdata.h -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/

#ifndef WXRUBY_COLOURDATA_H
#define WXRUBY_COLOURDATA_H

class WxColourData {
public:
    static VALUE alloc(VALUE self);
    static VALUE init(VALUE self);
    static VALUE init0(const wxColourData &colourData);
    static VALUE GetChooseFull(VALUE self);
    static VALUE GetColour(VALUE self);
    static VALUE GetCustomColour(VALUE self,VALUE vi);
    static void SetChooseFull(VALUE self,VALUE vflag);
    static void SetColour(VALUE self,VALUE vcolour);
    static void SetCustomColour(VALUE self,VALUE vi,VALUE vcolour);

    static void DefineClass();
	static VALUE rubyClass;
};

#endif
