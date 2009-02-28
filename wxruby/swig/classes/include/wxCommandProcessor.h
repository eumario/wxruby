// wxCommandProcessor.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxCommandProcessor_h_)
#define _wxCommandProcessor_h_
class wxCommandProcessor : public wxObject
{
public:
	/**
	 * \brief Constructor.

  may be set to a positive integer to limit the number of
commands stored to it, otherwise (and by default) the list of commands can grow
arbitrarily. 
	 * \param int  
	*/

   wxCommandProcessor(int maxCommands = -1) ;
	/**
	 * \brief Destructor. 
	*/

  virtual  ~wxCommandProcessor() ;
	/**
	 * \brief Returns true if the currently-active command can be undone, false otherwise. 
	*/

  virtual bool CanUndo() ;
	/**
	 * \brief Deletes all the commands in the list and sets the current command pointer to NULL. 
	*/

  virtual void ClearCommands() ;
	/**
	 * \brief Executes (redoes) the current command (the command that has just been undone if any). 
	*/

  virtual bool Redo() ;
	/**
	 * \brief Returns the list of commands. 
	*/

  wxList& GetCommands() const;
	/**
	 * \brief Returns the maximum number of commands that the command processor stores. 
	*/

  int GetMaxCommands() const;
	/**
	 * \brief Returns the edit menu associated with the command processor. 
	*/

  wxMenu* GetEditMenu() const;
	/**
	 * \brief Returns the string that will be appended to the Redo menu item. 
	*/

  const wxString& GetRedoAccelerator() const;
	/**
	 * \brief Returns the string that will be shown for the redo menu item. 
	*/

  wxString GetRedoMenuLabel() const;
	/**
	 * \brief Returns the string that will be appended to the Undo menu item. 
	*/

  const wxString& GetUndoAccelerator() const;
	/**
	 * \brief Returns the string that will be shown for the undo menu item. 
	*/

  wxString GetUndoMenuLabel() const;
	/**
	 * \brief Initializes the command processor, setting the current command to the
last in the list (if any), and updating the edit menu (if one has been
specified). 
	*/

  virtual void Initialize() ;
	/**
	 * \brief Tells the command processor to update the Undo and Redo items on this
menu as appropriate. Set this to NULL if the menu is about to be
destroyed and command operations may still be performed, or the command
processor may try to access an invalid pointer. 
	 * \param wxMenu*   
	*/

  void SetEditMenu(wxMenu*  menu ) ;
	/**
	 * \brief Sets the menu labels according to the currently set menu and the current
command state. 
	*/

  void SetMenuStrings() ;
	/**
	 * \brief Sets the string that will be appended to the Redo menu item. 
	 * \param const wxString&  
	*/

  void SetRedoAccelerator(const wxString& accel ) ;
	/**
	 * \brief Sets the string that will be appended to the Undo menu item. 
	 * \param const wxString&  
	*/

  void SetUndoAccelerator(const wxString& accel ) ;
	/**
	 * \brief Submits a new command to the command processor. The command processor
calls wxCommand::Do to execute the command; if it succeeds, the command
is stored in the history list, and the associated edit menu (if any) updated
appropriately. If it fails, the command is deleted
immediately. Once Submit has been called, the passed command should not
be deleted directly by the application.

  indicates whether the successful command should be stored
in the history list. 
	 * \param wxCommand *  
	 * \param bool  
	*/

  virtual bool Submit(wxCommand * command , bool storeIt = true) ;
	/**
	 * \brief Undoes the command just executed. 
	*/

  virtual bool Undo() ;
};


#endif
