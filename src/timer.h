/**********************************************************************

  timer.h -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#ifndef WXRUBY_TIMER_H
#define WXRUBY_TIMER_H

class WxTimer {
public:
    static VALUE alloc(VALUE self);
    static VALUE init(int argc, VALUE *argv, VALUE self);
    static VALUE Start(int argc, VALUE *argv, VALUE self);
    static void Stop(VALUE self);

    static void DefineClass();
	static VALUE rubyClass;
};

class WxStopWatch {
public:
    static VALUE alloc(VALUE self);
    static VALUE init(VALUE self);
    static void Pause(VALUE self);
    static void Resume(VALUE self);
    static void Start(int argc, VALUE *argv, VALUE self);
    static VALUE Time(VALUE self);
    static void free(VALUE self);

    static void DefineClass();
	static VALUE rubyClass;
};

#endif
