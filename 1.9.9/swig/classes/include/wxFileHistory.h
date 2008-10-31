// wxFileHistory.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxFileHistory_h_)
#define _wxFileHistory_h_
class wxFileHistory : public wxObject
{
public:
	/**
	 * \brief Constructor. Pass the maximum number of files that should be stored and
displayed.

  defaults to wxID_FILE1 and represents the id given to the first
history menu item.  Since menu items can't share the same ID you should change
idBase (To one of your own defined IDs) when using more than one wxFileHistory
in your application. 
	 * \param size_t  
	 * \param wxWindowID  
	*/

   wxFileHistory(size_t maxFiles = 9, wxWindowID idBase = wxID_FILE1) ;
	/**
	 * \brief Destructor. 
	*/

  virtual  ~wxFileHistory() ;
	/**
	 * \brief Adds a file to the file history list, if the object has a pointer to an appropriate file menu. 
	 * \param const wxString&   
	*/

  void AddFileToHistory(const wxString&  filename ) ;
	/**
	 * \brief Appends the files in the history list, to all menus managed by the file history object. 
	*/

  void AddFilesToMenu() ;
	/**
	 * \brief Appends the files in the history list, to the given menu only. 
	 * \param wxMenu*  
	*/

  void AddFilesToMenu(wxMenu*  menu ) ;
	/**
	 * \brief Returns the file at this index (zero-based). 
	 * \param size_t  
	*/

  wxString GetHistoryFile(size_t  index ) const;
	/**
	 * \brief Returns the maximum number of files that can be stored. 
	*/

  size_t GetMaxFiles() const;
	/**
	 * \brief Returns the number of files currently stored in the file history. 
	*/

  size_t GetNoHistoryFiles() const;
	/**
	 * \brief Loads the file history from the given config object. This function should be called explicitly by the application. 
	 * \param wxConfigBase&   
	*/

  void Load(wxConfigBase&  config ) ;
	/**
	 * \brief Removes this menu from the list of those managed by this object. 
	 * \param wxMenu*   
	*/

  void RemoveMenu(wxMenu*  menu ) ;
	/**
	 * \brief Saves the file history into the given config object. This must be called
explicitly by the application. 
	 * \param wxConfigBase&   
	*/

  void Save(wxConfigBase&  config ) ;
	/**
	 * \brief Adds this menu to the list of those managed by this object. 
	 * \param wxMenu*   
	*/

  void UseMenu(wxMenu*  menu ) ;
};


#endif
