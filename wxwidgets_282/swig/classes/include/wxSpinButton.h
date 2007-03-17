// wxSpinButton.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxSpinButton_h_)
#define _wxSpinButton_h_
class wxSpinButton : public wxControl
{
public:
	/**
	 * \brief Default constructor. 
	*/

   wxSpinButton() ;
	/**
	 * \brief  
	 * \param wxWindow*  
	 * \param wxWindowID   
	 * \param const wxPoint&   
	 * \param const wxSize&   
	 * \param long  
	 * \param const wxString&   
	*/

   wxSpinButton(wxWindow*  parent , wxWindowID  id , const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long style = wxSP_HORIZONTAL, const wxString&  name = wxT("spinButton")) ;
	/**
	 * \brief Destructor, destroys the spin button control. 
	*/

  virtual  ~wxSpinButton() ;
	/**
	 * \brief Scrollbar creation function called by the spin button constructor.
See   for details. 
	 * \param wxWindow*  
	 * \param wxWindowID   
	 * \param const wxPoint&   
	 * \param const wxSize&   
	 * \param long  
	 * \param const wxString&   
	*/

  bool Create(wxWindow*  parent , wxWindowID  id , const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long style = wxSP_HORIZONTAL, const wxString&  name = wxT("spinButton")) ;
	/**
	 * \brief Returns the maximum permissible value. 
	*/

  int GetMax() const;
	/**
	 * \brief Returns the minimum permissible value. 
	*/

  int GetMin() const;
	/**
	 * \brief Returns the current spin button value. 
	*/

  int GetValue() const;
	/**
	 * \brief  
	 * \param int  
	 * \param int  
	*/

  void SetRange(int  min , int  max ) ;
	/**
	 * \brief Sets the value of the spin button. 
	 * \param int  
	*/

  void SetValue(int  value ) ;
};


#endif
