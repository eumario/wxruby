// wxMutexLocker.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxMutexLocker_h_)
#define _wxMutexLocker_h_
class wxMutexLocker
{
public:
	/**
	 * \brief Constructs a wxMutexLocker object associated with mutex and locks it.
Call   to check if the mutex was
successfully locked. 
	 * \param wxMutex&  
	*/

   wxMutexLocker(wxMutex&  mutex ) ;
	/**
	 * \brief Destructor releases the mutex if it was successfully acquired in the ctor. 
	*/

  virtual  ~wxMutexLocker() ;
	/**
	 * \brief Returns true if mutex was acquired in the constructor, false otherwise. 
	*/

  bool IsOk() const;
};


#endif
