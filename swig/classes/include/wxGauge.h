// wxGauge.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxGauge_h_)
#define _wxGauge_h_
class wxGauge : public wxControl
{
public:
   wxGauge() ;
   wxGauge(wxWindow*  parent , wxWindowID  id , int  range , const wxPoint&  pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxGA_HORIZONTAL, const wxValidator&  validator = wxDefaultValidator, const wxString&  name = "gauge") ;
  virtual  ~wxGauge() ;
  bool Create(wxWindow*  parent , wxWindowID  id , int  range , const wxPoint&  pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxGA_HORIZONTAL, const wxValidator&  validator = wxDefaultValidator, const wxString&  name = "gauge") ;
  int GetBezelFace() const;
  int GetRange() const;
  int GetShadowWidth() const;
  int GetValue() const;
  void SetBezelFace(int  width ) ;
  void SetRange(int  range ) ;
  void SetShadowWidth(int  width ) ;
  void SetValue(int  pos ) ;
};


#endif
