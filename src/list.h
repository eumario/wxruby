/**********************************************************************

  list.h -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#ifndef WXRUBY_LIST_H
#define WXRUBY_LIST_H

#include "wx/imaglist.h"

class WxList {
public:
    static VALUE alloc(VALUE self);
    static VALUE init(int argc, VALUE *argv, VALUE self);
    static VALUE init0(wxList *list);

    static void DefineClass();
	static VALUE rubyClass;
};

class WxImageList {
public:
    static VALUE alloc(VALUE self);
    static VALUE init(int argc, VALUE *argv, VALUE self);
    static VALUE init0(wxImageList *imageList);
    static VALUE Add(int argc, VALUE *argv, VALUE self);
    static VALUE AddWithColourMask(VALUE self,VALUE vbitmap,VALUE vmaskColour);
    static VALUE Draw(int argc, VALUE *argv, VALUE self);
    static VALUE GetImageCount(VALUE self);
    static VALUE GetSize(VALUE self,VALUE vindex);
    static VALUE Remove(VALUE self,VALUE vindex);
    static VALUE RemoveAll(VALUE self);
    static VALUE Replace(int argc, VALUE *argv, VALUE self);
#ifdef __WXMSW__
    static VALUE ReplaceIcon(VALUE self,VALUE vindex,VALUE vicon);
#endif

    static void DefineClass();
	static VALUE rubyClass;
};



#endif
