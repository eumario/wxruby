// wxRadioBox.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxRadioBox_h_)
#define _wxRadioBox_h_
class wxRadioBox : public wxControl
{
public:
	/**
	 * \brief Default constructor. 
	*/

   wxRadioBox() ;
	/**
	 * \brief  
	 * \param wxWindow*   
	 * \param wxWindowID   
	 * \param const wxString&   
	 * \param const wxPoint&   
	 * \param const wxSize&   
	 * \param int  
	 * \param const wxString  
	 * \param int  
	 * \param long  
	 * \param const wxValidator&   
	 * \param const wxString&   
	*/

   wxRadioBox(wxWindow*  parent , wxWindowID  id , const wxString&  label , const wxPoint&  point = wxDefaultPosition, const wxSize&  size = wxDefaultSize, int n = 0, const wxString choices[] = NULL, int majorDimension = 0, long style = wxRA_SPECIFY_COLS, const wxValidator&  validator = wxDefaultValidator, const wxString&  name = "radioBox") ;
	/**
	 * \brief Destructor, destroying the radiobox item. 
	*/

  virtual  ~wxRadioBox() ;
	/**
	 * \brief Creates the radiobox for two-step construction. See  
for further details. 
	 * \param wxWindow*   
	 * \param wxWindowID   
	 * \param const wxString&   
	 * \param const wxPoint&   
	 * \param const wxSize&   
	 * \param int  
	 * \param const wxString  
	 * \param int  
	 * \param long  
	 * \param const wxValidator&   
	 * \param const wxString&   
	*/

  bool Create(wxWindow*  parent , wxWindowID  id , const wxString&  label , const wxPoint&  point = wxDefaultPosition, const wxSize&  size = wxDefaultSize, int n = 0, const wxString choices[] = NULL, int majorDimension = 0, long style = wxRA_SPECIFY_COLS, const wxValidator&  validator = wxDefaultValidator, const wxString&  name = "radioBox") ;
	/**
	 * \brief Enables or disables the entire radiobox. 
	 * \param bool  
	*/

  void Enable(bool enable = true) ;
	/**
	 * \brief Enables or disables an individual button in the radiobox.







\pythonnote{In place of a single overloaded method name, wxPython
implements the following methods:\par
\indented{2cm}{ }
} 
	 * \param int  
	 * \param bool  
	*/

  void Enable(int  n , bool enable = true) ;
	/**
	 * \brief Finds a button matching the given string, returning the position if found, or
-1 if not found. 
	 * \param const wxString&   
	*/

  int FindString(const wxString&  string ) const;
	/**
	 * \brief Returns the number of items in the radiobox. 
	*/

  int GetCount() const;
	/**
	 * \brief Returns the radiobox label. 
	*/

  wxString GetLabel() const;
	/**
	 * \brief  
	 * \param int   
	*/

  wxString GetLabel(int  n ) const;
	/**
	 * \brief Returns the zero-based position of the selected button. 
	*/

  int GetSelection() const;
	/**
	 * \brief Returns the selected string. 
	*/

  wxString GetStringSelection() const;
	/**
	 * \brief This method is obsolete and was replaced with 
 , please use the new method in the new
code. This method is only available if wxWindows was compiled with 
  defined and will disappear completely in
future versions.

Returns the number of buttons in the radiobox. 
	*/

  int Number() const;
	/**
	 * \brief Sets the radiobox label. 
	 * \param const wxString&  
	*/

  void SetLabel(const wxString&  label ) ;
	/**
	 * \brief Sets a label for a radio button.







\pythonnote{In place of a single overloaded method name, wxPython
implements the following methods:\par
\indented{2cm}{ }
} 
	 * \param int   
	 * \param const wxString&  
	*/

  void SetLabel(int  n , const wxString&  label ) ;
	/**
	 * \brief Sets a button by passing the desired string position. This does not cause
a wxEVT_COMMAND_RADIOBOX_SELECTED event to get emitted. 
	 * \param int  
	*/

  void SetSelection(int  n ) ;
	/**
	 * \brief Sets the selection to a button by passing the desired string. This does not cause
a wxEVT_COMMAND_RADIOBOX_SELECTED event to get emitted. 
	 * \param const wxString&   
	*/

  void SetStringSelection(const wxString&  string ) ;
	/**
	 * \brief Shows or hides the entire radiobox. 
	 * \param const bool  
	*/

  void Show(const bool  show ) ;
	/**
	 * \brief Shows or hides individual buttons.







\pythonnote{In place of a single overloaded method name, wxPython
implements the following methods:\par
\indented{2cm}{ }
} 
	 * \param int   
	 * \param const bool  
	*/

  void Show(int  item , const bool  show ) ;
	/**
	 * \brief Returns the label for the button at the given position. 
	 * \param int  
	*/

  wxString GetString(int  n ) const;
};


#endif
