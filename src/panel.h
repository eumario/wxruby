/**********************************************************************

  panel.h -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#ifndef WXRUBY_PANEL_H
#define WXRUBY_PANEL_H

class WxPanel {
public:
    static VALUE alloc(VALUE self);
    static VALUE init(int argc, VALUE *argv, VALUE self);
    static VALUE GetDefaultItem(VALUE self);
    static void InitDialog(VALUE self);
    static void SetDefaultItem(VALUE self,VALUE vbtn);

    static void DefineClass();
	static VALUE rubyClass;
};

#endif
