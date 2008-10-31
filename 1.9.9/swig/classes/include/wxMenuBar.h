// wxMenuBar.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxMenuBar_h_)
#define _wxMenuBar_h_
class wxMenuBar : public wxWindow
{
public:
	/**
	 * \brief Default constructor. 
	 * \param long   
	*/

   wxMenuBar(long  style = 0) ;
	/**
	 * \brief Construct a menu bar from arrays of menus and titles.











\pythonnote{Only the default constructor is supported in wxPython.
Use wxMenuBar.Append instead.}

\perlnote{wxPerl only supports the first constructor: 
use   instead.} 
	 * \param int  
	 * \param wxMenu*  
	 * \param const wxString   
	*/

   wxMenuBar(int  n , wxMenu*  menus[] , const wxString  titles[] ) ;
	/**
	 * \brief Destructor, destroying the menu bar and removing it from the parent frame (if any). 
	*/

  virtual  ~wxMenuBar() ;
	/**
	 * \brief Adds the item to the end of the menu bar. 
	 * \param wxMenu *  
	 * \param const wxString&   
	*/

  bool Append(wxMenu * menu , const wxString&  title ) ;
	/**
	 * \brief Checks or unchecks a menu item. 
	 * \param int  
	 * \param const bool  
	*/

  void Check(int  id , const bool  check ) ;
	/**
	 * \brief Enables or disables (greys out) a menu item. 
	 * \param int  
	 * \param const bool  
	*/

  void Enable(int  id , const bool  enable ) ;
	/**
	 * \brief Enables or disables a whole menu. 
	 * \param int  
	 * \param const bool  
	*/

  void EnableTop(int  pos , const bool  enable ) ;
	/**
	 * \brief Returns the index of the menu with the given   or wxNOT_FOUND if no
such menu exists in this menubar. The   parameter may specify either
the menu title (with accelerator characters, i.e.  ) or just the
menu label ( ) indifferently. 
	 * \param const wxString&   
	*/

  int FindMenu(const wxString&  title ) ;//const; (the const messes up the SWIG code generation)
	/**
	 * \brief Finds the menu item id for a menu name/menu item string pair. 
	 * \param const wxString&   
	 * \param const wxString&   
	*/

  int FindMenuItem(const wxString&  menuString , const wxString&  itemString ) const;
	/**
	 * \brief Finds the menu item object associated with the given menu item identifier. 
	 * \param int  
	 * \param wxMenu  
	*/

  wxMenuItem * FindItem(int  id , wxMenu **menu = NULL) const;
	/**
	 * \brief Gets the help string associated with the menu item identifier. 
	 * \param int  
	*/

  wxString GetHelpString(int  id ) const;
	/**
	 * \brief Gets the label associated with a menu item. 
	 * \param int  
	*/

  wxString GetLabel(int  id ) const;
	/**
	 * \brief Returns the label of a top-level menu. Note that the returned string does not
include the accelerator characters which could have been specified in the menu
title string during its construction. 
	 * \param int  
	*/

  wxString GetLabelTop(int  pos ) const;
	/**
	 * \brief Returns the menu at   (zero-based). 
	 * \param int  
	*/

  wxMenu* GetMenu(int  menuIndex ) const;
	/**
	 * \brief Returns the number of menus in this menubar. 
	*/

  int GetMenuCount() const;
	/**
	 * \brief Inserts the menu at the given position into the menu bar. Inserting menu at
position 0 will insert it in the very beginning of it, inserting at position 
  is the same as calling 
 . 
	 * \param size_t   
	 * \param wxMenu *  
	 * \param const wxString&   
	*/

  bool Insert(size_t  pos , wxMenu * menu , const wxString&  title ) ;
	/**
	 * \brief Determines whether an item is checked. 
	 * \param int  
	*/

  bool IsChecked(int  id ) const;
	/**
	 * \brief Determines whether an item is enabled. 
	 * \param int  
	*/

  bool IsEnabled(int  id ) const;
	/**
	 * \brief Redraw the menu bar 
	*/

  void Refresh() ;
	/**
	 * \brief Removes the menu from the menu bar and returns the menu object - the caller is
responsible for deleting it. This function may be used together with 
  to change the menubar
dynamically. 
	 * \param size_t   
	*/

  wxMenu * Remove(size_t  pos ) ;
	/**
	 * \brief Replaces the menu at the given position with another one. 
	 * \param size_t   
	 * \param wxMenu *  
	 * \param const wxString&   
	*/

  wxMenu * Replace(size_t  pos , wxMenu * menu , const wxString&  title ) ;
	/**
	 * \brief Sets the help string associated with a menu item. 
	 * \param int  
	 * \param const wxString&   
	*/

  void SetHelpString(int  id , const wxString&  helpString ) ;
	/**
	 * \brief Sets the label of a menu item. 
	 * \param int  
	 * \param const wxString&   
	*/

  void SetLabel(int  id , const wxString&  label ) ;
	/**
	 * \brief Sets the label of a top-level menu. 
	 * \param int  
	 * \param const wxString&   
	*/

  void SetLabelTop(int  pos , const wxString&  label ) ;
};


#endif
