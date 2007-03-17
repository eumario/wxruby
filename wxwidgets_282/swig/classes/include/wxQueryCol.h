// wxQueryCol.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxQueryCol_h_)
#define _wxQueryCol_h_
class wxQueryCol : public wxObject
{
public:
	/**
	 * \brief Constructor. Sets the attributes of the column to default values. 
	*/

   wxQueryCol() ;
	/**
	 * \brief Destructor. Deletes the wxQueryField list. 
	*/

  virtual  ~wxQueryCol() ;
	/**
	 * \brief Binds a user-defined variable to a column. Whenever a column is bound to a
variable, it will automatically copy the data of the current field into this
buffer (to a maximum of   bytes). 
	 * \param void *  
	 * \param long  
	*/

  void * BindVar(void * v , long  sz ) ;
	/**
	 * \brief Fills the bound variable with the data of the field recnum. When no variable
is bound to the column nothing will happen. 
	 * \param int  
	*/

  void FillVar(int  recnum ) ;
	/**
	 * \brief Returns a pointer to the data of the field. 
	 * \param int  
	*/

  void * GetData(int  field ) ;
	/**
	 * \brief Returns the name of a column. 
	*/

  wxString GetName() ;
	/**
	 * \brief Returns the data type of a column. 
	*/

  short GetType() ;
	/**
	 * \brief Return the size of the data of the field field. 
	 * \param int  
	*/

  long GetSize(int  field ) ;
	/**
	 * \brief Returns true if the given field has been changed, but not saved. 
	 * \param int  
	*/

  bool IsRowDirty(int  field ) ;
	/**
	 * \brief Returns true if a column may contain no data. 
	*/

  bool IsNullable() ;
	/**
	 * \brief Appends a wxQueryField instance to the field list of the column.   bytes from
  will be copied into the field's buffer. 
	 * \param void *  
	 * \param long  
	*/

  void AppendField(void * buf , long  len ) ;
	/**
	 * \brief Sets the data of a field. This function finds the wxQueryField corresponding to
  and calls wxQueryField::SetData with   and   arguments. 
	 * \param int  
	 * \param void *  
	 * \param long  
	*/

  bool SetData(int  field , void * buf , long  len ) ;
	/**
	 * \brief Sets the name of a column. Only useful when creating new tables or
appending columns. 
	 * \param const wxString&   
	*/

  void SetName(const wxString&  name ) ;
	/**
	 * \brief Determines whether a column may contain no data. Only useful when creating new tables or
appending columns. 
	 * \param bool  
	*/

  void SetNullable(bool  nullable ) ;
	/**
	 * \brief Sets the dirty tag of a given field. 
	 * \param int  
	 * \param bool   
	*/

  void SetFieldDirty(int  field , bool  dirty = true) ;
	/**
	 * \brief Sets the data type of a column. Only useful when creating new tables or
appending columns. 
	 * \param short  
	*/

  void SetType(short  type ) ;
};


#endif
