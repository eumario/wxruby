// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxBitmapDataObject_h_)
#define _wxBitmapDataObject_h_
class wxBitmapDataObject : public wxDataObjectSimple
{
public:
  wxBitmapDataObject(const wxBitmap& bitmap = wxNullBitmap);
  virtual wxBitmap GetBitmap() const;
  virtual void SetBitmap(const wxBitmap& bitmap);
};

#endif
