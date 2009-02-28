// wxStaticBox.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxStaticBox_h_)
#define _wxStaticBox_h_
class wxStaticBox : public wxControl
{
public:
	/**
	 * \brief Default constructor. 
	*/

   wxStaticBox() ;
	/**
	 * \brief Constructor, creating and showing a static box. 
	 * \param wxWindow*   
	 * \param wxWindowID   
	 * \param const wxString&   
	 * \param const wxPoint&  
	 * \param const wxSize&   
	 * \param long  
	 * \param const wxString&   
	*/

   wxStaticBox(wxWindow*  parent , wxWindowID  id , const wxString&  label , const wxPoint& pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long style = 0, const wxString&  name = wxT("staticBox")) ;
	/**
	 * \brief Destructor, destroying the group box. 
	*/

  virtual  ~wxStaticBox() ;
	/**
	 * \brief Creates the static box for two-step construction. See  
for further details. 
	 * \param wxWindow*   
	 * \param wxWindowID   
	 * \param const wxString&   
	 * \param const wxPoint&  
	 * \param const wxSize&   
	 * \param long  
	 * \param const wxString&   
	*/

  bool Create(wxWindow*  parent , wxWindowID  id , const wxString&  label , const wxPoint& pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long style = 0, const wxString&  name = wxT("staticBox")) ;
};


#endif
