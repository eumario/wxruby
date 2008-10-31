// wxProcessEvent.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxProcessEvent_h_)
#define _wxProcessEvent_h_
class wxProcessEvent : public wxEvent
{
public:
	/**
	 * \brief Constructor. Takes a wxProcessObject or window id, a process id and an
exit status. 
	 * \param int   
	 * \param int   
	 * \param int   
	*/

   wxProcessEvent(int  id = 0, int  pid = 0, int  exitcode = 0) ;
	/**
	 * \brief Returns the process id. 
	*/

  int GetPid() const;
	/**
	 * \brief Returns the exist status. 
	*/

  int GetExitCode() ;
};


#endif
