// wxTaskBarIcon.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxTaskBarIcon_h_)
#define _wxTaskBarIcon_h_
class wxTaskBarIcon : public wxEvtHandler
{
public:
	/**
	 * \brief Default constructor. 
	*/

   wxTaskBarIcon() ;
	/**
	 * \brief Destroys the wxTaskBarIcon object, removing the icon if not already removed. 
	*/

  virtual  ~wxTaskBarIcon() ;
	/**
	 * \brief Returns true if   was called with no subsequent  . 
	*/

  bool IsIconInstalled() ;
	/**
	 * \brief Returns true if the object initialized successfully. 
	*/

  bool IsOk() ;
	/**
	 * \brief Pops up a menu at the current mouse position. The events can be handled by
a class derived from wxTaskBarIcon. 
	 * \param wxMenu*  
	*/

  bool PopupMenu(wxMenu*  menu ) ;
	/**
	 * \brief Removes the icon previously set with  . 
	*/

  bool RemoveIcon() ;
	/**
	 * \brief Sets the icon, and optional tooltip text. 
	 * \param const wxIcon&  
	 * \param const wxString&   
	*/

  bool SetIcon(const wxIcon&  icon , const wxString&  tooltip ) ;

 protected:
  // Override to return a menu on right-click
  virtual wxMenu* CreatePopupMenu();
};


#endif
