// Copyright 2004-2009, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxDataObjectSimple_h_)
#define _wxDataObjectSimple_h_

class wxDataObjectSimple : public wxDataObject
{
public:
  wxDataObjectSimple(const wxDataFormat& format = wxFormatInvalid);
  const wxDataFormat& GetFormat() const;
  void SetFormat(const wxDataFormat&  format ) ;
  virtual size_t GetDataSize() const;

  virtual bool GetDataHere(void *buf) const;
  virtual bool SetData(size_t len, const void *buf);

  virtual wxDataFormat GetPreferredFormat(wxDataObject::Direction dir = Get) const;
  virtual size_t GetFormatCount(wxDataObject::Direction dir = Get) const;
  virtual void GetAllFormats(wxDataFormat *formats,
                             wxDataObject::Direction dir = Get) const;
  virtual size_t GetDataSize(const wxDataFormat& format) const;
  virtual WXRUBY_DATA_OUT GetDataHere(const wxDataFormat& format, void *buf) const;
  virtual WXRUBY_DATA_IN SetData(const wxDataFormat& format,
                                 size_t len, const void *buf);


};


#endif
