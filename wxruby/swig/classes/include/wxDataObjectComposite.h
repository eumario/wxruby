// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxDataObjectComposite_h_)
#define _wxDataObjectComposite_h_

class wxDataObjectComposite : public wxDataObject
{
public:
  wxDataObjectComposite();
  void Add(wxDataObjectSimple *dataObject, bool preferred = false);
  wxDataFormat GetReceivedFormat() const;

  // implement base class pure virtuals
  virtual wxDataFormat GetPreferredFormat(wxDataObject::Direction dir = Get) const;
  virtual size_t GetFormatCount(wxDataObject::Direction dir = Get) const;
  virtual void GetAllFormats(wxDataFormat *formats, wxDataObject::Direction dir = Get) const;
  virtual size_t GetDataSize(const wxDataFormat& format) const;
  virtual bool GetDataHere(const wxDataFormat& format, void *buf) const;
  virtual bool SetData(const wxDataFormat& format, size_t len, const void *buf);

/* #if defined(__WXMSW__) */
/*   virtual const void* GetSizeFromBuffer( const void* buffer, size_t* size, */
/*                                            const wxDataFormat& format ); */
/*   virtual void* SetSizeInBuffer( void* buffer, size_t size, */
/*                                  const wxDataFormat& format ); */
/*   virtual size_t GetBufferOffset( const wxDataFormat& format ); */
/* #endif */

};

#endif
