// wxCalendarEvent.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxCalendarEvent_h_)
#define _wxCalendarEvent_h_
class wxCalendarEvent
{
public:
	/**
	 * \brief Returns the date. This function may be called for all event types except 
  one for which it doesn't make sense. 
	*/

  const wxDateTime& GetDate() const;
	/**
	 * \brief Returns the week day on which the user clicked in 
  handler. It doesn't make sense to call
this function in other handlers. 
	*/

  wxDateTime::WeekDay GetWeekDay() const;
};


#endif
