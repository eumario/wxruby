/**********************************************************************

  menubar.h -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#ifndef WXRUBY_MENUBAR_H
#define WXRUBY_MENUBAR_H

class WxMenuBar {
public:
    static VALUE alloc(VALUE self);
    static VALUE init(int argc, VALUE *argv, VALUE self);
    static VALUE init0(wxMenuBar *menubar);
    static void Append(int argc, VALUE *argv, VALUE self);
    static void Check(VALUE self,VALUE vid,VALUE vcheck);
    static VALUE IsChecked(VALUE self,VALUE vid);

    static void DefineClass();
	static VALUE rubyClass;
};

#endif
