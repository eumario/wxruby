// wxChoice.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxChoice_h_)
#define _wxChoice_h_
class wxChoice : public wxControlWithItems
{
public:
	/**
	 * \brief Default constructor. 
	*/

   wxChoice() ;
	/**
	 * \brief  
	 * \param wxWindow *  
	 * \param wxWindowID  
	 * \param const wxPoint&   
	 * \param const wxSize&  
	 * \param int  
	 * \param const wxString   
	 * \param long  
	 * \param const wxValidator&   
	 * \param const wxString&   
	*/

   wxChoice(wxWindow * parent , wxWindowID  id , const wxPoint&  pos , const wxSize&  size , int  n , const wxString  choices[] , long style = 0, const wxValidator&  validator = wxDefaultValidator, const wxString&  name = wxT("choice")) ;
	/**
	 * \brief Destructor, destroying the choice item. 
	*/

  virtual  ~wxChoice() ;
	/**
	 * \brief Creates the choice for two-step construction. See  . 
	 * \param wxWindow *  
	 * \param wxWindowID  
	 * \param const wxPoint&   
	 * \param const wxSize&  
	 * \param int  
	 * \param const wxString   
	 * \param long  
	 * \param const wxString&   
	*/

  bool Create(wxWindow * parent , wxWindowID  id , const wxPoint&  pos , const wxSize&  size , int  n , const wxString  choices[] , long style = 0, const wxValidator&  validator = wxDefaultValidator, const wxString&  name = wxT("choice"));
	/**
	 * \brief Deletes the item with the given index from the control. 
	 * \param int   
	*/

  void Delete(int  n ) ;
	/**
	 * \brief Gets the number of columns in this choice item. 
	*/

  int GetColumns() const;
	/**
	 * \brief Sets the number of columns in this choice item. 
	 * \param int  
	*/

  void SetColumns(int n = 1) ;
  // the following were missing from the xml
  void SetSelection(int  n );
  void SetStringSelection(wxString &);
};


#endif
