// wxDataObject.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxDataObject_h_)
#define _wxDataObject_h_
class wxDataObject
{
public:
   wxDataObject() ;
  virtual  ~wxDataObject() ;
  virtual void GetAllFormats(wxDataFormat * formats , Direction dir = Get) const;
  virtual bool GetDataHere(const wxDataFormat&  format , void  *buf ) const;
  virtual size_t GetDataSize(const wxDataFormat&  format ) const;
  virtual size_t GetFormatCount(Direction dir = Get) const;
  virtual wxDataFormat GetPreferredFormat(Direction dir = Get) const;
  virtual bool SetData(const wxDataFormat&  format , size_t  len , const void  *buf ) ;
};


#endif
