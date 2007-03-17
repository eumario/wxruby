// wxObject.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxObject_h_)
#define _wxObject_h_
class wxObject
{
public:
	/**
	 * \brief  
	*/

   wxObject() ;
	/**
	 * \brief Default and copy constructors. 
	 * \param const wxObject&  
	*/

   wxObject(const wxObject&  other ) ;
	/**
	 * \brief Destructor. Performs dereferencing, for those objects
that use reference counting. 
	*/

  virtual  ~wxObject() ;
	/**
	 * \brief A virtual function that may be redefined by derived classes to allow dumping of
memory states.

This function is only defined in debug build and doesn't exist at all if
  is not defined. 
	 * \param ostream&  
	*/

  void Dump(ostream&  stream ) ;
	/**
	 * \brief This virtual function is redefined for every class that requires run-time
type information, when using DECLARE_CLASS macros. 
	*/

  wxClassInfo * GetClassInfo() ;
	/**
	 * \brief  
	*/

  wxObjectRefData* GetRefData() const;
	/**
	 * \brief Determines whether this class is a subclass of (or the same class as)
the given class. 
	 * \param wxClassInfo *  
	*/

  bool IsKindOf(wxClassInfo * info ) ;
	/**
	 * \brief  
	 * \param const wxObject&   
	*/

  void Ref(const wxObject&  clone ) ;
	/**
	 * \brief  
	 * \param wxObjectRefData*  
	*/

  void SetRefData(wxObjectRefData*  data ) ;
	/**
	 * \brief  
	*/

  void UnRef() ;
};


#endif
