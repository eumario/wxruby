// wxIdleEvent.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxIdleEvent_h_)
#define _wxIdleEvent_h_
class wxIdleEvent : public wxEvent
{
public:
	/**
	 * \brief Constructor. 
	*/

   wxIdleEvent() ;
	/**
	 * \brief Tells wxWindows that more processing is required. This function can be called by an OnIdle
handler for a window or window event handler to indicate that wxApp::OnIdle should
forward the OnIdle event once more to the application windows. If no window calls this function
during OnIdle, then the application will remain in a passive event loop (not calling OnIdle) until a
new event is posted to the application by the windowing system. 
	 * \param bool  
	*/

  void RequestMore(bool needMore = true) ;
	/**
	 * \brief Returns true if the OnIdle function processing this event requested more processing time. 
	*/

  bool MoreRequested() const;
};


#endif
