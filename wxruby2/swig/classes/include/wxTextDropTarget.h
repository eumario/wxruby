// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxTextDropTarget_h_)
#define _wxTextDropTarget_h_
class wxTextDropTarget : public wxDropTarget
{
public:
  wxTextDropTarget();
  virtual bool OnDrop(long x, long y,
                      const void *data, size_t size) = 0;
  virtual bool OnDropText(wxCoord x, wxCoord y, 
                          const wxString& data) = 0;
};


#endif
