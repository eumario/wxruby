// wxNotebookEvent.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxNotebookEvent_h_)
#define _wxNotebookEvent_h_
class wxNotebookEvent : public wxNotifyEvent
{
public:
	/**
	 * \brief Constructor (used internally by wxWindows only). 
	 * \param wxEventType  
	 * \param int  
	 * \param int  
	 * \param int  
	*/

   wxNotebookEvent(wxEventType eventType = wxEVT_NULL, int id = 0, int sel = -1, int oldSel = -1) ;
	/**
	 * \brief Returns the page that was selected before the change, $-1$ if none was selected. 
	*/

  int GetOldSelection() const;
	/**
	 * \brief Returns the currently selected page, or $-1$ if none was selected.

  under Windows, GetSelection() will return the same value as
  when called from
  handler and not the page which is going to
be selected. 
	*/

  int GetSelection() const;
	/**
	 * \brief Sets the id of the page selected before the change. 
	 * \param int  
	*/

  void SetOldSelection(int  page ) ;
	/**
	 * \brief Sets the selection member variable. 
	 * \param int  
	*/

  void SetSelection(int  page ) ;
};


#endif
