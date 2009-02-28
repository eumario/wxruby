// wxBusyInfo.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxBusyInfo_h_)
#define _wxBusyInfo_h_
class wxBusyInfo
{
public:
	/**
	 * \brief Constructs a busy info window as child of   and displays  
in it.

  If   is not   you must ensure that it is not
closed while the busy info is shown. 
	 * \param const wxString&  
	 * \param wxParent   
	*/

  wxBusyInfo(const wxString&  msg , wxWindow *parent = NULL);
	/**
	 * \brief Hides and closes the window containing the information text. 
	*/

  virtual  ~wxBusyInfo() ;
};


#endif
