// wxSemaphore.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxSemaphore_h_)
#define _wxSemaphore_h_
class wxSemaphore
{
public:
	/**
	 * \brief Specifying a   of 0 actually makes wxSemaphore behave as if
there is no upper limit. If maxcount is 1 the semaphore behaves exactly as a
mutex.

  is the initial value of the semaphore which must be between
0 and   (if it is not set to 0). 
	 * \param int   
	 * \param int   
	*/

   wxSemaphore(int  initialcount = 0, int  maxcount = 0) ;
	/**
	 * \brief Destructor is not virtual, don't use this class polymorphically. 
	*/

  virtual  ~wxSemaphore() ;
	/**
	 * \brief Increments the semaphore count and signals one of the waiting
threads in an atomic way. Returns wxSEMA_OVERFLOW if the count
would increase the counter past the maximum. 
	*/

  wxSemaError  Post() ;
	/**
	 * \brief Same as  , but returns immediately. 
	*/

  wxSemaError  TryWait() ;
	/**
	 * \brief Wait indefinitely until the semaphore count becomes strictly positive
and then decrement it and return. 
	*/

  wxSemaError  Wait() ;
	/**
	 * \brief Same as  , but with a timeout
limit. 
	 * \param unsigned
long  
	*/

  wxSemaError  WaitTimeout(unsigned
long timeout_millis ) ;
};


#endif
