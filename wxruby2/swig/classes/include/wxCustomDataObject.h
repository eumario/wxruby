// wxCustomDataObject.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxCustomDataObject_h_)
#define _wxCustomDataObject_h_
class wxCustomDataObject : public wxDataObjectSimple
{
public:
   wxCustomDataObject(const wxDataFormat&  format = wxFormatInvalid) ;
  virtual  ~wxCustomDataObject() ;
  virtual void * Alloc(size_t  size ) ;
  virtual void Free() ;
  virtual size_t GetSize() const;
  virtual void * GetData() const;
  virtual void SetData(size_t  size , const void  *data ) ;
  virtual void TakeData(size_t  size , const void  *data ) ;
};


#endif
