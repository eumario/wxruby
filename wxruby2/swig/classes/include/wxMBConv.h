// wxMBConv.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxMBConv_h_)
#define _wxMBConv_h_
class wxMBConv
{
public:
   wxMBConv() ;
  virtual size_t MB2WC(wchar_t*  buf , const char*  psz , size_t  n ) const;
  virtual size_t WC2MB(char*  buf , const wchar_t*  psz , size_t  n ) const;
  const wxWCharBuffer cMB2WC(const char*  psz ) const;
  const wxCharBuffer cWC2MB(const wchar_t*  psz ) const;
  const char* cMB2WX(const char*  psz ) const;
  const wxWCharBuffer cMB2WX(const char*  psz ) const;
  const char* cWX2MB(const wxChar*  psz ) const;
  const wxCharBuffer cWX2MB(const wxChar*  psz ) const;
  const wchar_t* cWC2WX(const wchar_t*  psz ) const;
  const wxCharBuffer cWC2WX(const wchar_t*  psz ) const;
  const wchar_t* cWX2WC(const wxChar*  psz ) const;
  const wxWCharBuffer cWX2WC(const wxChar*  psz ) const;
};


#endif
