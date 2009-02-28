// wxCondition.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxCondition_h_)
#define _wxCondition_h_
class wxCondition
{
public:
	/**
	 * \brief Default and only constructor. The   must be locked by the caller
before calling   function.

Use   to check if the object was successfully
intiialized. 
	 * \param wxMutex&   
	*/

   wxCondition(wxMutex&  mutex ) ;
	/**
	 * \brief Destroys the wxCondition object. The destructor is not virtual so this class
should not be used polymorphically. 
	*/

  virtual  ~wxCondition() ;
	/**
	 * \brief Broadcasts to all waiting threads, waking all of them up. Note that this method
may be called whether the mutex associated with this condition is locked or
not. 
	*/

  void Broadcast() ;
	/**
	 * \brief Returns   if the object had been initialized successfully,   
if an error occured. 
	*/

  bool IsOk() const;
	/**
	 * \brief Signals the object waking up at most one thread. If several threads are waiting
on the same condition, the exact thread which is woken up is undefined. If no
threads are waiting, the signal is lost and the condition would have to be
signalled again to wake up any thread which may start waiting on it later.

Note that this method may be called whether the mutex associated with this
condition is locked or not. 
	*/

  void Signal() ;
	/**
	 * \brief Waits until the condition is signalled.

This method atomically releases the lock on the mutex associated with this
condition (this is why it must be locked prior to calling Wait) and puts the
thread to sleep until   or 
  is called.

Note that even if   had been called before
Wait without waking up any thread, the thread would still wait for another one
and so it is important to ensure that the condition will be signalled after
Wait or the thread may sleep forever. 
	*/

  wxCondError Wait() ;
	/**
	 * \brief Waits until the condition is signalled or the timeout has elapsed.

This method is identical to   except that it
returns, with the return code of   as soon as the given
timeout expires. 
	 * \param unsigned long  
	*/

  wxCondError WaitTimeout(unsigned long  milliseconds ) ;
};


#endif
