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
#if 0
#define wxUSE_THREADS 1
#define wxUSE_LOG 1
#define __WXDEBUG__ 1

#include <wx/filename.h>

extern "C" void gtk_set_locale();
extern "C" void gtk_init(int* argc, char** argv[]);
extern "C" void gdk_threads_enter();
extern "C" void gdk_threads_leave();
#define g_thread_supported() 1
extern "C" void g_thread_init(void *vtable);
extern int gtk_major_version;
extern int gtk_minor_version;
extern int gtk_micro_version;

extern GtkWidget* wxGetRootWindow();
extern int wxEntryStart( int& argc, char *argv[] );
extern int wxEntryInitGui();
extern void wxEntryCleanup();



//extern void wxTrap();
//-----------------------------------------------------------------------------
// wxEntry
//-----------------------------------------------------------------------------

#if 0
// NB: argc and argv may be changed here, pass by reference!
int wxEntryStart( int& argc, char *argv[] )
{
#if wxUSE_THREADS
    // GTK 1.2 up to version 1.2.3 has broken threads
    if ((gtk_major_version == 1) &&
        (gtk_minor_version == 2) &&
        (gtk_micro_version < 4))
    {
        printf( "wxWindows warning: GUI threading disabled due to outdated GTK version\n" );
    }
    else
    {
        if (!g_thread_supported())
            g_thread_init(NULL);
    }
#endif

    gtk_set_locale();

    // We should have the wxUSE_WCHAR_T test on the _outside_
#if wxUSE_WCHAR_T
#if defined(__WXGTK20__)
    // gtk+ 2.0 supports Unicode through UTF-8 strings
    wxConvCurrent = &wxConvUTF8;
#else
    if (!wxOKlibc()) wxConvCurrent = &wxConvLocal;
#endif
#else
    if (!wxOKlibc()) wxConvCurrent = (wxMBConv*) NULL;
#endif

    gtk_init( &argc, &argv );

    /* we can not enter threads before gtk_init is done */
    gdk_threads_enter();

    wxSetDetectableAutoRepeat( TRUE );

    if (!wxApp::Initialize())
    {
        gdk_threads_leave();
        return -1;
    }

    return 0;
}

int wxEntryInitGui()
{
//printf("In wxEntryInitGui\n");
    int retValue = 0;

    if ( !wxTheApp->OnInitGui() )
        retValue = -1;

    wxGetRootWindow();
//printf("Exiting wxEntryInitGui with %d\n", retValue);
    return retValue;
}

void wxEntryCleanup()
{
#if wxUSE_LOG
    // flush the logged messages if any
    wxLog *log = wxLog::GetActiveTarget();
    if (log != NULL && log->HasPendingMessages())
        log->Flush();

    // continuing to use user defined log target is unsafe from now on because
    // some resources may be already unavailable, so replace it by something
    // more safe
    wxLog *oldlog = wxLog::SetActiveTarget(new wxLogStderr);
    if ( oldlog )
        delete oldlog;
#endif // wxUSE_LOG

    wxApp::CleanUp();

    gdk_threads_leave();
}
#endif

int wxEntry( int argc, char *argv[] )
{
printf("in wxEntry, wxTheApp=%p\n", wxTheApp);
#if (defined(__WXDEBUG__) && wxUSE_MEMORY_TRACING) || wxUSE_DEBUG_CONTEXT
    // This seems to be necessary since there are 'rogue'
    // objects present at this point (perhaps global objects?)
    // Setting a checkpoint will ignore them as far as the
    // memory checking facility is concerned.
    // Of course you may argue that memory allocated in globals should be
    // checked, but this is a reasonable compromise.
    wxDebugContext::SetCheckpoint();
#endif
printf("b\n");
    int err = wxEntryStart(argc, argv);
printf("c\n");
    if (err)
        return err;

    if (!wxTheApp)
    {
        wxCHECK_MSG( wxApp::GetInitializerFunction(), -1,
                     wxT("wxWindows error: No initializer - use IMPLEMENT_APP macro.\n") );

        wxAppInitializerFunction app_ini = wxApp::GetInitializerFunction();

        wxObject *test_app = app_ini();

        wxTheApp = (wxApp*) test_app;
    }

printf("d\n");
    wxCHECK_MSG( wxTheApp, -1, wxT("wxWindows error: no application object") );

printf("e\n");
    wxTheApp->argc = argc;
#if wxUSE_UNICODE
    wxTheApp->argv = new wxChar*[argc+1];
    int mb_argc = 0;
    while (mb_argc < argc)
    {
        wxTheApp->argv[mb_argc] = wxStrdup(wxConvLibc.cMB2WX(argv[mb_argc]));
        mb_argc++;
    }
    wxTheApp->argv[mb_argc] = (wxChar *)NULL;
#else
    wxTheApp->argv = argv;
#endif

printf("f\n");
    if (wxTheApp->argc > 0)
    {
        wxFileName fname( wxTheApp->argv[0] );
        wxTheApp->SetAppName( fname.GetName() );
    }
wxTrap();
printf("about to call wxEntryInitGui, wxTheApp=%p\n", wxTheApp);
    int retValue;
    retValue = wxEntryInitGui();
printf("wxEntryInitGui returned %d\n", retValue);

    // Here frames insert themselves automatically into wxTopLevelWindows by
    // getting created in OnInit().
    if ( retValue == 0 )
    {
printf("about to call OnInit, wxTheApp=%p\n", wxTheApp);
        if ( !wxTheApp->OnInit() )
            retValue = -1;
printf("returned from OnInit, retValue=%d\n", retValue);
    }

printf("k\n");
    if ( retValue == 0 )
    {
printf("l\n");
        // Delete pending toplevel windows
        wxTheApp->DeletePendingObjects();

        // When is the app not initialized ?
        wxTheApp->m_initialized = TRUE;

        if (wxTheApp->Initialized())
        {
            wxTheApp->OnRun();

            wxWindow *topWindow = wxTheApp->GetTopWindow();

            // Delete all pending windows if any
            wxTheApp->DeletePendingObjects();

            // Reset top window
            if (topWindow)
                wxTheApp->SetTopWindow( (wxWindow*) NULL );

            retValue = wxTheApp->OnExit();
        }
    }
printf("m\n");

    wxEntryCleanup();
printf("n\n");

    return retValue;
}

#endif

///////////////////////////////////////////////////
extern "C" void Init_wxRubyStockObjects();

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
