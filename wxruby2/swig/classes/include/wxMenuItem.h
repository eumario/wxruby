// wxMenuItem.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxMenuItem_h_)
#define _wxMenuItem_h_
class wxMenuItem : public wxObject
{
public:
	/**
	 * \brief Constructs a wxMenuItem object. 
	 * \param wxMenu*  
	 * \param int  
	 * \param const wxString&   
	 * \param const wxString&   
	 * \param wxItemKind   
	 * \param wxMenu*  
	*/

   wxMenuItem(wxMenu* parentMenu = NULL, int id = ID_SEPARATOR, const wxString&  text = wxT(""), const wxString&  helpString = wxT(""), wxItemKind  kind = wxITEM_NORMAL, wxMenu* subMenu = NULL) ;
	/**
	 * \brief Destructor. 
	*/

  virtual  ~wxMenuItem() ;
	/**
	 * \brief Checks or unchecks the menu item. 
	 * \param bool  
	*/

  void Check(bool  check ) ;
	/**
	 * \brief Deletes the submenu, if any. 
	*/

  void DeleteSubMenu() ;
	/**
	 * \brief Enables or disables the menu item. 
	 * \param bool  
	*/

  void Enable(bool  enable ) ;
	/**
	 * \brief Returns the background colour associated with the menu item (Windows only). 
	*/

  wxColour& GetBackgroundColour() const;
	/**
	 * \brief Returns the checked or unchecked bitmap (Windows only). 
	 * \param bool  
	*/

  wxBitmap& GetBitmap(bool checked = true) const;
	/**
	 * \brief Returns the font associated with the menu item (Windows only). 
	*/

  wxFont& GetFont() const;
	/**
	 * \brief Returns the help string associated with the menu item. 
	*/

  wxString GetHelp() const;
	/**
	 * \brief Returns the menu item identifier. 
	*/

  int GetId() const;
	/**
	 * \brief Returns the item kind, one of  ,  , 
  or  . 
	*/

  wxItemKind GetKind() const;
	/**
	 * \brief  
	*/

  wxString GetLabel() const;
	/**
	 * \brief  
	 * \param const wxString&   
	*/

  static wxString GetLabelFromText(const wxString&  text ) ;
	/**
	 * \brief Gets the width of the menu item checkmark bitmap (Windows only). 
	*/

  int GetMarginWidth() const;
	/**
	 * \brief Returns the text associated with the menu item.

  this function is deprecated, please use 
  or   
instead. 
	*/

  wxString GetName() const;
	/**
	 * \brief  
	*/

  wxString GetText() const;
	/**
	 * \brief Returns the submenu associated with the menu item, or NULL if there isn't one. 
	*/

  wxMenu* GetSubMenu() const;
	/**
	 * \brief Returns the text colour associated with the menu item (Windows only). 
	*/

  wxColour& GetTextColour() const;
	/**
	 * \brief Returns true if the item is checkable. 
	*/

  bool IsCheckable() const;
	/**
	 * \brief Returns true if the item is checked. 
	*/

  bool IsChecked() const;
	/**
	 * \brief Returns true if the item is enabled. 
	*/

  bool IsEnabled() const;
	/**
	 * \brief Returns true if the item is a separator. 
	*/

  bool IsSeparator() const;
	/**
	 * \brief Sets the background colour associated with the menu item (Windows only). 
	 * \param const wxColour&   
	*/

  void SetBackgroundColour(const wxColour&  colour ) const;
	/**
	 * \brief Sets the bitmap for the menu item (Windows and GTK+ only). It is
equivalent to  (bmp, wxNullBitmap). 
	 * \param const wxBitmap&   
	*/

  void SetBitmap(const wxBitmap&  bmp ) const;
	/**
	 * \brief Sets the checked/unchecked bitmaps for the menu item (Windows only). The first bitmap
is also used as the single bitmap for uncheckable menu items. 
	 * \param const wxBitmap&   
	 * \param const wxBitmap&   
	*/

  void SetBitmaps(const wxBitmap&  checked , const wxBitmap&  unchecked = wxNullBitmap) const;
	/**
	 * \brief Sets the font associated with the menu item (Windows only). 
	 * \param const wxFont&   
	*/

  void SetFont(const wxFont&  font ) const;
	/**
	 * \brief Sets the help string. 
	 * \param const wxString&   
	*/

  void SetHelp(const wxString&  helpString ) const;
	/**
	 * \brief Sets the width of the menu item checkmark bitmap (Windows only). 
	 * \param int  
	*/

  void SetMarginWidth(int  width ) const;
	/**
	 * \brief Sets the text associated with the menu item. 
	 * \param const wxString&   
	*/

  void SetText(const wxString&  text ) const;
	/**
	 * \brief Sets the text colour associated with the menu item (Windows only). 
	 * \param const wxColour&   
	*/

  void SetTextColour(const wxColour&  colour ) const;
};


#endif
