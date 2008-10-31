// wxMDIChildFrame.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxMDIChildFrame_h_)
#define _wxMDIChildFrame_h_
class wxMDIChildFrame : public wxFrame
{
public:
	/**
	 * \brief Default constructor. 
	*/

   wxMDIChildFrame() ;
	/**
	 * \brief Constructor, creating the window. 
	 * \param wxMDIParentFrame*   
	 * \param wxWindowID   
	 * \param const wxString&   
	 * \param const wxPoint&  
	 * \param const wxSize&  
	 * \param long  
	 * \param const wxString&   
	*/

   wxMDIChildFrame(wxMDIParentFrame*  parent , wxWindowID  id , const wxString&  title , const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_FRAME_STYLE, const wxString&  name = wxT("frame")) ;
	/**
	 * \brief Destructor. Destroys all child windows and menu bar if present. 
	*/

  virtual  ~wxMDIChildFrame() ;
	/**
	 * \brief Activates this MDI child frame. 
	*/

  void Activate() ;
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

  bool Create(wxMDIParentFrame*  parent , wxWindowID  id , const wxString&  title , const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_FRAME_STYLE, const wxString&  name = wxT("frame"));
	/**
	 * \brief Maximizes this MDI child frame. 
	*/

  void Maximize() ;
	/**
	 * \brief Restores this MDI child frame (unmaximizes). 
	*/

  void Restore() ;
};


#endif
