// wxVariant.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxVariant_h_)
#define _wxVariant_h_
class wxVariant : public wxObject
{
public:
   wxVariant() ;
   wxVariant(const wxVariant&  variant ) ;
   wxVariant(const char*  value , const wxString&  name = "") ;
   wxVariant(const wxString&  value , const wxString&  name = "") ;
   wxVariant(char  value , const wxString&  name = "") ;
   wxVariant(long  value , const wxString&  name = "") ;
   wxVariant(bool  value , const wxString&  name = "") ;
   wxVariant(double  value , const wxString&  name = "") ;
   wxVariant(const wxList&  value , const wxString&  name = "") ;
   wxVariant(const wxStringList&  value , const wxString&  name = "") ;
   wxVariant(void*  value , const wxString&  name = "") ;
   wxVariant(wxObject*  value , const wxString&  name = "") ;
   wxVariant(wxVariantData*  data , const wxString&  name = "") ;
  virtual  ~wxVariant() ;
  void Append(const wxVariant&  value ) ;
  void ClearList() ;
  int GetCount() const;
  bool Delete(int  item ) ;
  bool GetBool() const;
  char GetChar() const;
  wxVariantData* GetData() const;
  double GetDouble() const;
  long GetLong() const;
  const wxString& GetName() const;
  wxString GetString() const;
  wxString GetType() const;
  void* GetVoidPtr() const;
  void* GetWxObjectPtr() const;
  void Insert(const wxVariant&  value ) ;
  bool IsNull() const;
  bool IsType(const wxString&  type ) const;
  bool IsValueKindOf(const wxClassInfo* type  type ) const;
  void MakeNull() ;
  wxString MakeString() const;
  bool Member(const wxVariant&  value ) const;
  void NullList() ;
  void SetData(wxVariantData*  data ) ;
};


#endif
