// wxSystemOptions.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxSystemOptions_h_)
#define _wxSystemOptions_h_
class wxSystemOptions : public wxObject
{
public:
   wxSystemOptions() ;
  wxString GetOption(const wxString&  name ) const;
  int GetOptionInt(const wxString&  name ) const;
  bool HasOption(const wxString&  name ) const;
  void SetOption(const wxString&  name , const wxString&  value ) ;
  void SetOption(const wxString&  name , int  value ) ;
};


#endif
