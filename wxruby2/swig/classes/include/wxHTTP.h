// wxHTTP.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxHTTP_h_)
#define _wxHTTP_h_
class wxHTTP : public wxProtocol
{
public:
  wxInputStream * GetInputStream(const wxString&  path ) ;
  void SetHeader(const wxString&  header , const wxString&  h_data ) ;
  wxString GetHeader(const wxString&  header ) ;
};


#endif
