// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

%include "../common.i"

%module(directors="1") wxApp

%{
#include <wx/init.h>
extern "C" {
#include <st.h>
}
%}


// Not supported
%ignore GetAuto3D;
%ignore OnQueryEndSession;
%ignore ProcessMessage;
%ignore SetAuto3D;

// Not useful - command line parsing would be done using ruby's libraries
%ignore OnCmdLineError;
%feature("nodirector") OnCmdLineError;
%ignore OnCmdLineHelp;
%feature("nodirector") OnCmdLineHelp;
%ignore OnCmdLineParsed;
%feature("nodirector") OnCmdLineParsed;
%ignore OnInitCmdLine;
%feature("nodirector") OnInitCmdLine;

// Redefined below
%ignore MainLoop;

// Avoid exception on exit
%feature("nodirector") GetTopWindow;

%rename(wx_initialize) Initialize;

// The App class in wxRuby is actually a custom-written subclass, but it
// is presented to the user as Wx::App
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
extern void GC_SetWindowDeleted(void*);
extern "C" void Init_wxRubyStockObjects();

// Pre-fetched id because it's called very frequently in wxRubyApp::FilterEvent
static VALUE filter_event_sym = rb_intern("filter_event");

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
	GC_SetWindowDeleted((void *)wx_obj);
	event.Skip();
  }

  // When ruby's garbage collection runs, if the app is still active, it
  // cycles through all currently known SWIG objects and calls this
  // function on each to preserve still active Wx::Windows.
  static int markIterate(VALUE key, VALUE value, int lev)
  {
	VALUE rb_obj = SWIG_RubyReferenceToObject(value);
	// Check if it's a valid object (sometimes SWIG doesn't return what we're
	// expecting), a descendant of Wx::Window, and if it has not yet been
	// deleted by WxWidgets; if so, mark it.
	if ( TYPE(rb_obj) == T_DATA && rb_obj_is_kind_of(rb_obj, cWxWindow.klass) )
	  {
		rb_gc_mark(rb_obj);
	  }
	return ST_CONTINUE;
  }

  // Implements GC protection across wxRuby. Always called because
  // Wx::THE_APP is a constant so always checked in GC mark phase.
  static void mark_wxRubyApp(void *ptr)
  {

#ifdef __WXDEBUG__
	printf("=== Starting App GC mark phase\n");
#endif

	// If the App has ended, the ruby object will have been unlinked from 
	// the C++ one; this implies that all Windows have already been destroyed
	// so there is no point trying to mark them, and doing so may cause 
	// errors.
    if ( rb_gv_get("__wx_app_ended__" ) == Qtrue )
      {
#ifdef __WXDEBUG__
	printf("=== App has ended, skipping mark phase\n");
#endif
        return;
      }

	// To do the marking, iterate over SWIG's list of objects. Note, we
	// have to use the low-level st_foreach here, b/c rb_iterate creates
	// a new object which is a bug in latest 1.8 ruby.
    st_foreach(RHASH(swig_ruby_trackings)->tbl,
               (int(*)(...))(wxRubyApp::markIterate), 0);

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
      // Get the ruby representation of the App object, and call the
      // ruby on_init method to set up the initial window state
	  VALUE the_app = rb_const_get(mWxruby2, rb_intern("THE_APP"));
	  VALUE result  = rb_funcall(the_app, rb_intern("on_init"), 0, NULL);
      
      // If on_init return any (ruby) true value, signal to wxWidgets to
      // enter the main event loop by returning true, else return false
      // which will make wxWidgets exit.
	  if ( result == Qfalse || result == Qnil )
        {
		  rb_gv_set("__wx_app_ended__", Qtrue); // Don't do any more GC
		  return false; 
		}
      else
		{
		  return true; 
		}
    }

    virtual int OnExit()
    {
#ifdef __WXDEBUG__	
        printf("OnExit...\n");
#endif 
        // Note in a global variable that the App has ended, so that we
        // can skip any GC marking later
        rb_gv_set("__wx_app_ended__", Qtrue);
		VALUE the_app = rb_const_get(mWxruby2, rb_intern("THE_APP"));
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
  static bool IsMainLoopRunning();
  bool IsActive() const;
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
