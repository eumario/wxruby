// wxEvent.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxEvent_h_)
#define _wxEvent_h_
class wxEvent : public wxObject
{
public:
	/**
	 * \brief Constructor. Should not need to be used directly by an application. 
	 * \param int   
	 * \param wxEventType   
	*/

   wxEvent(int  id = 0, wxEventType  eventType = wxEVT_NULL) ;
	/**
	 * \brief Returns a copy of the event.

Any event that is posted to the wxWindows event system for later action (via
  or
 ) must implement this method. All wxWindows
events fully implement this method, but any derived events implemented by the
user should also implement this method just in case they (or some event
derived from them) are ever posted.

All wxWindows events implement a copy constructor, so the easiest way of
implementing the Clone function is to implement a copy constructor for
a new event (call it MyEvent) and then define the Clone function like this: 
	*/

  virtual wxEvent* Clone() const = 0;
	/**
	 * \brief Returns the object associated with the
event, if any. 
	*/

  wxObject* GetEventObject() ;
	/**
	 * \brief Returns the identifier of the given event type,
such as wxEVENT_TYPE_BUTTON_COMMAND. 
	*/

  WXTYPE GetEventType() ;
	/**
	 * \brief Returns the identifier associated with this event, such as a button command id. 
	*/

  int GetId() ;
	/**
	 * \brief Returns true if the event handler should be skipped, false otherwise. 
	*/

  bool GetSkipped() ;
	/**
	 * \brief Gets the timestamp for the event. 
	*/

  long GetTimestamp() ;
	/**
	 * \brief Sets the originating object. 
	 * \param wxObject*   
	*/

  void SetEventObject(wxObject*  object ) ;
	/**
	 * \brief Sets the event type. 
	 * \param WXTYPE   
	*/

  void SetEventType(WXTYPE  typ ) ;
	/**
	 * \brief Sets the identifier associated with this event, such as a button command id. 
	 * \param int  
	*/

  void SetId(int  id ) ;
	/**
	 * \brief Sets the timestamp for the event.

Sets the originating object. 
	 * \param long   
	*/

  void SetTimestamp(long  timeStamp ) ;
	/**
	 * \brief Called by an event handler to tell the event system that the
event handler should be skipped, and the next valid handler used
instead. 
	 * \param bool  
	*/

  void Skip(bool skip = true) ;
};


#endif
