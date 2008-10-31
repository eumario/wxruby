// wxDateSpan.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxDateSpan_h_)
#define _wxDateSpan_h_
class wxDateSpan
{
public:
	/**
	 * \brief Constructs the date span object for the given number of years, months, weeks
and days. Note that the weeks and days add together if both are given. 
	 * \param int   
	 * \param int   
	 * \param int   
	 * \param int   
	*/

   wxDateSpan(int  years = 0, int  months = 0, int  weeks = 0, int  days = 0) ;
	/**
	 * \brief  
	 * \param const wxDateSpan&   
	*/

  wxDateSpan Add(const wxDateSpan&  other ) const;
	/**
	 * \brief  
	 * \param const wxDateSpan&   
	*/

  wxDateSpan& Add(const wxDateSpan&  other ) ;
	/**
	 * \brief Returns the sum of two date spans. The first version returns a new object, the
second and third ones modify this object in place. 
	 * \param const wxDateSpan&   
	*/

  wxDateSpan& Add(const wxDateSpan&  other ) ;
	/**
	 * \brief Returns a date span object corresponding to one day. 
	*/

  static wxDateSpan Day() ;
	/**
	 * \brief Returns a date span object corresponding to the given number of days. 
	 * \param int   
	*/

  static wxDateSpan Days(int  days ) ;
	/**
	 * \brief Returns the number of days (only, that it not counting the weeks component!)
in this date span. 
	*/

  int GetDays() const;
	/**
	 * \brief Returns the number of the months (not counting the years) in this date span. 
	*/

  int GetMonths() const;
	/**
	 * \brief  
	*/

  int GetTotalDays() const;
	/**
	 * \brief Returns the number of weeks in this date span. 
	*/

  int GetWeeks() const;
	/**
	 * \brief Returns the number of years in this date span. 
	*/

  int GetYears() const;
	/**
	 * \brief Returns a date span object corresponding to one month. 
	*/

  static wxDateSpan Month() ;
	/**
	 * \brief Returns a date span object corresponding to the given number of months. 
	 * \param int   
	*/

  static wxDateSpan Months(int  mon ) ;
	/**
	 * \brief  
	 * \param int   
	*/

  wxDateSpan Multiply(int  factor ) const;
	/**
	 * \brief  
	 * \param int   
	*/

  wxDateSpan& Multiply(int  factor ) ;
	/**
	 * \brief Returns the product of the date span by the specified  . The
product is computed by multiplying each of the components by the factor.

The first version returns a new object, the second and third ones modify this
object in place. 
	 * \param int   
	*/

  wxDateSpan& Multiply(int  factor ) ;
	/**
	 * \brief Returns the date span with the opposite sign. 
	*/

  wxDateSpan Negate() const;
	/**
	 * \brief  
	*/

  wxDateSpan& Neg() ;
	/**
	 * \brief Changes the sign of this date span. 
	*/

  wxDateSpan& Neg() ;
	/**
	 * \brief Sets the number of days (without modifying any other components) in this date
span. 
	 * \param int   
	*/

  wxDateSpan& SetDays(int  n ) ;
	/**
	 * \brief Sets the number of years (without modifying any other components) in this date
span. 
	 * \param int   
	*/

  wxDateSpan& SetYears(int  n ) ;
	/**
	 * \brief Sets the number of months (without modifying any other components) in this
date span. 
	 * \param int   
	*/

  wxDateSpan& SetMonths(int  n ) ;
	/**
	 * \brief Sets the number of weeks (without modifying any other components) in this date
span. 
	 * \param int   
	*/

  wxDateSpan& SetWeeks(int  n ) ;
	/**
	 * \brief  
	 * \param const wxDateSpan&   
	*/

  wxDateSpan Subtract(const wxDateSpan&  other ) const;
	/**
	 * \brief  
	 * \param const wxDateSpan&   
	*/

  wxDateSpan& Subtract(const wxDateSpan&  other ) ;
	/**
	 * \brief Returns the difference of two date spans. The first version returns a new
object, the second and third ones modify this object in place. 
	 * \param const wxDateSpan&   
	*/

  wxDateSpan& Subtract(const wxDateSpan&  other ) ;
	/**
	 * \brief Returns a date span object corresponding to one week. 
	*/

  static wxDateSpan Week() ;
	/**
	 * \brief Returns a date span object corresponding to the given number of weeks. 
	 * \param int   
	*/

  static wxDateSpan Weeks(int  weeks ) ;
	/**
	 * \brief Returns a date span object corresponding to one year. 
	*/

  static wxDateSpan Year() ;
	/**
	 * \brief Returns a date span object corresponding to the given number of years. 
	 * \param int   
	*/

  static wxDateSpan Years(int  years ) ;
};


#endif
