// wxGauge.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxGauge_h_)
#define _wxGauge_h_
class wxGauge : public wxControl
{
public:
	/**
	 * \brief Default constructor. 
	*/

   wxGauge() ;
	/**
	 * \brief Constructor, creating and showing a gauge. 
	 * \param wxWindow*   
	 * \param wxWindowID   
	 * \param int  
	 * \param const wxPoint&   
	 * \param const wxSize&  
	 * \param long  
	 * \param const wxValidator&   
	 * \param const wxString&   
	*/

   wxGauge(wxWindow*  parent , wxWindowID  id , int  range , const wxPoint&  pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxGA_HORIZONTAL, const wxValidator&  validator = wxDefaultValidator, const wxString&  name = wxT("gauge")) ;
	/**
	 * \brief Destructor, destroying the gauge. 
	*/

  virtual  ~wxGauge() ;
	/**
	 * \brief Creates the gauge for two-step construction. See  
for further details. 
	 * \param wxWindow*   
	 * \param wxWindowID   
	 * \param int  
	 * \param const wxPoint&   
	 * \param const wxSize&  
	 * \param long  
	 * \param const wxValidator&   
	 * \param const wxString&   
	*/

  bool Create(wxWindow*  parent , wxWindowID  id , int  range , const wxPoint&  pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxGA_HORIZONTAL, const wxValidator&  validator = wxDefaultValidator, const wxString&  name = wxT("gauge")) ;
	/**
	 * \brief Returns the width of the 3D bezel face. 
	*/

  int GetBezelFace() const;
	/**
	 * \brief Returns the maximum position of the gauge. 
	*/

  int GetRange() const;
	/**
	 * \brief Returns the 3D shadow margin width. 
	*/

  int GetShadowWidth() const;
	/**
	 * \brief Returns the current position of the gauge. 
	*/

  int GetValue() const;
	/**
	 * \brief Sets the 3D bezel face width. 
	 * \param int   
	*/

  void SetBezelFace(int  width ) ;
	/**
	 * \brief Sets the range (maximum value) of the gauge. 
	 * \param int   
	*/

  void SetRange(int  range ) ;
	/**
	 * \brief Sets the 3D shadow width. 
	 * \param int   
	*/

  void SetShadowWidth(int  width ) ;
	/**
	 * \brief Sets the position of the gauge. 
	 * \param int   
	*/

  void SetValue(int  pos ) ;
};


#endif
