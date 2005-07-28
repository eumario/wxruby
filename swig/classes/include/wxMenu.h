// wxMenu.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxMenu_h_)
#define _wxMenu_h_
class wxMenu : public wxEvtHandler
{
public:
	/**
	 * \brief Constructs a wxMenu object. 
	 * \param const wxString&   
	 * \param long  
	*/

   wxMenu(const wxString&  title = wxT(""), long style = 0) ;
	/**
	 * \brief Constructs a wxMenu object. 
	 * \param long  
	*/

   wxMenu(long  style ) ;
	/**
	 * \brief Destructor, destroying the menu.

Note: under Motif, a popup menu must have a valid parent (the window
it was last popped up on) when being destroyed. Therefore, make sure
you delete or re-use the popup menu   destroying the
parent window. Re-use in this context means popping up the menu on
a different window from last time, which causes an implicit destruction
and recreation of internal data structures. 
	*/

  virtual  ~wxMenu() ;
	/**
	 * \brief Adds a string item to the end of the menu. 
	 * \param int  
	 * \param const wxString&   
	 * \param const wxString&   
	 * \param wxItemKind  
	*/

  wxMenuItem* Append(int itemid, const wxString& text, const wxString& help = wxEmptyString, wxItemKind kind = wxITEM_NORMAL);
	/**
	 * \brief Adds a pull-right submenu to the end of the menu. Append the submenu to the parent
menu   you have added your menu items, or accelerators may not be
registered properly. 
	 * \param int  
	 * \param const wxString&   
	 * \param wxMenu *  
	 * \param const wxString&   
	*/

  wxMenuItem* Append(int itemid, const wxString& text, wxMenu *submenu, const wxString& help = wxEmptyString);
	/**
	 * \brief  
	 * \param wxMenuItem*  
	*/

  wxMenuItem* Append(wxMenuItem *item);
	/**
	 * \brief Adds a checkable item to the end of the menu. 
	 * \param int  
	 * \param const wxString&   
	 * \param const wxString&   
	*/

  void AppendCheckItem(int  id , const wxString&   item , const wxString&  helpString = wxT("")) ;
	/**
	 * \brief Adds a radio item to the end of the menu. All consequent radio items form a
group and when an item in the group is checked, all the others are
automatically unchecked.

  Currently only implemented under Windows and GTK, use
  to test for availability of this feature. 
	 * \param int  
	 * \param const wxString&   
	 * \param const wxString&   
	*/

  void AppendRadioItem(int  id , const wxString&   item , const wxString&  helpString = wxT("")) ;
	/**
	 * \brief Adds a separator to the end of the menu. 
	*/

  void AppendSeparator() ;
	/**
	 * \brief Inserts a break in a menu, causing the next appended item to appear in a new column. 
	*/

  void Break() ;
	/**
	 * \brief Checks or unchecks the menu item. 
	 * \param int  
	 * \param const bool  
	*/

  void Check(int  id , const bool  check ) ;
	/**
	 * \brief  
	 * \param int   
	*/

  void Delete(int  id ) ;
	/**
	 * \brief Deletes the menu item from the menu. If the item is a submenu, it will
  be deleted. Use   if you want to
delete a submenu. 
	 * \param wxMenuItem *  
	*/

  void Delete(wxMenuItem * item ) ;
	/**
	 * \brief  
	 * \param int   
	*/

  void Destroy(int  id ) ;
	/**
	 * \brief Deletes the menu item from the menu. If the item is a submenu, it will
be deleted. Use   if you want to keep the submenu
(for example, to reuse it later). 
	 * \param wxMenuItem *  
	*/

  void Destroy(wxMenuItem * item ) ;
	/**
	 * \brief Enables or disables (greys out) a menu item. 
	 * \param int  
	 * \param const bool  
	*/

  void Enable(int  id , const bool  enable ) ;
	/**
	 * \brief Finds the menu item id for a menu item string. 
	 * \param const wxString&   
	*/

  int FindItem(const wxString&  itemString ) const;
	/**
	 * \brief Finds the menu item object associated with the given menu item identifier and,
optionally, the (sub)menu it belongs to.

\perlnote{In wxPerl this method takes just the   parameter;
in scalar context it returns the associated  , in list
context it returns a 2-element list  } 
	 * \param int  
	 * \param wxMenu **  
	*/

  wxMenuItem * FindItem(int  id , wxMenu ** menu = NULL) const;
	/**
	 * \brief Returns the wxMenuItem given a position in the menu. 
	 * \param size_t   
	*/

  wxMenuItem* FindItemByPosition(size_t  position ) const;
	/**
	 * \brief  
	 * \param int  
	*/

  wxString GetHelpString(int  id ) const;
	/**
	 * \brief Returns a menu item label. 
	 * \param int  
	*/

  wxString GetLabel(int  id ) const;
	/**
	 * \brief Returns the number of items in the menu. 
	*/

  size_t GetMenuItemCount() const;
	/**
	 * \brief Returns the list of items in the menu. wxMenuItemList is a pseudo-template
list class containing wxMenuItem pointers. 
	*/

  const wxMenuItemList& GetMenuItems() const;
	/**
	 * \brief Returns the title of the menu. 
	*/

  wxString GetTitle() const;
	/**
	 * \brief  
	 * \param size_t   
	 * \param wxMenuItem *  
	*/

  bool Insert(size_t  pos , wxMenuItem * item ) ;
	/**
	 * \brief Inserts the given   before the position  . Inserting the item
at the position   is the same
as appending it. 
	 * \param size_t   
	 * \param int  
	 * \param const wxString&   
	 * \param const wxString&   
	 * \param wxItemKind  
	*/

  void Insert(size_t  pos , int  id , const wxString&   item , const wxString&  helpString = wxT(""), wxItemKind kind = wxITEM_NORMAL) ;
	/**
	 * \brief Inserts a checkable item at the given position. 
	 * \param size_t   
	 * \param int  
	 * \param const wxString&   
	 * \param const wxString&   
	*/

  void InsertCheckItem(size_t  pos , int  id , const wxString&   item , const wxString&  helpString = wxT("")) ;
	/**
	 * \brief Inserts a radio item at the given position. 
	 * \param size_t   
	 * \param int  
	 * \param const wxString&   
	 * \param const wxString&   
	*/

  void InsertRadioItem(size_t  pos , int  id , const wxString&   item , const wxString&  helpString = wxT("")) ;
	/**
	 * \brief Inserts a separator at the given position. 
	 * \param size_t   
	*/

  void InsertSeparator(size_t  pos ) ;
	/**
	 * \brief Determines whether a menu item is checked. 
	 * \param int  
	*/

  bool IsChecked(int  id ) const;
	/**
	 * \brief Determines whether a menu item is enabled. 
	 * \param int  
	*/

  bool IsEnabled(int  id ) const;
	/**
	 * \brief  
	 * \param wxMenuItem *  
	*/

  void Prepend(wxMenuItem * item );
	/**
	 * \brief Inserts the given   at the position 0, i.e. before all the other
existing items. 
	 * \param int  
	 * \param const wxString&   
	 * \param const wxString&   
	 * \param wxItemKind  
	*/

  void Prepend(int  id , const wxString&   item , const wxString&  helpString = wxT(""), wxItemKind kind = wxITEM_NORMAL) ;
	/**
	 * \brief Inserts a checkable item at the position 0. 
	 * \param int  
	 * \param const wxString&   
	 * \param const wxString&   
	*/

  void PrependCheckItem(int  id , const wxString&   item , const wxString&  helpString = wxT("")) ;
	/**
	 * \brief Inserts a radio item at the position 0. 
	 * \param int  
	 * \param const wxString&   
	 * \param const wxString&   
	*/

  void PrependRadioItem(int  id , const wxString&   item , const wxString&  helpString = wxT("")) ;
	/**
	 * \brief Inserts a separator at the position 0. 
	 * \param size_t   
	*/

  void PrependSeparator();
	/**
	 * \brief  
	 * \param int   
	*/

  wxMenuItem * Remove(int  id ) ;
	/**
	 * \brief Removes the menu item from the menu but doesn't delete the associated C++
object. This allows to reuse the same item later by adding it back to the menu
(especially useful with submenus). 
	 * \param wxMenuItem *  
	*/

  wxMenuItem * Remove(wxMenuItem * item ) ;
	/**
	 * \brief Sets an item's help string. 
	 * \param int  
	 * \param const wxString&   
	*/

  void SetHelpString(int  id , const wxString&  helpString ) ;
	/**
	 * \brief  
	 * \param int  
	 * \param const wxString&   
	*/

  void SetLabel(int  id , const wxString&  label ) ;
	/**
	 * \brief Sets the title of the menu. 
	 * \param const wxString&   
	*/

  void SetTitle(const wxString&  title ) ;
	/**
	 * \brief Sends events to   (or owning window if NULL) to update the
menu UI. This is called just before the menu is popped up with  , but
the application may call it at other times if required. 
	 * \param wxEvtHandler*  
	*/

  void UpdateUI(wxEvtHandler* source = NULL);
  void Append(int itemid, const wxString& text, const wxString& help, bool isCheckable);
  void Insert(size_t pos, int itemid, const wxString& text, const wxString& help, bool isCheckable);
  void Prepend(int itemid, const wxString& text, const wxString& help, bool isCheckable);
  static void LockAccels(bool locked);    
};


#endif
