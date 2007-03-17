// wxTimer.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxTimer_h_)
#define _wxTimer_h_
class wxTimer : public wxEvtHandler
{
public:
	/**
	 * \brief Default constructor. If you use it to construct the object and don't call 
  later, you must override 
  method to process the notifications. 
	*/

   wxTimer() ;
	/**
	 * \brief Creates a timer and associates it with  . Please see 
  for the description of parameters. 
	 * \param wxEvtHandler *  
	 * \param int   
	*/

   wxTimer(wxEvtHandler * owner , int  id = -1) ;
	/**
	 * \brief Destructor. Stops the timer if it is running. 
	*/

  virtual  ~wxTimer() ;
	/**
	 * \brief Returns the current interval for the timer (in milliseconds). 
	*/

  int GetInterval() const;
	/**
	 * \brief Returns   if the timer is one shot, i.e.\ if it will stop after firing the
first notification automatically. 
	*/

  bool IsOneShot() const;
	/**
	 * \brief Returns   if the timer is running,   if it is stopped. 
	*/

  bool IsRunning() const;
	/**
	 * \brief This member should be overridden by the user if the default constructor was
used and   wasn't called.

Perform whatever action which is to be taken periodically here. 
	*/

  void Notify() ;
	/**
	 * \brief Associates the timer with the given  \/ object. When the timer is
running, the owner will receive   with
id equal to  \/ specified here. 
	 * \param wxEvtHandler *  
	 * \param int   
	*/

  void SetOwner(wxEvtHandler * owner , int  id = -1) ;
	/**
	 * \brief (Re)starts the timer. If  \/ parameter is -1 (value by default),
the previous value is used. Returns   if the timer could not be started,
  otherwise (in MS Windows timers are a limited resource).

If  \/ is   (the default), the   
function will be called repeatedly until the timer is stopped. If  ,
it will be called only once and the timer will stop automatically. To make your
code more readable you may also use the following symbolic constants
\twocolwidtha{5cm} 


If the timer was already running, it will be stopped by this method before
restarting it. 
	 * \param int  
	 * \param bool   
	*/

  bool Start(int milliseconds = -1, bool  oneShot = false) ;
	/**
	 * \brief Stops the timer. 
	*/

  void Stop() ;
};


#endif
