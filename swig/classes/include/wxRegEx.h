// wxRegEx.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxRegEx_h_)
#define _wxRegEx_h_
class wxRegEx
{
public:
   wxRegEx() ;
   wxRegEx(const wxString&  expr , int  flags = wxRE_DEFAULT) ;
  virtual  ~wxRegEx() ;
  bool Compile(const wxString&  pattern , int  flags = wxRE_DEFAULT) ;
  bool IsValid() const;
  bool GetMatch(size_t*  start , size_t*  len , size_t  index = 0) const;
  wxString GetMatch(const wxString&  text , size_t  index = 0) const;
  bool Matches(const wxChar*  text , int  flags = 0) const;
  int Replace(wxString*  text , const wxString&  replacement , size_t  maxMatches = 0) const;
  int ReplaceAll(wxString*  text , const wxString&  replacement ) const;
  int ReplaceFirst(wxString*  text , const wxString&  replacement ) const;
};


#endif
