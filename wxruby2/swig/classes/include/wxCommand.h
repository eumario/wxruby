// wxCommand.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxCommand_h_)
#define _wxCommand_h_
class wxCommand : public wxObject
{
public:
	/**
	 * \brief Constructor. wxCommand is an abstract class, so you will need to derive
a new class and call this constructor from your own constructor.

  tells the command processor whether this command is undo-able. You
can achieve the same functionality by overriding the CanUndo member function (if for example
the criteria for undoability is context-dependent).

  must be supplied for the command processor to display the command name
in the application's edit menu. 
	 * \param bool  
	 * \param const wxString&   
	*/

   wxCommand(bool canUndo = false, const wxString&  name = NULL) ;
	/**
	 * \brief Destructor. 
	*/

  virtual  ~wxCommand() ;
	/**
	 * \brief Returns true if the command can be undone, false otherwise. 
	*/

  bool CanUndo() ;
	/**
	 * \brief Override this member function to execute the appropriate action when called.
Return true to indicate that the action has taken place, false otherwise.
Returning false will indicate to the command processor that the action is
not undoable and should not be added to the command history. 
	*/

  bool Do() ;
	/**
	 * \brief Returns the command name. 
	*/

  wxString GetName() ;
	/**
	 * \brief Override this member function to un-execute a previous Do.
Return true to indicate that the action has taken place, false otherwise.
Returning false will indicate to the command processor that the action is
not redoable and no change should be made to the command history.

How you implement this command is totally application dependent, but typical
strategies include:

 

The docview sample uses the first method, to remove or restore segments
in the drawing. 
	*/

  bool Undo() ;
};


#endif
