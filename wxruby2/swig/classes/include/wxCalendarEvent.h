// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license


#if !defined(_wxCalendarEvent_h_)
#define _wxCalendarEvent_h_
class wxCalendarEvent : public wxDateEvent
{
public:
  wxDateTime::WeekDay GetWeekDay() const;
  void SetWeekDay(wxDateTime::WeekDay day);

  // override pure virtual methods from base classes
  virtual wxEvent* Clone() const;

};


#endif
