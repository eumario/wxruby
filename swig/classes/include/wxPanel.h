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

   wxPanel(wxWindow*  parent , wxWindowID  id = -1, const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long style = wxTAB_TRAVERSAL, const wxString&  name = "panel") ;
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

  bool Create(wxWindow*  parent , wxWindowID  id , const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long style = wxTAB_TRAVERSAL, const wxString&  name = "panel") ;
	/**
	 * \brief Returns a pointer to the button which is the default for this window, or NULL.
The default button is the one activated by pressing the Enter key. 
	*/

  wxButton* GetDefaultItem() const;
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
	/**
	 * \brief Changes the default button for the panel. 
	 * \param wxButton   
	*/

  void SetDefaultItem(wxButton  *btn ) ;
};


#endif
