// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxPen_h_)
#define _wxPen_h_
class wxPen : public wxGDIObject
{
public:
   wxPen() ;
   wxPen(const wxColour&  colour , int  width = 1 , int  style = wxSOLID ) ;
   wxPen(const wxString&  colourName , int  width = 1 , int  style = wxSOLID ) ;
// not available on GTK
#if defined(__WXMSW__) || defined(__WXMAC__)
   wxPen(const wxBitmap&  stipple , int  width ) ;
#endif
   wxPen(const wxPen&  pen ) ;
  virtual  ~wxPen() ;
  int GetCap() const;
  wxColour& GetColour() const;
  int GetDashes(wxDash**  dashes ) const;
  int GetJoin() const;
// not available on GTK
#if defined(__WXMSW__) || defined(__WXMAC__)
  wxBitmap* GetStipple() const;
#endif
  int GetStyle() const;
  int GetWidth() const;
  bool Ok() const;
  void SetCap(int  capStyle ) ;
  void SetColour(wxColour&  colour ) ;
  void SetColour(const wxString&  colourName ) ;
  void SetColour(int  red , int  green , int  blue ) ;
  void SetDashes(int  n , wxDash*  dashes ) ;
  void SetJoin(int join_style ) ;
// not available on GTK
#if defined(__WXMSW__) || defined(__WXMAC__)
  void SetStipple(const wxBitmap&  stipple ) ;
#endif
  void SetStyle(int  style ) ;
  void SetWidth(int  width ) ;
};


#endif
