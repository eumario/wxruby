/**********************************************************************

  dirdialog.h -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#ifndef WXRUBY_DIRDIALOG_H
#define WXRUBY_DIRDIALOG_H

class WxDirDialog {
public:
    static VALUE alloc(VALUE self);
    static VALUE init(int argc, VALUE *argv, VALUE self);
    static VALUE ShowModal(VALUE self);
    static VALUE GetPath(VALUE self);

    static void DefineClass();
	static VALUE rubyClass;
};

#endif
