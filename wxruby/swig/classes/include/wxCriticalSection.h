// wxCriticalSection.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxCriticalSection_h_)
#define _wxCriticalSection_h_
class wxCriticalSection
{
public:
	/**
	 * \brief Default constructor initializes critical section object. 
	*/

   wxCriticalSection() ;
	/**
	 * \brief Destructor frees the resources. 
	*/

  virtual  ~wxCriticalSection() ;
	/**
	 * \brief Enter the critical section (same as locking a mutex). There is no error return
for this function. After entering the critical section protecting some global
data the thread running in critical section may safely use/modify it. 
	*/

  void  Enter() ;
	/**
	 * \brief Leave the critical section allowing other threads use the global data protected
by it. There is no error return for this function. 
	*/

  void  Leave() ;
};


#endif
