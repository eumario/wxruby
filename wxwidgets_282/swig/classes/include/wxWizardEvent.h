// wxWizardEvent.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxWizardEvent_h_)
#define _wxWizardEvent_h_
class wxWizardEvent : public wxNotifyEvent
{
public:
	/**
	 * \brief Constructor. It is not normally used by the user code as the objects of this
type are constructed by wxWizard. 
	 * \param wxEventType   
	 * \param int   
	 * \param bool   
	*/

   wxWizardEvent(wxEventType  type = wxEVT_NULL, int  id = -1, bool  direction = true) ;
	/**
	 * \brief Return the direction in which the page is changing: for  , return   if we're going forward or
false otherwise and for   return   if
we came from the previous page and   if we returned from the next
one. 
	*/

  bool GetDirection() const;
	/**
	 * \brief Returns the   which was active when this
event was generated. 
	*/

  wxWizardPage* GetPage() const;
};


#endif
