/**********************************************************************

  ownerdrawn.h -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/

#ifdef __WXMSW__
#ifndef WXRUBY_OWNERDRAWN_H
#define WXRUBY_OWNERDRAWN_H

class WxOwnerDrawn {
public:
    static VALUE alloc(VALUE self);
    static VALUE init(int argc, VALUE *argv, VALUE self);
    static VALUE init0(wxOwnerDrawn *ownerdrawn);
    static VALUE GetBackgroundColour(VALUE self);
    static VALUE GetBitmap(int argc, VALUE *argv, VALUE self);
    static VALUE GetDefaultMarginWidth(VALUE self);
    static VALUE GetFont(VALUE self);
    static VALUE GetMarginWidth(VALUE self);
    static VALUE GetName(VALUE self);
    static VALUE GetTextColour(VALUE self);
    static VALUE IsCheckable(VALUE self);
    static VALUE IsOwnerDrawn(VALUE self);
    static void ResetOwnerDrawn(VALUE self);
    static void  SetAccelString(VALUE self,VALUE vstrAccel);
    static void  SetBackgroundColour(VALUE self,VALUE vcolBack);
    static void  SetBitmap(VALUE self,VALUE vbmpChecked);
    static void  SetBitmaps(int argc, VALUE *argv, VALUE self);
    static void  SetCheckable(VALUE self,VALUE vcheckable);
    static void  SetFont(VALUE self,VALUE vfont);
    static void  SetMarginWidth(VALUE self,VALUE vnWidth);
    static void  SetName(VALUE self,VALUE vstrName);
    static void  SetTextColour(VALUE self,VALUE vcolText);
    
    static void DefineClass();
	static VALUE rubyClass;
};


#endif
#endif
