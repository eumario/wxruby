// wxDateSpan.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxDateSpan_h_)
#define _wxDateSpan_h_
class wxDateSpan
{
public:
   wxDateSpan(int  years = 0, int  months = 0, int  weeks = 0, int  days = 0) ;
  wxDateSpan Add(const wxDateSpan&  other ) const;
  wxDateSpan& Add(const wxDateSpan&  other ) ;
  wxDateSpan& Add(const wxDateSpan&  other ) ;
  static wxDateSpan Day() ;
  static wxDateSpan Days(int  days ) ;
  int GetDays() const;
  int GetMonths() const;
  int GetTotalDays() const;
  int GetWeeks() const;
  int GetYears() const;
  static wxDateSpan Month() ;
  static wxDateSpan Months(int  mon ) ;
  wxDateSpan Multiply(int  factor ) const;
  wxDateSpan& Multiply(int  factor ) ;
  wxDateSpan& Multiply(int  factor ) ;
  wxDateSpan Negate() const;
  wxDateSpan& Neg() ;
  wxDateSpan& Neg() ;
  wxDateSpan& SetDays(int  n ) ;
  wxDateSpan& SetYears(int  n ) ;
  wxDateSpan& SetMonths(int  n ) ;
  wxDateSpan& SetWeeks(int  n ) ;
  wxDateSpan Subtract(const wxDateSpan&  other ) const;
  wxDateSpan& Subtract(const wxDateSpan&  other ) ;
  wxDateSpan& Subtract(const wxDateSpan&  other ) ;
  static wxDateSpan Week() ;
  static wxDateSpan Weeks(int  weeks ) ;
  static wxDateSpan Year() ;
  static wxDateSpan Years(int  years ) ;
};


#endif
