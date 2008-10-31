// wxAutomationObject.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxAutomationObject_h_)
#define _wxAutomationObject_h_
class wxAutomationObject : public wxObject
{
public:
	/**
	 * \brief Constructor, taking an optional IDispatch pointer which will be released when the
object is deleted. 
	 * \param WXIDISPATCH*  
	*/

   wxAutomationObject(WXIDISPATCH* dispatchPtr = NULL) ;
	/**
	 * \brief Destructor. If the internal IDispatch pointer is non-null, it will be released. 
	*/

  virtual  ~wxAutomationObject() ;
	/**
	 * \brief  
	 * \param const wxString&  
	 * \param int  
	 * \param wxVariant   
	*/

  wxVariant CallMethod(const wxString&  method , int  noArgs , wxVariant  args[] ) const;
	/**
	 * \brief Calls an automation method for this object. The first form takes a method name, number of
arguments, and an array of variants. The second form takes a method name and zero to six
constant references to variants. Since the variant class has constructors for the basic
data types, and C++ provides temporary objects automatically, both of the following lines
are syntactically valid:

 

Note that   can contain dot-separated property names, to save the application
needing to call GetProperty several times using several temporary objects. For example: 
	 * \param const wxString&  
	 * \param ...  
	*/

  wxVariant CallMethod(const wxString&  method , ...  ) const;
	/**
	 * \brief Creates a new object based on the class id, returning true if the object was successfully created,
or false if not. 
	 * \param const wxString&  
	*/

  bool CreateInstance(const wxString&  classId ) const;
	/**
	 * \brief Gets the IDispatch pointer. 
	*/

  IDispatch* GetDispatchPtr() const;
	/**
	 * \brief Retrieves the current object associated with a class id, and attaches the IDispatch pointer
to this object. Returns true if a pointer was successfully retrieved, false otherwise.

Note that this cannot cope with two instances of a given OLE object being active simultaneously,
such as two copies of Excel running. Which object is referenced cannot currently be specified. 
	 * \param const wxString&  
	*/

  bool GetInstance(const wxString&  classId ) const;
	/**
	 * \brief Retrieves a property from this object, assumed to be a dispatch pointer, and initialises   with it.
To avoid having to deal with IDispatch pointers directly, use this function in preference
to   when retrieving objects
from other objects.

Note that an IDispatch pointer is stored as a void&#42; pointer in wxVariant objects. 
	 * \param wxAutomationObject&  
	 * \param const wxString&  
	 * \param int  
	 * \param wxVariant   
	*/

  bool GetObject(wxAutomationObject& obj , const wxString&  property , int noArgs = 0, wxVariant  args[] = NULL) const;
	/**
	 * \brief  
	 * \param const wxString&  
	 * \param int  
	 * \param wxVariant   
	*/

  wxVariant GetProperty(const wxString&  property , int  noArgs , wxVariant  args[] ) const;
	/**
	 * \brief Gets a property value from this object. The first form takes a property name, number of
arguments, and an array of variants. The second form takes a property name and zero to six
constant references to variants. Since the variant class has constructors for the basic
data types, and C++ provides temporary objects automatically, both of the following lines
are syntactically valid:

 

Note that   can contain dot-separated property names, to save the application
needing to call GetProperty several times using several temporary objects. 
	 * \param const wxString&  
	 * \param ...  
	*/

  wxVariant GetProperty(const wxString&  property , ...  ) const;
	/**
	 * \brief This function is a low-level implementation that allows access to the IDispatch Invoke function.
It is not meant to be called directly by the application, but is used by other convenience functions.







. 
	 * \param const wxString&  
	 * \param int  
	 * \param wxVariant&   
	 * \param int  
	 * \param wxVariant  
	 * \param const wxVariant*  
	*/

  bool Invoke(const wxString&  member , int  action , wxVariant&  retValue , int  noArgs , wxVariant  args[] , const wxVariant* ptrArgs[] = 0) const;
	/**
	 * \brief  
	 * \param const wxString&  
	 * \param int  
	 * \param wxVariant   
	*/

  bool PutProperty(const wxString&  property , int  noArgs , wxVariant  args[] ) const;
	/**
	 * \brief Puts a property value into this object. The first form takes a property name, number of
arguments, and an array of variants. The second form takes a property name and zero to six
constant references to variants. Since the variant class has constructors for the basic
data types, and C++ provides temporary objects automatically, both of the following lines
are syntactically valid:

 

Note that   can contain dot-separated property names, to save the application
needing to call GetProperty several times using several temporary objects. 
	 * \param const wxString&  
	 * \param ...  
	*/

  bool PutProperty(const wxString&  property , ...  ) ;
	/**
	 * \brief Sets the IDispatch pointer. This function does not check if there is already an IDispatch pointer.

You may need to cast from IDispatch&#42; to WXIDISPATCH&#42; when calling this function. 
	 * \param WXIDISPATCH*  
	*/

  void SetDispatchPtr(WXIDISPATCH*  dispatchPtr ) ;
};


#endif
