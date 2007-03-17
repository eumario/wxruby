// wxQueryLayoutInfoEvent.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxQueryLayoutInfoEvent_h_)
#define _wxQueryLayoutInfoEvent_h_
class wxQueryLayoutInfoEvent : public wxEvent
{
public:
	/**
	 * \brief Constructor. 
	 * \param wxWindowID   
	*/

   wxQueryLayoutInfoEvent(wxWindowID  id = 0) ;
	/**
	 * \brief Specifies the alignment of the window (which side of the remaining parent client area
the window sticks to). One of wxLAYOUT_TOP, wxLAYOUT_LEFT, wxLAYOUT_RIGHT, wxLAYOUT_BOTTOM. 
	*/

  void GetAlignment() const;
	/**
	 * \brief Returns the flags associated with this event. Not currently used. 
	*/

  int GetFlags() const;
	/**
	 * \brief Returns the orientation that the event handler specified to the event object. May be one of wxLAYOUT_HORIZONTAL,
wxLAYOUT_VERTICAL. 
	*/

  wxLayoutOrientation GetOrientation() const;
	/**
	 * \brief Returns the requested length of the window in the direction of the window orientation. This information
is not yet used. 
	*/

  int GetRequestedLength() const;
	/**
	 * \brief Returns the size that the event handler specified to the event object as being the requested size of the window. 
	*/

  wxSize GetSize() const;
	/**
	 * \brief Call this to specify the alignment of the window (which side of the remaining parent client area
the window sticks to). May be one of wxLAYOUT_TOP, wxLAYOUT_LEFT, wxLAYOUT_RIGHT, wxLAYOUT_BOTTOM. 
	 * \param wxLayoutAlignment   
	*/

  void SetAlignment(wxLayoutAlignment  alignment ) ;
	/**
	 * \brief Sets the flags associated with this event. Not currently used. 
	 * \param int   
	*/

  void SetFlags(int  flags ) ;
	/**
	 * \brief Call this to specify the orientation of the window. May be one of wxLAYOUT_HORIZONTAL,
wxLAYOUT_VERTICAL. 
	 * \param wxLayoutOrientation   
	*/

  void SetOrientation(wxLayoutOrientation  orientation ) ;
	/**
	 * \brief Sets the requested length of the window in the direction of the window orientation. This information
is not yet used. 
	 * \param int  
	*/

  void SetRequestedLength(int  length ) ;
	/**
	 * \brief Call this to let the calling code know what the size of the window is. 
	 * \param const wxSize&   
	*/

  void SetSize(const wxSize&  size ) ;
};


#endif
