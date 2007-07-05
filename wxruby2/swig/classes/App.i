// Copyright 2004-2007 by Kevin Smith
// released under the MIT-like wxRuby license

%include "../common.i"

%module(directors="1") wxApp

%{
#include <wx/init.h>
%}


// Not supported
%ignore GetAuto3D;
%ignore OnQueryEndSession;
%ignore ProcessMessage;
%ignore SetAuto3D;

// Redefined below
%ignore MainLoop;
%ignore FilterEvent;

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
	GC_SetWindowDeleted(wx_obj);
	event.Skip();
  }


  static VALUE mark_iterate(VALUE pair, VALUE arg, VALUE self) 
  {
	VALUE key, val;

	key = rb_ary_entry(pair, 0);
	val = rb_ary_entry(pair, 1);
	VALUE rb_obj = SWIG_RubyReferenceToObject(val);

	// Check if it's a valid object (sometimes SWIG doesn't return what we're
	// expecting), a descendant of Wx::Window, and if it has not yet been
	// deleted by WxWidgets; if so, mark it.
	if ( TYPE(rb_obj) == T_DATA &&
		 rb_obj_is_kind_of(rb_obj, cWxWindow.klass) && 
		 rb_iv_get(rb_obj, "@__wx_destroyed__") != Qtrue )
	  {
		rb_gc_mark(rb_obj);
	  }
	return Qnil;
  }

  // Implements GC protection. Always called because Wx::THE_APP is a 
  // so always checked in GC mark phase. 
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

	// To do the marking, iterate over SWIG's hash list of known wrapped
	// objects (swig_ruby_trackings) and check each one.
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


  int FilterEvent(wxEvent& event) {
	VALUE rb_self = SWIG_RubyInstanceFor(this);
	// Just proceed if no ruby filter_event method is defined in App class
	// filter_event_sym defined above
	if ( ! rb_respond_to(rb_self, filter_event_sym) ) 
	  { return -1; }
	// else wrap the event and pass into that method
	VALUE event_type_id =  INT2NUM(event.GetEventType());
	VALUE event_klass = rb_funcall(cWxEvtHandler.klass, 
								   rb_intern("event_class_for_type"),
								   1, event_type_id ); 	  

	VALUE rb_event = Data_Wrap_Struct(event_klass, 0, 0, 0);
	DATA_PTR(rb_event) = &event;

	VALUE rb_ret_val = rb_funcall(rb_self, filter_event_sym, 1, rb_event);
	if ( ! FIXNUM_P(rb_ret_val)  )
	  { rb_raise(rb_eTypeError, "filter_event must return an integer"); }
	int ret_val = FIX2INT(rb_ret_val);
	if ( ret_val < -1 || ret_val > 1  )
	  { rb_raise(rb_eRuntimeError, "filter_event must return -1, 0, or 1"); }

	return ret_val;
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
