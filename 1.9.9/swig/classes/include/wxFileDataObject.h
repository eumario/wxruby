// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxFileDataObject_h_)
#define _wxFileDataObject_h_
class wxFileDataObject : public wxDataObjectSimple
{
public:
  virtual void AddFile(const wxString&  file );
  const wxArrayString& GetFilenames() const;
};


#endif
