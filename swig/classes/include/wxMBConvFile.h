// wxMBConvFile.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxMBConvFile_h_)
#define _wxMBConvFile_h_
class wxMBConvFile : public wxMBConv
{
public:
  size_t MB2WC(wchar_t*  buf , const char*  psz , size_t  n ) const;
  size_t WC2MB(char*  buf , const wchar_t*  psz , size_t  n ) const;
};


#endif
