// wxSashWindow.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxSashWindow_h_)
#define _wxSashWindow_h_
class wxSashWindow : public wxWindow
{
public:
	/**
	 * \brief Default constructor. 
	*/

   wxSashWindow() ;
	/**
	 * \brief Constructs a sash window, which can be a child of a frame, dialog or any other non-control window. 
	 * \param wxWindow*  
	 * \param wxWindowID   
	 * \param const wxPoint&   
	 * \param const wxSize&   
	 * \param long   
	 * \param const wxString&   
	*/

   wxSashWindow(wxWindow*  parent , wxWindowID  id , const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long  style = wxCLIP_CHILDREN, const wxString&  name = wxT("sashWindow")) ;
	/**
	 * \brief Destructor. 
	*/

  virtual  ~wxSashWindow() ;
	/**
	 * \brief Returns true if a sash is visible on the given edge, false otherwise. 
	 * \param wxSashEdgePosition   
	*/

  bool GetSashVisible(wxSashEdgePosition  edge ) const;
	/**
	 * \brief Gets the maximum window size in the x direction. 
	*/

  int GetMaximumSizeX() const;
	/**
	 * \brief Gets the maximum window size in the y direction. 
	*/

  int GetMaximumSizeY() const;
	/**
	 * \brief Gets the minimum window size in the x direction. 
	*/

  int GetMinimumSizeX() ;
	/**
	 * \brief Gets the minimum window size in the y direction. 
	 * \param int  
	*/

  int GetMinimumSizeY() const;
	/**
	 * \brief Returns true if the sash has a border, false otherwise. 
	 * \param wxSashEdgePosition   
	*/

  bool HasBorder(wxSashEdgePosition  edge ) const;
	/**
	 * \brief Sets the maximum window size in the x direction. 
	 * \param int  
	*/

  void SetMaximumSizeX(int  min ) ;
	/**
	 * \brief Sets the maximum window size in the y direction. 
	 * \param int  
	*/

  void SetMaximumSizeY(int  min ) ;
	/**
	 * \brief Sets the minimum window size in the x direction. 
	 * \param int  
	*/

  void SetMinimumSizeX(int  min ) ;
	/**
	 * \brief Sets the minimum window size in the y direction. 
	 * \param int  
	*/

  void SetMinimumSizeY(int  min ) ;
	/**
	 * \brief Call this function to make a sash visible or invisible on a particular edge. 
	 * \param wxSashEdgePosition   
	 * \param bool  
	*/

  void SetSashVisible(wxSashEdgePosition  edge , bool  visible ) ;
	/**
	 * \brief Call this function to give the sash a border, or remove the border. 
	 * \param wxSashEdgePosition   
	 * \param bool  
	*/

  void SetSashBorder(wxSashEdgePosition  edge , bool  hasBorder ) ;
};


#endif
