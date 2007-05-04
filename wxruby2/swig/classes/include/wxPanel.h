// wxPanel.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxPanel_h_)
#define _wxPanel_h_
class wxPanel : public wxWindow
{
public:
	/**
	 * \brief Default constructor. 
	*/

  //wxPanel();
	/**
	 * \brief Constructor. 
	 * \param wxWindow*   
	 * \param wxWindowID   
	 * \param const wxPoint&   
	 * \param const wxSize&   
	 * \param long  
	 * \param const wxString&   
	*/

   wxPanel(wxWindow*  parent , wxWindowID  id = -1, const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long style = wxTAB_TRAVERSAL|wxNO_BORDER, const wxString&  name = wxT("panel")) ;
	/**
	 * \brief Destructor. Deletes any child windows before deleting the physical window. 
	*/

  virtual  ~wxPanel() ;
	/**
	 * \brief Used for two-step panel construction. See  
for details. 
	 * \param wxWindow*   
	 * \param wxWindowID   
	 * \param const wxPoint&   
	 * \param const wxSize&   
	 * \param long  
	 * \param const wxString&   
	*/

  bool Create(wxWindow*  parent , wxWindowID  id , const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long style = wxTAB_TRAVERSAL, const wxString&  name = wxT("panel")) ;
	/**
	 * \brief Sends a  , which
in turn transfers data to the dialog via validators. 
	*/

  void InitDialog() ;
	/**
	 * \brief The default handler for wxEVT_SYS_COLOUR_CHANGED. 
	 * \param wxSysColourChangedEvent&   
	*/

  virtual void OnSysColourChanged(wxSysColourChangedEvent&  event ) ;
};


#endif
