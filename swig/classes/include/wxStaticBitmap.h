// wxStaticBitmap.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxStaticBitmap_h_)
#define _wxStaticBitmap_h_
class wxStaticBitmap : public wxControl
{
public:
	/**
	 * \brief Default constructor. 
	*/

   wxStaticBitmap() ;
	/**
	 * \brief Constructor, creating and showing a text control. 
	 * \param wxWindow*   
	 * \param wxWindowID  
	 * \param const wxBitmap&   
	 * \param const wxPoint&   
	 * \param const wxSize&   
	 * \param long  
	 * \param const wxString&   
	*/

   wxStaticBitmap(wxWindow*  parent , wxWindowID  id , const wxBitmap&  label , const wxPoint&  pos , const wxSize&  size = wxDefaultSize, long style = 0, const wxString&  name = "staticBitmap") ;
	/**
	 * \brief Creation function, for two-step construction. For details see  . 
	 * \param wxWindow*   
	 * \param wxWindowID  
	 * \param const wxBitmap&   
	 * \param const wxPoint&   
	 * \param const wxSize&   
	 * \param long  
	 * \param const wxString&   
	*/

  bool Create(wxWindow*  parent , wxWindowID  id , const wxBitmap&  label , const wxPoint&  pos , const wxSize&  size = wxDefaultSize, long style = 0, const wxString&  name = "staticBitmap") ;
	/**
	 * \brief Returns a reference to the label bitmap. 
	*/

  wxBitmap GetBitmap() const;
	/**
	 * \brief Sets the bitmap label. 
	 * \param const wxBitmap&   
	*/

  virtual void SetBitmap(const wxBitmap&   label ) ;
};


#endif
