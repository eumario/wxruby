// wxHashMap.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxHashMap_h_)
#define _wxHashMap_h_
class wxHashMap
{
public:
	/**
	 * \brief The size parameter is just an hint, the table will resize automatically
to preserve performance. 
	 * \param size_type  
	*/

   wxHashMap(size_type size = 10) ;
	/**
	 * \brief Copy constructor. 
	 * \param const wxHashMap&  
	*/

   wxHashMap(const wxHashMap&  map ) ;
	/**
	 * \brief  
	*/

  const_iterator begin() const;
	/**
	 * \brief Returns an iterator pointing at the first element of the hash map.
Please remember that hash maps do not guarantee ordering. 
	*/

  iterator begin() ;
	/**
	 * \brief Removes all elements from the hash map. 
	*/

  void clear() ;
	/**
	 * \brief Counts the number of elements with the given key present in the map.
This function can actually return 0 or 1. 
	 * \param const key_type&  
	*/

  size_type count(const key_type&  key ) const;
	/**
	 * \brief Returns true if the hash map does not contain any element, false otherwise. 
	*/

  bool empty() const;
	/**
	 * \brief  
	*/

  const_iterator end() const;
	/**
	 * \brief Returns an iterator pointing at the one-after-the-last element of the hash map.
Please remember that hash maps do not guarantee ordering. 
	*/

  iterator end() ;
	/**
	 * \brief Erases the element with the given key, and returns the number of element
erased (either 0 or 1). 
	 * \param const key_type&  
	*/

  size_type erase(const key_type&  key ) ;
	/**
	 * \brief  
	 * \param iterator  
	*/

  void erase(iterator  it ) ;
	/**
	 * \brief Erases the element pointed to by the iterator. After the deletion
the iterator is no longer valid and must not be used. 
	 * \param const_iterator  
	*/

  void erase(const_iterator  it ) ;
	/**
	 * \brief  
	 * \param const key_type&  
	*/

  iterator find(const key_type&  key ) ;
	/**
	 * \brief If an element with the given key is present, the functions returns
an iterator pointing at that element, otherwise an invalid iterator
is returned (i.e. hashmap.find( non_existent_key ) == hashmap.end()). 
	 * \param const key_type&  
	*/

  const_iterator find(const key_type&  key ) const;
	/**
	 * \brief Inserts the given value in the hash map. 
	 * \param const value_type&  
	*/

  void insert(const value_type&  v ) ;
	/**
	 * \brief Returns the numbers of elements in the map. 
	*/

  size_type size() const;
};


#endif
