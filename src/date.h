/**********************************************************************

  date.h -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/

#ifndef WXRUBY_DATE_H
#define WXRUBY_DATE_H

#include "wx/datetime.h"

class WxDateTime {
public:
    static VALUE alloc(VALUE self);
    static VALUE init(int argc, VALUE *argv, VALUE self);
    static VALUE init0(const wxDateTime &dateTime);
    static VALUE GetDay(VALUE self);
    static VALUE Today(VALUE self);
    static VALUE IsValid(VALUE self);
    
    static VALUE FormatISODate(VALUE self);
	static VALUE ToTime(VALUE self);

    static void DefineClass();
	static VALUE rubyClass;
};

#endif
