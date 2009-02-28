// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxFileDropTarget_h_)
#define _wxFileDropTarget_h_
class wxFileDropTarget : public wxDropTarget
{
public:
  wxFileDropTarget();
  virtual bool OnDrop(long x, long y, 
                      const void *data, size_t size) = 0;
  virtual bool OnDropFiles(wxCoord x, wxCoord y, 
                           const wxArrayString& filenames) = 0;
};


#endif
