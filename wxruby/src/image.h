/**********************************************************************

  image.h -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#ifndef WXRUBY_IMAGE_H
#define WXRUBY_IMAGE_H

#include "wx/image.h"

class WxImage {
public:
    static VALUE alloc(VALUE self);
    static VALUE init(int argc, VALUE *argv, VALUE self);
    static VALUE init0(wxImage image);
    static VALUE ConvertToBitmap(VALUE self);
    static VALUE ConvertToMono(VALUE self,VALUE vr,VALUE vg,VALUE gb);
    static VALUE Copy(VALUE self);
    static void Create(VALUE self,VALUE vwidth,VALUE vheight);
    static void Destroy(VALUE self);
    static VALUE GetBlue(VALUE self,VALUE vx,VALUE vy);
    static VALUE GetData(VALUE self);
    static VALUE GetGreen(VALUE self,VALUE vx,VALUE vy);
    static VALUE GetHeight(VALUE self);
    static VALUE GetImageCount(int argc, VALUE *argv, VALUE self);
    static VALUE GetMaskBlue(VALUE self);
    static VALUE GetMaskGreen(VALUE self);
    static VALUE GetMaskRed(VALUE self);
    static VALUE GetOption(VALUE self,VALUE vname);
    static VALUE GetOptionInt(VALUE self,VALUE vname);
    static VALUE GetPalette(VALUE self);
    static VALUE GetRed(VALUE self,VALUE vx,VALUE vy);
    static VALUE GetSubImage(VALUE self,VALUE vrect);
    static VALUE GetWidth(VALUE self);
    static VALUE HasMask(VALUE self);
    static VALUE HasOption(VALUE self,VALUE vname);
    static VALUE LoadFile(int argc, VALUE *argv, VALUE self);
    static VALUE Mirror(int argc, VALUE *argv, VALUE self);
    static VALUE Ok(VALUE self);
    static void Replace(VALUE self,VALUE vr1,VALUE vg1,VALUE vb1,VALUE vr2,VALUE vg2,VALUE vb2);
    static VALUE Rescale(VALUE self,VALUE vwidth,VALUE vheight);
    static VALUE Rotate(int argc, VALUE *argv, VALUE self);
    static VALUE Rotate90(int argc, VALUE *argv, VALUE self);
    static VALUE SaveFile(int argc, VALUE *argv, VALUE self);
    static VALUE Scale(VALUE self,VALUE vwidth,VALUE vheight);
    static void SetData(VALUE self,VALUE vdata);
    static void SetMask(int argc, VALUE *argv, VALUE self);
    static void SetMaskColour(VALUE self,VALUE vred,VALUE vblue,VALUE vgreen);
    static VALUE SetMaskFromImage(VALUE self,VALUE vmask,VALUE vred,VALUE vblue,VALUE vgreen);
    static void SetOption(VALUE self,VALUE vname,VALUE vvalue);
    static void SetPalette(VALUE self,VALUE vpalette);
    static void SetRGB(VALUE self,VALUE vx,VALUE vy,VALUE vred,VALUE vblue,VALUE vgreen);

    static void DefineClass();
	static VALUE rubyClass;
};


#endif
