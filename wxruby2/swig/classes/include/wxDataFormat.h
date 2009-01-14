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
  wxDataFormatId GetType() const;
  void SetId(const wxChar *format);
  void SetType(wxDataFormatId format);
};


#endif
