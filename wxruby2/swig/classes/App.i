// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxApp

%{
#include <wx/init.h>
%}


%ignore GetAuto3D;
%ignore OnQueryEndSession;
%ignore ProcessMessage;
%ignore SetAuto3D;

%ignore MainLoop;
%rename(wx_initialize) Initialize;

#//////////////////////////////////
%rename(App) wxRubyApp;

// Prevent the App being destroyed prematurely when Ruby exits down with
// an exception. Otherwise GC destroys the C++ object, which can still
// be needed for final WxWidgets events.
GC_NEVER(wxRubyApp);

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"

%{

extern swig_class cWxEvtHandler;
extern swig_class cWxWindow;
extern swig_class cWxEvent;
extern "C" void Init_wxRubyStockObjects();


class wxRubyApp : public wxApp
{
    
public:


  virtual ~wxRubyApp()
  {
#ifdef __WXDEBUG__    
	printf("~wxRubyApp\n");
#endif	
    }

  // special event handler for destruction of windows which is done
  // automatically by wxWidgets. Tag the object as having been destroyed
  // by WxWidgets.
  void OnWindowDestroy(wxWindowDestroyEvent &event) 
  {
	wxObject* wx_obj = event.GetEventObject();
	// Would be neater - but can't do it this way b/c of destruction sequence
	// SWIG_RubyUnlinkObjects((void *)wx_obj);

	VALUE rb_obj = SWIG_RubyInstanceFor((void *)wx_obj);
	rb_iv_set(rb_obj, "@__wx_destroyed__", Qtrue);
	event.Skip();
  }


  static VALUE mark_iterate(VALUE pair, VALUE arg, VALUE self) 
  {
	VALUE key, val;

	key = rb_ary_entry(pair, 0);
	val = rb_ary_entry(pair, 1);
	VALUE rb_obj = SWIG_RubyReferenceToObject(val);
	// Check if it's a descendant of Wx::Window, and if it has not yet been
	// deleted by WxWidgets.
	if ( rb_obj_is_kind_of(rb_obj, cWxWindow.klass) && 
		 rb_iv_get(rb_obj, "@__wx_destroyed__") != Qtrue )
	  {
		rb_gc_mark(rb_obj);
	  }
	return Qnil;
  }

  static void mark_wxRubyApp(void *ptr)
  {

#ifdef __WXDEBUG__
	printf("=== Starting App GC mark phase\n");
#endif

	// If the App has ended, the ruby object will have been unlinked from 
	// the C++ one; this implies that all Windows have already been destroyed
	// so there is no point trying to mark them, and doing so may cause 
	// errors.
	VALUE the_app = rb_const_get(mWxruby2, rb_intern("THE_APP"));
	if ( DATA_PTR(the_app) == 0 ) 
	  {
		return;
	  }

	rb_iterate(rb_each, swig_ruby_trackings, (VALUE(*)(...))mark_iterate, Qnil);
#ifdef __WXDEBUG__
        printf("=== App GC mark phase completed\n");
#endif

  }

  // This is the method run when main_loop is called in Ruby
  // wxEntry calls the C++ App::OnInit method
    int main_loop()
    {
	  rb_define_const(mWxruby2, "THE_APP", SWIG_RubyInstanceFor(this));
	  static int argc = 1;
	  static wxChar *argv[] = {wxT("wxruby"), NULL};
	  this->Connect(wxEVT_DESTROY,
					wxWindowDestroyEventHandler(wxRubyApp::OnWindowDestroy));

#ifdef __WXDEBUG__
        printf("Calling wxEntry, this=%p\n", this);
#endif

#ifdef __WXMSW__
		extern int wxEntry(HINSTANCE hInstance,
						   HINSTANCE WXUNUSED(hPrevInstance),
						   wxCmdLineArgType WXUNUSED(pCmdLine),
						   int nCmdShow);
		wxEntry(GetModuleHandle(NULL),(HINSTANCE)0,(wxCmdLineArgType)"",(int)true);
#elif __WXMAC__
		wxEntry(argc,(char **)argv);
#else
		wxEntry(argc, argv);
#endif        

#ifdef __WXDEBUG__
        printf("returned from wxEntry...\n");
#endif	
        rb_gc_start();
#ifdef __WXDEBUG__	
        printf("survived gc\n");
#endif	
        return 0;
    }
    
    // This method initializes the stock objects (Pens, Brushes, Fonts) 
    // before yielding to ruby by calling the App's on_init method.
    // Note that as of wxWidget 2.8, the stock fonts in particular cannot
    // be initialized any earlier than this without crashing
    bool OnInit()
    {
      Init_wxRubyStockObjects();
	  VALUE the_app = rb_const_get(mWxruby2, rb_intern("THE_APP"));
	  VALUE result  = rb_funcall(the_app, rb_intern("on_init"), 0, NULL);
	  if ( result == Qfalse || result == Qnil ) { 
		return false; 
	  }
  	  else { 
		return true; 
	  }
    }

    virtual int OnExit()
    {


#ifdef __WXDEBUG__	
        printf("OnExit...\n");
#endif 

		// unhook the App ruby object from the C++ object
		SWIG_RubyUnlinkObjects((void *)this);

        wxLog *oldlog = wxLog::SetActiveTarget(new wxLogStderr);
        SetTopWindow(0);
        if ( oldlog )
		  {
			delete oldlog;
			
		  }

        return 0;
		
    }
	
    // actually implemented in ruby in classes/app.rb
	virtual void OnAssertFailure(const wxChar *file, int line, const wxChar *cond, const wxChar *msg)
	{
		printf("ASSERT fired\n");
	}

};

%}

%markfunc wxRubyApp "wxRubyApp::mark_wxRubyApp";

class wxRubyApp : public wxApp
{
public:
   wxRubyApp() ;
  virtual  ~wxApp() ;
  void Dispatch() ;
  virtual int FilterEvent(wxEvent&  event ) ;
  wxString GetAppName() const;
  bool GetAuto3D() const;
  wxString GetClassName() const;
  bool GetExitOnFrameDelete() const;
  virtual wxWindow * GetTopWindow() const;
  bool GetUseBestVisual() const;
  wxString GetVendorName() const;
  void ExitMainLoop() ;
  int MainLoop() ;
  virtual void OnAssertFailure(const wxChar *file, int line, const wxChar *cond, const wxChar *msg);
  virtual int OnExit() ;
  virtual bool OnCmdLineError(wxCmdLineParser&  parser ) ;
  virtual bool OnCmdLineHelp(wxCmdLineParser&  parser ) ;
  virtual bool OnCmdLineParsed(wxCmdLineParser&  parser ) ;
  virtual void OnFatalException() ;
  bool OnInit() ;
  virtual void OnInitCmdLine(wxCmdLineParser&  parser ) ;
  ;
  bool ProcessMessage(WXMSG * msg ) ;
  bool Pending() ;
#if 0
  bool SendIdleEvents() ;
  bool SendIdleEvents(wxWindow*  win ) ;
#endif
  void SetAppName(const wxString&  name ) ;
  void SetAuto3D(const bool  auto3D ) ;
  void SetClassName(const wxString&  name ) ;
  void SetExitOnFrameDelete(bool  flag ) ;
  void SetTopWindow(wxWindow*  window ) ;
  void SetVendorName(const wxString&  name ) ;
  void SetUseBestVisual(bool  flag ) ;
  bool Yield(bool onlyIfNeeded = false) ;
  int main_loop();
};
