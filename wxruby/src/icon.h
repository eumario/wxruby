/**********************************************************************

  icon.h -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#ifndef WXRUBY_ICON_H
#define WXRUBY_ICON_H

class WxIcon {
public:
    static VALUE alloc(VALUE self);
    static VALUE init(int argc, VALUE *argv, VALUE self);
    static VALUE Ok(VALUE self);
    static void CopyFromBitmap(VALUE self,VALUE vbmp);
    static VALUE GetDepth(VALUE self);
    static VALUE GetHeight(VALUE self);
    static VALUE GetWidth(VALUE self);
    static VALUE LoadFile(VALUE self,VALUE vname,VALUE vtype);
    static void SetDepth(VALUE self,VALUE vdepth);
    static void SetHeight(VALUE self,VALUE vheight);
//    static void SetOk(VALUE self,VALUE visOk);
    static void SetWidth(VALUE self,VALUE vwidth);
    static VALUE init0(const wxIcon &icon);

    static void DefineClass();
	static VALUE rubyClass;
};


#endif
