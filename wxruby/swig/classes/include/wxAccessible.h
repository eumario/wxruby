// wxAccessible.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxAccessible_h_)
#define _wxAccessible_h_
class wxAccessible : public wxObject
{
public:
	/**
	 * \brief Constructor, taking an optional window. The object can be associated with
a window later. 
	 * \param wxWindow*   
	*/

   wxAccessible(wxWindow*  win = NULL) ;
	/**
	 * \brief Destructor. 
	*/

  virtual  ~wxAccessible() ;
	/**
	 * \brief Performs the default action for the object.   is 0 (the action for this object)
or greater than 0 (the action for a child). Return wxACC_NOT_SUPPORTED if there
is no default action for this window (e.g. an edit control). 
	 * \param int   
	*/

  virtual wxAccStatus DoDefaultAction(int  childId ) ;
	/**
	 * \brief Gets the specified child (starting from 1). If   is NULL and the return value is wxACC_OK,
this means that the child is a simple element and not an accessible object. 
	 * \param int   
	 * \param wxAccessible**   
	*/

  virtual wxAccStatus GetChild(int  childId , wxAccessible**  child ) ;
	/**
	 * \brief Returns the number of children in  . 
	 * \param int*   
	*/

  virtual wxAccStatus GetChildCount(int*  childCount ) ;
	/**
	 * \brief Gets the default action for this object (0) or a child (greater than 0).
Return wxACC_OK even if there is no action.   is the action, or the empty
string if there is no action. The retrieved string describes the action that is performed on an object,
not what the object does as a result. For example, a toolbar button that prints
a document has a default action of &quot;Press&quot; rather than &quot;Prints the current document.&quot; 
	 * \param int   
	 * \param wxString*   
	*/

  virtual wxAccStatus GetDefaultAction(int  childId , wxString*  actionName ) ;
	/**
	 * \brief Returns the description for this object or a child. 
	 * \param int   
	 * \param wxString*   
	*/

  virtual wxAccStatus GetDescription(int  childId , wxString*  description ) ;
	/**
	 * \brief Gets the window with the keyboard focus. If childId is 0 and child is NULL, no object in
this subhierarchy has the focus. If this object has the focus, child should be 'this'. 
	 * \param int*   
	 * \param wxAccessible**   
	*/

  virtual wxAccStatus GetFocus(int*  childId , wxAccessible**  child ) ;
	/**
	 * \brief Returns help text for this object or a child, similar to tooltip text. 
	 * \param int   
	 * \param wxString*   
	*/

  virtual wxAccStatus GetHelpText(int  childId , wxString*  helpText ) ;
	/**
	 * \brief Returns the keyboard shortcut for this object or child.
Return e.g. ALT+K. 
	 * \param int   
	 * \param wxString*   
	*/

  virtual wxAccStatus GetKeyboardShortcut(int  childId , wxString*  shortcut ) ;
	/**
	 * \brief Returns the rectangle for this object (id is 0) or a child element (id is greater than 0).
  is in screen coordinates. 
	 * \param wxRect&   
	 * \param int   
	*/

  virtual wxAccStatus GetLocation(wxRect&  rect , int  elementId ) ;
	/**
	 * \brief Gets the name of the specified object. 
	 * \param int   
	 * \param wxString*   
	*/

  virtual wxAccStatus GetName(int  childId , wxString*  name ) ;
	/**
	 * \brief Returns the parent of this object, or NULL. 
	 * \param wxAccessible**   
	*/

  virtual wxAccStatus GetParent(wxAccessible**  parent ) ;
	/**
	 * \brief Returns a role constant describing this object. See   for a list
of these roles. 
	 * \param int   
	 * \param wxAccRole*   
	*/

  virtual wxAccStatus GetRole(int  childId , wxAccRole*  role ) ;
	/**
	 * \brief Gets a variant representing the selected children
of this object.

Acceptable values are: 
	 * \param wxVariant*   
	*/

  virtual wxAccStatus GetSelections(wxVariant*  selections ) ;
	/**
	 * \brief Returns a state constant. See   for a list
of these states. 
	 * \param int   
	 * \param long*   
	*/

  virtual wxAccStatus GetState(int  childId , long*  state ) ;
	/**
	 * \brief Returns a localized string representing the value for the object
or child. 
	 * \param int   
	 * \param wxString*   
	*/

  virtual wxAccStatus GetValue(int  childId , wxString*  strValue ) ;
	/**
	 * \brief Returns the window associated with this object. 
	*/

  wxWindow* GetWindow() ;
	/**
	 * \brief Returns a status value and object id to indicate whether the given point was on this or
a child object. Can return either a child object, or an integer
representing the child element, starting from 1.

  is in screen coordinates. 
	 * \param const wxPoint&   
	 * \param int*   
	 * \param wxAccessible**   
	*/

  virtual wxAccStatus HitTest(const wxPoint&  pt , int*  childId , wxAccessible**  childObject ) ;
	/**
	 * \brief Navigates from   to  / . 
	 * \param wxNavDir   
	 * \param int   
	 * \param int*   
	 * \param wxAccessible**   
	*/

  virtual wxAccStatus Navigate(wxNavDir  navDir , int  fromId , int*  toId , wxAccessible**  toObject ) ;
	/**
	 * \brief Allows the application to send an event when something changes in an accessible object. 
	 * \param int  
	 * \param wxWindow*   
	 * \param wxAccObjectt   
	 * \param int   
	*/

  virtual static void NotifyEvent(int  eventType , wxWindow*  window , wxAccObjectt  objectType , int  objectType ) ;
	/**
	 * \brief Selects the object or child. See   for a list
of the selection actions. 
	 * \param int   
	 * \param wxAccSelectionFlags   
	*/

  virtual wxAccStatus Select(int  childId , wxAccSelectionFlags  selectFlags ) ;
	/**
	 * \brief Sets the window associated with this object. 
	 * \param wxWindow*   
	*/

  void SetWindow(wxWindow*  window ) ;
};


#endif
