// wxThread.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxThread_h_)
#define _wxThread_h_
class wxThread
{
public:
	/**
	 * \brief This constructor creates a new detached (default) or joinable C++ thread object. It
does not create or start execution of the real thread -- for this you should
use the   and   methods.

The possible values for   parameters are:

\twocolwidtha{7cm} 
	 * \param wxThreadKind   
	*/

   wxThread(wxThreadKind  kind = wxTHREAD_DETACHED) ;
	/**
	 * \brief The destructor frees the resources associated with the thread. Notice that you
should never delete a detached thread -- you may only call
  on it or wait until it terminates (and auto
destructs) itself. Because the detached threads delete themselves, they can
only be allocated on the heap.

Joinable threads should be deleted explicitly. The   and   functions
will not delete the C++ thread object. It is also safe to allocate them on
stack. 
	*/

  virtual  ~wxThread() ;
	/**
	 * \brief Creates a new thread. The thread object is created in the suspended state, and you
should call   to start running it.  You may optionally
specify the stack size to be allocated to it (Ignored on platforms that don't
support setting it explicitly, eg. Unix). 
	 * \param unsigned int   
	*/

  wxThreadError Create(unsigned int  stackSize = 0) ;
	/**
	 * \brief Calling   is a graceful way to terminate the
thread. It asks the thread to terminate and, if the thread code is well
written, the thread will terminate after the next call to
  which should happen quite soon.

However, if the thread doesn't call  
often enough (or at all), the function will not return immediately, but wait
until the thread terminates. As it may take a long time, and the message processing
is not stopped during this function execution, message handlers may be
called from inside it!

Delete() may be called for a thread in any state: running, paused or even not
yet created. Moreover, it must be called if   or
  fail in order to free the memory occupied by the
thread object. However, you should not call Delete() on a detached thread which
already terminated -- doing so will probably result in a crash because the
thread object doesn't exist any more.

For detached threads Delete() will also delete the C++ thread object, but it
will not do this for joinable ones.

This function can only be called from another thread context. 
	*/

  void Delete() ;
	/**
	 * \brief This is the entry point of the thread. This function is pure virtual and must
be implemented by any derived class. The thread execution will start here.

The returned value is the thread exit code which is only useful for
joinable threads and is the value returned by  .

This function is called by wxWindows itself and should never be called
directly. 
	*/

  virtual ExitCode Entry() ;
	/**
	 * \brief This is a protected function of the wxThread class and thus can only be called
from a derived class. It also can only be called in the context of this
thread, i.e. a thread can only exit from itself, not from another thread.

This function will terminate the OS thread (i.e. stop the associated path of
execution) and also delete the associated C++ object for detached threads.
  will be called just before exiting. 
	 * \param ExitCode   
	*/

  void Exit(ExitCode  exitcode = 0) ;
	/**
	 * \brief Returns the number of system CPUs or -1 if the value is unknown. 
	*/

  static int GetCPUCount() ;
	/**
	 * \brief Returns the platform specific thread ID of the current thread as a
long.  This can be used to uniquely identify threads, even if they are
not wxThreads. 
	*/

  static unsigned long GetCurrentId() ;
	/**
	 * \brief Gets the thread identifier: this is a platform dependent number that uniquely identifies the
thread throughout the system during its existence (i.e. the thread identifiers may be reused). 
	*/

  unsigned long GetId() const;
	/**
	 * \brief Gets the priority of the thread, between zero and 100.

The following priorities are defined:

\twocolwidtha{7cm} 
	*/

  int GetPriority() const;
	/**
	 * \brief Returns true if the thread is alive (i.e. started and not terminating). 
	*/

  bool IsAlive() const;
	/**
	 * \brief Returns true if the thread is of the detached kind, false if it is a joinable one. 
	*/

  bool IsDetached() const;
	/**
	 * \brief Returns true if the calling thread is the main application thread. 
	*/

  static bool IsMain() ;
	/**
	 * \brief Returns true if the thread is paused. 
	*/

  bool IsPaused() const;
	/**
	 * \brief Returns true if the thread is running. 
	*/

  bool IsRunning() const;
	/**
	 * \brief Immediately terminates the target thread.   The resources
allocated to the thread will not be freed and the state of the C runtime library
may become inconsistent. Use   instead.

For detached threads Kill() will also delete the associated C++ object.
However this will not happen for joinable threads and this means that you will
still have to delete the wxThread object yourself to avoid memory leaks.
In neither case   of the dying thread will be
called, so no thread-specific cleanup will be performed.

This function can only be called from another thread context, i.e. a thread
cannot kill itself.

It is also an error to call this function for a thread which is not running or
paused (in the latter case, the thread will be resumed first) -- if you do it,
a   error will be returned. 
	*/

  wxThreadError Kill() ;
	/**
	 * \brief Called when the thread exits. This function is called in the context of the
thread associated with the wxThread object, not in the context of the main
thread. This function will not be called if the thread was
 .

This function should never be called directly. 
	*/

  virtual void OnExit() ;
	/**
	 * \brief Suspends the thread. Under some implementations (Win32), the thread is
suspended immediately, under others it will only be suspended when it calls
  for the next time (hence, if the
thread doesn't call it at all, it won't be suspended).

This function can only be called from another thread context. 
	*/

  wxThreadError Pause() ;
	/**
	 * \brief Starts the thread execution. Should be called after
 .

This function can only be called from another thread context. 
	*/

  wxThreadError Run() ;
	/**
	 * \brief Sets the priority of the thread, between 0 and 100. It can only be set
after calling   but before calling
 .

The following priorities are already defined:

\twocolwidtha{7cm} 
	 * \param int  
	*/

  void SetPriority(int  priority ) ;
	/**
	 * \brief Pauses the thread execution for the given amount of time.

This function should be used instead of   by all worker
threads (i.e. all except the main one). 
	 * \param unsigned long   
	*/

  static void Sleep(unsigned long  milliseconds ) ;
	/**
	 * \brief Resumes a thread suspended by the call to  .

This function can only be called from another thread context. 
	*/

  wxThreadError Resume() ;
	/**
	 * \brief Sets the thread concurrency level for this process. This is, roughly, the
number of threads that the system tries to schedule to run in parallel.
The value of 0 for   may be used to set the default one.

Returns true on success or false otherwise (for example, if this function is
not implemented for this platform -- currently everything except Solaris). 
	 * \param size_t   
	*/

  static bool SetConcurrency(size_t  level ) ;
	/**
	 * \brief This function should be called periodically by the thread to ensure that calls
to   and   will
work. If it returns true, the thread should exit as soon as possible. 
	*/

  bool TestDestroy() ;
	/**
	 * \brief Return the thread object for the calling thread. NULL is returned if the calling thread
is the main (GUI) thread, but   should be used to test
whether the thread is really the main one because NULL may also be returned for the thread
not created with wxThread class. Generally speaking, the return value for such a thread
is undefined. 
	*/

  static wxThread * This() ;
	/**
	 * \brief Give the rest of the thread time slice to the system allowing the other threads to run.
See also  . 
	*/

  void Yield() ;
	/**
	 * \brief Waits until the thread terminates and returns its exit code or   on error.

You can only Wait() for joinable (not detached) threads.

This function can only be called from another thread context. 
	*/

  ExitCode Wait() const;
};


#endif
