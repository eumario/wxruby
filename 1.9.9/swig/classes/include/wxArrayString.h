// wxArrayString.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxArrayString_h_)
#define _wxArrayString_h_
class wxArrayString
{
public:
	/**
	 * \brief  
	*/

   wxArrayString() ;
	/**
	 * \brief Default and copy constructors.

Note that when an array is assigned to a sorted array, its contents is
automatically sorted during construction. 
	 * \param const wxArrayString&  
	*/

   wxArrayString(const wxArrayString&  array ) ;
	/**
	 * \brief Destructor frees memory occupied by the array strings. For the performance
reasons it is not virtual, so this class should not be derived from. 
	*/

  virtual  ~wxArrayString() ;
	/**
	 * \brief Appends the given number of   of the new item   to the
array and returns the index of the first new item in the array.

  For sorted arrays, the index of the inserted item will not be,
in general, equal to   - 1 because
the item is inserted at the correct position to keep the array sorted and not
appended.

See also: 
	 * \param const wxString&   
	 * \param size_t  
	*/

  size_t Add(const wxString&  str , size_t copies = 1) ;
	/**
	 * \brief Preallocates enough memory to store   items. This function may be
used to improve array class performance before adding a known number of items
consecutively.

See also: 
	 * \param size_t   
	*/

  void Alloc(size_t  nCount ) ;
	/**
	 * \brief Clears the array contents and frees memory.

See also: 
	*/

  void Clear() ;
	/**
	 * \brief Returns the number of items in the array. This function is deprecated and is
for backwards compatibility only, please use 
  instead. 
	*/

  size_t Count() const;
	/**
	 * \brief Empties the array: after a call to this function 
  will return 0. However, this
function does not free the memory used by the array and so should be used when
the array is going to be reused for storing other strings. Otherwise, you
should use   to empty the array and free
memory. 
	*/

  void Empty() ;
	/**
	 * \brief Returns the number of items in the array. 
	*/

  size_t GetCount() const;
	/**
	 * \brief Search the element in the array, starting from the beginning if
  is false or from end otherwise. If  , comparison is
case sensitive (default), otherwise the case is ignored.

This function uses linear search for wxArrayString and binary search for
wxSortedArrayString, but it ignores the   and   
parameters in the latter case.

Returns index of the first item matched or wxNOT_FOUND if there is no match. 
	 * \param const char *  
	 * \param bool  
	 * \param bool  
	*/

  int Index(const char *  sz , bool bCase = true, bool bFromEnd = false) ;
	/**
	 * \brief Insert the given number of   of the new element in the array before the position  . Thus, for
example, to insert the string in the beginning of the array you would write

 

If   is equal to   this function behaves as 
 .

  this function should not be used with sorted arrays because it
could break the order of items and, for example, subsequent calls to 
  would then not work! 
	 * \param const wxString&   
	 * \param size_t  
	 * \param size_t   
	*/

  void Insert(const wxString&  str , size_t  nIndex , size_t  copies = 1) ;
	/**
	 * \brief Returns true if the array is empty, false otherwise. This function returns the
same result as   but is probably easier to read. 
	*/

   IsEmpty() ;
	/**
	 * \brief Return the array element at position  . An assert failure will
result from an attempt to access an element beyond the end of array in debug
mode, but no check is done in release mode.

See also   for the operator
version. 
	 * \param size_t   
	*/

  wxString& Item(size_t  nIndex ) const;
	/**
	 * \brief Returns the last element of the array. Attempt to access the last element of
an empty array will result in assert failure in debug build, however no checks
are done in release mode. 
	*/

   Last() ;
	/**
	 * \brief Removes the first item matching this value. An assert failure is provoked by
an attempt to remove an element which does not exist in debug build.

See also: 
	 * \param const char *  
	*/

  void Remove(const char *  sz ) ;
	/**
	 * \brief Removes   items starting at position   from the array. 
	 * \param size_t   
	 * \param size_t   
	*/

  void Remove(size_t  nIndex , size_t  count = 1) ;
	/**
	 * \brief Releases the extra memory allocated by the array. This function is useful to
minimize the array memory consumption.

See also:  , 
	*/

  void Shrink() ;
	/**
	 * \brief Sorts the array in alphabetical order or in reverse alphabetical order if 
  is true. The sort is case-sensitive.

  this function should not be used with sorted array because it
could break the order of items and, for example, subsequent calls to 
  would then not work! 
	 * \param bool  
	*/

  void Sort(bool reverseOrder = false) ;
	/**
	 * \brief Sorts the array using the specified   for item comparison.
  is defined as a function taking two   parameters and returning an   value less than, equal to or
greater than 0 if the first string is less than, equal to or greater than the
second one. 
	 * \param CompareFunction   
	*/

  void Sort(CompareFunction  compareFunction ) ;
};


#endif
