/**********************************************************************

  statictext.h -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#ifndef WXRUBY_STATICTEXT_H
#define WXRUBY_STATICTEXT_H

#include "wx/statline.h"

class WxStaticText {
public:
    static VALUE alloc(VALUE self);
	static VALUE wrapNew(int argc, VALUE *argv, VALUE self);
    static VALUE init(int argc, VALUE *argv, VALUE self);
    static void SetLabel(VALUE self,VALUE vlabel);
    static void SetFont(VALUE self,VALUE vfont);

    static void DefineClass();
	static VALUE rubyClass;
};

class WxStaticBox {
public:
    static VALUE alloc(VALUE self);
    static VALUE init(int argc, VALUE *argv, VALUE self);

    static void DefineClass();
	static VALUE rubyClass;
};

class WxStaticLine {
public:
    static VALUE alloc(VALUE self);
    static VALUE init(int argc, VALUE *argv, VALUE self);

    static void DefineClass();
	static VALUE rubyClass;
};

#endif
