// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxDataObject_h_)
#define _wxDataObject_h_
class wxDataObject
{
public:
  wxDataObject() ;
  virtual  ~wxDataObject() ;
  virtual void GetAllFormats(wxDataFormat *formats, 
                             wxDataObject::Direction dir = Get) const = 0;
  virtual bool GetDataHere(const wxDataFormat&  format , void  *buf ) const = 0;
  virtual size_t GetDataSize(const wxDataFormat&  format ) const = 0;
  virtual size_t GetFormatCount(wxDataObject::Direction dir = Get) const = 0;
  virtual wxDataFormat GetPreferredFormat(wxDataObject::Direction dir = Get) const=0;
  virtual bool SetData(const wxDataFormat& format, 
                       size_t  len, 
                       const void  *buf ) ;
  // the following were missing from the xml
  enum Direction { Get=0x01, Set=0x02};;
};


#endif
