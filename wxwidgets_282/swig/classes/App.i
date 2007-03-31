#   Copyright 2004-2005 by Kevin Smith
#   released under the MIT-style wxruby2 license

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

%import "include/wxObject.h"
%import "include/wxEvtHandler.h"

%{

extern swig_class cWxEvtHandler;
extern "C" void Init_wxRubyStockObjects();


class wxRubyApp : public wxApp
{
    
public:
    static VALUE app_ptr;


    virtual ~wxRubyApp()
    {
#ifdef __WXDEBUG__    
        printf("~wxRubyApp\n");
#endif	
    }

  // This is the method run when main_loop is called in Ruby
  // wxEntry calls the C++ App::OnInit method
    int main_loop()
    {
        static int argc = 1;
        static wxChar *argv[] = {wxT("wxruby"), NULL};
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
	  VALUE result = rb_funcall(wxRubyApp::app_ptr, rb_intern("on_init"), 0, NULL);
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
        rb_gc_start();
#ifdef __WXDEBUG__	
        printf("survived gc\n");
#endif

        wxLog *oldlog = wxLog::SetActiveTarget(new wxLogStderr);
        SetTopWindow(0);
        if ( oldlog )
        {
#ifdef __WXDEBUG__
	    printf("Deleting oldlog...\n");
#endif	    
            delete oldlog;
#ifdef __WXDEBUG__	    
            printf("worked\n");
#endif	    
        }
        return 0;
    }
	
    // actually implemented in ruby in classes/app.rb
	virtual void OnAssertFailure(const wxChar *file, int line, const wxChar *cond, const wxChar *msg)
	{
		printf("ASSERT fired\n");
	}

};

VALUE wxRubyApp::app_ptr = Qnil;

%}

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
