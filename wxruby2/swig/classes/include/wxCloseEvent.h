// wxCloseEvent.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxCloseEvent_h_)
#define _wxCloseEvent_h_
class wxCloseEvent : public wxEvent
{
public:
	/**
	 * \brief Constructor. 
	 * \param WXTYPE  
	 * \param int  
	*/

   wxCloseEvent(WXTYPE commandEventType = 0, int id = 0) ;
	/**
	 * \brief Returns true if you can veto a system shutdown or a window close event.
Vetoing a window close event is not possible if the calling code wishes to
force the application to exit, and so this function must be called to check this. 
	*/

  bool CanVeto() ;
	/**
	 * \brief Returns true if the user is logging off. 
	*/

  bool GetLoggingOff() const;
	/**
	 * \brief Returns true if the session is ending. 
	*/

  bool GetSessionEnding() const;
	/**
	 * \brief Returns true if the application wishes to force the window to close.
This will shortly be obsolete, replaced by CanVeto. 
	*/

  bool GetForce() const;
	/**
	 * \brief Sets the 'can veto' flag. 
	 * \param bool  
	*/

  void SetCanVeto(bool  canVeto ) ;
	/**
	 * \brief Sets the 'force' flag. 
	 * \param bool  
	*/

  void SetForce(bool  force ) const;
	/**
	 * \brief Sets the 'logging off' flag. 
	 * \param bool  
	*/

  void SetLoggingOff(bool  loggingOff );
	/**
	 * \brief Call this from your event handler to veto a system shutdown or to signal
to the calling application that a window close did not happen.

You can only veto a shutdown if   returns
true. 
	 * \param bool  
	*/

  void Veto(bool veto = true) ;
  // the following were missing from the xml
  virtual ~wxCloseEvent();
};


#endif
