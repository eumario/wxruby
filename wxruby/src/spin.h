/**********************************************************************

  spin.h -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#ifndef WXRUBY_SPIN_H
#define WXRUBY_SPIN_H

#include "wx/spinctrl.h"
#include "wx/spinbutt.h"

class WxSpinButton {
public:
    static VALUE alloc(VALUE self);
    static VALUE init(int argc, VALUE *argv, VALUE self);
    static VALUE GetMax(VALUE self);
    static VALUE GetMin(VALUE self);
    static VALUE GetValue(VALUE self);
    static void SetRange(VALUE self,VALUE vmin,VALUE vmax);
    static void SetValue(VALUE self,VALUE vvalue);

    static void DefineClass();
	static VALUE rubyClass;
};

class WxSpinCtrl {
public:
    static VALUE alloc(VALUE self);
    static VALUE init(int argc, VALUE *argv, VALUE self);
    static VALUE GetMax(VALUE self);
    static VALUE GetMin(VALUE self);
    static VALUE GetValue(VALUE self);
    static void SetRange(VALUE self,VALUE vminVal,VALUE vmaxVal);
#ifdef __WXMSW__
    static void SetSelection(VALUE self,VALUE vfrom,VALUE vto);
#endif
    static void SetValue(VALUE self,VALUE vvalue);

    static void DefineClass();
	static VALUE rubyClass;
};

#endif
