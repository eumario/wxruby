/**********************************************************************

  tooltip.h -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#ifndef WXRUBY_TOOLTIP_H
#define WXRUBY_TOOLTIP_H

#include "wx/tooltip.h"

class WxToolTip {
public:
    static VALUE alloc(VALUE self);
    static VALUE init(VALUE self,VALUE vtip);
    static void Enable(VALUE self,VALUE vflag);
    static void SetDelay(VALUE self,VALUE vmsecs);
    static void SetTip(VALUE self,VALUE vtip);
    static VALUE GetTip(VALUE self);
    static VALUE GetWindow(VALUE self);
    static VALUE init0(wxToolTip *tooltip);

    static void DefineClass();
	static VALUE rubyClass;
};

#endif
