// wxLongLong.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxLongLong_h_)
#define _wxLongLong_h_
class wxLongLong
{
public:
	/**
	 * \brief Default constructor initializes the object to 0. 
	*/

   wxLongLong() ;
	/**
	 * \brief Constructor from native long long (only for compilers supporting it). 
	 * \param wxLongLong_t   
	*/

   wxLongLong(wxLongLong_t  ll ) ;
	/**
	 * \brief Constructor from 2 longs: the high and low part are combined into one
wxLongLong. 
	 * \param long   
	 * \param unsigned long   
	*/

   wxLongLong(long  hi , unsigned long  lo ) ;
	/**
	 * \brief  
	*/

  wxLongLong Abs() const;
	/**
	 * \brief Returns an absolute value of wxLongLong - either making a copy (const version)
or modifying it in place (the second one).  Not in wxULongLong. 
	*/

  wxLongLong& Abs() ;
	/**
	 * \brief This allows to convert a double value to wxLongLong type. Such conversion is
not always possible in which case the result will be silently truncated in a
platform-dependent way.  Not in wxULongLong. 
	 * \param double   
	*/

  wxLongLong& Assign(double  d ) ;
	/**
	 * \brief Returns the high 32 bits of 64 bit integer. 
	*/

  long GetHi() const;
	/**
	 * \brief Returns the low 32 bits of 64 bit integer. 
	*/

  unsigned long GetLo() const;
	/**
	 * \brief Convert to native long long (only for compilers supporting it) 
	*/

  wxLongLong_t GetValue() const;
	/**
	 * \brief Truncate wxLongLong to long. If the conversion loses data (i.e. the wxLongLong
value is outside the range of built-in long type), an assert will be triggered
in debug mode. 
	*/

  long ToLong() const;
	/**
	 * \brief Returns the string representation of a wxLongLong. 
	*/

  wxString ToString() const;
};


#endif
