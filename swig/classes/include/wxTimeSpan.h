// wxTimeSpan.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxTimeSpan_h_)
#define _wxTimeSpan_h_
class wxTimeSpan
{
public:
	/**
	 * \brief Returns the absolute value of the timespan: does not modify the
object. 
	*/

  wxTimeSpan Abs() const;
	/**
	 * \brief  
	 * \param const wxTimeSpan&   
	*/

  wxTimeSpan Add(const wxTimeSpan&  diff ) const;
	/**
	 * \brief  
	 * \param const wxTimeSpan&   
	*/

  wxTimeSpan& Add(const wxTimeSpan&  diff ) ;
	/**
	 * \brief Returns the sum of two timespans. 
	 * \param const wxTimeSpan&  
	*/

  wxTimeSpan& Add(const wxTimeSpan& diff ) ;
	/**
	 * \brief Returns the timespan for the given number of days. 
	 * \param long   
	*/

  static wxTimespan Days(long  days ) ;
	/**
	 * \brief Returns the timespan for one day. 
	*/

  static wxTimespan Day() ;
	/**
	 * \brief  
	*/

   Format() ;
	/**
	 * \brief Returns the difference in number of days. 
	*/

  int GetDays() const;
	/**
	 * \brief Returns the difference in number of hours. 
	*/

  int GetHours() const;
	/**
	 * \brief Returns the difference in number of milliseconds. 
	*/

  wxLongLong GetMilliseconds() const;
	/**
	 * \brief Returns the difference in number of minutes. 
	*/

  int GetMinutes() const;
	/**
	 * \brief Returns the difference in number of seconds. 
	*/

  wxLongLong GetSeconds() const;
	/**
	 * \brief Returns the internal representation of timespan. 
	*/

  wxLongLong GetValue() const;
	/**
	 * \brief Returns the difference in number of weeks. 
	*/

  int GetWeeks() const;
	/**
	 * \brief Returns the timespan for the given number of hours. 
	 * \param long   
	*/

  static wxTimespan Hours(long  hours ) ;
	/**
	 * \brief Returns the timespan for one hour. 
	*/

  static wxTimespan Hour() ;
	/**
	 * \brief Returns   if two timespans are equal. 
	 * \param const wxTimeSpan&   
	*/

  bool IsEqualTo(const wxTimeSpan&  ts ) const;
	/**
	 * \brief Compares two timespans: works with the absolute values, i.e. -2
hours is longer than 1 hour. Also, it will return   if
the timespans are equal in absolute value. 
	 * \param const wxTimeSpan&   
	*/

  bool IsLongerThan(const wxTimeSpan&  ts ) const;
	/**
	 * \brief Returns   if the timespan is negative. 
	*/

  bool IsNegative() const;
	/**
	 * \brief Returns   if the timespan is empty. 
	*/

  bool IsNull() const;
	/**
	 * \brief Returns   if the timespan is positive. 
	*/

  bool IsPositive() const;
	/**
	 * \brief Compares two timespans: works with the absolute values, i.e. 1
hour is shorter than -2 hours. Also, it will return   if
the timespans are equal in absolute value. 
	 * \param const wxTimeSpan&   
	*/

  bool IsShorterThan(const wxTimeSpan&  ts ) const;
	/**
	 * \brief Returns the timespan for the given number of minutes. 
	 * \param long   
	*/

  static wxTimespan Minutes(long  min ) ;
	/**
	 * \brief Returns the timespan for one minute. 
	*/

  static wxTimespan Minute() ;
	/**
	 * \brief  
	 * \param int   
	*/

  wxTimeSpan Multiply(int  n ) const;
	/**
	 * \brief  
	 * \param int   
	*/

  wxTimeSpan& Multiply(int  n ) ;
	/**
	 * \brief Multiplies timespan by a scalar. 
	 * \param int   
	*/

  wxTimeSpan& Multiply(int  n ) ;
	/**
	 * \brief Returns timespan with inversed sign. 
	*/

  wxTimeSpan Negate() const;
	/**
	 * \brief  
	*/

  wxTimeSpan& Neg() ;
	/**
	 * \brief Negate the value of the timespan. 
	*/

  wxTimeSpan& Neg() ;
	/**
	 * \brief Returns the timespan for the given number of seconds. 
	 * \param long   
	*/

  static wxTimespan Seconds(long  sec ) ;
	/**
	 * \brief Returns the timespan for one second. 
	*/

  static wxTimespan Second() ;
	/**
	 * \brief  
	 * \param const wxTimeSpan&  
	*/

  wxTimeSpan Substract(const wxTimeSpan& diff ) const;
	/**
	 * \brief  
	 * \param const wxTimeSpan&   
	*/

  wxTimeSpan& Substract(const wxTimeSpan&  diff ) ;
	/**
	 * \brief Returns the difference of two timespans. 
	 * \param const wxTimeSpan&  
	*/

  wxTimeSpan& Substract(const wxTimeSpan& diff ) ;
	/**
	 * \brief Returns the timespan for the given number of weeks. 
	 * \param long   
	*/

  static wxTimespan Weeks(long  weeks ) ;
	/**
	 * \brief Returns the timespan for one week. 
	*/

  static wxTimespan Week() ;
	/**
	 * \brief Default constructor, constructs a zero timespan. 
	*/

   wxTimeSpan() ;
	/**
	 * \brief Constructs timespan from separate values for each component, with the date
set to 0. Hours are not restricted to 0..24 range, neither are
minutes, seconds or milliseconds. 
	 * \param long   
	 * \param long   
	 * \param long   
	 * \param long   
	*/

   wxTimeSpan(long  hours , long  min , long  sec , long  msec ) ;
};


#endif
