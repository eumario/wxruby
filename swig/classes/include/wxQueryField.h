// wxQueryField.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxQueryField_h_)
#define _wxQueryField_h_
class wxQueryField : public wxObject
{
public:
   wxQueryField() ;
  virtual  ~wxQueryField() ;
  bool AllocData() ;
  void ClearData() ;
  void * GetData() ;
  long GetSize() ;
  short GetType() ;
  bool IsDirty() ;
  bool SetData(void * data , long  sz ) ;
  void SetDirty(bool dirty = true) ;
  void SetSize(long  size ) ;
  void SetType(short  type ) ;
};


#endif
