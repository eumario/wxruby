// wxEncodingConverter.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxEncodingConverter_h_)
#define _wxEncodingConverter_h_
class wxEncodingConverter : public wxObject
{
public:
   wxEncodingConverter() ;
  bool Init(wxFontEncoding  input_enc , wxFontEncoding  output_enc , int  method = wxCONVERT_STRICT) ;
  void Convert(const char*  input , char*  output ) ;
  void Convert(const wchar_t*  input , wchar_t*  output ) ;
  void Convert(const char*  input , wchar_t*  output ) ;
  void Convert(const wchar_t*  input , char*  output ) ;
  void Convert(char*  str ) ;
  void Convert(wchar_t*  str ) ;
  wxString Convert(const wxString&  input ) ;
  static wxFontEncodingArray GetPlatformEquivalents(wxFontEncoding  enc , int  platform = wxPLATFORM_CURRENT) ;
  static wxFontEncodingArray GetAllEquivalents(wxFontEncoding  enc ) ;
};


#endif
