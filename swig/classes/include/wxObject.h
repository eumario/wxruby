// wxObject.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

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
