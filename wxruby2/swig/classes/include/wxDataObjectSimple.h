// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxDataObjectSimple_h_)
#define _wxDataObjectSimple_h_
class wxDataObjectSimple : public wxDataObject
{
public:
   wxDataObjectSimple(const wxDataFormat& format = wxFormatInvalid) ;
  const wxDataFormat& GetFormat() const;
  void SetFormat(const wxDataFormat&  format ) ;
  virtual size_t GetDataSize() const;
  virtual bool GetDataHere(void *buf) const;
  virtual bool SetData(size_t len, const void *buf);
};


#endif
