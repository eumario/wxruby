// wxSpinCtrl.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxSpinCtrl_h_)
#define _wxSpinCtrl_h_
class wxSpinCtrl : public wxControl
{
public:
	/**
	 * \brief Default constructor. 
	*/

   wxSpinCtrl() ;
	/**
	 * \brief Constructor, creating and showing a spin control. 
	 * \param wxWindow*   
	 * \param wxWindowID   
	 * \param const wxString&   
	 * \param const wxPoint&   
	 * \param const wxSize&   
	 * \param long   
	 * \param int   
	 * \param int   
	 * \param int   
	 * \param const wxString&   
	*/

  wxSpinCtrl(wxWindow*  parent , wxWindowID  id = -1, const wxString&  value = wxEmptyString, const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long  style = wxSP_ARROW_KEYS, int  min = 0, int  max = 100, int  initial = 0, const wxString&  name = wxT("wxSpinCtrl"));
	/**
	 * \brief Creation function called by the spin control constructor.

See   for details. 
	 * \param wxWindow*   
	 * \param wxWindowID   
	 * \param const wxString&   
	 * \param const wxPoint&   
	 * \param const wxSize&   
	 * \param long   
	 * \param int   
	 * \param int   
	 * \param int   
	 * \param const wxString&   
	*/

  bool Create(wxWindow*  parent , wxWindowID  id = -1, const wxString&  value = wxEmptyString, const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long  style = wxSP_ARROW_KEYS, int  min = 0, int  max = 100, int  initial = 0, const wxString&  name = wxT("wxSpinCtrl"));
	/**
	 * \brief  
	 * \param const wxString&   
	*/

  void SetValue(const wxString&  text ) ;
	/**
	 * \brief Sets the value of the spin control. 
	 * \param int   
	*/

  void SetValue(int  value ) ;
	/**
	 * \brief Gets the value of the spin control. 
	*/

  int GetValue() const;
	/**
	 * \brief Sets range of allowable values. 
	 * \param int   
	 * \param int   
	*/

  void SetRange(int  minVal , int  maxVal ) ;
	/**
	 * \brief Select the text in the text part of the control between  positions 
  (inclusive) and   (exclusive). This is similar to 
 .

  this is currently only implemented for Windows and generic versions
of the control. 
	 * \param long   
	 * \param long   
	*/

  void SetSelection(long  from , long  to ) ;
	/**
	 * \brief Gets minimal allowable value. 
	*/

  int GetMin() const;
	/**
	 * \brief Gets maximal allowable value. 
	*/

  int GetMax() const;
};


#endif
