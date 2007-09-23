// Copyright 2006 - 2007 by Kevin Smith
// released under the MIT-style wxruby2 license

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
