/**********************************************************************

  fontdata.h -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#ifndef WXRUBY_FONTDATA_H
#define WXRUBY_FONTDATA_H

class WxFontData {
public:
    static VALUE alloc(VALUE self);
    static VALUE init(VALUE self);
    static VALUE init0(const wxFontData &fontData);
    static void SetInitialFont(VALUE self,VALUE vfont);
    static void SetColour(VALUE self,VALUE vcolour);
    static void SetShowHelp(VALUE self,VALUE vshowHelp);
    static VALUE GetChosenFont(VALUE self);
    static VALUE GetColour(VALUE self);

    static void DefineClass();
	static VALUE rubyClass;
};

#endif
