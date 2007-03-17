// wxHashTable.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxHashTable_h_)
#define _wxHashTable_h_
class wxHashTable : public wxObject
{
public:
	/**
	 * \brief Constructor.   is one of wxKEY_INTEGER, or wxKEY_STRING,
and indicates what sort of keying is required.   is optional. 
	 * \param unsigned int  
	 * \param int  
	*/

   wxHashTable(unsigned int  key_type , int size = 1000) ;
	/**
	 * \brief Destroys the hash table. 
	*/

  virtual  ~wxHashTable() ;
	/**
	 * \brief The counterpart of  .  If the application wishes to iterate
through all the data in the hash table, it can call   and
then loop on  . 
	*/

  void BeginFind() ;
	/**
	 * \brief Clears the hash table of all nodes (but as usual, doesn't delete user data). 
	*/

  void Clear() ;
	/**
	 * \brief  
	 * \param long  
	*/

  wxObject * Delete(long  key ) ;
	/**
	 * \brief Deletes entry in hash table and returns the user's data (if found). 
	 * \param const wxString&   
	*/

  wxObject * Delete(const wxString&   key ) ;
	/**
	 * \brief If set to true data stored in hash table will be deleted when hash table object
is destroyed. 
	 * \param bool  
	*/

  void DeleteContents(bool  flag ) ;
	/**
	 * \brief  
	 * \param long  
	*/

  wxObject * Get(long  key ) ;
	/**
	 * \brief Gets data from the hash table, using an integer or string key (depending on which
has table constructor was used). 
	 * \param const char*  
	*/

  wxObject * Get(const char*  key ) ;
	/**
	 * \brief Makes an integer key out of a string. An application may wish to make a key
explicitly (for instance when combining two data values to form a key). 
	 * \param const wxString&   
	*/

  long MakeKey(const wxString&  string ) ;
	/**
	 * \brief If the application wishes to iterate through all the data in the hash
table, it can call   and then loop on  . This function
returns a   pointer (or NULL if there are no more nodes).  See the
description for  . The user will probably only wish to use the
  function to retrieve the data; the node may also be deleted. 
	*/

  wxNode * Next() ;
	/**
	 * \brief  
	 * \param long  
	 * \param wxObject *  
	*/

  void Put(long  key , wxObject * object ) ;
	/**
	 * \brief Inserts data into the hash table, using an integer or string key (depending on which
has table constructor was used). The key string is copied and stored by the hash
table implementation. 
	 * \param const char*  
	 * \param wxObject *  
	*/

  void Put(const char*  key , wxObject * object ) ;
	/**
	 * \brief Returns the number of elements in the hash table. 
	*/

  size_t GetCount() const;
};


#endif
