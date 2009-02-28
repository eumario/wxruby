// wxExprDatabase.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxExprDatabase_h_)
#define _wxExprDatabase_h_
class wxExprDatabase : public wxList
{
public:
	/**
	 * \brief Construct a new, unhashed database, with an optional error handler. The
error handler must be a function returning a bool and taking an integer and a string
argument. When an error occurs when reading or writing a database, this function is
called. The error is given as the first argument (currently one of WXEXPR_ERROR_GENERAL,
WXEXPR_ERROR_SYNTAX) and an error message is given as the second argument. If false
is returned by the error handler, processing of the wxExpr operation stops.

Another way of handling errors is simply to call   after
the operation, to check whether errors have occurred, instead of installing an error handler.
If the error count is more than zero,   and
  will return false to
the application.

For example: 
	 * \param proioErrorHandler  
	*/

   wxExprDatabase(proioErrorHandler handler = 0) ;
	/**
	 * \brief Construct a new database hashed on a combination of the clause functor and
a named attribute (often an integer identification).

See above for an explanation of the error handler. 
	 * \param wxExprType  
	 * \param const wxString&  
	 * \param int  
	 * \param proioErrorHandler  
	*/

   wxExprDatabase(wxExprType  type , const wxString& attribute , int size = 500, proioErrorHandler handler = 0) ;
	/**
	 * \brief Delete the database and contents. 
	*/

  virtual  ~wxExprDatabase() ;
	/**
	 * \brief Append a clause to the end of the database. If the database is hashing,
the functor and a user-specified attribute will be hashed upon, giving the
option of random access in addition to linear traversal of the database. 
	 * \param wxExpr*   
	*/

  void Append(wxExpr*  clause ) ;
	/**
	 * \brief Reset the current position to the start of the database. Subsequent
  calls will move the pointer. 
	*/

  void BeginFind() ;
	/**
	 * \brief Clears the contents of the database. 
	*/

  void ClearDatabase() ;
	/**
	 * \brief Find a clause based on the special ``id'' attribute. 
	 * \param long  
	*/

  wxExpr*  FindClause(long  id ) ;
	/**
	 * \brief Find a clause which has the given attribute set to the given string or word value. 
	 * \param const wxString&  
	 * \param const wxString&  
	*/

  wxExpr*  FindClause(const wxString&  attribute , const wxString&  value ) ;
	/**
	 * \brief Find a clause which has the given attribute set to the given integer value. 
	 * \param const wxString&  
	 * \param long  
	*/

  wxExpr* FindClause(const wxString&  attribute , long  value ) ;
	/**
	 * \brief Find a clause which has the given attribute set to the given floating point value. 
	 * \param const wxString&  
	 * \param float  
	*/

  wxExpr* FindClause(const wxString&  attribute , float  value ) ;
	/**
	 * \brief Find the next clause with the specified functor. 
	 * \param const wxString&  
	*/

  wxExpr* FindClauseByFunctor(const wxString&  functor ) ;
	/**
	 * \brief Returns the number of errors encountered during the last read or write operation. 
	*/

  int GetErrorCount() const;
	/**
	 * \brief Finds the clause with the given functor and with the attribute specified
in the database constructor having the given integer value.

For example,

 

This would retrieve a clause which is written:  . 
	 * \param const wxString&  
	 * \param long  
	*/

  wxExpr* HashFind(const wxString&  functor , long  value ) const;
	/**
	 * \brief Finds the clause with the given functor and with the attribute specified
in the database constructor having the given string value. 
	 * \param const wxString&  
	 * \param const wxString&  
	*/

  wxExpr* HashFind(const wxString&  functor , const wxString&  value ) ;
	/**
	 * \brief Reads in the given file, returning true if successful. 
	 * \param const wxString&  
	*/

  bool Read(const wxString&  filename ) ;
	/**
	 * \brief Reads a Prolog database from the given string buffer, returning true if
successful. 
	 * \param const wxString&  
	*/

  bool ReadFromString(const wxString&  buffer ) ;
	/**
	 * \brief  
	 * \param FILE *  
	*/

  bool Write(FILE * stream ) ;
	/**
	 * \brief Writes the database as a Prolog-format file. 
	 * \param const wxString&  
	*/

  bool Write(const wxString&  filename ) ;
};


#endif
