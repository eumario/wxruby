// wxMutex.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxMutex_h_)
#define _wxMutex_h_
class wxMutex
{
public:
	/**
	 * \brief Default constructor. 
	*/

   wxMutex() ;
	/**
	 * \brief Destroys the wxMutex object. 
	*/

  virtual  ~wxMutex() ;
	/**
	 * \brief Locks the mutex object. 
	*/

  wxMutexError Lock() ;
	/**
	 * \brief Tries to lock the mutex object. If it can't, returns immediately with an error. 
	*/

  wxMutexError TryLock() ;
	/**
	 * \brief Unlocks the mutex object. 
	*/

  wxMutexError Unlock() ;
};


#endif
