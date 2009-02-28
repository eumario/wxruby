// Copyright 2004-2007, wxRuby development team
// released under the MIT-like wxRuby2 license

#if !defined(_wxGauge_h_)
#define _wxGauge_h_
class wxGauge : public wxControl
{
public:
   wxGauge() ;
   wxGauge(wxWindow*  parent , wxWindowID  id , int  range , const wxPoint&  pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxGA_HORIZONTAL, const wxValidator&  validator = wxDefaultValidator, const wxString&  name = wxT("gauge")) ;
  virtual  ~wxGauge() ;
  bool Create(wxWindow*  parent , wxWindowID  id , int  range , const wxPoint&  pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxGA_HORIZONTAL, const wxValidator&  validator = wxDefaultValidator, const wxString&  name = wxT("gauge")) ;
  int GetBezelFace() const;
  int GetRange() const;
  int GetShadowWidth() const;
  int GetValue() const;
  void Pulse();
  void SetBezelFace(int  width ) ;
  void SetRange(int  range ) ;
  void SetShadowWidth(int  width ) ;
  void SetValue(int  pos ) ;
};


#endif
