// wxNotifyEvent.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxNotifyEvent_h_)
#define _wxNotifyEvent_h_
class wxNotifyEvent : public wxCommandEvent
{
public:
	/**
	 * \brief Constructor (used internally by wxWindows only). 
	 * \param wxEventType  
	 * \param int  
	*/

   wxNotifyEvent(wxEventType eventType = wxEVT_NULL, int id = 0) ;
	/**
	 * \brief This is the opposite of  : it explicitly
allows the event to be processed. For most events it is not necessary to call
this method as the events are allowed anyhow but some are forbidden by default
(this will be mentioned in the corresponding event description). 
	*/

  void Allow() ;
	/**
	 * \brief Returns true if the change is allowed (  
hasn't been called) or false otherwise (if it was). 
	*/

  bool IsAllowed() const;
	/**
	 * \brief Prevents the change announced by this event from happening.

It is in general a good idea to notify the user about the reasons for vetoing
the change because otherwise the applications behaviour (which just refuses to
do what the user wants) might be quite surprising. 
	*/

  void Veto() ;
};


#endif
