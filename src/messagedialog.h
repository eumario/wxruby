/**********************************************************************

  messagedialog.h -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#ifndef WXRUBY_MESSAGEDIALOG_H
#define WXRUBY_MESSAGEDIALOG_H

class WxMessageDialog {
public:
    static VALUE alloc(VALUE self);
    static VALUE init(int argc, VALUE *argv, VALUE self);
    static VALUE ShowModal(VALUE self);

    static void DefineClass();
	static VALUE rubyClass;
};

#endif
