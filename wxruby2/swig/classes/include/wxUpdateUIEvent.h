// wxUpdateUIEvent.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxUpdateUIEvent_h_)
#define _wxUpdateUIEvent_h_
class wxUpdateUIEvent : public wxCommandEvent
{
public:
	/**
	 * \brief Constructor. 
	 * \param wxWindowID   
	*/

   wxUpdateUIEvent(wxWindowID  commandId = 0) ;
	/**
	 * \brief Check or uncheck the UI element. 
	 * \param bool  
	*/

  void Check(bool  check ) ;
	/**
	 * \brief Enable or disable the UI element. 
	 * \param bool  
	*/

  void Enable(bool  enable ) ;
	/**
	 * \brief Returns true if the UI element should be checked. 
	*/

  bool GetChecked() const;
	/**
	 * \brief Returns true if the UI element should be enabled. 
	*/

  bool GetEnabled() const;
	/**
	 * \brief Returns true if the application has called  . For wxWindows internal use only. 
	*/

  bool GetSetChecked() const;
	/**
	 * \brief Returns true if the application has called  . For wxWindows internal use only. 
	*/

  bool GetSetEnabled() const;
	/**
	 * \brief Returns true if the application has called  . For wxWindows internal use only. 
	*/

  bool GetSetText() const;
	/**
	 * \brief Returns the text that should be set for the UI element. 
	*/

  wxString GetText() const;
	/**
	 * \brief Sets the text for this UI element. 
	 * \param const wxString&  
	*/

  void SetText(const wxString&  text ) ;
  // the following were missing from the xml
  virtual ~wxUpdateUIEvent();
};


#endif
