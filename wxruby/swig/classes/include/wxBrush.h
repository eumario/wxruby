// Copyright 2004-2008, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxBrush_h_)
#define _wxBrush_h_
class wxBrush : public wxGDIObject
{
public:
  wxBrush() ;
  wxBrush(const wxColour& colour, int style = wxSOLID);
  wxBrush(const wxString& colourName, int style);
  wxBrush(const wxBitmap& stippleBitmap);
  wxBrush(const wxBrush&  brush);
  virtual  ~wxBrush() ;
#ifdef __WXMSW__
  wxColour GetColour() const;
#else
  wxColour& GetColour() const;
#endif
  wxBitmap * GetStipple() const;
  int GetStyle() const;
  bool IsHatch() const;
  bool IsOk() const;
  void SetColour(wxColour& colour);
  void SetColour(const wxString& colourName);
  void SetColour(const unsigned char red, 
                 const unsigned char green, 
                 const unsigned char  blue);
  void SetStipple(const wxBitmap& bitmap);
  void SetStyle(int  style ) ;
};


#endif
