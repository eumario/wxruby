// wxStringList.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxStringList_h_)
#define _wxStringList_h_
class wxStringList : public wxList
{
public:
	/**
	 * \brief Constructor. 
	*/

   wxStringList() ;
	/**
	 * \brief Constructor, taking NULL-terminated string argument list. wxStringList
allocates memory for the strings. 
	 * \param char*   
	*/

   wxStringList(char*  first ) ;
	/**
	 * \brief Deletes string list, deallocating strings. 
	*/

  virtual  ~wxStringList() ;
	/**
	 * \brief Adds string to list, allocating memory. 
	 * \param const wxString&   
	*/

  wxNode * Add(const wxString&  s ) ;
	/**
	 * \brief Clears all strings from the list. 
	*/

  void Clear() ;
	/**
	 * \brief Searches for string and deletes from list, deallocating memory. 
	 * \param const wxString&   
	*/

  void Delete(const wxString&  s ) ;
	/**
	 * \brief Converts the list to an array of strings, only allocating new memory if
  is true. 
	 * \param bool  
	*/

  char* ListToArray(bool new_copies = false) ;
	/**
	 * \brief Returns true if   is a member of the list (tested using  ). 
	 * \param const wxString&   
	*/

  bool Member(const wxString&  s ) ;
	/**
	 * \brief Sorts the strings in ascending alphabetical order. Note that all nodes
(but not strings) get deallocated and new ones allocated. 
	*/

  void Sort() ;
};


#endif
