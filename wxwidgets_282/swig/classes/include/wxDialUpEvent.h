// wxDialUpEvent.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxDialUpEvent_h_)
#define _wxDialUpEvent_h_
class wxDialUpEvent : public wxEvent
{
public:
	/**
	 * \brief Constructor is only used by  . 
	 * \param bool   
	 * \param bool   
	*/

   wxDialUpEvent(bool  isConnected , bool  isOwnEvent ) ;
	/**
	 * \brief Is this a   or   event? In other words, does it
notify about transition from offline to online state or vice versa? 
	*/

  bool IsConnectedEvent() const;
	/**
	 * \brief Does this event come from wxDialUpManager::Dial() or from some extrenal
process (i.e. does it result from our own attempt to establish the
connection)? 
	*/

  bool IsOwnEvent() const;
};


#endif
