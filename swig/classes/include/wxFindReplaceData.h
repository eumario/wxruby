// wxFindReplaceData.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxFindReplaceData_h_)
#define _wxFindReplaceData_h_
class wxFindReplaceData : public wxObject
{
public:
   wxFindReplaceData(wxUint32  flags = 0) ;
  const wxString& GetFindString() ;
  const wxString& GetReplaceString() ;
  int GetFlags() const;
  void SetFlags(wxUint32  flags ) ;
  void SetFindString(const wxString&  str ) ;
  void SetReplaceString(const wxString&  str ) ;
};


#endif
