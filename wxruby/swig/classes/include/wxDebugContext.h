// wxDebugContext.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxDebugContext_h_)
#define _wxDebugContext_h_
class wxDebugContext
{
public:
	/**
	 * \brief Checks the memory blocks for errors, starting from the currently set
checkpoint. 
	*/

  int Check() ;
	/**
	 * \brief Performs a memory dump from the currently set checkpoint, writing to the
current debug stream. Calls the   member function for each wxObject
derived instance. 
	*/

  bool Dump() ;
	/**
	 * \brief Returns true if the memory allocator checks all previous memory blocks for errors.
By default, this is false since it slows down execution considerably. 
	*/

  bool GetCheckPrevious() ;
	/**
	 * \brief Returns true if debug mode is on. If debug mode is on, the wxObject new and delete
operators store or use information about memory allocation. Otherwise,
a straight malloc and free will be performed by these operators. 
	*/

  bool GetDebugMode() ;
	/**
	 * \brief Gets the debug level (default 1). The debug level is used by the wxTraceLevel function and
the WXTRACELEVEL macro to specify how detailed the trace information is; setting
a different level will only have an effect if trace statements in the application
specify a value other than one.

This is obsolete, replaced by   functionality. 
	*/

  int GetLevel() ;
	/**
	 * \brief Returns the output stream associated with the debug context.

This is obsolete, replaced by   functionality. 
	*/

  ostream& GetStream() ;
	/**
	 * \brief Returns a pointer to the output stream buffer associated with the debug context.
There may not necessarily be a stream buffer if the stream has been set
by the user.

This is obsolete, replaced by   functionality. 
	*/

  streambuf* GetStreamBuf() ;
	/**
	 * \brief  
	*/

  bool HasStream() ;
	/**
	 * \brief Prints a list of the classes declared in this application, giving derivation
and whether instances of this class can be dynamically created. 
	*/

  bool PrintClasses() ;
	/**
	 * \brief Performs a statistics analysis from the currently set checkpoint, writing
to the current debug stream. The number of object and non-object
allocations is printed, together with the total size. 
	 * \param bool  
	*/

  bool PrintStatistics(bool detailed = true) ;
	/**
	 * \brief Sets the current checkpoint: Dump and PrintStatistics operations will
be performed from this point on. This allows you to ignore allocations
that have been performed up to this point. 
	 * \param bool  
	*/

  void SetCheckpoint(bool all = false) ;
	/**
	 * \brief Tells the memory allocator to check all previous memory blocks for errors.
By default, this is false since it slows down execution considerably. 
	 * \param bool  
	*/

  void SetCheckPrevious(bool  check ) ;
	/**
	 * \brief Sets the debug mode on or off. If debug mode is on, the wxObject new and delete
operators store or use information about memory allocation. Otherwise,
a straight malloc and free will be performed by these operators.

By default, debug mode is on if __WXDEBUG__ is defined. If the application
uses this function, it should make sure that all object memory allocated
is deallocated with the same value of debug mode. Otherwise, the
delete operator might try to look for memory information that does not
exist. 
	 * \param bool  
	*/

  void SetDebugMode(bool  debug ) ;
	/**
	 * \brief Sets the current debug file and creates a stream. This will delete any existing
stream and stream buffer. By default, the debug context stream
outputs to the debugger (Windows) or standard error (other platforms). 
	 * \param const wxString&   
	*/

  bool SetFile(const wxString&  filename ) ;
	/**
	 * \brief Sets the debug level (default 1). The debug level is used by the wxTraceLevel function and
the WXTRACELEVEL macro to specify how detailed the trace information is; setting
a different level will only have an effect if trace statements in the application
specify a value other than one.

This is obsolete, replaced by   functionality. 
	 * \param int  
	*/

  void SetLevel(int  level ) ;
	/**
	 * \brief Sets the debugging stream to be the debugger (Windows) or standard error (other platforms).
This is the default setting. The existing stream will be flushed and deleted.

This is obsolete, replaced by   functionality. 
	*/

  bool SetStandardError() ;
	/**
	 * \brief  
	 * \param ostream*   
	 * \param streambuf*   
	*/

  void SetStream(ostream*  stream , streambuf*  streamBuf = NULL) ;
};


#endif
