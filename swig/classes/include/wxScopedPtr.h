// wxScopedPtr.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxScopedPtr_h_)
#define _wxScopedPtr_h_
class wxScopedPtr
{
public:
	/**
	 * \brief Creates the smart pointer with the given pointer or none if NULL.  On
compilers that support it, this uses the explicit keyword. 
	 * \param type  
	*/

   wxScopedPtr(type T = NULL) ;
	/**
	 * \brief Deletes the currently held pointer and sets it to 'p' or to NULL if no 
arguments are specified. This function does check to make sure that the
pointer you are assigning is not the same pointer that is already stored. 
	 * \param T  
	*/

  void reset(T * = NULL) ;
	/**
	 * \brief This operator gets the pointer stored in the smart pointer or returns NULL if
there is none. 
	*/

  const T* get() ;
	/**
	 * \brief Swap the pointer inside the smart pointer with 'ot'. The pointer being swapped
must be of the same type (hence the same class name). 
	 * \param wxScopedPtr  
	*/

  void swap(wxScopedPtr  & ot ) ;
};


#endif
