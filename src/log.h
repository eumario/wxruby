/**********************************************************************

  log.h -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#ifndef WXRUBY_LOG_H
#define WXRUBY_LOG_H

class WxLog {
public:
    static VALUE alloc(VALUE self);
    static VALUE GetActiveTarget(VALUE self);
    static VALUE SetActiveTarget(VALUE self,VALUE vlogtarget);
    static void Flush(VALUE self);
    static VALUE init0(wxLog *log);
    static void DontCreateOnDemand(VALUE self);
    static void FlushActive(VALUE self);
    static void Resume(VALUE self);
    static void Suspend(VALUE self);

    static void DefineClass();
	static VALUE rubyClass;
};

class WxLogTextCtrl {
public:
    static VALUE alloc(VALUE self);
    static VALUE init(VALUE self,VALUE vtextctrl);

    static void DefineClass();
	static VALUE rubyClass;
};

#endif
