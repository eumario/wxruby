/**********************************************************************

  calendar.h -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/

#ifndef WXRUBY_CALENDAR_H
#define WXRUBY_CALENDAR_H

#include "wx/calctrl.h"


class WxCalendarDateAttr {
public:
    static VALUE alloc(VALUE self);
    static VALUE init(int argc, VALUE *argv, VALUE self);
    static VALUE init0(wxCalendarDateAttr *attr);
    static VALUE GetBackgroundColour(VALUE self);

    static void DefineClass();
	static VALUE rubyClass;
};

class WxCalendarCtrl {
public:
    static VALUE alloc(VALUE self);
    static VALUE init(int argc, VALUE *argv, VALUE self);
    static VALUE GetAttr(VALUE self,VALUE vday);
    static void SetAttr(VALUE self,VALUE vday,VALUE vattr);
    static void ResetAttr(VALUE self,VALUE vday);
    static void EnableHolidayDisplay(int argc, VALUE *argv, VALUE self);
    static void EnableYearChange(int argc, VALUE *argv, VALUE self);
    static void EnableMonthChange(int argc, VALUE *argv, VALUE self);

    static void DefineClass();
	static VALUE rubyClass;
};


#endif
