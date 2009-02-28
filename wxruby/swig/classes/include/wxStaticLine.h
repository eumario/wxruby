// wxStaticLine.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxStaticLine_h_)
#define _wxStaticLine_h_
class wxStaticLine : public wxControl
{
public:
	/**
	 * \brief Default constructor. 
	*/

   wxStaticLine() ;
	/**
	 * \brief Constructor, creating and showing a static line. 
	 * \param wxWindow*   
	 * \param wxWindowID   
	 * \param const wxPoint&  
	 * \param const wxSize&   
	 * \param long  
	 * \param const wxString&   
	*/

   wxStaticLine(wxWindow*  parent , wxWindowID  id = wxID_ANY , const wxPoint& pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long style = wxLI_HORIZONTAL, const wxString&  name = wxT("staticLine")) ;
	/**
	 * \brief Creates the static line for two-step construction. See  
for further details. 
	 * \param wxWindow*   
	 * \param wxWindowID   
	 * \param const wxPoint&  
	 * \param const wxSize&   
	 * \param long  
	 * \param const wxString&   
	*/

  bool Create(wxWindow*  parent , wxWindowID  id = wxID_ANY , const wxPoint& pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long style = 0, const wxString&  name = wxT("staticLine")) ;
	/**
	 * \brief Returns true if the line is vertical, false if horizontal. 
	*/

  bool IsVertical() const;
	/**
	 * \brief This static function returns the size which will be given to the smaller
dimension of the static line, i.e. its height for a horizontal line or its
width for a vertical one. 
	*/

  int GetDefaultSize() ;
};


#endif
