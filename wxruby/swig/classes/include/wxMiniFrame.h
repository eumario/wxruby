// wxMiniFrame.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxMiniFrame_h_)
#define _wxMiniFrame_h_
class wxMiniFrame : public wxFrame
{
public:
	/**
	 * \brief Default constructor. 
	*/

   wxMiniFrame() ;
	/**
	 * \brief Constructor, creating the window. 
	 * \param wxWindow*   
	 * \param wxWindowID   
	 * \param const wxString&   
	 * \param const wxPoint&  
	 * \param const wxSize&  
	 * \param long  
	 * \param const wxString&   
	*/

   wxMiniFrame(wxWindow*  parent , wxWindowID  id , const wxString&  title , const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_FRAME_STYLE, const wxString&  name = wxT("frame")) ;
	/**
	 * \brief Destructor. Destroys all child windows and menu bar if present. 
	*/

  virtual  ~wxMiniFrame() ;
	/**
	 * \brief Used in two-step frame construction. See  
for further details. 
	 * \param wxWindow*   
	 * \param wxWindowID   
	 * \param const wxString&   
	 * \param const wxPoint&  
	 * \param const wxSize&  
	 * \param long  
	 * \param const wxString&   
	*/

  bool Create(wxWindow*  parent , wxWindowID  id , const wxString&  title , const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_FRAME_STYLE, const wxString&  name = wxT("frame")) ;
};


#endif
