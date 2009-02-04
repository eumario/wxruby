// Copyright 2004-2009, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxDataFormat_h_)
#define _wxDataFormat_h_

class wxDataFormat
{
public:
  wxDataFormat(wxDataFormatId format = wxDF_INVALID);
  wxDataFormat(const wxChar *format);
  wxString GetId() const;
  // The formal signature for these is NativeFormat; this is required on
  // MSVC as otherwise an impermissible implicit cast is tried, and so
  // doesn't compile
#ifdef __WXMSW__
  typedef unsigned short NativeFormat;
  NativeFormat GetType() const;
#else
  wxDataFormatId GetType() const;
#endif
  void SetId(const wxChar *format);
  void SetType(wxDataFormatId format);
};


#endif
