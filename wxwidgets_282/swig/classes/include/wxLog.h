// wxLog.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxLog_h_)
#define _wxLog_h_
class wxLog
{
public:
	
	virtual ~wxLog();

	/**
	 * \brief Add the   to the list of allowed masks for
 . 
	 * \param const wxString&   
	*/

  static void AddTraceMask(const wxString&  mask ) ;
	/**
	 * \brief Removes all trace masks previously set with
 . 
	*/

  static void ClearTraceMasks() ;
	/**
	 * \brief Returns the currently allowed list of string trace masks. 
	*/

  static const wxArrayString & GetTraceMasks() ;
	/**
	 * \brief Forwards the message at specified level to the   function of the
active log target if there is any, does nothing otherwise. 
	 * \param wxLogLevel   
	 * \param const char *   
	*/

  static void OnLog(wxLogLevel   level , const char *   message );
	/**
	 * \brief Returns the pointer to the active log target (may be NULL). 
	*/

  static wxLog * GetActiveTarget() ;
	/**
	 * \brief Sets the specified log target as the active one. Returns the pointer to the
previous active log target (may be NULL). 
	 * \param wxLog *   
	*/

  static wxLog * SetActiveTarget(wxLog *   logtarget ) ;
	/**
	 * \brief Suspends the logging until   is called. Note that
the latter must be called the same number of times as the former to undo it,
i.e. if you call Suspend() twice you must call Resume() twice as well.

Note that suspending the logging means that the log sink won't be be flushed
periodically, it doesn't have any effect if the current log target does the
logging immediately without waiting for   to be
called (the standard GUI log target only shows the log dialog when it is
flushed, so Suspend() works as expected with it).

\wxheading{See also:}

 , 
	*/

  static void Suspend() ;
	/**
	 * \brief Resumes logging previously suspended by a call to
 . All messages logged in the meanwhile will be
flushed soon. 
	*/

  static void Resume() ;
	/**
	 * \brief Called to process the message of the specified severity.   is the text
of the message as specified in the call of   function which
generated it and   is the moment when the message was generated.

The base class version prepends the timestamp to the message, adds a prefix
corresponding to the log level and then calls
  with the resulting string. 
	 * \param wxLogLevel   
	 * \param const wxChar   
	 * \param time_t   
	*/

  //virtual void DoLog(wxLogLevel  level , const wxChar  *msg , time_t  timestamp );
	/**
	 * \brief Called to log the specified string. The timestamp is already included into the
string but still passed to this function.

A simple implementation may just send the string to   or, better,
 . 
	 * \param const wxChar   
	 * \param time_t   
	*/

  //virtual void DoLogString(const wxChar  *msg , time_t  timestamp );
	/**
	 * \brief Instructs wxLog to not create new log targets on the fly if there is none
currently. (Almost) for internal use only: it is supposed to be called by the
application shutdown code.

Note that this function also calls
 . 
	*/

  static void DontCreateOnDemand() ;
	/**
	 * \brief Shows all the messages currently in buffer and clears it. If the buffer
is already empty, nothing happens. 
	*/

  virtual void Flush() ;
	/**
	 * \brief Flushes the current log target if any, does nothing if there is none.

See also: 
	*/

  static void FlushActive() ;
	/**
	 * \brief Activates or deactivates verbose mode in which the verbose messages are
logged as the normal ones instead of being silently dropped. 
	 * \param bool   
	*/

  static void SetVerbose(bool  verbose = true) ;
	/**
	 * \brief Returns whether the verbose mode is currently active. 
	*/

  static bool GetVerbose() ;
	/**
	 * \brief Specifies that log messages with $level &gt; logLevel$ should be ignored
and not sent to the active log target. 
	 * \param wxLogLevel   
	*/

  static void SetLogLevel(wxLogLevel   logLevel ) ;
	/**
	 * \brief Returns the current log level limit. 
	*/

  static wxLogLevel GetLogLevel() ;
	/**
	 * \brief Sets the timestamp format prepended by the default log targets to all
messages. The string may contain any normal characters as well as \prefixed format specificators, see   manual for details.
Passing a NULL value (not empty string) to this function disables message timestamping. 
	 * \param const char *   
	*/

  void SetTimestamp(const wxChar *   format );
	/**
	 * \brief Returns the current timestamp format string. 
	*/

  const char * GetTimestamp() const;
	/**
	 * \brief Sets the trace mask, see  
section for details. 
	 * \param wxTraceMask   
	*/

  static void SetTraceMask(wxTraceMask   mask ) ;
	/**
	 * \brief Returns true if the   is one of allowed masks for
 .

See also:  , 
	 * \param const wxChar *  
	*/

  static bool IsAllowedTraceMask(const wxChar * mask ) ;
	/**
	 * \brief Remove the   from the list of allowed masks for
 .

See also: 
	 * \param const wxString&   
	*/

  static void RemoveTraceMask(const wxString&  mask ) ;
};


#endif
