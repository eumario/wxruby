#   Copyright 2004 by Kevin Smith
#   released under the wxWidgets license
#   as part of the wxRuby project
%include "../common.i"

%module(directors="1") wxApp

%{
#ifdef __WXMAC__
int wxEntry( int argc, char *argv[],bool val=true );
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
    virtual ~wxRubyApp()
    {
        printf("~wxRubyApp\n");
    }

    int main_loop()
    {
        static int argc = 1;
        static char *argv[] = {"wxruby", NULL};
        printf("Calling wxEntry, this=%p\n", this);
#ifdef __WXMSW__
		extern int  wxEntry(WXHINSTANCE hInstance,
            WXHINSTANCE WXUNUSED(hPrevInstance),
            char *lpCmdLine,
            int nCmdShow,
            bool enterLoop);
        printf("Module handle = %d\n",GetModuleHandle(NULL));
		wxEntry(GetModuleHandle(NULL),0,"",true,true);
		
#else     
        wxEntry(argc,argv);
#endif        
		

        printf("returned from wxEntry...\n");
        rb_gc_start();
        printf("survived gc\n");
        return 0;
    }
    
    virtual bool OnInitGui()
    {
        Init_wxRubyEventTypes();
        
        printf("OnInitGui before\n");
        bool result = wxApp::OnInitGui();
        printf("OnInitGui after\n");
        if(result)
            Init_wxRubyStockObjects();
        return result;
    }

    virtual int OnExit()
    {
        printf("OnExit...\n");
        rb_gc_start();
        printf("survived gc\n");
        wxTheApp = 0;
        wxLog *oldlog = wxLog::SetActiveTarget(new wxLogStderr);
        SetTopWindow(0);
        if ( oldlog )
        {
            printf("Deleting oldlog...\n");
            delete oldlog;
            printf("worked\n");
        }
        return 0;
    }
};
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
  bool SendIdleEvents() ;
  bool SendIdleEvents(wxWindow*  win ) ;
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
