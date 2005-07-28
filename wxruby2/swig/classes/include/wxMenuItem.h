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

  wxMenuItem(wxMenu *parentMenu = (wxMenu *)NULL,
             int id = wxID_SEPARATOR,
             const wxString& name = wxEmptyString,
             const wxString& help = wxEmptyString,
             wxItemKind kind = wxITEM_NORMAL,
             wxMenu *subMenu = (wxMenu *)NULL);
	/**
	 * \brief Destructor. 
	*/

  // compatibility only, don't use in new code
  wxMenuItem(wxMenu *parentMenu,
             int id,
             const wxString& text,
             const wxString& help,
             bool isCheckable,
             wxMenu *subMenu = (wxMenu *)NULL);

  virtual  ~wxMenuItem() ;
	/**
	 * \brief Checks or unchecks the menu item. 
	 * \param bool  
	*/

  void Check(bool bDoCheck = true);
	/**
	 * \brief Deletes the submenu, if any. 
	*/

  // mark item as belonging to the given radio group
  void SetAsRadioGroupStart();
  void SetRadioGroupStart(int start);
  void SetRadioGroupEnd(int end);

  void Enable(bool bDoEnable = true);

  void Toggle();

  wxString GetHelp();
	/**
	 * \brief Returns the menu item identifier. 
	*/

  int GetRealId();
  
  void SetId(int itemid);
  int GetId();
	/**
	 * \brief Returns the item kind, one of  ,  , 
  or  . 
	*/

  void SetKind(wxItemKind kind);
  wxItemKind GetKind();
	/**
	 * \brief  
	*/

  wxString GetLabel();
	/**
	 * \brief  
	 * \param const wxString&   
	*/

  static wxString GetLabelFromText(const wxString&  text ) ;
	/**
	 * \brief Gets the width of the menu item checkmark bitmap (Windows only). 
	*/

	/**
	 * \brief  
	*/

  wxString GetText();
	/**
	 * \brief Returns the submenu associated with the menu item, or NULL if there isn't one. 
	*/

  bool IsSubMenu();
  
  void SetSubMenu(wxMenu *menu);
  
  wxMenu* GetSubMenu();
	/**
	 * \brief Returns the text colour associated with the menu item (Windows only). 
	*/

  virtual void SetCheckable(bool checkable);

  bool IsCheckable();
	/**
	 * \brief Returns true if the item is checked. 
	*/

  bool IsChecked();
	/**
	 * \brief Returns true if the item is enabled. 
	*/

  bool IsEnabled();
	/**
	 * \brief Returns true if the item is a separator. 
	*/

  bool IsSeparator();
	/**
	 * \brief Sets the background colour associated with the menu item (Windows only). 
	 * \param const wxColour&   
	*/


  void SetHelp(const wxString& str);
	/**
	 * \brief Sets the width of the menu item checkmark bitmap (Windows only). 
	 * \param int  
	*/


	/**
	 * \brief Sets the text associated with the menu item. 
	 * \param const wxString&   
	*/

  void SetText(const wxString& strName);
	/**
	 * \brief Sets the text colour associated with the menu item (Windows only). 
	 * \param const wxColour&   
	*/

  wxMenu *GetMenu();
  void SetMenu(wxMenu* menu);
  
#if wxUSE_ACCEL
  // extract the accelerator from the given menu string, return NULL if none
  // found
  static wxAcceleratorEntry *GetAccelFromString(const wxString& label);

  // get our accelerator or NULL (caller must delete the pointer)
  virtual wxAcceleratorEntry *GetAccel();

  // set the accel for this item - this may also be done indirectly with
  // SetText()
  virtual void SetAccel(wxAcceleratorEntry *accel);
#endif // wxUSE_ACCEL  


  // Depreciated
  //void SetName(const wxString& str);
  //const wxString& GetName();

};


#endif
