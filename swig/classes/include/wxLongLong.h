// wxLongLong.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxLongLong_h_)
#define _wxLongLong_h_
class wxLongLong
{
public:
   wxLongLong() ;
   wxLongLong(wxLongLong_t  ll ) ;
   wxLongLong(long  hi , unsigned long  lo ) ;
  wxLongLong Abs() const;
  wxLongLong& Abs() ;
  wxLongLong& Assign(double  d ) ;
  long GetHi() const;
  unsigned long GetLo() const;
  wxLongLong_t GetValue() const;
  long ToLong() const;
  wxString ToString() const;
};


#endif
