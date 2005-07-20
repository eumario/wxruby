// wxListBox.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxListBox_h_)
#define _wxListBox_h_
class wxListBox : public wxControlWithItems
{
public:
	/**
	 * \brief Default constructor. 
	*/

   wxListBox() ;
	/**
	 * \brief  
	 * \param wxWindow*  
	 * \param wxWindowID  
	 * \param const wxPoint&  
	 * \param const wxSize&  
	 * \param int  
	 * \param const wxString   
	 * \param long  
	 * \param const wxValidator&   
	 * \param const wxString&   
	*/

  wxListBox(wxWindow*  parent , wxWindowID  id , const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, int  n = 0 , const wxString  choices[] = NULL, long style = 0, const wxValidator&  validator = wxDefaultValidator, const wxString&  name = wxT("listBox"));
	/**
	 * \brief Destructor, destroying the list box. 
	*/

  virtual  ~wxListBox() ;
	/**
	 * \brief Creates the listbox for two-step construction. See  
for further details. 
	 * \param wxWindow*  
	 * \param wxWindowID  
	 * \param const wxPoint&  
	 * \param const wxSize&  
	 * \param int  
	 * \param const wxString   
	 * \param long  
	 * \param const wxValidator&   
	 * \param const wxString&   
	*/

  bool Create(wxWindow*  parent , wxWindowID  id , const wxPoint& pos , const wxSize& size , int  n , const wxString  choices[] = NULL, long style = 0, const wxValidator&  validator = wxDefaultValidator, const wxString&  name = wxT("listBox"));
	/**
	 * \brief Deselects an item in the list box. 
	 * \param int  
	*/

  void Deselect(int  n ) ;
	/**
	 * \brief Fill an array of ints with the positions of the currently selected items. 
	 * \param wxArrayInt&   
	*/

  int GetSelections(wxArrayInt&  selections ) const;
	/**
	 * \brief Insert the given number of strings before the specified position.









\pythonnote{The first two parameters are collapsed into a single
parameter for wxPython, which is a list of strings.}

\perlnote{In wxPerl there is just an array reference in place of  
and  .} 
	 * \param int  
	 * \param const wxString  
	 * \param int  
	*/

  void InsertItems(int nItems, const wxString *items, int pos);
  void InsertItems(const wxArrayString& items, int pos);
	/**
	 * \brief Determines whether an item is selected. 
	 * \param int  
	*/

  bool Selected(int  n ) const;
	/**
	 * \brief  
	 * \param int  
	 * \param const wxString*  
	 * \param void  
	*/

  void Set(int  n , const wxString*  choices , void **clientData = NULL) ;
	/**
	 * \brief Clears the list box and adds the given strings to it. 
	 * \param const wxArrayString&  
	 * \param void  
	*/

  void Set(const wxArrayString&  choices , void **clientData = NULL) ;
	/**
	 * \brief  
	 * \param int  
	*/

  void SetFirstItem(int  n ) ;
	/**
	 * \brief Set the specified item to be the first visible item. Windows only. 
	 * \param const wxString&   
	*/

  void SetFirstItem(const wxString&  string ) ;
  // the following were missing from the xml
  void SetSelection(int n, const bool select = TRUE);
  void SetStringSelection(const wxString& string, const bool select = TRUE);
  void Append(const wxString& item);
  void Delete(int n);
  int FindString(wxString & string);
  int GetCount();
  int GetSelection();
  wxString GetString(int n);
  wxString GetStringSelection();
  void SetString(int n, wxString& string);
  void Select(int n);
};


#endif
