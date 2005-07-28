// wxControlWithItems.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxControlWithItems_h_)
#define _wxControlWithItems_h_
class wxControlWithItems : public wxControl
{
public:
	/**
	 * \brief Adds the item to the end of the list box. 
	 * \param const wxString&   
	*/

  int Append(const wxString&   item )  = 0;
	/**
	 * \brief  
	 * \param const wxString&   
	 * \param void *  
	*/

  int Append(const wxString&   item , void * clientData )  = 0;
	/**
	 * \brief Adds the item to the end of the list box, associating the given, typed or
untyped, client data pointer with the item. 
	 * \param const wxString&   
	 * \param wxClientData *  
	*/

  int Append(const wxString&   item , wxClientData * clientData )  = 0;
	/**
	 * \brief Appends several items at once to the control. Notice that calling this method
may be much faster than appending the items one by one if you need to add a lot
of items. 
	 * \param const wxArrayString&   
	*/

  void Append(const wxArrayString&  strings )  = 0;
	/**
	 * \brief Removes all items from the control.

  also deletes the client data of the existing items if it is owned
by the control. 
	*/

  void Clear()  = 0;
	/**
	 * \brief Deletes an item from the control. The client data associated with the item
will be also deleted if it is owned by the control.

Note that it is an error (signalled by an assert failure in debug builds) to
remove an item with the index negative or greater or equal than the number of
items in the control. 
	 * \param int  
	*/

  void Delete(int  n )  = 0;
	/**
	 * \brief Finds an item whose label matches the given string. 
	 * \param const wxString&   
	*/

  int FindString(const wxString&  string )  = 0;
	/**
	 * \brief Returns a pointer to the client data associated with the given item (if any).
It is an error to call this function for a control which doesn't have untyped
client data at all although it is ok to call it even if the given item doesn't
have any client data associated with it (but other items do). 
	 * \param int  
	*/

  void * GetClientData(int  n ) const;
	/**
	 * \brief Returns a pointer to the client data associated with the given item (if any).
It is an error to call this function for a control which doesn't have typed
client data at all although it is ok to call it even if the given item doesn't
have any client data associated with it (but other items do). 
	 * \param int  
	*/

  wxClientData * GetClientObject(int  n ) const;
	/**
	 * \brief Returns the number of items in the control. 
	*/

  int GetCount() const = 0;
	/**
	 * \brief Returns the index of the selected item or   if no item is
selected. 
	*/

  int GetSelection() const = 0;
	/**
	 * \brief Returns the label of the item with the given index. 
	 * \param int  
	*/

  wxString GetString(int  n ) const = 0;
	/**
	 * \brief Returns the label of the selected item or an empty string if no item is
selected. 
	*/

  wxString GetStringSelection() const;
	/**
	 * \brief Inserts the item into the list before pos.
Not valid for   or   styles, use Append instead. 
	 * \param const wxString&   
	 * \param int   
	*/

  int Insert(const wxString&   item , int  pos ) ;
	/**
	 * \brief  
	 * \param const wxString&   
	 * \param int   
	 * \param void *  
	*/

  int Insert(const wxString&   item , int  pos , void * clientData ) ;
	/**
	 * \brief Inserts the item into the list before pos, associating the given, typed or
untyped, client data pointer with the item.
Not valid for   or   styles, use Append instead. 
	 * \param const wxString&   
	 * \param int   
	 * \param wxClientData *  
	*/

  int Insert(const wxString&   item , int  pos , wxClientData * clientData ) ;
	/**
	 * \brief Returns   if the control is empty or   if it has some items. 
	*/

  bool IsEmpty() const;
	/**
	 * \brief This method is obsolete and was replaced with
 , please use the new method in
the new code. This method is only available if wxWindows was compiled with 
  defined and will disappear completely in
future versions. 
	*/

	/**
	 * \brief Associates the given untyped client data pointer with the given item. Note that
it is an error to call this function if any typed client data pointers had been
associated with the control items before. 
	 * \param int  
	 * \param void *  
	*/

  void SetClientData(int  n , void * data ) ;
	/**
	 * \brief Associates the given typed client data pointer with the given item: the 
  object will be deleted when the item is deleted (either explicitly
by using   or implicitly when the
control itself is destroyed).

Note that it is an error to call this function if any untyped client data
pointers had been associated with the control items before. 
	 * \param int  
	 * \param wxClientData *  
	*/

  void SetClientObject(int  n , wxClientData * data ) ;
	/**
	 * \brief Sets the choice by passing the desired string position. This does not cause
any command events to get emitted. 
	 * \param int  
	*/

  void SetSelection(int  n ) ;
	/**
	 * \brief Sets the label for the given item. 
	 * \param int  
	 * \param const wxString&   
	*/

  void SetString(int  n , const wxString&   string )  = 0;
	/**
	 * \brief Selects the item with the specified string in the control. This doesn't cause
any command events being emitted. 
	 * \param const wxString&   
	*/

  void SetStringSelection(const wxString&   string ) ;
};


#endif
