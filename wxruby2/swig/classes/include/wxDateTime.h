// wxDateTime.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxDateTime_h_)
#define _wxDateTime_h_
class wxDateTime
{
public:
	/**
	 * \brief Converts the year in absolute notation (i.e. a number which can be negative,
positive or zero) to the year in BC/AD notation. For the positive years,
nothing is done, but the year 0 is year 1 BC and so for other years there is a
difference of 1.

This function should be used like this: 
	 * \param int   
	*/

  static int ConvertYearToBC(int  year ) ;
	/**
	 * \brief Returns the translations of the strings   and   used for time
formatting for the current locale. Either of the pointers may be   if
the corresponding value is not needed. 
	 * \param wxString *  
	 * \param wxString *  
	*/

  static void GetAmPmStrings(wxString * am , wxString * pm ) ;
	/**
	 * \brief Get the beginning of DST for the given country in the given year (current one
by default). This function suffers from limitations described in
 . 
	 * \param int   
	 * \param Country   
	*/

  static wxDateTime GetBeginDST(int  year = Inv_Year, Country  country = Country_Default) ;
	/**
	 * \brief Returns the current default country. The default country is used for DST
calculations, for example. 
	*/

  static Country GetCountry() ;
	/**
	 * \brief Get the current year in given calendar (only Gregorian is currently supported). 
	 * \param Calendar   
	*/

  static int GetCurrentYear(Calendar  cal = Gregorian) ;
	/**
	 * \brief Get the current month in given calendar (only Gregorian is currently supported). 
	 * \param Calendar   
	*/

  static Month GetCurrentMonth(Calendar  cal = Gregorian) ;
	/**
	 * \brief Get the current century, i.e. first two digits of the year, in given calendar
(only Gregorian is currently supported). 
	 * \param int   
	*/

  static int GetCentury(int  year = Inv_Year) ;
	/**
	 * \brief Returns the end of DST for the given country in the given year (current one by
default). 
	 * \param int   
	 * \param Country   
	*/

  static wxDateTime GetEndDST(int  year = Inv_Year, Country  country = Country_Default) ;
	/**
	 * \brief Gets the full (default) or abbreviated (specify   name of the
given month. 
	 * \param Month   
	 * \param NameFlags   
	*/

  static wxString GetMonthName(Month  month , NameFlags  flags = Name_Full) ;
	/**
	 * \brief  
	 * \param int   
	 * \param Calendar   
	*/

  static wxDateTime_t GetNumberOfDays(int  year , Calendar  cal = Gregorian) ;
	/**
	 * \brief Returns the number of days in the given year or in the given month of the
year.

The only supported value for   parameter is currently  .

\pythonnote{These two methods are named  
and   in wxPython.} 
	 * \param Month   
	 * \param int   
	 * \param Calendar   
	*/

  static wxDateTime_t GetNumberOfDays(Month  month , int  year = Inv_Year, Calendar  cal = Gregorian) ;
	/**
	 * \brief Gets the full (default) or abbreviated (specify   name of the
given week day. 
	 * \param WeekDay   
	 * \param NameFlags   
	*/

  static wxString GetWeekDayName(WeekDay  weekday , NameFlags  flags = Name_Full) ;
	/**
	 * \brief Returns   if the   is a leap one in the specified calendar.

This functions supports Gregorian and Julian calendars. 
	 * \param int   
	 * \param Calendar   
	*/

  static bool IsLeapYear(int  year = Inv_Year, Calendar  cal = Gregorian) ;
	/**
	 * \brief This function returns   if the specified (or default) country is one
of Western European ones. It is used internally by wxDateTime to determine the
DST convention and date and time formatting rules. 
	 * \param Country   
	*/

  static bool IsWestEuropeanCountry(Country  country = Country_Default) ;
	/**
	 * \brief Returns   if DST was used n the given year (the current one by
default) in the given country. 
	 * \param int   
	 * \param Country   
	*/

  static bool IsDSTApplicable(int  year = Inv_Year, Country  country = Country_Default) ;
	/**
	 * \brief Returns the object corresponding to the current time.

Example:

 

Note that this function is accurate up to second: 
  should be used for better precision
(but it is less efficient and might not be available on all platforms). 
	*/

  static wxDateTime Now() ;
	/**
	 * \brief Sets the country to use by default. This setting influences the DST
calculations, date formatting and other things.

The possible values for   parameter are enumerated in
 . 
	 * \param Country   
	*/

  static void SetCountry(Country  country ) ;
	/**
	 * \brief Returns the object corresponding to the midnight of the current day (i.e. the
same as  , but the time part is set to 0). 
	*/

  static wxDateTime Today() ;
	/**
	 * \brief Returns the object corresponding to the current time including the
milliseconds if a function to get time with such precision is available on the
current platform (supported under most Unices and Win32). 
	*/

  static wxDateTime UNow() ;
	/**
	 * \brief Default constructor. Use one of   functions to initialize the object
later. 
	*/

   wxDateTime() ;
	/**
	 * \brief Same as  .

\pythonnote{This constructor is named   in wxPython.} 
	 * \param time_t   
	*/

   wxDateTime(time_t  timet ) ;
	/**
	 * \brief Same as  

\pythonnote{Unsupported.} 
	 * \param const struct tm&   
	*/

   wxDateTime(const struct tm&  tm ) ;
	/**
	 * \brief Same as  

\pythonnote{This constructor is named   in wxPython.} 
	 * \param double   
	*/

   wxDateTime(double  jdn ) ;
	/**
	 * \brief Same as  

\pythonnote{This constructor is named   in wxPython.} 
	 * \param wxDateTime_t   
	 * \param wxDateTime_t   
	 * \param wxDateTime_t   
	 * \param wxDateTime_t   
	*/

   wxDateTime(wxDateTime_t  hour , wxDateTime_t  minute = 0, wxDateTime_t  second = 0, wxDateTime_t  millisec = 0) ;
	/**
	 * \brief Same as  

\pythonnote{This constructor is named   in wxPython.} 
	 * \param wxDateTime_t   
	 * \param Month   
	 * \param int  
	 * \param wxDateTime_t   
	 * \param wxDateTime_t   
	 * \param wxDateTime_t   
	 * \param wxDateTime_t   
	*/

   wxDateTime(wxDateTime_t  day , Month  month = Inv_Month, int  Inv_Year , wxDateTime_t  hour = 0, wxDateTime_t  minute = 0, wxDateTime_t  second = 0, wxDateTime_t  millisec = 0) ;
	/**
	 * \brief Sets the date and time of to the current values. Same as assigning the result
of   to this object. 
	*/

  wxDateTime& SetToCurrent() ;
	/**
	 * \brief Constructs the object from   value holding the number of seconds
since Jan 1, 1970.

\pythonnote{This method is named   in wxPython.} 
	 * \param time_t   
	*/

  wxDateTime& Set(time_t  timet ) ;
	/**
	 * \brief Sets the date and time from the broken down representation in the standard
  structure.

\pythonnote{Unsupported.} 
	 * \param const struct tm&   
	*/

  wxDateTime& Set(const struct tm&  tm ) ;
	/**
	 * \brief Sets the date from the so-called  .

By definition, the Julian Day Number, usually abbreviated as JDN, of a
particular instant is the fractional number of days since 12 hours Universal
Coordinated Time (Greenwich mean noon) on January 1 of the year -4712 in the
Julian proleptic calendar.

\pythonnote{This method is named   in wxPython.} 
	 * \param double   
	*/

  wxDateTime& Set(double  jdn ) ;
	/**
	 * \brief Sets the date to be equal to   and the time
from supplied parameters.

\pythonnote{This method is named   in wxPython.} 
	 * \param wxDateTime_t   
	 * \param wxDateTime_t   
	 * \param wxDateTime_t   
	 * \param wxDateTime_t   
	*/

  wxDateTime& Set(wxDateTime_t  hour , wxDateTime_t  minute = 0, wxDateTime_t  second = 0, wxDateTime_t  millisec = 0) ;
	/**
	 * \brief Sets the date and time from the parameters. 
	 * \param wxDateTime_t   
	 * \param Month   
	 * \param int   
	 * \param wxDateTime_t   
	 * \param wxDateTime_t   
	 * \param wxDateTime_t   
	 * \param wxDateTime_t   
	*/

  wxDateTime& Set(wxDateTime_t  day , Month  month = Inv_Month, int  year = Inv_Year, wxDateTime_t  hour = 0, wxDateTime_t  minute = 0, wxDateTime_t  second = 0, wxDateTime_t  millisec = 0) ;
	/**
	 * \brief Reset time to midnight (00:00:00) without changing the date. 
	*/

  wxDateTime& ResetTime() ;
	/**
	 * \brief Sets the year without changing other date components. 
	 * \param int   
	*/

  wxDateTime& SetYear(int  year ) ;
	/**
	 * \brief Sets the month without changing other date components. 
	 * \param Month   
	*/

  wxDateTime& SetMonth(Month  month ) ;
	/**
	 * \brief Sets the day without changing other date components. 
	 * \param wxDateTime_t   
	*/

  wxDateTime& SetDay(wxDateTime_t  day ) ;
	/**
	 * \brief Sets the hour without changing other date components. 
	 * \param wxDateTime_t   
	*/

  wxDateTime& SetHour(wxDateTime_t  hour ) ;
	/**
	 * \brief Sets the minute without changing other date components. 
	 * \param wxDateTime_t   
	*/

  wxDateTime& SetMinute(wxDateTime_t  minute ) ;
	/**
	 * \brief Sets the second without changing other date components. 
	 * \param wxDateTime_t   
	*/

  wxDateTime& SetSecond(wxDateTime_t  second ) ;
	/**
	 * \brief Sets the millisecond without changing other date components. 
	 * \param wxDateTime_t   
	*/

  wxDateTime& SetMillisecond(wxDateTime_t  millisecond ) ;
	/**
	 * \brief Returns   if the object represents a valid time moment. 
	*/

  bool IsValid() const;
	/**
	 * \brief Returns broken down representation of the date and time. 
	 * \param const TimeZone&   
	*/

  Tm GetTm(const TimeZone&  tz = Local) const;
	/**
	 * \brief Returns the number of seconds since Jan 1, 1970. An assert failure will occur
if the date is not in the range covered by   type. 
	*/

  time_t GetTicks() const;
	/**
	 * \brief Returns the year in the given timezone (local one by default). 
	 * \param const TimeZone&   
	*/

  int GetYear(const TimeZone&  tz = Local) const;
	/**
	 * \brief Returns the month in the given timezone (local one by default). 
	 * \param const TimeZone&   
	*/

  Month GetMonth(const TimeZone&  tz = Local) const;
	/**
	 * \brief Returns the day in the given timezone (local one by default). 
	 * \param const TimeZone&   
	*/

  wxDateTime_t GetDay(const TimeZone&  tz = Local) const;
	/**
	 * \brief Returns the week day in the given timezone (local one by default). 
	 * \param const TimeZone&   
	*/

  WeekDay GetWeekDay(const TimeZone&  tz = Local) const;
	/**
	 * \brief Returns the hour in the given timezone (local one by default). 
	 * \param const TimeZone&   
	*/

  wxDateTime_t GetHour(const TimeZone&  tz = Local) const;
	/**
	 * \brief Returns the minute in the given timezone (local one by default). 
	 * \param const TimeZone&   
	*/

  wxDateTime_t GetMinute(const TimeZone&  tz = Local) const;
	/**
	 * \brief Returns the seconds in the given timezone (local one by default). 
	 * \param const TimeZone&   
	*/

  wxDateTime_t GetSecond(const TimeZone&  tz = Local) const;
	/**
	 * \brief Returns the milliseconds in the given timezone (local one by default). 
	 * \param const TimeZone&   
	*/

  wxDateTime_t GetMillisecond(const TimeZone&  tz = Local) const;
	/**
	 * \brief Returns the day of the year (in $1\ldots366$ range) in the given timezone
(local one by default). 
	 * \param const TimeZone&   
	*/

  wxDateTime_t GetDayOfYear(const TimeZone&  tz = Local) const;
	/**
	 * \brief Returns the number of the week of the year this date is in. The first week of
the year is, according to international standards, the one containing Jan 4.
The week number is in $1\ldots53$ range (52 for non leap years).

The function depends on the   convention
specified by the   argument. 
	 * \param WeekFlags   
	 * \param const TimeZone&   
	*/

  wxDateTime_t GetWeekOfYear(WeekFlags  flags = Monday_First, const TimeZone&  tz = Local) const;
	/**
	 * \brief Returns the ordinal number of the week in the month (in $1\ldots5$  range).

As  , this function supports
both conventions for the week start. See the description of these
  conventions. 
	 * \param WeekFlags   
	 * \param const TimeZone&   
	*/

  wxDateTime_t GetWeekOfMonth(WeekFlags  flags = Monday_First, const TimeZone&  tz = Local) const;
	/**
	 * \brief Returns   is this day is not a holiday in the given country. 
	 * \param Country   
	*/

  bool IsWorkDay(Country  country = Country_Default) const;
	/**
	 * \brief Returns   if the given date os later than the date of adoption of the
Gregorian calendar in the given country (and hence the Gregorian calendar
calculations make sense for it). 
	 * \param GregorianAdoption   
	*/

  bool IsGregorianDate(GregorianAdoption  country = Gr_Standard) const;
	/**
	 * \brief Sets the date from the date and time in 
  
format. 
	 * \param unsigned long   
	*/

  wxDateTime& SetFromDOS(unsigned long  ddt ) ;
	/**
	 * \brief Returns the date and time in 
  
format. 
	*/

  unsigned long GetAsDOS() const;
	/**
	 * \brief Returns   if the two dates are strictly identical. 
	 * \param const wxDateTime&   
	*/

  bool IsEqualTo(const wxDateTime&  datetime ) const;
	/**
	 * \brief Returns   if this date precedes the given one. 
	 * \param const wxDateTime&   
	*/

  bool IsEarlierThan(const wxDateTime&  datetime ) const;
	/**
	 * \brief Returns   if this date is later than the given one. 
	 * \param const wxDateTime&   
	*/

  bool IsLaterThan(const wxDateTime&  datetime ) const;
	/**
	 * \brief Returns   if this date lies strictly between the two others, 
	 * \param const wxDateTime&   
	 * \param const wxDateTime&   
	*/

  bool IsStrictlyBetween(const wxDateTime&  t1 , const wxDateTime&  t2 ) const;
	/**
	 * \brief Returns   if  
is   or if the date is equal to one of the limit values. 
	 * \param const wxDateTime&   
	 * \param const wxDateTime&   
	*/

  bool IsBetween(const wxDateTime&  t1 , const wxDateTime&  t2 ) const;
	/**
	 * \brief Returns   if the date is the same without comparing the time parts. 
	 * \param const wxDateTime&   
	*/

  bool IsSameDate(const wxDateTime&  dt ) const;
	/**
	 * \brief Returns   if the time is the same (although dates may differ). 
	 * \param const wxDateTime&   
	*/

  bool IsSameTime(const wxDateTime&  dt ) const;
	/**
	 * \brief Returns   if the date is equal to another one up to the given time
interval, i.e. if the absolute difference between the two dates is less than
this interval. 
	 * \param const wxDateTime&   
	 * \param const wxTimeSpan&   
	*/

  bool IsEqualUpTo(const wxDateTime&  dt , const wxTimeSpan&  ts ) const;
	/**
	 * \brief  
	 * \param const wxTimeSpan&   
	*/

  wxDateTime Add(const wxTimeSpan&  diff ) const;
	/**
	 * \brief  
	 * \param const wxTimeSpan&   
	*/

  wxDateTime& Add(const wxTimeSpan&  diff ) ;
	/**
	 * \brief Adds the given time span to this object.

\pythonnote{This method is named   in wxPython.} 
	 * \param const wxTimeSpan&   
	*/

  wxDateTime& Add(const wxTimeSpan&  diff ) ;
	/**
	 * \brief  
	 * \param const wxDateSpan&   
	*/

  wxDateTime Add(const wxDateSpan&  diff ) const;
	/**
	 * \brief  
	 * \param const wxDateSpan&   
	*/

  wxDateTime& Add(const wxDateSpan&  diff ) ;
	/**
	 * \brief Adds the given date span to this object.

\pythonnote{This method is named   in wxPython.} 
	 * \param const wxDateSpan&   
	*/

  wxDateTime& Add(const wxDateSpan&  diff ) ;
	/**
	 * \brief  
	 * \param const wxTimeSpan&   
	*/

  wxDateTime Subtract(const wxTimeSpan&  diff ) const;
	/**
	 * \brief  
	 * \param const wxTimeSpan&   
	*/

  wxDateTime& Subtract(const wxTimeSpan&  diff ) ;
	/**
	 * \brief Subtracts the given time span from this object.

\pythonnote{This method is named   in wxPython.} 
	 * \param const wxTimeSpan&   
	*/

  wxDateTime& Subtract(const wxTimeSpan&  diff ) ;
	/**
	 * \brief  
	 * \param const wxDateSpan&   
	*/

  wxDateTime Subtract(const wxDateSpan&  diff ) const;
	/**
	 * \brief  
	 * \param const wxDateSpan&   
	*/

  wxDateTime& Subtract(const wxDateSpan&  diff ) ;
	/**
	 * \brief Subtracts the given date span from this object.

\pythonnote{This method is named   in wxPython.} 
	 * \param const wxDateSpan&   
	*/

  wxDateTime& Subtract(const wxDateSpan&  diff ) ;
	/**
	 * \brief Subtracts another date from this one and returns the difference between them
as wxTimeSpan. 
	 * \param const wxDateTime&   
	*/

  wxTimeSpan Subtract(const wxDateTime&  dt ) const;
	/**
	 * \brief Parses the string   looking for a date formatted according to the RFC
822 in it. The exact description of this format may, of course, be found in
the RFC (section 5), but, briefly, this is the format used in the headers of
Internet email messages and one of the most common strings expressing date in
this format may be something like  .

Returns   if the conversion failed, otherwise return the pointer to
the character immediately following the part of the string which could be
parsed. If the entire string contains only the date in RFC 822 format,
the returned pointer will be pointing to a   character.

This function is intentionally strict, it will return an error for any string
which is not RFC 822 compliant. If you need to parse date formatted in more
free ways, you should use   or
  instead. 
	 * \param const wxChar*   
	*/

  const wxChar * ParseRfc822Date(const wxChar*  date ) ;
	/**
	 * \brief , \param{const wxChar &#42;}{format = &quot;\
This function parses the string   according to the given
 . The system   function is used whenever available,
but even if it is not, this function is still implemented (although support
for locale-dependent format specificators such as   for the syntax of
the format string.

The   parameter is used to fill in the fields which could not be
determined from the format string. For example, if the format is  {wxdatetimetoday} is used as the
default date.

Returns   if the conversion failed, otherwise return the pointer to
the character which stopped the scan. 
	*/

  ParseFormat ParseFormat() ;
	/**
	 * \brief Parses the string   containing the date and time in free format.
This function tries as hard as it can to interpret the given string as date
and time. Unlike  , it
will accept anything that may be accepted and will only reject strings which
can not be parsed in any way at all.

Returns   if the conversion failed, otherwise return the pointer to
the character which stopped the scan. 
	 * \param const wxChar *  
	*/

  const wxChar * ParseDateTime(const wxChar * datetime ) ;
	/**
	 * \brief This function is like  , but it
only allows the date to be specified. It is thus less flexible then 
 , but also has less chances to
misinterpret the user input.

Returns   if the conversion failed, otherwise return the pointer to
the character which stopped the scan. 
	 * \param const wxChar *  
	*/

  const wxChar * ParseDate(const wxChar * date ) ;
	/**
	 * \brief This functions is like  , but
only allows the time to be specified in the input string.

Returns   if the conversion failed, otherwise return the pointer to
the character which stopped the scan. 
	 * \param const wxChar *  
	*/

  const wxChar * ParseTime(const wxChar * time ) ;
	/**
	 * \brief  
	*/

   Format() const;
	/**
	 * \brief Identical to calling   with {\tt &quot;\argument (which means `preferred date representation for the current locale'). 
	*/

  wxString  FormatDate() const;
	/**
	 * \brief Identical to calling   with {\tt &quot;\argument (which means `preferred time representation for the current locale'). 
	*/

  wxString  FormatTime() const;
	/**
	 * \brief This function returns the date representation in the ISO 8601 format
(YYYY-MM-DD). 
	*/

  wxString  FormatISODate() const;
	/**
	 * \brief This function returns the time representation in the ISO 8601 format
(HH:MM:SS). 
	*/

  wxString  FormatISOTime() const;
	/**
	 * \brief Adjusts the date so that it will still lie in the same week as before, but its
week day will be the given one.

Returns the reference to the modified object itself. 
	 * \param WeekDay   
	 * \param WeekFlags  
	*/

  wxDateTime& SetToWeekDayInSameWeek(WeekDay  weekday , WeekFlags flags = Monday_First) ;
	/**
	 * \brief Returns the copy of this object to which 
  was
applied. 
	 * \param WeekDay   
	 * \param WeekFlags  
	*/

  wxDateTime GetWeekDayInSameWeek(WeekDay  weekday , WeekFlags flags = Monday_First) const;
	/**
	 * \brief Sets the date so that it will be the first   following the current
date.

Returns the reference to the modified object itself. 
	 * \param WeekDay   
	*/

  wxDateTime& SetToNextWeekDay(WeekDay  weekday ) ;
	/**
	 * \brief Returns the copy of this object to which
  was applied. 
	 * \param WeekDay   
	*/

  wxDateTime GetNextWeekDay(WeekDay  weekday ) const;
	/**
	 * \brief Sets the date so that it will be the last   before the current
date.

Returns the reference to the modified object itself. 
	 * \param WeekDay   
	*/

  wxDateTime& SetToPrevWeekDay(WeekDay  weekday ) ;
	/**
	 * \brief Returns the copy of this object to which
  was applied. 
	 * \param WeekDay   
	*/

  wxDateTime GetPrevWeekDay(WeekDay  weekday ) const;
	/**
	 * \brief Sets the date to the  -th   in the given month of the given
year (the current month and year are used by default). The parameter  
may be either positive (counting from the beginning of the month) or negative
(counting from the end of it).

For example,   will set the date to the
second Wednesday in the current month and
  -- to the last Sunday in it.

Returns   if the date was modified successfully,  
otherwise meaning that the specified date doesn't exist. 
	 * \param WeekDay   
	 * \param int   
	 * \param Month   
	 * \param int   
	*/

  bool SetToWeekDay(WeekDay  weekday , int  n = 1, Month  month = Inv_Month, int  year = Inv_Year) ;
	/**
	 * \brief Returns the copy of this object to which
  was applied. 
	 * \param WeekDay   
	 * \param int   
	 * \param Month   
	 * \param int   
	*/

  wxDateTime GetWeekDay(WeekDay  weekday , int  n = 1, Month  month = Inv_Month, int  year = Inv_Year) const;
	/**
	 * \brief The effect of calling this function is the same as of calling
 . The date will be set to the last
  in the given month and year (the current ones by default).

Always returns  . 
	 * \param WeekDay   
	 * \param Month   
	 * \param int   
	*/

  bool SetToLastWeekDay(WeekDay  weekday , Month  month = Inv_Month, int  year = Inv_Year) ;
	/**
	 * \brief Returns the copy of this object to which
  was applied. 
	 * \param WeekDay   
	 * \param Month   
	 * \param int   
	*/

  wxDateTime GetLastWeekDay(WeekDay  weekday , Month  month = Inv_Month, int  year = Inv_Year) ;
	/**
	 * \brief Set the date to the given   in the week with given number
 . The number should be in range $1\ldots53$ and   will
be returned if the specified date doesn't exist.   is returned if the
date was changed successfully. 
	 * \param wxDateTime_t   
	 * \param WeekDay   
	 * \param WeekFlags  
	*/

  bool SetToTheWeek(wxDateTime_t  numWeek , WeekDay  weekday = Mon, WeekFlags flags = Monday_First) ;
	/**
	 * \brief Returns the copy of this object to which
  was applied. 
	 * \param wxDateTime_t   
	 * \param WeekDay   
	 * \param WeekFlags  
	*/

  wxDateTime GetWeek(wxDateTime_t  numWeek , WeekDay  weekday = Mon, WeekFlags flags = Monday_First) const;
	/**
	 * \brief Sets the date to the last day in the specified month (the current one by
default).

Returns the reference to the modified object itself. 
	 * \param Month   
	 * \param int   
	*/

  wxDateTime& SetToLastMonthDay(Month  month = Inv_Month, int  year = Inv_Year) ;
	/**
	 * \brief Returns the copy of this object to which
  was applied. 
	 * \param Month   
	 * \param int   
	*/

  wxDateTime GetLastMonthDay(Month  month = Inv_Month, int  year = Inv_Year) const;
	/**
	 * \brief Sets the date to the day number   in the same year (i.e., unlike the
other functions, this one does not use the current year). The day number
should be in the range $1\ldots366$ for the leap years and $1\ldots365$ for
the other ones.

Returns the reference to the modified object itself. 
	 * \param wxDateTime_t   
	*/

  wxDateTime& SetToYearDay(wxDateTime_t  yday ) ;
	/**
	 * \brief Returns the copy of this object to which
  was applied. 
	 * \param wxDateTime_t   
	*/

  wxDateTime GetYearDay(wxDateTime_t  yday ) const;
	/**
	 * \brief Returns the   corresponding to this date. Beware
of rounding errors! 
	*/

  double GetJulianDayNumber() const;
	/**
	 * \brief Synonym for  . 
	*/

  double GetJDN() const;
	/**
	 * \brief Returns the   (MJD) which is, by definition,
equal to $JDN - 2400000.5$. The MJDs are simpler to work with as the integral
MJDs correspond to midnights of the dates in the Gregorian calendar and not th
noons like JDN. The MJD 0 is Nov 17, 1858. 
	*/

  double GetModifiedJulianDayNumber() const;
	/**
	 * \brief Synonym for  . 
	*/

  double GetMJD() const;
	/**
	 * \brief Return the   of this date.

By definition, the Rata Die number is a date specified as the number of days
relative to a base date of December 31 of the year 0. Thus January 1 of the
year 1 is Rata Die day 1. 
	*/

  double GetRataDie() const;
	/**
	 * \brief Transform the date to the given time zone. If   is  , no
DST adjustments will be made.

Returns the date in the new time zone. 
	 * \param const TimeZone&   
	 * \param bool   
	*/

  wxDateTime ToTimezone(const TimeZone&  tz , bool  noDST = false) const;
	/**
	 * \brief Modifies the object in place to represent the date in another time zone. If
  is  , no DST adjustments will be made. 
	 * \param const TimeZone&   
	 * \param bool   
	*/

  wxDateTime& MakeTimezone(const TimeZone&  tz , bool  noDST = false) ;
	/**
	 * \brief This is the same as calling   with
the argument  . 
	 * \param bool   
	*/

  wxDateTime ToGMT(bool  noDST = false) const;
	/**
	 * \brief This is the same as calling   with
the argument  . 
	 * \param bool   
	*/

  wxDateTime& MakeGMT(bool  noDST = false) ;
	/**
	 * \brief Returns   if the DST is applied for this date in the given country. 
	 * \param Country   
	*/

  int IsDST(Country  country = Country_Default) const;
};


#endif
