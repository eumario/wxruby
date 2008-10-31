// wxArray.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxArray_h_)
#define _wxArray_h_
class wxArray
{
public:
	/**
	 * \brief  
	*/

  virtual  ~wxArray() ;
	/**
	 * \brief  
	*/

  virtual  ~wxArray() ;
	/**
	 * \brief The wxObjArray destructor deletes all the items owned by the array. This is not
done by wxArray and wxSortedArray versions - you may use 
  macro for this. 
	*/

  virtual  ~wxArray() ;
	/**
	 * \brief  
	 * \param T   
	 * \param size_t  
	*/

  void Add(T  item , size_t copies = 1) ;
	/**
	 * \brief  
	 * \param T *  
	*/

  void Add(T * item ) ;
	/**
	 * \brief Appends the given number of   of the   to the array
consisting of the elements of type  .

The first version is used with wxArray and wxSortedArray. The second and the
third are used with wxObjArray. There is an important difference between
them: if you give a pointer to the array, it will take ownership of it, i.e.
will delete it when the item is deleted from the array. If you give a reference
to the array, however, the array will make a copy of the item and will not take
ownership of the original item. Once again, it only makes sense for wxObjArrays
because the other array types never take ownership of their elements. Also note
that you cannot append more than one pointer as reusing it would lead to
deleting it twice (or more) and hence to a crash.

You may also use   macro to append all
elements of one array to another one but it is more efficient to use 
  parameter and modify the elements in place later if you plan to
append a lot of items. 
	 * \param T &  
	 * \param size_t  
	*/

  void Add(T & item , size_t copies = 1) ;
	/**
	 * \brief Preallocates memory for a given number of array elements. It is worth calling
when the number of items which are going to be added to the array is known in
advance because it will save unneeded memory reallocation. If the array already
has enough memory for the given number of items, nothing happens. 
	 * \param size_t   
	*/

  void Alloc(size_t  count ) ;
	/**
	 * \brief This function does the same as   and additionally
frees the memory allocated to the array. 
	*/

  void Clear() ;
	/**
	 * \brief Same as  . This function is deprecated -
it exists only for compatibility. 
	*/

  size_t Count() const;
	/**
	 * \brief Removes the element from the array, but, unlike, 
  doesn't delete it. The function returns the
pointer to the removed element. 
	 * \param size_t   
	*/

  T * Detach(size_t  index ) ;
	/**
	 * \brief Empties the array. For wxObjArray classes, this destroys all of the array
elements. For wxArray and wxSortedArray this does nothing except marking the
array of being empty - this function does not free the allocated memory, use 
  for this. 
	*/

  void Empty() ;
	/**
	 * \brief Return the number of items in the array. 
	*/

  size_t GetCount() const;
	/**
	 * \brief  
	 * \param T&   
	 * \param bool   
	*/

  int Index(T&  item , bool  searchFromEnd = false) ;
	/**
	 * \brief The first version of the function is for wxArray and wxObjArray, the second is
for wxSortedArray only.

Searches the element in the array, starting from either beginning or the end
depending on the value of   parameter. wxNOT_FOUND is
returned if the element is not found, otherwise the index of the element is
returned.

Linear search is used for the wxArray and wxObjArray classes but binary search
in the sorted array is used for wxSortedArray (this is why searchFromEnd
parameter doesn't make sense for it).

  even for wxObjArray classes, the operator==() of the elements in the
array is   used by this function. It searches exactly the given
element in the array and so will only succeed if this element had been
previously added to the array, but fail even if another, identical, element is
in the array. 
	 * \param T&   
	*/

  int Index(T&  item ) ;
	/**
	 * \brief  
	 * \param T   
	 * \param size_t   
	 * \param size_t   
	*/

  void Insert(T  item , size_t  n , size_t  copies = 1) ;
	/**
	 * \brief  
	 * \param T *  
	 * \param size_t   
	*/

  void Insert(T * item , size_t  n ) ;
	/**
	 * \brief Insert the given number of   of the   into the array before
the existing item   - thus,   will insert an
item in such way that it will become the first array element.

Please see   for explanation of the differences
between the overloaded versions of this function. 
	 * \param T &  
	 * \param size_t   
	 * \param size_t   
	*/

  void Insert(T & item , size_t  n , size_t  copies = 1) ;
	/**
	 * \brief Returns true if the array is empty, false otherwise. 
	*/

  bool IsEmpty() const;
	/**
	 * \brief Returns the item at the given position in the array. If   is out of
bounds, an assert failure is raised in the debug builds but nothing special is
done in the release build.

The returned value is of type &quot;reference to the array element type&quot; for all of
the array classes. 
	 * \param size_t   
	*/

  T& Item(size_t  index ) const;
	/**
	 * \brief Returns the last element in the array, i.e. is the same as Item(GetCount() - 1).
An assert failure is raised in the debug mode if the array is empty.

The returned value is of type &quot;reference to the array element type&quot; for all of
the array classes. 
	*/

  T& Last() const;
	/**
	 * \brief Removes an element from the array by value: the first item of the
array equal to   is removed, an assert failure will result from an
attempt to remove an item which doesn't exist in the array.

When an element is removed from wxObjArray it is deleted by the array - use 
  if you don't want this to happen. On the
other hand, when an object is removed from a wxArray nothing happens - you
should delete it manually if required:

 

See also   macro which deletes all
elements of a wxArray (supposed to contain pointers). 
	 * \param T   
	*/

  void Remove(T  item ) ;
	/**
	 * \brief Removes   elements starting at   from the array. When an
element is removed from wxObjArray it is deleted by the array - use
  if you don't want this to happen. On
the other hand, when an object is removed from a wxArray nothing happens -
you should delete it manually if required:

 

See also   macro which deletes all
elements of a wxArray (supposed to contain pointers). 
	 * \param size_t   
	 * \param size_t   
	*/

  void RemoveAt(size_t  index , size_t  count = 1) ;
	/**
	 * \brief This function ensures that the number of array elements is at least 
 . If the array has already   or mroe items, nothing is
done. Otherwise,   elements are added and initialized to
the value  . 
	 * \param size_t   
	 * \param T   
	*/

  void SetCount(size_t  count , T  defval = T(0)) ;
	/**
	 * \brief Frees all memory unused by the array. If the program knows that no new items
will be added to the array it may call Shrink() to reduce its memory usage.
However, if a new item is added to the array, some extra memory will be
allocated again. 
	*/

  void Shrink() ;
	/**
	 * \brief The notation CMPFUNC&lt;T&gt; should be read as if we had the following declaration:

 

where   is the type of the array elements. I.e. it is a function returning 
  which is passed two arguments of type  .

Sorts the array using the specified compare function: this function should
return a negative, zero or positive value according to whether the first element
passed to it is less than, equal to or greater than the second one.

wxSortedArray doesn't have this function because it is always sorted. 
	 * \param CMPFUNC<T>   
	*/

  void Sort(CMPFUNC<T>  compareFunction ) ;
};


#endif
