// wxSocketEvent.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxSocketEvent_h_)
#define _wxSocketEvent_h_
class wxSocketEvent : public wxEvent
{
public:
	/**
	 * \brief Constructor. 
	 * \param int  
	*/

   wxSocketEvent(int id = 0) ;
	/**
	 * \brief Gets the client data of the socket which generated this event, as
set with  . 
	*/

  void * GetClientData() ;
	/**
	 * \brief Returns the socket object to which this event refers to. This makes
it possible to use the same event handler for different sockets. 
	*/

  wxSocketBase * GetSocket() const;
	/**
	 * \brief Returns the socket event type. 
	*/

  wxSocketNotify GetSocketEvent() const;
};


#endif
