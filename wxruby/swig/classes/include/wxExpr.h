// wxExpr.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxExpr_h_)
#define _wxExpr_h_
class wxExpr
{
public:
	/**
	 * \brief Construct a new clause with this form, supplying the functor name. A clause is an object
that will appear in the data file, with a list of attribute/value pairs. 
	 * \param const wxString&  
	*/

   wxExpr(const wxString& functor ) ;
	/**
	 * \brief Construct a new empty list, or a word (will be output with no quotes), or a string, depending on the
value of  .

  can be  ,  , or  . If   is wxExprList,
the value of   will be ignored. 
	 * \param wxExprType  
	 * \param const wxString&  
	*/

   wxExpr(wxExprType  type , const wxString& wordOrString = wxT("")) ;
	/**
	 * \brief Construct an integer expression. 
	 * \param long  
	*/

   wxExpr(long  value ) ;
	/**
	 * \brief Construct a floating point expression. 
	 * \param float  
	*/

   wxExpr(float  value ) ;
	/**
	 * \brief Construct a list expression. The list's nodes' data should
themselves be  s.

wxExpr no longer uses the   internally,
so this constructor turns the list into its internal
format (assuming a non-nested list) and then deletes the supplied
list. 
	 * \param wxList*   
	*/

   wxExpr(wxList*  value ) ;
	/**
	 * \brief Destructor. 
	*/

  virtual  ~wxExpr() ;
	/**
	 * \brief Adds an attribute and floating point value pair to the clause. 
	 * \param const wxString&  
	 * \param float   
	*/

  void AddAttributeValue(const wxString&  attribute , float  value ) ;
	/**
	 * \brief Adds an attribute and long integer value pair to the clause. 
	 * \param const wxString&  
	 * \param long   
	*/

  void AddAttributeValue(const wxString&  attribute , long  value ) ;
	/**
	 * \brief Adds an attribute and list value pair to the clause, converting the list into
internal form and then deleting  . Note that the list should not contain
nested lists (except if in internal   form.) 
	 * \param const wxString&  
	 * \param wxList*   
	*/

  void AddAttributeValue(const wxString&  attribute , wxList*  value ) ;
	/**
	 * \brief Adds an attribute and wxExpr value pair to the clause. Do not delete
  once this function has been called. 
	 * \param const wxString&  
	 * \param wxExpr*   
	*/

  void AddAttributeValue(const wxString&  attribute , wxExpr*  value ) ;
	/**
	 * \brief Adds an attribute and string value pair to the clause. 
	 * \param const wxString&  
	 * \param const wxString&  
	*/

  void AddAttributeValueString(const wxString&  attribute , const wxString&  value ) ;
	/**
	 * \brief Adds an attribute and string list value pair to the clause.

Note that the list passed to this function is a list of strings, NOT a list
of  s; it gets turned into a list of  s
automatically. This is a convenience function, since lists of strings
are often manipulated in C++. 
	 * \param const wxString&  
	 * \param wxList*   
	*/

  void AddAttributeValueStringList(const wxString&  attribute , wxList*  value ) ;
	/**
	 * \brief Adds an attribute and word value pair to the clause. 
	 * \param const wxString&  
	 * \param const wxString&  
	*/

  void AddAttributeValueWord(const wxString&  attribute , const wxString&  value ) ;
	/**
	 * \brief Append the   to the end of the list. `this' must be a list. 
	 * \param wxExpr*  
	*/

  void Append(wxExpr*  value ) ;
	/**
	 * \brief Get nth arg of the given clause (starting from 1). NULL is returned if
the expression is not a clause, or   is invalid, or the given type
does not match the actual type. See also  . 
	 * \param wxExprType  
	 * \param int  
	*/

  wxExpr*  Arg(wxExprType  type , int  n ) const;
	/**
	 * \brief Insert the   at the start of the list. `this' must be a list. 
	 * \param wxExpr*   
	*/

  void Insert(wxExpr*  value ) ;
	/**
	 * \brief Retrieve a string (or word) value. 
	 * \param const wxString&  
	 * \param wxString&  
	*/

  bool GetAttributeValue(const wxString&  attribute , wxString&  value ) const;
	/**
	 * \brief Retrieve a floating point value. 
	 * \param const wxString&  
	 * \param float&   
	*/

  bool GetAttributeValue(const wxString&  attribute , float&  value ) const;
	/**
	 * \brief Retrieve an integer value. 
	 * \param const wxString&  
	 * \param int&   
	*/

  bool GetAttributeValue(const wxString&  attribute , int&  value ) const;
	/**
	 * \brief Retrieve a long integer value. 
	 * \param const wxString&  
	 * \param long&   
	*/

  bool GetAttributeValue(const wxString&  attribute , long&  value ) const;
	/**
	 * \brief Retrieve a wxExpr pointer. 
	 * \param const wxString&  
	 * \param wxExpr**  
	*/

  bool GetAttributeValue(const wxString&  attribute , wxExpr**  value ) const;
	/**
	 * \brief Use this on clauses ONLY. See above for comments on this style of
attribute value retrieval. This function expects to receive a pointer to
a new list (created by the calling application); it will append strings
to the list if the attribute is present in the clause. 
	 * \param const wxString&  
	 * \param wxList*   
	*/

  void GetAttributeValueStringList(const wxString& attribute , wxList*  value ) const;
	/**
	 * \brief Use this on clauses ONLY. Searches the clause for an attribute
matching  , and returns the value associated with it. 
	 * \param const wxString&  
	*/

  wxExpr* AttributeValue(const wxString&  word ) const;
	/**
	 * \brief Recursively copies the expression, allocating new storage space. 
	*/

  wxExpr* Copy() const;
	/**
	 * \brief Use this on clauses only. Deletes the attribute and its value (if any) from the
clause. 
	 * \param const wxString&  
	*/

  void DeleteAttributeValue(const wxString&  attribute ) ;
	/**
	 * \brief Use this on clauses only. Returns the clause's functor (object name). 
	*/

  wxString Functor() const;
	/**
	 * \brief Retrieve arbitrary data stored with this clause. This can be useful when
reading in data for storing a pointer to the C++ object, so when another
clause makes a reference to this clause, its C++ object can be retrieved.
See  . 
	*/

  wxObject* GetClientData() const;
	/**
	 * \brief If this is a list expression (or clause), gets the first element in the list.

See also  ,  ,  . 
	*/

  wxExpr* GetFirst() const;
	/**
	 * \brief If this is a list expression (or clause), gets the last element in the list.

See also  ,  ,  . 
	*/

  wxExpr* GetLast() const;
	/**
	 * \brief If this is a node in a list (any wxExpr may be a node in a list), gets the
next element in the list.

See also  ,  ,  . 
	*/

  wxExpr* GetNext() const;
	/**
	 * \brief Returns the integer value of the expression. 
	*/

  long IntegerValue() const;
	/**
	 * \brief Get nth arg of the given list expression (starting from 0). NULL is returned if
the expression is not a list expression, or   is invalid. See also  .

Normally, you would use attribute-value pairs to add and retrieve data
from objects (clauses) in a data file. However, if the data gets complex,
you may need to store attribute values as lists, and pick them apart
yourself. 
	 * \param int  
	*/

  wxExpr* Nth(int  n ) const;
	/**
	 * \brief Returns the floating point value of the expression. 
	*/

  float RealValue() const;
	/**
	 * \brief Associate arbitrary data with this clause. This can be useful when
reading in data for storing a pointer to the C++ object, so when another
clause makes a reference to this clause, its C++ object can be retrieved.
See  . 
	 * \param wxObject *  
	*/

  void SetClientData(wxObject * data ) ;
	/**
	 * \brief Returns the string value of the expression. 
	*/

  wxString StringValue() const;
	/**
	 * \brief Returns the type of the expression.   is defined as follows: 
	*/

  wxExprType Type() const;
	/**
	 * \brief Returns the word value of the expression. 
	*/

  wxString WordValue() const;
	/**
	 * \brief Writes the clause to the given stream in Prolog format. Not normally needed, since
the whole   will usually be written at once. The format is:
functor, open parenthesis, list of comma-separated expressions, close parenthesis,
full stop. 
	 * \param FILE *  
	*/

  void WriteClause(FILE *  stream ) ;
	/**
	 * \brief Writes the expression (not clause) to the given stream in Prolog
format. Not normally needed, since the whole   will
usually be written at once. Lists are written in square bracketed,
comma-delimited format. 
	 * \param FILE *  
	*/

  void WriteExpr(FILE *  stream ) ;
};


#endif
