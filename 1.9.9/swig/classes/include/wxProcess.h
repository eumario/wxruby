// wxProcess.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxProcess_h_)
#define _wxProcess_h_
class wxProcess : public wxEvtHandler
{
public:
	/**
	 * \brief  
	 * \param wxEvtHandler *  
	 * \param int  
	*/

   wxProcess(wxEvtHandler * parent = NULL, int id = -1) ;
	/**
	 * \brief Constructs a process object.   is only used in the case you want to
use wxWindows events. It identifies this object, or another window that will
receive the event.

If the   parameter is different from NULL, it will receive
a wxEVT_END_PROCESS notification event (you should insert EVT_END_PROCESS
macro in the event table of the parent to handle it) with the given  .

The second constructor creates an object without any associated parent (and
hence no id neither) but allows to specify the   which can have the
value of   or  . Specifying the
former value has no particular effect while using the latter one is equivalent
to calling  . 
	 * \param int   
	*/

   wxProcess(int  flags ) ;
	/**
	 * \brief Destroys the wxProcess object. 
	*/

  virtual  ~wxProcess() ;
	/**
	 * \brief Closes the output stream (the one connected to the stdin of the child
process). This function can be used to indicate to the child process that
there is no more data to be read - usually, a filter program will only
terminate when the input stream is closed. 
	*/

  void CloseOutput() ;
	/**
	 * \brief Normally, a wxProcess object is deleted by its parent when it receives the
notification about the process termination. However, it might happen that the
parent object is destroyed before the external process is terminated (e.g. a
window from which this external process was launched is closed by the user)
and in this case it   the wxProcess object, but
  instead. After the wxProcess object is detached
from its parent, no notification events will be sent to the parent and the
object will delete itself upon reception of the process termination
notification. 
	*/

  void Detach() ;
	/**
	 * \brief Returns an input stream which corresponds to the standard error output (stderr)
of the child process. 
	*/

  wxInputStream*  GetErrorStream() const;
	/**
	 * \brief It returns an input stream corresponding to the standard output stream of the
subprocess. If it is NULL, you have not turned on the redirection.
See  . 
	*/

  wxInputStream*  GetInputStream() const;
	/**
	 * \brief It returns an output stream correspoding to the input stream of the subprocess.
If it is NULL, you have not turned on the redirection.
See  . 
	*/

  wxOutputStream*  GetOutputStream() const;
	/**
	 * \brief Returns   if there is data to be read on the child process standard
error stream. 
	*/

  bool IsErrorAvailable() const;
	/**
	 * \brief Returns   if there is data to be read on the child process standard
output stream. This allows to write simple (and extremely inefficient)
polling-based code waiting for a better mechanism in future wxWindows versions.

See the   for an example of using this
function. 
	*/

  bool IsInputAvailable() const;
	/**
	 * \brief Returns   if the child process standard output stream is opened. 
	*/

  bool IsInputOpened() const;
	/**
	 * \brief Send the specified signal to the given process. Possible signal values are:

 

 ,   and   have the same meaning
under both Unix and Windows but all the other signals are equivalent to
  under Windows.

Returns the element of   enum: 
	 * \param int  
	 * \param wxSignal  
	*/

  static wxKillError Kill(int  pid , wxSignal signal = wxSIGNONE) ;
	/**
	 * \brief Returns   if the given process exists in the system. 
	 * \param int  
	*/

  static bool Exists(int  pid ) ;
	/**
	 * \brief It is called when the process with the pid   finishes.
It raises a wxWindows event when it isn't overridden. 
	 * \param int  
	 * \param int  
	*/

  virtual void OnTerminate(int  pid , int  status ) const;
	/**
	 * \brief This static method replaces the standard   function: it launches
the process specified by the   parameter and returns the wxProcess
object which can be used to retrieve the streams connected to the standard
input, output and error output of the child process.

If the process couldn't be launched,   is returned. Note that in any
case the returned pointer should   be deleted, rather the process
object will be destroyed automatically when the child process terminates. This
does mean that the child process should be told to quit before the main program
exits to avoid memory leaks. 
	 * \param const wxString&   
	 * \param int   
	*/

  static wxProcess * Open(const wxString&  cmd , int  flags = wxEXEC_ASYNC) ;
	/**
	 * \brief Turns on redirection. wxExecute will try to open a couple of pipes
to catch the subprocess stdio. The caught input stream is returned by
GetOutputStream() as a non-seekable stream. The caught output stream is returned
by GetInputStream() as a non-seekable stream. 
	*/

  void Redirect() ;
};


#endif
