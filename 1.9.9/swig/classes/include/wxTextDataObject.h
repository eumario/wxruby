// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxTextDataObject_h_)
#define _wxTextDataObject_h_
class wxTextDataObject : public wxDataObjectSimple
{
public:
  wxTextDataObject(const wxString&  text = wxEmptyString);
  virtual size_t GetTextLength() const;
  virtual wxString GetText() const;
  virtual void SetText(const wxString& strText);
};


#endif
