/**********************************************************************

  app.cpp -

  $Author$
  $Date$
  created at: 2003-04-14 11:02

  Copyright (C) 2003  Kevin Smith

**********************************************************************/


#include "wx.h"

#ifdef WIN32
#  include <time.h>
#else
#  include <sys/time.h>
#endif

#if defined(__cplusplus)
extern "C" {
#endif
#include "intern.h"
#include "rubysig.h"
#if defined(__cplusplus)
}
#endif
#include "app_cb.h"

#include "app.h"

BEGIN_EVENT_TABLE(wxAppWithCallbacks, wxEvtHandler)
    EVT_IDLE(wxAppWithCallbacks::OnIdle)
END_EVENT_TABLE()

bool wxAppWithCallbacks::OnInit()
{
    wxApp::OnInit();
    return FALSE;
}

void wxAppWithCallbacks::OnIdle(wxIdleEvent& event)
{
    struct timeval wait;

    wait.tv_sec  = 0;
    wait.tv_usec = 100000; /* 100ms */

    CHECK_INTS;
    if (!rb_thread_critical) rb_thread_wait_for(wait);

    wxApp::OnIdle(event);
}

int wxAppWithCallbacks::MainLoop()
{
    int retval = 0;

    DeletePendingObjects();
#ifdef __WXGTK__
    m_initialized = wxTopLevelWindows.GetCount() != 0;
#endif

    if( Initialized() )
    {
        if( m_exitOnFrameDelete == Later )
            m_exitOnFrameDelete = Yes;
        retval = wxApp::MainLoop();
        OnExit();
    }

    return retval;
}

int wxAppWithCallbacks::OnExit()
{
  return wxApp::OnExit();
}

//-------------------------------------------------
void WxApp::DefineClass()
{
	if(rubyClass)
		return;

	rubyClass = rb_define_class_under(GetWxModule(),"App", rb_cObject);
	rb_define_alloc_func(rubyClass,alloc);
	rb_define_singleton_method(rubyClass, "new", VALUEFUNC(new0), 0);
	rb_define_method(rubyClass, "initialize", VALUEFUNC(init), 0);
	rb_define_method(rubyClass, "main_loop", VALUEFUNC(MainLoop), 0);
	rb_define_method(rubyClass, "exit_main_loop", VALUEFUNC(ExitMainLoop), 0);
	rb_define_method(rubyClass, "set_top_window", VALUEFUNC(SetTopWindow), 1);
	rb_define_method(rubyClass, "get_app_name", VALUEFUNC(GetAppName), 0);
	rb_define_method(rubyClass, "get_class_name", VALUEFUNC(GetClassName), 0);
	rb_define_method(rubyClass, "get_vendor_name", VALUEFUNC(GetVendorName), 0);
	rb_define_method(rubyClass, "set_app_name", VALUEFUNC(SetAppName), 1);
	rb_define_method(rubyClass, "set_class_name", VALUEFUNC(SetClassName), 1);
	rb_define_method(rubyClass, "set_vendor_name", VALUEFUNC(SetVendorName), 1);
	rb_define_method(rubyClass, "yield", VALUEFUNC(Yield), 0);
}

wxAppWithCallbacks* WxApp::GetPtr(VALUE self)
{
	wxAppWithCallbacks *ptr;
	Data_Get_Struct(self, wxAppWithCallbacks, ptr);
	return ptr;
}

VALUE WxApp::alloc(VALUE self)
{
	return Data_Wrap_Struct(self, 0, free, 0);
}

void WxApp::free(wxAppWithCallbacks *ptr)
{
	if (ptr) {
		delete(ptr);
	}
}

VALUE WxApp::init(VALUE self)
{
	wxAppWithCallbacks *pCppSelf = GetPtr(self);
	pCppSelf = new wxAppWithCallbacks();
	DATA_PTR(self) = pCppSelf;

	extern VALUE rb_cRbApp;
	rb_cRbApp = self;

	rubyClass = self;
	pCppSelf->SetAppName("wxruby");

	extern int  wxEntryInitGui();
	wxEntryInitGui();
	if(rb_respond_to(self,rb_intern("on_init")))
	  rb_funcall(self,rb_intern("on_init"),0);
	else if(rb_respond_to(self,rb_intern("OnInit")))
	  rb_funcall(self,rb_intern("OnInit"),0);

	return self;
}


VALUE WxApp::MainLoop(VALUE self)
{
	wxAppWithCallbacks *pCppSelf = GetPtr(self);
	return INT2NUM(pCppSelf->MainLoop());
}

VALUE WxApp::ExitMainLoop(VALUE self)
{
	wxAppWithCallbacks *pCppSelf = GetPtr(self);
	pCppSelf->ExitMainLoop();
	return Qnil;
}

void WxApp::SetTopWindow(VALUE self,VALUE vwin)
{
	wxWindow *win;
	Data_Get_Struct(vwin, wxWindow, win);
	wxAppWithCallbacks *pCppSelf = GetPtr(self);
	pCppSelf->SetTopWindow(win);
}

VALUE WxApp::GetAppName(VALUE self)
{
	wxAppWithCallbacks *pCppSelf = GetPtr(self);
	return rb_str_new2(pCppSelf->GetAppName());
}

void WxApp::SetAppName(VALUE self,VALUE vname)
{
	wxString name = StringValuePtr(vname);
	wxAppWithCallbacks *pCppSelf = GetPtr(self);
	pCppSelf->SetAppName(name);
}

VALUE WxApp::GetClassName(VALUE self)
{
	wxAppWithCallbacks *pCppSelf = GetPtr(self);
	return rb_str_new2(pCppSelf->GetClassName());
}

void WxApp::SetClassName(VALUE self,VALUE vname)
{
	wxString name = StringValuePtr(vname);
	wxAppWithCallbacks *pCppSelf = GetPtr(self);
	pCppSelf->SetClassName(name);
}

VALUE WxApp::GetVendorName(VALUE self)
{
	wxAppWithCallbacks *pCppSelf = GetPtr(self);
	return rb_str_new2(pCppSelf->GetVendorName());
}

void WxApp::SetVendorName(VALUE self,VALUE vname)
{
	wxString name = StringValuePtr(vname);
	wxAppWithCallbacks *pCppSelf = GetPtr(self);
	pCppSelf->SetVendorName(name);
}

void WxApp::Yield(VALUE self)
{
	wxAppWithCallbacks *pCppSelf = GetPtr(self);
	pCppSelf->Yield();
}

VALUE WxApp::rubyClass;

class ZAutoDefineWxApp
{
public:
   ZAutoDefineWxApp()
    {
       WxApp::DefineClass();
    }
};
static ZAutoDefineWxApp x;
