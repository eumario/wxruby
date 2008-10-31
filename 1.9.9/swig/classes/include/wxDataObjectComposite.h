// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxDataObjectComposite_h_)
#define _wxDataObjectComposite_h_

class wxDataObjectComposite : public wxDataObject
{
public:
  wxDataObjectComposite();
  void Add(wxDataObjectSimple *dataObject, bool preferred = false);
};

#endif
