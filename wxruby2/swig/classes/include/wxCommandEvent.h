// wxCommandEvent.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxCommandEvent_h_)
#define _wxCommandEvent_h_
class wxCommandEvent : public wxEvent
{
public:
	/**
	 * \brief Constructor. 
	 * \param WXTYPE  
	 * \param int  
	*/

   wxCommandEvent(WXTYPE commandEventType = 0, int id = 0) ;
	/**
	 * \brief Deprecated, use   instead. 
	*/

  bool Checked() const;
	/**
	 * \brief Returns client data pointer for a listbox or choice selection event
(not valid for a deselection). 
	*/

  void* GetClientData() ;
	/**
	 * \brief Returns the   member. 
	*/

  long GetExtraLong() ;
	/**
	 * \brief Returns the   member. 
	*/

  int GetInt() ;
	/**
	 * \brief Returns item index for a listbox or choice selection event (not valid for
a deselection). 
	*/

  int GetSelection() ;
	/**
	 * \brief Returns item string for a listbox or choice selection event (not valid for
a deselection). 
	*/

  wxString GetString() ;
	/**
	 * \brief This method can be used with checkbox and menu events: for the checkboxes, the
method returns   for a selection event and   for a
deselection one. For the menu events, this method indicates if the menu item
just has become checked or unchecked (and thus only makes sense for checkable
menu items). 
	*/

  bool IsChecked() const;
	/**
	 * \brief For a listbox or choice event, returns true if it is a selection, false if it
is a deselection. 
	*/

  bool IsSelection() ;
	/**
	 * \brief Sets the client data for this event. 
	 * \param void*  
	*/

  void SetClientData(void*  clientData ) ;
	/**
	 * \brief Sets the   member. 
	 * \param int  
	*/

  void SetExtraLong(int  extraLong ) ;
	/**
	 * \brief Sets the   member. 
	 * \param int  
	*/

  void SetInt(int  intCommand ) ;
	/**
	 * \brief Sets the   member. 
	 * \param const wxString&  
	*/

  void SetString(const wxString&  string ) ;
  // the following were missing from the xml
  virtual ~wxCommandEvent();
};


#endif
