// wxCalendarDateAttr.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxCalendarDateAttr_h_)
#define _wxCalendarDateAttr_h_
class wxCalendarDateAttr
{
public:
   wxCalendarDateAttr() ;
   wxCalendarDateAttr(const wxColour&  colText , const wxColour&  colBack = wxNullColour, const wxColour&  colBorder = wxNullColour, const wxFont&  font = wxNullFont, wxCalendarDateBorder  border = wxCAL_BORDER_NONE) ;
   wxCalendarDateAttr(wxCalendarDateBorder  border , const wxColour&  colBorder = wxNullColour) ;
  void SetTextColour(const wxColour&  colText ) ;
  void SetBackgroundColour(const wxColour&  colBack ) ;
  void SetBorderColour(const wxColour&  col ) ;
  void SetFont(const wxFont&  font ) ;
  void SetBorder(wxCalendarDateBorder  border ) ;
  void SetHoliday(bool  holiday ) ;
  bool HasTextColour() const;
  bool HasBackgroundColour() const;
  bool HasBorderColour() const;
  bool HasFont() const;
  bool HasBorder() const;
  bool IsHoliday() const;
  const wxColour& GetTextColour() const;
  const wxColour& GetBackgroundColour() const;
  const wxColour& GetBorderColour() const;
  const wxFont& GetFont() const;
  wxCalendarDateBorder GetBorder() const;
};


#endif
