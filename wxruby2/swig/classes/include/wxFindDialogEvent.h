// wxFindDialogEvent.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxFindDialogEvent_h_)
#define _wxFindDialogEvent_h_
class wxFindDialogEvent : public wxCommandEvent
{
public:
	/**
	 * \brief Constuctor used by wxWindows only. 
	 * \param wxEventType   
	 * \param int   
	*/

   wxFindDialogEvent(wxEventType  commandType = wxEVT_NULL, int  id = 0) ;
	/**
	 * \brief Get the currently selected flags: this is the combination of  ,
  and   flags. 
	*/

  int GetFlags() const;
	/**
	 * \brief Return the string to find (never empty). 
	*/

  wxString GetFindString() const;
	/**
	 * \brief Return the string to replace the search string with (only for replace and
replace all events). 
	*/

  wxString GetReplaceString() const;
	/**
	 * \brief Return the pointer to the dialog which generated this event. 
	*/

  wxFindReplaceDialog* GetDialog() const;
};


#endif
