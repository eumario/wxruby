// wxCSConv.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxCSConv_h_)
#define _wxCSConv_h_
class wxCSConv : public wxMBConv
{
public:
   wxCSConv(const wxChar*  charset ) ;
  virtual  ~wxCSConv() ;
  void LoadNow() ;
  size_t MB2WC(wchar_t*  buf , const char*  psz , size_t  n ) const;
  size_t WC2MB(char*  buf , const wchar_t*  psz , size_t  n ) const;
};


#endif
