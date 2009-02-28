// wxLogChain.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxLogChain_h_)
#define _wxLogChain_h_
class wxLogChain : public wxLog
{
public:
	/**
	 * \brief Sets the specified   (which may be  ) as the default log
target but the log messages are also passed to the previous log target if any. 
	 * \param wxLog *  
	*/

   wxLogChain(wxLog * logger ) ;
	/**
	 * \brief Destroys the previous log target. 
	*/

  virtual  ~wxLogChain() ;
	/**
	 * \brief Returns the pointer to the previously active log target (which may be  ). 
	*/

  wxLog * GetOldLog() const;
	/**
	 * \brief Returns   if the messages are passed to the previously active log
target (default) or   if  
had been called. 
	*/

  bool IsPassingMessages() const;
	/**
	 * \brief By default, the log messages are passed to the previously active log target.
Calling this function with   parameter disables this behaviour
(presumably temporarily, as you shouldn't use wxLogChain at all otherwise) and
it can be reenabled by calling it again with   set to  . 
	 * \param bool   
	*/

  void PassMessages(bool  passMessages ) ;
	/**
	 * \brief Sets another log target to use (may be  ). The log target specified
in the   or in a previous call to
this function is deleted.

This doesn't change the old log target value (the one the messages are
forwarded to) which still remains the same as was active when wxLogChain
object was created. 
	 * \param wxLog *  
	*/

  void SetLog(wxLog * logger ) ;
};


#endif
