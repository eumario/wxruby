// wxComboBox.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxComboBox_h_)
#define _wxComboBox_h_
class wxComboBox : public wxControlWithItems
{
public:
	/**
	 * \brief Default constructor. 
	*/

   wxComboBox() ;
	/**
	 * \brief  
	 * \param wxWindow*  
	 * \param wxWindowID  
	 * \param const wxString&   
	 * \param const wxPoint&  
	 * \param const wxSize&  
	 * \param int  
	 * \param const wxString   
	 * \param long  
	 * \param const wxValidator&   
	 * \param const wxString&   
	*/

  wxComboBox(wxWindow*  parent , wxWindowID  id , const wxString&  value, const wxPoint& pos , const wxSize& size , int  n , const wxString  choices[] , long style = 0, const wxValidator&  validator = wxDefaultValidator, const wxString&  name = wxT("comboBox"));
	/**
	 * \brief Destructor, destroying the combobox. 
	*/

  virtual  ~wxComboBox() ;
	/**
	 * \brief Creates the combobox for two-step construction. Derived classes
should call or replace this function. See  
for further details. 
	 * \param wxWindow*  
	 * \param wxWindowID  
	 * \param const wxString&   
	 * \param const wxPoint&  
	 * \param const wxSize&  
	 * \param int  
	 * \param const wxString   
	 * \param long  
	 * \param const wxValidator&   
	 * \param const wxString&   
	*/

  bool Create(wxWindow*  parent , wxWindowID  id , const wxString&  value, const wxPoint& pos , const wxSize& size , int  n , const wxString  choices[] , long style = 0, const wxValidator&  validator = wxDefaultValidator, const wxString&  name = wxT("comboBox"));
	/**
	 * \brief Copies the selected text to the clipboard. 
	*/

  void Copy() ;
	/**
	 * \brief Copies the selected text to the clipboard and removes the selection. 
	*/

  void Cut() ;
	/**
	 * \brief Returns the insertion point for the combobox's text field. 
	*/

  long GetInsertionPoint() const;
	/**
	 * \brief Returns the last position in the combobox text field. 
	*/

  long GetLastPosition() const;
	/**
	 * \brief Returns the current value in the combobox text field. 
	*/

  wxString GetValue() const;
	/**
	 * \brief Pastes text from the clipboard to the text field. 
	*/

  void Paste() ;
	/**
	 * \brief Replaces the text between two positions with the given text, in the combobox text field. 
	 * \param long  
	 * \param long  
	 * \param const wxString&   
	*/

  void Replace(long  from , long  to , const wxString&  text ) ;
	/**
	 * \brief Removes the text between the two positions in the combobox text field. 
	 * \param long  
	 * \param long  
	*/

  void Remove(long  from , long  to ) ;
	/**
	 * \brief Sets the insertion point in the combobox text field. 
	 * \param long  
	*/

  void SetInsertionPoint(long  pos ) ;
	/**
	 * \brief Sets the insertion point at the end of the combobox text field. 
	*/

  void SetInsertionPointEnd() ;
	/**
	 * \brief Selects the text between the two positions, in the combobox text field.







\pythonnote{This method is called   in wxPython,  
name is kept for 
 .} 
	 * \param long  
	 * \param long  
	*/

  void SetSelection(long  from , long  to ) ;
	/**
	 * \brief Sets the text for the combobox text field.

  For a combobox with   style the string must be in
the combobox choices list, otherwise the call to SetValue() is ignored. 
	 * \param const wxString&   
	*/

  void SetValue(const wxString&  text ) ;
  // the following were missing from the xml
  void Append(const wxString& item);
  void SetSelection(int n);
  void SetStringSelection(wxString &);
};


#endif
