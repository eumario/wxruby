// wxVariantData.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxVariantData_h_)
#define _wxVariantData_h_
class wxVariantData : public wxObject
{
public:
   wxVariantData() ;
  void Copy(wxVariantData&  data ) ;
  bool Eq(wxVariantData&  data ) const;
  wxString GetType() const;
  wxClassInfo* GetValueClassInfo() const;
  bool Read(ostream&  stream ) ;
  bool Read(wxString&  string ) ;
  bool Write(ostream&  stream ) const;
  bool Write(wxString&  string ) const;
};


#endif
