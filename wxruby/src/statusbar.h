/**********************************************************************

  statusbar.h -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/

#ifndef WXRUBY_STATUSBAR_H
#define WXRUBY_STATUSBAR_H

class WxStatusBar {
public:
    static VALUE alloc(VALUE self);
    static VALUE init(int argc, VALUE *argv, VALUE self);
    static VALUE init0(wxStatusBar *statusbar);
    static VALUE GetFieldRect(VALUE self,VALUE vi);
    static VALUE GetFieldsCount(VALUE self);
    static VALUE GetStatusText(int argc, VALUE *argv, VALUE self);
    static void PopStatusText(int argc, VALUE *argv, VALUE self);
    static void PushStatusText(int argc, VALUE *argv, VALUE self);
    static void SetFieldsCount(int argc, VALUE *argv, VALUE self);
    static void SetMinHeight(VALUE self,VALUE vheight);
    static void SetStatusText(int argc, VALUE *argv, VALUE self);
    static void SetStatusWidths(VALUE self,VALUE vwidths);

    static void DefineClass();
	static VALUE rubyClass;
};

#endif
