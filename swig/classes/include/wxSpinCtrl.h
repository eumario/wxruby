// wxSpinCtrl.h
// This file was automatically generated
// by extractxml.rb, part of the wxRuby project
// Do not make changes directly to this file!

#if !defined(_wxSpinCtrl_h_)
#define _wxSpinCtrl_h_
class wxSpinCtrl : public wxControl
{
public:
   wxSpinCtrl() ;
   wxSpinCtrl(wxWindow*  parent , wxWindowID  id = -1, const wxString&  value = wxEmptyString, const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long  style = wxSP_ARROW_KEYS, int  min = 0, int  max = 100, int  initial = 0, const wxString&  name = _T("wxSpinCtrl")) ;
  bool Create(wxWindow*  parent , wxWindowID  id = -1, const wxString&  value = wxEmptyString, const wxPoint&  pos = wxDefaultPosition, const wxSize&  size = wxDefaultSize, long  style = wxSP_ARROW_KEYS, int  min = 0, int  max = 100, int  initial = 0, const wxString&  name = _T("wxSpinCtrl")) ;
  void SetValue(const wxString&  text ) ;
  void SetValue(int  value ) ;
  int GetValue() const;
  void SetRange(int  minVal , int  maxVal ) ;
  void SetSelection(long  from , long  to ) ;
  int GetMin() const;
  int GetMax() const;
};


#endif
