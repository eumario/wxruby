// wxQueryField.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxQueryField_h_)
#define _wxQueryField_h_
class wxQueryField : public wxObject
{
public:
	/**
	 * \brief Constructor. Sets type and size of the field to default values. 
	*/

   wxQueryField() ;
	/**
	 * \brief Destructor. Frees the associated memory depending on the field type. 
	*/

  virtual  ~wxQueryField() ;
	/**
	 * \brief Allocates memory depending on the size and type of the field. 
	*/

  bool AllocData() ;
	/**
	 * \brief Deletes the contents of the field buffer without deallocating the memory. 
	*/

  void ClearData() ;
	/**
	 * \brief Returns a pointer to the field buffer. 
	*/

  void * GetData() ;
	/**
	 * \brief Returns the size of the field buffer. 
	*/

  long GetSize() ;
	/**
	 * \brief Returns the type of the field (currently SQL_CHAR, SQL_VARCHAR or SQL_INTEGER). 
	*/

  short GetType() ;
	/**
	 * \brief Returns true if the data of a field has been changed, but not saved. 
	*/

  bool IsDirty() ;
	/**
	 * \brief Allocates memory of the size   and copies the contents of   into the
field buffer. 
	 * \param void *  
	 * \param long  
	*/

  bool SetData(void * data , long  sz ) ;
	/**
	 * \brief Sets the dirty tag of a field. 
	 * \param bool  
	*/

  void SetDirty(bool dirty = true) ;
	/**
	 * \brief Resizes the field buffer. Stored data will be lost. 
	 * \param long  
	*/

  void SetSize(long  size ) ;
	/**
	 * \brief Sets the type of the field. Currently the types SQL_CHAR, SQL_VARCHAR and
SQL_INTEGER are supported. 
	 * \param short   
	*/

  void SetType(short  type ) ;
};


#endif
