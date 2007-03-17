// wxMouseCaptureChangedEvent.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxMouseCaptureChangedEvent_h_)
#define _wxMouseCaptureChangedEvent_h_
class wxMouseCaptureChangedEvent : public wxEvent
{
public:
	/**
	 * \brief Constructor. 
	 * \param wxWindowID   
	 * \param wxWindow*  
	*/

   wxMouseCaptureChangedEvent(wxWindowID  windowId = 0, wxWindow* gainedCapture = NULL) ;
	/**
	 * \brief Returns the window that gained the capture, or NULL if it was a non-wxWindows window. 
	*/

  wxWindow* GetCapturedWindow() const;
};


#endif
