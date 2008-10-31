// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxURLDataObject_h_)
#define _wxURLDataObject_h_

#ifdef __WXMSW__
class wxURLDataObject : public wxDataObjectComposite
#else
class wxURLDataObject : public wxTextDataObject
#endif
{
  wxURLDataObject(const wxString& url = wxEmptyString);
  wxString GetURL();
  void SetURL(const wxString& url);
};

#endif
