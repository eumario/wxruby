// wxToolTip.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxToolTip_h_)
#define _wxToolTip_h_
class wxToolTip : public wxObject
{
public:
	/**
	 * \brief Enable or disable tooltips globally. 
	 * \param bool   
	*/

  static void Enable(bool  flag ) ;
	/**
	 * \brief Set the delay after which the tooltip appears. 
	 * \param long   
	*/

  static void SetDelay(long  msecs ) ;
	/**
	 * \brief Constructor. 
	 * \param const wxString&   
	*/

   wxToolTip(const wxString&  tip ) ;
	/**
	 * \brief Set the tooltip text. 
	 * \param const wxString&   
	*/

  void SetTip(const wxString&  tip ) ;
	/**
	 * \brief Get the tooltip text. 
	*/

  wxString GetTip() const;
	/**
	 * \brief Get the associated window. 
	*/

  wxWindow* GetWindow() const;
};


#endif
