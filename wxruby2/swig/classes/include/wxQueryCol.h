// wxQueryCol.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxQueryCol_h_)
#define _wxQueryCol_h_
class wxQueryCol : public wxObject
{
public:
   wxQueryCol() ;
  virtual  ~wxQueryCol() ;
  void * BindVar(void * v , long  sz ) ;
  void FillVar(int  recnum ) ;
  void * GetData(int  field ) ;
  wxString GetName() ;
  short GetType() ;
  long GetSize(int  field ) ;
  bool IsRowDirty(int  field ) ;
  bool IsNullable() ;
  void AppendField(void * buf , long  len ) ;
  bool SetData(int  field , void * buf , long  len ) ;
  void SetName(const wxString&  name ) ;
  void SetNullable(bool  nullable ) ;
  void SetFieldDirty(int  field , bool  dirty = true) ;
  void SetType(short  type ) ;
};


#endif
