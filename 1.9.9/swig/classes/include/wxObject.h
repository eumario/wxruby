// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxObject_h_)
#define _wxObject_h_
class wxObject
{
public:
  wxObject() ;
  wxObject(const wxObject&  other ) ;
  virtual  ~wxObject() ;
  void Dump(ostream&  stream ) ;
  wxClassInfo * GetClassInfo() ;
  wxObjectRefData* GetRefData() const;
  bool IsKindOf(wxClassInfo * info ) ;
  void Ref(const wxObject&  clone ) ;
  void SetRefData(wxObjectRefData*  data ) ;
  void UnRef() ;
};


#endif
