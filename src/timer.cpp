/**********************************************************************

  timer.cpp -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#include "wx.h"
#include "timer.h"

void WxTimer::DefineClass()
{
	if(rubyClass)
		return;
	rubyClass = rb_define_class_under(GetWxModule(),"Timer", rb_cObject);
	rb_define_alloc_func(rubyClass,WxTimer::alloc);
	rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new_1), -1);
	rb_define_method(rubyClass, "initialize", VALUEFUNC(WxTimer::init), -1);
	rb_define_method(rubyClass, "start", VALUEFUNC(WxTimer::Start), -1);
	rb_define_method(rubyClass, "stop", VALUEFUNC(WxTimer::Stop), 0);
}

VALUE
WxTimer::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxTimer::init(int argc, VALUE *argv, VALUE self)
{
    wxEvtHandler *owner;
    int id = -1;

    if(argc>0 && TYPE(argv[0])==T_DATA) {
	Data_Get_Struct(argv[0], wxEvtHandler, owner);
    }
    if(argc>1 && TYPE(argv[1])==T_FIXNUM)
      id = NUM2INT(argv[1]);

    wxTimer *ptr;
    Data_Get_Struct(self, wxTimer, ptr);
    ptr = new wxTimer(owner,id);
    DATA_PTR(self) = ptr;

    return self;
}

VALUE
WxTimer::Start(int argc, VALUE *argv, VALUE self)
{
    int milliseconds = -1;
    bool oneShot = FALSE;
    if(argc>0 && TYPE(argv[0])==T_FIXNUM)
      milliseconds = NUM2INT(argv[0]);
    if(argc>0 && argv[1]==Qtrue)
      oneShot = TRUE;
    wxTimer *ptr;
    Data_Get_Struct(self, wxTimer, ptr);
    return (ptr->Start(milliseconds,oneShot) ? Qtrue : Qfalse);
}

void
WxTimer::Stop(VALUE self)
{
    wxTimer *ptr;
    Data_Get_Struct(self, wxTimer, ptr);
    ptr->Stop();
}

VALUE WxTimer::rubyClass;

class ZAutoDefineWxTimer
{
public:
   ZAutoDefineWxTimer()
    {
       WxTimer::DefineClass();
    }
};
static ZAutoDefineWxTimer x;

//--------------------------------------------------------------------------------
void WxStopWatch::DefineClass()
{
	if(rubyClass)
		return;
	rubyClass = rb_define_class_under(GetWxModule(),"StopWatch", rb_cObject);
	rb_define_alloc_func(rubyClass,WxStopWatch::alloc);
	rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new0), 0);
	rb_define_method(rubyClass, "initialize", VALUEFUNC(WxStopWatch::init), 0);
	rb_define_method(rubyClass, "pause", VALUEFUNC(WxStopWatch::Pause), 0);
	rb_define_method(rubyClass, "resume", VALUEFUNC(WxStopWatch::Resume), 0);
	rb_define_method(rubyClass, "start", VALUEFUNC(WxStopWatch::Start), -1);
	rb_define_method(rubyClass, "time", VALUEFUNC(WxStopWatch::Time), 0);
	rb_define_method(rubyClass, "free", VALUEFUNC(WxStopWatch::free), 0);
}

VALUE
WxStopWatch::alloc(VALUE self)
{
    return Data_Wrap_Struct(self, 0, 0, 0);
}

VALUE
WxStopWatch::init(VALUE self)
{
    wxStopWatch *ptr;
    Data_Get_Struct(self, wxStopWatch, ptr);
    ptr = new wxStopWatch();
    DATA_PTR(self) = ptr;

    return self;
}

void
WxStopWatch::Start(int argc, VALUE *argv, VALUE self)
{
    int milliseconds = 0;
    if(argc>0 && TYPE(argv[0])==T_FIXNUM)
      milliseconds = NUM2INT(argv[0]);
    wxStopWatch *ptr;
    Data_Get_Struct(self, wxStopWatch, ptr);
    ptr->Start(milliseconds);
}

void
WxStopWatch::free(VALUE self)
{
    wxStopWatch *ptr;
    Data_Get_Struct(self, wxStopWatch, ptr);
    delete ptr;
}

void
WxStopWatch::Pause(VALUE self)
{
    wxStopWatch *ptr;
    Data_Get_Struct(self, wxStopWatch, ptr);
    ptr->Pause();
}

void
WxStopWatch::Resume(VALUE self)
{
    wxStopWatch *ptr;
    Data_Get_Struct(self, wxStopWatch, ptr);
    ptr->Resume();
}

VALUE
WxStopWatch::Time(VALUE self)
{
    wxStopWatch *ptr;
    Data_Get_Struct(self, wxStopWatch, ptr);
    return INT2NUM(ptr->Time());
}

VALUE WxStopWatch::rubyClass;

class ZAutoDefineWxStopWatch
{
public:
   ZAutoDefineWxStopWatch()
    {
       WxStopWatch::DefineClass();
    }
};
static ZAutoDefineWxStopWatch x2;
