//   Copyright 2004-2007 by Kevin Smith
//   released under the MIT-style wxruby2 license


#if !defined(_wxCalendarEvent_h_)
#define _wxCalendarEvent_h_
class wxCalendarEvent : public wxEvent
{
public:
  const wxDateTime& GetDate() const;
  wxDateTime::WeekDay GetWeekDay() const;
  void SetWeekDay(wxDateTime::WeekDay day);

  // override pure virtual methods from base classes
  virtual wxEvent* Clone() const;

};


#endif
