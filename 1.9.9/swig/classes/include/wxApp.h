// wxApp.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxApp_h_)
#define _wxApp_h_
class wxApp : public wxEvtHandler
{
public:
	/**
	 * \brief Constructor. Called implicitly with a definition of a wxApp object. 
	*/

   wxApp() ;
	/**
	 * \brief Destructor. Will be called implicitly on program exit if the wxApp
object is created on the stack. 
	*/

  virtual  ~wxApp() ;
	/**
	 * \brief Creates a wxLog class for the application to use for logging errors. The default
implementation returns a new wxLogGui class. 
	*/

  virtual wxLog* CreateLogTarget() ;
	/**
	 * \brief Dispatches the next event in the windowing system event queue.

This can be used for programming event loops, e.g. 
	*/

  void Dispatch() ;
	/**
	 * \brief This function is called before processing any event and allows the application
to preempt the processing of some events. If this method returns $-1$ the event
is processed normally, otherwise either   or   should be
returned and the event processing stops immediately considering that the event
had been already processed (for the former return value) or that it is not
going to be processed at all (for the latter one). 
	 * \param wxEvent&   
	*/

virtual int FilterEvent(wxEvent&  event ) ;
	/**
	 * \brief Returns the application name. 
	*/

  wxString GetAppName() const;
	/**
	 * \brief Returns true if 3D control mode is on, false otherwise. 
	*/

  bool GetAuto3D() const;
	/**
	 * \brief Gets the class name of the application. The class name may be used in a platform specific
manner to refer to the application. 
	*/

  wxString GetClassName() const;
	/**
	 * \brief Returns true if the application will exit when the top-level window is deleted, false
otherwise. 
	*/

  bool GetExitOnFrameDelete() const;
	/**
	 * \brief Returns a pointer to the top window. 
	*/

  virtual wxWindow * GetTopWindow() const;
	/**
	 * \brief Returns true if the application will use the best visual on systems that support
different visuals, false otherwise. 
	*/

  bool GetUseBestVisual() const;
	/**
	 * \brief Returns the application's vendor name. 
	*/

  wxString GetVendorName() const;
	/**
	 * \brief Call this to explicitly exit the main message (event) loop.
You should normally exit the main loop (and the application) by deleting
the top window. 
	*/

  void ExitMainLoop() ;
	/**
	 * \brief Returns true if the application has been initialized (i.e. if
  has returned successfully).  This can be useful for error
message routines to determine which method of output is best for the
current state of the program (some windowing systems may not like
dialogs to pop up before the main loop has been entered). 
	*/

  bool Initialized() ;
	/**
	 * \brief Called by wxWindows on creation of the application. Override this if you wish
to provide your own (environment-dependent) main loop. 
	*/

  int MainLoop() ;
	/**
	 * \brief This function is called when an assert failure occurs, i.e. the condition
specified in   macro evaluated to  .
It is only called in debug mode (when   is defined) as
asserts are not left in the release code at all.

The base class version show the default assert failure dialog box proposing to
the user to stop the program, continue or ignore all subsequent asserts. 
	 * \param const wxChar   
	 * \param int   
	 * \param const wxChar   
	 * \param const wxChar   
	*/

  ;
	/**
	 * \brief Provide this member function for any processing which needs to be
done as the application is about to exit. OnExit is called after
destroying all application windows and controls, but before
wxWindows cleanup. 
	*/

  virtual int OnExit() ;
	/**
	 * \brief Called when command line parsing fails (i.e. an incorrect command line option
was specified by the user). The default behaviour is to show the program usage
text and abort the program.

Return   to continue normal execution or   to return 
  from   thus terminating the program. 
	 * \param wxCmdLineParser&   
	*/

  virtual bool OnCmdLineError(wxCmdLineParser&  parser ) ;
	/**
	 * \brief Called when the help option ( ) was specified on the command line.
The default behaviour is to show the program usage text and abort the program.

Return   to continue normal execution or   to return 
  from   thus terminating the program. 
	 * \param wxCmdLineParser&   
	*/

  virtual bool OnCmdLineHelp(wxCmdLineParser&  parser ) ;
	/**
	 * \brief Called after the command line had been successfully parsed. You may override
this method to test for the values of the various parameters which could be
set from the command line.

Don't forget to call the base class version unless you want to suppress
processing of the standard command line options.

Return   to continue normal execution or   to return 
  from   thus terminating the program. 
	 * \param wxCmdLineParser&   
	*/

  virtual bool OnCmdLineParsed(wxCmdLineParser&  parser ) ;
	/**
	 * \brief This function may be called if something fatal happens: an unhandled
exception under Win32 or a a fatal signal under Unix, for example. However,
this will not happen by default: you have to explicitly call 
  to enable this.

Generally speaking, this function should only show a message to the user and
return. You may attempt to save unsaved data but this is not guaranteed to
work and, in fact, probably won't. 
	*/

  virtual void OnFatalException() ;
	/**
	 * \brief This must be provided by the application, and will usually create the
application's main window, optionally calling 
 .

Notice that if you want to to use the command line processing provided by
wxWindows you have to call the base class version in the derived class
OnInit().

Return true to continue processing, false to exit the application. 
	*/

  virtual bool OnInit() ;
	/**
	 * \brief Called from   and may be used to initialize the
parser with the command line options for this application. The base class
versions adds support for a few standard options only. 
	 * \param wxCmdLineParser&   
	*/

  virtual void OnInitCmdLine(wxCmdLineParser&  parser ) ;
	/**
	 * \brief This is an event handler function called when the operating system or GUI session is
about to close down. Typically, an application will try to save unsaved documents
at this point.

If   returns true, the application
is allowed to veto the shutdown by calling  .
The application might veto the shutdown after prompting for documents to be saved, and the
user has cancelled the save.

Use the EVT_QUERY_END_SESSION event table macro to handle query end session events.

You should check whether the application is forcing the deletion of the window
using  . If this is true,
destroy the window using  .
If not, it is up to you whether you respond by destroying the window.

The default handler calls   on the top-level window,
and vetoes the shutdown if Close returns false. This will be sufficient for many applications. 
	 * \param wxCloseEvent&   
	*/

  virtual void OnQueryEndSession(wxCloseEvent&  event ) ;
	/**
	 * \brief Windows-only function for processing a message. This function
is called from the main message loop, checking for windows that
may wish to process it. The function returns true if the message
was processed, false otherwise. If you use wxWindows with another class
library with its own message loop, you should make sure that this
function is called to allow wxWindows to receive messages. For example,
to allow co-existence with the Microsoft Foundation Classes, override
the PreTranslateMessage function: 
	 * \param WXMSG *  
	*/

  bool ProcessMessage(WXMSG * msg ) ;
	/**
	 * \brief Returns true if unprocessed events are in the window system event queue. 
	*/

  bool Pending() ;
	/**
	 * \brief Sends idle events to all top-level windows. 
	*/

  //bool SendIdleEvents();
	/**
	 * \brief Sends idle events to a window and its children. 
	 * \param wxWindow*  
	*/

  bool SendIdleEvents(wxWindow*  win, wxIdleEvent &evt );
	/**
	 * \brief Sets the name of the application. The name may be used in dialogs
(for example by the document/view framework). A default name is set by
wxWindows. 
	 * \param const wxString&   
	*/

  void SetAppName(const wxString&  name ) ;
	/**
	 * \brief Switches automatic 3D controls on or off. 
	 * \param const bool  
	*/

  void SetAuto3D(const bool  auto3D ) ;
	/**
	 * \brief Sets the class name of the application. This may be used in a platform specific
manner to refer to the application. 
	 * \param const wxString&   
	*/

  void SetClassName(const wxString&  name ) ;
	/**
	 * \brief Allows the programmer to specify whether the application will exit when the
top-level frame is deleted. 
	 * \param bool  
	*/

  void SetExitOnFrameDelete(bool  flag ) ;
	/**
	 * \brief  
	 * \param wxWindow*   
	*/

  void SetTopWindow(wxWindow*  window ) ;
	/**
	 * \brief Sets the name of application's vendor. The name will be used
in registry access. A default name is set by
wxWindows. 
	 * \param const wxString&   
	*/

  void SetVendorName(const wxString&  name ) ;
	/**
	 * \brief Allows the programmer to specify whether the application will use the best visual
on systems that support several visual on the same display. This is typically the
case under Solaris and IRIX, where the default visual is only 8-bit whereas certain
applications are supposed to run in TrueColour mode.

Note that this function has to be called in the constructor of the   
instance and won't have any effect when called later on.

This function currently only has effect under GTK. 
	 * \param bool  
	*/

  void SetUseBestVisual(bool  flag ) ;
	/**
	 * \brief Yields control to pending messages in the windowing system. This can be useful, for example, when a
time-consuming process writes to a text window. Without an occasional
yield, the text window will not be updated properly, and on systems with
cooperative multitasking, such as Windows 3.1 other processes will not respond.

Caution should be exercised, however, since yielding may allow the
user to perform actions which are not compatible with the current task.
Disabling menu items or whole menus during processing can avoid unwanted
reentrance of code: see   for a better
function.

Note that Yield() will not flush the message logs. This is intentional as
calling Yield() is usually done to quickly update the screen and popping up a
message box dialog may be undesirable. If you do wish to flush the log
messages immediately (otherwise it will be done during the next idle loop
iteration), call  .

Calling Yield() recursively is normally an error and an assert failure is
raised in debug build if such situation is detected. However if the the 
  parameter is  , the method will just silently
return   instead. 
	 * \param bool  
	*/

  bool Yield(bool onlyIfNeeded = false) ;
};


#endif
