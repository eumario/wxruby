// wxVariant.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxVariant_h_)
#define _wxVariant_h_
class wxVariant : public wxObject
{
public:
	/**
	 * \brief Default constructor. 
	*/

   wxVariant() ;
	/**
	 * \brief Copy constructor. 
	 * \param const wxVariant&   
	*/

   wxVariant(const wxVariant&  variant ) ;
	/**
	 * \brief  
	 * \param const char*  
	 * \param const wxString&   
	*/

   wxVariant(const char*  value , const wxString&  name = wxT("")) ;
	/**
	 * \brief Construction from a string value. 
	 * \param const wxString&  
	 * \param const wxString&   
	*/

   wxVariant(const wxString&  value , const wxString&  name = wxT("")) ;
	/**
	 * \brief Construction from a character value. 
	 * \param char  
	 * \param const wxString&   
	*/

   wxVariant(char  value , const wxString&  name = wxT("")) ;
	/**
	 * \brief Construction from an integer value. You may need to cast to (long) to
avoid confusion with other constructors (such as the bool constructor). 
	 * \param long  
	 * \param const wxString&   
	*/

   wxVariant(long  value , const wxString&  name = wxT("")) ;
	/**
	 * \brief Construction from a boolean value. 
	 * \param bool  
	 * \param const wxString&   
	*/

   wxVariant(bool  value , const wxString&  name = wxT("")) ;
	/**
	 * \brief Construction from a double-precision floating point value. 
	 * \param double  
	 * \param const wxString&   
	*/

   wxVariant(double  value , const wxString&  name = wxT("")) ;
	/**
	 * \brief Construction from a list of wxVariant objects. This constructor
copies  , the application is still responsible for
deleting   and its contents. 
	 * \param const wxList&  
	 * \param const wxString&   
	*/

   wxVariant(const wxList&  value , const wxString&  name = wxT("")) ;
	/**
	 * \brief Construction from a list of strings. This constructor
copies  , the application is still responsible for
deleting   and its contents. 
	 * \param const wxStringList&  
	 * \param const wxString&   
	*/

   wxVariant(const wxStringList&  value , const wxString&  name = wxT("")) ;
	/**
	 * \brief Construction from a void pointer. 
	 * \param void*  
	 * \param const wxString&   
	*/

   wxVariant(void*  value , const wxString&  name = wxT("")) ;
	/**
	 * \brief Construction from a wxObject pointer. 
	 * \param wxObject*  
	 * \param const wxString&   
	*/

   wxVariant(wxObject*  value , const wxString&  name = wxT("")) ;
	/**
	 * \brief Construction from user-defined data. The variant holds on to the   pointer. 
	 * \param wxVariantData*  
	 * \param const wxString&   
	*/

   wxVariant(wxVariantData*  data , const wxString&  name = wxT("")) ;
	/**
	 * \brief Destructor. 
	*/

  virtual  ~wxVariant() ;
	/**
	 * \brief Appends a value to the list. 
	 * \param const wxVariant&  
	*/

  void Append(const wxVariant&  value ) ;
	/**
	 * \brief Deletes the contents of the list. 
	*/

  void ClearList() ;
	/**
	 * \brief Returns the number of elements in the list. 
	*/

  int GetCount() const;
	/**
	 * \brief Deletes the zero-based   from the list. 
	 * \param int   
	*/

  bool Delete(int  item ) ;
	/**
	 * \brief Returns the boolean value. 
	*/

  bool GetBool() const;
	/**
	 * \brief Returns the character value. 
	*/

  char GetChar() const;
	/**
	 * \brief Returns a pointer to the internal variant data. 
	*/

  wxVariantData* GetData() const;
	/**
	 * \brief Returns the floating point value. 
	*/

  double GetDouble() const;
	/**
	 * \brief Returns the integer value. 
	*/

  long GetLong() const;
	/**
	 * \brief Returns a constant reference to the variant name. 
	*/

  const wxString& GetName() const;
	/**
	 * \brief Gets the string value. 
	*/

  wxString GetString() const;
	/**
	 * \brief Returns the value type as a string. The built-in types are: bool, char, date, double, list, long, string, stringlist, time, void&#42;.

If the variant is null, the value type returned is the string ``null&quot; (not the empty string). 
	*/

  wxString GetType() const;
	/**
	 * \brief Gets the void pointer value. 
	*/

  void* GetVoidPtr() const;
	/**
	 * \brief Gets the wxObject pointer value. 
	*/

  void* GetWxObjectPtr() const;
	/**
	 * \brief Inserts a value at the front of the list. 
	 * \param const wxVariant&  
	*/

  void Insert(const wxVariant&  value ) ;
	/**
	 * \brief Returns true if there is no data associated with this variant, false if there is data. 
	*/

  bool IsNull() const;
	/**
	 * \brief Returns true if   matches the type of the variant, false otherwise. 
	 * \param const wxString&  
	*/

  bool IsType(const wxString&  type ) const;
	/**
	 * \brief Returns true if the data is derived from the class described by  , false otherwise. 
	 * \param const wxClassInfo* type  
	*/

  bool IsValueKindOf(const wxClassInfo* type  type ) const;
	/**
	 * \brief Makes the variant null by deleting the internal data. 
	*/

  void MakeNull() ;
	/**
	 * \brief Makes a string representation of the variant value (for any type). 
	*/

  wxString MakeString() const;
	/**
	 * \brief Returns true if   matches an element in the list. 
	 * \param const wxVariant&  
	*/

  bool Member(const wxVariant&  value ) const;
	/**
	 * \brief Makes an empty list. This differs from a null variant which has no data; a null list
is of type list, but the number of elements in the list is zero. 
	*/

  void NullList() ;
	/**
	 * \brief Sets the internal variant data, deleting the existing data if there is any. 
	 * \param wxVariantData*  
	*/

  void SetData(wxVariantData*  data ) ;
};


#endif
