// wxStopWatch.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxStopWatch_h_)
#define _wxStopWatch_h_
class wxStopWatch
{
public:
	/**
	 * \brief Constructor. This starts the stop watch. 
	*/

   wxStopWatch() ;
	/**
	 * \brief Pauses the stop watch. Call   to resume 
time measuring again.

If this method is called several times,   must be called the same
number of times to really resume the stop watch. You may, however, call 
  to resume it unconditionally. 
	*/

  void Pause() ;
	/**
	 * \brief Resumes the stop watch which had been paused with 
 . 
	*/

  void Resume() ;
	/**
	 * \brief (Re)starts the stop watch with a given initial value. 
	 * \param long  
	*/

  void Start(long milliseconds = 0) ;
	/**
	 * \brief \label{wxstopwatchtime}

Returns the time in milliseconds since the start (or restart) or the last call of 
 . 
	*/

  long Time() const;
};


#endif
