#   Copyright 2004 by Kevin Smith
#   released under the wxWidgets license
#   as part of the wxRuby project
%include "../common.i"

%module(directors="1") wxApp

%{
#ifdef __WXMAC__
#if wxMINOR_VERSION == 4
int wxEntry( int argc, char *argv[],bool val=true );
#else
int wxEntry( int &argc, char *argv[]);
#endif
#else
int wxEntry( int argc, char *argv[]);
#endif
%}

%ignore GetAuto3D;
%ignore OnAssert;
%ignore OnQueryEndSession;
%ignore ProcessMessage;
%ignore SetAuto3D;

%ignore MainLoop;
%rename(wx_initialize) Initialize;

#//////////////////////////////////
%rename(App) wxRubyApp;

%{

extern swig_class cWxEvtHandler;


///////////////////////////////////////////////////
extern "C" void Init_wxRubyStockObjects();
extern "C" void Init_wxRubyEventTypes();

class wxRubyApp : public wxApp
{
    
public:
    static VALUE app_ptr;


    virtual ~wxRubyApp()
    {
#ifdef wxDEBUG    
        printf("~wxRubyApp\n");
#endif	
    }

    int main_loop()
    {
        static int argc = 1;
        static char *argv[] = {"wxruby", NULL};
#ifdef wxDEBUG
        printf("Calling wxEntry, this=%p\n", this);
#endif

#ifdef __WXMSW__

#if wxMINOR_VERSION == 4
		    extern int  wxEntry(WXHINSTANCE hInstance,
            WXHINSTANCE WXUNUSED(hPrevInstance),
            char *lpCmdLine,
            int nCmdShow,
            bool enterLoop);
	    wxEntry(GetModuleHandle(NULL),0,"",true,true);
#else
		    extern int wxEntry(HINSTANCE hInstance,
                        HINSTANCE WXUNUSED(hPrevInstance),
                        wxCmdLineArgType WXUNUSED(pCmdLine),
                        int nCmdShow);
	    wxEntry(GetModuleHandle(NULL),(HINSTANCE)0,(wxCmdLineArgType)"",(int)true);
#endif
        
	
		
#else     
        wxEntry((const int)argc,(char **)argv);
#endif        
		
#ifdef wxDEBUG
        printf("returned from wxEntry...\n");
#endif	
        rb_gc_start();
#ifdef wxDEBUG	
        printf("survived gc\n");
#endif	
        return 0;
    }
    
    virtual bool OnInitGui()
    {
#ifdef wxDEBUG        
        printf("OnInitGui before\n");
#endif	
        bool result = wxApp::OnInitGui();
#ifdef wxDEBUG	
        printf("OnInitGui after\n");
#endif	
        if(result)
        {
            Init_wxRubyEventTypes();
            Init_wxRubyStockObjects();
        }
        return result;
    }

    virtual int OnExit()
    {
#ifdef wxDEBUG    
        printf("OnExit...\n");
#endif	
        rb_gc_start();
#ifdef wxDEBUG	
        printf("survived gc\n");
#endif

#if !wxCHECK_VERSION(2,5,0)
        wxTheApp = 0;
#endif
        wxLog *oldlog = wxLog::SetActiveTarget(new wxLogStderr);
        SetTopWindow(0);
        if ( oldlog )
        {
#ifdef wxDEBUG
	    printf("Deleting oldlog...\n");
#endif	    
            delete oldlog;
#ifdef wxDEBUG	    
            printf("worked\n");
#endif	    
        }
        return 0;
    }
};

VALUE wxRubyApp::app_ptr = Qnil;



%}

class wxRubyApp : public wxApp
{
public:
   wxRubyApp() ;
  virtual  ~wxApp() ;
  virtual wxLog* CreateLogTarget() ;
  void Dispatch() ;
  int FilterEvent(wxEvent&  event ) ;
  wxString GetAppName() const;
  bool GetAuto3D() const;
  wxString GetClassName() const;
  bool GetExitOnFrameDelete() const;
  virtual wxWindow * GetTopWindow() const;
  bool GetUseBestVisual() const;
  wxString GetVendorName() const;
  void ExitMainLoop() ;
  bool Initialized() ;
  int MainLoop() ;
  ;
  virtual int OnExit() ;
  virtual bool OnCmdLineError(wxCmdLineParser&  parser ) ;
  virtual bool OnCmdLineHelp(wxCmdLineParser&  parser ) ;
  virtual bool OnCmdLineParsed(wxCmdLineParser&  parser ) ;
  virtual void OnFatalException() ;
  virtual bool OnInit() ;
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

%extend wxRubyApp {

}

