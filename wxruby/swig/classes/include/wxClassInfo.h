// wxClassInfo.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxClassInfo_h_)
#define _wxClassInfo_h_
class wxClassInfo
{
public:
	/**
	 * \brief Constructs a wxClassInfo object. The supplied macros implicitly construct objects of this
class, so there is no need to create such objects explicitly in an application. 
	 * \param char*   
	 * \param char*   
	 * \param char*   
	 * \param int  
	 * \param wxObjectConstructorFn   
	*/

  //wxClassInfo(char*  className , char*  baseClass1 , char*  baseClass2 , int  size , wxObjectConstructorFn  fn );
	/**
	 * \brief Creates an object of the appropriate kind. Returns NULL if the class has not been declared
dynamically creatable (typically, it is an abstract class). 
	*/

  wxObject* CreateObject() ;
	/**
	 * \brief Finds the wxClassInfo object for a class of the given string name. 
	 * \param char*   
	*/

  static wxClassInfo * FindClass(wxChar *  name );
	/**
	 * \brief Returns the name of the first base class (NULL if none). 
	*/

  char* GetBaseClassName1() const;
	/**
	 * \brief Returns the name of the second base class (NULL if none). 
	*/

  char* GetBaseClassName2() const;
	/**
	 * \brief Returns the string form of the class name. 
	*/

  char * GetClassName() const;
	/**
	 * \brief Returns the size of the class. 
	*/

  int GetSize() const;
	/**
	 * \brief Initializes pointers in the wxClassInfo objects for fast execution
of IsKindOf. Called in base wxWindows library initialization. 
	*/

  static void InitializeClasses() ;
	/**
	 * \brief Returns true if this class is a kind of (inherits from) the given class. 
	 * \param wxClassInfo*   
	*/

  bool IsKindOf(wxClassInfo*  info ) ;
  // the following were missing from the xml
  private: wxClassInfo(); public:;
};


#endif
