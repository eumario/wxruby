// wxDateTime.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxDateTime_h_)
#define _wxDateTime_h_
class wxDateTime
{
public:
  static int ConvertYearToBC(int  year ) ;
  static void GetAmPmStrings(wxString * am , wxString * pm ) ;
  static wxDateTime GetBeginDST(int  year = Inv_Year, Country  country = Country_Default) ;
  static Country GetCountry() ;
  static int GetCurrentYear(Calendar  cal = Gregorian) ;
  static Month GetCurrentMonth(Calendar  cal = Gregorian) ;
  static int GetCentury(int  year = Inv_Year) ;
  static wxDateTime GetEndDST(int  year = Inv_Year, Country  country = Country_Default) ;
  static wxString GetMonthName(Month  month , NameFlags  flags = Name_Full) ;
  static wxDateTime_t GetNumberOfDays(int  year , Calendar  cal = Gregorian) ;
  static wxDateTime_t GetNumberOfDays(Month  month , int  year = Inv_Year, Calendar  cal = Gregorian) ;
  static wxString GetWeekDayName(WeekDay  weekday , NameFlags  flags = Name_Full) ;
  static bool IsLeapYear(int  year = Inv_Year, Calendar  cal = Gregorian) ;
  static bool IsWestEuropeanCountry(Country  country = Country_Default) ;
  static bool IsDSTApplicable(int  year = Inv_Year, Country  country = Country_Default) ;
  static wxDateTime Now() ;
  static void SetCountry(Country  country ) ;
  static wxDateTime Today() ;
  static wxDateTime UNow() ;
   wxDateTime() ;
   wxDateTime(time_t  timet ) ;
   wxDateTime(const struct tm&  tm ) ;
   wxDateTime(double  jdn ) ;
   wxDateTime(wxDateTime_t  hour , wxDateTime_t  minute = 0, wxDateTime_t  second = 0, wxDateTime_t  millisec = 0) ;
   wxDateTime(wxDateTime_t  day , Month  month = Inv_Month, int  Inv_Year , wxDateTime_t  hour = 0, wxDateTime_t  minute = 0, wxDateTime_t  second = 0, wxDateTime_t  millisec = 0) ;
  wxDateTime& SetToCurrent() ;
  wxDateTime& Set(time_t  timet ) ;
  wxDateTime& Set(const struct tm&  tm ) ;
  wxDateTime& Set(double  jdn ) ;
  wxDateTime& Set(wxDateTime_t  hour , wxDateTime_t  minute = 0, wxDateTime_t  second = 0, wxDateTime_t  millisec = 0) ;
  wxDateTime& Set(wxDateTime_t  day , Month  month = Inv_Month, int  year = Inv_Year, wxDateTime_t  hour = 0, wxDateTime_t  minute = 0, wxDateTime_t  second = 0, wxDateTime_t  millisec = 0) ;
  wxDateTime& ResetTime() ;
  wxDateTime& SetYear(int  year ) ;
  wxDateTime& SetMonth(Month  month ) ;
  wxDateTime& SetDay(wxDateTime_t  day ) ;
  wxDateTime& SetHour(wxDateTime_t  hour ) ;
  wxDateTime& SetMinute(wxDateTime_t  minute ) ;
  wxDateTime& SetSecond(wxDateTime_t  second ) ;
  wxDateTime& SetMillisecond(wxDateTime_t  millisecond ) ;
  bool IsValid() const;
  Tm GetTm(const TimeZone&  tz = Local) const;
  time_t GetTicks() const;
  int GetYear(const TimeZone&  tz = Local) const;
  Month GetMonth(const TimeZone&  tz = Local) const;
  wxDateTime_t GetDay(const TimeZone&  tz = Local) const;
  WeekDay GetWeekDay(const TimeZone&  tz = Local) const;
  wxDateTime_t GetHour(const TimeZone&  tz = Local) const;
  wxDateTime_t GetMinute(const TimeZone&  tz = Local) const;
  wxDateTime_t GetSecond(const TimeZone&  tz = Local) const;
  wxDateTime_t GetMillisecond(const TimeZone&  tz = Local) const;
  wxDateTime_t GetDayOfYear(const TimeZone&  tz = Local) const;
  wxDateTime_t GetWeekOfYear(WeekFlags  flags = Monday_First, const TimeZone&  tz = Local) const;
  wxDateTime_t GetWeekOfMonth(WeekFlags  flags = Monday_First, const TimeZone&  tz = Local) const;
  bool IsWorkDay(Country  country = Country_Default) const;
  bool IsGregorianDate(GregorianAdoption  country = Gr_Standard) const;
  wxDateTime& SetFromDOS(unsigned long  ddt ) ;
  unsigned long GetAsDOS() const;
  bool IsEqualTo(const wxDateTime&  datetime ) const;
  bool IsEarlierThan(const wxDateTime&  datetime ) const;
  bool IsLaterThan(const wxDateTime&  datetime ) const;
  bool IsStrictlyBetween(const wxDateTime&  t1 , const wxDateTime&  t2 ) const;
  bool IsBetween(const wxDateTime&  t1 , const wxDateTime&  t2 ) const;
  bool IsSameDate(const wxDateTime&  dt ) const;
  bool IsSameTime(const wxDateTime&  dt ) const;
  bool IsEqualUpTo(const wxDateTime&  dt , const wxTimeSpan&  ts ) const;
  wxDateTime Add(const wxTimeSpan&  diff ) const;
  wxDateTime& Add(const wxTimeSpan&  diff ) ;
  wxDateTime& Add(const wxTimeSpan&  diff ) ;
  wxDateTime Add(const wxDateSpan&  diff ) const;
  wxDateTime& Add(const wxDateSpan&  diff ) ;
  wxDateTime& Add(const wxDateSpan&  diff ) ;
  wxDateTime Subtract(const wxTimeSpan&  diff ) const;
  wxDateTime& Subtract(const wxTimeSpan&  diff ) ;
  wxDateTime& Subtract(const wxTimeSpan&  diff ) ;
  wxDateTime Subtract(const wxDateSpan&  diff ) const;
  wxDateTime& Subtract(const wxDateSpan&  diff ) ;
  wxDateTime& Subtract(const wxDateSpan&  diff ) ;
  wxTimeSpan Subtract(const wxDateTime&  dt ) const;
  const wxChar * ParseRfc822Date(const wxChar*  date ) ;
  ParseFormat ParseFormat() ;
  const wxChar * ParseDateTime(const wxChar * datetime ) ;
  const wxChar * ParseDate(const wxChar * date ) ;
  const wxChar * ParseTime(const wxChar * time ) ;
   Format() const;
  wxString  FormatDate() const;
  wxString  FormatTime() const;
  wxString  FormatISODate() const;
  wxString  FormatISOTime() const;
  wxDateTime& SetToWeekDayInSameWeek(WeekDay  weekday , WeekFlags flags = Monday_First) ;
  wxDateTime GetWeekDayInSameWeek(WeekDay  weekday , WeekFlags flags = Monday_First) const;
  wxDateTime& SetToNextWeekDay(WeekDay  weekday ) ;
  wxDateTime GetNextWeekDay(WeekDay  weekday ) const;
  wxDateTime& SetToPrevWeekDay(WeekDay  weekday ) ;
  wxDateTime GetPrevWeekDay(WeekDay  weekday ) const;
  bool SetToWeekDay(WeekDay  weekday , int  n = 1, Month  month = Inv_Month, int  year = Inv_Year) ;
  wxDateTime GetWeekDay(WeekDay  weekday , int  n = 1, Month  month = Inv_Month, int  year = Inv_Year) const;
  bool SetToLastWeekDay(WeekDay  weekday , Month  month = Inv_Month, int  year = Inv_Year) ;
  wxDateTime GetLastWeekDay(WeekDay  weekday , Month  month = Inv_Month, int  year = Inv_Year) ;
  bool SetToTheWeek(wxDateTime_t  numWeek , WeekDay  weekday = Mon, WeekFlags flags = Monday_First) ;
  wxDateTime GetWeek(wxDateTime_t  numWeek , WeekDay  weekday = Mon, WeekFlags flags = Monday_First) const;
  wxDateTime& SetToLastMonthDay(Month  month = Inv_Month, int  year = Inv_Year) ;
  wxDateTime GetLastMonthDay(Month  month = Inv_Month, int  year = Inv_Year) const;
  wxDateTime& SetToYearDay(wxDateTime_t  yday ) ;
  wxDateTime GetYearDay(wxDateTime_t  yday ) const;
  double GetJulianDayNumber() const;
  double GetJDN() const;
  double GetModifiedJulianDayNumber() const;
  double GetMJD() const;
  double GetRataDie() const;
  wxDateTime ToTimezone(const TimeZone&  tz , bool  noDST = false) const;
  wxDateTime& MakeTimezone(const TimeZone&  tz , bool  noDST = false) ;
  wxDateTime ToGMT(bool  noDST = false) const;
  wxDateTime& MakeGMT(bool  noDST = false) ;
  int IsDST(Country  country = Country_Default) const;
};


#endif
