// wxTimeSpan.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxTimeSpan_h_)
#define _wxTimeSpan_h_
class wxTimeSpan
{
public:
  wxTimeSpan Abs() const;
  wxTimeSpan Add(const wxTimeSpan&  diff ) const;
  wxTimeSpan& Add(const wxTimeSpan&  diff ) ;
  wxTimeSpan& Add(const wxTimeSpan& diff ) ;
  static wxTimespan Days(long  days ) ;
  static wxTimespan Day() ;
   Format() ;
  int GetDays() const;
  int GetHours() const;
  wxLongLong GetMilliseconds() const;
  int GetMinutes() const;
  wxLongLong GetSeconds() const;
  wxLongLong GetValue() const;
  int GetWeeks() const;
  static wxTimespan Hours(long  hours ) ;
  static wxTimespan Hour() ;
  bool IsEqualTo(const wxTimeSpan&  ts ) const;
  bool IsLongerThan(const wxTimeSpan&  ts ) const;
  bool IsNegative() const;
  bool IsNull() const;
  bool IsPositive() const;
  bool IsShorterThan(const wxTimeSpan&  ts ) const;
  static wxTimespan Minutes(long  min ) ;
  static wxTimespan Minute() ;
  wxTimeSpan Multiply(int  n ) const;
  wxTimeSpan& Multiply(int  n ) ;
  wxTimeSpan& Multiply(int  n ) ;
  wxTimeSpan Negate() const;
  wxTimeSpan& Neg() ;
  wxTimeSpan& Neg() ;
  static wxTimespan Seconds(long  sec ) ;
  static wxTimespan Second() ;
  wxTimeSpan Substract(const wxTimeSpan& diff ) const;
  wxTimeSpan& Substract(const wxTimeSpan&  diff ) ;
  wxTimeSpan& Substract(const wxTimeSpan& diff ) ;
  static wxTimespan Weeks(long  weeks ) ;
  static wxTimespan Week() ;
   wxTimeSpan() ;
   wxTimeSpan(long  hours , long  min , long  sec , long  msec ) ;
};


#endif
