// wxList.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxList_h_)
#define _wxList_h_
class wxList : public wxObject
{
public:
	/**
	 * \brief  
	*/

   wxList() ;
	/**
	 * \brief  
	 * \param unsigned int  
	*/

   wxList(unsigned int  key_type ) ;
	/**
	 * \brief  
	 * \param int  
	 * \param T *  
	*/

   wxList(int  n , T * objects[] ) ;
	/**
	 * \brief Constructors.   is one of wxKEY_NONE, wxKEY_INTEGER, or wxKEY_STRING,
and indicates what sort of keying is required (if any).

  is an array of   objects with which to initialize the list.

The variable-length argument list constructor must be supplied with a
terminating NULL. 
	 * \param T *  
	*/

   wxList(T * object ) ;
	/**
	 * \brief Destroys the list.  Also destroys any remaining nodes, but does not destroy
client data held in the nodes. 
	*/

  virtual  ~wxList() ;
	/**
	 * \brief  
	 * \param T *  
	*/

  wxNode<T> * Append(T * object ) ;
	/**
	 * \brief  
	 * \param long  
	 * \param T *  
	*/

  wxNode<T> * Append(long  key , T * object ) ;
	/**
	 * \brief Appends a new   to the end of the list and puts a
pointer to the   in the node.  The last two forms store a key
with the object for later retrieval using the key. The new node is returned in
each case.

The key string is copied and stored by the list implementation. 
	 * \param const wxString&   
	 * \param T *  
	*/

  wxNode<T> * Append(const wxString&  key , T * object ) ;
	/**
	 * \brief Clears the list (but does not delete the client data stored with each node
unless you called DeleteContents( ), in which case it deletes data). 
	*/

  void Clear() ;
	/**
	 * \brief If   is  , instructs the list to call   on the client contents of
a node whenever the node is destroyed. The default is  . 
	 * \param bool  
	*/

  void DeleteContents(bool  destroy ) ;
	/**
	 * \brief Deletes the given node from the list, returning   if successful. 
	 * \param wxNode<T> *  
	*/

  bool DeleteNode(wxNode<T> * node ) ;
	/**
	 * \brief Finds the given client   and deletes the appropriate node from the list, returning
  if successful. The application must delete the actual object separately. 
	 * \param T *  
	*/

  bool DeleteObject(T * object ) ;
	/**
	 * \brief Returns the node whose client date is   or NULL if none found. 
	 * \param T *  
	*/

  wxNode<T> * Find(T *  object ) ;
	/**
	 * \brief  
	 * \param long  
	*/

  wxNode<T> * Find(long  key ) ;
	/**
	 * \brief Returns the node whose stored key matches  . Use on a keyed list only. 
	 * \param const wxString&   
	*/

  wxNode<T> * Find(const wxString&  key ) ;
	/**
	 * \brief Returns the number of elements in the list. 
	*/

  size_t GetCount() const;
	/**
	 * \brief Returns the first node in the list (NULL if the list is empty). 
	*/

  wxNode<T> * GetFirst() ;
	/**
	 * \brief Returns the last node in the list (NULL if the list is empty). 
	*/

  wxNode<T> * GetLast() ;
	/**
	 * \brief Returns the index of   within the list or wxNOT_FOUND if   
is not found in the list. 
	 * \param T*  
	*/

  int IndexOf(T*  obj  ) ;
	/**
	 * \brief Insert object at front of list. 
	 * \param T *  
	*/

  wxNode<T> * Insert(T * object ) ;
	/**
	 * \brief Insert object before  , i.e. the index of the new item in the
list will be equal to  .   should be less than or
equal to  ; if it is equal to it, this is the
same as calling  . 
	 * \param size_t   
	 * \param T *  
	*/

  wxNode<T> * Insert(size_t  position , T * object ) ;
	/**
	 * \brief Inserts the object before the given  . 
	 * \param wxNode<T> *  
	 * \param T *  
	*/

  wxNode<T> * Insert(wxNode<T> * node , T * object ) ;
	/**
	 * \brief Returns   if the list is empty,   otherwise. 
	*/

  bool IsEmpty() const;
	/**
	 * \brief Returns the node at given position in the list. 
	 * \param size_t   
	*/

  wxNode<T> * Item(size_t  index ) const;
	/**
	 * \brief This function is deprecated, use   instead.

Returns the node associated with   if it is in the list, NULL otherwise. 
	 * \param T *  
	*/

  wxNode<T> * Member(T * object ) ;
	/**
	 * \brief This function is deprecated, use   instead.

Returns the   node in the list, indexing from zero (NULL if the list is empty
or the nth node could not be found). 
	 * \param int  
	*/

  wxNode<T> * Nth(int  n ) ;
	/**
	 * \brief This function is deprecated, use   instead.

Returns the number of elements in the list. 
	*/

  int Number() ;
	/**
	 * \brief Allows the sorting of arbitrary lists by giving
a function to compare two list elements. We use the system   function
for the actual sorting process.

If you use untyped wxList the sort function receives pointers to wxObject
pointers (wxObject &#42;&#42;), so be careful to dereference appropriately - but,
of course, a better solution is to use list of appropriate type defined with
 .

Example: 
	 * \param wxSortCompareFunction  
	*/

  void Sort(wxSortCompareFunction  compfunc ) ;
};


#endif
