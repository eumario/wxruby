// wxBitmapButton.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxBitmapButton_h_)
#define _wxBitmapButton_h_
class wxBitmapButton : public wxButton
{
public:
	/**
	 * \brief Default constructor. 
	*/

   wxBitmapButton() ;
	/**
	 * \brief  
	 * \param wxWindow*   
	 * \param wxWindowID   
	 * \param const wxBitmap&   
	 * \param const wxPoint&   
	 * \param const wxSize&   
	 * \param long   
	 * \param const wxValidator&   
	 * \param const wxString&   
	*/

   wxBitmapButton(wxWindow*  parent , wxWindowID  id , const wxBitmap&  bitmap , const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long  style = wxBU_AUTODRAW, const wxValidator&  validator = wxDefaultValidator, const wxString&  name = "button") ;
	/**
	 * \brief Destructor, destroying the button. 
	*/

  virtual  ~wxBitmapButton() ;
	/**
	 * \brief Button creation function for two-step creation. For more details, see  . 
	 * \param wxWindow*   
	 * \param wxWindowID  
	 * \param const wxBitmap&   
	 * \param const wxPoint&   
	 * \param const wxSize&   
	 * \param long  
	 * \param const wxValidator&   
	 * \param const wxString&   
	*/

  bool Create(wxWindow*  parent , wxWindowID  id , const wxBitmap&  bitmap , const wxPoint&  pos , const wxSize&  size = wxDefaultSize, long style = 0, const wxValidator&  validator = wxDefaultValidator, const wxString&  name = "button");
	/**
	 * \brief Returns the bitmap for the disabled state. 
	*/

  const wxBitmap& GetBitmapDisabled() const;
	/**
	 * \brief Returns the bitmap for the focused state. 
	*/

  const wxBitmap& GetBitmapFocus() const;
	/**
	 * \brief Returns the label bitmap (the one passed to the constructor). 
	*/

  const wxBitmap& GetBitmapLabel() const;
	/**
	 * \brief Returns the bitmap for the selected state. 
	*/

  const wxBitmap& GetBitmapSelected() const;
	/**
	 * \brief Sets the bitmap for the disabled button appearance. 
	 * \param const wxBitmap&   
	*/

  void SetBitmapDisabled(const wxBitmap&  bitmap ) ;
	/**
	 * \brief Sets the bitmap for the button appearance when it has the keyboard focus. 
	 * \param const wxBitmap&   
	*/

  void SetBitmapFocus(const wxBitmap&  bitmap ) ;
	/**
	 * \brief Sets the bitmap label for the button. 
	 * \param const wxBitmap&   
	*/

  void SetBitmapLabel(const wxBitmap&  bitmap ) ;
	/**
	 * \brief Sets the bitmap for the selected (depressed) button appearance. 
	 * \param const wxBitmap&   
	*/

  void SetBitmapSelected(const wxBitmap&  bitmap ) ;
  // the following were missing from the xml
  wxBitmap& GetBitmapDisabled();
  wxBitmap& GetBitmapFocus();
  wxBitmap& GetBitmapLabel();
  wxBitmap& GetBitmapSelected();
};


#endif
