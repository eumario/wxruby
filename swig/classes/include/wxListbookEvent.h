// wxListbookEvent.h

#if !defined(_wxListbookEvent_h_)
#define _wxListbookEvent_h_
class wxListbookEvent : public wxNotifyEvent
{
public:
	/**
	 * \brief Constructor (used internally by wxWindows only). 
	 * \param wxEventType  
	 * \param int  
	 * \param int  
	 * \param int  
	*/

  wxListbookEvent(wxEventType commandType = wxEVT_NULL, int id = 0,
              int nSel = wxNOT_FOUND, int nOldSel = wxNOT_FOUND);
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
